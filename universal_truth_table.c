#include <stdio.h>

int main() {
    int A, B;
    int nand_result, nor_result;

    // Print the header for the NAND gate truth table
    printf("NAND Gate Truth Table\n");
    printf("A B | A NAND B\n");
    printf("-------------\n");
    
    // Loop through all combinations of A and B (0 and 1)
    for (A = 0; A <= 1; A++) {
        for (B = 0; B <= 1; B++) {
            // Calculate the NAND result
            nand_result = !(A && B);
            
            // Print the current values and the NAND result
            printf("%d %d | %d\n", A, B, nand_result);
        }
    }

    // Print a blank line for separation
    printf("\n");

    // Print the header for the NOR gate truth table
    printf("NOR Gate Truth Table\n");
    printf("A B | A NOR B\n");
    printf("-------------\n");
    
    // Loop through all combinations of A and B (0 and 1)
    for (A = 0; A <= 1; A++) {
        for (B = 0; B <= 1; B++) {
            // Calculate the NOR result
            nor_result = !(A || B);
            
            // Print the current values and the NOR result
            printf("%d %d | %d\n", A, B, nor_result);
        }
    }

    return 0;
}
