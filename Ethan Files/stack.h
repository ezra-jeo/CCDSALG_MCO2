// #include "graph.h"

struct vertexNodeTag {
    Vertex*               vertex;
    struct vertexNodeTag* nextVertex;
};

typedef struct vertexNodeTag* Stack;
typedef struct vertexNodeTag* Tree;