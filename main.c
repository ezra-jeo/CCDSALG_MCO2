#include <stdio.h>
#include "graph.c"

int main()
{
    Graph test = createGraph();
    Vertex v1 = createVertex("Bruce");
    Vertex v2 = createVertex("Clark");
    Vertex v3 = createVertex("Diana");
    Vertex v4 = createVertex("Hal");

    //Vertex v5 = createVertex("Barry");
    // addVertex(v1, &test);
    // addVertex(v2, &test);
    // addVertex(v3, &test);
    // addVertex(v4, &test);

    adjacencyList(test);

    addEdge(&v1, &v3);
    addEdge(&v2, &v3);
    addEdge(&v2, &v4);
    addEdge(&v3, &v1);
    addEdge(&v3, &v2);
    addEdge(&v3, &v4);
    addEdge(&v4, &v2);
    addEdge(&v4, &v3);

    addVertex(v1, &test);
    addVertex(v2, &test);
    addVertex(v3, &test);
    addVertex(v4, &test);

    adjacencyList(test);

    return 0;
}