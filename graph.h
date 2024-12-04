#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <iostream>
#define firstVertex(G) (G).firstVertex
#define firstEdge(V) (V)->firstEdge
#define nextVertex(V) (V)->nextVertex
#define infoVertex(V) (V)->idVertex
#define destVertexId(V) (V)->destVertexId
#define nextEdge(V) (V)->nextEdge
#define ychjbjbh

using namespace std;

typedef struct vertex *adrVertex;
typedef struct edge *adrEdge;

struct vertex {
    string idVertex;
    adrVertex nextVertex;
    adrEdge firstEdge;
};

struct edge {
    string destVertexID;    // ID vertex tujuan dari edge ini
    int weight;           // Bobot (weight) dari edge (opsional)
    adrEdge nextEdge;     // Pointer ke edge berikutnya
};

struct graph {
    adrVertex firstVertex; // Pointer ke vertex pertama dalam graph
};

// Deklarasi fungsi
void menu();
adrVertex createVertex(char newVertexID);
adrEdge createEdge(string destVertexId, int weight);
void addVertex(graph &G, char newVertexID);
void addEdge(graph &G, string searchVertexID )
int shortPashSearching(graph &G, string startVertexID, string endVertexID);
int longPathSearching(graph &G, string startVertexID, string endVertexID);

#endif // GRAPH_H_INCLUDED
