#include "graph.h"
using namespace std;

void menu(){
    cout << "===== MENU PENGOLAHAN GRAF GUDANG =====\n";
    cout << "1. Tambah Gudang Baru\n";
    cout << "2. Tambah Rute Antar Gudang\n";
    cout << "3. Hapus Gudang\n";
    cout << "4. Hapus Rute Antar Gudang\n";
    cout << "5. Cari Jarak Terpendek Antar Gudang\n";
    cout << "6. Cari Harga Terkecil Antar Gudang\n";
    cout << "7. Cari Rute Alternatif Antar Gudang\n";
    cout << "8. Keluar\n";
    cout << "=======================================\n" << endl;
}

adrVertex createVertex(string newVertexID) {
    adrVertex V = new vertex;
    V->idVertex = newVertexID;
    V->nextVertex = NULL;
    V->firstEdge = NULL;
    return V;
}

adrEdge createEdge(string destVertexID, int weight) {
    adrEdge E = new edge;
    E->destVertexID = destVertexID;
    E->weight = weight;
    E->nextEdge = NULL;
    return E;
}

void addVertex(graph &G, string newVertexID) {
    adrVertex V = createVertex(newVertexID);

    if (firstVertex(G) == NULL) {
        firstVertex(G) = V;
    } else {
        adrVertex P = firstVertex(G);
        while (P->nextVertex != NULL) {
            P = P->nextVertex;
        }
        P->nextVertex = V;
    }
    cout << "Vertex " << newVertexID << " berhasil ditambahkan." << endl;
}

void addEdge(graph &G, string searchVertexID, string destVertexID, int weight) {
    cout << "Menambahkan edge dari " << searchVertexID << " ke " << destVertexID << " dengan bobot " << weight << endl;

    adrVertex searchVertex = firstVertex(G);
    while (searchVertex != NULL && infoVertex(searchVertex) != searchVertexID) {
        searchVertex = nextVertex(searchVertex);
    }

    if (searchVertex == NULL) {
        cout << "Vertex asal " << searchVertexID << " tidak ditemukan." << endl;
        return;
    }

    adrEdge newEdge = createEdge(destVertexID, weight);
    if (firstEdge(searchVertex) == NULL) {
        firstEdge(searchVertex) = newEdge;
    } else {
        adrEdge P = firstEdge(searchVertex);
        while (P->nextEdge != NULL) {
            P = P->nextEdge;
        }
        P->nextEdge = newEdge;
    }
    cout << "Edge berhasil ditambahkan dari " << searchVertexID << " ke " << destVertexID << endl;
}

int shortPathSearching(graph &G, string startVertexID, string endVertexID) {
    adrVertex startVertex = firstVertex(G);
    while (startVertex != NULL && infoVertex(startVertex) != startVertexID) {
        startVertex = nextVertex(startVertex);
    }

    if (startVertex == NULL) {
        cout << "Vertex " << startVertexID << " tidak ditemukan." << endl;
        return -1;
    }

    int minWeight = INT_MAX;
    return (minWeight == INT_MAX) ? -1 : minWeight;
}

int longPathSearching(graph &G, string startVertexID, string endVertexID) {
    adrVertex startVertex = firstVertex(G);
    while (startVertex != NULL && infoVertex(startVertex) != startVertexID) {
        startVertex = nextVertex(startVertex);
    }

    if (startVertex == NULL) {
        cout << "Vertex " << startVertexID << " tidak ditemukan." << endl;
        return -1;
    }

    int maxWeight = INT_MIN;
    return (maxWeight == INT_MIN) ? -1 : maxWeight;
}

void removeRoute(graph &G, string startVertexID, string endVertexID) {
    adrVertex startVertex = firstVertex(G);
    while (startVertex != NULL && infoVertex(startVertex) != startVertexID) {
        startVertex = nextVertex(startVertex);
    }

    if (startVertex == NULL) {
        cout << "Gudang tidak ditemukan." << endl;
        return;
    }

    adrEdge prevEdge = NULL;
    adrEdge currentEdge = firstEdge(startVertex);

    while (currentEdge != NULL) {
        if (currentEdge->destVertexID == endVertexID) {
            if (prevEdge == NULL) {
                firstEdge(startVertex) = currentEdge->nextEdge;
            } else {
                prevEdge->nextEdge = currentEdge->nextEdge;
            }
            delete currentEdge;
            cout << "Rute berhasil dihapus." << endl;
            return;
        }
        prevEdge = currentEdge;
        currentEdge = currentEdge->nextEdge;
    }
    cout << "Rute tidak ditemukan." << endl;
}
void removeVertex(graph &G, string idVertex) {
    adrVertex prevVertex = NULL;
    adrVertex currentVertex = firstVertex(G);

    while (currentVertex != NULL && infoVertex(currentVertex) != idVertex) {
        prevVertex = currentVertex;
        currentVertex = nextVertex(currentVertex);
    }

    if (currentVertex == NULL) {
        cout << "Vertex tidak ditemukan." << endl;
        return;
    }

    if (prevVertex == NULL) {
        firstVertex(G) = nextVertex(currentVertex);
    } else {
        prevVertex->nextVertex = nextVertex(currentVertex);
    }
    delete currentVertex;
    cout << "Vertex berhasil dihapus." << endl;
}
