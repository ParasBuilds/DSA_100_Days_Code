/*
Problem: Given integers a and b, compute a^b using recursion
without using pow() function.
*/

#include <stdio.h>

// Recursive function to calculate power
int power(int a, int b) 
{
    if (b == 0)
        return 1;

    // Recursive case
    return a * power(a, b - 1);
}

int main() 
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    printf("%d", power(num1, num2));

    return 0;
}
