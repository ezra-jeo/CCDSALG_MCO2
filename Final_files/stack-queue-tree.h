
struct vertexNodeTag 
{
    Vertex*               vertex;
    struct vertexNodeTag* nextVertex;
};

typedef struct vertexNodeTag VertexNode;

typedef VertexNode* Stack;
typedef VertexNode* Tree;

struct queueTag 
{
    VertexNode* headNode;
    VertexNode* tailNode;
};

typedef struct queueTag* Queue;
