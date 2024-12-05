#include "graph.h"

void menu() {
    cout << "Menu:" << endl;
    cout << "1. Tambah vertex" << endl;
    cout << "2. Tambah edge" << endl;
    cout << "3. Cari tetangga terdekat" << endl;
    cout << "4. Cari rute terpanjang" << endl;
    cout << "5. Hapus rute" << endl;
    cout << "6. Hapus vertex" << endl;
    cout << "7. Cari alternatif rute" << endl;
    cout << "0. Keluar" << endl;
}

adrVertex createVertex(string newVertex) {
    adrVertex V = new vertex;
    V->infoVertex = newVertex;
    V->nextVertex = NULL;
    return V;

}

void initGraph(graph *G) {
    firstVertex(G) = NULL;
}

void buildGraph(graph *G);
void printGraph(graph *G);

adrEdge createEdge(string destVertexID, int weight) {
    adrEdge E = new edge;
    E->destVertexID = destvertexID;
    E->weight = weight;
    E->nextEdge = NULL;
    return E;
}

void addVertex(graph &G, string newVertex) {
        adrVertex V = createVertex(newVertexID);

        if(firstVertex(G) == NULL) {
            firstVertex(G) = newVertex;
        } else {
            adrVertex P = firstVertex(G);
            while(P->nextVertex!= NULL) {
                P = P->nextVertex;
            }
            P->nextVertex = newVertex;
        }
        cout << "Vertex " << newVertexID << " berhasil ditambahkan." << endl;
}

void addEdge(graph &G, string searchVertexID, string destVertexID, int weight) {
    adrVertex searchVertex = firstVertex(G);
    while (searchVertex != NULL && infoVertex(searchVertex) != searchVertexID) {
        searchVertex = nextVertex(searchVertex);
    }

    if (searchVertex == NULL) {
        cout << "Vertex " << searchVertexID << " tidak ditemukan." << endl;
        return;
    }

    adrEdge newEdge = createEdge(destVertexID, weight) ;
    if (firstEdge(searchVertex) == NULL) {
        firstEdge(searchVertex) = newEdge;
    } else {
        adrEdge P = firstEdge(searchVertex);
        while(P->nextEdge!= NULL) {
            P = P->nextEdge;
        }
        P->nextEdge = newEdge;
    }
        nextEdge(searchVertex) = newEdge;
        /* code */
    }

int shortPathSearching(graph &G, string startVertexID, string endVertexID);
int longPathSearching(graph &G, string startVertexID, string endVertexID);
void removeRoute(graph &G, string startVertexID, string endVertexID);
void removeVertex(graph &G, string idVertex);
void findAlternatifRoutes(graph &G, string startVertexID, string endVertexID);

