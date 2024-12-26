#include "graph.h"
using namespace std;

void menu(){
    cout << "===== MENU PENGOLAHAN GRAF GUDANG =====\n";
    cout << "1. Lihat semua Gudang yang tersedia\n";
    cout << "2. Lihat semua Jarak yang tersedia\n";
    cout << "3. Lihat semua Gudang beserta Jarak antar Gudang\n";
    cout << "4. Tambah Gudang Baru\n";
    cout << "5. Tambah Rute Antar Gudang\n";
    cout << "6. Hapus Gudang\n";
    cout << "7. Hapus Rute Antar Gudang\n";
    cout << "8. Cari Jarak Terpendek Antar Gudang\n";
    cout << "9. Cari Jarak Terpanjang Antar Gudang\n";
    cout << "10. Keluar\n";
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

}

void addEdge(graph &G, string searchVertexID, string destVertexID, int weight) {
    adrVertex searchVertex = firstVertex(G);

    // Cari vertex asal
    while (searchVertex != NULL && infoVertex(searchVertex) != searchVertexID) {
        searchVertex = nextVertex(searchVertex);
    }

    if (searchVertex == NULL) {
        cout << "Gudang asal " << searchVertexID << " tidak ditemukan." << endl;
        return;
    }

    adrEdge currentEdge = firstEdge(searchVertex);

    // Cek apakah rute sudah ada
    while (currentEdge != NULL) {
        if (currentEdge->destVertexID == destVertexID) {
            // Jika rute ditemukan, perbarui jarak
            currentEdge->weight = weight;
            cout << "Rute dari " << searchVertexID << " ke " << destVertexID << " telah diperbarui menjadi " << weight << "." << endl;
            return;
        }
        currentEdge = currentEdge->nextEdge;
    }

    // Jika rute belum ada, tambahkan rute baru
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
}


int shortPathSearching(graph &G, string startVertexID, string endVertexID) {
    const int MAX_VERTEX = 100;
    int jarak[MAX_VERTEX];
    bool visited[MAX_VERTEX];
    adrVertex vertexArray[MAX_VERTEX];
    int idxAwal = -1, idxAkhir = -1;

    // Inisialisasi variabel
    int jumlahVertex = 0;
    adrVertex current = firstVertex(G);
    while (current != NULL) {
        vertexArray[jumlahVertex] = current;
        jarak[jumlahVertex] = INT_MAX;
        visited[jumlahVertex] = false;
        if (infoVertex(current) == startVertexID) idxAwal = jumlahVertex;
        if (infoVertex(current) == endVertexID) idxAkhir = jumlahVertex;
        jumlahVertex++;
        current = nextVertex(current);
    }

    if (idxAwal == -1 || idxAkhir == -1) {
        cout << "Error: Vertex awal atau tujuan tidak ditemukan." << endl;
        return -1;
    }

    jarak[idxAwal] = 0;

    for (int i = 0; i < jumlahVertex; ++i) {
        int minJarak = INT_MAX;
        int idxMin = -1;

        // Cari vertex dengan jarak minimum yang belum dikunjungi
        for (int j = 0; j < jumlahVertex; ++j) {
            if (!visited[j] && jarak[j] < minJarak) {
                minJarak = jarak[j];
                idxMin = j;
            }
        }

        if (idxMin == -1) break;
        visited[idxMin] = true;

        adrEdge edge = firstEdge(vertexArray[idxMin]);
        while (edge != NULL) {
            int idxTetangga = -1;
            for (int k = 0; k < jumlahVertex; ++k) {
                if (infoVertex(vertexArray[k]) == destVertexID(edge)) {
                    idxTetangga = k;
                    break;
                }
            }
            if (idxTetangga != -1 && !visited[idxTetangga]) {
                int jarakBaru = jarak[idxMin] + weight(edge); // weight adalah bobot (jarak) edge
                if (jarakBaru < jarak[idxTetangga]) {
                    jarak[idxTetangga] = jarakBaru;
                }
            }
            edge = nextEdge(edge);
        }
    }

    // Return hasil
    if (jarak[idxAkhir] == INT_MAX) {
        cout << "Tidak ada jalur dari " << startVertexID << " ke " << endVertexID << "." << endl;
        return -1;
    } else {
        cout << "Jarak terpendek dari " << startVertexID << " ke " << endVertexID << " adalah " << jarak[idxAkhir] << "." << endl;
        return jarak[idxAkhir];
    }
}

int longPathSearching(graph &G, string startVertexID, string endVertexID) {
    const int MAX_VERTEX = 100;
    int jarak[MAX_VERTEX];
    bool visited[MAX_VERTEX];
    adrVertex vertexArray[MAX_VERTEX];
    int idxAwal = -1, idxAkhir = -1;

    // Inisialisasi variabel
    int jumlahVertex = 0;
    adrVertex current = firstVertex(G);
    while (current != NULL) {
        vertexArray[jumlahVertex] = current;
        jarak[jumlahVertex] = INT_MIN; // Inisialisasi dengan nilai minimum
        visited[jumlahVertex] = false;
        if (infoVertex(current) == startVertexID) idxAwal = jumlahVertex;
        if (infoVertex(current) == endVertexID) idxAkhir = jumlahVertex;
        jumlahVertex++;
        current = nextVertex(current);
    }

    if (idxAwal == -1 || idxAkhir == -1) {
        cout << "Error: Vertex awal atau tujuan tidak ditemukan." << endl;
        return -1;
    }

    jarak[idxAwal] = 0;

    for (int i = 0; i < jumlahVertex; ++i) {
        int maxJarak = INT_MIN;
        int idxMax = -1;

        // Cari vertex dengan jarak maksimum yang belum dikunjungi
        for (int j = 0; j < jumlahVertex; ++j) {
            if (!visited[j] && jarak[j] > maxJarak) {
                maxJarak = jarak[j];
                idxMax = j;
            }
        }

        if (idxMax == -1) break;
        visited[idxMax] = true;

        adrEdge edge = firstEdge(vertexArray[idxMax]);
        while (edge != NULL) {
            int idxTetangga = -1;
            for (int k = 0; k < jumlahVertex; ++k) {
                if (infoVertex(vertexArray[k]) == destVertexID(edge)) {
                    idxTetangga = k;
                    break;
                }
            }
            if (idxTetangga != -1 && !visited[idxTetangga]) {
                int jarakBaru = jarak[idxMax] + weight(edge); // weight adalah bobot (jarak) edge
                if (jarakBaru > jarak[idxTetangga]) {
                    jarak[idxTetangga] = jarakBaru;
                }
            }
            edge = nextEdge(edge);
        }
    }

    // Return hasil
    if (jarak[idxAkhir] == INT_MIN) {
        cout << "Tidak ada jalur dari " << startVertexID << " ke " << endVertexID << "." << endl;
        return -1;
    } else {
        cout << "Jarak terpanjang dari " << startVertexID << " ke " << endVertexID << " adalah " << jarak[idxAkhir] << "." << endl;
        return jarak[idxAkhir];
    }
}


void removeRoute(graph &G, string startVertexID, string endVertexID) {
    adrVertex startVertex = firstVertex(G);
    while (startVertex != NULL && infoVertex(startVertex) != startVertexID) {
        startVertex = nextVertex(startVertex);
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
        cout << "Gudang tidak ditemukan." << endl;
        return;
    }

    if (prevVertex == NULL) {
        firstVertex(G) = nextVertex(currentVertex);
    } else {
        prevVertex->nextVertex = nextVertex(currentVertex);
    }
    delete currentVertex;
    cout << "Gudang berhasil dihapus." << endl;
}

void showVertex(graph G) {
    cout << "\n=============================\n";
    cout << "    Daftar Gudang Terdaftar  \n";
    cout << "=============================\n";

    adrVertex h = firstVertex(G);
    if (h == NULL) {
        cout << "Tidak ada gudang yang tersedia.\n";
    } else {
        while (h != NULL) {
            cout << "- " << infoVertex(h) << endl;
            h = nextVertex(h);
        }
    }
    cout << "=============================\n\n";
}

void showEdge(graph G) {
    cout << "\n===========================================\n";
    cout << "    Daftar Jalur Antar Gudang Beserta Jarak\n";
    cout << "===========================================\n";

    adrVertex v = firstVertex(G);
    if (v == NULL) {
        cout << "Tidak ada jalur yang tersedia.\n";
    } else {
        while (v != NULL) {
            cout << "- Dari Gudang: " << infoVertex(v) << endl;
            adrEdge e = firstEdge(v);
            if (e == NULL) {
                cout << "Tidak ada jalur dari gudang ini.\n";
            } else {
                while (e != NULL) {
                    cout << " Ke " << destVertexID(e)
                         << " dengan jarak " << weight(e) << " KM" << endl;
                    e = nextEdge(e);
                }
            }
            v = nextVertex(v);
        }
    }
    cout << "===========================================\n\n";
}

void showAll(graph G) {
    cout << "\n===========================================\n";
    cout << "   Informasi Semua Gudang dan Rute Terkait \n";
    cout << "===========================================\n";

    adrVertex h = firstVertex(G);
    if (h == NULL) {
        cout << "Graph kosong! Tidak ada gudang yang terdaftar.\n";
    } else {
        while (h != NULL) {
            cout << "Gudang: " << infoVertex(h) << endl;
            adrEdge e = firstEdge(h);
            if (e == NULL) {
                cout << "Tidak ada pengiriman dari gudang ini.\n";
            } else {
                cout << "Rute:\n";
                while (e != NULL) {
                    cout << "Ke " << destVertexID(e)
                         << ", Jarak: " << weight(e) << " KM.\n";
                    e = nextEdge(e);
                }
            }
            h = nextVertex(h);
            cout << "-------------------------------------------\n";
        }
    }
    cout << "===========================================\n\n";
}
