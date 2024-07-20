// This module file contains the declarations for the attributes of a Queue data structure.

// #include <string.h>
// #include <stdlib.h>
// #include "graph.h"

#define MAX_SIZE_QUEUE 255 * 2

typedef char String[256];

struct nodeTag
{
    Vertex* data;
    struct nodeTag* nextNode;
};
typedef struct nodeTag Node;
struct queueTag 
{
    int  size;
    int  head;
    int  tail;
    Node* list;
};

typedef struct queueTag Queue;