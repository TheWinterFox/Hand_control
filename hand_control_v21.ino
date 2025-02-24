/*ARM CONTROL FOR MK-3 IRON MAN SUIT
*
*
CREATED BY WINTER_FOX & SAMURAI
*
*
program version: V.0.2
*
*/




#include <Servo.h>

//variables
const int flex = A0;
const int press = A1;
int data_1 = 0;
int data_2 = 0;
const int pul = 5;

Servo servo_1;
Servo servo_2;
Servo servo_3;

bool state = 0;
  
void setup()
{
  Serial.begin(9600);
  
  servo_1.attach(2);
  servo_2.attach(3);
  servo_3.attach(4);
  
  pinMode(pul, INPUT_PULLUP);
  
}

void loop()
{
  sensor_reading();
  misille_launch_control();
  shield();
  lock();
 
}


/*-------reading sensor----------
*
default values for "misille launch control" and "shield expand and 
retract control" were setted up using our personal values(hand grip and 
force apply to the press sensor) and may not work
corretcly in other devices. We recommend you to
calibrate sensors using the serial monitor, uncommenting the
lines "calibration" and setting your new values where is indicated.
*
*/

void sensor_reading(){
  //---flex sensor---
  data_1 = analogRead(flex);
  //Serial.print("flex sensor: "); //**calibration**
  //Serial.println(data_1); //**calibration**
  delay(100);
  
  //----force sensor-----
  data_2 = analogRead(press);
  //Serial.print("press sensor: "); //**calibration**
  //Serial.println(data_2); //**calibration**
  delay(100);
  }

//-----misille control-------

void misille_launch_control(){
  if(data_1<120){  //**calibrate this value**
    servo_1.write(90);
    servo_2.write(90);
  }
  else{
    servo_1.write(0);
    servo_2.write(0);
  }
 }

//--------shield expand and retract control---------

 void shield(){
  if(data_2>795){ //**calibrate this value**
    servo_3.write(180);
  }
  else{
    servo_3.write(0);
  }
 }

/*-------lock & unlock sistem-----------
*
*
This allows you to move your hand freely without activating 
any of the arm features
*
*/

void lock(){
  if(digitalRead(pul)==LOW){
    delay(100);
    
    //anti-bounce
    while(digitalRead(pul)==LOW){
    }
    state=!state;
    
    //shows state
    if(state==0){
       Serial.println("state: unlocked");
    }
    else{
       Serial.println("state: locked");
       
    }
         
    
  }
  
  if(state==0){
   
  }
  else{
    servo_1.write(0);
    servo_2.write(0);
    servo_3.write(0);
    
  }
    
 }