#include <SoftwareSerial.h>
#include <Servo.h>
Servo servomecatronicos;


SoftwareSerial myApp(7,8); //7-RX 8-TX
//RXD BLUETOOTH - PIN 8  
//TXD BLUETOOTH - PIN 7

char myChar;
//puente h
int IN1 = 9;
int IN2 = 10;
int IN3 = 11;
int IN4 = 12;

void setup() {
  servomecatronicos.attach(3); //seleccionemos un pin libre. Luego vemos mejor cual es el ideal



  
  Serial.begin(9600);
  myApp.begin(9600);
  Serial.println("SERIAL PC LISTO");
  myApp.println("APP LISTA#");
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
void loop() {

  while(myApp.available()){
    myChar=myApp.read();
    Serial.print(myChar);
    myApp.print(myChar);
    myApp.print("#");
    if(myChar=='U'){
      adelante();
    }
    if(myChar=='D'){
      atras();
    }
    if(myChar=='L'){
      izquierda();
    }
     if(myChar=='R'){
      derecha();
    }
     if(myChar=='p'){
      parar();
    }
    if(myChar=='Y'){
      servomotor();
    }
    if(myChar=='O'){
      servomotor1();
    }
    
  }
  while(Serial.available()){
    myChar= Serial.read();
    myApp.print(myChar);
    myApp.print("#");
  }
}

void adelante(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  myApp.print("Funcion ejecutada");
}
void atras(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  myApp.print("Funcion ejecutada");
}
void izquierda(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  myApp.print("Funcion ejecutada");
}
void derecha(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  myApp.print("Funcion ejecutada");
}
void parar(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  myApp.print("Funcion ejecutada");
}
void servomotor(){
   servomecatronicos.write(0);
   delay(0);
}
void servomotor1(){
  servomecatronicos.write(180);
  delay(0);
}
 
