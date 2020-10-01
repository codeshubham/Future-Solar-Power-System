#include <Servo.h>

Servo sr;
int l1,l2,a=10,error=65,ip=90;

void setup() {
  pinMode(a,OUTPUT);
   pinMode(A1, INPUT);   
  pinMode(A0, INPUT);
     sr.attach(12);
Serial.begin(9600);
sr.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
l1=analogRead(A1);
l2=analogRead(A0);
Serial.println(l1);
Serial.println(l2);


int diff1=abs(l1-l2);
int diff2=abs(l2-l1);
if((diff1 <= error) || (diff2 <= error)) {
  ip=ip+0;
  } else {    
    if(l1 > l2)
    {
      ip=ip-1;;  
    }
    if(l1 < l2) 
    {
      ip=ip+1; 
    }
  }
 sr.write(ip); 
  delay(100);
 }
