#include "graph.h"

typedef struct VertexTag
{
    String id;
    String edges[50];
    int degree;

} Vertex;

typedef struct GraphTag 
{
    Vertex vertices[50];
    int size;

} Graph;

Graph createGraph() 
{
    Graph newGraph;
    Vertex newVertex;

    strcpy(newVertex.id, "");
    strcpy(newVertex.edges[0], "");
    newGraph.vertices[0] = newVertex;
    newGraph.size = 0;

    return newGraph;  
}

Vertex createVertex(String id)
{
    Vertex newVertex;

    strcpy(newVertex.id, id);
    strcpy(newVertex.edges[0], "");
    newVertex.degree = 0;

    return newVertex;
}

int searchVertex(String id, Graph graph)
{
    int i;

    for (i = 0; i < graph.size; i++)
    {
        if (strcmp(graph.vertices[i].id, id) == 0)
            return i;
    }
    return -1;

}

int searchEdge(String id, Vertex vertex)
{
    int i;

    for (i = 0; i < vertex.degree; i++)
    {
        if (strcmp(vertex.edges[i], id) == 0)
            return i;
    }
    return -1;
}

int addVertex(Vertex vertex, Graph *graph) 
{   
    if (searchVertex(vertex.id, *graph) == -1)
    {   
        graph->vertices[graph->size] = vertex;
        graph->size += 1;
        
        return 1;
    }
    else
        return 0;

}

int addEdge(Vertex *vertex1, Vertex *vertex2)
{
    if (searchEdge(vertex1->id, *vertex2) == -1) // Since undirected, if the edge is nonexistent for vertex 1, it is also nonexistent for vertex2.
    {
        strcpy(vertex1->edges[vertex1->degree], vertex2->id);
        strcpy(vertex2->edges[vertex2->degree], vertex1->id);
        vertex1->degree += 1;
        vertex2->degree += 1;
        
        return 1;
    }
    else 
        return 0;
}


void adjacency(Vertex vertex)
{
    int i;

    printf("%s->", vertex.id);

    for (i = 0; i < vertex.degree; i++)
    {
        printf("%s->", vertex.edges[i]);
    }
    printf("\n");

}


void adjacencyList(Graph graph)
{
    int i;

    for (i = 0; i < graph.size; i++)
    {
        adjacency(graph.vertices[i]);
    }
}


/*
TODO: 
*/