#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.c"
#include "queue.c"
#include "BFS.c"

// void 
// breadthFirstSearch(Graph adjacencyList, String startVertex) 
// {
//     int i;
//     Queue vertexQueue = createQueue();
//     Vertex* currVertex;
//     Vertex* adjacentVertex;
    
//     // Enqueuing the root vertex
//     enqueue(&vertexQueue, searchVertexID(adjacencyList, startVertex));

//     while(!isQueueEmpty(vertexQueue))
//     {
//         currVertex = dequeue(&vertexQueue)->data;

//         printf("%s ", currVertex->ID);
//         currVertex->checked = 1;

//         if (currVertex->degree > 0)
//         {
//             i = 0;
//             adjacentVertex = searchVertexID(adjacencyList, currVertex->adjacentVertexList->ID);
//             while(adjacentVertex != NULL && i < currVertex->degree)
//             {
//                 adjacentVertex->checked = 1;
//                 enqueue(&vertexQueue, adjacentVertex);
//                 i++;
//             }
//         }
//     }
//     printf("\n");
// }

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

        if (searchVertexID(adjacencyList, vertexID) == NULL)
            printf("Vertex %s not found.", vertexID);
        else {
            traversalFile = fopen("TRAVERSAL.TXT", "wt");
            exportVertexList(adjacencyList, traversalFile, vertexID);
            breadthFirstSearch(adjacencyList, traversalFile, vertexID);
            fclose(traversalFile);

        }
    }
    return 0;
}