
int buzzer=12;

void setup() {
  // put your setup code here, to run once:

  pinMode(buzzer,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

      
      
    for(int i=1500;i>0;i--)
    {
      
      digitalWrite(buzzer,HIGH);
      delayMicroseconds(i);
      digitalWrite(buzzer,LOW);
      delayMicroseconds(i);   
    }
  delay(2000);
 
}
