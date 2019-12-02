#include <Wire.h>
#include <LiquidCrystal.h>
#include <DS3231.h>
LiquidCrystal lcd(12,11,5,4,3,2);

int led = 13;
int received = 0;
int i;
const int buzzer = 9;


void setup() {
  Serial.begin(9600); 
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
}
 
void loop() {
  while (Serial.available() > 0) {
    received = Serial.read();
  
    if (received == 'a'){
    delay(200);
    Serial.println("MOVEMENT");
    lcd.begin(16,2);
    tone(buzzer, 700);
    lcd.print("You have...");
    lcd.setCursor(0,1);
    delay(1000);
    lcd.print("Snail Mail!!!");
    delay(2000);
    noTone(buzzer);
    }
    
    else if (received == 'r'){
      lcd.begin(16,2);
      tone(buzzer, 700);
      lcd.print("Snail Mailbox:");
      lcd.setCursor(0,1);
      delay(1000);
      lcd.print("EMPTY");
      delay(2000);  
      noTone(buzzer);
    }
  }
}

 
