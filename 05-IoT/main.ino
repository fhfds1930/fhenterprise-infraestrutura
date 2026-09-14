#include <LiquidCrystal.h>
#include <Servo.h>

const int pinSensor = A0;
const int pinLedVerde = 2;
const int pinLedAmarelo = 3;
const int pinLedVermelho = 4;
const int pinServo = 6;
const int pinBuzzer = 7;

Servo cooler;
LiquidCrystal lcd(12, 11, 10, 9, 8, 13);

void setup() {
  pinMode(pinLedVerde, OUTPUT);
  pinMode(pinLedAmarelo, OUTPUT);
  pinMode(pinLedVermelho, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  
  cooler.attach(pinServo);
  cooler.write(0);

  lcd.begin(16, 2);
  lcd.print("FH ENTERPRISE");
  lcd.setCursor(0, 1);
  lcd.print("MONITOR DATACENTER");
  delay(1500);
  lcd.clear();
}

void loop() {
  int leituraRaw = analogRead(pinSensor);
  float voltagem = leituraRaw * (5.0 / 1024.0);
  float temperaturaC = (voltagem - 0.5) * 100.0;

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperaturaC, 1);
  lcd.print((char)223);
  lcd.print("C   ");

  if (temperaturaC < 25.0) {
    digitalWrite(pinLedVerde, HIGH);
    digitalWrite(pinLedAmarelo, LOW);
    digitalWrite(pinLedVermelho, LOW);
    
    noTone(pinBuzzer);
    digitalWrite(pinBuzzer, LOW);
    cooler.write(0);
    
    lcd.setCursor(0, 1);
    lcd.print("STATUS: NORMAL  ");
  } 
  else if (temperaturaC >= 25.0 && temperaturaC <= 35.0) {
    digitalWrite(pinLedVerde, LOW);
    digitalWrite(pinLedAmarelo, HIGH);
    digitalWrite(pinLedVermelho, LOW);
    cooler.write(90);
    
    lcd.setCursor(0, 1);
    lcd.print("STATUS: ATENCAO ");

    tone(pinBuzzer, 1000, 100);
  } 
  else {
    digitalWrite(pinLedVerde, LOW);
    digitalWrite(pinLedAmarelo, LOW);
    digitalWrite(pinLedVermelho, HIGH);
    cooler.write(180);
    
    lcd.setCursor(0, 1);
    lcd.print("STATUS: CRITICO!");

    tone(pinBuzzer, 1800);
  }

  delay(400);
}
