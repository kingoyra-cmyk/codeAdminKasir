#include <iostream>
using namespace std;

string kodeBarang[100] = {"P001", "P002", "P003", "P004", "P005", "P006"};
string namaBarang[100] = {"Indomie Goreng", "Ultramilk Coklat", "Buku Sinar Dunia", "Pulpen Pilot", "Chitato Rasa Ayam", "Coca Cola"};
string kategori[100] = {"Makanan", "Minuman", "ATK", "ATK", "Snack", "Minuman"};
int harga[100] = {3000, 6000, 5000, 2500, 12000, 8000};
int stok[100] = {50, 24, 100, 85, 10, 75};
int totalBarang = 6;
int totalTransaksi = 0;

void struk(string namaBarang[], int qty[], int hargaBarang[], int subTotal[], int totalSementara, float diskon, int total, int bayar, int totalTransaksi) {
    cout << "====================================================" << endl;
    cout << "|                        TOKO                      |" << endl;
    cout << "|          Jln. Koding No. 1 Jakarta               |" << endl;
    cout << "====================================================" << endl;
    cout << "| Tgl\t: 12/01/2026 12:00                          |" << endl;
    cout << "| Kasir\t: kasir1                                  |" << endl;
    cout << "----------------------------------------------------" << endl; 
    for (int i = 0; i < totalTransaksi; i++) {
        cout << namaBarang[i] << endl;
        cout << "  " << qty[i] << " x " << hargaBarang[i] << "\t\t" << subTotal[i] << endl;
    }
    cout << "----------------------------------------------------" << endl;
    cout << "Subtotal: \t\t" << totalSementara << endl;
    cout << "Diskon: \t\t" << diskon << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Total\t: \t\t" << total << endl;
    cout << "Bayar\t: \t\t" << bayar << endl;
    cout << "Kembali\t: \t\t" << bayar - total << endl;
    cout << "====================================================" << endl;
    cout << "|          TERIMA KASIH TELAH BERBELANJA           |" << endl;
    cout << "|              BARANG YANG SUDAH DIBELI            |" << endl;
    cout << "|             TIDAK DAPAT DITUKAR KEMBALI          |" << endl;
    cout << "====================================================" << endl;
    
    cout << "Simulasi Cetak Struk Selesai..." << endl;
    cout << "[Tekan Enter Kembali]" << endl;        
}

void transaksiPenjualan(string kodeBarang[], string namaBarang[], string kategori[], int harga[], int stok[], int totalBarang) {
    string nama = "";
    int pilihan, totalSementara = 0;
    string kode[100];
    string namaDibeli[100];
    int qty[100];
    float hargaDiskon;
    int index;
    int subTotal[100];
    float diskon = 0;
    int nominal;

    do {
        cout << "====================================================" << endl;
        cout << "          SISTEM POS MANAJEMEN TOKO V.PRO           " << endl;
        cout << "====================================================" << endl;
        cout << " User\t: kasir1" << endl;
        cout << " Status\t: KASIR" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << ">> TRANSAKSI: ";
        if (nama == "") {
            getline(cin, nama);
        } else {
            cout << nama << endl;
        }
        cout << "----------------------------------------------------" << endl;
        cout << "NO\tITEM\t\tQTY\tSUBTOTAL" << endl;
        cout << "----------------------------------------------------" << endl;

        for (int i = 0; i < totalTransaksi; i++) {
            cout << i + 1 << " " << namaDibeli[i] << "\t" << qty[i] << "\t " << subTotal[i] << endl;
            totalSementara += subTotal[i];
        }
        cout << "-----------------------------------------" << endl;
        cout << "TOTAL SEMENTARA: Rp" << totalSementara << endl;
        cout << "-----------------------------------------" << endl;
        cout << "[1] Scan Item  |  [2] Bayar  | [0] Batal" << endl;
        cout << "> ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            cout << "Kode Barang: ";
            cin >> kode[totalTransaksi];

            for (int i = 0; i <= totalBarang; i++) {
                if (kodeBarang[i] == kode[totalTransaksi]) {
                    cout << namaBarang[i] << " @ " << harga[i] << " (Stok: " << stok[i] << ")" << endl;
                    index = i;
                    namaDibeli[totalTransaksi] = namaBarang[i];
                }

            }

            if (stok[index] <= 0) {
                cout << "Stok Habis." << endl;
            } else {
                do {
                    cout << "Qty: ";
                    cin >> qty[totalTransaksi];
                    cin.ignore();
                    
                    if (qty[totalTransaksi] > stok[index]) {
                        cout << "Stok tidak cukup." << endl;
                    } 
                } while (qty[totalTransaksi] > stok[index]);

                    if (qty[totalTransaksi] >= 5) {
                        hargaDiskon = harga[index] * 0.03;
                        cout << " [INFO] Dapat Diskon Grosir Rp " << hargaDiskon << "/pcs!" << endl;
                    }

                    stok[index] -= qty[totalTransaksi];

                    cout << endl;

                    subTotal[totalTransaksi] = (harga[index] - hargaDiskon) * qty[totalTransaksi];
                    totalTransaksi++;
            }

            
        } else if (pilihan == 2) {
            if (totalSementara >= 100000) {
                diskon = totalSementara * 0.05;
            }

            int total = totalSementara - diskon;
            cout << "\n--- PEMBAYARAN ---" << endl;
            cout << "Subtotal: Rp" << totalSementara << endl;
            cout << "Diskon: Rp" << diskon << endl;
            cout << "Netto: Rp" << total << endl;
            cout << "Nominal: Rp";
            cin >> nominal;

            struk(namaBarang, qty, harga, subTotal, totalSementara, diskon, total, nominal, totalTransaksi);
            break;
        }
        
    } while (pilihan != 0);
}

void menu() {
    int pilihan;

    do {
        cout << "====================================================" << endl;
        cout << "          SISTEM POS MANAJEMEN TOKO V.PRO           " << endl;
        cout << "====================================================" << endl;
        cout << " User\t: kasir1" << endl;
        cout << " Status\t: KASIR" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << ">> MENU DASHBOARD" << endl;
        cout << "[1] Kelola Data Barang (LOCKED)" << endl;
        cout << "[2] Transaksi Kasir" << endl;
        cout << "[3] Laporan Penjualan" << endl;
        cout << "[9] Logout" << endl;
        cout << "[0] Keluar Aplikasi" << endl;
        cout << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();
        cout << endl;

        switch (pilihan) {
            case 1:
                break;

            case 2:
                transaksiPenjualan(kodeBarang, namaBarang, kategori, harga, stok, totalBarang);
                break;
            
            case 3:
                break;
            
            case 9:
                cout << "Terima kasih" << endl;
                break;
            
            default:
                cout << "Input tidak valid." << endl;
                break;
        }
    } while (pilihan != 9);
}

int main() {
    menu();
}
