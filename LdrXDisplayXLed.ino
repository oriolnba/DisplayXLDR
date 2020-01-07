#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int ledPin = 13;
int ldrPin = A0;

void setup() {
  Serial.begin(9600);
  lcd.begin(0x27,16, 2);
  pinMode (ledPin, OUTPUT);  
  pinMode (ldrPin, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Si el nivel de ");
  lcd.setCursor(0,1);
  lcd.print("luz<2 led ON");
  delay(7000);
}

void loop() {
  int ldrStatus = analogRead(ldrPin);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Nivel de Luz");
  lcd.setCursor(0,1);
  lcd.print(ldrStatus);
  
  if (ldrStatus <=3) {
    digitalWrite(ledPin, HIGH);
    lcd.setCursor(5,1);
    lcd.print("LED ON");
  }

  else {
    digitalWrite(ledPin, LOW);
    lcd.setCursor(5,1);
    lcd.print("LED OFF");
  }

}
