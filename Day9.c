/*
Problem: A secret system stores code names in forward order.
To display them in mirror format, reverse the given string.
*/

#include <stdio.h>
#include <string.h>

int main() 
{
    char str[100];
    int left, right;
    char temp;

    // Input string
    printf("Enter a string: ");
    scanf("%s", str);

    left = 0;
    right = strlen(str) - 1;

    while (left < right) {
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }

    // Output reversed string
    printf("Reversed string: ");
    printf("%s", str);

    return 0;
}
