#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf('%d',&t);
    while(t--)
    {
        char s[10000];
        int count = 0;
        scanf("%s", &s);
        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == '1')
                count++;
        }

        if (count == 1)
            printf("TRUE\n");
        else
            printf("FALSE\n");
    }
    return 0;
}