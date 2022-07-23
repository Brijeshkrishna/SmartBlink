#include <Arduino.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <LiquidCrystal.h>

DynamicJsonDocument doc(4097);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

unsigned int end = 16;
unsigned int start = 0;
String data ;
String user ;

String get_msg(String StrDisplay)
{ 
  
  String StrProcess = StrDisplay + "          ";

  if (end > StrProcess.length()){
    end = 16;
    start = 0;
  }
  return StrProcess.substring(end++, start++);
}


void print_lcd(){
  lcd.setCursor(0, 0);
  lcd.print("brijesh");
  lcd.setCursor(0, 1);

  if (user.length() > 16)
    lcd.print(get_msg(data));
  else
    lcd.print(data);
}

void setup()
{
  Serial.begin(9600);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.begin(16, 2);
}

void loop(){
  

  while(Serial.available()) {
    data = Serial.readString();
 
    DeserializationError error = deserializeJson(doc,data);
 
    if(error){
      Serial.println(data);
     return;

    }

    user = doc["user"].as<String>();
    data = doc["msg"].as<String>();
    Serial.print("user => "+user+" msg => "+ data);
  
  }
}



