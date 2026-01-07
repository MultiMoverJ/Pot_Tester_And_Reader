//Pot Reader V0.1
//by David Jason Hall


//#include <DS3231.h> Time Modual Libary
#include <LiquidCrystal_I2C.h> // LCD Libary


int Debug = true;

LiquidCrystal_I2C lcd(0x27, 28, 4);


// the setup routine runs once when you press reset:
void setup() {
  lcd.init();
  lcd.backlight();
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  //Serial.println("Multi MOver Sensor Tester");
  //Serial.println("Ver : 0.01");
  //Serial.println("By: David Jason Hall");
  //Serial.println("Patent Pending");
  lcd.setCursor(2,1);
  //lcd.print("Company Name");
  lcd.print("Mult - Mover  UK");
  lcd.setCursor(0,3);
  lcd.print("Ver: 0.0.1");
  delay(2000);
  lcd.clear();
}


// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValueA = analogRead(A0); //Only used for all
  
  //int sensorValueB = analogRead(A1); //Only used for models xxl and above
  //int sensorValueC = analogRead(A2); //Only used for models xxl and above
  //int sensorValueD = analogRead(A3); //Only used for models xxl and above

  // Raw data to Voltage convesion
  float voltageA= sensorValueA * (5.0 / 975.0); // Math for the conversion from raw data to something readable
  //float voltageB= sensorValueB * (5.0 / 975.0); // Math for the conversion from raw data to something readable
  //float voltageC= sensorValueC * (5.0 / 975.0); // Math for the conversion from raw data to something readable
  //float voltageD= sensorValueD * (5.0 / 975.0); // Math for the conversion from raw data to something readable

  
  // print out the value you read:
  if (Debug == true) {Serial.print ("Input 1 : ") * Serial.print(voltageA) * Serial.println("");}  
  //if (Debug == true) {Serial.print ("Input 2 : ") * Serial.print(voltageB) * Serial.println("");}
  //if (Debug == true) {Serial.print ("Input 3 : ") * Serial.print(voltageC) * Serial.println("");}
  //if (Debug == true) {Serial.print ("Input 4 : ") * Serial.print(voltageD) * Serial.println("");}

  
  lcd.setCursor(0,0); lcd.print("Sensor 1 : "); lcd.setCursor(11,0); lcd.print(voltageA);
  lcd.setCursor(0,1); lcd.print("Sensor 2 : "); lcd.setCursor(11,1); lcd.print("No Conn.."); //lcd.print(voltageB);
  lcd.setCursor(0,2); lcd.print("Sensor 3 : "); lcd.setCursor(11,2); lcd.print("No Conn.."); //lcd.print(voltageC);
  lcd.setCursor(0,3); lcd.print("Sensor 4 : "); lcd.setCursor(11,3); lcd.print("No Conn.."); //lcd.print(voltageD);

  //Lcd.print("Hello World");
  delay(1000);  // delay in between reads for stability
}
