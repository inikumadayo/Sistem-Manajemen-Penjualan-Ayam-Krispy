#include <iostream>
#include <string>
using namespace std;

class Toko
{
private:
    string daftarMakanan[100] = {"Dada Ayam Geprek", "Sayap Ayam Geprek", "Paha Bawah Ayam Geprek", "Paha Atas Ayam Geprek", "Dada Ayam Crispy", "Sayap Ayam Crispy", "Paha Bawah Ayam Crispy", "Paha Atas Ayam Crispy", "Usus Ayam Crispy", "Jamur Crispy", "Tahu Crispy"};
    int hargaMakanan[100] = {9000, 9000, 9000, 14000, 7000, 7000, 7000, 7000, 5000, 5000, 1000};
    int jumlahMakanan = 11;

    string daftarMinuman[50] = {"Es Teh", "Es Jeruk", "Es Kopi", "Air Mineral", "Jus Alpukat"};
    int hargaMinuman[50] = {3000, 5000, 4000, 2000, 8000};
    int jumlahMinuman = 5;

    string username[2] = {"admin", "pelanggan"};
    string password[2] = {"admin123", "belibang"};

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
    int totalDibeli[100] = {0};
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
    int kembalian = 0;
    int biayaAntar = 5000;

    string kodePromo[5] = {"DISKON10", "HEMAT20", "GRATISONGKIR", "BELI5", "NEWYEAR"};
    float diskonPromo[5] = {0.1, 0.2, 0.15, 0.05, 0.25};
    string deskripsiPromo[5] = {
        "Diskon 10% untuk semua menu",
        "Diskon 20% dengan minimal pembelian Rp50.000",
        "Gratis ongkir dengan minimal pembelian Rp30.000",
        "Diskon 5% untuk pembelian 5 item atau lebih",
        "Diskon 25% khusus tahun baru"};
    int jumlahPromo = 5;
    float diskonAktif = 0.0;
    string kodePromoAktif = "";

    int stokMakanan[100] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
    int stokMinuman[50] = {100, 100, 100, 100, 100};

    string reviewPelanggan[100];
    int ratingPelanggan[100];
    int jumlahReview = 0;

    string tanggalLaporan[30];
    int pemasukanLaporan[30];
    int pengeluaranLaporan[30];
    int keuntunganLaporan[30];
    int jumlahLaporan = 0;

    string namaKaryawan[10];
    string jabatanKaryawan[10];
    string teleponKaryawan[10];
    string alamatKaryawan[10];
    double gajiKaryawan[10];
    int jumlahKaryawan = 0;

    bool sudahBackup = false;
    string backupDaftarMakanan[100], backupDaftarMinuman[50];
    int backupHargaMakanan[100], backupHargaMinuman[50];
    int backupStokMakanan[100], backupStokMinuman[50];
    int backupTotalDibeli[150];

public:
    void clearScreen();
    void pauseScreen();
    bool pilihYaTidak(string pertanyaan);
    void tampilkanHeader(string judul);
    void tampilkanFooter();

    void loginAdmin();
    void loginUser();
    void admin();
    void user();
    void home();

    void tambahMenu();
    void editMenu();
    void hapusMenu();
    void kelolaPromoMenu();

    void liatDaftarMakanan();
    void liatDaftarMinuman();
    void tambahMenuMakanan();
    void tambahMenuMinuman();
    void editMenuMakanan();
    void editMenuMinuman();
    void hapusMenuMakanan();
    void hapusMenuMinuman();
    void sortirMenu();
    void cariMenu();
    void kelolaStok();

    void lihatStok();
    void tambahStok();
    void kurangiStok();
    void carikanJumlahStok();

    void pesanMakanan();
    void pesanMinuman();
    void pesanAntar();
    void pesanDineIn();
    void lihatPesanan();
    void hapusPesanan();
    void batalkanPesanan();
    void bayarPesanan();
    void applyPromo();

    void pembayaranTunai();
    void pembayaranTransferBank();
    void pembayaranQRIS();
    void pembayaranDigitalWallet();

    void laporanPenjualan();
    void laporanStok();
    void laporanReview();

    void kelolaKaryawan();
    void pengaturanToko();

    void struk();
    void beriReview();
    void tampilkanPromo();
    void tambahPromo();
    void hapusPromo();

    void pilihMetodePengiriman();
};

void Toko::clearScreen()
{
    system("cls");
}

void Toko::pauseScreen()
{
    system("pause");
}

bool Toko::pilihYaTidak(string pertanyaan)
{
    string pilihan;
    cout << "+---------------------------------------------------------------------+" << endl;
    do
    {
        cout << " " << pertanyaan << " (y/n): ";
        cin >> pilihan;
        if (!(pilihan == "y" || pilihan == "Y" || pilihan == "n" || pilihan == "N"))
        {
            cout << " *Tolong masukkan huruf yang benar !!" << endl;
        }
    } while (!(pilihan == "y" || pilihan == "Y" || pilihan == "n" || pilihan == "N"));
    cout << "+---------------------------------------------------------------------+" << endl;
    return (pilihan == "y" || pilihan == "Y");
}

void Toko::tampilkanHeader(string judul)
{
    long long panjangSpasi = (70 - judul.length()) / 2;
    cout << "+=====================================================================+" << endl;
    cout << "|           SISTEM MANAJEMEN TOKO AYAM KRISPY SARI RASA 99            |" << endl;
    cout << "|";
    for (int i = 0; i < panjangSpasi; i++)
    {
        cout << " ";
    }
    cout << judul;
    if (judul.length() % 2 == 0)
    {
        for (int i = 0; i < panjangSpasi - 1; i++)
        {
            cout << " ";
        }
    }
    else
    {
        for (int i = 0; i < panjangSpasi; i++)
        {
            cout << " ";
        }
    }
    cout << "|" << endl;
    cout << "+=====================================================================+" << endl;
}

void Toko::tampilkanFooter()
{
    cout << "+---------------------------------------------------------------------+" << endl;
}

void Toko::loginAdmin()
{
    int hitung = 1;
    string usernameAdmin, passwordAdmin;
    do
    {
        clearScreen();
        tampilkanHeader("LOGIN ADMIN");
        if (hitung > 5)
        {
            cout << " *PERINGATAN!!" << endl;
            cout << "  Anda salah memasukkan username dan password 5x" << endl;
            if (pilihYaTidak("Apakah anda ingin kembali ke home? "))
            {
                home();
                return;
            }
            else
            {
                hitung = 1;
            }
        }
        cout << " Masukkan Username: ";
        cin >> usernameAdmin;
        cout << " Masukkan Password: ";
        cin >> passwordAdmin;
        hitung++;
        if (usernameAdmin != username[0] || passwordAdmin != password[0])
        {
            cout << " *Username atau Password yang anda masukkan salah!!" << endl;
            pauseScreen();
        }
    } while (usernameAdmin != username[0] || passwordAdmin != password[0]);
    admin();
}

void Toko::loginUser()
{
    int hitung = 1;
    string usernameUser, passwordUser;
    do
    {
        clearScreen();
        tampilkanHeader("LOGIN PELANGGAN");
        if (hitung > 5)
        {
            cout << " *PERINGATAN!!" << endl;
            cout << "  Anda salah memasukkan username dan password 5x" << endl;
            if (pilihYaTidak("Apakah anda ingin kembali ke home? "))
            {
                home();
                return;
            }
            else
            {
                hitung = 1;
            }
        }
        cout << " Masukkan Username: ";
        cin >> usernameUser;
        cout << " Masukkan Password: ";
        cin >> passwordUser;
        hitung++;
        if (usernameUser != username[1] || passwordUser != password[1])
        {
            cout << " *Username atau Password yang anda masukkan salah!!" << endl;
            pauseScreen();
        }
    } while (usernameUser != username[1] || passwordUser != password[1]);
    user();
}

void Toko::admin()
{
    string pilihan;
    do
    {
        clearScreen();
        tampilkanHeader("MENU ADMIN");
        cout << "  1. Lihat Daftar Menu" << endl;
        cout << "  2. Tambah Menu" << endl;
        cout << "  3. Edit Menu" << endl;
        cout << "  4. Hapus Menu" << endl;
        cout << "  5. Kelola Stok" << endl;
        cout << "  6. Kelola Promo" << endl;
        cout << "  7. Kelola Karyawan" << endl;
        cout << "  8. Laporan Penjualan" << endl;
        cout << "  9. Laporan Stok" << endl;
        cout << " 10. Laporan Review" << endl;
        cout << " 11. Pengaturan Toko" << endl;
        cout << " 12. Home" << endl;
        tampilkanFooter();
        cout << " Masukkan pilihan: ";
        cin >> pilihan;

        if (pilihan == "1")
        {
            clearScreen();
            liatDaftarMakanan();
            liatDaftarMinuman();
            pauseScreen();
        }
        else if (pilihan == "2")
        {
            tambahMenu();
        }
        else if (pilihan == "3")
        {
            editMenu();
        }
        else if (pilihan == "4")
        {
            hapusMenu();
        }
        else if (pilihan == "5")
        {
            kelolaStok();
        }
        else if (pilihan == "6")
        {
            kelolaPromoMenu();
        }
        else if (pilihan == "7")
        {
            kelolaKaryawan();
        }
        else if (pilihan == "8")
        {
            laporanPenjualan();
        }
        else if (pilihan == "9")
        {
            laporanStok();
        }
        else if (pilihan == "10")
        {
            laporanReview();
        }
        else if (pilihan == "11")
        {
            pengaturanToko();
        }
        else if (pilihan == "12")
        {
            home();
            return;
        }
        else
        {
            cout << " *Pilihan tidak valid. Silakan coba lagi." << endl;
            pauseScreen();
        }
    } while (pilihan != "13");
}

void Toko::user()
{
    string pilihan;
    do
    {
        clearScreen();
        tampilkanHeader("MENU PELANGGAN");
        cout << "  1. Lihat Daftar Menu" << endl;
        cout << "  2. Sortir Menu" << endl;
        cout << "  3. Cari Menu" << endl;
        cout << "  4. Pesan Makanan/Minuman" << endl;
        cout << "  5. Lihat Promo" << endl;
        cout << "  6. Lihat Pesanan" << endl;
        cout << "  7. Hapus Pesanan" << endl;
        cout << "  8. Batalkan Pesanan" << endl;
        cout << "  9. Bayar Pesanan" << endl;
        cout << " 10. Beri Review" << endl;
        cout << " 11. Home" << endl;
        tampilkanFooter();
        cout << " Masukkan pilihan: ";
        cin >> pilihan;

        if (pilihan == "1")
        {
            clearScreen();
            liatDaftarMakanan();
            liatDaftarMinuman();
            pauseScreen();
        }
        else if (pilihan == "2")
        {
            sortirMenu();
        }
        else if (pilihan == "3")
        {
            cariMenu();
        }
        else if (pilihan == "4")
        {
            pesanMakanan();
        }
        else if (pilihan == "5")
        {
            tampilkanPromo();
        }
        else if (pilihan == "6")
        {
            clearScreen();
            lihatPesanan();
            pauseScreen();
        }
        else if (pilihan == "7")
        {
            hapusPesanan();
        }
        else if (pilihan == "8")
        {
            batalkanPesanan();
        }
        else if (pilihan == "9")
        {
            bayarPesanan();
        }
        else if (pilihan == "10")
        {
            beriReview();
        }
        else if (pilihan == "11")
        {
            home();
            return;
        }
        else
        {
            cout << " *Pilihan tidak valid. Silakan coba lagi." << endl;
            pauseScreen();
        }
    } while (pilihan != "12");
}

void Toko::home()
{
    string pilihan;
    clearScreen();
    tampilkanHeader("WELCOME");
    cout << " 1. Admin" << endl;
    cout << " 2. Pelanggan" << endl;
    cout << " 3. Keluar" << endl;
    tampilkanFooter();
    cout << " Masukkan Pilihan: ";
    cin >> pilihan;

    if (pilihan == "1")
    {
        loginAdmin();
        return;
    }
    else if (pilihan == "2")
    {
        loginUser();
        return;
    }
    else if (pilihan == "3")
    {
        clearScreen();
        tampilkanHeader("TERIMA KASIH");
        cout << " Sampai Jumpa " << endl;
        tampilkanFooter();
        return;
    }
    else
    {
        cout << " *Pilihan yang anda masukkan tidak ada. Silahkan pilih lagi!" << endl;
        pauseScreen();
        home();
    }
}

void Toko::tambahMenu()
{
    string pilihanTambah;
    clearScreen();
    tampilkanHeader("TAMBAH MENU");
    cout << " 1. Tambah Makanan" << endl;
    cout << " 2. Tambah Minuman" << endl;
    cout << " 3. Kembali" << endl;
    tampilkanFooter();
    cout << " Masukkan Pilihan: ";
    cin >> pilihanTambah;

    if (pilihanTambah == "1")
        tambahMenuMakanan();
    else if (pilihanTambah == "2")
        tambahMenuMinuman();
    else if (pilihanTambah == "3")
        return;
    else
    {
        cout << " *Pilihan tidak valid. Silakan coba lagi." << endl;
        pauseScreen();
        tambahMenu();
    }
}

void Toko::editMenu()
{
    string pilihanEdit;
    clearScreen();
    tampilkanHeader("EDIT MENU");
    cout << " 1. Edit Makanan" << endl;
    cout << " 2. Edit Minuman" << endl;
    cout << " 3. Kembali" << endl;
    tampilkanFooter();
    cout << " Masukkan Pilihan: ";
    cin >> pilihanEdit;

    if (pilihanEdit == "1")
        editMenuMakanan();
    else if (pilihanEdit == "2")
        editMenuMinuman();
    else if (pilihanEdit == "3")
        return;
    else
    {
        cout << " *Pilihan tidak valid. Silakan coba lagi." << endl;
        pauseScreen();
        editMenu();
    }
}

void Toko::hapusMenu()
{
    string pilihanHapus;
    clearScreen();
    tampilkanHeader("HAPUS MENU");
    cout << " 1. Hapus Makanan" << endl;
    cout << " 2. Hapus Minuman" << endl;
    cout << " 3. Kembali" << endl;
    tampilkanFooter();
    cout << " Masukkan Pilihan: ";
    cin >> pilihanHapus;

    if (pilihanHapus == "1")
        hapusMenuMakanan();
    else if (pilihanHapus == "2")
        hapusMenuMinuman();
    else if (pilihanHapus == "3")
        return;
    else
    {
        cout << " *Pilihan tidak valid. Silakan coba lagi." << endl;
        pauseScreen();
        hapusMenu();
    }
}

void Toko::kelolaPromoMenu()
{
    string pilihanPromo;
    clearScreen();
    tampilkanHeader("KELOLA PROMO");
    cout << " 1. Lihat Promo" << endl;
    cout << " 2. Tambah Promo" << endl;
    cout << " 3. Hapus Promo" << endl;
    cout << " 4. Kembali" << endl;
    tampilkanFooter();
    cout << " Masukkan Pilihan: ";
    cin >> pilihanPromo;

    if (pilihanPromo == "1")
        tampilkanPromo();
    else if (pilihanPromo == "2")
        tambahPromo();
    else if (pilihanPromo == "3")
        hapusPromo();
    else if (pilihanPromo == "4")
        return;
    else
    {
        cout << " *Pilihan tidak valid. Silakan coba lagi." << endl;
        pauseScreen();
        kelolaPromoMenu();
    }
}

void Toko::liatDaftarMakanan()
{
    tampilkanHeader("DAFTAR MAKANAN");
    if (jumlahMakanan != 0)
    {
        for (int i = 0; i < jumlahMakanan; i++)
        {
            cout << " " << i + 1 << ". " << daftarMakanan[i] << " - Rp" << hargaMakanan[i] << " (Stok: " << stokMakanan[i] << ")" << endl;
        }
    }
    else
    {
        cout << " Daftar makanan masih kosong." << endl;
        cout << " Silahkan isi terlebih dahulu !!" << endl;
    }
    tampilkanFooter();
}

void Toko::liatDaftarMinuman()
{
    tampilkanHeader("DAFTAR MINUMAN");
    if (jumlahMinuman != 0)
    {
        for (int i = 0; i < jumlahMinuman; i++)
        {
            cout << " " << i + 1 << ". " << daftarMinuman[i] << " - Rp" << hargaMinuman[i] << " (Stok: " << stokMinuman[i] << ")" << endl;
        }
    }
    else
    {
        cout << " Daftar minuman masih kosong." << endl;
        cout << " Silahkan isi terlebih dahulu !!" << endl;
    }
    tampilkanFooter();
}

void Toko::tambahMenuMakanan()
{
    if (sudahBackup)
    {
        for (int i = 0; i < jumlahMakanan; i++)
        {
            daftarMakanan[i] = backupDaftarMakanan[i];
            hargaMakanan[i] = backupHargaMakanan[i];
            stokMakanan[i] = backupStokMakanan[i];
            totalDibeli[i] = backupTotalDibeli[i];
        }
        for (int i = 0; i < jumlahMinuman; i++)
        {
            daftarMinuman[i] = backupDaftarMinuman[i];
            hargaMinuman[i] = backupHargaMinuman[i];
            stokMinuman[i] = backupStokMinuman[i];
            totalDibeli[jumlahMakanan + i] = backupTotalDibeli[jumlahMakanan + i];
        }
        sudahBackup = false;
    }

    clearScreen();
    tampilkanHeader("TAMBAH MENU MAKANAN");
    if (jumlahMakanan >= 100)
    {
        cout << " *Peringatan!!" << endl;
        cout << " Kapasitas menu makanan penuh." << endl;
        cout << " Silahkan hapus terlebih dahulu !!" << endl;
        tampilkanFooter();
        pauseScreen();
        return;
    }

    string nama;
    int harga, stok;

    cout << " Masukkan Nama Makanan: ";
    cin.ignore();
    getline(cin, nama);

    cout << " Masukkan Harga Makanan: ";
    cin >> harga;

    cout << " Masukkan Stok Awal: ";
    cin >> stok;

    daftarMakanan[jumlahMakanan] = nama;
    hargaMakanan[jumlahMakanan] = harga;
    stokMakanan[jumlahMakanan] = stok;
    jumlahMakanan++;

    tampilkanFooter();
    cout << " *Menu makanan berhasil ditambahkan." << endl;
    (pilihYaTidak("Apakah Anda ingin menambah menu makanan lagi?")) ? tambahMenuMakanan() : pauseScreen();
}

void Toko::tambahMenuMinuman()
{
    if (sudahBackup)
    {
        for (int i = 0; i < jumlahMakanan; i++)
        {
            daftarMakanan[i] = backupDaftarMakanan[i];
            hargaMakanan[i] = backupHargaMakanan[i];
            stokMakanan[i] = backupStokMakanan[i];
            totalDibeli[i] = backupTotalDibeli[i];
        }
        for (int i = 0; i < jumlahMinuman; i++)
        {
            daftarMinuman[i] = backupDaftarMinuman[i];
            hargaMinuman[i] = backupHargaMinuman[i];
            stokMinuman[i] = backupStokMinuman[i];
            totalDibeli[jumlahMakanan + i] = backupTotalDibeli[jumlahMakanan + i];
        }
        sudahBackup = false;
    }

    clearScreen();
    tampilkanHeader("TAMBAH MENU MINUMAN");
    if (jumlahMinuman >= 50)
    {
        cout << " *Peringatan!!" << endl;
        cout << " Kapasitas menu minuman penuh." << endl;
        cout << " Silahkan hapus terlebih dahulu !!" << endl;
        tampilkanFooter();
        pauseScreen();
        return;
    }

    string nama;
    int harga, stok;

    cout << " Masukkan Nama Minuman: ";
    cin.ignore();
    getline(cin, nama);

    cout << " Masukkan Harga Minuman: ";
    cin >> harga;

    cout << " Masukkan Stok Awal: ";
    cin >> stok;

    daftarMinuman[jumlahMinuman] = nama;
    hargaMinuman[jumlahMinuman] = harga;
    stokMinuman[jumlahMinuman] = stok;
    jumlahMinuman++;

    tampilkanFooter();
    cout << " *Menu minuman berhasil ditambahkan." << endl;
    (pilihYaTidak("Apakah Anda ingin menambah menu minuman lagi?")) ? tambahMenuMinuman() : pauseScreen();
}

void Toko::editMenuMakanan()
{
    clearScreen();
    liatDaftarMakanan();
    tampilkanHeader("EDIT MENU MAKANAN");
    int index;
    cout << " Masukkan nomor makanan yang ingin diedit: ";
    cin >> index;

    if (index < 1 || index > jumlahMakanan)
    {
        cout << " *Nomor makanan tidak valid. Edit gagal!!" << endl;
        pauseScreen();
        return;
    }

    cout << " *Makanan ditemukan: " << daftarMakanan[index - 1] << endl;
    tampilkanFooter();
    string nama, pilihan;
    int hargaTemp, stokTemp;

    cout << " Apa yang anda ingin ubah?" << endl;
    cout << " 1. Nama Makanan" << endl;
    cout << " 2. Harga Makanan" << endl;
    cout << " 3. Stok Makanan" << endl;
    cout << " 4. Semua" << endl;
    cout << " 5. Cancel" << endl;
    tampilkanFooter();
    do
    {
        cout << " Masukkan pilihan: ";
        cin >> pilihan;
        if (pilihan == "1")
        {
            cout << " Masukkan Nama Makanan Baru [" << daftarMakanan[index - 1] << "]: ";
            cin.ignore();
            getline(cin, nama);
            daftarMakanan[index - 1] = nama;
        }
        else if (pilihan == "2")
        {
            cout << " Masukkan Harga Makanan Baru [" << hargaMakanan[index - 1] << "]: ";
            cin >> hargaTemp;
            hargaMakanan[index - 1] = hargaTemp;
        }
        else if (pilihan == "3")
        {
            cout << " Masukkan Stok Baru [" << stokMakanan[index - 1] << "]: ";
            cin >> stokTemp;
            stokMakanan[index - 1] = stokTemp;
        }
        else if (pilihan == "4")
        {
            cout << " Masukkan Nama Makanan Baru [" << daftarMakanan[index - 1] << "]: ";
            cin.ignore();
            getline(cin, daftarMakanan[index - 1]);
            cout << " Masukkan Harga Makanan Baru [" << hargaMakanan[index - 1] << "]: ";
            cin >> hargaTemp;
            hargaMakanan[index - 1] = hargaTemp;

            cout << " Masukkan Stok Baru [" << stokMakanan[index - 1] << "]: ";
            cin >> stokTemp;
            stokMakanan[index - 1] = stokTemp;
        }
        else if (pilihan == "5")
        {
            cout << " *Edit dibatalkan." << endl;
            tampilkanFooter();
            pauseScreen();
            return;
        }
        else
        {
            cout << " *Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != "1" && pilihan != "2" && pilihan != "3" && pilihan != "4" && pilihan != "5");
    tampilkanFooter();
    cout << " *Menu makanan berhasil diperbarui." << endl;
    (pilihYaTidak("Apakah Anda ingin mengedit menu makanan lain?")) ? editMenuMakanan() : pauseScreen();
}

void Toko::editMenuMinuman()
{
    clearScreen();
    liatDaftarMinuman();
    tampilkanHeader("EDIT MENU MINUMAN");
    int index;
    cout << " Masukkan nomor minuman yang ingin diedit: ";
    cin >> index;

    if (index < 1 || index > jumlahMinuman)
    {
        cout << " *Nomor minuman tidak valid. Edit gagal!!" << endl;
        pauseScreen();
        return;
    }

    cout << " *Minuman ditemukan: " << daftarMinuman[index - 1] << endl;
    tampilkanFooter();
    string nama, pilihan;
    int hargaTemp, stokTemp;

    cout << " Apa yang anda ingin ubah?" << endl;
    cout << " 1. Nama Minuman" << endl;
    cout << " 2. Harga Minuman" << endl;
    cout << " 3. Stok Minuman" << endl;
    cout << " 4. Semua" << endl;
    cout << " 5. Cancel" << endl;
    tampilkanFooter();
    do
    {
        cout << " Masukkan pilihan: ";
        cin >> pilihan;
        if (pilihan == "1")
        {
            cout << " Masukkan Nama Minuman Baru [" << daftarMinuman[index - 1] << "]: ";
            cin.ignore();
            getline(cin, nama);
            daftarMinuman[index - 1] = nama;
        }
        else if (pilihan == "2")
        {
            cout << " Masukkan Harga Minuman Baru [" << hargaMinuman[index - 1] << "]: ";
            cin >> hargaTemp;
            hargaMinuman[index - 1] = hargaTemp;
        }
        else if (pilihan == "3")
        {
            cout << " Masukkan Stok Baru [" << stokMinuman[index - 1] << "]: ";
            cin >> stokTemp;
            stokMinuman[index - 1] = stokTemp;
        }
        else if (pilihan == "4")
        {
            cout << " Masukkan Nama Minuman Baru [" << daftarMinuman[index - 1] << "]: ";
            cin.ignore();
            getline(cin, daftarMinuman[index - 1]);
            cout << " Masukkan Harga Minuman Baru [" << hargaMinuman[index - 1] << "]: ";
            cin >> hargaTemp;
            hargaMinuman[index - 1] = hargaTemp;
            cout << " Masukkan Stok Baru [" << stokMinuman[index - 1] << "]: ";
            cin >> stokTemp;
            stokMinuman[index - 1] = stokTemp;
        }
        else if (pilihan == "5")
        {
            cout << " *Edit dibatalkan." << endl;
            tampilkanFooter();
            pauseScreen();
            return;
        }
        else
        {
            cout << " *Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != "1" && pilihan != "2" && pilihan != "3" && pilihan != "4" && pilihan != "5");
    tampilkanFooter();
    cout << " *Menu minuman berhasil diperbarui." << endl;
    (pilihYaTidak("Apakah Anda ingin mengedit menu minuman lain?")) ? editMenuMinuman() : pauseScreen();
}

void Toko::hapusMenuMakanan()
{
    clearScreen();
    liatDaftarMakanan();
    tampilkanHeader("HAPUS MENU MAKANAN");
    int index;
    cout << " Masukkan nomor makanan yang ingin dihapus: ";
    cin >> index;

    if (index < 1 || index > jumlahMakanan)
    {
        cout << " *Nomor makanan tidak valid. Hapus gagal!!" << endl;
        pauseScreen();
        return;
    }

    for (int i = index - 1; i < jumlahMakanan - 1; i++)
    {
        daftarMakanan[i] = daftarMakanan[i + 1];
        hargaMakanan[i] = hargaMakanan[i + 1];
        stokMakanan[i] = stokMakanan[i + 1];
    }
    jumlahMakanan--;
    tampilkanFooter();
    cout << " *Menu makanan berhasil dihapus." << endl;
    pauseScreen();
}

void Toko::hapusMenuMinuman()
{
    clearScreen();
    liatDaftarMinuman();
    tampilkanHeader("HAPUS MENU MINUMAN");
    int index;
    cout << " Masukkan nomor minuman yang ingin dihapus: ";
    cin >> index;

    if (index < 1 || index > jumlahMinuman)
    {
        cout << " *Nomor minuman tidak valid. Hapus gagal!!" << endl;
        pauseScreen();
        return;
    }

    for (int i = index - 1; i < jumlahMinuman - 1; i++)
    {
        daftarMinuman[i] = daftarMinuman[i + 1];
        hargaMinuman[i] = hargaMinuman[i + 1];
        stokMinuman[i] = stokMinuman[i + 1];
    }
    jumlahMinuman--;
    cout << " *Menu minuman berhasil dihapus." << endl;
    pauseScreen();
}

void Toko::sortirMenu()
{
    string pilihanSortir;
    do
    {
        clearScreen();
        tampilkanHeader("SORTIR MENU");
        cout << " 1. Terpopuler" << endl;
        cout << " 2. Termurah" << endl;
        cout << " 3. Termahal" << endl;
        cout << " 4. Urutan Semula" << endl;
        cout << " 5. Kembali" << endl;
        tampilkanFooter();
        cout << " Masukkan Pilihan: ";
        cin >> pilihanSortir;

        if (!sudahBackup && pilihanSortir != "5" && pilihanSortir != "4")
        {
            for (int i = 0; i < jumlahMakanan; i++)
            {
                backupDaftarMakanan[i] = daftarMakanan[i];
                backupHargaMakanan[i] = hargaMakanan[i];
                backupStokMakanan[i] = stokMakanan[i];
                backupTotalDibeli[i] = totalDibeli[i];
            }
            for (int i = 0; i < jumlahMinuman; i++)
            {
                backupDaftarMinuman[i] = daftarMinuman[i];
                backupHargaMinuman[i] = hargaMinuman[i];
                backupStokMinuman[i] = stokMinuman[i];
                backupTotalDibeli[jumlahMakanan + i] = totalDibeli[jumlahMakanan + i];
            }
            sudahBackup = true;
        }

        if (pilihanSortir == "1")
        {
            for (int i = 0; i < jumlahMakanan - 1; i++)
            {
                int maxIdx = i;
                for (int j = i + 1; j < jumlahMakanan; j++)
                {
                    if (totalDibeli[j] > totalDibeli[maxIdx])
                        maxIdx = j;
                }
                if (maxIdx != i)
                {
                    string tempNama = daftarMakanan[i];
                    daftarMakanan[i] = daftarMakanan[maxIdx];
                    daftarMakanan[maxIdx] = tempNama;

                    int tempHarga = hargaMakanan[i];
                    hargaMakanan[i] = hargaMakanan[maxIdx];
                    hargaMakanan[maxIdx] = tempHarga;

                    int tempStok = stokMakanan[i];
                    stokMakanan[i] = stokMakanan[maxIdx];
                    stokMakanan[maxIdx] = tempStok;

                    int tempDibeli = totalDibeli[i];
                    totalDibeli[i] = totalDibeli[maxIdx];
                    totalDibeli[maxIdx] = tempDibeli;
                }
            }

            for (int i = 0; i < jumlahMinuman - 1; i++)
            {
                int maxIdx = i;
                for (int j = i + 1; j < jumlahMinuman; j++)
                {
                    if (totalDibeli[jumlahMakanan + j] > totalDibeli[jumlahMakanan + maxIdx])
                        maxIdx = j;
                }
                if (maxIdx != i)
                {
                    string tempNama = daftarMinuman[i];
                    daftarMinuman[i] = daftarMinuman[maxIdx];
                    daftarMinuman[maxIdx] = tempNama;

                    int tempHarga = hargaMinuman[i];
                    hargaMinuman[i] = hargaMinuman[maxIdx];
                    hargaMinuman[maxIdx] = tempHarga;

                    int tempStok = stokMinuman[i];
                    stokMinuman[i] = stokMinuman[maxIdx];
                    stokMinuman[maxIdx] = tempStok;

                    int tempDibeli = totalDibeli[jumlahMakanan + i];
                    totalDibeli[jumlahMakanan + i] = totalDibeli[jumlahMakanan + maxIdx];
                    totalDibeli[jumlahMakanan + maxIdx] = tempDibeli;
                }
            }
            cout << " *Menu berhasil diurutkan berdasarkan popularitas." << endl;
            cout << "  Silahkan lihat daftar menu untuk melihat hasilnya." << endl;
            pauseScreen();
        }
        else if (pilihanSortir == "2")
        {
            for (int i = 0; i < jumlahMakanan - 1; i++)
            {
                int minIdx = i;
                for (int j = i + 1; j < jumlahMakanan; j++)
                {
                    if (hargaMakanan[j] < hargaMakanan[minIdx])
                        minIdx = j;
                }
                if (minIdx != i)
                {
                    string tempNama = daftarMakanan[i];
                    daftarMakanan[i] = daftarMakanan[minIdx];
                    daftarMakanan[minIdx] = tempNama;

                    int tempHarga = hargaMakanan[i];
                    hargaMakanan[i] = hargaMakanan[minIdx];
                    hargaMakanan[minIdx] = tempHarga;

                    int tempStok = stokMakanan[i];
                    stokMakanan[i] = stokMakanan[minIdx];
                    stokMakanan[minIdx] = tempStok;

                    int tempDibeli = totalDibeli[i];
                    totalDibeli[i] = totalDibeli[minIdx];
                    totalDibeli[minIdx] = tempDibeli;
                }
            }

            for (int i = 0; i < jumlahMinuman - 1; i++)
            {
                int minIdx = i;
                for (int j = i + 1; j < jumlahMinuman; j++)
                {
                    if (hargaMinuman[j] < hargaMinuman[minIdx])
                        minIdx = j;
                }
                if (minIdx != i)
                {
                    string tempNama = daftarMinuman[i];
                    daftarMinuman[i] = daftarMinuman[minIdx];
                    daftarMinuman[minIdx] = tempNama;

                    int tempHarga = hargaMinuman[i];
                    hargaMinuman[i] = hargaMinuman[minIdx];
                    hargaMinuman[minIdx] = tempHarga;

                    int tempStok = stokMinuman[i];
                    stokMinuman[i] = stokMinuman[minIdx];
                    stokMinuman[minIdx] = tempStok;

                    int tempDibeli = totalDibeli[jumlahMakanan + i];
                    totalDibeli[jumlahMakanan + i] = totalDibeli[jumlahMakanan + minIdx];
                    totalDibeli[jumlahMakanan + minIdx] = tempDibeli;
                }
            }
            cout << " *Menu berhasil diurutkan berdasarkan harga termurah." << endl;
            cout << "  Silahkan lihat daftar menu untuk melihat hasilnya." << endl;
            pauseScreen();
        }
        else if (pilihanSortir == "3")
        {
            for (int i = 0; i < jumlahMakanan - 1; i++)
            {
                int maxIdx = i;
                for (int j = i + 1; j < jumlahMakanan; j++)
                {
                    if (hargaMakanan[j] > hargaMakanan[maxIdx])
                        maxIdx = j;
                }
                if (maxIdx != i)
                {
                    string tempNama = daftarMakanan[i];
                    daftarMakanan[i] = daftarMakanan[maxIdx];
                    daftarMakanan[maxIdx] = tempNama;

                    int tempHarga = hargaMakanan[i];
                    hargaMakanan[i] = hargaMakanan[maxIdx];
                    hargaMakanan[maxIdx] = tempHarga;

                    int tempStok = stokMakanan[i];
                    stokMakanan[i] = stokMakanan[maxIdx];
                    stokMakanan[maxIdx] = tempStok;

                    int tempDibeli = totalDibeli[i];
                    totalDibeli[i] = totalDibeli[maxIdx];
                    totalDibeli[maxIdx] = tempDibeli;
                }
            }

            for (int i = 0; i < jumlahMinuman - 1; i++)
            {
                int maxIdx = i;
                for (int j = i + 1; j < jumlahMinuman; j++)
                {
                    if (hargaMinuman[j] > hargaMinuman[maxIdx])
                        maxIdx = j;
                }
                if (maxIdx != i)
                {
                    string tempNama = daftarMinuman[i];
                    daftarMinuman[i] = daftarMinuman[maxIdx];
                    daftarMinuman[maxIdx] = tempNama;

                    int tempHarga = hargaMinuman[i];
                    hargaMinuman[i] = hargaMinuman[maxIdx];
                    hargaMinuman[maxIdx] = tempHarga;

                    int tempStok = stokMinuman[i];
                    stokMinuman[i] = stokMinuman[maxIdx];
                    stokMinuman[maxIdx] = tempStok;

                    int tempDibeli = totalDibeli[jumlahMakanan + i];
                    totalDibeli[jumlahMakanan + i] = totalDibeli[jumlahMakanan + maxIdx];
                    totalDibeli[jumlahMakanan + maxIdx] = tempDibeli;
                }
            }
            cout << " *Menu berhasil diurutkan berdasarkan harga termahal." << endl;
            cout << "  Silahkan lihat daftar menu untuk melihat hasilnya." << endl;
            pauseScreen();
        }
        else if (pilihanSortir == "4")
        {
            for (int i = 0; i < jumlahMakanan; i++)
            {
                daftarMakanan[i] = backupDaftarMakanan[i];
                hargaMakanan[i] = backupHargaMakanan[i];
                stokMakanan[i] = backupStokMakanan[i];
                totalDibeli[i] = backupTotalDibeli[i];
            }
            for (int i = 0; i < jumlahMinuman; i++)
            {
                daftarMinuman[i] = backupDaftarMinuman[i];
                hargaMinuman[i] = backupHargaMinuman[i];
                stokMinuman[i] = backupStokMinuman[i];
                totalDibeli[jumlahMakanan + i] = backupTotalDibeli[jumlahMakanan + i];
            }
            sudahBackup = false;
            cout << " *Menu berhasil dikembalikan ke urutan semula." << endl;
            cout << "  Silahkan lihat daftar menu untuk melihat hasilnya." << endl;
            pauseScreen();
        }
        else if (pilihanSortir == "5")
        {
            return;
        }
        else
        {
            cout << " *Pilihan tidak valid. Silakan coba lagi." << endl;
            pauseScreen();
        }
    } while (pilihanSortir != "5");
}

void Toko::cariMenu()
{
    clearScreen();
    tampilkanHeader("CARI MENU");
    string keyword;
    cout << " Masukkan nama menu yang dicari: ";
    cin.ignore();
    getline(cin, keyword);

    bool ditemukanMakanan = false, ditemukanMinuman = false;
    int idxMakanan = -1, idxMinuman = -1;

    for (int i = 0; i < jumlahMakanan; i++)
    {
        if (daftarMakanan[i] == keyword)
        {
            ditemukanMakanan = true;
            idxMakanan = i;
            cout << " *Makanan ditemukan: " << daftarMakanan[i] << " - Rp" << hargaMakanan[i] << " (Stok: " << stokMakanan[i] << ")" << endl;
        }
    }

    for (int i = 0; i < jumlahMinuman; i++)
    {
        if (daftarMinuman[i] == keyword)
        {
            ditemukanMinuman = true;
            idxMinuman = i;
            cout << " *Minuman ditemukan: " << daftarMinuman[i] << " - Rp" << hargaMinuman[i] << " (Stok: " << stokMinuman[i] << ")" << endl;
        }
    }

    if (!ditemukanMakanan && !ditemukanMinuman)
    {
        cout << " *Tidak ditemukan menu dengan nama '" << keyword << "'" << endl;
        pauseScreen();
        return;
    }

    if (pilihYaTidak("Apakah Anda ingin memesan menu yang ditemukan?"))
    {
        if (ditemukanMakanan && !ditemukanMinuman)
        {
            int jumlah;
            cout << " Masukkan jumlah yang ingin dipesan (Stok tersedia: " << stokMakanan[idxMakanan] << "): ";
            cin >> jumlah;
            if (jumlah > 0 && jumlah <= stokMakanan[idxMakanan])
            {
                namaPesanan[totalPesanan] = daftarMakanan[idxMakanan];
                hargaPesanan[totalPesanan] = hargaMakanan[idxMakanan];
                jumlahPesanan[totalPesanan] = jumlah;
                totalHargaPesenan += hargaMakanan[idxMakanan] * jumlah;
                stokMakanan[idxMakanan] -= jumlah;
                totalPesanan++;
                if (pilihYaTidak("Apakah Anda memiliki kode promo?"))
                {
                    applyPromo();
                }
                pilihMetodePengiriman();
                cout << " *Pesanan berhasil ditambahkan!" << endl;
            }
            else
            {
                cout << " *Jumlah tidak valid atau stok tidak cukup." << endl;
            }
        }
        else if (ditemukanMinuman && !ditemukanMakanan)
        {
            int jumlah;
            cout << " Masukkan jumlah yang ingin dipesan (Stok tersedia: " << stokMinuman[idxMinuman] << "): ";
            cin >> jumlah;
            if (jumlah > 0 && jumlah <= stokMinuman[idxMinuman])
            {
                namaPesanan[totalPesanan] = daftarMinuman[idxMinuman];
                hargaPesanan[totalPesanan] = hargaMinuman[idxMinuman];
                jumlahPesanan[totalPesanan] = jumlah;
                totalHargaPesenan += hargaMinuman[idxMinuman] * jumlah;
                stokMinuman[idxMinuman] -= jumlah;
                totalPesanan++;
                if (pilihYaTidak("Apakah Anda memiliki kode promo?"))
                {
                    applyPromo();
                }
                pilihMetodePengiriman();
                cout << " *Pesanan berhasil ditambahkan!" << endl;
            }
            else
            {
                cout << " *Jumlah tidak valid atau stok tidak cukup." << endl;
            }
        }
        else if (ditemukanMakanan && ditemukanMinuman)
        {
            int pilihJenis;
            cout << " Menu ditemukan di makanan dan minuman. Pilih yang ingin dipesan:" << endl;
            cout << " 1. " << daftarMakanan[idxMakanan] << " (Makanan)" << endl;
            cout << " 2. " << daftarMinuman[idxMinuman] << " (Minuman)" << endl;
            tampilkanFooter();
            cout << " Masukkan Pilihan: ";
            cin >> pilihJenis;
            int jumlah;
            if (pilihJenis == 1)
            {
                cout << " Masukkan jumlah yang ingin dipesan (Stok tersedia: " << stokMakanan[idxMakanan] << "): ";
                cin >> jumlah;
                if (jumlah > 0 && jumlah <= stokMakanan[idxMakanan])
                {
                    namaPesanan[totalPesanan] = daftarMakanan[idxMakanan];
                    hargaPesanan[totalPesanan] = hargaMakanan[idxMakanan];
                    jumlahPesanan[totalPesanan] = jumlah;
                    totalHargaPesenan += hargaMakanan[idxMakanan] * jumlah;
                    stokMakanan[idxMakanan] -= jumlah;
                    totalPesanan++;
                    if (pilihYaTidak("Apakah Anda memiliki kode promo?"))
                    {
                        applyPromo();
                    }
                    pilihMetodePengiriman();
                    cout << "Pesanan berhasil ditambahkan!" << endl;
                }
                else
                {
                    cout << " *Jumlah tidak valid atau stok tidak cukup." << endl;
                }
            }
            else if (pilihJenis == 2)
            {
                cout << " Masukkan jumlah yang ingin dipesan (Stok tersedia: " << stokMinuman[idxMinuman] << "): ";
                cin >> jumlah;
                if (jumlah > 0 && jumlah <= stokMinuman[idxMinuman])
                {
                    namaPesanan[totalPesanan] = daftarMinuman[idxMinuman];
                    hargaPesanan[totalPesanan] = hargaMinuman[idxMinuman];
                    jumlahPesanan[totalPesanan] = jumlah;
                    totalHargaPesenan += hargaMinuman[idxMinuman] * jumlah;
                    stokMinuman[idxMinuman] -= jumlah;
                    totalPesanan++;
                    if (pilihYaTidak("Apakah Anda memiliki kode promo?"))
                    {
                        applyPromo();
                    }
                    pilihMetodePengiriman();
                    cout << " *Pesanan berhasil ditambahkan!" << endl;
                }
                else
                {
                    cout << " *Jumlah tidak valid atau stok tidak cukup." << endl;
                }
            }
            else
            {
                cout << " *Pilihan tidak valid." << endl;
            }
        }
    }
}

void Toko::carikanJumlahStok()
{
    clearScreen();
    tampilkanHeader("STOK YANG DICARI");
    cout << " Masukkan jumlah stok yang ingin dicari: ";
    int jumlahStok;
    cin >> jumlahStok;
    if (jumlahStok < 0)
    {
        cout << " *Jumlah stok tidak boleh negatif." << endl;
        pauseScreen();
        return;
    }
    cout << endl;
    int stokTemp[100];
    string namaTemp[100];
    for (int i = 0; i < jumlahMakanan; i++) {
        stokTemp[i] = stokMakanan[i];
        namaTemp[i] = daftarMakanan[i];
    }

    for (int i = 0; i < jumlahMakanan - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < jumlahMakanan; j++) {
            if (stokTemp[j] < stokTemp[minIdx])
                minIdx = j;
        }
        if (minIdx != i) {
            int stokMin = stokTemp[minIdx];
            string namaMin = namaTemp[minIdx];
            for (int k = minIdx; k > i; k--) {
                stokTemp[k] = stokTemp[k - 1];
                namaTemp[k] = namaTemp[k - 1];
            }
            stokTemp[i] = stokMin;
            namaTemp[i] = namaMin;
        }
    }
    int left = 0, right = jumlahMakanan - 1, idx = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (stokTemp[mid] < jumlahStok) {
            idx = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << " Makanan dengan stok kurang dari " << jumlahStok << ":" << endl;
    if (idx == -1) {
        cout << " Tidak ada makanan dengan stok kurang dari " << jumlahStok << "." << endl;
    } else {
        for (int i = 0; i <= idx; i++) {
            cout << " " << i + 1 << ". " << namaTemp[i] << " - Stok: " << stokTemp[i] << endl;
        }
    }

    // --- Untuk Minuman ---
    int stokTempMinum[50];
    string namaTempMinum[50];
    for (int i = 0; i < jumlahMinuman; i++) {
        stokTempMinum[i] = stokMinuman[i];
        namaTempMinum[i] = daftarMinuman[i];
    }
    // Selection sort ascending tanpa swap
    for (int i = 0; i < jumlahMinuman - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < jumlahMinuman; j++) {
            if (stokTempMinum[j] < stokTempMinum[minIdx])
                minIdx = j;
        }
        if (minIdx != i) {
            int stokMin = stokTempMinum[minIdx];
            string namaMin = namaTempMinum[minIdx];
            for (int k = minIdx; k > i; k--) {
                stokTempMinum[k] = stokTempMinum[k - 1];
                namaTempMinum[k] = namaTempMinum[k - 1];
            }
            stokTempMinum[i] = stokMin;
            namaTempMinum[i] = namaMin;
        }
    }
    left = 0; right = jumlahMinuman - 1; idx = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (stokTempMinum[mid] < jumlahStok) {
            idx = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << endl << " Minuman dengan stok kurang dari " << jumlahStok << ":" << endl;
    if (idx == -1) {
        cout << " Tidak ada minuman dengan stok kurang dari " << jumlahStok << "." << endl;
    } else {
        for (int i = 0; i <= idx; i++) {
            cout << " " << i + 1 << ". " << namaTempMinum[i] << " - Stok: " << stokTempMinum[i] << endl;
        }
    }
    cout << endl;
    tampilkanFooter();
    pauseScreen();
}

void Toko::kelolaStok()
{
    string pilihan;
    clearScreen();
    tampilkanHeader("KELOLA STOK");
    cout << " 1. Lihat Stok" << endl;
    cout << " 2. Tambah Stok" << endl;
    cout << " 3. Kurangi Stok" << endl;
    cout << " 4. Tampilkan stok kurang dari 10" << endl;
    cout << " 5. Kembali" << endl;
    tampilkanFooter();
    cout << " Masukkan Pilihan: ";
    cin >> pilihan;

    if (pilihan == "1")
    {
        lihatStok();
    }
    else if (pilihan == "2")
    {
        tambahStok();
    }
    else if (pilihan == "3")
    {
        kurangiStok();
    }
    else if (pilihan == "4")
    {
        carikanJumlahStok();
    }
    else if (pilihan == "5")
    {
        return;
    }
    else
    {
        cout << " *Pilihan tidak valid. Silakan coba lagi." << endl;
        pauseScreen();
        kelolaStok();
    }
}

void Toko::lihatStok()
{
    clearScreen();
    liatDaftarMakanan();
    liatDaftarMinuman();
    pauseScreen();
    kelolaStok();
}

void Toko::tambahStok()
{
    clearScreen();
    tampilkanHeader("TAMBAH STOK");
    cout << " Pilih jenis menu yang ingin ditambah stoknya:" << endl;
    cout << " 1. Makanan" << endl;
    cout << " 2. Minuman" << endl;
    cout << " 3. Kembali" << endl;
    tampilkanFooter();
    string pilihan;
    cout << " Masukkan Pilihan: ";
    cin >> pilihan;

    if (pilihan == "1")
    {
        int index, jumlah;
        liatDaftarMakanan();
        cout << " Masukkan nomor makanan: ";
        cin >> index;
        if (index < 1 || index > jumlahMakanan || jumlah < 1)
        {
            cout << " *Input tidak valid." << endl;
            pauseScreen();
            tambahStok();
            return;
        }
        cout << " Masukkan jumlah yang ingin ditambahkan: ";
        cin >> jumlah;
        stokMakanan[index - 1] += jumlah;
        cout << " *Stok " << daftarMakanan[index - 1] << " berhasil ditambahkan" << endl;
        tampilkanFooter();
        cout << " Stok sekarang: " << stokMakanan[index - 1] << endl;
    }
    else if (pilihan == "2")
    {
        int index, jumlah;
        liatDaftarMinuman();
        cout << " Masukkan nomor minuman: ";
        cin >> index;
        if (index < 1 || index > jumlahMinuman || jumlah < 1)
        {
            cout << " *Input tidak valid." << endl;
            pauseScreen();
            tambahStok();
            return;
        }
        cout << " Masukkan jumlah yang ingin ditambahkan: ";
        cin >> jumlah;
        stokMinuman[index - 1] += jumlah;
        cout << " *Stok " << daftarMinuman[index - 1] << " berhasil ditambahkan" << endl;
        tampilkanFooter();
        cout << " Stok sekarang: " << stokMinuman[index - 1] << endl;
    }
    else if (pilihan == "3")
    {
        kelolaStok();
        return;
    }
    else
    {
        cout << " *Jenis menu tidak valid." << endl;
    }
    pauseScreen();
    tambahStok();
}

void Toko::kurangiStok()
{
    clearScreen();
    tampilkanHeader("KURANGI STOK");
    cout << " Pilih jenis menu yang ingin dikurangi stoknya:" << endl;
    cout << " 1. Makanan" << endl;
    cout << " 2. Minuman" << endl;
    cout << " 3. Kembali" << endl;
    tampilkanFooter();
    string jenis;
    cout << " Masukkan Pilihan: ";
    cin >> jenis;

    if (jenis == "1")
    {
        int index, jumlah;
        cout << " Masukkan nomor makanan: ";
        cin >> index;
        if (index < 1 || index > jumlahMakanan || jumlah < 1)
        {
            cout << " *Input tidak valid." << endl;
            pauseScreen();
            kurangiStok();
            return;
        }
        cout << " Masukkan jumlah yang ingin dikurangi: ";
        cin >> jumlah;
        if (jumlah > stokMakanan[index - 1])
        {
            cout << " *Jumlah pengurangan melebihi stok yang ada." << endl;
            pauseScreen();
            kurangiStok();
            return;
        }
        else
        {
            stokMakanan[index - 1] -= jumlah;
            cout << " *Stok " << daftarMakanan[index - 1] << " berhasil dikurangi" << endl;
            tampilkanFooter();
            cout << " Stok sekarang: " << stokMakanan[index - 1] << endl;
        }
    }
    else if (jenis == "2")
    {
        int index, jumlah;
        cout << " Masukkan nomor minuman: ";
        cin >> index;
        if (index < 1 || index > jumlahMinuman || jumlah < 1)
        {
            cout << " *Input tidak valid." << endl;
            pauseScreen();
            kurangiStok();
            return;
        }
        cout << " Masukkan jumlah yang ingin dikurangi: ";
        cin >> jumlah;
        if (jumlah > stokMinuman[index - 1])
        {
            cout << " *Jumlah pengurangan melebihi stok yang ada." << endl;
            pauseScreen();
            kurangiStok();
            return;
        }
        else
        {
            stokMinuman[index - 1] -= jumlah;
            cout << "Stok " << daftarMinuman[index - 1] << " berhasil dikurangi" << endl;
            tampilkanFooter();
            cout << " Stok sekarang: " << stokMinuman[index - 1] << endl;
        }
    }
    else if (jenis == "3")
    {
        kelolaStok();
        return;
    }
    else
    {
        cout << " *Jenis menu tidak valid." << endl;
        pauseScreen();
        kurangiStok();
    }
    pauseScreen();
}

void Toko::pesanMakanan()
{
    clearScreen();
    if (totalPesanan > 0)
    {
        cout << " *Anda sudah memiliki pesanan sebelumnya" << endl;
        cout << "  Silakan selesaikan pesanan sebelumnya sebelum memesan lagi." << endl;
        pauseScreen();
        return;
    }
    liatDaftarMakanan();
    tampilkanHeader("PESAN MAKANAN");

    int index;
    int jumlah;
    int pesanan = 0;

    do
    {
        do
        {
            cout << " Masukkan nomor makanan yang ingin dipesan: ";
            cin >> index;

            if (index < 1 || index > jumlahMakanan)
            {
                cout << " *Nomor makanan tidak valid. Silakan coba lagi." << endl;
            }
            else if (stokMakanan[index - 1] <= 0)
            {
                cout << " *Maaf, stok " << daftarMakanan[index - 1] << " habis." << endl;
                index = -1;
            }
        } while (index < 1 || index > jumlahMakanan);

        do
        {
            cout << " Berapa banyak makanan yang ingin dipesan? (Stok tersedia: " << stokMakanan[index - 1] << "): ";
            cin >> jumlah;

            if (jumlah <= 0)
            {
                cout << " *Jumlah harus lebih dari 0. Silakan coba lagi." << endl;
            }
            else if (jumlah > stokMakanan[index - 1])
            {
                cout << " *Jumlah pesanan melebihi stok yang tersedia. Silakan coba lagi." << endl;
            }
        } while (jumlah <= 0 || jumlah > stokMakanan[index - 1]);

        namaPesanan[pesanan] = daftarMakanan[index - 1];
        hargaPesanan[pesanan] = hargaMakanan[index - 1];
        jumlahPesanan[pesanan] = jumlah;
        totalHargaPesenan += hargaPesanan[pesanan] * jumlahPesanan[pesanan];
        stokMakanan[index - 1] -= jumlah;
        pesanan++;
        totalPesanan++;
    } while (pilihYaTidak("Apakah Anda ingin memesan makanan lain?"));

    if (pilihYaTidak("Apakah Anda ingin memesan minuman?"))
    {
        pesanMinuman();
    }

    if (pilihYaTidak("Apakah Anda memiliki kode promo?"))
    {
        applyPromo();
    }

    pilihMetodePengiriman();

    tampilkanFooter();
    cout << " *Pesanan berhasil ditambahkan!" << endl;
    pauseScreen();
}

void Toko::pesanMinuman()
{
    clearScreen();
    liatDaftarMinuman();
    tampilkanHeader("PESAN MINUMAN");

    int index;
    int jumlah;
    int pesanan = totalPesanan;

    do
    {
        do
        {
            cout << " Masukkan nomor minuman yang ingin dipesan: ";
            cin >> index;

            if (index < 1 || index > jumlahMinuman)
            {
                cout << " *Nomor minuman tidak valid. Silakan coba lagi." << endl;
            }
            else if (stokMinuman[index - 1] <= 0)
            {
                cout << " *Maaf, stok " << daftarMinuman[index - 1] << " habis." << endl;
                index = -1;
            }
        } while (index < 1 || index > jumlahMinuman);

        do
        {
            cout << " Berapa banyak minuman yang ingin dipesan? (Stok tersedia: " << stokMinuman[index - 1] << "): ";
            cin >> jumlah;

            if (jumlah <= 0)
            {
                cout << " *Jumlah harus lebih dari 0. Silakan coba lagi." << endl;
            }
            else if (jumlah > stokMinuman[index - 1])
            {
                cout << " *Jumlah pesanan melebihi stok yang tersedia. Silakan coba lagi." << endl;
            }
        } while (jumlah <= 0 || jumlah > stokMinuman[index - 1]);

        namaPesanan[pesanan] = daftarMinuman[index - 1];
        hargaPesanan[pesanan] = hargaMinuman[index - 1];
        jumlahPesanan[pesanan] = jumlah;
        totalHargaPesenan += hargaPesanan[pesanan] * jumlahPesanan[pesanan];
        stokMinuman[index - 1] -= jumlah;
        pesanan++;
        totalPesanan++;
    } while (pilihYaTidak("Apakah Anda ingin memesan minuman lain?"));
}

void Toko::pesanAntar()
{
    clearScreen();
    tampilkanHeader("PESAN ANTAR");
    cout << " *Pesan antar akan memerlukan biaya tambahan sebesar Rp" << biayaAntar << "." << endl;

    if (pilihYaTidak("Apakah anda yakin ingin pesan antar?"))
    {
        antar = true;
        cin.ignore();
        cout << " Masukkan Nama Pemesan: ";
        getline(cin, namaPemesan);
        cout << " Masukkan Alamat: ";
        getline(cin, alamatPemesan);
        cout << " Masukkan Nomor Telepon: ";
        cin >> nomorTeleponPemesan;

        if (kodePromoAktif != "GRATISONGKIR" || totalHargaPesenan < 30000)
        {
            totalHargaPesenan += biayaAntar;
        }
        else
        {
            cout << " *Anda mendapatkan promo gratis ongkir!" << endl;
        }

        tampilkanFooter();
        cout << " Pesanan atas nama: " << namaPemesan << endl;
        cout << " Akan diantar ke alamat: " << alamatPemesan << endl;
        cout << " Dengan nomor telepon: " << nomorTeleponPemesan << endl;

        if (kodePromoAktif != "GRATISONGKIR" || totalHargaPesenan < 30000)
        {
            cout << " Biaya antar: Rp" << biayaAntar << endl;
        }

        cout << " Total Harga Pesanan Anda: Rp" << totalHargaPesenan << endl;

        if (pilihYaTidak("Apakah Anda ingin mengubah alamat atau nomor telepon?"))
        {
            string pilihanStr;
            do
            {
                cout << " Apa yang ingin Anda ubah?" << endl;
                cout << " 1. Nama Pemesan" << endl;
                cout << " 2. Alamat" << endl;
                cout << " 3. Nomor Telepon" << endl;
                cout << " 4. Edit semua" << endl;
                cout << " 5. Batal" << endl;
                tampilkanFooter();
                cout << " Masukkan Pilihan: ";
                cin >> pilihanStr;

                if (pilihanStr == "1")
                {
                    cout << " Masukkan Nama Pemesan Baru: ";
                    cin.ignore();
                    getline(cin, namaPemesan);
                    tampilkanFooter();
                    cout << " *Pesan antar berhasil diperbarui." << endl;
                }
                else if (pilihanStr == "2")
                {
                    cout << " Masukkan Alamat Baru: ";
                    cin.ignore();
                    getline(cin, alamatPemesan);
                }
                else if (pilihanStr == "3")
                {
                    cout << " Masukkan Nomor Telepon Baru: ";
                    cin >> nomorTeleponPemesan;
                    tampilkanFooter();
                    cout << " *Pesan antar berhasil diperbarui." << endl;
                }
                else if (pilihanStr == "4")
                {
                    cout << " Masukkan Nama Pemesan Baru: ";
                    cin.ignore();
                    getline(cin, namaPemesan);
                    cout << " Masukkan Alamat Baru: ";
                    getline(cin, alamatPemesan);
                    cout << " Masukkan Nomor Telepon Baru: ";
                    cin >> nomorTeleponPemesan;
                    tampilkanFooter();
                    cout << " *Pesan antar berhasil diperbarui." << endl;
                }
                else if (pilihanStr == "5")
                {
                    tampilkanFooter();
                    cout << " *Pengubahan pesan antar dibatalkan." << endl;
                }
                else
                {
                    cout << " *Pilihan tidak valid. Silakan coba lagi." << endl;
                }
            } while (pilihanStr != "1" && pilihanStr != "2" && pilihanStr != "3" && pilihanStr != "4" && pilihanStr != "5");
        }
    }
    else
    {
        antar = false;
        cout << " *Pesanan Anda tidak akan diantar." << endl;
        pauseScreen();
    }
}

void Toko::pilihMetodePengiriman()
{
    clearScreen();
    tampilkanHeader("PILIH METODE PENGIRIMAN");
    string metodePengiriman;
    do
    {
        cout << " Pilih metode pengiriman:" << endl;
        cout << " 1. Antar" << endl;
        cout << " 2. Ambil Sendiri" << endl;
        tampilkanFooter();
        cout << " Masukkan Pilihan: ";
        cin >> metodePengiriman;

        if (metodePengiriman == "1")
        {
            pesanAntar();
        }
        else if (metodePengiriman == "2")
        {
            antar = false;
            tampilkanFooter();
            cout << " *Pesanan akan disiapkan untuk diambil sendiri." << endl;
        }
        else
        {
            cout << " *Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (metodePengiriman != "1" && metodePengiriman != "2");
}

void Toko::lihatPesanan()
{
    tampilkanHeader("DAFTAR PESANAN ANDA");
    if (totalPesanan > 0)
    {
        for (int i = 0; i < totalPesanan; i++)
        {
            cout << " " << i + 1 << ". " << namaPesanan[i] << " - Rp" << hargaPesanan[i] << " x " << jumlahPesanan[i] << endl;
        }

        tampilkanFooter();
        if (diskonAktif > 0)
        {
            cout << " Diskon (" << kodePromoAktif << "): " << (diskonAktif * 100) << "%" << endl;
            cout << " Subtotal: Rp" << totalHargaPesenan / (1 - diskonAktif) << endl;
        }
        cout << " Total Harga Pesanan Anda: Rp" << totalHargaPesenan << endl;
    }
    else
    {
        cout << " *Anda belum memesan makanan." << endl;
    }
}

void Toko::hapusPesanan()
{
    clearScreen();
    tampilkanHeader("HAPUS PESANAN");
    if (totalPesanan == 0)
    {
        cout << " *Anda belum memesan makanan." << endl;
        pauseScreen();
        return;
    }

    lihatPesanan();
    int index;
    cout << " Masukkan nomor pesanan yang ingin dihapus: ";
    cin >> index;

    if (index < 1 || index > totalPesanan)
    {
        cout << " *Nomor pesanan tidak valid." << endl;
        pauseScreen();
        return;
    }

    for (int i = 0; i < jumlahMakanan; i++)
    {
        if (daftarMakanan[i] == namaPesanan[index - 1])
        {
            stokMakanan[i] += jumlahPesanan[index - 1];
            break;
        }
    }
    for (int i = 0; i < jumlahMinuman; i++)
    {
        if (daftarMinuman[i] == namaPesanan[index - 1])
        {
            stokMinuman[i] += jumlahPesanan[index - 1];
            break;
        }
    }

    totalHargaPesenan -= hargaPesanan[index - 1] * jumlahPesanan[index - 1];

    for (int i = index - 1; i < totalPesanan - 1; i++)
    {
        namaPesanan[i] = namaPesanan[i + 1];
        hargaPesanan[i] = hargaPesanan[i + 1];
        jumlahPesanan[i] = jumlahPesanan[i + 1];
    }
    totalPesanan--;

    if (diskonAktif > 0)
    {
        if (kodePromoAktif == "HEMAT20" && totalHargaPesenan < 50000)
        {
            diskonAktif = 0.0;
            kodePromoAktif = "";
            cout << " *Diskon tidak berlaku lagi karena total pembelian kurang dari Rp50.000" << endl;
        }
        else
        {
            totalHargaPesenan = (totalHargaPesenan / (1 - diskonAktif)) * (1 - diskonAktif);
        }
    }

    tampilkanFooter();
    cout << " *Pesanan berhasil dihapus." << endl;
    pauseScreen();
}

void Toko::batalkanPesanan()
{
    clearScreen();
    tampilkanHeader("BATALKAN PESANAN");
    if (totalPesanan > 0)
    {
        lihatPesanan();
        if (pilihYaTidak("Apakah Anda yakin ingin membatalkan pesanan?"))
        {
            for (int i = 0; i < totalPesanan; i++)
            {
                for (int j = 0; j < jumlahMakanan; j++)
                {
                    if (namaPesanan[i] == daftarMakanan[j])
                    {
                        stokMakanan[j] += jumlahPesanan[i];
                        break;
                    }
                }

                for (int j = 0; j < jumlahMinuman; j++)
                {
                    if (namaPesanan[i] == daftarMinuman[j])
                    {
                        stokMinuman[j] += jumlahPesanan[i];
                        break;
                    }
                }
            }

            totalPesanan = 0;
            totalHargaPesenan = 0;
            diskonAktif = 0.0;
            kodePromoAktif = "";

            if (antar)
            {
                antar = false;
                alamatPemesan = "";
                nomorTeleponPemesan = "";
                namaPemesan = "";
            }

            cout << " *Pesanan berhasil dibatalkan." << endl;
            if (bayarDengan != "")
            {
                cout << " *Pembayaran Anda dengan metode " << bayarDengan << " telah dibatalkan." << endl;
                bayarDengan = "";
            }
        }
        else
        {
            cout << " *Pembatalan pesanan dibatalkan." << endl;
        }
    }
    else
    {
        cout << " *Anda belum memesan makanan." << endl;
    }
    pauseScreen();
}

void Toko::applyPromo()
{
    clearScreen();
    tampilkanHeader("PROMO");
    string kode;
    cout << " Masukkan kode promo: ";
    cin >> kode;

    bool promoValid = false;
    for (int i = 0; i < jumlahPromo; i++)
    {
        if (kode == kodePromo[i])
        {
            promoValid = true;

            if (kode == "HEMAT20" && totalHargaPesenan < 50000)
            {
                cout << " *Promo ini hanya berlaku untuk pembelian minimal Rp50.000" << endl;
                promoValid = false;
            }
            else if (kode == "GRATISONGKIR" && totalHargaPesenan < 30000)
            {
                cout << " *Promo ini hanya berlaku untuk pembelian minimal Rp30.000" << endl;
                promoValid = false;
            }
            else if (kode == "BELI5" && totalPesanan < 5)
            {
                cout << " *Promo ini hanya berlaku untuk pembelian 5 item atau lebih" << endl;
                promoValid = false;
            }
            else
            {
                diskonAktif = diskonPromo[i];
                kodePromoAktif = kodePromo[i];
                totalHargaPesenan = totalHargaPesenan * (1 - diskonAktif);

                cout << " Promo berhasil digunakan!" << endl;
                cout << " Deskripsi: " << deskripsiPromo[i] << endl;
                cout << " Diskon: " << (diskonAktif * 100) << "%" << endl;
                cout << " Total harga setelah diskon: Rp" << totalHargaPesenan << endl;
            }
            break;
        }
    }

    if (!promoValid)
    {
        cout << " *Kode promo tidak valid atau tidak memenuhi syarat." << endl;
    }

    pauseScreen();
}

void Toko::bayarPesanan()
{
    clearScreen();
    tampilkanHeader("BAYAR PESANAN");
    if (totalPesanan > 0)
    {
        lihatPesanan();
        int metodePembayaran;
        do
        {
            cout << " Pilih Metode Pembayaran:" << endl;
            cout << " 1. Tunai" << endl;
            cout << " 2. Transfer Bank" << endl;
            cout << " 3. QRIS" << endl;
            cout << " 4. Dompet Digital" << endl;
            cout << " 5. Kembali" << endl;
            cout << " Masukkan pilihan: ";
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
            case 4:
                pembayaranDigitalWallet();
                bayarDengan = "Dompet Digital";
                break;
            case 5:
                return;
            default:
                cout << " *Metode pembayaran tidak valid. Silakan coba lagi." << endl;
                break;
            }
        } while (metodePembayaran < 1 || metodePembayaran > 5);

        struk();

        totalPesanan = 0;
        totalHargaPesenan = 0;
        diskonAktif = 0.0;
        kodePromoAktif = "";

        if (antar)
        {
            antar = false;
            alamatPemesan = "";
            nomorTeleponPemesan = "";
            namaPemesan = "";
        }
    }
    else
    {
        cout << " *Anda belum memesan makanan." << endl;
        pauseScreen();
        return;
    }
}

void Toko::pembayaranTunai()
{
    clearScreen();
    tampilkanHeader("PEMBAYARAN TUNAI");
    if (totalPesanan > 0)
    {
        lihatPesanan();

        if (!pilihYaTidak("Apakah Anda ingin melanjutkan pembayaran dengan Tunai?"))
        {
            bayarPesanan();
            return;
        }

        int pembayaran = 0;
        int tampung;
        kembalian = 0;

        do
        {
            cout << " Masukkan jumlah uang yang dibayarkan / Tambah pembayaran: Rp";
            cin >> tampung;

            pembayaran += tampung;

            if (pembayaran < totalHargaPesenan)
            {
                cout << " *Uang yang dibayarkan kurang. Silakan tambahkan pembayaran." << endl;
            }

        } while (pembayaran < totalHargaPesenan);

        if (pembayaran > totalHargaPesenan)
        {
            kembalian = pembayaran - totalHargaPesenan;
            cout << " *Pembayaran berhasil. Kembalian Anda: Rp" << kembalian << endl;
        }
        else
        {
            kembalian = 0;
        }
    }
    else
    {
        cout << " *Anda belum memesan makanan." << endl;
    }
    pauseScreen();
}

void Toko::pembayaranTransferBank()
{
    clearScreen();
    tampilkanHeader("PEMBAYARAN TRANSFER BANK");
    if (totalPesanan > 0)
    {
        lihatPesanan();

        if (!pilihYaTidak("Apakah Anda ingin melanjutkan pembayaran dengan Transfer Bank?"))
        {
            bayarPesanan();
            return;
        }

        int pilihanBank;
        do
        {
            cout << " Pilih Bank Pembayaran:" << endl;
            for (int i = 0; i < 4; i++)
            {
                cout << " " << i + 1 << ". " << namaBank[i] << " (Rekening: " << rekeningBank[i] << ")" << endl;
            }
            tampilkanFooter();
            cout << " Masukkan pilihan: ";
            cin >> pilihanBank;

            if (pilihanBank < 1 || pilihanBank > 4)
            {
                cout << " *Pilihan tidak valid. Silakan coba lagi." << endl;
            }
        } while (pilihanBank < 1 || pilihanBank > 4);

        cout << " Silakan transfer ke nomor rekening: " << rekeningBank[pilihanBank - 1] << endl;
        cout << " Atas Nama: TOKO MAKANAN KAMI" << endl;
        cout << " Jumlah: Rp" << totalHargaPesenan << endl;
        tampilkanFooter();
        cout << " *Pembayaran berhasil. Terima kasih telah melakukan pembayaran." << endl;
    }
    else
    {
        cout << " *Anda belum memesan makanan." << endl;
    }
    pauseScreen();
}

void Toko::pembayaranQRIS()
{
    clearScreen();
    tampilkanHeader("PEMBAYARAN QRIS");
    if (totalPesanan > 0)
    {
        lihatPesanan();

        if (!pilihYaTidak("Apakah Anda ingin melanjutkan pembayaran dengan QRIS?"))
        {
            bayarPesanan();
            return;
        }

        cout << " Silakan scan QRIS untuk melakukan pembayaran." << endl;
        cout << " +------------------------+" << endl;
        cout << " | █ █   █   █ █ █   █ █  |" << endl;
        cout << " |   █ █ █ █     █ █ █    |" << endl;
        cout << " | █   █   █ █ █ █   █  |" << endl;
        cout << " | █ █   █   █   █ █ █ █   |" << endl;
        cout << " |   █ █ █   █ █   █   █  |" << endl;
        cout << " | █   █   █   █ █   █ █  |" << endl;
        cout << " | █ █   █ █   █   █   █  |" << endl;
        cout << " |   █   █ █ █   █ █ █    |" << endl;
        cout << " | █   █   █   █   █   █  |" << endl;
        cout << " | █ █   █ █   █ █   █ █  |" << endl;
        cout << " +------------------------+" << endl;
        cout << " Jumlah: Rp" << totalHargaPesenan << endl;

        int pembayaran = 0;
        int tampung;

        do
        {
            cout << " Masukkan jumlah uang yang dibayarkan / Tambah pembayaran" << endl;
            cout << " *Pastikan pembayaran pas (tidak ada kembalian): Rp";
            cin >> tampung;

            pembayaran += tampung;

            if (pembayaran < totalHargaPesenan)
            {
                cout << " *Uang yang dibayarkan kurang. Silakan tambahkan pembayaran." << endl;
            }

        } while (pembayaran < totalHargaPesenan);

        cout << " *Pembayaran berhasil. Terima kasih telah melakukan pembayaran." << endl;
    }
    else
    {
        cout << " *Anda belum memesan makanan." << endl;
    }
    pauseScreen();
}

void Toko::pembayaranDigitalWallet()
{
    clearScreen();
    tampilkanHeader("PEMBAYARAN DOMPET DIGITAL");
    if (totalPesanan > 0)
    {
        lihatPesanan();

        if (!pilihYaTidak("Apakah Anda ingin melanjutkan pembayaran dengan Dompet Digital?"))
        {
            bayarPesanan();
            return;
        }

        string pilihanWallet;
        cout << " Pilih Dompet Digital:" << endl;
        cout << " 1. GoPay" << endl;
        cout << " 2. OVO" << endl;
        cout << " 3. DANA" << endl;
        cout << " 4. LinkAja" << endl;
        tampilkanFooter();
        cout << " Masukkan Pilihan: ";
        cin >> pilihanWallet;

        if (pilihanWallet == "1" || pilihanWallet == "2" || pilihanWallet == "3" || pilihanWallet == "4")
        {
            string namaWallet;
            if (pilihanWallet == "1")
                namaWallet = "GoPay";
            else if (pilihanWallet == "2")
                namaWallet = "OVO";
            else if (pilihanWallet == "3")
                namaWallet = "DANA";
            else
                namaWallet = "LinkAja";

            cout << " Silakan buka aplikasi " << namaWallet << " Anda dan lakukan pembayaran." << endl;
            cout << " Nomor Telepon/ID: 081234567890" << endl;
            cout << " Atas Nama: TOKO MAKANAN KAMI" << endl;
            cout << " Jumlah: Rp" << totalHargaPesenan << endl;
            tampilkanFooter();
            cout << " *Pembayaran berhasil. Terima kasih telah melakukan pembayaran." << endl;
            pauseScreen();
        }
        else
        {
            cout << " *Pilihan tidak valid." << endl;
            pauseScreen();
            pembayaranDigitalWallet();
        }
    }
    else
    {
        cout << " *Anda belum memesan makanan." << endl;
        pauseScreen();
    }
}

void Toko::laporanPenjualan()
{
    clearScreen();
    tampilkanHeader("LAPORAN PENJUALAN");
    cout << " Daftar Menu & Jumlah Dibeli:" << endl;
    for (int i = 0; i < jumlahMakanan; i++)
    {
        cout << " " << i + 1 << ". " << daftarMakanan[i] << " - " << totalDibeli[i] << " kali" << endl;
    }
    for (int i = 0; i < jumlahMinuman; i++)
    {
        cout << " " << (jumlahMakanan + i + 1) << ". " << daftarMinuman[i] << " - " << totalDibeli[jumlahMakanan + i] << " kali" << endl;
    }
    tampilkanFooter();
    cout << "Jumlah Pesanan Antar : " << totalPesananAntar << endl;
    if (totalPesananAntar > 0)
    {
        cout << " Daftar Pesanan Antar:" << endl;
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
    tampilkanFooter();
    cout << " Total Pemasukan : Rp" << totalPemasukan << endl;
    tampilkanFooter();
    pauseScreen();
}

void Toko::laporanStok()
{
    clearScreen();
    tampilkanHeader("LAPORAN STOK");

    cout << " DAFTAR MAKANAN:" << endl;
    for (int i = 0; i < jumlahMakanan; i++)
    {
        cout << " " << i + 1 << ". " << daftarMakanan[i] << " - Stok: " << stokMakanan[i];
        if (stokMakanan[i] < 10)
        {
            cout << " (PERLU RESTOCK!)";
        }
        cout << endl;
    }

    cout << endl
         << " DAFTAR MINUMAN:" << endl;
    for (int i = 0; i < jumlahMinuman; i++)
    {
        cout << " " << i + 1 << ". " << daftarMinuman[i] << " - Stok: " << stokMinuman[i];
        if (stokMinuman[i] < 10)
        {
            cout << " (PERLU RESTOCK!)";
        }
        cout << endl;
    }

    tampilkanFooter();
    pauseScreen();
}

void Toko::laporanReview()
{
    clearScreen();
    tampilkanHeader("LAPORAN REVIEW");

    if (jumlahReview == 0)
    {
        cout << " *Belum ada review dari pelanggan." << endl;
    }
    else
    {
        double totalRating = 0;
        for (int i = 0; i < jumlahReview; i++)
        {
            cout << " Review #" << i + 1 << endl;
            cout << " Rating: " << ratingPelanggan[i] << "/5" << endl;
            cout << " Ulasan: " << reviewPelanggan[i] << endl;
            cout << " -------------------------" << endl;
            totalRating += ratingPelanggan[i];
        }

        double rataRating = totalRating / jumlahReview;
        cout << " Rata-rata Rating: " << rataRating << "/5" << endl;
    }

    tampilkanFooter();
    pauseScreen();
}

void Toko::kelolaKaryawan()
{
    string pilihan;
    do
    {
        clearScreen();
        tampilkanHeader("KELOLA KARYAWAN");
        cout << " 1. Lihat Daftar Karyawan" << endl;
        cout << " 2. Tambah Karyawan" << endl;
        cout << " 3. Edit Karyawan" << endl;
        cout << " 4. Hapus Karyawan" << endl;
        cout << " 5. Cari Karyawan" << endl;
        cout << " 6. Kembali" << endl;
        tampilkanFooter();
        cout << " Masukkan Pilihan: ";
        cin >> pilihan;

        if (pilihan == "1")
        {
            clearScreen();
            tampilkanHeader("DAFTAR KARYAWAN");
            if (jumlahKaryawan == 0)
            {
                cout << " *Belum ada karyawan yang terdaftar." << endl;
            }
            else
            {
                for (int i = 0; i < jumlahKaryawan; i++)
                {
                    cout << " Karyawan #" << i + 1 << endl;
                    cout << " Nama    : " << namaKaryawan[i] << endl;
                    cout << " Jabatan : " << jabatanKaryawan[i] << endl;
                    cout << " Telepon : " << teleponKaryawan[i] << endl;
                    cout << " Alamat  : " << alamatKaryawan[i] << endl;
                    cout << " Gaji    : Rp" << gajiKaryawan[i] << endl;
                    cout << "-------------------------" << endl;
                }
            }
            pauseScreen();
        }
        else if (pilihan == "2")
        {
            if (jumlahKaryawan >= 10)
            {
                cout << " *Kapasitas karyawan sudah penuh (maksimal 10 karyawan)." << endl;
                pauseScreen();
                continue;
            }

            cout << " Masukkan Nama Karyawan: ";
            cin.ignore();
            getline(cin, namaKaryawan[jumlahKaryawan]);

            cout << " Masukkan Jabatan Karyawan: ";
            getline(cin, jabatanKaryawan[jumlahKaryawan]);

            cout << " Masukkan Nomor Telepon Karyawan: ";
            getline(cin, teleponKaryawan[jumlahKaryawan]);

            cout << " Masukkan Alamat Karyawan: ";
            getline(cin, alamatKaryawan[jumlahKaryawan]);

            cout << " Masukkan Gaji Karyawan: ";
            cin >> gajiKaryawan[jumlahKaryawan];

            jumlahKaryawan++;
            cout << " *Karyawan berhasil ditambahkan." << endl;
            pauseScreen();
        }
        else if (pilihan == "3")
        {
            if (jumlahKaryawan == 0)
            {
                cout << " *Belum ada karyawan yang terdaftar." << endl;
                pauseScreen();
                continue;
            }

            clearScreen();
            tampilkanHeader("DAFTAR KARYAWAN");
            for (int i = 0; i < jumlahKaryawan; i++)
            {
                cout << " " << i + 1 << ". " << namaKaryawan[i] << " - " << jabatanKaryawan[i] << endl;
            }

            int index;
            cout << " Masukkan nomor karyawan yang ingin diedit: ";
            cin >> index;

            if (index < 1 || index > jumlahKaryawan)
            {
                cout << " *Nomor karyawan tidak valid." << endl;
                pauseScreen();
                kelolaKaryawan();
                return;
            }

            cin.ignore();
            cout << " Masukkan Nama Karyawan Baru [" << namaKaryawan[index - 1] << "]: ";
            getline(cin, namaKaryawan[index - 1]);

            cout << " Masukkan Jabatan Karyawan Baru [" << jabatanKaryawan[index - 1] << "]: ";
            getline(cin, jabatanKaryawan[index - 1]);

            cout << " Masukkan Nomor Telepon Karyawan Baru [" << teleponKaryawan[index - 1] << "]: ";
            getline(cin, teleponKaryawan[index - 1]);

            cout << " Masukkan Alamat Karyawan Baru [" << alamatKaryawan[index - 1] << "]: ";
            getline(cin, alamatKaryawan[index - 1]);

            cout << " Masukkan Gaji Karyawan Baru [" << gajiKaryawan[index - 1] << "]: ";
            cin >> gajiKaryawan[index - 1];

            tampilkanFooter();
            cout << " *Data karyawan berhasil diperbarui." << endl;
            pauseScreen();
        }
        else if (pilihan == "4")
        {
            if (jumlahKaryawan == 0)
            {
                cout << " *Belum ada karyawan yang terdaftar." << endl;
                pauseScreen();
                continue;
            }

            clearScreen();
            tampilkanHeader("DAFTAR KARYAWAN");
            for (int i = 0; i < jumlahKaryawan; i++)
            {
                cout << " " << i + 1 << ". " << namaKaryawan[i] << " - " << jabatanKaryawan[i] << endl;
            }

            int index;
            cout << " Masukkan nomor karyawan yang ingin dihapus: ";
            cin >> index;

            if (index < 1 || index > jumlahKaryawan)
            {
                cout << " *Nomor karyawan tidak valid." << endl;
                pauseScreen();
                continue;
            }

            for (int i = index - 1; i < jumlahKaryawan - 1; i++)
            {
                namaKaryawan[i] = namaKaryawan[i + 1];
                jabatanKaryawan[i] = jabatanKaryawan[i + 1];
                teleponKaryawan[i] = teleponKaryawan[i + 1];
                alamatKaryawan[i] = alamatKaryawan[i + 1];
                gajiKaryawan[i] = gajiKaryawan[i + 1];
            }
            jumlahKaryawan--;

            cout << " *Karyawan berhasil dihapus." << endl;
            pauseScreen();
        } else if (pilihan == "5")
        {
            clearScreen();
            tampilkanHeader("CARI KARYAWAN");
            string namaCari;
            cout << " Masukkan nama karyawan yang dicari: ";
            cin.ignore();
            getline(cin, namaCari);

            bool ditemukan = false;
            for (int i = 0; i < jumlahKaryawan; i++)
            {
                if (namaKaryawan[i] == namaCari)
                {
                    cout << " Karyawan ditemukan:" << endl;
                    cout << " Nama: " << namaKaryawan[i] << endl;
                    cout << " Jabatan: " << jabatanKaryawan[i] << endl;
                    cout << " Telepon: " << teleponKaryawan[i] << endl;
                    cout << " Alamat: " << alamatKaryawan[i] << endl;
                    cout << " Gaji: " << gajiKaryawan[i] << endl;
                    ditemukan = true;
                    break;
                }
            }

            if (!ditemukan)
            {
                cout << " *Karyawan tidak ditemukan." << endl;
            }
            pauseScreen();
        }
    } while (pilihan != "6");
}

void Toko::pengaturanToko()
{
    string pilihan;
    do
    {
        clearScreen();
        tampilkanHeader("PENGATURAN TOKO");
        cout << " 1. Ganti Nama Toko" << endl;
        cout << " 2. Ganti Biaya Antar" << endl;
        cout << " 3. Ganti Password Admin" << endl;
        cout << " 4. Ganti Password User" << endl;
        cout << " 5. Kembali" << endl;
        cout << " Masukkan Pilihan: ";
        cin >> pilihan;

        if (pilihan == "1")
        {
            cout << " *Fitur ini belum tersedia." << endl;
            pauseScreen();
        }
        else if (pilihan == "2")
        {
            cout << " Biaya antar saat ini: Rp" << biayaAntar << endl;
            cout << " Masukkan biaya antar baru: ";
            cin >> biayaAntar;
            cout << " *Biaya antar berhasil diubah menjadi Rp" << biayaAntar << endl;
            pauseScreen();
        }
        else if (pilihan == "3")
        {
            string passLama, passBaru;
            cout << " Masukkan password admin saat ini: ";
            cin >> passLama;

            if (passLama != password[0])
            {
                cout << " *Password salah!" << endl;
            }
            else
            {
                cout << " Masukkan password admin baru: ";
                cin >> passBaru;
                password[0] = passBaru;
                cout << " *Password admin berhasil diubah." << endl;
            }
            pauseScreen();
        }
        else if (pilihan == "4")
        {
            string passLama, passBaru;
            cout << " Masukkan password user saat ini: ";
            cin >> passLama;

            if (passLama != password[1])
            {
                cout << " *Password salah!" << endl;
            }
            else
            {
                cout << " Masukkan password user baru: ";
                cin >> passBaru;
                password[1] = passBaru;
                cout << " *Password user berhasil diubah." << endl;
            }
            pauseScreen();
        }
    } while (pilihan != "5");
}

void Toko::beriReview()
{
    clearScreen();
    tampilkanHeader("BERI REVIEW");

    if (totalPemasukan == 0)

    {
        cout << " *Anda belum pernah memesan di toko kami." << endl;
        pauseScreen();
        return;
    }

    if (jumlahReview >= 100)
    {
        cout << " *Kapasitas review sudah penuh." << endl;
        pauseScreen();
        return;
    }

    string ulasan;
    int rating;

    cout << " Masukkan rating (1-5): ";
    cin >> rating;
    while (rating < 1 || rating > 5)
    {
        cout << " Rating harus antara 1-5. Silakan coba lagi: ";
        cin >> rating;
    }

    cout << " Masukkan ulasan Anda: ";
    cin.ignore();
    getline(cin, ulasan);

    reviewPelanggan[jumlahReview] = ulasan;
    ratingPelanggan[jumlahReview] = rating;
    jumlahReview++;

    tampilkanFooter();
    cout << " *Terima kasih atas review Anda!" << endl;
    pauseScreen();
}

void Toko::tampilkanPromo()
{
    clearScreen();
    tampilkanHeader("PROMO YANG TERSEDIA");

    if (jumlahPromo == 0)
    {
        cout << " *Tidak ada promo yang tersedia saat ini." << endl;
    }
    else
    {
        for (int i = 0; i < jumlahPromo; i++)
        {
            cout << " Kode Promo : " << kodePromo[i] << endl;
            cout << " Diskon     : " << (diskonPromo[i] * 100) << "%" << endl;
            cout << " Deskripsi  : " << deskripsiPromo[i] << endl;
            cout << "-------------------------" << endl;
        }
    }

    pauseScreen();
}

void Toko::tambahPromo()
{
    clearScreen();
    tampilkanHeader("TAMBAH PROMO");

    if (jumlahPromo >= 5)
    {
        cout << " *Kapasitas promo sudah penuh (maksimal 5 promo)." << endl;
        pauseScreen();
        return;
    }

    string kode, deskripsi;
    float diskon;

    cout << " Masukkan Kode Promo: ";
    cin >> kode;

    cout << " Masukkan Besar Diskon (dalam persen, contoh: 10 untuk 10%): ";
    cin >> diskon;
    while (diskon <= 0 || diskon > 100)
    {
        cout << " *Diskon harus antara 0-100%. Silakan coba lagi: ";
        cin >> diskon;
    }
    diskon = diskon / 100;

    cout << " Masukkan Deskripsi Promo: ";
    cin.ignore();
    getline(cin, deskripsi);

    kodePromo[jumlahPromo] = kode;
    diskonPromo[jumlahPromo] = diskon;
    deskripsiPromo[jumlahPromo] = deskripsi;
    jumlahPromo++;

    cout << " *Promo berhasil ditambahkan." << endl;
    pauseScreen();
}

void Toko::hapusPromo()
{
    clearScreen();
    tampilkanHeader("HAPUS PROMO");

    if (jumlahPromo == 0)
    {
        cout << " *Tidak ada promo yang tersedia." << endl;
        pauseScreen();
        return;
    }

    tampilkanPromo();

    string kode;
    cout << " Masukkan kode promo yang ingin dihapus: ";
    cin >> kode;

    bool ditemukan = false;
    for (int i = 0; i < jumlahPromo; i++)
    {
        if (kodePromo[i] == kode)
        {
            for (int j = i; j < jumlahPromo - 1; j++)
            {
                kodePromo[j] = kodePromo[j + 1];
                diskonPromo[j] = diskonPromo[j + 1];
                deskripsiPromo[j] = deskripsiPromo[j + 1];
            }
            jumlahPromo--;
            ditemukan = true;
            cout << " *Promo berhasil dihapus." << endl;
            break;
        }
    }

    if (!ditemukan)
    {
        cout << " *Promo dengan kode tersebut tidak ditemukan." << endl;
    }

    pauseScreen();
}

void Toko::struk()
{
    clearScreen();
    tampilkanHeader("STRUK PEMBAYARAN");
    if (antar)
    {
        cout << " Pesanan atas nama : " << namaPemesan << endl;
        cout << " Alamat            : " << alamatPemesan << endl;
        cout << " Nomor Telepon     : " << nomorTeleponPemesan << endl;
    }
    cout << "----------------------------------------" << endl;
    cout << " Daftar Pesanan Anda:" << endl;
    for (int i = 0; i < totalPesanan; i++)
    {
        cout << " " << i + 1 << ". " << namaPesanan[i] << " - Rp" << hargaPesanan[i] << " x " << jumlahPesanan[i] << endl;
    }

    if (diskonAktif > 0)
    {
        tampilkanFooter();
        cout << " Subtotal         : Rp" << totalHargaPesenan / (1 - diskonAktif) << endl;
        cout << " Diskon (" << kodePromoAktif << ") : " << (diskonAktif * 100) << "%" << endl;
    }

    if (antar)
    {
        if (kodePromoAktif == "GRATISONGKIR" && totalHargaPesenan >= 30000)
        {
            cout << " Biaya antar     : Rp0 (Promo)" << endl;
        }
        else
        {
            cout << " Biaya antar     : Rp" << biayaAntar << endl;
        }
    }

    tampilkanFooter();
    cout << " Total Harga Pesanan Anda: Rp" << totalHargaPesenan << endl;
    cout << " Metode Pembayaran       : " << bayarDengan << endl;
    if (bayarDengan == "Tunai")
    {
        cout << " Kembalian               : Rp" << kembalian << endl;
    }
    tampilkanFooter();
    cout << " *Terima kasih telah berbelanja di Toko Kami!" << endl;

    for (int i = 0; i < totalPesanan; i++)
    {
        for (int j = 0; j < jumlahMakanan; j++)
        {
            if (namaPesanan[i] == daftarMakanan[j])
            {
                totalDibeli[j] += jumlahPesanan[i];
                break;
            }
        }
        for (int j = 0; j < jumlahMinuman; j++)
        {
            if (namaPesanan[i] == daftarMinuman[j])
            {
                totalDibeli[jumlahMakanan + j] += jumlahPesanan[i];
                break;
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

    pauseScreen();
}

int main()
{
    Toko toko;
    toko.home();
    return 0;
}
