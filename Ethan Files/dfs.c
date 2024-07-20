// typedef char String[256];
//  #include <stdio.h>
//  #include "graph.c"
//  #include "stack.h"

// For verification
void
printDepthFirstSearchTree(Tree depthFirstSearchTree)
{
    Tree depthFirstSearchTreeVertex = depthFirstSearchTree;

    printf("\nFor checking depth-first search tree: ");

    while (depthFirstSearchTreeVertex != NULL)
    {
        printf("%s ", depthFirstSearchTreeVertex->vertex->ID);
        depthFirstSearchTreeVertex = depthFirstSearchTreeVertex->nextVertex;
    }
    printf("\n\n");
}

void
exportDepthFirstSearchTree(Tree depthFirstSearchTree, FILE** traversalFile) 
{
    Tree depthFirstSearchVertex = depthFirstSearchTree;

    while (depthFirstSearchVertex != NULL)
    {
        fprintf(*traversalFile, "%s ", depthFirstSearchVertex->vertex->ID);
        depthFirstSearchVertex = depthFirstSearchVertex->nextVertex;
    }

    fprintf(*traversalFile, "\n\n");
}

Vertex*
getFirstUnvisitedVertex(Graph adjacencyList, AdjacentVertex* adjacentVertexList) 
{
    AdjacentVertex* adjacentVertex = adjacentVertexList;
    Vertex*         unvisitedVertex = NULL;
    int             found = 0;

    while (!found && adjacentVertex != NULL)
    {
        unvisitedVertex = searchVertex(adjacencyList, adjacentVertex->ID);

        if (unvisitedVertex->visitStatus == 0)
            found = 1;

        adjacentVertex = adjacentVertex->nextAdjacentVertex;
    }

    if (found)
        return unvisitedVertex;
    else
        return NULL;
}

Tree
createTreeNode(Vertex* vertex)
{
    Tree depthFirstSearchVertex = (Tree) malloc (sizeof (Tree));
    depthFirstSearchVertex->vertex = vertex;
    depthFirstSearchVertex->nextVertex = NULL;

    return depthFirstSearchVertex;
}

void
depthFirstSearch(Graph adjacencyList, Vertex* startVertex, FILE* traversalFile) 
{
    Stack   stack = createStack();
    Tree    depthFirstSearchTree = NULL;
    Tree    depthFirstSearchVertex = NULL;
    Tree    lastdepthFirstSearchVertex = NULL;
    Vertex* vertex = NULL;
    Vertex* topVertex = NULL;

    push(&stack, startVertex);
    displayStack(stack);
    depthFirstSearchVertex = createTreeNode(startVertex);
    depthFirstSearchTree = depthFirstSearchVertex;
    lastdepthFirstSearchVertex = depthFirstSearchTree;
    depthFirstSearchVertex->vertex->visitStatus = 1;
    vertex = getFirstUnvisitedVertex(adjacencyList, startVertex->adjacentVertexList);

    if (vertex != NULL)
    {
        do
        {
            push(&stack, vertex);
            displayStack(stack);
            depthFirstSearchVertex = createTreeNode(vertex);
            lastdepthFirstSearchVertex->nextVertex = depthFirstSearchVertex;
            lastdepthFirstSearchVertex = depthFirstSearchVertex; 
            depthFirstSearchVertex->vertex->visitStatus = 1;
            vertex = getFirstUnvisitedVertex(adjacencyList, vertex->adjacentVertexList);

            while (vertex == NULL && !isStackEmpty(stack))
            {
                pop(&stack);
                displayStack(stack);

                if (!isStackEmpty(stack)) {
                    topVertex = getTopVertex(stack);
                    vertex = getFirstUnvisitedVertex(adjacencyList, topVertex->adjacentVertexList);
                }
            }
        } while (!isStackEmpty(stack));
    }
    
    printDepthFirstSearchTree(depthFirstSearchTree);
    exportDepthFirstSearchTree(depthFirstSearchTree, &traversalFile);
}