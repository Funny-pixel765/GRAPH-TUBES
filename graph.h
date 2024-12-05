#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <iostream>
#define firstVertex(G) G.firstVertex
#define nextVertex(V) V->nextVertex
#define infoVertex(V) V->infoVertex
#define firstEdge(V) V->firstEdge
#define destvertexID(V) V->destvertexID
#define nextEdge(E) E->nextEdge
#define weight(E) E->weight
using namespace std;

typedef struct vertex *adrVertex;
typedef struct edge *adrEdge;

struct vertex {
    string infoVertex;
    adrVertex nextVertex;
    adrEdge firstEdge;
};

struct edge {
    string destVertexID;
    int weight;
    adrEdge nextEdge;
};

struct graph {
    adrVertex firstVertex;
};

// Deklarasi fungsi
void menu();
adrVertex createVertex(char newVertexID);
adrEdge createEdge(string destVertexId, int weight);
void addVertex(graph &G, char newVertexID);
void addEdge(graph &G, string searchVertexID )
int shortPathSearching(graph &G, string startVertexID, string endVertexID);
int longPathSearching(graph &G, string startVertexID, string endVertexID);
void removeRoute(graph &G, string startVertexID, string endVertexID);
void removeVertex(graph &G, string idVertex);
void findAlternatifRoutes(graph &G, string startVertexID, string endVertexID);

#endif // GRAPH_H_INCLUDED