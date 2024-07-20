// #include <stdio.h>
#include "stack.h"

Stack
createStack()
{
    Stack stack = NULL;

    return stack;
}

Stack
createStackNode(Vertex* vertex)
{
    Stack stackVertexNode = (Stack) malloc (sizeof (Stack));
    stackVertexNode->vertex = vertex;
    stackVertexNode->nextVertex = NULL; 

    return stackVertexNode;
}

void
push(Stack* stack, Vertex* vertex)
{
    Stack stackVertexNode = createStackNode(vertex);

    stackVertexNode->nextVertex = *stack;
    *stack = stackVertexNode;
    printf("\nPush: %s", stackVertexNode->vertex->ID);
}

Vertex*
pop(Stack* stack)
{
    Stack   stackVertexNode = *stack;
    Vertex* vertex = stackVertexNode->vertex;

    *stack = (*stack)->nextVertex;
    free(stackVertexNode);
    printf("\nPop: %s", vertex->ID);

    return vertex;
}

Vertex*
getTopVertex(Stack stack)
{
    Stack stackVertexNode = stack;
    Vertex* vertex = stackVertexNode->vertex;

    return vertex;
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
displayStack(Stack stack)
{
    Stack vertex;

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