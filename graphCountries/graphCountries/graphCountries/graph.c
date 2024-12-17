#include "graph.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

Graph* createGraph(int numCities) {
    Graph* graph = malloc(sizeof(Graph));
    if (graph == NULL) {
        return NULL;
    }
    graph->numCities = numCities;
    graph->countries = malloc(numCities *sizeof(List*));
    for (int i = 0; i < numCities; i++) {
        graph->countries[i] = NULL;
    }
    if (graph->countries == NULL) {
        return NULL;
    }
    return graph;
}

Graph* addNote(Graph* graph, int country, int numCities, int** matrix, bool** distributeScale) {
    int nearestLength = 1000;
    int nearestCity = -1;

    if (graph->countries[country] == NULL) {
        graph->countries[country] = createList();
        Position position = first(graph->countries[country]);
        add(graph->countries[country], position, country);
        (*distributeScale)[country] = true;
        return graph;
    }

    Position position = first(graph->countries[country]);

    for (int i = 0; i < getLength(graph->countries[country]); i++) {
        position = next(position);
        int cityOfCountry = getValue(graph->countries[country], position);
        for (int j = 0; j < numCities; j++) {
            if (matrix[cityOfCountry][j] != 0 && !(*distributeScale)[j] && j != country) {
                if (matrix[cityOfCountry][j] < nearestLength) {
                    nearestLength = matrix[cityOfCountry][j];
                    nearestCity = j;
                }
            }
        }
    }
    (*distributeScale)[nearestCity] = true;
    add(graph->countries[country], position, nearestCity);
    return graph;
}

void printGraph(Graph* graph) {
    for (int country = 0; country < graph->numCities; country++) {
        if (graph->countries[country] != NULL) {
            Position position = first(graph->countries[country]);
            position = next(position); 
            
            int capital = getValue(graph->countries[country], position);
            printf("Capital - %d Cities: ", capital);

            for (int j = 1; j < getLength(graph->countries[country]); j++) {
                position = next(position);
                int city = getValue(graph->countries[country], position);
                printf("%d ", city);
            }
            printf("\n");
        }
    }
}

bool allDistribute(int numCities, bool* distributeScale) {
    for (int i = 0; i < numCities; i++) {
        if (!distributeScale[i]) {
            return false;
        }
    }
    return true;
}

void removeGraph(Graph* graph) {
    for (int i = 0; i < graph->numCities; i++) {
        if (graph->countries[i] != NULL) {
            freeListElements(graph->countries[i]);
        }
    }
}