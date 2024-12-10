#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
    Graph graph;
    int choice;
    string start, end;
    int weight;

    switch (choice) {
        case 1:
            cout << "Masukkan ID Gudang: ";
            cin >> start;
            graph.addVertex(start);
            break;
        case 2:
            cout << "Masukkan Gudang Asal: ";
            cin >> start;
            cout << "Masukkan Gudang Tujuan: ";
            cin >> end;
            cout << "Masukkan Bobot: ";
            cin >> weight;
            graph.addEdge(start, end, weight);
            break;
        case 3:
            cout << "Masukkan ID Gudang yang akan dihapus: ";
            cin >> start;
            graph.removeVertex(start);
            break;
        case 4:
            cout << "Masukkan Gudang Asal: ";
            cin >> start;
            cout << "Masukkan Gudang Tujuan: ";
            cin >> end;
            graph.removeRoute(start, end);
            break;
        case 5:
            cout << "Masukkan Gudang Asal: ";
            cin >> start;
            cout << "Masukkan Gudang Tujuan: ";
            cin >> end;
            weight = graph.shortPashSearching(start, end);
            if (weight != -1)
                cout << "Jarak terpendek dari " << start << " ke " << end << " adalah " << weight << ".\n";
            break;
        case 6:
            cout << "Masukkan Gudang Asal: ";
            cin >> start;
            cout << "Masukkan Gudang Tujuan: ";
            cin >> end;
            graph.findAlternativeRoutes(start, end);
            break;
        case 7:
            cout << "Keluar dari program. Terima kasih!\n";
            return 0;
        default:
            cout << "Pilihan tidak valid. Coba lagi.\n";
        }
        cout << endl;
}
