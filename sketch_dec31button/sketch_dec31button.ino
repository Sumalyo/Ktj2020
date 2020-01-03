void setup() {
  int i;
  Serial.begin(9600);
  for (i=2;i<=5;i++)
  pinMode(i,INPUT);
  //Serial.begin(9600);
  

}

void loop() {
  int i;
  for (i=2;i<=5;i++)
  digitalWrite(i,HIGH);
  int data=0;
  for(i=2;i<=5;i++)
  {if(digitalRead(i)==LOW)
  data++;
  }
 // if(Serial.available())
    Serial.println(data);
    delay(10);
}
