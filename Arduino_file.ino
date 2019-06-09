#include <SoftwareSerial.h>
#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11

//lets define RX AND TX Pins for UART serial communication
SoftwareSerial s(2,3) ;//rx and tx

void setup(){
  s.begin(9600);
  Serial.begin(9600);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT); 
//  stopit();
  
  
  }

void loop(){

  
  if(s.available()){
    int data = s.read();
    Serial.println(data);
    if(data==1){
      forward();
      }
    if(data==0){
      stopit();
      }
    }

 
  
  
  }

void forward(){
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  
  }
void stopit() {
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
//  Serial.println("stopping");
}
