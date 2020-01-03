

//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int pot1x;
int pot1y;
int pot2x;
int pot2y;
//create an RF24 object
RF24 radio(9, 10);  // CE, CSN
//address through which two modules communicate.
const byte address[6] = "00001";
void setup()
{
  radio.begin();
 
  //set the address
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  int i;
  for (i=2;i<=5;i++)
  pinMode(i,INPUT);
  //Serial.begin(9600);
}
void loop()
{
   int i;
  for (i=2;i<=5;i++)
  digitalWrite(i,HIGH);
  int data[4]={127,132,127,127};
pot1x = digitalRead(3);
pot1y = digitalRead(4);
pot2x = digitalRead(5);
pot2y = digitalRead(2);
if(!(pot1x))
data[0]=0;
if(!(pot1y))
data[0]=255;
if(!(pot2x))
data[2]=0;
if(!(pot2y))
data[2]=255;
  radio.write(&data, sizeof(data));
 
  delay(1000);
}
