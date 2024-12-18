#include "graph.h"

int main() {
    Graph* graph = createGraph();
    BFS(graph, 1);
    return 0;
}