#include <SoftwareSerial.h>


SoftwareSerial sim7600a(10, 11);  // RX, TX


const int pirPin = 2;

void setup() {

  Serial.begin(9600);
  sim7600a.begin(9600);


  pinMode(pirPin, INPUT);


  delay(2000);
  
 
  sim7600a.println("AT+CMGF=1");
  delay(1000);
  

  sim7600a.println("AT+CMGS=\"+525649293692\""); 
  delay(1000);
  

  sim7600a.println("Movimiento Detectado");
  delay(1000);
  

  sim7600a.write(0x1A);
}

void loop() {

  if (digitalRead(pirPin) == HIGH) {

    delay(5000);
    
   
    sim7600a.println("AT+CMGF=1");
    delay(1000);
    
   
    sim7600a.println("AT+CMGS=\"+525649293692\"");  
    delay(1000);
    
   
    sim7600a.println("Movimiento Detectado");
    delay(1000);
    
  
    sim7600a.write(0x1A);
  }
}
