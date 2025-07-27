
# Sistem Parkir Pintar dengan Manajemen Slot Real-Time

## Deskripsi
Sistem Parkir Pintar ini adalah proyek yang dikembangkan untuk mata kuliah **Organisasi dan Arsitektur Komputer (OAK)** di **Universitas Teknologi Bandung**. Proyek ini bertujuan untuk memberikan solusi **manajemen parkir otomatis dan efisien** dengan memanfaatkan teknologi **Edge-Computing** dan **Cloud-Computing**.

Dengan menggunakan **ESP32**, **sensor ultrasonik**, dan **motor servo**, sistem ini secara otomatis mengelola status slot parkir dan memperbarui informasi secara real-time ke **Google Sheets**, sehingga pengelola dapat memantau status parkir dari jarak jauh.

## Fitur Utama
- **Deteksi Kendaraan Otomatis** menggunakan **sensor ultrasonik** untuk mendeteksi kendaraan yang memasuki dan keluar dari slot parkir.
- **Kontrol Pintu Parkir** secara otomatis dengan **motor servo** untuk membuka dan menutup pintu parkir berdasarkan status kendaraan.
- **Manajemen Data Real-Time** menggunakan **Google Sheets** untuk menyimpan status slot parkir yang dapat diakses dari jarak jauh.
- **Simulasi Wokwi** yang memvisualisasikan alur kerja sistem parkir pintar.

## Teknologi yang Digunakan
- **ESP32**: Mikrokontroler dengan kemampuan Wi-Fi untuk mengendalikan sensor dan motor servo.
- **Sensor Ultrasonik**: Mengukur jarak kendaraan dan memberikan sinyal untuk membuka pintu parkir.
- **Motor Servo**: Digunakan untuk membuka dan menutup pintu parkir sesuai kebutuhan.
- **Google Sheets**: Tempat penyimpanan data status parkir secara real-time.
- **Wokwi**: Platform untuk mensimulasikan dan mendemonstrasikan cara kerja sistem secara visual. Jika Anda tidak memiliki perangkat fisik, Anda dapat menggunakan **Wokwi** untuk menjalankan simulasi proyek ini.

## Libraries yang Digunakan
Berikut adalah library yang diinstal dalam proyek ini:

- **LiquidCrystal I2C**: Untuk menampilkan informasi status slot parkir di layar LCD.
- **Servo**: Untuk mengendalikan motor servo dalam membuka dan menutup pintu parkir.
- **ESP32Servo**: Digunakan khusus untuk kontrol motor servo pada ESP32.

## Tujuan Proyek
- Mengoptimalkan penggunaan ruang parkir di area yang padat seperti gedung perkantoran atau tempat parkir umum.
- Mengurangi waktu tunggu kendaraan dalam mencari slot parkir yang tersedia.
- Memberikan solusi **IoT (Internet of Things)** yang terintegrasi dengan **cloud computing** untuk mempermudah pengelolaan parkir.

## Demo
Simak video demo proyek kami untuk melihat bagaimana sistem parkir pintar ini bekerja di **[YouTube](https://youtu.be/LUXA-J6YsoQ?si=IIke9WmznAZ-GYEc)**.

## Instalasi
Untuk menjalankan proyek ini, pastikan Anda sudah menginstal beberapa hal berikut:

1. **Arduino IDE** untuk mengunggah kode ke ESP32.
2. **Library ESP32 Servo dan gspread** untuk kontrol motor servo dan komunikasi dengan Google Sheets.

### Langkah-langkah Instalasi:
1. **Clone repositori**:
   ```bash
   git clone https://github.com/username/Sistem-Parkir-Pintar.git
   ```

2. **Menginstal dependensi**:
   - Pastikan Anda menginstal **ESP32 Board** melalui Board Manager di Arduino IDE.
   - Instal **gspread** library untuk menghubungkan dengan Google Sheets.

3. **Unggah kode ke ESP32**:
   - Buka file `parkir_pintar.ino` di Arduino IDE dan unggah ke board ESP32 Anda.

4. **Konfigurasi Google Sheets**:
   - Ikuti petunjuk pada dokumentasi **gspread** untuk menghubungkan sistem dengan Google Sheets.

## Dokumentasi
Untuk penjelasan lebih lanjut, Anda dapat melihat dokumentasi pada bagian **[Dokumentasi Proyek](https://github.com/username/Sistem-Parkir-Pintar/wiki)** (gantilah dengan link jika ada).

## Anggota Kelompok
- **Arif Rahmansyah**  
- **Bintang Dwi Ramadhan**  
- **Fadli Septian Sutaryana**  
- **Gholib Ahmad Refan**  
- **M Dafa Dwi Saputra**  
- **Muhammad Sultan Fathurasyid**  

## Lisensi
Proyek ini dilisensikan di bawah **MIT License** - lihat [LICENSE](LICENSE) untuk informasi lebih lanjut.

---

> "Menggunakan teknologi untuk mempermudah hidup, sistem parkir pintar yang mengoptimalkan ruang parkir secara otomatis dan efisien."
