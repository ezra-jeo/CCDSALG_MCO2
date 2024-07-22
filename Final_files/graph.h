
struct adjacentVertexTag 
{
    String10                  ID;
    struct adjacentVertexTag* nextAdjacentVertex;
};

typedef struct adjacentVertexTag AdjacentVertex;

struct vertexTag 
{
    String10          ID;
    int               degree;
    int               visitStatus;
    AdjacentVertex*   adjacentVertexList;
    struct vertexTag* nextVertex;
};

typedef struct vertexTag Vertex;

typedef Vertex* Graph;
