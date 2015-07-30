/* This is test code for the Si7021 on the Sensor1 R2a platform
29 July 2015
*/

#include <Wire.h>
 
const int ADDR =0x40;
int X0,X1,Y0,Y1,Y2,Y3;
double X,Y,X_out,Y_out1,Y_out2;

int t1=0;
 
void setup()
{ 
  Serial.begin(9600);   
  Wire.begin();                                   
  delay(100);  
  Wire.beginTransmission(ADDR);
  Wire.endTransmission();
  pinMode(13,OUTPUT);  


// test I/O
   pinMode(7,OUTPUT);      // led0
   pinMode(6,OUTPUT);      // led1
   pinMode(3,OUTPUT);      // led2
   pinMode(4,OUTPUT);      // led3
   
   pinMode(A1,OUTPUT);     // Relay 1
   pinMode(A2,OUTPUT);     // Relay 2
      

  
}
void loop()
{
  /**Send command of initiating temperature measurement**/
  Wire.beginTransmission(ADDR);
  Wire.write(0xE3);
  Wire.endTransmission();
 
  Serial.print("Temp");
  Serial.print("\t");
  Serial.println("RH");
 
  /**Read data of temperature**/
  digitalWrite(13,HIGH);  
  Wire.requestFrom(ADDR,2);
 
  if(Wire.available()<=2);
  {
    X0 = Wire.read();
    X1 = Wire.read();
    X0 = X0<<8;
    X_out = X0+X1;
  }
 
  /**Calculate and display temperature**/
  X=(175.72*X_out)/65536;                        
  X=X-46.85;
  Serial.print(X);
  Serial.print("C");
  Serial.print("\t");
 
  /**Send command of initiating relative humidity measurement**/
  Wire.beginTransmission(ADDR);                     
  Wire.write(0xE5);
  Wire.endTransmission(); 
 
  /**Read data of relative humidity**/
  Wire.requestFrom(ADDR,2);
  if(Wire.available()<=2);
  {
    Y0 = Wire.read();
    Y2=Y0/100; 
    Y0=Y0%100;
    Y1 = Wire.read();
    Y_out1 = Y2*25600;
    Y_out2 = Y0*256+Y1;
  }
 
  /**Calculate and display relative humidity**/
  Y_out1 = (125*Y_out1)/65536;                     
  Y_out2 = (125*Y_out2)/65536;
  Y = Y_out1+Y_out2;
  Y=Y-6;
  Serial.print(Y);
  Serial.println("%");
 
  digitalWrite(13,LOW);                           
  delay(500);
  
  digitalWrite(7, t1);   // sets the LED1 on
  digitalWrite(6, t1);   // sets the LED2 on
  digitalWrite(3, t1);   // sets the LED3 on
  digitalWrite(4, t1);   // sets the LED4 on
  
  // digitalWrite(A1, t1);   // sets the Relay 1 on
  // digitalWrite(A2, t1);   // sets the Relay 2 on
  
   t1 = !t1;              // toggle state of LED's and Relays
  
}