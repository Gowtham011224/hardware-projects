int trigPin=7;
int echoPin=8;
int green=4;
int yellow=2;
int red=3;
int buzzer=6;
void setup() {
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(green,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  long duration,cm;
  duration=pulseIn(echoPin,HIGH);
  delayMicroseconds(100);
  cm=(duration/29)/2;
  Serial.println(cm);
  
  if(cm>60){
    noTone(buzzer);
    digitalWrite(green,HIGH);
    digitalWrite(yellow,LOW);
    digitalWrite(red,LOW);
  }
  if(cm<=60 && cm>=30){
    noTone(buzzer);
    if (cm>30 && cm<=45){
      tone(buzzer,5000);
    }
    digitalWrite(yellow,HIGH);
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
  }
  if(cm<30){
    tone(buzzer,1000);
    digitalWrite(red,HIGH);
    digitalWrite(yellow,LOW);
    digitalWrite(green,LOW);
  }
}