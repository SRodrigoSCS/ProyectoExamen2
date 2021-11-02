#include <LiquidCrystal.h>
LiquidCrystal LCD(12,11,5,4,3,2);
void setup()
{
  Serial.begin(9600);
  LCD.begin(16, 2);
  pinMode(A0, INPUT);
}
float Newton, Vsal, Res, Peso, Sensor;
void loop()
{
  Sensor= analogRead(A0);
  Vsal=(5*Sensor)/1023;
  Res= 150*((5/Vsal)-1);
  Newton = pow(Res/6.2491,-1.3351135);
  Peso = Newton/9.81;
  LCD.setCursor(0,0);
  LCD.print("Sensor: ");
  LCD.print(Newton);
  LCD.print(" N");
  LCD.setCursor(0,1);
  LCD.print("Peso: ");
  LCD.print(Peso);
  LCD.print(" g");
}
