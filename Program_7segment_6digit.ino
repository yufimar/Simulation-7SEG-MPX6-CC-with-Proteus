#include "LedControl.h" //Menggunakan library Led Control
LedControl lc=LedControl(12,11,10,0); // Pin DIN,CLK,CS,No.
unsigned int siklus=0;
/* Wiring Module Display MAX7219 (6digit 7segment) ke Arduino (Uno)
 Arduino Pin D12 to DIN, (Data In/SDA/Data/MISO) 
 Arduino Pin D11 to CLK, (Clock/SCK/SCL/MOSI)
 Arduino Pin D10 to CS, (Shift/SS)
 No.of devices is 1 (Display Urutan ke 1) */

const int PB1 = 7, PB2 = 6, PB3 = 5; // Pin yang digunakan push button

/* hasil mapping dimasukkan, ke struktur program dibawah
char adalah type variabel nya, penulisannya seperti berikut 
[Nama_Variable] = [Bilangan HexaDecimal dari karakter yang akan di tampilkan]
*/

char hurufA=0x7d, hurufU=0x3e, hurufN=0x76, hurufI=0x06, hurufM1=0x66, hurufM2=0x72, hurufE=0x4f,hurufC=0x4e,hurufF=0x47,hurufB=0x1f; 
char angka1=0x30, angka2=0x6d, angka3=0x79, angka4=0x33, angka5=0x5b, angka6=0x5f, angka7=0x70, angka8=0x7f, angka9=0x7b, angka0=0x7e;
unsigned long delaytime=20, detime=10;

void setup()
{
  Serial.begin(9600);
  pinMode(PB1, INPUT);    digitalWrite(PB1,HIGH);
  pinMode(PB2, INPUT);    digitalWrite(PB2,HIGH);
  pinMode(PB3, INPUT);    digitalWrite(PB3,HIGH);

  /* Initialize the IC Driver Control LedMAX7219 device
   Kondisi default Max7219 saat power ON adalah Standby jadi harus kita aktifkan terlebih dahulu...*/
  lc.shutdown(0,false);   // Enable display
  lc.setIntensity(0,15);  // Set brightness level (Level Kecerahan : 0 sampai 15)
  lc.clearDisplay(0);     // Clear display register (Mengkosongkan tampilan segment)
}

void loop()
{ 
  if (digitalRead(PB1)== LOW ){
    siklus=1;}
  if (digitalRead(PB2)== LOW ){
    siklus=2;}
  if (digitalRead(PB3)== LOW ){
    siklus=3;}      
Serial.println(siklus);
  switch (siklus)
  {
  case 1: 
  mercubuana();
  break;
  
  case 2:
  nim();
  break;
  
  case 3:
  tgl();
  break;
  
  }
}


// menampilkan Nama Kampus
void mercubuana() {
  for (int i =0; i<detime ; i++) {
    for (int a=0; a<6;a++) {
      lc.setRow(0,0,hurufM1);       delay(delaytime);
      lc.setRow(0,1,hurufM2);       delay(delaytime);
      lc.setRow(0,2,hurufE);        delay(delaytime);
      lc.setRow(0,3,hurufM1);       delay(delaytime);
      lc.setRow(0,4,hurufC);        delay(delaytime);
      lc.setRow(0,5,hurufU);        delay(delaytime);
      lc.clearDisplay(0);
    }
  } 

  delay(200);
  for (int i =0; i<detime ; i++) {
    for (int a=0; a<6;a++) {
      lc.setRow(0,0,hurufB);       delay(delaytime);
      lc.setRow(0,1,hurufU);       delay(delaytime);
      lc.setRow(0,2,hurufA);       delay(delaytime);
      lc.setRow(0,3,hurufN);       delay(delaytime);
      lc.setRow(0,4,hurufA);       delay(delaytime);
      lc.clearDisplay(0);
    }
  }
  delay(200);
  siklus=0;
}

// menampilkan NIM
void nim() {
  for (int i =0; i<detime ; i++) {
    for (int a=0; a<6;a++) {
      lc.setRow(0,0,angka4);       delay(delaytime);
      lc.setRow(0,1,angka1);       delay(delaytime);
      lc.setRow(0,2,angka4);       delay(delaytime);
      lc.setRow(0,3,angka1);       delay(delaytime);
      lc.setRow(0,4,angka8);       delay(delaytime);
      lc.setRow(0,5,angka1);       delay(delaytime);
      lc.clearDisplay(0);
    }
  }
  delay(200);
  for (int i =0; i<detime ; i++) {
    for (int a=0; a<6;a++) {
      lc.setRow(0,0,angka2);       delay(delaytime);
      lc.setRow(0,1,angka0);       delay(delaytime);
      lc.setRow(0,2,angka0);       delay(delaytime);
      lc.setRow(0,3,angka8);       delay(delaytime);
      lc.setRow(0,4,angka2);       delay(delaytime);
      lc.clearDisplay(0);
    }
  }
  delay(200);  
  siklus=0;
}

// menampilkan TGL Lahir
void tgl() {
  for (int i =0; i<detime ; i++) {
    for (int a=0; a<6;a++) {
      lc.setRow(0,0,angka2);       delay(delaytime);
      lc.setRow(0,1,angka4);       delay(delaytime);
      lc.setRow(0,3,hurufF);       delay(delaytime);
      lc.setRow(0,4,hurufE);       delay(delaytime);
      lc.setRow(0,5,hurufB);       delay(delaytime);
      lc.clearDisplay(0);
    }
  }
  delay(200);
  for (int i =0; i<detime ; i++) {
    for (int a=0; a<6;a++) {
      lc.setRow(0,0,angka1);       delay(delaytime);
      lc.setRow(0,1,angka9);       delay(delaytime);
      lc.setRow(0,2,angka9);       delay(delaytime);
      lc.setRow(0,3,angka7);       delay(delaytime);
      lc.clearDisplay(0);
    }
  }
  delay(200);  
  siklus =0;
}



