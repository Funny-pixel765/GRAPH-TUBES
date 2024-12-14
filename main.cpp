#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    graph G;
    G.firstVertex = NULL; // Inisialisasi awal

    int choice;
    string start, end;

    do {
        menu();
        cout << "Masukkan pilihan: ";
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Input tidak valid. Masukkan angka: ";
        }

        switch (choice) {
            case 1:
                cout << "Masukkan ID Gudang: ";
                cin >> start;
                addVertex(G, start);
                break;
            case 2: {
                int weight;
                cout << "Masukkan Gudang Asal: ";
                cin >> start;
                cout << "Masukkan Gudang Tujuan: ";
                cin >> end;
                cout << "Masukkan Bobot: ";
                cin >> weight;
                addEdge(G, start, end, weight);
                break;
            }
            case 3:
                cout << "Masukkan ID Gudang yang akan dihapus: ";
                cin >> start;
                removeVertex(G, start);
                break;
            case 4:
                cout << "Masukkan Gudang Asal: ";
                cin >> start;
                cout << "Masukkan Gudang Tujuan: ";
                cin >> end;
                removeRoute(G, start, end);
                break;
            case 5: {
                int weight;
                cout << "Masukkan Gudang Asal: ";
                cin >> start;
                cout << "Masukkan Gudang Tujuan: ";
                cin >> end;
                weight = shortPathSearching(G, start, end);
                if (weight != -1)
                    cout << "Jarak terpendek dari " << start << " ke " << end << " adalah " << weight << ".\n";
                break;
            }
            case 6:
                cout << "Fitur belum tersedia.\n";
                break;
            case 7:
                cout << "Keluar dari program. Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
        }
        cout << endl;
    } while (choice != 7);

    return 0;
}
