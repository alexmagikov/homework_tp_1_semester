#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {

    FILE* file = fopen("file.txt", "r");
    int numCities = 0;
    fscanf(file, "%d", &numCities);
    int numRoads = 0;
    fscanf(file, "%d", &numRoads);
    int** matrix = malloc(numCities * sizeof(int));
    if (matrix == NULL) {
        printf("mem fail");
        return -1;
    }
    for (int i = 0; i < numCities; i++) {
        matrix[i] = malloc(numCities * sizeof(int));
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
    bool* distribute = calloc(numCities, sizeof(bool));

    countries = addCapital(countries, 2);
    int m = 0;
    /*
    for (int i = 0; i < numCapitals; i++) {
        int capital = -1;
        fscanf(file, "%d", &capital);
        countries = addCapital(countries, capital);
    }*/

    debugPrintGraph(countries);

    fclose(file);

    free(distribute);

    // TODO: Add function to free graph memory
    free(countries);
    return 0;
}