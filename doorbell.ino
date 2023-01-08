#include <ESP8266WiFi.h>

const char* ssid = "{SSID}";
const char* password = "{PASSWORD}";

const char* resource = "{IFTTT WEBHOOK URL}"
const char* server = "maker.ifttt.com";

int Button = D1;
int ButtonOLD = 0;
int ButtonCURRENT;

void setup() {
  Serial.begin(9600);
  
  // connect to wifi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected to Network!");
  
  pinMode(D1, INPUT);
}


void loop() {
  
  // read status of doorbell button
  int ButtonCURRENT = digitalRead(Button);

  // Serial.println(ButtonOLD);
  // Serial.println(ButtonCurrent);
  
  // if button toggled, send IFTTT request to send notification
  // button cooldown so notifications aren't spammed
  if (ButtonCURRENT== HIGH && ButtonOLD == LOW) {
    Serial.println("Someone is at the door\n");      
    webIFTTTRequest();          
    delay(10000);
  }
  
  ButtonOLD = ButtonCURRENT;

}


void webIFTTTRequest() {
  // send GET web request to IFTTT
  
  WiFiClient client;
  client.connect(server, 80);


  if (!client.connect(server,80)) {
    Serial.println("Connection Failed");
  }
  
  client.print(String("GET ") + resource + " HTTP/1.1\r\n" +
                  "Host: " + server + "\r\n" + 
                  "Connection: close\r\n\r\n");
                                 
  client.stop();
}
