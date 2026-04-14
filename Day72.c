#include <stdio.h>
#include <string.h>

char firstRepeated(char* s) {
    int seen[26] = {0};   // seen[i] = 1 if (i+'a') already encountered

    for (int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';   // map 'a'→0, 'b'→1, ..., 'z'→25

        if (seen[idx])           // already seen → this is 2nd occurrence
            return s[i];

        seen[idx] = 1;           // first time seeing this character
    }

    return '\0';   // no repeated character found
}

int main() {
    char s[1000];
    scanf("%s", s);

    char result = firstRepeated(s);

    if (result == '\0')
        printf("-1\n");
    else
        printf("%c\n", result);

    return 0;
}