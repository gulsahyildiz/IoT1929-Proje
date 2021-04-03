#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <LiquidCrystal_I2C_AvrI2C.h>

LiquidCrystal_I2C_AvrI2C lcd(0x27,16,2);
Servo servo;

#define sdaPin 10 
#define rstPin 4
#define motor 7

int green = 5;
int red = 6;


MFRC522 mfrc522(sdaPin, rstPin);   
int statuss = 0;
int out = 0;

void setup() {

  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  servo.attach(7);
  Serial.begin(9600); 
  lcd.begin();
  lcd.backlight();  
  SPI.begin();      
  mfrc522.PCD_Init(); 
  
  lcd.setCursor(0,0);
  lcd.print("KARTINIZI OKUTUN.");
  
 
}

void loop() {

    if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }

  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  lcd.clear();
  Serial.print(" UID kodu :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  content.toUpperCase();
  if (content.substring(1) == "DC 17 5F 22")
  {
    lcd.setCursor(0,0);
    lcd.print("GIRIS BASARILI.");
    lcd.setCursor(0,1);
    lcd.print("HOS GELDINIZ!");
    
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);

    servo.write(90);
    delay(5000);
    servo.write(0);
    digitalWrite(green, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("KARTINIZI OKUTUN.");
  }
  
  else   {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("KART");
    lcd.setCursor(0,1);
    lcd.print("TANIMLANMADI!");
    
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
    delay(5000);
    digitalWrite(red, LOW);
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("KARTINIZI OKUTUN.");
    

  }
}
