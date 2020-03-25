#include "DHT.h"
#include <LiquidCrystal.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include <TimeLib.h>
#include <DS1307RTC.h>


// Bluetooth 
#include <SoftwareSerial.h>
SoftwareSerial Genotronex(10, 11); // RX, TX
//

#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)

Adafruit_BMP280 bmp; // I2C

LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 

const char *months [12] {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

#define DHTPIN 8   
#define DHTTYPE DHT22  

DHT dht(DHTPIN, DHTTYPE);


void send2Digits (int number){
  if (number >= 0 && number < 10){    
     Genotronex.print("0");
  }
  Genotronex.print(number);
}

// Tutaj dodane zeby wyswietlało zawsze godzine i minute oraz date na dwoch miejscach 
void return2digits(int number){
  if (number >= 0 && number < 10) {
    lcd.print("0");
    lcd.print(number);
    }
   else{lcd.print(number);}
}

void setup() {
  Genotronex.begin(9600);
  Serial.begin(9600);
  while (!Serial) ; // wait for serial
  delay(200);
  Serial.println(F("DHTxx test!"));
  Serial.println(F("BMP280 test"));
  Serial.println("DS1307RTC Read Test");
  Serial.println("-------------------");
  
  dht.begin();

  if (!bmp.begin(0x76)) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);}

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

}

void loop() {

  tmElements_t tm;
  
  delay(2000);

  // dane z dht 

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
 
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  // dane z bmp 

  float t2 = bmp.readTemperature();
  float p = bmp.readPressure()*0.01;

  lcd.begin(16, 2);       //Deklaracja typu wyswietlacza 
  lcd.setCursor(0, 0);    //Ustawienie kursora
  lcd.print("Temp1:");    //Wyświetlenie tekstu
  lcd.setCursor(7, 0);    //Ustawienie kursora 
  lcd.print(t);           // Wyswietlenie zmiennej
  lcd.setCursor(13, 0);   // itd ..
  lcd.print("C");         // itd ..
  
  lcd.setCursor(0, 1); 
  lcd.print("Temp2:"); 
  lcd.setCursor(7, 1); 
  lcd.print(t2); 

  lcd.setCursor(13, 1); 
  lcd.print("C"); 

  delay(2000);

  lcd.clear();

  lcd.setCursor(0, 0); 
  lcd.print("Wilg:"); 
  lcd.setCursor(6, 0); 
  lcd.print(h); 

  lcd.setCursor(12, 0); 
  lcd.print("%"); 
  
  lcd.setCursor(0, 1); 
  lcd.print("Cisn:"); 
  lcd.setCursor(6, 1); 
  lcd.print(p); 

  lcd.setCursor(13 , 1); 
  lcd.print("hPa"); 

  delay(2000);
  
  lcd.clear();


  if(RTC.read(tm)){

  lcd.setCursor(0,0);
  lcd.print("Date:");
  lcd.setCursor(5,0);
  //lcd.print(tm.Day);
  return2digits(tm.Day);
  lcd.setCursor(8,0);
  lcd.print(months[tm.Month-1]);
  lcd.setCursor(12,0);
  lcd.print(tmYearToCalendar(tm.Year));
    
  lcd.setCursor(0, 1); 
  lcd.print("Time:"); 
  lcd.setCursor(6, 1); 
  //lcd.print(tm.Hour); 
  return2digits(tm.Hour);
  lcd.print(":");
  lcd.setCursor(9, 1); 
  //lcd.print(tm.Minute); 
  return2digits(tm.Minute);
  lcd.setCursor(11,1);
  lcd.print(":");
  lcd.setCursor(12, 1); 
  //lcd.print(tm.Second); 
  return2digits(tm.Second);

  
   for(int n=0;n<100;n++){
    Genotronex.println();
  }

  // Wysylanie informacji modułem Bluetooth

  Genotronex.print("Data : ");
  send2Digits(tm.Day);
  Genotronex.print(" ");
  Genotronex.print(months[tm.Month-1]);
  Genotronex.print(" ");
  Genotronex.println(tmYearToCalendar(tm.Year));

  Genotronex.print("Czas : ");
  send2Digits(tm.Hour);
  Genotronex.print(":");
  send2Digits(tm.Minute);
  Genotronex.print(":");
  send2Digits(tm.Second);
  Genotronex.println();
  
  Genotronex.print("Temperatura 1 : ");
  Genotronex.print(t);
  Genotronex.println(" C");
  Genotronex.print("Temperatura 2 : ");
  Genotronex.print(t2);
  Genotronex.println(" C");

  Genotronex.print("Wilgotnosc : ");
  Genotronex.print(h);
  Genotronex.println(" %");
  Genotronex.print("Cisnienie : ");
  Genotronex.print(p);
  Genotronex.println(" hPa");

  }
  
}