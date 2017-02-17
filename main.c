#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LINE_MAX_LENGTH 5

bool charEmpty(char c) {
    return (c == '\t' || c == ' ');
}

int main () {
    char line[LINE_MAX_LENGTH + 1];
    char c;
    int charCount = 0;
    int lastCharPos, lastSpacePos;
    int i = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n' || ((c == '\t' || c == ' ') && charCount == LINE_MAX_LENGTH)) {
            line[charCount] = '\n';
            line[++charCount] = '\0';
            printf("%s", line);
            charCount = 0;
        } else if (charCount < LINE_MAX_LENGTH) {
            line[charCount++] = c;
        } else {
            for (lastSpacePos = charCount - 1; !charEmpty(line[lastSpacePos]) && lastSpacePos >= 0; --lastSpacePos);
            if (lastSpacePos == -1) {//no spaces in line
                line[charCount] = '\0';
                printf("%s\n", line);
                line[0] = c;
                charCount = 1;
            } else {
                for (lastCharPos = lastSpacePos; charEmpty(line[lastCharPos] && lastCharPos >= 0); --lastCharPos);
                line[lastCharPos + 1] = '\0';
                printf("%s\n", line);
                for (i = 0; i < LINE_MAX_LENGTH - lastSpacePos - 1; ++i)
                    line[i] = line[lastSpacePos + i + 1];
                charCount = i;
                line[charCount++] = c;
            }
        }
    }
    line[charCount] = '\0';
    printf("%s\n", line);
    return EXIT_SUCCESS;
}
