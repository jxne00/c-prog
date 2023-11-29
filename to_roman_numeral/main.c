#include "roman.h"
#include <stdio.h>

int main() {
    // get user input
    printf("Enter a number between 1 and 3999: ");
    int value;
    scanf("%d", &value);

    // convert to roman
    printf("%s\n", int_to_roman(value));
    return 0;
}