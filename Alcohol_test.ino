
#define sensorDigital1 6
#define sensorDigital2 7
#define LED1 3
#define LED2 5
#define buzzer 4
#define sensorAnalog1 A1
#define sensorAnalog2 A2
int old_sum = 150;
 
void setup() {
  pinMode(sensorDigital1, INPUT);
  pinMode(sensorDigital2, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  bool digital1 = digitalRead(sensorDigital1);
  int analog1 = analogRead(sensorAnalog1);
  bool digital2 = digitalRead(sensorDigital2);
  int analog2 = analogRead(sensorAnalog2);
  analog2 = analog2 - 200;
  int sum = 0;
 
//  Serial.print("Analog value : ");
//  Serial.print(analog1);
//  Serial.print(" ");
//  Serial.print(analog2);
//  Serial.print(" ");
//  Serial.print("t");
//  Serial.print("Digital value :");
//  Serial.println(digital1);
//  Serial.println(digital2);
  if(analog1>=100 && analog2>=100) {
    sum = analog1 + analog2;
    sum = sum/2;
  } else if(analog1>=100 && analog2<100) {
    sum = analog1;
  } else if(analog2>=100 && analog1<100) {
    sum = analog2;
  } 
  

  if(sum<100) {
    if(old_sum<100) {
        old_sum = sum;
      } else {
          Serial.println("Oodha sona urira");
          Serial.println(sum);
     digitalWrite(LED1,HIGH);
     delay(1000);
     digitalWrite(LED1,LOW);
     delay(100); 
     
     old_sum = sum;
      }
  }

    if(sum>=100 && sum<200)
  {
      //analogWrite(9,255);
      if(old_sum>=100 && old_sum<200) {
        old_sum = sum;
      } else {
          Serial.println("You are sober.");
          Serial.println(sum);
     digitalWrite(LED1,HIGH);
     delay(1000);
     digitalWrite(LED1,LOW);
     delay(100); 
     old_sum = sum;
      }
  }
  if (sum>=200 && sum< 400)
  {    
    if(old_sum>=200 && old_sum<400) {
        old_sum = sum;
      } else {
          digitalWrite(LED2,HIGH);
      delay(1000);
      digitalWrite(LED2,LOW);
      delay(100); 
      Serial.println("You are sober");
      Serial.println(sum);
      old_sum = sum;
      }
      
  }
  if(sum>400)
  { 
    if(old_sum>400) {
        old_sum = sum;
      } else {
         digitalWrite(LED1,HIGH);
     delay(1000);
     digitalWrite(LED1,LOW);
     delay(100); 
     Serial.println("This person is drunk!");
     Serial.println(sum);
     old_sum = sum;
      }
     
  }
 }
