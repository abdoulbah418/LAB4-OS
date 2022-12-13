

#include <stdio.h>
#include <stdlib.h>

/* Declare functions */
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int main(void) {
    /* Define two pre-defined integers */
    int a = 10, b = 5;

    /* Take a single character from the user as input */
    printf("Enter a single character (0, 1, 2, 3, or 4): ");
    char ch;
    scanf("%c", &ch);

    /* Check the input character and perform the corresponding operation on the two pre-defined integers */
    switch (ch) {
        case '0':
            printf("Result: %d\n", add(a, b));
            break;
        case '1':
            printf("Result: %d\n", subtract(a, b));
            break;
        case '2':
            printf("Result: %d\n", multiply(a, b));
            break;
        case '3':
            printf("Result: %d\n", divide(a, b));
            break;
        case '4':
            printf("Exiting program...\n");
            exit(0);
            break;
        default:
            printf("Invalid character entered!\n");
            break;
    }

    return 0;
}

/* Define functions */
int add(int a, int b) {
    printf("Adding 'a' and 'b'\n");
    return a + b;
}

int subtract(int a, int b) {
    printf("Subtracting 'b' from 'a'\n");
    return a - b;
}

int multiply(int a, int b) {
    printf("Multiplying 'a' and 'b'\n");
    return a * b;
}

int divide(int a, int b) {
    printf("Dividing 'a' and 'b'\n");
		return a / b;
}
