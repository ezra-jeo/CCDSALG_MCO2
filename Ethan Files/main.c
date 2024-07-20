typedef char String[256];

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "graph.h"
#include "graph.c"
#include "stack.c"
#include "dfs.c"

int
main() 
{
    String  vertexID;
    String  fileName;
    FILE*   graphFile;
    FILE*   traversalFile;
    Vertex* startVertex = NULL;
    Graph   adjacencyList = NULL;

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

        startVertex = searchVertex(adjacencyList, vertexID);

        if (startVertex == NULL)
            printf("Vertex %s not found.", vertexID);
        else {
            traversalFile = fopen("TRAVERSAL.TXT", "wt");
            exportVertexList(adjacencyList, traversalFile);
            depthFirstSearch(adjacencyList, startVertex, traversalFile);
            fclose(traversalFile);
        }
    }

    return 0;
}