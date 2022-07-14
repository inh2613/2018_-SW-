<<<<<<< Updated upstream
#include <SoftwareSerial.h>
#include <SPI.h>
#include <SdFat.h>
#include <SdFatUtil.h>
#include <SFEMP3Shield.h>
SoftwareSerial BTSerial(5,4);
#define trig1 A4
#define eco1 A3
#define trig2 A5
#define eco2 A2
#define cled A0
int sensor=A1;
int button=10;
SdFat sd;
SFEMP3Shield MP3player;
char ar[3];
int state0;
void setup() {
  pinMode(trig1,OUTPUT);
  pinMode(eco1,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(eco2,INPUT);
  pinMode(sensor,INPUT);
  pinMode(button,INPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);
  sd.begin(SD_SEL, SPI_HALF_SPEED);
}

void loop() {
  long distance1=0, distance2=0, old1, old2;
  ar[3]={0};
  ar[0] = BTSerial.read();
    if(ar[0] == 'a'){
    analogWrite(3,180);
    ar[0] = 'z';
  }
    
  while(ar[0] == 'z'){
   state0 = digitalRead(sensor); 
   Serial.println(state0);
 
   
   if(state0 == 1)
  {
    Serial.println("led on");
    BTSerial.write('O');
    analogWrite(3,255);
    
     delay(5000);
     distance1 = cm1();
     distance2 = cm2(); 
     
    while(1){
     ar[1] = BTSerial.read();
     if(ar[1] == 'b'){
     analogWrite(3,0);
     ar[0]="0";
     break;
     }
     //스트레칭
     if(ar[1] == 'v'){
      MP3player.begin(); 
      while(1){
        MP3player.playTrack(05);
      ar[2]=BTSerial.read();
        if(ar[2] == 's'){
          MP3player.stopTrack();
          MP3player.end();
          MP3player.vs_init();
          ar[0]="0";
          break;
      }
    }break; 
   }

     
   if(ar[1] == 'i'){
     analogWrite(3,100);
     BTSerial.write('X');
     Serial.println("basic on");
   
     while(1){
      ar[2]=BTSerial.read();
      if(ar[2] == 'j'){
        
          analogWrite(3,0);
          Serial.println("basic off");
          ar[0]="0";
          break;
     
    }
   }
   break;
  }
    //백색
   if(ar[1] == 'd'){
      MP3player.begin();
      while(1){
      MP3player.playTrack(03);
      ar[2] = BTSerial.read();
        if(ar[2] == 'w'){
          MP3player.stopTrack();
          MP3player.end();
          MP3player.vs_init();
          ar[0]="0";
   
          break;
      }
   }
 }
   

    if(ar[1] == 'c'){
      MP3player.begin();
      int time=millis();
      int oldtime=time;
      while(1){
        time=millis();
        analogWrite(3, 255);
        delay(300);
        analogWrite(3, 0);
        delay(300);
       if(time - oldtime >= 5000) {
        MP3player.playTrack(04);
         }
       if(digitalRead(button) == LOW){
        MP3player.stopTrack();
        MP3player.end();
        MP3player.vs_init();
        analogWrite(3,255);
        break;
       }
      }
    }
//파티
    if(ar[1] == 'f'){
      MP3player.begin();
      BTSerial.write('X');
      while(1){
       ar[2] = BTSerial.read();
       analogWrite(cled, 255);
       analogWrite(3, 255);
        delay(100);
        analogWrite(cled, 0);
        analogWrite(3, 0);
        delay(100);
        MP3player.playTrack(02);
        if(ar[2] == 'g'){
          MP3player.stopTrack();
          MP3player.end();
          MP3player.vs_init();
          ar[0]="0";
   
          break;
        }
       
      } break;
    } 
   
    
    old1 = distance1;
    old2 = distance2;
    distance1 = cm1(); Serial.println(distance1);
    distance2 = cm2();Serial.println(distance1);
    
    if(old1 - distance1 >= 50 || old2 - distance2 >= 50){
      Serial.println("led off");
      BTSerial.write('X');
      analogWrite(3,0);
      //analogWrite(4,0); 
      break;
       }
    }
    state0 = 0;
  }
  delay(5000);
 }
 
}
 int cm1(){
  long duration1,distance1;

  digitalWrite(trig1, HIGH);      //Trig 핀 High
  delayMicroseconds(10);            //10us 유지
  digitalWrite(trig1, LOW);        //Trig 핀 Low
  
  duration1 = pulseIn(eco1,HIGH);
  distance1 = duration1/29/2;
  
  delay(500);
  return distance1;
}
int cm2(){
  long duration2, distance2;
   
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  duration2 = pulseIn(eco2,HIGH);
 
  distance2 = duration2/29/2;
  
  delay(500);
  return distance2;
}
=======
#include <SoftwareSerial.h>
#include <SPI.h>
#include <SdFat.h>
#include <SdFatUtil.h>
#include <SFEMP3Shield.h>
SoftwareSerial BTSerial(5,4);
#define trig1 A4
#define eco1 A3
#define trig2 A5
#define eco2 A2
#define cled A0
int sensor=A1;
int button=10;
SdFat sd;
SFEMP3Shield MP3player;
char ar[3];
int state0;
void setup() {
  pinMode(trig1,OUTPUT);
  pinMode(eco1,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(eco2,INPUT);
  pinMode(sensor,INPUT);
  pinMode(button,INPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);
  sd.begin(SD_SEL, SPI_HALF_SPEED);
}

void loop() {
  long distance1=0, distance2=0, old1, old2;
  ar[3]={0};
  ar[0] = BTSerial.read();
    if(ar[0] == 'a'){
    analogWrite(3,180);
    ar[0] = 'z';
  }
    
  while(ar[0] == 'z'){
   state0 = digitalRead(sensor); 
   Serial.println(state0);
 
   
   if(state0 == 1)
  {
    Serial.println("led on");
    BTSerial.write('O');
    analogWrite(3,255);
    
     delay(5000);
     distance1 = cm1();
     distance2 = cm2(); 
     
    while(1){
     ar[1] = BTSerial.read();
     if(ar[1] == 'b'){
     analogWrite(3,0);
     ar[0]="0";
     break;
     }
     //스트레칭
     if(ar[1] == 'v'){
      MP3player.begin(); 
      while(1){
        MP3player.playTrack(05);
      ar[2]=BTSerial.read();
        if(ar[2] == 's'){
          MP3player.stopTrack();
          MP3player.end();
          MP3player.vs_init();
          ar[0]="0";
          break;
      }
    }break; 
   }

     
   if(ar[1] == 'i'){
     analogWrite(3,100);
     BTSerial.write('X');
     Serial.println("basic on");
   
     while(1){
      ar[2]=BTSerial.read();
      if(ar[2] == 'j'){
        
          analogWrite(3,0);
          Serial.println("basic off");
          ar[0]="0";
          break;
     
    }
   }
   break;
  }
    //백색
   if(ar[1] == 'd'){
      MP3player.begin();
      while(1){
      MP3player.playTrack(03);
      ar[2] = BTSerial.read();
        if(ar[2] == 'w'){
          MP3player.stopTrack();
          MP3player.end();
          MP3player.vs_init();
          ar[0]="0";
   
          break;
      }
   }
 }
   

    if(ar[1] == 'c'){
      MP3player.begin();
      int time=millis();
      int oldtime=time;
      while(1){
        time=millis();
        analogWrite(3, 255);
        delay(300);
        analogWrite(3, 0);
        delay(300);
       if(time - oldtime >= 5000) {
        MP3player.playTrack(04);
         }
       if(digitalRead(button) == LOW){
        MP3player.stopTrack();
        MP3player.end();
        MP3player.vs_init();
        analogWrite(3,255);
        break;
       }
      }
    }
//파티
    if(ar[1] == 'f'){
      MP3player.begin();
      BTSerial.write('X');
      while(1){
       ar[2] = BTSerial.read();
       analogWrite(cled, 255);
       analogWrite(3, 255);
        delay(100);
        analogWrite(cled, 0);
        analogWrite(3, 0);
        delay(100);
        MP3player.playTrack(02);
        if(ar[2] == 'g'){
          MP3player.stopTrack();
          MP3player.end();
          MP3player.vs_init();
          ar[0]="0";
   
          break;
        }
       
      } break;
    } 
   
    
    old1 = distance1;
    old2 = distance2;
    distance1 = cm1(); Serial.println(distance1);
    distance2 = cm2();Serial.println(distance1);
    
    if(old1 - distance1 >= 50 || old2 - distance2 >= 50){
      Serial.println("led off");
      BTSerial.write('X');
      analogWrite(3,0);
      //analogWrite(4,0); 
      break;
       }
    }
    state0 = 0;
  }
  delay(5000);
 }
 
}
 int cm1(){
  long duration1,distance1;

  digitalWrite(trig1, HIGH);      //Trig 핀 High
  delayMicroseconds(10);            //10us 유지
  digitalWrite(trig1, LOW);        //Trig 핀 Low
  
  duration1 = pulseIn(eco1,HIGH);
  distance1 = duration1/29/2;
  
  delay(500);
  return distance1;
}
int cm2(){
  long duration2, distance2;
   
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  duration2 = pulseIn(eco2,HIGH);
 
  distance2 = duration2/29/2;
  
  delay(500);
  return distance2;
}
>>>>>>> Stashed changes
