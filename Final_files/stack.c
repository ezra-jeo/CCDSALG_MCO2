
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
}

Vertex*
pop(Stack* stack)
{
    VertexNode* stackVertexNode = *stack;
    Vertex*     vertex = stackVertexNode->vertex;

    *stack = (*stack)->nextVertex;
    free(stackVertexNode);

    return vertex;
}

Vertex*
getTopVertex(Stack stack)
{
    VertexNode* stackVertexNode = stack;
    Vertex*     vertex = stackVertexNode->vertex;

    return vertex;
}
