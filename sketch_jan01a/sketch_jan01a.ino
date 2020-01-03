int pin1=4;
int pin2=6;
int pin3=7;
int pin4=8;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  String state;
  if(Serial.available()>0)
  {
    int direc=-1;
    char command;
    
    command=Serial.read();
    Serial.println(command);
    //state=Serial.readString();
    //Serial.println(state[0]);
    
    if(command=='F')
    direc=1;
    if(command=='G')
    direc=0;
    if(command=='L')
    direc=2;
    if(command=='R')
    direc=3;
    if(command=='S')
    direc=-1;

    
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
   
    
    delay(100);
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
  //delay(100);
  //analogWrite(3,180);analogWrite(5,220);
}
void revr()
{
  digitalWrite(pin4,LOW);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin2,LOW);
  digitalWrite(pin1,HIGH);
  //delay(100);
  //analogWrite(3,180);analogWrite(5,180);
}
void left()
{
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,LOW);
  //delay(100);
  //analogWrite(3,220);analogWrite(5,0);
}
void right()
{
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,LOW);
  //delay(100);
  //analogWrite(3,0);analogWrite(5,220);
}
