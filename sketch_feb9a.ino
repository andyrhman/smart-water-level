// Inklusi library LiquidCrystal
#include <LiquidCrystal.h>

// Inisialisasi objek LiquidCrystal dengan pin yang terhubung ke LCD
LiquidCrystal lcd(13,  12,  11,  10,  9,  8);

// Definisi pin
const int motor1 =  5;
const int MB1 = A1;
const int MB2 =  4;
const int MB3 =  3;

// Variabel untuk menghitung liter air
int liter =  0;
// Variabel untuk menyimpan nilai RS
int RS =  0;

void setup() {
  // Mulai komunikasi serial
  Serial.begin(9600);
  // Konfigurasi ukuran LCD
  lcd.begin(20,  4);

  // Atur pin motor sebagai OUTPUT
  pinMode(motor1, OUTPUT);
  // Atur pin sensor sebagai INPUT
  pinMode(MB1, INPUT);
  pinMode(MB2, INPUT);
  pinMode(MB3, INPUT);
  // Matikan motor pada startup
  digitalWrite(motor1, LOW);

  // Cetak judul pada LCD
  lcd.setCursor(0,  0);
  lcd.print("Meteran Air Cerdas");

  // Cetak data liter dan RS pada LCD
  lcd.setCursor(0,  1);
  lcd.print("L=");
  lcd.print(liter);
  lcd.setCursor(11,  1);
  lcd.print("Rs=");
  lcd.print(RS);
  // Cetak status motor pada LCD
  lcd.setCursor(5,  3);
  lcd.print("Motor= OFF");
}

void loop() {
  // Jika MB1 dan MB2 HIGH dan liter kurang dari  50
  if (digitalRead(MB1) == HIGH && digitalRead(MB2) == HIGH && liter <  50) {
    // Nyalakan motor
    digitalWrite(motor1, HIGH);
    lcd.setCursor(5,  3);
    lcd.print("Motor= ON  ");

    // Tambahkan liter
    liter++;
    lcd.setCursor(0,  1);
    lcd.print("L=");
    lcd.print(liter);
    // Baca nilai sensor
    int sensorValue = analogRead(A0);
    // Hitung nilai RS
    RS = liter *  3;
    lcd.setCursor(11,  1);
    lcd.print("Rs=");
    lcd.print(RS);
  }
  // Jika MB1 dan MB3 HIGH dan liter antara  50 dan  100
  else if (digitalRead(MB1) == HIGH && digitalRead(MB3) == HIGH && liter <  100 && liter >=  50) {
    // Nyalakan motor
    digitalWrite(motor1, HIGH);
    lcd.setCursor(5,  3);
    lcd.print("Motor= ON  ");

    // Tambahkan liter
    liter++;
    lcd.setCursor(0,  1);
    lcd.print("L=");
    lcd.print(liter);
    // Baca nilai sensor
    int sensorValue = analogRead(A0);
    // Hitung nilai RS
    RS = liter *  3;
    lcd.setCursor(11,  1);
    lcd.print("Rs=");
    lcd.print(RS);
  } else {
    // Matikan motor
    digitalWrite(motor1, LOW);
    lcd.setCursor(5,  3);
    lcd.print("Motor= OFF");
  }

  // Tunda selama 90 milidetik
  delay(90);
}
