#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.c"

int
main() {
    String fileName;
    FILE*  graphFile;
    Graph  adjacencyList = NULL;

    printf("Input filename: ");
    scanf("%s", fileName);

    graphFile = fopen(fileName, "rt");

    if (graphFile == NULL)
        printf("%s not found.", fileName);
    else {
        adjacencyList = representGraph(graphFile);
        printAdjacencyList(adjacencyList);

        fclose(graphFile);
    }

    return 0;
}