#include <stdio.h>

int GetKey() {
    char mycharacter;
    printf("\nEnter a character: ");
    if (scanf(" %c", &mycharacter) != 1) {
        printf("Invalid input\n");
        return -1;
    }
    return (int)mycharacter;
}
