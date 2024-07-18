#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.c"

int
main() 
{
    String vertexID;
    String fileName;
    FILE*  graphFile;
    FILE*  traversalFile;
    Graph  adjacencyList = NULL;

    printf("Input filename: ");
    scanf("%s", fileName);

    graphFile = fopen(fileName, "rt");

    if (graphFile == NULL)
        printf("%s not found.", fileName);
    else 
    {
        adjacencyList = representGraph(graphFile);
        fclose(graphFile);

        printf("Input start vertex for the traversal: ");
        scanf("%s", vertexID);

        if (searchVertexID(adjacencyList, vertexID) == 0)
            printf("Vertex %s not found.", vertexID);
        else {
            traversalFile = fopen("TRAVERSAL.TXT", "wt");
            exportVertexList(adjacencyList, traversalFile);
            fclose(traversalFile);
        }
    }

    return 0;
}