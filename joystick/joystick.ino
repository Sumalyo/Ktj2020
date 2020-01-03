int pot1x;
int pot1y;
int pot2x;
int pot2y;
void setup() {
Serial.begin(9600);
pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(A2, INPUT);
pinMode(A3, INPUT);
}
void loop() {
pot1x = analogRead(A0);
pot1y = analogRead(A1);
pot2x = analogRead(A2);
pot2y = analogRead(A3);
                      
Serial.print("pot1y = ");
Serial.println(pot1y);
delay(1000);
Serial.print("pot1x = ");
Serial.println(pot1x);
delay(1000);
Serial.print("pot2y = ");
Serial.println(pot2y);
delay(1000);
Serial.print("pot2x = ");
Serial.println(pot2x);
delay(1000);
}
