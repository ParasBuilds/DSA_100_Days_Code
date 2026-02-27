/*
Problem: Write a recursive function fib(n) to compute the n-th Fibonacci number
where fib(0) = 0 and fib(1) = 1.
*/

#include <stdio.h>

// Recursive function to find Fibonacci number
int fib(int n) 
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() 
{
    int n;
    scanf("%d", &n);

    printf("%d", fib(n));

    return 0;
}
