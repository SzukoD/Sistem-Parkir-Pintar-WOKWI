#include <ESP32Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <HTTPClient.h>

// Wi-Fi credentials
const char* ssid = "Wokwi-GUEST";  // SSID default di Wokwi
const char* password = "";  // Tidak ada password di Wokwi Wi-Fi

// Google Sheets API endpoint (URL Web App Google Apps Script Anda)
String serverURL = "https://script.google.com/macros/s/AKfycbyLtWP_mgVfOfy0gyz6enr33By95gCjINubml-Jw2Me6meqq8f_M5H-MZC82q67xH0low/exec";

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin1 = 2;
const int echoPin1 = 0;

const int trigPin2 = 10;
const int echoPin2 = 9;

Servo servoMasuk;
Servo servoKeluar;

const int servoMasukPin = 19;
const int servoKeluarPin = 34;

int slot = 6;
const int batasJarak = 10;
int lastSlot = 200;  // Variabel untuk menyimpan slot sebelumnya

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  servoMasuk.attach(servoMasukPin);
  servoKeluar.attach(servoKeluarPin);

  servoMasuk.write(0);
  servoKeluar.write(0);

  lcd.init();
  lcd.clear();
  lcd.backlight();  // Mengaktifkan backlight

  tampilkanSlot();

  Serial.begin(115200);

  // Sambungkan ke Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected to WiFi");
}

void loop() {
  long jarakMasuk = bacaUltrasonik(trigPin1, echoPin1);
  if (jarakMasuk > 0 && jarakMasuk <= batasJarak) {
    if (slot > 0) {
      slot--;
      bukaServo(servoMasuk);
      tampilkanSlot();

      // Kirim data hanya jika slot berubah
      if (slot != lastSlot) {
        kirimDataKeGoogleSheets("Kendaraan Masuk");  // Kirimkan data ke Google Sheets
        lastSlot = slot;  // Menyimpan nilai slot terakhir yang telah berubah
      }

      delay(2000);  // Tunggu 2 detik setelah kendaraan masuk
    }
  }

  long jarakKeluar = bacaUltrasonik(trigPin2, echoPin2);
  if (jarakKeluar > 0 && jarakKeluar <= batasJarak) {
    if (slot < 200) {
      slot++;
      bukaServo(servoKeluar);
      tampilkanSlot();

      // Kirim data hanya jika slot berubah
      if (slot != lastSlot) {
        kirimDataKeGoogleSheets("Kendaraan Keluar");  // Kirimkan data ke Google Sheets
        lastSlot = slot;  // Menyimpan nilai slot terakhir yang telah berubah
      }

      delay(2000);  // Tunggu 2 detik setelah kendaraan keluar
    }
  }

  delay(500);  // Tunggu sejenak untuk mencegah pembacaan berulang terlalu cepat
}

long bacaUltrasonik(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long durasi = pulseIn(echo, HIGH, 30000);
  if (durasi == 0) ;
  return durasi * 0.034 / 2;
}

void bukaServo(Servo &servo) {
  servo.write(90);
  delay(1000);
  servo.write(0);
}

void tampilkanSlot() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Slot Parkir:");
  lcd.setCursor(0, 1);
  lcd.print(slot);
  lcd.print(" motor");
}

void kirimDataKeGoogleSheets(String keterangan) {
  // Membuat string post data untuk mengirim data ke Google Sheets
  String postData = "slot=" + String(slot) + 
                    "&keterangan=" + keterangan + 
                    "&statusParkir=" + (slot == 0 ? "Penuh" : "Tersedia") + 
                    "&lokasi=AreaA";  // Kirimkan status slot parkir dan tambahan data

  // Debugging: Tampilkan data yang akan dikirim di Serial Monitor
  Serial.print("Data yang dikirim: ");
  Serial.println(postData);

  HTTPClient http;
  http.begin(serverURL);  // Mulai koneksi HTTP ke server
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");  // Set content type untuk POST data

  int httpResponseCode = http.POST(postData);  // Mengirim HTTP POST request

  // Debugging HTTP Response Code
  Serial.print("HTTP Response Code: ");
  Serial.println(httpResponseCode);

  if (httpResponseCode == 200) {
    Serial.println("Data sent successfully");
  } else {
    Serial.println("Error sending data");
    String payload = http.getString();
    Serial.println("Response Payload: ");
    Serial.println(payload);  // Tampilkan respons dari server
  }

  http.end();  // Menutup koneksi HTTP
}
