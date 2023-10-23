// Define pins for segment

const int A = 2;
const int B  = 3;
const int C = 4;
const int D = 6;
const int DP = 5;
const int E = 7;
const int F = 8;
const int G = 9; 
  
int switchUpPin = 13;
int switchDownPin = 12;
int counter = 0;
int buttonUpState = 0;
int lastButtonUpState = 0;
int buttonDownState = 0;
int lastButtonDownState = 0; 
  
// Intialize digital pins as outputs

void setup() { 
  Serial.begin(9600); 
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT); 
  digitalWrite(DP ,HIGH);
} 
  // up down switch

void loop() {
  buttonUpState = digitalRead(switchUpPin); 
  buttonDownState = digitalRead(switchDownPin);
  if (buttonUpState != lastButtonUpState) {
    if (buttonUpState == HIGH) {
      if(counter == 9) {
        counter = 9;
      } 
      counter++; 
      Serial.println(counter);       
      changeNumber(counter);       
      delay(300); 
    } else { 
      Serial.println("OFF"); 
    } 
    delay(50); 
  }
  if (buttonDownState != lastButtonDownState) {
    if (buttonDownState == HIGH) {
      if(counter == 0) {
        counter = 0; 
      }
      counter--;
      Serial.println(counter);
      changeNumber(counter);
      delay(300); 
    } else { 
      Serial.println("OFF");
    } 
    delay(50);
  } 
  changeNumber(counter);
} 
 
// 0 = A,B,C,D,E,F
// 1 = B,C
// 2 = A,B,G,E,D
// 3 = A,B,C,D,G
// 4 = A,F,G,C,D
// 5 = A,C,D,F,G
// 6 = A,C,D,E,F,G
// 7 = A,B,C
// 8 = A,B,C,D,E,F,G
// 9 = A,B,C,D,F,G

void changeNumber(int buttonPress) {
  switch (buttonPress) {
    case 0: 
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);
    break;
    case 1: 
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    break; 
    case 2:
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, LOW);
    break; 
    case 3:
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, LOW);
    break; 
    case 4:
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    break; 
    case 5: 
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    break; 
    case 6: 
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    break; 
    case 7:
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    break; 
    case 8: 
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    break; 
    case 9: 
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    break;
  } 
} 
 
 
