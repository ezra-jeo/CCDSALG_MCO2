#include "graph.h"
#include <stdlib.h>

void
printAdjacencyList(Graph adjacencyList) {
    Vertex*         vertex = adjacencyList;
    AdjacentVertex* adjacentVertex = NULL;

    while (vertex != NULL) {
        printf("%s ", vertex->ID);
        adjacentVertex = vertex->adjacentVertexList;

        while (adjacentVertex != NULL) {
            printf("%s ", adjacentVertex->ID);
            adjacentVertex = adjacentVertex->nextAdjacentVertex;
        }

        printf("\n");
        vertex = vertex->nextVertex;
    }    
}

// Sorting

Graph
representGraph(FILE* graphFile) 
{
    Graph           adjacencyList = NULL;
    Vertex*         vertex = NULL;
    Vertex*         lastVertex = NULL;
    AdjacentVertex* adjacentVertex = NULL;
    AdjacentVertex* lastAdjacentVertex = NULL;
    String          ID;
    int             numVertex;
    int             vertexNum = 0;
    int             end;
    char            dump;

    fscanf(graphFile, "%d", &numVertex);

    while (fscanf(graphFile, "%c", &dump) && vertexNum < numVertex) {
        fscanf(graphFile, "%s", ID);
        vertex = (Vertex*) malloc (sizeof (Vertex));
        strcpy(vertex->ID, ID);
        vertex->adjacentVertexList = NULL;
        vertex->nextVertex = NULL;
        vertexNum++;

        if (adjacencyList == NULL)
            adjacencyList = vertex;
        else {
            lastVertex = adjacencyList;

            while (lastVertex->nextVertex != NULL)
                lastVertex = lastVertex->nextVertex;

            lastVertex->nextVertex = vertex;
        }

        end = 0;
        do
        {
            fscanf(graphFile, "%s", ID);

            if (strcmp(ID, "-1") == 0)
                end = 1;
            else {
                adjacentVertex = (AdjacentVertex*) malloc (sizeof (AdjacentVertex));
                strcpy(adjacentVertex->ID, ID);
                adjacentVertex->nextAdjacentVertex = NULL;

                if (vertex->adjacentVertexList == NULL)
                    vertex->adjacentVertexList = adjacentVertex;
                else {
                    lastAdjacentVertex = vertex->adjacentVertexList;

                    while (lastAdjacentVertex->nextAdjacentVertex != NULL)
                            lastAdjacentVertex = lastAdjacentVertex->nextAdjacentVertex;
                        
                    lastAdjacentVertex->nextAdjacentVertex = adjacentVertex;
                }            
            }
        } while (!end);
    }

    // Sort adjacent vertex list before returning for easy traversing.

    return adjacencyList;
}