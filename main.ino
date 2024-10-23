#include <PS2X_lib.h>  //for v1.6
#include <Servo.h>

#define m1a 6
#define m1b 5
#define velmotor 3

Servo myservo;
PS2X ps2x;

bool turbo = true;
int vel = 0;
int error = 0; 
byte type = 0;
byte vibrate = 0;

void setup(){
 Serial.begin(57600);

 pinMode(velmotor, OUTPUT);
 pinMode(m1b, OUTPUT);
 pinMode(m1a, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(8, OUTPUT);

{ 
  myservo.attach(A5);
} 
  
 error = ps2x.config_gamepad(13,11,10,12, true, true);
 
 if(error == 0){
   Serial.println("Found Controller, configured successful");
 }
   
  else if(error == 1)
   Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");
   
  else if(error == 2)
   Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");
   
  else if(error == 3)
   Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
   
   //Serial.print(ps2x.Analog(1), HEX);
   
   type = ps2x.readType(); 
     switch(type) {
       case 0:
        Serial.println("Unknown Controller type");
       break;
       case 1:
        Serial.println("DualShock Controller Found");
       break;
       case 2:
         Serial.println("GuitarHero Controller Found");
       break;
     }
  
}

void loop(){
 if(error == 1)
  return; 


  ps2x.read_gamepad(false, vibrate);
  
  if(ps2x.Button(PSB_START))
       Serial.println("Start");
  if(ps2x.Button(PSB_SELECT))
       Serial.println("Select");
       
       
   if(ps2x.Button(PSB_PAD_UP)) {
     Serial.println("Up");
    }
    if(ps2x.Button(PSB_PAD_RIGHT)){
     Serial.println("Right");
//        Serial.println(ps2x.Analog(PSAB_PAD_RIGHT), DEC);
     myservo.write(165);
     delay(2); 
    }
    if(ps2x.Button(PSB_PAD_LEFT)){
     Serial.println("LEFT held this hard");
//        Serial.println(ps2x.Analog(PSAB_PAD_LEFT), DEC);
     myservo.write(35);
     delay(2); 
    }
    if(ps2x.Button(PSB_PAD_DOWN)){
     Serial.println("DOWN held this hard");
//     Serial.println(ps2x.Analog(PSAB_PAD_DOWN), DEC);
     myservo.write(100);
     delay(2); 
    }   

  
    vibrate = ps2x.Analog(PSAB_BLUE);        
                                                
  
  if (ps2x.NewButtonState())
  {
      if(ps2x.Button(PSB_L3))
       Serial.println("L3 pressed");
      if(ps2x.Button(PSB_R3))
       Serial.println("R3 pressed");
      if(ps2x.Button(PSB_L2))
       Serial.println("L2 pressed");
      if(ps2x.Button(PSB_R2))
       Serial.println("R2 pressed");
      if(ps2x.Button(PSB_GREEN))
       Serial.println("Triangle pressed");
  }   
       
  if(ps2x.Button(PSB_RED)){
       Serial.println("Circle just pressed");
       tone(8,466,50000);
       delay(250);
       noTone(8);
  }
  if(ps2x.ButtonReleased(PSB_PINK)){ 
       Serial.println("Square just released");
       if(turbo){ 
         analogWrite(velmotor, 255);
         digitalWrite(m1a, HIGH);
         digitalWrite(m1b, LOW);
         delay(5);
         turbo = !turbo;
         Serial.println("LIGADO"); 
       } else { 
         analogWrite(velmotor, 255);
         digitalWrite(m1a, LOW);
         digitalWrite(m1b, LOW);
         delay(5);
         turbo = !turbo;
         Serial.println("DESLIGADO");
       }
  }
  if(ps2x.NewButtonState(PSB_BLUE)){
       Serial.println("X just changed");    
  }
  if(ps2x.Button(PSB_L1) || ps2x.Button(PSB_R1))
  {
      Serial.print(" Values:");
      Serial.print(ps2x.Analog(PSS_LY), DEC); 
      Serial.print(",");
      Serial.print(ps2x.Analog(PSS_LX), DEC); 
      Serial.print(",");
      Serial.print(ps2x.Analog(PSS_RY), DEC); 
      Serial.print(",");
      Serial.println(ps2x.Analog(PSS_RX), DEC); 
      Serial.print(ps2x.Analog(PSS_RY));
      
      if(ps2x.Analog(PSS_RY) < 126 && ps2x.Analog(PSS_RY) > 80) {
       analogWrite(velmotor, 100);
       digitalWrite(m1a, HIGH);
       digitalWrite(m1b, LOW);
       delay(10);
       Serial.print("VELOCIDADE 1+");
      }
      if(ps2x.Analog(PSS_RY) < 80 && ps2x.Analog(PSS_RY) > 20) {
       analogWrite(velmotor, 160);
       digitalWrite(m1a, HIGH);
       digitalWrite(m1b, LOW);
       delay(10);
       Serial.print("VELOCIDADE 2+");
      }
      if(ps2x.Analog(PSS_RY) < 20) {
       analogWrite(velmotor, 210);
       digitalWrite(m1a, HIGH);
       digitalWrite(m1b, LOW);
       delay(10);
       Serial.print("VELOCIDADE 3+");
      }
      if(ps2x.Analog(PSS_RY) < 128 && ps2x.Analog(PSS_RY) > 126){
       digitalWrite(m1a, LOW);
       digitalWrite(m1b, LOW);
      }
      if(ps2x.Analog(PSS_RY) > 128 && ps2x.Analog(PSS_RY) < 180) {
       analogWrite(velmotor, 100);
       digitalWrite(m1a, LOW);
       digitalWrite(m1b, HIGH);
       delay(10);
       Serial.print("VELOCIDADE 1-");
      }
      if(ps2x.Analog(PSS_RY) > 180 && ps2x.Analog(PSS_RY) < 240) {
       analogWrite(velmotor, 160);
       digitalWrite(m1a, LOW);
       digitalWrite(m1b, HIGH);
       delay(10);
       Serial.print("VELOCIDADE 2-");
      }
      if(ps2x.Analog(PSS_RY) > 240) {
       analogWrite(velmotor, 210);
       digitalWrite(m1a, LOW);
       digitalWrite(m1b, HIGH);
       delay(10);
       Serial.print("VELOCIDADE 3-");
      }
  } 
 delay(30);    
}
