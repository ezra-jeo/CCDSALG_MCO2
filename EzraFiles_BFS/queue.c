// This C file contains the implementations and definitions for the operations of a Queue data structure.

#include "queue.h" // Module file for a Queue data structure.


/* createQueue() creates an empty queue and returns it.
   @return the created empty queue.
*/
Queue
createQueue() 
{
    Queue queue;
    
    queue.head = 0;
    queue.tail = 0;
    queue.list = NULL;
    
    return queue;
}

Node*
createNode(Vertex *data)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->nextNode = NULL;

    return newNode;
}

Node*
getNode(int nodeNum, Node *list)
{
    int i;
    Node* node;

    node = list;

    i = 0;
    while(i < nodeNum && node->nextNode != NULL)
    {
        //printf("Error in %d\n", i);
        node = node->nextNode;
        i++;
    }

    return node;

}

/* isQueueEmpty() checks if the given queue is empty or not.
   @param queue - the queue to be considered.
   @return 1 if the queue is empty and 0 if not.
*/
int
isQueueEmpty(Queue queue) 
{
    if (queue.head == queue.tail)
        return 1;
    else
        return 0;
}

/* isQueueFull() checks if the given queue is full or not.
   @param queue - the queue to be considered.
   @return 1 if the queue is full and 0 if not.
*/
int
isQueueFull(Queue queue) 
{
    if (queue.head == (queue.tail + 1) % queue.size)
        return 1;
    else
        return 0;
}

/* enqueue() inserts a character element into the given queue.
   @param queue - the address of the queue where the element will be inserted.
   @param token - the character element that will be inserted into the queue.
   Pre-condition/s: queue is not full.
*/
void
enqueue(Queue* queue, Vertex *data) 
{
    Node* newNode = createNode(data);
    Node* prevNode;

    if (!isQueueEmpty(*queue))
    {   //printf("Case Hello\n");
        prevNode = getNode(queue->tail-1, queue->list);
        prevNode->nextNode = newNode;
    }
    else
    {   
        if (queue->tail > 0)
        {
            prevNode = getNode(queue->tail-1, queue->list);
            prevNode->nextNode = newNode;
        }
        else    
            queue->list = newNode;

        //printf("Case Hi\n");


    }
    
    //printf("Case 0.25\n");

    // Implementation of a circular queue.
    if (queue->tail + 1 != queue->size)
        queue->tail += 1;
    else
        queue->tail = 0;
}

/* dequeue() deletes the first element from the queue and returns it.
   @param queue - the address of the queue where the element will be deleted.
   @return the character element that was deleted from the queue.
   Pre-condition/s: queue is not empty.
*/
Node*
dequeue(Queue* queue) 
{
    Node* headNode = getNode(queue->head, queue->list);

    // Implementation of a circular queue.
    if (queue->head + 1 != queue->size)
        queue->head += 1;
    else
        queue->head = 0;
        
    return headNode;
}

/* getHead() returns the character element at the head of the queue.
   @param queue - the queue to be considered.
   @return the character element at the head of the queue.
*/
Node*
getHead(Queue *queue) 
{
    Node* headNode = getNode(queue->head, queue->list);

    return headNode;

}

/* getTail() returns the character element at the tail of the queue.
   @param queue - the queue to be considered.
   @return the character element at the tail of the queue.
*/
Node*
getTail(Queue *queue) 
{
    Node* tailNode = getNode(queue->tail, queue->list);

    return tailNode;
}
