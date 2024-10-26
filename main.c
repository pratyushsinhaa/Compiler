#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

// Function to interpret the bytecode
void interpret(byte* bytecode, int size) {
    int pc = 0;  // Program counter
    while (pc < size) {
        byte opcode = bytecode[pc];
        printf("Processing opcode: %x at position %d\n", opcode, pc);
        switch (opcode) {
            case 0x01: {  // Addition
                if (pc + 2 >= size) {
                    printf("Error: Incomplete bytecode for addition\n");
                    return;
                }
                int operand1 = bytecode[pc + 1];
                int operand2 = bytecode[pc + 2];
                int result = operand1 + operand2;
                printf("Addition: %d + %d = %d\n", operand1, operand2, result);
                pc += 3;
                break;
            }
            case 0x02: {  // Multiplication
                if (pc + 2 >= size) {
                    printf("Error: Incomplete bytecode for multiplication\n");
                    return;
                }
                int operand1 = bytecode[pc + 1];
                int operand2 = bytecode[pc + 2];
                int result = operand1 * operand2;
                printf("Multiplication: %d * %d = %d\n", operand1, operand2, result);
                pc += 3;
                break;
            }
            case 0x03: {  // Subtraction
                if (pc + 2 >= size) {
                    printf("Error: Incomplete bytecode for subtraction\n");
                    return;
                }
                int operand1 = bytecode[pc + 1];
                int operand2 = bytecode[pc + 2];
                int result = operand1 - operand2;
                printf("Subtraction: %d - %d = %d\n", operand1, operand2, result);
                pc += 3;
                break;
            }
            case 0x04: {  // Division
                if (pc + 2 >= size) {
                    printf("Error: Incomplete bytecode for division\n");
                    return;
                }
                int operand1 = bytecode[pc + 1];
                int operand2 = bytecode[pc + 2];
                if (operand2 == 0) {
                    printf("Error: Division by zero\n");
                    return;
                }
                int result = operand1 / operand2;
                printf("Division: %d / %d = %d\n", operand1, operand2, result);
                pc += 3;
                break;
            }
            default:
                printf("Error: Unknown opcode %x\n", opcode);
                return;
        }
    }
}

int main() {
    // Path to the bytecode file
    const char* filepath = "/Users/pratyushsinha/GitHub/Compiler/pyth/__pycache__/test2.pyc";  // Adjust the path as needed

    // Open the bytecode file
    FILE* file = fopen(filepath, "rb");
    if (file == NULL) {
        printf("Failed to open file\n");
        return 1;
    }
    
    // Get the file size
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    // Allocate memory for the bytecode
    byte* bytecode = (byte*)malloc(size);
    if (bytecode == NULL) {
        printf("Failed to allocate memory\n");
        fclose(file);
        return 1;
    }
    
    // Read the bytecode into memory
    size_t bytesRead = fread(bytecode, 1, size, file);
    fclose(file);
    
    // Check if the entire bytecode was read
    if (bytesRead != size) {
        printf("Failed to read the complete bytecode\n");
        free(bytecode);
        return 1;
    }
    
    // Print the bytecode for debugging
    printf("Bytecode read from file:\n");
    for (int i = 0; i < size; i++) {
        printf("%02x ", bytecode[i]);
    }
    printf("\n");
    
    // Interpret the bytecode
    interpret(bytecode, size);
    
    // Free the allocated memory
    free(bytecode);
    
    return 0;
}