#include <stdio.h>
#include "main.h"

int func(int i) {
  return i;
}

void main() {
    int result, squareOfInt;
    printf("Enter a number: ");
    scanf("%i", &result);
    printf("Here's the number: %i", func(result));
    printf("\n\nEnter a number: ");
    scanf("%i", &squareOfInt);
    printf("Here's the square of the number: %i\n", square(squareOfInt));
}