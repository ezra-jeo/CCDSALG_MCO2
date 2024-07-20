//#include <stdio.h>
#include "graph.h"

// For verification
void
printAdjacencyList(Graph adjacencyList) 
{
    Vertex*         vertex = adjacencyList;
    AdjacentVertex* adjacentVertex = NULL;

    printf("\nFor checking adjacency list: ");

    while (vertex != NULL) 
    {
        printf("\n%s ", vertex->ID);
        adjacentVertex = vertex->adjacentVertexList;

        while (adjacentVertex != NULL) 
        {
            printf("%s ", adjacentVertex->ID);
            adjacentVertex = adjacentVertex->nextAdjacentVertex;
        }

        printf("%d", vertex->degree);
        vertex = vertex->nextVertex;
    }    

    printf("\n\n");
}

Vertex*
searchVertex(Graph adjacencyList, String vertexID) 
{
    Vertex* vertex = adjacencyList;
    int     found = 0;

    while (vertex != NULL && !found) 
    {
        if (strcasecmp(vertexID, vertex->ID) == 0)
            found = 1;
        else
            vertex = vertex->nextVertex;
    }

    return vertex;
}

void
exportVertexList(Graph adjacencyList, FILE* traversalFile) 
{
    Vertex* vertex = adjacencyList;

    while (vertex != NULL) 
    {
        fprintf(traversalFile, "%s\t%d\n", vertex->ID, vertex->degree);
        vertex = vertex->nextVertex;
    }

    fprintf(traversalFile, "\n");
}

void
swapVertexID(AdjacentVertex* adjacentVertex1, AdjacentVertex* adjacentVertex2)
{
    String tempID;

    strcpy(tempID, adjacentVertex2->ID);
    strcpy(adjacentVertex2->ID, adjacentVertex1->ID);
    strcpy(adjacentVertex1->ID, tempID);
}

void
sortAdjacentVertexLists(Graph adjacencyList) 
{
    Vertex*         vertex = adjacencyList;
    AdjacentVertex* adjacentVertex = NULL;
    AdjacentVertex* startAdjacentVertex = NULL;
    AdjacentVertex* minAdjacentVertex = NULL;

    while (vertex != NULL)
    {
        startAdjacentVertex = vertex->adjacentVertexList;

        while (startAdjacentVertex->nextAdjacentVertex != NULL)
        {
            minAdjacentVertex = startAdjacentVertex;
            adjacentVertex = startAdjacentVertex->nextAdjacentVertex;

            while (adjacentVertex != NULL)
            {
                if (strcasecmp(minAdjacentVertex->ID, adjacentVertex->ID) > 0)
                    minAdjacentVertex = adjacentVertex;

                adjacentVertex = adjacentVertex->nextAdjacentVertex;
            }

            if (minAdjacentVertex != startAdjacentVertex)
                swapVertexID(minAdjacentVertex, startAdjacentVertex);

            startAdjacentVertex = startAdjacentVertex->nextAdjacentVertex;
        }

        vertex = vertex->nextVertex;
    }
}

Vertex*
createGraphVertexNode(String vertexID)
{
    Vertex* vertex = (Vertex*) malloc (sizeof (Vertex));
    strcpy(vertex->ID, vertexID);
    vertex->adjacentVertexList = NULL;
    vertex->nextVertex = NULL;
    vertex->degree = 0;
    vertex->visitStatus = 0;

    return vertex;
}

AdjacentVertex*
createGraphAdjacentVertexNode(String vertexID)
{
    AdjacentVertex* adjacentVertex = (AdjacentVertex*) malloc (sizeof (AdjacentVertex));
    strcpy(adjacentVertex->ID, vertexID);
    adjacentVertex->nextAdjacentVertex = NULL;

    return adjacentVertex;
}

Graph
representGraph(FILE* graphFile) 
{
    Graph           adjacencyList = NULL;
    Vertex*         vertex = NULL;
    Vertex*         lastVertex = NULL;
    AdjacentVertex* adjacentVertex = NULL;
    AdjacentVertex* lastAdjacentVertex = NULL;
    String          vertexID;
    int             numVertex;
    int             vertexNum = 0;
    int             end;
    char            dump;

    fscanf(graphFile, "%d", &numVertex);

    while (fscanf(graphFile, "%c", &dump) && vertexNum < numVertex) 
    {
        fscanf(graphFile, "%s", vertexID);
        vertex = createGraphVertexNode(vertexID);
        vertexNum++;

        if (adjacencyList == NULL) 
        {
            adjacencyList = vertex;
            lastVertex = vertex;
        }
        else 
        {
            lastVertex->nextVertex = vertex;
            lastVertex = vertex;
        }

        end = 0;
        do
        {
            fscanf(graphFile, "%s", vertexID);

            if (strcmp(vertexID, "-1") == 0)
                end = 1;
            else 
            {
                adjacentVertex = createGraphAdjacentVertexNode(vertexID);

                if (vertex->adjacentVertexList == NULL) 
                {
                    vertex->adjacentVertexList = adjacentVertex;
                    lastAdjacentVertex = adjacentVertex;
                }
                else 
                {
                    lastAdjacentVertex->nextAdjacentVertex = adjacentVertex;
                    lastAdjacentVertex = adjacentVertex;
                }

                vertex->degree++;        
            }
        } while (!end);
    }

    sortAdjacentVertexLists(adjacencyList);
    printAdjacencyList(adjacencyList);
    
    return adjacencyList;
}