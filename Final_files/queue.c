// #include <stdio.h>
// #include "stack-queue-tree.h"

Queue
createQueue() 
{
    Queue queue = malloc (sizeof (Queue));

    queue->headNode = NULL;
    queue->tailNode = NULL;

    return queue;
}

VertexNode*
createQueueNode(Vertex* vertex)
{
    VertexNode* queueVertexNode = (VertexNode*) malloc (sizeof (VertexNode));
    queueVertexNode->vertex = vertex;
    queueVertexNode->nextVertex = NULL;

    return queueVertexNode;
}

int
isQueueEmpty(Queue queue) 
{
    if (queue->headNode == NULL)
        return 1;
    else
        return 0;
}

void
enqueue(Queue queue, Vertex* vertex) 
{
    VertexNode* queueVertexNode = createQueueNode(vertex);

    if (isQueueEmpty(queue)) 
    {
        queue->headNode = queueVertexNode;
        queue->tailNode = queueVertexNode;
    }
    else 
    {
        queue->tailNode->nextVertex = queueVertexNode;
        queue->tailNode = queueVertexNode;
    }

    printf("\nEnqueue: %s", queueVertexNode->vertex->ID);
}

Vertex*
dequeue(Queue queue) 
{
    VertexNode* queueVertexNode = queue->headNode;
    Vertex*     vertex = queueVertexNode->vertex;

    queue->headNode = queue->headNode->nextVertex;

    if (queue->headNode == NULL)
        queue->tailNode = NULL;

    free(queueVertexNode);

    printf("\nDequeue: %s", vertex->ID);

    return vertex;
}

// For verification
void
displayQueue(Queue queue)
{
    VertexNode* vertex;

    if (isQueueEmpty(queue))
        printf("\nQueue Empty.\n");
    else
    {
        vertex = queue->headNode;
        printf("\nQueue: ");
        while (vertex != NULL)
        {
            printf("%s ", vertex->vertex->ID);
            vertex = vertex->nextVertex;
        }

        printf("\n");
    }
}
