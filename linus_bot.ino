#include <AFMotor.h>
AF_DCMotor motor_left(1);
AF_DCMotor motor_right(3);

int sensor1 =0 ;
int sensor2 = 0;
int sensor3 = 0;
int sensor4 = 0;
int sensor5 = 0;
  int adj_1 =0;
  int adj_2=0;
  int adj_3=0;
  int adj_4=0;
  int adj_5 = 0;


int s1_min = 200;
int s1_max = 950;
 int s2_min = 200;
 int s2_max=950;
int s3_min= 200;
int s3_max = 950;
int s4_min= 200;
int s4_max =950;
int s5_min= 200;
int s5_max=950;

int lower_threshold =20;

int threshold =128 ;

int upper_threshold =230 ;


int speed_value = 255;


void setup() {

Serial.begin(9600);
motor_left.setSpeed(255);
motor_left.run(RELEASE);

motor.right.setSpeed(255);
motor_right.run(RELEASE);

  // put your setup code here, to run once:

}


void update_sensors(){

sensor1=analogRead(0);
adj_1 = map(sensor1, s1_min , s1_max , 0, 255);
adj_1 = constrain(adj_1,0,255);

sensor2 = analogRead(1);
adj_2 = map(sensor2,s2_min,s2_max,0,255);
adj_2 = constrain(adj_2,0,255);


sensor3= analogRead(2):
adj_3 =map(sensor3, s3_min , s3_max , 0 ,255);
adj = constrain(adj_3 ,0,255);

sensor4= analogRead(3);
adj_4= map(sensor4,s4_min,s4_max,0,255);
adj_4 = constrain(adj_4 , 0 ,255);


sensor5 = aanalogRead(4);
adj_5= map(sensor5,s5_min,s5_max,0,255);
adj_5 = constrain (adj_5 , 0 ,255);
 
}

void loop() {

update_sensors();
if(adj_3<lower_threshold){
if ( adj_2>threshold && adj_4 >threshold){
motor_left.run(FORWARD);
motor_left.setSpeed(speed_value);
}
 // you want the bot to stop when it reaches the black box.
 else if (adj_1 < 1){
 if (adj_2 < 1){
 if (adj_3 < 1){
 if (adj_4 < 1){
 if (adj_5 < 1){

 // if all sensors are reading black, stop Linus.
 motor_left.run(RELEASE);
 motor_right.run(RELEASE);
 }
 }
 }
 }
 }
 }
// otherwise, the center sensor is above the threshold
// so we need to check what sensor i

154
 else {
 // first check sensors 1
 if (adj_1 < upper_threshold && adj_5 > upper_threshold){
 motor_left.run(RELEASE);
 motor_left.setSpeed(0);
 motor_right.run(FORWARD);
 motor_right.setSpeed(speed_value);
 }
 // then check sensor 5
 else if (adj_1 > upper_threshold && adj_5 < upper_threshold){
 motor_left.run(FORWARD);
 motor_left.setSpeed(speed_value);
 motor_right.run(RELEASE);
 motor_right.setSpeed(0);
 }

 // if not sensor 1 or 5, then check sensor 2
 else if (adj_2 < upper_threshold && adj_4 > upper_threshold){
 motor_left.run(RELEASE);
 motor_left.setSpeed(0);
 motor_right.run(FORWARD);
 motor_right.setSpeed(speed_value);
 }
 // if not sensor 2, then check sensor 4
 else if (adj_2 > upper_threshold && adj_4 < upper_threshold){
 motor_left.run(FORWARD);
 motor_left.setSpeed(speed_value);
 motor_right.run(RELEASE);
 motor_right.setSpeed(0);
 }
 }
 ///// Print values for each sensor
 /////sensor 1 values
 Serial.print("sensor 1: ");
 Serial.print(sensor1);
 Serial.print(" - ");
 Serial.print("Adj 1: ");
 Serial.print(adj_1);
 Serial.print(" - ");
www.it-ebooks.info
CHAPTER 4  LINUS THE LINE-BOT
155
 /////sensor 2 values
 Serial.print("sensor 2: ");
 Serial.print(sensor2);
 Serial.print(" - ");
 Serial.print("Adj 2: ");
 Serial.print(adj_2);
 Serial.print(" - ");
 /////sensor 3 values
 Serial.print("sensor 3: ");
 Serial.print(sensor3);
 Serial.print(" - ");
 Serial.print("Adj 3: ");
 Serial.print(adj_3);
 Serial.print(" - ");
 /////sensor 4 values
 Serial.print("sensor 4: ");
 Serial.print(sensor4);
 Serial.print(" - ");
 Serial.print("Adj 4: ");
 Serial.print(adj_4);
 Serial.print(" - ");
 /////sensor 5 values
 Serial.print("sensor 5: ");
 Serial.print(sensor5);
 Serial.print(" - ");
 Serial.print("Adj 5: ");
 Serial.print(adj_5);
 Serial.print(" ");
 Serial.print("speed: ");
 Serial.print(speed_pot);
 Serial.println(" "); 



  
}

  
}


  
  // put your main code here, to run repeatedly:

}
