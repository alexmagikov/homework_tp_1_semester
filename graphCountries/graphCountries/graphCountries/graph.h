#pragma once
#include <stdbool.h>
#include "list.h"

typedef struct Country Country;

typedef struct Graph {
    Country** countries;
    int numCities;
} Graph;

// add capital to country note 
Graph* addCapital(Graph* graph, int capital);

// initialize graph
Graph* createGraph(int numCities);

// add nearest unoccupied city 
Graph* addNote(Graph* graph, int country, int** matrix, bool* distribute);

// print each capital and her cities 
void printGraph(Graph* graph);

void debugPrintGraph(Graph* graph);




