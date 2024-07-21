// #include <stdio.h>
// #include "stack-queue-tree.h"

Stack
createStack()
{
    Stack stack = NULL;

    return stack;
}

VertexNode*
createStackNode(Vertex* vertex)
{
    VertexNode* stackVertexNode = (VertexNode*) malloc (sizeof (VertexNode));
    stackVertexNode->vertex = vertex;
    stackVertexNode->nextVertex = NULL; 

    return stackVertexNode;
}

int
isStackEmpty(Stack stack)
{
    if (stack == NULL)
        return 1;
    else
        return 0;
}

void
push(Stack* stack, Vertex* vertex)
{
    VertexNode* stackVertexNode = createStackNode(vertex);

    stackVertexNode->nextVertex = *stack;
    *stack = stackVertexNode;
    printf("\nPush: %s", stackVertexNode->vertex->ID);
}

Vertex*
pop(Stack* stack)
{
    VertexNode* stackVertexNode = *stack;
    Vertex*     vertex = stackVertexNode->vertex;

    *stack = (*stack)->nextVertex;
    free(stackVertexNode);
    printf("\nPop: %s", vertex->ID);

    return vertex;
}

Vertex*
getTopVertex(Stack stack)
{
    VertexNode* stackVertexNode = stack;
    Vertex*     vertex = stackVertexNode->vertex;

    return vertex;
}

// For verification
void
displayStack(Stack stack)
{
    VertexNode* vertex;

    if (isStackEmpty(stack))
        printf("\nStack Empty.\n");
    else 
    {
        vertex = stack;
        printf("\nStack: ");
        while (vertex != NULL) 
        {
            printf("%s ", vertex->vertex->ID);
            vertex = vertex->nextVertex;
        }
        printf("\n");
    }
}