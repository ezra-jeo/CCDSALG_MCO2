
Vertex*
searchVertex(Graph adjacencyList, String10 vertexID) 
{
    Vertex* vertex = adjacencyList;
    int     found = 0;

    while (vertex != NULL && !found) 
    {
        if (strcasecmp(vertexID, vertex->ID) == 0)
            found = 1;
        else
            vertex = vertex->nextVertex;
    }

    return vertex;
}

void
exportVertexList(Graph adjacencyList, FILE* traversalFile) 
{
    Vertex* vertex = adjacencyList;

    while (vertex != NULL) 
    {
        fprintf(traversalFile, "%-10s %d\n", vertex->ID, vertex->degree);
        vertex = vertex->nextVertex;
    }

    fprintf(traversalFile, "\n");
}

void
resetVisitStatus(Graph adjacencyList)
{
    Vertex* vertex = adjacencyList;

    while (vertex != NULL)
    {
        vertex->visitStatus = 0;
        vertex = vertex->nextVertex;
    }
}

void
swapVertexID(AdjacentVertex* adjacentVertex1, AdjacentVertex* adjacentVertex2)
{
    String10 tempID;

    strcpy(tempID, adjacentVertex2->ID);
    strcpy(adjacentVertex2->ID, adjacentVertex1->ID);
    strcpy(adjacentVertex1->ID, tempID);
}

void
sortAdjacentVertexLists(Graph adjacencyList) 
{
    Vertex*         vertex = adjacencyList;
    AdjacentVertex* adjacentVertex = NULL;
    AdjacentVertex* startAdjacentVertex = NULL;
    AdjacentVertex* minAdjacentVertex = NULL;

    while (vertex != NULL)
    {
        startAdjacentVertex = vertex->adjacentVertexList;

        if (startAdjacentVertex != NULL)
        {
            while (startAdjacentVertex->nextAdjacentVertex != NULL)
            {
                minAdjacentVertex = startAdjacentVertex;
                adjacentVertex = startAdjacentVertex->nextAdjacentVertex;

                while (adjacentVertex != NULL)
                {
                    if (strcasecmp(minAdjacentVertex->ID, adjacentVertex->ID) > 0)
                        minAdjacentVertex = adjacentVertex;

                    adjacentVertex = adjacentVertex->nextAdjacentVertex;
                }

                if (minAdjacentVertex != startAdjacentVertex)
                    swapVertexID(minAdjacentVertex, startAdjacentVertex);

                startAdjacentVertex = startAdjacentVertex->nextAdjacentVertex;
            }
        }

        vertex = vertex->nextVertex;
    }
}

Vertex*
createGraphVertexNode(String10 vertexID)
{
    Vertex* vertex = (Vertex*) malloc (sizeof (Vertex));
    strcpy(vertex->ID, vertexID);
    vertex->adjacentVertexList = NULL;
    vertex->nextVertex = NULL;
    vertex->degree = 0;
    vertex->visitStatus = 0;

    return vertex;
}

AdjacentVertex*
createGraphAdjacentVertexNode(String10 vertexID)
{
    AdjacentVertex* adjacentVertex = (AdjacentVertex*) malloc (sizeof (AdjacentVertex));
    strcpy(adjacentVertex->ID, vertexID);
    adjacentVertex->nextAdjacentVertex = NULL;

    return adjacentVertex;
}

Graph
representGraph(FILE* graphFile) 
{
    Graph           adjacencyList = NULL;
    Vertex*         vertex = NULL;
    Vertex*         lastVertex = NULL;
    AdjacentVertex* adjacentVertex = NULL;
    AdjacentVertex* lastAdjacentVertex = NULL;
    String10        vertexID;
    int             numVertex;
    int             vertexNum = 0;
    int             end;
    char            dump;

    fscanf(graphFile, "%d", &numVertex);

    while (fscanf(graphFile, "%c", &dump) && vertexNum < numVertex) 
    {
        fscanf(graphFile, "%s", vertexID);
        vertex = createGraphVertexNode(vertexID);
        vertexNum++;

        if (adjacencyList == NULL) 
        {
            adjacencyList = vertex;
            lastVertex = vertex;
        }
        else 
        {
            lastVertex->nextVertex = vertex;
            lastVertex = vertex;
        }

        end = 0;
        do
        {
            fscanf(graphFile, "%s", vertexID);

            if (strcmp(vertexID, "-1") == 0)
                end = 1;
            else 
            {
                adjacentVertex = createGraphAdjacentVertexNode(vertexID);

                if (vertex->adjacentVertexList == NULL) 
                {
                    vertex->adjacentVertexList = adjacentVertex;
                    lastAdjacentVertex = adjacentVertex;
                }
                else 
                {
                    lastAdjacentVertex->nextAdjacentVertex = adjacentVertex;
                    lastAdjacentVertex = adjacentVertex;
                }

                vertex->degree++;        
            }
        } while (!end);
    }

    sortAdjacentVertexLists(adjacencyList);

    return adjacencyList;
}