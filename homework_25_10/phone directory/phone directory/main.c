#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main(void) {
    FILE* file = fopen("numbers.txt", "r+");
    char buffer[31];
    int index = 0;
    char** array = NULL;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        array = (char*)realloc(array, (index + 1) * sizeof(char*));
        if (array == NULL) {
            printf("memory failed");
            free(array);
            fclose(file);
            exit(0);
        }
        array[index] = malloc(32);
        if (array[index] == NULL) {
            printf("memory failed");
            free(array);
            fclose(file);
            exit(0);
        }
        strcpy(array[index], buffer);
        index++;
    }
    int indexOfLastElementInFile = index;
    fclose(file);
    while (true) {
        int currentDo = 0;
        char* name[20];
        char* number[11];
        printf("input command ");
        scanf("%d", &currentDo);
        if (currentDo == 0) {
            free(array);
            fclose(file);
            exit(0);
        }
        else if (currentDo == 1) {
            printf("input name and number ");
            scanf("%20s", name);
            scanf("%11s", number);
            char* note[32];
            strcpy(note, "\n");
            strcat(note, name);
            strcat(note, " ");
            strcat(note, number);
            array = (char*)realloc(array, (index + 1) * sizeof(char*));
            if (array == NULL) {
                printf("memory failed");
                free(array);
                fclose(file);
                exit(0);
            }
            array[index] = malloc(32);
            if (array[index] == NULL) {
                printf("memory failed");
                free(array);
                fclose(file);
                exit(0);
            }
            strcpy(array[index], note);
            index++;
        }
        else if (currentDo == 2) {
            for (int i = 0; i < index; i++) {
                printf("%s", array[i]);
            }
            printf("\n");
        }
        else if (currentDo == 3) {
            bool isFind = false;
            char name[20];
            printf("input name ");
            scanf("%s", name);
            for (int i = 0; i < indexOfLastElementInFile; i++) {
                char nameNote[20];
                int indexName = 0;
                while (array[i][indexName] != ' ') {
                    nameNote[indexName] = array[i][indexName];
                    indexName++;
                }
                nameNote[indexName] = '\0';
                if (!strcmp(name, nameNote)) {
                    indexName++;
                    printf("number: ");
                    while (array[i][indexName] != '\n' && array[i][indexName] != '\0' && array[i][indexName] != ' ') {
                        printf("%c", array[i][indexName]);
                        indexName++;
                    }
                    isFind = true;
                    break;
                }

            }
            if (!isFind) {
                printf("number didnt find");
            }
            printf("\n");
        }
        else if (currentDo == 4) {
            char number[12];
            printf("input number ");
            scanf("%s", number);
            bool isFind = false;
            for (int i = 0; i < indexOfLastElementInFile; i++) {
                char numberNote[12];
                char nameNote[20];
                int indexNote = 0;
                int indexName = 0;
                while (array[i][indexNote] != ' ') {
                    nameNote[indexNote] = array[i][indexNote];
                    indexNote++;
                }
                nameNote[indexNote] = '\0';
                indexNote++;
                indexName = indexNote;
                while (array[i][indexNote] != '\n' && array[i][indexNote] != '\0' && array[i][indexNote] != ' ') {
                    numberNote[indexNote - indexName] = array[i][indexNote];
                    indexNote++;
                }
                numberNote[indexNote - indexName] = '\0';
                if (!strcmp(number, numberNote)) {
                    printf("name: %s", nameNote);
                    isFind = true;
                    break;
                }

            }
            if (!isFind) {
                printf("number didnt find");
            }
            printf("\n");
        }
        else if (currentDo == 5) {
            FILE* file = fopen("numbers.txt", "a");
            for (int i = 0; i < (index - indexOfLastElementInFile); i++) {
                fprintf(file, array[indexOfLastElementInFile + i]);
            }
            fclose(file);
        }
    }
}