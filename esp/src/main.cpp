#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>
#include <cstring>
#include <time.h>
#include <sys/time.h>
#include "auth.h"

#define HOST "https://api.telegram.org/bot"


#define RECEIVE_URL String(HOST) + String(TOKEN) + "/getUpdates?offset=-1"
#define SEND_URL String(HOST) + String(TOKEN) + "/sendMessage?chat_id=" + String(CHAT_ID) + "&text="

WiFiClientSecure client;
HTTPClient http_send;
HTTPClient http_receive;
WiFiClient *playload;

DynamicJsonDocument receive_buffer(6144);
DynamicJsonDocument send_buffer(4097);

char user[33];
char buffer[4097] ;


void send()
{
  
  send_buffer["user"] = user;
  send_buffer["msg"] = buffer;
  serializeJson(send_buffer,Serial);

  boolean messageReady = false;
  while(messageReady == false) { 
    if(Serial.available()) {
      messageReady = true;
    }
  }

}

void send_msg()
{

    http_send.begin(client, SEND_URL + buffer);
    http_send.GET();
    send();

}


bool receive_msg()
{

  if (http_receive.GET() == HTTP_CODE_OK)  {
 
    deserializeJson(receive_buffer, http_receive.getStream());
    JsonObject result = receive_buffer["result"][0]["message"];

    if (strcmp(result["text"] , buffer))
    {

      strcpy(user,result["chat"].as<JsonObject>()["first_name"]);
      strcpy(buffer,result["text"].as<const char *>());
      return  true;
    }
    else
      return false;
  }
  return false;
}

void connect_wifi()
{

  WiFi.begin(SSID, PASSWORD);
  Serial.print("\nConnecting to ");
  Serial.print(SSID);
  Serial.print(" WIFI ");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print("⏳");
  }
  Serial.print("\nConnected to WiFi network with IP Address ==> ");
  Serial.println(WiFi.localIP());
  http_receive.begin(client, RECEIVE_URL);

}

void http_setup()
{

  Serial.println("Connecting to Telegram Server...");
  client.setInsecure();

  if (!client.connect(HOST, 443))
    Serial.println("Connection Success 👍");
  else{
    Serial.println("Connection failed 👎");
    return;
  }

  http_send.begin(client, RECEIVE_URL);
  pinMode(16, OUTPUT);
  pinMode(2, OUTPUT);
}



void setup()
{

  Serial.begin(9600);

  connect_wifi();
  
  http_setup();
  strcpy(buffer,"BOT Started ");
  send_msg();
}

void loop()
{
  if (receive_msg())
    send_msg();
}

// #include <ESP8266WiFi.h>
// #include <ESP8266WebServer.h>
// #include <ArduinoJson.h>


// char* ssid = "Krishna";
// char* password = "12345678";
// void handleIndex()
// {

//   DynamicJsonDocument doc(1024);
 

//   doc["type"] = "request";
//   serializeJson(doc,Serial);

  
  
// }
// void setup()
// {

//   Serial.begin(9600);

// }

// void loop()
// {
//   handleIndex();
// }

