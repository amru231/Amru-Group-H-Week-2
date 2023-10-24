#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// initialize lcd
LiquidCrystal_I2C lcd(0x20, 16, 2);

int switchUpPin = 13;
int switchDownPin = 12;
int counter = 0;
int buttonUpState = 0;
int lastButtonUpState = 0;
int buttonDownState = 0;
int lastButtonDownState = 0;

void setup() { 
  Serial.begin(9600);
  lcd.init(); 
  lcd.backlight();
  pinMode(switchUpPin, INPUT);
  pinMode(switchDownPin, INPUT);

// display initial value
  lcd.setCursor(0,0);
  lcd.print("Counter: ");
  lcd.setCursor(9,0);
  lcd.print(counter);
} 

// up down switch

void loop() {
  buttonUpState = digitalRead(switchUpPin);
  buttonDownState = digitalRead(switchDownPin);

  if (buttonUpState != lastButtonUpState) {
    if (buttonUpState == HIGH) {
      if(counter < 9) { 
        counter++; 
      } 
      Serial.println(counter);       
      updateLCD(counter);       
      delay(300); 
    } 
    delay(50); 
  }

  if (buttonDownState != lastButtonDownState) {
    if (buttonDownState == HIGH) {
      if(counter > 0) {
        counter--; 
      }
      Serial.println(counter);
      updateLCD(counter);
      delay(300); 
    } 
    delay(50);
  } 

  lastButtonUpState = buttonUpState; 
  lastButtonDownState = buttonDownState;
} 

// lcd number update

void updateLCD(int count){
  lcd.setCursor(9,0); 
  lcd.print(" "); 
  lcd.setCursor(9,0); 
  lcd.print(count);
}