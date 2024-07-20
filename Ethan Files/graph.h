//typedef char String[256];

struct adjacentVertexTag 
{
    String                    ID;
    struct adjacentVertexTag* nextAdjacentVertex;
};

typedef struct adjacentVertexTag AdjacentVertex;

struct vertexTag 
{
    String            ID;
    int               degree;
    int               visitStatus;
    AdjacentVertex*   adjacentVertexList;
    struct vertexTag* nextVertex;
};

typedef struct vertexTag Vertex;

typedef Vertex* Graph;
