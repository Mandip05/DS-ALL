#include <stdio.h>

// Define the NAND gate function
int nand(int a, int b) {
    return !(a && b);
}

// Define the NOR gate function
int nor(int a, int b) {
    return !(a || b);
}

// Print the truth table
void print_truth_table() {
    printf("NAND Gate Truth Table\n");
    printf("A|B|Output\n");
    printf("0|0|%d\n", nand(0, 0));
    printf("0|1|%d\n", nand(0, 1));
    printf("1|0|%d\n", nand(1, 0));
    printf("1|1|%d\n", nand(1, 1));
    printf("\n");
    printf("NOR Gate Truth Table\n");
    printf("A|B|Output\n");
    printf("0|0|%d\n", nor(0, 0));
    printf("0|1|%d\n", nor(0, 1));
    printf("1|0|%d\n", nor(1, 0));
    printf("1|1|%d\n", nor(1, 1));
}

int main() {
    print_truth_table();
    return 0;
}