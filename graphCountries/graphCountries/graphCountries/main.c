#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {

    FILE* file = fopen("file.txt", "r");
    if (file == NULL) {
        printf("open fail");
        return -1;
    }
    int numCities = 0;
    fscanf(file, "%d", &numCities);
    int numRoads = 0;
    fscanf(file, "%d", &numRoads);

    int** matrix = malloc(numCities * sizeof(int*));
    if (matrix == NULL) {
        printf("mem fail");
        return -1;
    }
    for (int i = 0; i < numCities; i++) {
        matrix[i] = calloc(numCities, sizeof(int));
        if (matrix[i] == NULL) {
            printf("mem fail");
            return -1;
        }
    }

    for (int i = 0; i < numRoads; i++) {
        int from = 0;
        int to = 0;
        int length = 0;
        fscanf(file, "%d %d %d", &from, &to, &length);
        matrix[from][to] = length;
        matrix[to][from] = length;
    }

    int numCapitals = 0;
    fscanf(file, "%d", &numCapitals);
    Graph* countries = createGraph(numCities);
    bool* distributeScale = calloc(numCities, sizeof(bool));

    int* capitals = malloc(numCapitals * sizeof(int));

    for (int i = 0; i < numCapitals; i++) {
        int capital = -1;
        fscanf(file, "%d", &capital);
        countries = addNote(countries, capital, numCities, matrix, &distributeScale);
        capitals[i] = capital;
    }

    int index = 0;
    while (!allDistribute(numCities, distributeScale)) {
        addNote(countries, capitals[index], numCities, matrix, &distributeScale);
        index++;
        if (index >= numCapitals) {
            index = 0;
        }
    }
    
    printGraph(countries);

    fclose(file);
    for (int i = 0; i < numCities; i++) {
        free(matrix[i]);
    }
    removeGraph(countries);
    free(matrix);
    return 0;
}