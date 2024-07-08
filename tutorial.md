# 5 stage Pipeline Stall Detector/ Simulator
This C program is designed to identify the instructions in a given program where a pipeline might stall. The input will be an assembly program and the output will be a modified assembly program with added nops (no-operation) to make it stall-free.

## Usage

1. Compile the program using a C compiler:

   ```bash
   gcc AI22BTECH11005.c -o lab5
2. Run the program:

   ```bash
   ./lab5
3. The program will prompt you to enter the name of a file containing assembly code. Ensure that the file is in the same directory as the executable.

4. The program will read the file, identify which lines require stalls, and display the corresponding assembly instructions in one line after other in the terminal.

## Supported Instructions

- R-Type instructions (e.g. add, sub, or etc)
- I-Type instructions (e.g. addi, slti, lb, lh, lw etc.) except jalr
- S-Type intructions (e.g. sd, sw, sh etc)

## Input File Format

1. The input file should be a .txt file

2. A sample input file named 
    ```bash
    inputs.txt
containing assembly code I used is also attached.

3. The code is designed to handle upto 50 (modifiable with 'MAXROWS') lines of code with each line being less than 24 characters (modifiable with 'MAXCOLS') and the name of the file should be under 24 (modifiable with 'MAXSIZE') characters including '.txt'.

## Output

The program will output the modified assembly programme in the terminal and number of cycles for running the code. For example input:

    add t0, t1, t2
    sub t4, t0, t3

The output would be :

    Case: 1  No data forwarding and no hazard detection : Total cycle: 8 
    add t0, t1 ,t2  
    nop 
    nop
    sub t4, t0, t3   
    
    Case 2: Data forwarding but no hazard detection : Total cycles: 6
    add t0, t1 ,t2 
    sub t4, t0, t3 

## Note

1. The third parameter in function 
    ```bash
    decode(char *arr, int *arr2, int type)
being 1 decodes consideering instrucions as R-type, but for value being 2 decoding is done considering it as load instructions, type as 3 would be in the case of other I type instructions (except jalr), 4 for S-type instructions.

1. The third parameter in function 
    ```bash
    nop_counter(int arr[], int arr2[], int type)
being 1 considers there is no instruction between 2 instructions having register dependencies , but for any other value considers there is exactly 1 instruction between 2 instructions having register dependencies 

1. The code can check the need for nops even in the case of register dependancies like in the case :
        
        add x0, x1, x2
        add x3, x0, x1

    The output would be :
    
            Case: 1  No data forwarding and no hazard detection : Total cycle: 6 
            add x0, x1, x2  
            add x3, x0, x1  

            Case 2: Data forwarding but no hazard detection : Total cycles: 6
            add x0, x1, x2 
            add x3, x0, x1 
    as the value is getting loaded into x0 which is always set to be zero.

