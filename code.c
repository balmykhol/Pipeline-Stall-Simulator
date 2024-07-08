#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXROWS 50
#define MAXCOLS 25
#define MAXSIZE 25

int clock_cycles_1 = 4;
int clock_cycles_2 = 4;

int reg_num(char *arr)
{
    if (strcmp(arr, "zero") == 0 || strcmp(arr, "x0") == 0)
        return 0;
    if (strcmp(arr, "ra") == 0 || strcmp(arr, "x1") == 0)
        return 1;
    if (strcmp(arr, "sp") == 0 || strcmp(arr, "x2") == 0)
        return 2;
    if (strcmp(arr, "gp") == 0 || strcmp(arr, "x3") == 0)
        return 3;
    if (strcmp(arr, "tp") == 0 || strcmp(arr, "x4") == 0)
        return 4;
    if (strcmp(arr, "t0") == 0 || strcmp(arr, "x5") == 0)
        return 5;
    if (strcmp(arr, "t1") == 0 || strcmp(arr, "x6") == 0)
        return 6;
    if (strcmp(arr, "t2") == 0 || strcmp(arr, "x7") == 0)
        return 7;
    if (strcmp(arr, "s0") == 0 || strcmp(arr, "x8") == 0 || strcmp(arr, "fp") == 0)
        return 8;
    if (strcmp(arr, "s1") == 0 || strcmp(arr, "x9") == 0)
        return 9;
    if (strcmp(arr, "a0") == 0 || strcmp(arr, "x10") == 0)
        return 10;
    if (strcmp(arr, "a1") == 0 || strcmp(arr, "x11") == 0)
        return 11;
    if (strcmp(arr, "a2") == 0 || strcmp(arr, "x12") == 0)
        return 12;
    if (strcmp(arr, "a3") == 0 || strcmp(arr, "x13") == 0)
        return 13;
    if (strcmp(arr, "a4") == 0 || strcmp(arr, "x14") == 0)
        return 14;
    if (strcmp(arr, "a5") == 0 || strcmp(arr, "x15") == 0)
        return 15;
    if (strcmp(arr, "a6") == 0 || strcmp(arr, "x16") == 0)
        return 16;
    if (strcmp(arr, "a7") == 0 || strcmp(arr, "x17") == 0)
        return 17;
    if (strcmp(arr, "s2") == 0 || strcmp(arr, "x18") == 0)
        return 18;
    if (strcmp(arr, "s3") == 0 || strcmp(arr, "x19") == 0)
        return 19;
    if (strcmp(arr, "s4") == 0 || strcmp(arr, "x20") == 0)
        return 20;
    if (strcmp(arr, "s5") == 0 || strcmp(arr, "x21") == 0)
        return 21;
    if (strcmp(arr, "s6") == 0 || strcmp(arr, "x22") == 0)
        return 22;
    if (strcmp(arr, "s7") == 0 || strcmp(arr, "x23") == 0)
        return 23;
    if (strcmp(arr, "s8") == 0 || strcmp(arr, "x24") == 0)
        return 24;
    if (strcmp(arr, "s9") == 0 || strcmp(arr, "x25") == 0)
        return 25;
    if (strcmp(arr, "s10") == 0 || strcmp(arr, "x26") == 0)
        return 26;
    if (strcmp(arr, "s11") == 0 || strcmp(arr, "x27") == 0)
        return 27;
    if (strcmp(arr, "t3") == 0 || strcmp(arr, "x28") == 0)
        return 28;
    if (strcmp(arr, "t4") == 0 || strcmp(arr, "x29") == 0)
        return 29;
    if (strcmp(arr, "t5") == 0 || strcmp(arr, "x30") == 0)
        return 30;
    return 31;
}

char *sliceString(char *str, int start, int end)
{
    int i;
    int size = (end - start) + 1;
    char *output = (char *)malloc(size * sizeof(char));

    for (i = 0; start < end; start++, i++)
    {
        output[i] = str[start];
    }
    output[size - 1] = '\0';
    return output;
}

void decode(char *arr, int *arr2, int type)
{
    int start = 0, end = 0, count = 0;
    if (type == 1)
    {
        for (int i = 0; arr[i] != '\0'; i++)
        {
            if (arr[i] == ' ')
            {
                start = i + 1;
                while (arr[i] != ',' && arr[i] != '\0')
                {
                    i++;
                }
                end = i;
                arr2[count] = reg_num(sliceString(arr, start, end));
                count++;
            }
        }
    }
    if (type == 2 || type == 4)
    {
        for (int i = 0; arr[i] != '\0'; i++)
        {
            if (arr[i] == ' ' && count == 0)
            {
                start = i + 1;
                while (arr[i] != ',')
                {
                    i++;
                }
                end = i;
                arr2[count] = reg_num(sliceString(arr, start, end));
                count++;
            }
            if (arr[i] == '(')
            {
                start = i + 1;
                while (arr[i] != ')')
                {
                    i++;
                }
                end = i;
                arr2[count] = reg_num(sliceString(arr, start, end));
                count++;
            }
        }
    }
    if (type == 3)
    {
        int i = 0;
        while (count < 2)
        {
            if (arr[i] == ' ')
            {
                start = i + 1;
                while (arr[i] != ',' && arr[i] != '\0')
                {
                    i++;
                }
                end = i;
                arr2[count] = reg_num(sliceString(arr, start, end));
                count++;
            }
            i++;
        }
    }
}

// type 1- reg+=2
// else reg+=1
int nop_counter(int arr[], int arr2[], int type)
{
    if (arr[0] == 0)
        return 0;
    if (arr2[0] == 0)
        return 0;
    if (type == 1)
        return 2;
    return 1;
}

int get_type(char arr[][MAXCOLS], int row)
{
    if (strcmp(sliceString(arr[row], 0, 2), "ld") == 0)
        return 2;
    if (strcmp(sliceString(arr[row], 0, 2), "sd") == 0)
        return 4;
    if (strcmp(sliceString(arr[row], 0, 2), "lb") == 0)
        return 2;
    if (strcmp(sliceString(arr[row], 0, 2), "lh") == 0)
        return 2;
    if (strcmp(sliceString(arr[row], 0, 2), "lw") == 0)
        return 2;
    if (strcmp(sliceString(arr[row], 0, 3), "lbu") == 0)
        return 2;
    if (strcmp(sliceString(arr[row], 0, 3), "lhu") == 0)
        return 2;
    if (strcmp(sliceString(arr[row], 0, 3), "lwu") == 0)
        return 2;
    if (strcmp(sliceString(arr[row], 0, 2), "sb") == 0)
        return 4;
    if (strcmp(sliceString(arr[row], 0, 2), "sh") == 0)
        return 4;
    if (strcmp(sliceString(arr[row], 0, 2), "sw") == 0)
        return 4;
    if (strcmp(sliceString(arr[row], 0, 3), "ori") == 0)
        return 3;
    if (strcmp(sliceString(arr[row], 0, 4), "addi") == 0)
        return 3;
    if (strcmp(sliceString(arr[row], 0, 4), "xori") == 0)
        return 3;
    if (strcmp(sliceString(arr[row], 0, 4), "andi") == 0)
        return 3;
    if (strcmp(sliceString(arr[row], 0, 4), "slli") == 0)
        return 3;
    if (strcmp(sliceString(arr[row], 0, 4), "srli") == 0)
        return 3;
    if (strcmp(sliceString(arr[row], 0, 4), "srai") == 0)
        return 3;
    if (strcmp(sliceString(arr[row], 0, 4), "slti") == 0)
        return 3;
    if (strcmp(sliceString(arr[row], 0, 5), "sltiu") == 0)
        return 3;
    return 1;
}

void nops(int row, char arr[][MAXCOLS], char arr2[][5])
{
    int reg1 = 0, reg2 = 0, extra1 = 0, ld = 0, type;
    int regs[3] = {0};
    int regs2[3] = {0};
    int regs3[3] = {0};
    type = get_type(arr, row);
    decode(arr[row], regs, type);
    if (type != 1)
        regs[2] = regs[1];
    if (type == 4)
    {
        regs[1] = regs[0];
        regs[0] = regs[2];
    }
    // printf(" data: [%s], [%d] [%d] [%d] [%d]\n", arr[row], type, regs[0], regs[1], regs[2]);
    if (row >= 1)
    {
        type = get_type(arr, row - 1);
        if (type == 2)
            ld = 1;
        decode(arr[row - 1], regs2, type);
        if (type == 4)
            regs2[0] = 32;
        if (regs2[0] == regs[1] || regs2[0] == regs[2])
        {
            reg1 = nop_counter(regs2, regs, 1);
            if (ld == 1)
                extra1 = nop_counter(regs2, regs, 2);
            for (int i = 1; i <= reg1 + extra1; i++)
            {
                strcpy(arr2[3 * row - i], "\nnop");
            }
            clock_cycles_1 += reg1;
            clock_cycles_2 += extra1;
        }
    }
    if (row >= 2)
    {
        type = get_type(arr, row - 2);
        decode(arr[row - 2], regs3, type);
        if (type == 4)
            regs3[0] = 32;
        if (regs3[0] == regs[1] || regs3[0] == regs[2])
        {
            reg2 = nop_counter(regs3, regs, 2);
            if (reg2 > reg1)
            {
                for (int i = 1; i <= reg2; i++)
                {
                    strcpy(arr2[3 * row - i - 3], "\nnop");
                }
                clock_cycles_1 += reg2;
            }
        }
    }
}

int main()
{
    printf("Input file name? ");
    char str[MAXSIZE];
    fgets(str, MAXSIZE, stdin);

    str[strcspn(str, "\n")] = '\0';
    FILE *file = fopen(str, "r");

    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return 1;
    }

    char arr[MAXROWS][MAXCOLS] = {'\0'};
    int rows = 0;
    int cols = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF && rows < MAXROWS)
    {
        if (ch == '\n')
        {
            cols = 0;
            rows++;
        }
        else if (cols < MAXCOLS)
        {
            arr[rows][cols] = ch;
            cols++;
        }
    }

    rows++;
    fclose(file);

    char arr2[3 * MAXROWS][5] = {'\0'};
    for (int i = rows - 1; i >= 0; i--)
    {
        nops(i, arr, arr2);
        clock_cycles_1 += 1;
        clock_cycles_2 += 1;
    }
    printf("\nCase: 1  No data forwarding and no hazard detection : Total cycle: %d ", clock_cycles_1);
    for (int i = 0; i < rows; i++)
    {
        printf("\n%s %s %s", arr[i], arr2[3 * i + 1], arr2[3 * i + 2]);
    }
    printf("\n \n \nCase 2: Data forwarding but no hazard detection : Total cycles: %d", clock_cycles_2);
    for (int i = 0; i < rows; i++)
    {
        printf("\n%s %s", arr[i], arr2[3 * i]);
    }
    printf("\n");
}