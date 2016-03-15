   #include <SoftwareSerial.h>
 
int bluetoothTx = 2; // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 3; // RX-I pin of bluetooth mate, Arduino D3
 
int led = 12;
int buzzer=11;
int state=0;
int flag=0;


 static int frequenc = 255;
 
int dataFromBt;
 
boolean lightBlink = false;

  
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
 
void setup()
{
 bluetooth.begin(115200); // The Bluetooth Mate defaults to 115200bps
 delay(100); // Short delay, wait for the Mate to send back CMD
 bluetooth.begin(9600); // Start bluetooth serial at 9600


 
 pinMode(buzzer,OUTPUT);
pinMode(led, OUTPUT);
digitalWrite(led,HIGH);

Serial.begin(9600); // Begin the serial monitor at 9600bps
 

}
 
void loop()
{
 
 if(bluetooth.available()) // If the bluetooth sent any characters
 {
 // Send any characters the bluetooth prints to the serial monitor
 //Serial.println((char)bluetooth.read());
 
 dataFromBt = bluetooth.read();
 
 if(dataFromBt == '0'){
 Serial.println("led on");
 digitalWrite(led, HIGH);
 
 }
 if(dataFromBt == '1'){
 Serial.println("led off");
 digitalWrite(led, LOW);

 }

 if(dataFromBt == 'a'){
 Serial.println("buzzer off");
 tone(buzzer,0,1000);
 //digitalWrite(buzzer, 255);
 
 }
 
 if(dataFromBt == 'b'){
 Serial.println("buzzer on");
 tone(buzzer,1255);
 //digitalWrite(buzzer, 255);
 delay(1);
 }
 
  if(dataFromBt == 'c'){
 Serial.println("buzzer on");
 tone(buzzer,2255);
 //digitalWrite(buzzer, 1000);
 delay(1);
 }
 
 if(dataFromBt == 'd')
 {
    
    tone(buzzer, frequenc);
    frequenc += 1000;


 }

 if(dataFromBt == 'e')
 {
    
    tone(buzzer, frequenc);
    frequenc -= 1000;


 }
 }
 
 if(Serial.available()) // If stuff was typed in the serial monitor
 {
 // Send any characters the Serial monitor prints to the bluetooth
 bluetooth.print((char)Serial.read());
 }

   
 }
 
