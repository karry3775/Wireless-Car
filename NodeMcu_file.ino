#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <SoftwareSerial.h>

//lets start the webserver instance on port 80
ESP8266WebServer server(80);

//lets create instance of the SoftwareSerial class
SoftwareSerial s(D6,D5); //RX AND TX respectively

//network credentials
const char* ssid = "your network ssid"; //type iwgetid in ubunut terminal to get it
const char* password = "your networks password";

void setup(){
  s.begin(9600);  
  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED){
    delay(10);
    }

   //lets start the server
   server.on("/",[](){server.send(200,"text/plain","Welcome to home page of motor control");});
   server.on("/forward",moveforward);
   server.on("/stop",stopit);
   server.begin();
  
  }

void loop(){
  server.handleClient(); //receive incoming information from the clients
  
  }

void moveforward(){
  s.write(1);
  server.send(200,"text/plain","moving forward");
  
  }
void stopit(){
  s.write(0);
  server.send(200,"text/plain","stopping");
  
  }
