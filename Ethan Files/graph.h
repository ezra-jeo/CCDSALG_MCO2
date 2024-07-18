// This module file contains the declarations for the attributes of a Graph data structure.

typedef char String[256];

struct adjacentVertexTag {
    String                    ID;
    struct adjacentVertexTag* nextAdjacentVertex;
};

typedef struct adjacentVertexTag AdjacentVertex;

struct vertexTag {
    String            ID;
    AdjacentVertex*   adjacentVertexList;
    struct vertexTag* nextVertex;
};

typedef struct vertexTag Vertex;

typedef Vertex* Graph;
