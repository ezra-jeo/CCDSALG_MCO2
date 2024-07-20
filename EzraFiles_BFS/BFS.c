// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include "graph.c"


void 
breadthFirstSearch(Graph adjacencyList, FILE* traversalFile, String startVertex) 
{
    int i;
    Queue vertexQueue = createQueue();
    Vertex* currVertex;
    AdjacentVertex* adjacentVertex;
    Vertex* temp;
    
    // Enqueuing the root vertex
    //printf("Case 0\n");
    enqueue(&vertexQueue, searchVertexID(adjacencyList, startVertex));
    
    //printf("Case 0.5\n");

    while(!isQueueEmpty(vertexQueue))
    {
        //printf("Case 1\n");
        //printf("Head: %s\n", getNode(vertexQueue.head, vertexQueue.list)->data->ID);
        currVertex = dequeue(&vertexQueue)->data;

        fprintf(traversalFile,"%s ", currVertex->ID);
        currVertex->checked = 1;

        if (currVertex->degree > 0)
        {
            //printf("Case 2\n");

            i = 0;
            adjacentVertex = currVertex->adjacentVertexList;

            while(adjacentVertex != NULL && i < currVertex->degree)
            {
                temp = searchVertexID(adjacencyList, adjacentVertex->ID);
                //printf("Case 2.5 %s\n", temp->ID);

                if (!(temp->checked)) 
                {
                    //printf("Case 3\n");
                    temp->checked = 1;
                    enqueue(&vertexQueue, temp);
                    //printf("Enqueued %s\n", temp->ID);
                }
                //printf("Case 2.75\n");
                adjacentVertex = adjacentVertex->nextAdjacentVertex;
                i++;

            }
        }
    }
    printf("\n");
}

/*
    Queue vertexQueue = createQueue();
    Vertex currVertex;
    Vertex adjacentVertex;
    int i;
    int vertexCount = 0;
    // First vertex;
    enqueue(&vertexQueue, graph->vertices[searchVertex(startId, *graph)]);
    //printf("Case 0\n");

    while (isQueueEmpty(vertexQueue) == 0) {
        //printf("Case 1\n");
    
        currVertex = dequeue(&vertexQueue);
        
        printf("%s ", currVertex.id);
        currVertex.checked = 1;
        graph->vertices[searchVertex(currVertex.id, *graph)] = currVertex;

        if (currVertex.degree > 0)
        {
            for (i = 0; i < currVertex.degree; i++) 
            {
                adjacentVertex = graph->vertices[searchVertex(currVertex.edges[i], *graph)];
                
                if (adjacentVertex.checked == 0) {
                    enqueue(&vertexQueue, adjacentVertex);
                    adjacentVertex.checked = 1;
                    graph->vertices[searchVertex(adjacentVertex.id, *graph)] = adjacentVertex;

                }
            }
        }
    }

    printf("\n");

 */