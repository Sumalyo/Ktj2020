//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//create an RF24 object
RF24 radio(9,10); // CE, CSN
//address through which two modules communicate.
const byte address[6] = "00001";
int pin1=4;
int pin2=6;
int pin3=7;
int pin4=8;
void setup()
{
  int i;
  for(i=3;i<8;i++)
  pinMode(i,OUTPUT);

  
  while (!Serial);
    Serial.begin(9600);
 
  radio.begin();
 
  //set the address
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
 
  //Set module as receiver
  radio.startListening();
}
void loop()
{
  //Read the data if available in buffer
  if (radio.available())
  {
    int text[4] = {0,0,0,0};
    radio.read(&text, sizeof(text));
    //Serial.println(text[2]);
    if(text[0]>125&&text[0]<134)
    {text[0]=0;}else{text[0]=129-text[0];}
    if(text[1]>130&&text[1]<138)
    {text[1]=0;}else{text[1]=135-text[1];}
    if(text[2]>120&&text[2U]<130)
    {text[2]=0;}else{text[2]=124-text[2];}
    if(text[3]>125&&text[3]<134)
    {text[3]=0;}else{text[3]=128-text[3];}
    int direc = -1;
    if(text[2]>0)
    {direc=2;}
    if(text[2]<0)
    {direc=3;}
    if(text[0]>0)
    {direc=0;}
   if(text[0]<0)
   {direc=1;}

   //Serial.println(text[2]);
   if(direc==1)
   {Serial.println("UP");forward();}
    if(direc==0)
   {Serial.println("BACK");revr();}
    if(direc==2)
   {Serial.println("RIGHT");right();}
    if(direc==3)
   {Serial.println("LEFT");left();}
    if(direc==-1)
   {Serial.println("NA");stopp();}
   
    
    
    

    
  }
}

void stopp()
{
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,LOW);
 // analogWrite(3,0);analogWrite(5,0);
}

void forward()
{
  digitalWrite(pin4,HIGH);
  digitalWrite(pin3,LOW);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin1,LOW);
  //analogWrite(3,180);analogWrite(5,220);
}
void revr()
{
  digitalWrite(pin4,LOW);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin2,LOW);
  digitalWrite(pin1,HIGH);
  //analogWrite(3,180);analogWrite(5,180);
}
void left()
{
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,LOW);
  //analogWrite(3,220);analogWrite(5,0);
}
void right()
{
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,LOW);
  //analogWrite(3,0);analogWrite(5,220);
}
