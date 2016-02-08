// By Ben Hardy
// Based off SparkFun tutorials 7 and 15 that came with my Arduino kit
// available at sparkfun.com/sikcode

#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Current Temp:");

}

void loop() {
  // put your main code here, to run repeatedly:
  float voltage, degreesC, degreesF;
  voltage = getVoltage(0);
  degreesC = (voltage - 0.5) * 100.0;
  degreesF = degreesC * (9.0/5.0) + 32.0;  

  
  lcd.setCursor(0,1);
  
  char temps[30];
  sprintf(temps, "%dC    %dF", int(degreesC), int(degreesF));
  //Serial.println(temps);
  lcd.print(degreesC);
  lcd.setCursor(5,1);
  lcd.print("C");
  lcd.setCursor(8,1);
  lcd.print(degreesF);
  lcd.setCursor(13,1);
  lcd.print("F");
  delay(2000); 
}

float getVoltage(int pin)
{
  return (analogRead(pin) * 0.004882814);
}
