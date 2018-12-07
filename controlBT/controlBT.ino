
#include <SoftwareSerial.h>

SoftwareSerial mySerial(8, 9); // RX, TX
byte in1 = 2;
byte in2 = 3;
byte in3 = 4;
byte in4 = 5;

void setup() {
  // put your setup code here, to run once:
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);

Serial.begin(9600);
mySerial.begin(38400);

}
  char command;
void loop() {
  // put your main code here, to run repeatedly:
  if (mySerial.available() > 0) {
     command = mySerial.read();
     Serial.println(command);
      if (command == 'F') {
      forward();
    }
    else if (command == 'B') {
      reward();
    }

    else if (command == 'R') {
      right();
    }


    else if (command == 'L') {
      left();
    }

     else if (command == 'S') {
      STOP();
    }
    
  }
    
  
}

void forward() {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);

}
void reward() {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}
void right() {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}
void left() {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);

}

void STOP() {
  
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
}

