#include <iostream>
#include <string>
using namespace std;

class Toko
{
private:
    string daftarMakanan[100] = {"Dada Ayam Geprek", "Sayap Ayam Geprek", "Paha Bawah Ayam Geprek", "Paha Atas Ayam Geprek", "Data Ayam Crispy", "Sayap Ayam Crispy", "Paha Bawah Ayam Crispy", "Paha Atas Ayam Crispy", "Usus Ayam Crispy", "Jamur Crispy", "Tahu Crispy"};
    int hargaMakanan[100] = {9000, 9000, 9000, 14000, 7000, 7000, 7000, 7000, 5000, 5000, 1000};
    int jumlahMakanan = 11;
    string username[2] = {"admin", "pelanggan"};
    string password[2] = {"admin123", "belibang"};
    // string daftarMakanan[100];
    // int hargaMakanan[100];
    // int jumlahMakanan = 0;
    string namaPesanan[100];
    int hargaPesanan[100];
    int jumlahPesanan[100];
    int totalHargaPesenan = 0;
    int totalPesanan = 0;
    string namaBank[4] = {"Bank Mandiri", "Bank BCA", "Bank BRI", "Bank BNI"};
    int rekeningBank[4] = {123456789, 987654321, 456789123, 321654987};
    string alamatPemesan;
    string nomorTeleponPemesan;
    string namaPemesan;
    bool antar;
    string bayarDengan;
    int totalDibeli[100];
    int totalPesananAntar = 0;
    string namaAntar[100];
    string alamatAntar[100];
    string noHPAntar[100];
    int totalAntar[100];
    string menuAntarNama[100][100];
    int menuAntarJumlah[100][100];
    int menuAntarBanyak[100];
    int jumlahDataAntar = 0;
    int totalPemasukan = 0;

    bool pilihYaTidak(string pertanyaan)
    {
        char pilihan;
        do
        {
            cout << pertanyaan << " (y/n): ";
            cin >> pilihan;
            if (!(pilihan == 'y' || pilihan == 'Y' || pilihan == 'n' || pilihan == 'N'))
            {
                cout << "Masukkan huruf yang benar!!" << endl;
            }
        } while (!(pilihan == 'y' || pilihan == 'Y' || pilihan == 'n' || pilihan == 'N'));
        return (pilihan == 'y' || pilihan == 'Y');
    }

    void loginAdmin()
    {
        int hitung = 1;
        string usernameAdmin, passwordAdmin;
        do
        {
            system("cls");
            cout << "========================================" << endl;
            cout << "             LOGIN ADMIN                " << endl;
            cout << "========================================" << endl;
            if (hitung > 5)
            {
                cout << "Anda sudah salah memasukkan username/password sebanyak 5 kali!!" << endl;
                if (pilihYaTidak("Apakah anda ingin kembali ke home? "))
                {
                    return home();
                }
                else
                {
                    hitung = 1;
                }
            }
            cout << "Masukkan Username: ";
            cin >> usernameAdmin;
            cout << "Masukkan Password: ";
            cin >> passwordAdmin;
            hitung++;
            if (usernameAdmin != username[0] || passwordAdmin != password[0])
            {
                cout << "Username atau Password yang anda masukkan salah!!" << endl;
                system("pause");
            }
        } while (usernameAdmin != username[0] || passwordAdmin != password[0]);
        admin();
    }

    void loginUser()
    {
        int hitung = 1;
        string usernameUser, passwordUser;
        do
        {
            system("cls");
            cout << "========================================" << endl;
            cout << "             LOGIN USER                 " << endl;
            cout << "========================================" << endl;
            if (hitung > 5)
            {
                cout << "Anda sudah salah memasukkan username/password sebanyak 5 kali!!" << endl;
                if (pilihYaTidak("Apakah anda ingin kembali ke home? "))
                {
                    return home();
                }
                else
                {
                    hitung = 1;
                }
            }
            cout << "Masukkan Username: ";
            cin >> usernameUser;
            cout << "Masukkan Password: ";
            cin >> passwordUser;
            hitung++;
            if (usernameUser != username[1] || passwordUser != password[1])
            {
                cout << "Username atau Password yang anda masukkan salah!!" << endl;
                system("pause");
            }
        } while (usernameUser != username[1] || passwordUser != password[1]);
        user();
    }

    void admin()
    {
        int pilihan;
        do
        {
            system("cls");
            cout << "========================================" << endl;
            cout << "               MENU ADMIN               " << endl;
            cout << "========================================" << endl;
            cout << " 1. Lihat Daftar Makanan" << endl;
            cout << " 2. Tambah Menu Makanan" << endl;
            cout << " 3. Edit Menu Makanan" << endl;
            cout << " 4. Hapus Menu Makanan" << endl;
            cout << " 5. Laporan Penjualan" << endl;
            cout << " 6. Home" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Masukkan pilihan: ";
            cin >> pilihan;

            switch (pilihan)
            {
            case 1:
                system("cls");
                liatDaftarMakanan();
                system("pause");
                break;
            case 2:
                tambahMenuMakanan();
                break;
            case 3:
                editMenuMakanan();
                break;
            case 4:
                hapusMenuMakanan();
                break;
            case 5:
                laporanPenjualan();
                break;
            case 6:
                return home();
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                system("pause");
            }
        } while (pilihan != 6);
    }

    void user()
    {
        int pilihan;
        do
        {
            system("cls");
            cout << "========================================" << endl;
            cout << "             MENU PELANGGAN             " << endl;
            cout << "========================================" << endl;
            cout << " 1. Lihat Daftar Makanan" << endl;
            cout << " 2. Pesan Makanan" << endl;
            cout << " 3. Lihat Pesanan" << endl;
            cout << " 4. Hapus Pesanan" << endl;
            cout << " 5. Batalkan Pesanan" << endl;
            cout << " 6. Bayar Pesanan" << endl;
            cout << " 7. Home" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Masukkan pilihan: ";
            cin >> pilihan;

            switch (pilihan)
            {
            case 1:
                system("cls");
                liatDaftarMakanan();
                system("pause");
                break;
            case 2:
                pesanMakanan();
                break;
            case 3:
                system("cls");
                lihatPesanan();
                system("pause");
                break;
            case 4:
                hapusPesanan();
                break;
            case 5:
                batalkanPesanan();
                break;
            case 6:
                bayarPesanan();
                break;
            case 7:
                return home();
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                system("pause");
            }
        } while (pilihan != 7);
    }

    void liatDaftarMakanan()
    {
        cout << "========================================" << endl;
        cout << "            DAFTAR MAKANAN              " << endl;
        cout << "========================================" << endl;
        if (jumlahMakanan != 0)
        {
            for (int i = 0; i < jumlahMakanan; i++)
            {
                cout << " " << i + 1 << ". " << daftarMakanan[i] << " - Rp" << hargaMakanan[i] << endl;
            }
        }
        else
        {
            cout << "Daftar makanan masih kosong. Silakan tambahkan makanan terlebih dahulu." << endl;
        }
        cout << "========================================" << endl;
    }

    void tambahMenuMakanan()
    {
        system("cls");
        cout << "========================================" << endl;
        cout << "         TAMBAH MENU MAKANAN            " << endl;
        cout << "========================================" << endl;
        if (jumlahMakanan == 0)
        {
            cout << "Daftar Makanan masih kosong." << endl;
            cout << "Masukkan Jumlah Makanan yang ingin ditambahkan: ";
            cin >> jumlahMakanan;

            for (int i = 0; i < jumlahMakanan; i++)
            {
                cout << "Masukkan Nama Makanan " << i + 1 << ": ";
                cin.ignore();
                getline(cin, daftarMakanan[i]);
                cout << "Masukkan Harga Makanan " << i + 1 << ": ";
                cin >> hargaMakanan[i];
            }
        }
        else
        {
            do
            {
                cout << "Masukkan Nama Makanan: ";
                cin.ignore();
                getline(cin, daftarMakanan[jumlahMakanan]);
                cout << "Masukkan Harga Makanan: ";
                cin >> hargaMakanan[jumlahMakanan];
                jumlahMakanan++;
            } while (pilihYaTidak("Apakah Anda ingin menambahkan makanan lagi?"));
        }
        cout << "========================================" << endl;
        cout << "Menu makanan berhasil ditambahkan." << endl;
        system("pause");
    }

    void editMenuMakanan()
    {
        system("cls");
        liatDaftarMakanan();
        cout << "========================================" << endl;
        cout << "           EDIT MENU MAKANAN            " << endl;
        cout << "========================================" << endl;
        int index;
        cout << "Masukkan nomor makanan yang ingin diedit: ";
        cin >> index;

        if (index < 1 || index > jumlahMakanan)
        {
            cout << "Nomor makanan tidak valid." << endl;
            system("pause");
            return;
        }

        cout << "Masukkan Nama Makanan Baru: ";
        cin.ignore();
        getline(cin, daftarMakanan[index - 1]);
        cout << "Masukkan Harga Makanan Baru: ";
        cin >> hargaMakanan[index - 1];
        cout << "Menu makanan berhasil diperbarui." << endl;
        cout << "========================================" << endl;
        system("pause");
    }

    void hapusMenuMakanan()
    {
        system("cls");
        liatDaftarMakanan();
        cout << "========================================" << endl;
        cout << "           HAPUS MENU MAKANAN           " << endl;
        cout << "========================================" << endl;
        int index;
        cout << "Masukkan nomor makanan yang ingin dihapus: ";
        cin >> index;

        if (index < 1 || index > jumlahMakanan)
        {
            cout << "Nomor makanan tidak valid. Hapus gagal!!" << endl;
            system("pause");
            return;
        }

        for (int i = index - 1; i < jumlahMakanan - 1; i++)
        {
            daftarMakanan[i] = daftarMakanan[i + 1];
            hargaMakanan[i] = hargaMakanan[i + 1];
        }
        jumlahMakanan--;
        cout << "Menu makanan berhasil dihapus." << endl;
        cout << "========================================" << endl;
        system("pause");
    }

    void laporanPenjualan()
    {
        system("cls");
        cout << "========================================" << endl;
        cout << "         LAPORAN PENJUALAN              " << endl;
        cout << "========================================" << endl;
        cout << "Daftar Menu & Jumlah Dibeli:" << endl;
        for (int i = 0; i < jumlahMakanan; i++)
        {
            cout << " " << i + 1 << ". " << daftarMakanan[i] << " - " << totalDibeli[i] << " kali" << endl;
        }
        cout << "----------------------------------------" << endl;
        cout << "Jumlah Pesanan Antar : " << totalPesananAntar << endl;
        if (totalPesananAntar > 0)
        {
            cout << "Daftar Pesanan Antar:" << endl;
            for (int i = 0; i < jumlahDataAntar; i++)
            {
                cout << " " << i + 1 << ". " << namaAntar[i] << " | " << alamatAntar[i] << " | " << noHPAntar[i] << endl;
                cout << "    Menu: " << endl;
                for (int j = 0; j < menuAntarBanyak[i]; j++)
                {
                    cout << "       " << menuAntarNama[i][j] << " x" << menuAntarJumlah[i][j];
                    cout << endl;
                }
                cout << endl
                     << "   Total: Rp" << totalAntar[i] << endl;
                cout << endl;
            }
        }
        cout << "----------------------------------------" << endl;
        cout << "Total Pemasukan : Rp" << totalPemasukan << endl;
        cout << "========================================" << endl;
        system("pause");
    }

    void pesanMakanan()
    {
        system("cls");
        if (totalPesanan > 0)
        {
            cout << "Anda sudah memesan makanan. Berikut adalah daftar pesanan Anda:" << endl;
            lihatPesanan();
            cout << "Silahkan bayar pesanan anda terlebih dahulu." << endl;
            system("pause");
        }
        else
        {
            liatDaftarMakanan();
            cout << endl
                 << "========================================" << endl;
            cout << "             PESAN MAKANAN              " << endl;
            cout << "========================================" << endl;

            int index;
            int jumlah;
            int pesanan = 0;

            do
            {
                do
                {
                    cout << "Masukkan nomor makanan yang ingin dipesan: ";
                    cin >> index;
                    if (index < 1 || index > jumlahMakanan)
                    {
                        cout << "Nomor makanan tidak valid. Silakan coba lagi." << endl;
                    }
                } while (index < 1 || index > jumlahMakanan);

                do
                {
                    cout << "Berapa banyak makanan yang ingin dipesan? ";
                    cin >> jumlah;
                    if (jumlah <= 0)
                    {
                        cout << "Jumlah harus lebih dari 0. Silakan coba lagi." << endl;
                    }
                } while (jumlah <= 0);

                namaPesanan[pesanan] = daftarMakanan[index - 1];
                hargaPesanan[pesanan] = hargaMakanan[index - 1];
                jumlahPesanan[pesanan] = jumlah;
                totalHargaPesenan += hargaPesanan[pesanan] * jumlahPesanan[pesanan];
                pesanan++;
                totalPesanan++;
            } while (pilihYaTidak("Apakah Anda ingin memesan makanan lain?"));

            if (pilihYaTidak("Apakah Anda Ingin Pesanan Diantar?"))
            {
                pesanAntar();
            }
            else
            {
                cout << "Pesanan Anda tidak akan diantar." << endl;
            }
            cout << "========================================" << endl;
            system("pause");
        }
    }

    void pesanAntar()
    {
        cout << "========================================" << endl;
        cout << "              PESAN ANTAR               " << endl;
        cout << "========================================" << endl;
        cout << "*Pesan antar akan memerlukan biaya tambahan sebesar Rp5000." << endl;
        if (pilihYaTidak("Apakah anda yakin ingin pesan antar?"))
        {
            antar = true;
            cin.ignore();
            cout << "Masukkan Nama Pemesan: ";
            getline(cin, namaPemesan);
            cout << "Masukkan Alamat: ";
            getline(cin, alamatPemesan);
            cout << "Masukkan Nomor Telepon: ";
            cin >> nomorTeleponPemesan;
            totalHargaPesenan += 5000;
            cout << "----------------------------------------" << endl;
            cout << "Pesanan atas nama: " << namaPemesan << endl;
            cout << "Akan diantar ke alamat: " << alamatPemesan << endl;
            cout << "Dengan nomor telepon: " << nomorTeleponPemesan << endl;
            cout << "Biaya antar: Rp5000" << endl;
            cout << "Total Harga Pesanan Anda: Rp" << totalHargaPesenan << endl;
            cout << "----------------------------------------" << endl;
            if (pilihYaTidak("Apakah Anda ingin mengubah alamat atau nomor telepon?"))
            {
                cout << "===== Edit Pesan Antar =====" << endl;
                int pilihan;
                do
                {
                    cout << "Apa yang ingin Anda ubah?" << endl;
                    cout << " 1. Nama Pemesan" << endl;
                    cout << " 2. Alamat" << endl;
                    cout << " 3. Nomor Telepon" << endl;
                    cout << " 4. Edit semua" << endl;
                    cout << " 5. Batal" << endl;
                    cout << "Pilihan: ";
                    cin >> pilihan;

                    switch (pilihan)
                    {
                    case 1:
                        cout << "Masukkan Nama Pemesan Baru: ";
                        cin.ignore();
                        getline(cin, namaPemesan);
                        break;
                    case 2:
                        cout << "Masukkan Alamat Baru: ";
                        cin.ignore();
                        getline(cin, alamatPemesan);
                        break;
                    case 3:
                        cout << "Masukkan Nomor Telepon Baru: ";
                        cin >> nomorTeleponPemesan;
                        break;
                    case 4:
                        cout << "Masukkan Nama Pemesan Baru: ";
                        cin.ignore();
                        getline(cin, namaPemesan);
                        cout << "Masukkan Alamat Baru: ";
                        getline(cin, alamatPemesan);
                        cout << "Masukkan Nomor Telepon Baru: ";
                        cin >> nomorTeleponPemesan;
                        break;
                    case 5:
                        cout << "Pengubahan pesan antar dibatalkan." << endl;
                        break;
                    default:
                        cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                        break;
                    }
                } while (pilihan < 1 || pilihan > 5);
                cout << "Pesan antar berhasil diperbarui." << endl;
            }
        }
        else
        {
            antar = false;
            cout << "Pesanan Anda tidak akan diantar." << endl;
        }
        cout << "========================================" << endl;
    }

    void lihatPesanan()
    {
        cout << "========================================" << endl;
        cout << "           DAFTAR PESANAN ANDA          " << endl;
        cout << "========================================" << endl;
        if (totalPesanan > 0)
        {
            for (int i = 0; i < totalPesanan; i++)
            {
                cout << " " << i + 1 << ". " << namaPesanan[i] << " - Rp" << hargaPesanan[i] << " x " << jumlahPesanan[i] << endl;
            }
            if (antar)
            {
                cout << "----------------------------------------" << endl;
                cout << "Pesanan akan diantar ke: " << alamatPemesan << endl;
                cout << "No. Telepon: " << nomorTeleponPemesan << endl;
                cout << "Biaya antar: Rp5000" << endl;
            }
            cout << "----------------------------------------" << endl;
            cout << "Total Harga: Rp" << totalHargaPesenan << endl;
        }
        else
        {
            cout << "Anda belum memesan makanan." << endl;
        }
        cout << "========================================" << endl;
    }

    void hapusPesanan()
    {
        system("cls");
        cout << "========================================" << endl;
        cout << "             HAPUS PESANAN              " << endl;
        cout << "========================================" << endl;
        if (totalPesanan > 0)
        {
            lihatPesanan();
            int index;
            cout << "Masukkan nomor pesanan yang ingin dihapus: ";
            cin >> index;

            if (index < 1 || index > totalPesanan)
            {
                cout << "Nomor pesanan tidak valid." << endl;
                system("pause");
                return;
            }

            totalHargaPesenan -= hargaPesanan[index - 1] * jumlahPesanan[index - 1];
            for (int i = index - 1; i < totalPesanan - 1; i++)
            {
                namaPesanan[i] = namaPesanan[i + 1];
                hargaPesanan[i] = hargaPesanan[i + 1];
                jumlahPesanan[i] = jumlahPesanan[i + 1];
            }
            totalPesanan--;
            cout << "Pesanan berhasil dihapus." << endl;
        }
        else
        {
            cout << "Anda belum memesan makanan." << endl;
        }
        cout << "========================================" << endl;
        system("pause");
    }

    void batalkanPesanan()
    {
        system("cls");
        cout << "========================================" << endl;
        cout << "           BATALKAN PESANAN             " << endl;
        cout << "========================================" << endl;
        if (totalPesanan > 0)
        {
            lihatPesanan();
            if (pilihYaTidak("Apakah Anda yakin ingin membatalkan pesanan?"))
            {
                totalPesanan = 0;
                totalHargaPesenan = 0;
                if (antar)
                {
                    antar = false;
                    alamatPemesan = "";
                    nomorTeleponPemesan = "";
                }
                cout << "Pesanan berhasil dibatalkan." << endl;
                if (bayarDengan != "")
                {
                    cout << "Pembayaran Anda dengan metode " << bayarDengan << " telah dibatalkan." << endl;
                    bayarDengan = "";
                }
            }
            else
            {
                cout << "Pembatalan pesanan dibatalkan." << endl;
            }
        }
        else
        {
            cout << "Anda belum memesan makanan." << endl;
        }
        cout << "========================================" << endl;
        system("pause");
    }

    void bayarPesanan()
    {
        system("cls");
        cout << "========================================" << endl;
        cout << "             BAYAR PESANAN              " << endl;
        cout << "========================================" << endl;
        if (totalPesanan > 0)
        {
            lihatPesanan();
            int metodePembayaran;
            do
            {
                cout << "Pilih Metode Pembayaran:" << endl;
                cout << " 1. Tunai" << endl;
                cout << " 2. Transfer Bank" << endl;
                cout << " 3. QRIS" << endl;
                cout << "Masukkan pilihan Anda: ";
                cin >> metodePembayaran;

                switch (metodePembayaran)
                {
                case 1:
                    pembayaranTunai();
                    bayarDengan = "Tunai";
                    break;
                case 2:
                    pembayaranTransferBank();
                    bayarDengan = "Transfer Bank";
                    break;
                case 3:
                    pembayaranQRIS();
                    bayarDengan = "QRIS";
                    break;
                default:
                    cout << "Metode pembayaran tidak valid. Silakan coba lagi." << endl;
                    break;
                }
            } while (metodePembayaran < 1 || metodePembayaran > 3);

            struk();
            totalPesanan = 0;
            totalHargaPesenan = 0;
            if (antar)
            {
                antar = false;
                alamatPemesan = "";
                nomorTeleponPemesan = "";
            }
        }
        else
        {
            cout << "Anda belum memesan makanan." << endl;
        }
        cout << "========================================" << endl;
    }

    void pembayaranTunai()
    {
        system("cls");
        cout << "========================================" << endl;
        cout << "           PEMBAYARAN TUNAI             " << endl;
        cout << "========================================" << endl;
        if (totalPesanan > 0)
        {
            lihatPesanan();

            int pembayaran = 0;
            int tampung;

            do
            {
                cout << "Masukkan jumlah uang yang dibayarkan / Tambah pembayaran: Rp";
                cin >> tampung;

                pembayaran += tampung;

                if (pembayaran < totalHargaPesenan)
                {
                    cout << "Uang yang dibayarkan kurang. Silakan tambahkan pembayaran." << endl;
                }

            } while (pembayaran < totalHargaPesenan);

            if (pembayaran > totalHargaPesenan)
            {
                int kembalian = pembayaran - totalHargaPesenan;
                cout << "Pembayaran berhasil. Kembalian Anda: Rp" << kembalian << endl;
            }

            cout << "Terima kasih telah melakukan pembayaran." << endl;
        }
        else
        {
            cout << "Anda belum memesan makanan." << endl;
        }
        cout << "========================================" << endl;
    }

    void pembayaranTransferBank()
    {
        system("cls");
        cout << "========================================" << endl;
        cout << "      PEMBAYARAN TRANSFER BANK          " << endl;
        cout << "========================================" << endl;
        if (totalPesanan > 0)
        {
            lihatPesanan();

            int pilihanBank;
            do
            {
                cout << "----------------------------------------" << endl;
                cout << "Pilih Bank Pembayaran:" << endl;
                for (int i = 0; i < 4; i++)
                {
                    cout << " " << i + 1 << ". " << namaBank[i] << " (Rekening: " << rekeningBank[i] << ")" << endl;
                }
                cout << "Masukkan pilihan Anda: ";
                cin >> pilihanBank;

                if (pilihanBank < 1 || pilihanBank > 4)
                {
                    cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                }
            } while (pilihanBank < 1 || pilihanBank > 4);

            cout << "Silakan transfer ke nomor rekening: " << rekeningBank[pilihanBank - 1] << endl;
            if (pilihYaTidak("Atau anda ingin melakukan pembayaran melalui bank lain?"))
            {
                pembayaranTransferBank();
            }
            else
            {
                cout << "Pembayaran berhasil. Terima kasih telah melakukan pembayaran." << endl;
            }
        }
        else
        {
            cout << "Anda belum memesan makanan." << endl;
        }
        cout << "========================================" << endl;
    }

    void pembayaranQRIS()
    {
        system("cls");
        cout << "========================================" << endl;
        cout << "            PEMBAYARAN QRIS             " << endl;
        cout << "========================================" << endl;
        if (totalPesanan > 0)
        {
            lihatPesanan();

            cout << "Silakan scan QRIS untuk melakukan pembayaran." << endl;
            cout << "+----------------------------------+" << endl;
            cout << "| ##  ##   ####   ##    ##  ###### |" << endl;
            cout << "| ##  ##  ##  ##  ## ## ##  ##     |" << endl;
            cout << "| ######  ##  ##  ## ## ##  ####   |" << endl;
            cout << "| ##  ##  ##  ##  ##    ##  ##     |" << endl;
            cout << "| ##  ##   ####   ##    ##  ###### |" << endl;
            cout << "|                                  |" << endl;
            cout << "| ##  ####  ##  ##   ####  ##  ##  |" << endl;
            cout << "| ##  ##    ##  ##  ##     ##  ##  |" << endl;
            cout << "| ##  ####  ######  ##     ######  |" << endl;
            cout << "| ##    ##  ##  ##  ##     ##  ##  |" << endl;
            cout << "| ##  ####  ##  ##   ####  ##  ##  |" << endl;
            cout << "+----------------------------------+" << endl;

            int pembayaran = 0;
            int tampung;

            do
            {
                cout << "Masukkan jumlah uang yang dibayarkan / Tambah pembayaran" << endl;
                cout << "*Pastikan pembayaran pas (tidak ada kembalian): Rp";
                cin >> tampung;

                pembayaran += tampung;

                if (pembayaran < totalHargaPesenan)
                {
                    cout << "Uang yang dibayarkan kurang. Silakan tambahkan pembayaran." << endl;
                }

            } while (pembayaran < totalHargaPesenan);

            cout << "Pembayaran berhasil. Terima kasih telah melakukan pembayaran." << endl;
        }
        else
        {
            cout << "Anda belum memesan makanan." << endl;
        }
        cout << "========================================" << endl;
    }

    void struk()
    {
        system("cls");
        cout << "========================================" << endl;
        cout << "            STRUK PEMBAYARAN            " << endl;
        cout << "========================================" << endl;
        if (antar)
        {
            cout << "Pesanan atas nama : " << namaPemesan << endl;
            cout << "Alamat           : " << alamatPemesan << endl;
            cout << "Nomor Telepon    : " << nomorTeleponPemesan << endl;
        }
        cout << "----------------------------------------" << endl;
        cout << "Daftar Pesanan Anda:" << endl;
        for (int i = 0; i < totalPesanan; i++)
        {
            cout << " " << i + 1 << ". " << namaPesanan[i] << " - Rp" << hargaPesanan[i] << " x " << jumlahPesanan[i] << endl;
        }
        if (antar)
        {
            cout << "Biaya antar: Rp5000" << endl;
        }
        cout << "----------------------------------------" << endl;
        cout << "Total Harga Pesanan Anda: Rp" << totalHargaPesenan << endl;
        cout << "Metode Pembayaran       : " << bayarDengan << endl;
        cout << "========================================" << endl;
        cout << "Terima kasih telah berbelanja di Toko Kami!" << endl;

        for (int i = 0; i < totalPesanan; i++)
        {
            for (int j = 0; j < jumlahMakanan; j++)
            {
                if (namaPesanan[i] == daftarMakanan[j])
                {
                    totalDibeli[j] += jumlahPesanan[i];
                }
            }
        }

        totalPemasukan += totalHargaPesenan;

        if (antar)
        {
            namaAntar[jumlahDataAntar] = namaPemesan;
            alamatAntar[jumlahDataAntar] = alamatPemesan;
            noHPAntar[jumlahDataAntar] = nomorTeleponPemesan;
            totalAntar[jumlahDataAntar] = totalHargaPesenan;
            menuAntarBanyak[jumlahDataAntar] = totalPesanan;
            for (int i = 0; i < totalPesanan; i++)
            {
                menuAntarNama[jumlahDataAntar][i] = namaPesanan[i];
                menuAntarJumlah[jumlahDataAntar][i] = jumlahPesanan[i];
            }
            jumlahDataAntar++;
            totalPesananAntar++;
        }

        system("pause");
    }

public:
    void home()
    {
        int pilihan;
        do
        {
            system("cls");
            cout << "========================================" << endl;
            cout << "         SELAMAT DATANG DI TOKO         " << endl;
            cout << "========================================" << endl;
            cout << " 1. Admin" << endl;
            cout << " 2. Pelanggan" << endl;
            cout << " 3. Keluar" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Silahkan Pilih: ";
            cin >> pilihan;

            if (pilihan == 1)
            {
                return loginAdmin();
            }
            else if (pilihan == 2)
            {
                return loginUser();
            }
            else if (pilihan == 3)
            {
                system("cls");
                cout << "========================================" << endl;
                cout << "  Terima kasih telah menggunakan sistem!" << endl;
                cout << "========================================" << endl;
                system("pause");
                return;
            }
            else
            {
                cout << "Pilihan yang anda masukkan tidak ada. Silahkan pilih lagi!" << endl;
            }
        } while (pilihan != 3);
    }
};

int main()
{
    Toko toko;
    toko.home();
    return 0;
}