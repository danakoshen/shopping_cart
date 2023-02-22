#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Debug.h>
#include <MFRC522Extended.h>
#include <MFRC522Hack.h>
#include <require_cpp11.h>
#include <SPI.h>
#include <LiquidCrystal.h>

#define SS_PIN 10
#define RST_PIN 9

LiquidCrystal lcd(A2, A3, 3, 2, 1, 0);
MFRC522 mfrc522(SS_PIN, RST_PIN);   

int price = 0;
int button = 0;
int milk = 0;
int bread = 0;
int juice = 0;
int water = 0;
int butter = 0;

void setup() 
{
  lcd.begin(16, 2);
  lcd.print("NU Smart Cart");
  SPI.begin();      
  mfrc522.PCD_Init();   
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);  
  pinMode(8, OUTPUT); 
}
void loop() 
{
  button = digitalRead(A1);
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
String UID = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) 
{
     UID.concat(String(mfrc522.uid.uidByte[i]
     < 0x10 ? " 0" : " "));
     UID.concat(String(mfrc522.uid.uidByte[i]
     , HEX));
}
  UID.toUpperCase();

 if (button == LOW){
  if (UID.substring(1) == "B3 6D 79 89") 
  {
    digitalWrite(A0, HIGH);
    price += 200;
    milk++;
    lcd.setCursor(0, 0);
    lcd.print("Milk, 200 KZT   ");
    lcd.setCursor(0, 1);
    lcd.print("Total = ");
    lcd.print(price);
    delay(1000);
    digitalWrite(A0, LOW);
    delay(3000);
  }
  else if (UID.substring(1) == "22 E3 97 54")
  {
    digitalWrite(A0, HIGH);
    price += 80;
    bread++;
    lcd.setCursor(0, 0);
    lcd.print("Bread, 80 KZT   ");
    lcd.setCursor(0, 1);
    lcd.print("Total = ");
    lcd.print(price);
    delay(1000);
    digitalWrite(A0, LOW);
    delay(3000);
  }
  else if (UID.substring(1) == "F2 1F 9A 54")
  {
    digitalWrite(A0, HIGH);
    price += 100;
    juice++;
    lcd.setCursor(0, 0);
    lcd.print("Juice, 100 KZT   ");
    lcd.setCursor(0, 1);
    lcd.print("Total = ");
    lcd.print(price);
    delay(1000);
    digitalWrite(A0, LOW);
    delay(3000);
  }
  else if (UID.substring(1) == "C2 86 A3 54")
    {
    digitalWrite(A0, HIGH);
    price += 170;
    water++;
    lcd.setCursor(0, 0);
    lcd.print("Water, 170 KZT   ");
    lcd.setCursor(0, 1);
    lcd.print("Total = ");
    lcd.print(price);
    delay(1000);
    digitalWrite(A0, LOW);
    delay(3000);
  }
  else if (UID.substring(1) == "16 44 53 C3")
    {
    digitalWrite(A0, HIGH);
    price += 300;
    butter++;
    lcd.setCursor(0, 0);
    lcd.print("Butter, 300 KZT   ");
    lcd.setCursor(0, 1);
    lcd.print("Total = ");
    lcd.print(price);
    delay(1000);
    digitalWrite(A0, LOW);
    delay(3000);
  }
  else {
    Serial.println(" Product not found");
    delay(3000);
  }
 }
  else {
  if (UID.substring(1) == "B3 6D 79 89") 
  {
    digitalWrite(8, HIGH);
    if (milk > 0){
      price -= 200;
      milk--;
      lcd.setCursor(0, 0);
      lcd.print("Milk,-200 KZT   ");
      lcd.setCursor(0, 1);
      lcd.print("Total = ");
      lcd.print(price);
      lcd.print("     ");
    }
    else{
      lcd.setCursor(0, 0);
      lcd.print("NO MILK LEFT   ");}
    delay(1000);
    digitalWrite(8, LOW);
    delay(3000);}
  else if (UID.substring(1) == "22 E3 97 54")
  {
    digitalWrite(8, HIGH);
    if (bread > 0){
      price -= 80;
      bread--;
      lcd.setCursor(0, 0);
      lcd.print("Bread,-80 KZT   ");
      lcd.setCursor(0, 1);
      lcd.print("Total = ");
      lcd.print(price);
      lcd.print("     ");
      }
    else {
      lcd.setCursor(0, 0);
      lcd.print("NO BREAD LEFT   ");
    }
    delay(1000);
    digitalWrite(8, LOW);
    delay(3000);
  }
  else if (UID.substring(1) == "F2 1F 9A 54")
  {
    digitalWrite(8, HIGH);
    if (juice > 0){
      price -= 100;
      juice--;
      lcd.setCursor(0, 0);
      lcd.print("Juice,-100 KZT  ");
      lcd.setCursor(0, 1);
      lcd.print("Total = ");
      lcd.print(price);
      lcd.print("     ");
      }
    else {
      lcd.setCursor(0, 0);
      lcd.print("NO JUICE LEFT   ");
    }
    delay(1000);
    digitalWrite(8, LOW);
    delay(3000);
  }
  else if (UID.substring(1) == "C2 86 A3 54")
    {
    digitalWrite(8, HIGH);
    if (water > 0){
      price -= 170;
      water--;
      lcd.setCursor(0, 0);
      lcd.print("Water,-170 KZT   ");
      lcd.setCursor(0, 1);
      lcd.print("Total = ");
      lcd.print(price);
      lcd.print("     ");
      }
    else {
      lcd.setCursor(0, 0);
      lcd.print("NO WATER LEFT   ");
    }
    delay(1000);
    digitalWrite(8, LOW);
    delay(3000);
  }
  else if (UID.substring(1) == "16 44 53 C3")
    {
    digitalWrite(8, HIGH);
    if (butter > 0){
      price -= 300;
      butter--;
      lcd.setCursor(0, 0);
      lcd.print("Butter,-300 KZT   ");
      lcd.setCursor(0, 1);
      lcd.print("Total = ");
      lcd.print(price);      
      lcd.print("     ");
      }
    else {
      lcd.setCursor(0, 0);
      lcd.print("NO BUTTER LEFT   ");   
    }
    delay(1000);
    digitalWrite(8, LOW);
    delay(3000);
  }
  else   {
    Serial.println(" Product not found");
    delay(3000);
  }
  }
}
