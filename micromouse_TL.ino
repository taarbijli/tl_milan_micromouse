int motor_lA = 11;
int motor_lB = 12;
int motor_enableA = 9;

int motor_rA = 4;
int motor_rB = 5;
int motor_enableB = 10;

int trigger_front = 7;
int echo_front = 6;

int trigger_left = A0;
int echo_left = A1;

int trigger_right = A2;
int echo_right = A3;
int d1 = 7;
int d2 = 10;


void setup() {
  pinMode(motor_lA,OUTPUT);
  pinMode(motor_lB,OUTPUT);
  pinMode(motor_enableA, OUTPUT);

  pinMode(motor_rA,OUTPUT);
  pinMode(motor_rB,OUTPUT);
  pinMode(motor_enableB, OUTPUT);

  pinMode(trigger_front,OUTPUT);
  pinMode(echo_front,INPUT);

  pinMode(trigger_left,OUTPUT);
  pinMode(echo_left,INPUT);

  pinMode(trigger_right,OUTPUT);
  pinMode(echo_right,INPUT);
  
  analogWrite(motor_enableA, 80);
  analogWrite(motor_enableB, 88);

}

void loop() {
  Serial.begin(9600);
  long duration_front, distance_front, duration_left, distance_left, duration_right, distance_right;

  digitalWrite(trigger_front, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_front, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_front, LOW);
  duration_front = pulseIn(echo_front, HIGH);
  distance_front= duration_front*0.034/2;

  digitalWrite(trigger_left, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_left, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_left, LOW);
  duration_left = pulseIn(echo_left, HIGH);
  distance_left= duration_left*0.034/2;

  digitalWrite(trigger_right, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_right, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_right, LOW);
  duration_right = pulseIn(echo_right, HIGH);
  distance_right= duration_right*0.034/2;

  Serial.print("front = ");
  Serial.println(distance_front);
  Serial.print("Left = ");
  Serial.println(distance_left);
  Serial.print("Right = ");
  Serial.println(distance_right);  
  delay(50);

  if (distance_right > d2){
    right();
  //  Stop();
  }
 
  else if (distance_right < d2){
    if (distance_front > d1){
      forward();
      Stop();
    }
    else if (distance_front < d1){
      left();
      Stop();
    }
  }
}
void forward()
{
  digitalWrite(motor_lA,1);
  digitalWrite(motor_lB,0);
  digitalWrite(motor_rA,1);
  digitalWrite(motor_rB,0);
  delay(500);
}


void right(){
  digitalWrite(motor_lA,1);
  digitalWrite(motor_lB,0);
  digitalWrite(motor_rA,0);
  digitalWrite(motor_rB,1);
 delay(750);
}


void left(){
  digitalWrite(motor_lA,0);
  digitalWrite(motor_lB,1);
  digitalWrite(motor_rA,1);
  digitalWrite(motor_rB,0);
  delay(750);
}



void Stop(){
  digitalWrite(motor_lA,0);
  digitalWrite(motor_lB,0);
  digitalWrite(motor_rA,0);
  digitalWrite(motor_rB,0);
  delay(300);
}


  
  
    

   
