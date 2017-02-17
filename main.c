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
    int firstCharPos, firstSpacePos;
    int i = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            line[charCount] = c;
            line[++charCount] = '\0';
            printf("%s", line);
            charCount = 0;
        }
        else if (charCount < LINE_MAX_LENGTH) {
            line[charCount++] = c;
        }
        else {
            for (firstSpacePos = charCount - 1; !charEmpty(line[firstSpacePos]); --firstSpacePos);
            for (firstCharPos = firstSpacePos; charEmpty(line[firstCharPos]); --firstCharPos);
            line[firstCharPos+1] = '\0';
            printf("%s\n", line);

            for (i = 0; i < LINE_MAX_LENGTH - firstSpacePos - 1; ++i)
                line[i] = line[firstSpacePos + i + 1];
            charCount = i;
            line[charCount++] = c;
        }
    }
    line[charCount] = '\0';
    printf("%s\n", line);
    return EXIT_SUCCESS;
}
