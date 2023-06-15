int in1=8,in2=9,in3=10,in4=12; 
const byte trig_left=2,trig_right=4,trig_forward=6;
const byte echo_left=3,echo_right=5,echo_forward=7;
int speed=11;
const unsigned long MEASURE_TIMEOUT = 25000UL;
const float SOUND_SPEED = 340.0 / 1000;
void setup() {
  Serial.begin(115200);
  analogWrite(speed,100);
  pinMode(trig_left, OUTPUT);
  pinMode(trig_right, OUTPUT);
  pinMode(trig_forward, OUTPUT);
  digitalWrite(trig_left, LOW);
  digitalWrite(trig_forward, LOW);
  digitalWrite(trig_right, LOW);
  pinMode(echo_left, INPUT);
  pinMode(echo_right, INPUT);
  pinMode(echo_forward, INPUT);
  for(int i=8;i<13;i++){
     pinMode(i, OUTPUT);
  }
}

//////////////////////////////////////////////
void loop() {
float dist_forward=distance_forward();
float dist_right=distance_right();
float dist_left=distance_left();
Serial.println(dist_left);  
Serial.println(dist_forward);
Serial.println(dist_right);
Serial.println("/////////");
if((dist_forward<20)){
  if(dist_right<5&&dist_left<5){
      backward();
      delay(1000);
      turn_right();}
  else if(dist_right>=5&&dist_left<5)
      turn_right();
  else if(dist_right<5&&dist_left>=5)
      turn_left();
  else{
    turn_right();
  }
}
else{
  forward();
}
                                                   
}
//////////////////////////////////////////////
void turn_left(){
Serial.println("left");
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
delay(1000);
///
digitalWrite(in1,LOW);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,LOW);
}
void turn_right(){
Serial.println("right");
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);
delay(1000);
///
digitalWrite(in1,LOW);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,LOW);
}
void forward(){
Serial.println("forward");
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH);
}
void backward(){
Serial.println("backward");
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
}
////////////////////////////////////////////
float distance_left(){
  digitalWrite(trig_left, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_left, LOW);
  long measure_left = pulseIn(echo_left, HIGH, MEASURE_TIMEOUT);
  float distance_left = measure_left / 2.0 * SOUND_SPEED;
  // Serial.print(F("Distance_left: "));
  // Serial.print(distance_left / 10.0, 2);
  // Serial.print(F("cm, "));
  delay(500);
  return distance_left/10.0;
}

float distance_right(){
  digitalWrite(trig_right, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_right, LOW);
  long measure_right = pulseIn(echo_right, HIGH, MEASURE_TIMEOUT);
  float distance_right = measure_right / 2.0 * SOUND_SPEED;
  // Serial.print(F("Distance_right: "));
  // Serial.print(distance_right / 10.0, 2);
  // Serial.print(F("cm, "));
  delay(500);
  return distance_right/10.0;
}

float distance_forward(){
  digitalWrite(trig_forward, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_forward, LOW);
  long measure_forward = pulseIn(echo_forward, HIGH, MEASURE_TIMEOUT);
  float distance_forward = measure_forward / 2.0 * SOUND_SPEED;
  // Serial.print(F("Distance_forward: "));
  // Serial.print(distance_forward / 10.0, 2);
  // Serial.print(F("cm, "));
  delay(500);
  return distance_forward/10.0;
}