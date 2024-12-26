#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <iostream>
#define firstVertex(G) (G).firstVertex
#define firstEdge(V) (V)->firstEdge
#define nextVertex(V) (V)->nextVertex
#define infoVertex(V) (V)->idVertex
#define destVertexID(E) (E)->destVertexID
#define nextEdge(E) (E)->nextEdge
#define weight(E) (E)->weight
using namespace std;

// Definisi tipe data
typedef struct vertex *adrVertex;
typedef struct edge *adrEdge;

struct vertex {
    string idVertex;
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
void addVertex(graph &G, string newVertexID);
void addEdge(graph &G, string searchVertexID, string destVertexID, int weight);
int shortPathSearching(graph &G, string startVertexID, string endVertexID);
int longPathSearching(graph &G, string startVertexID, string endVertexID);
void removeRoute(graph &G, string startVertexID, string endVertexID);
void removeVertex(graph &G, string idVertex);
void showVertex(graph G);
void showEdge(graph G);
void showAll(graph G);

#endif // GRAPH_H_INCLUDED
