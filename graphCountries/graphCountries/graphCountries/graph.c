#include "graph.h"
#include "list.h"
#include <stdlib.h>

typedef struct Country {
    int capital;
    List* cities;
} Country;

Graph* createGraph(int numCities) {
    Graph* graph = malloc(sizeof(Graph));
    if (graph == NULL) {
        return NULL;
    }
    graph->numCities = numCities;
    graph->countries = calloc(numCities, sizeof(Country*));
    if (graph->countries == NULL) {
        return NULL;
    }
    return graph;
}

Graph* addCapital(Graph* graph, int capital) {
    graph->countries[capital] = malloc(sizeof(Country));
    graph->countries[capital]->capital = capital;
    graph->countries[capital]->cities = createList();
    return graph;
}

Graph* addNote(Graph* graph, int country, int** matrix, bool* distribute) {
    int nearestLength = 1000;
    int nearestCity = -1;

    //for (int = 0; i < getLength(grap))
}

void printGraph(Graph* graph) {

}

void debugPrintGraph(Graph* graph) {
    if (graph == NULL) {
        printf("Graph is NULL\n");
        return;
    }

    printf("Graph info:\n");
    printf("Number of cities: %d\n", graph->numCities);

    printf("Capitals:\n");
    for (int i = 0; i < graph->numCities; i++) {
        if (graph->countries[i] != NULL) {
            printf("City %d: Capital %d, Cities list length: %d\n",
                i,
                graph->countries[i]->capital,
                getLength(graph->countries[i]->cities));
        }
    }
}