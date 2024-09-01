#include <stdio.h>
#include <string.h>

#define MAX 100

// Function to add two binary numbers
void addBinary(char* a, char* b, char* result) {
    int len1 = strlen(a);
    int len2 = strlen(b);
    int carry = 0;
    int sum, i, k;

    // Make both binary numbers of the same length
    if (len1 > len2) {
        for (i = len2; i < len1; i++)
            b[i] = '0';
        b[len1] = '\0';
    } else if (len2 > len1) {
        for (i = len1; i < len2; i++)
            a[i] = '0';
        a[len2] = '\0';
    }

    len1 = strlen(a);
    k = len1 - 1;
    result[k + 1] = '\0';

    // Perform binary addition
    for (i = len1 - 1; i >= 0; i--) {
        sum = (a[i] - '0') + (b[i] - '0') + carry;
        result[k] = (sum % 2) + '0';
        carry = sum / 2;
        k--;
    }

    // If there's a carry left, add it at the beginning
    if (carry) {
        for (i = len1; i >= 0; i--)
            result[i + 1] = result[i];
        result[0] = carry + '0';
    }
}

// Function to subtract binary number b from a
void subtractBinary(char* a, char* b, char* result) {
    int len1 = strlen(a);
    int len2 = strlen(b);
    int borrow = 0;
    int diff, i, k;

    // Make both binary numbers of the same length
    if (len1 > len2) {
        for (i = len2; i < len1; i++)
            b[i] = '0';
        b[len1] = '\0';
    } else if (len2 > len1) {
        for (i = len1; i < len2; i++)
            a[i] = '0';
        a[len2] = '\0';
    }

    len1 = strlen(a);
    k = len1 - 1;
    result[k + 1] = '\0';

    // Perform binary subtraction
    for (i = len1 - 1; i >= 0; i--) {
        diff = (a[i] - '0') - (b[i] - '0') - borrow;
        if (diff < 0) {
            diff += 2;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[k] = diff + '0';
        k--;
    }

    // Remove leading zeros
    int start = 0;
    while (result[start] == '0' && start < len1 - 1) {
        start++;
    }
    for (i = 0; i < len1 - start; i++) {
        result[i] = result[start + i];
    }
    result[i] = '\0';
}

int main() {
    char a[MAX], b[MAX], addResult[MAX + 1], subResult[MAX + 1];

    // Input binary numbers
    printf("Enter first binary number: ");
    scanf("%s", a);

    printf("Enter second binary number: ");
    scanf("%s", b);

    // Perform addition
    addBinary(a, b, addResult);
    printf("Sum of %s and %s is %s\n", a, b, addResult);

    // Perform subtraction
    subtractBinary(a, b, subResult);
    printf("Difference of %s and %s is %s\n", a, b, subResult);

    return 0;
}