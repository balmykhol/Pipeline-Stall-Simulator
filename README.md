# 5 Stage Pipeline Stall Detector/ Simulator

This C program identifies potential pipeline stalls in an assembly program and modifies it to be stall-free by inserting no-operation (nop) instructions. It analyzes dependencies between instructions to ensure efficient execution and minimal stalls.

## Features

- **Stall Detection**: Identifies instructions in the assembly program that may cause pipeline stalls.
- **No-op Insertion**: Automatically inserts `nop` instructions where necessary to avoid stalls.
- **Two Simulation Modes**:
  - **Case 1**: No data forwarding and no hazard detection.
  - **Case 2**: Data forwarding but no hazard detection.

## Usage

1. **Compile the Program**:
   ```bash
   gcc code.c -o code
   ```

2. **Run the Program**:
   ```bash
   ./code
   ```

3. **Input File**:
   - Provide an input file containing assembly code (e.g., `input.txt`).
   - Ensure the file is in the same directory as the executable.

4. **Output**:
   - The program will display:
     - The modified assembly program with inserted `nop` instructions.
     - Total clock cycles required for both simulation cases.

## Supported Instructions

- R-Type instructions (e.g., add, sub)
- I-Type instructions (e.g., addi, slti, lb, lh, lw, etc.) excluding jalr
- S-Type instructions (e.g., sd, sw, sh)

## File Structure

- `code.c`: Main C source code file.
- `input.txt`: Sample input file containing assembly code for testing.

## Parameters

- `MAXROWS`: Maximum number of lines the program can handle (default: 50).
- `MAXCOLS`: Maximum number of characters per line (default: 25).
- `MAXSIZE`: Maximum file name size (default: 25).

## Notes

- This program is designed to detect and mitigate potential pipeline stalls by analyzing register dependencies between instructions.
- Feel free to modify constants (`MAXROWS`, `MAXCOLS`, `MAXSIZE`) in the source code to suit your requirements.
