#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LINE_MAX_LENGTH 5
#define NEW_LINE '\n'
#define END_LINE '\0'

void printLine(char line[], int charNumber, char lineDelimeter);
int findSplitPos(char line[]);
bool CharEmpty(char c);
int removeChars(char line[], int pos);

int main() {
    char line[LINE_MAX_LENGTH];
    char c;
    int charCount = 0;
    bool isPassEmptyChars = false;

    do {
        c = getchar();
        if (c == '\n' && !isPassEmptyChars) {
            printLine(line, charCount, NEW_LINE);
            charCount = 0;
        } else if (c == EOF) {
            printLine(line, charCount, END_LINE);
        } else if (charCount == LINE_MAX_LENGTH) {
            if (c == ' ' || c == '\n' || c == '\t') {
                printLine(line, charCount, NEW_LINE);
                isPassEmptyChars = true;
                charCount = 0;
            } else {
                int splitPos = findSplitPos(line);
                if (splitPos == -1) {
                    //оформить перенос
                } else {
                    printLine(line, splitPos + 1, NEW_LINE);
                    charCount = removeChars(line, splitPos);
                    line[++charCount] = c;
                    ++charCount;
                }
            }
        } else {
            if (isPassEmptyChars) {
                isPassEmptyChars = CharEmpty(c);
                if (isPassEmptyChars)
                    continue;
            }
            line[charCount++] = c;
        }
    } while (c != EOF);
    return EXIT_SUCCESS;
}

void printLine(char line[], int charNumber, char lineDelimeter) {
    for (int i = 0; i < charNumber; ++i) {
        putchar(line[i]);
    }
    if (lineDelimeter != END_LINE)
        putchar(lineDelimeter);
}

int findSplitPos(char line[]) {
    bool isEmptyCharFound = false;
    for (int i = LINE_MAX_LENGTH - 1; i >= 0; --i) {
        if (!isEmptyCharFound)
            isEmptyCharFound = CharEmpty(line[i]);
        else if (!CharEmpty(line[i]))
            return ++i;
    }
    return -1;
}

bool CharEmpty(char c) {
    return c == ' ' || c == '\t';
}


int removeChars(char line[], int pos) {
    int j = -1;
    bool isStrip = true;
    for (int i = pos + 1; i < LINE_MAX_LENGTH; ++i) {
        if (isStrip && !CharEmpty(line[i]))
            isStrip = false;
        if (!isStrip)
            line[++j] = line[i];
    }
    return j;
}
