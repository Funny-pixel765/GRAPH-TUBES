
#include <iostream>
#include "graph.h"

using namespace std;

int main() {
    graph G;
    G.firstVertex = NULL; // Inisialisasi awal
    addVertex(G, "GudangA");
    addVertex(G, "GudangB");
    addVertex(G, "GudangC");
    addVertex(G, "GudangD");
    addVertex(G, "GudangE");
    addVertex(G, "GudangF");
    addVertex(G, "GudangG");
    addVertex(G, "GudangH");
    addVertex(G, "GudangI");

    addEdge(G,"GudangA","GudangB",5);
    addEdge(G,"GudangB","GudangD",8);
    addEdge(G,"GudangD","GudangC",12);
    addEdge(G,"GudangC","GudangH",20);
    addEdge(G,"GudangE","GudangA",2);
    addEdge(G,"GudangG","GudangE",18);
    addEdge(G,"GudangI","GudangB",11);
    addEdge(G,"GudangF","GudangH",3);
    addEdge(G,"GudangE","GudangI",28);

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
                showVertex(G);
                break;
            case 2:
                showEdge(G);
                break;
            case 3:
                showAll(G);
                break;
            case 4: {
                string gudang;
                cout << "Masukan nama gudang yang akan ditambah: ";
                cin >> gudang;
                addVertex(G,gudang);
                break;
            }
            case 5:{
                string gudangAsal;
                string gudangTujuan;
                int jarak;
                cout << "Masukkan Gudang Asal: ";
                cin >> gudangAsal;
                cout << "Masukkan Gudang Tujuan: ";
                cin >> gudangTujuan;
                cout << "Masukan jarak:";
                cin >> jarak;
                addEdge(G,gudangAsal,gudangTujuan,jarak);
                break;
            }
            case 6: {
                cout << "Masukkan Gudang Asal: ";
                cin >> start;
                cout << "Masukkan Gudang Tujuan: ";
                cin >> end;
                removeRoute(G, start, end);
                break;
            }
            case 7: {
                cout << "Masukkan Gudang Asal: ";
                cin >> start;
                cout << "Masukkan Gudang Tujuan: ";
                cin >> end;
                removeRoute(G, start, end);
                break;
            }
            case 8: {
                cout << "Masukkan Gudang Asal: ";
                cin >> start;
                cout << "Masukkan Gudang Tujuan: ";
                cin >> end;
                int result = shortPathSearching(G, start, end);
                if (result != -1) {
                    cout << "Jarak terpendek dari " << start << " ke " << end << " adalah " << result << endl;
                } else {
                    cout << "Tidak ada jalur yang tersedia dari " << start << " ke " << end << "." << endl;
                }
                break;
            }
            case 9: {
                cout << "Masukkan Gudang Asal: ";
                cin >> start;
                cout << "Masukkan Gudang Tujuan: ";
                cin >> end;
                int result = longPathSearching(G, start, end);
                if (result != -1) {
                    cout << "Jarak terpanjang dari " << start << " ke " << end << " adalah " << endl;
                } else {
                    cout << "Tidak ada jalur yang tersedia dari " << start << " ke " << end << "." << endl;
                }
                break;
            }
            case 10:
                cout << "Keluar dari program. Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
        }
        cout << endl;
    } while (choice < 10);

    return 0;
}
