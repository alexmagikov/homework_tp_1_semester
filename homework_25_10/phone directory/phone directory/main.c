#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Base {
    char** array;
    int indexOfLastElement;
} Base;

void returnErrorOfMemory(char* array) {
    printf("memory failed");
    free(array);
    exit(0);
}

Base createBase() {
    FILE* file = fopen("base.txt", "r+");
    char buffer[31];
    int index = 0;
    char** array = NULL;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        array = (char*)realloc(array, (index + 1) * sizeof(char*));
        if (array == NULL) {
            fclose(file);
            returnErrorOfMemory(array);
        }
        array[index] = malloc(32);
        if (array[index] == NULL) {
            fclose(file);
            returnErrorOfMemory(array[index]);
        }
        strcpy(array[index], buffer);
        index++;
    }
    int indexOfLastElementInFile = index;
    fclose(file);
    Base result;
    result.array = array;
    result.indexOfLastElement = indexOfLastElementInFile;
    return result;
}

void entryToBase(Base* base, int* index) {
    char* name[20];
    char* number[11];
    printf("input name and number ");
    scanf("%20s", name);
    scanf("%11s", number);
    char* note[32];
    
    if (*index == 0) {
        strcpy(note, "");
        strcat(note, name);
        strcat(note, " ");
        strcat(note, number);
    }
    else {
        strcpy(note, "\n");
        strcat(note, name);
        strcat(note, " ");
        strcat(note, number);
    }
    (*base).array = (char*)realloc((*base).array, (*index + 1) * sizeof(char*));
    if ((*base).array == NULL) {
        returnErrorOfMemory((*base).array);
    }
    (*base).array[*index] = malloc(32);
    if ((*base).array[*index] == NULL) {
        returnErrorOfMemory((*base).array[*index]);
    }
    strcpy((*base).array[*index], note);
    (*index)++;
}

void returnNumberByName(Base base) {
    bool isFind = false;
    char name[20];
    printf("input name ");
    scanf("%s", name);
    for (int i = 0; i < base.indexOfLastElement; i++) {
        char nameNote[20];
        int indexName = 0;
        while (base.array[i][indexName] != ' ') {
            nameNote[indexName] = base.array[i][indexName];
            indexName++;
        }
        nameNote[indexName] = '\0';
        if (!strcmp(name, nameNote)) {
            indexName++;
            printf("number: ");
            while (base.array[i][indexName] != '\n' && base.array[i][indexName] != '\0' && base.array[i][indexName] != ' ') {
                printf("%c", base.array[i][indexName]);
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

void returnNameByNumber(Base base) {
    char number[12];
    printf("input number ");
    scanf("%s", number);
    bool isFind = false;
    for (int i = 0; i < base.indexOfLastElement; i++) {
        char numberNote[12];
        char nameNote[20];
        int indexNote = 0;
        int indexName = 0;
        while (base.array[i][indexNote] != ' ') {
            nameNote[indexNote] = base.array[i][indexNote];
            indexNote++;
        }
        nameNote[indexNote] = '\0';
        indexNote++;
        indexName = indexNote;
        while (base.array[i][indexNote] != '\n' && base.array[i][indexNote] != '\0' && base.array[i][indexNote] != ' ') {
            numberNote[indexNote - indexName] = base.array[i][indexNote];
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

void printToFile(Base base, int index) {
    FILE* file = fopen("base.txt", "a");
    for (int i = 0; i < (index - base.indexOfLastElement); i++) {
        if (base.indexOfLastElement + i > 100) {
            printf("base is full");
            break;
        }
        else {
            fprintf(file, base.array[base.indexOfLastElement + i]);
        }
    }
    fclose(file);
}

void printfBase(Base base, int index) {
    for (int i = 0; i < index; i++) {
        printf("%s", base.array[i]);
    }
    printf("\n");
}

bool testForEntryToBase() {
    Base base;
    base.array = NULL;
    int index = 0;
    entryToBase(&base, &index);
    return base.array[0] != NULL;
}


void main(void) {
    if (!testForEntryToBase()){
        printf("tests are not accepted");
        exit(0);
    }
    Base base = createBase();
    int index = base.indexOfLastElement;
    while (true) {
        int currentDo = 0;
        printf("input command ");
        scanf("%d", &currentDo);

        if (currentDo == 0) {
            for (int i = 0; i < index; i++) {
                free(base.array[i]);
            }
            free(base.array);
            exit(0);
        }
        else if (currentDo == 1) {
            entryToBase(&base, &index);
        }
        else if (currentDo == 2) {
            printfBase(base, index);
        }
        else if (currentDo == 3) {
            returnNumberByName(base);
        }
        else if (currentDo == 4) {
            returnNameByNumber(base);
        }
        else if (currentDo == 5) {
            printToFile(base, index);
        }
    }
}