#include <LiquidCrystal.h>

// Pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int ThermistorPin = 0;
int Vo;
float R1 = 100000;
float logR2, R2, T, Tc, Tf;

float c1 = 0.000570569668;
float c2 = 0.000239294362;
float c3 = 0.000000047282773;

int getSmoothedAnalog(int pin, int samples = 10) {
  long total = 0;
  for (int i = 0; i < samples; i++) {
    total += analogRead(pin);
    delay(5);
  }
  return total / samples;
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  Vo = getSmoothedAnalog(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = 1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2);
  Tc = T - 273.15;
  Tf = (Tc * 9.0) / 5.0 + 32.0;

  Serial.print("Temperature: ");
  Serial.print(Tf);
  Serial.print(" F; ");
  Serial.print(Tc);
  Serial.println(" C");

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(Tc, 1);
  lcd.print((char)223); // ° symbol
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(Tf, 1);
  lcd.print((char)223);
  lcd.print("F");

  delay(500);
}
