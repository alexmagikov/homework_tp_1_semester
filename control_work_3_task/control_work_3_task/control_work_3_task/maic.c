#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
    FILE* file;
    char ch;
    file = fopen("file.txt", "r");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return 1;
    }
    char last = "";
    while ((ch = fgetc(file)) != EOF) {
        if (ch != last) {
            printf("%c", ch);
            last = ch;
        }
    }
    fclose(file);
    return 0;
}