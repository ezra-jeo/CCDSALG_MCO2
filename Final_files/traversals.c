
void
exportSearchTree(Tree searchTree, FILE** traversalFile) 
{
    VertexNode* searchTreeVertex = searchTree;

    while (searchTreeVertex != NULL)
    {
        fprintf(*traversalFile, "%s ", searchTreeVertex->vertex->ID);
        searchTreeVertex = searchTreeVertex->nextVertex;
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

VertexNode*
createTreeNode(Vertex* vertex)
{
    VertexNode* depthFirstSearchVertex = (VertexNode*) malloc (sizeof (VertexNode));
    depthFirstSearchVertex->vertex = vertex;
    depthFirstSearchVertex->nextVertex = NULL;

    return depthFirstSearchVertex;
}

void
breadthFirstSearch(Graph adjacencyList, Vertex* startVertex, FILE* traversalFile)
{
    Queue           queue = createQueue();
    Tree            breadthFirstSearchTree = NULL;
    VertexNode*     breadthFirstSearchVertex = NULL;
    VertexNode*     lastBreadthFirstSearchVertex = NULL;
    Vertex*         vertex = NULL;
    Vertex*         unvisitedVertex = NULL;

    enqueue(queue, startVertex);
    startVertex->visitStatus = 1;

    while (!isQueueEmpty(queue))
    {
        vertex = dequeue(queue);
        breadthFirstSearchVertex = createTreeNode(vertex);

        if (breadthFirstSearchTree == NULL) 
        {
            breadthFirstSearchTree = breadthFirstSearchVertex;
            lastBreadthFirstSearchVertex = breadthFirstSearchVertex;
        }
        else
        {
            lastBreadthFirstSearchVertex->nextVertex = breadthFirstSearchVertex;
            lastBreadthFirstSearchVertex = breadthFirstSearchVertex;
        }

        if (vertex->adjacentVertexList != NULL) 
        {
            do
            {
                unvisitedVertex = getFirstUnvisitedVertex(adjacencyList, vertex->adjacentVertexList);

                if (unvisitedVertex != NULL)
                {
                    enqueue(queue, unvisitedVertex);
                    unvisitedVertex->visitStatus = 1;
                }
            } while (unvisitedVertex != NULL);
        }
    }

    exportSearchTree(breadthFirstSearchTree, &traversalFile);
}

void
depthFirstSearch(Graph adjacencyList, Vertex* startVertex, FILE* traversalFile) 
{
    Stack       stack = createStack();
    Tree        depthFirstSearchTree = NULL;
    VertexNode* depthFirstSearchVertex = NULL;
    VertexNode* lastDepthFirstSearchVertex = NULL;
    Vertex*     vertex = NULL;
    Vertex*     topVertex = NULL;

    push(&stack, startVertex);
    depthFirstSearchVertex = createTreeNode(startVertex);
    depthFirstSearchTree = depthFirstSearchVertex;
    lastDepthFirstSearchVertex = depthFirstSearchVertex;
    depthFirstSearchVertex->vertex->visitStatus = 1;
    vertex = getFirstUnvisitedVertex(adjacencyList, startVertex->adjacentVertexList);

    if (vertex != NULL)
    {
        do
        {
            push(&stack, vertex);
            depthFirstSearchVertex = createTreeNode(vertex);
            lastDepthFirstSearchVertex->nextVertex = depthFirstSearchVertex;
            lastDepthFirstSearchVertex = depthFirstSearchVertex; 
            depthFirstSearchVertex->vertex->visitStatus = 1;
            vertex = getFirstUnvisitedVertex(adjacencyList, vertex->adjacentVertexList);

            while (vertex == NULL && !isStackEmpty(stack))
            {
                pop(&stack);

                if (!isStackEmpty(stack)) {
                    topVertex = getTopVertex(stack);
                    vertex = getFirstUnvisitedVertex(adjacencyList, topVertex->adjacentVertexList);
                }
            }
        } while (!isStackEmpty(stack));
    }
    
    exportSearchTree(depthFirstSearchTree, &traversalFile);
}