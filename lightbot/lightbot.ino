#define LM 9 //Left motor pin
#define RM 10 //Right motor pin
#define LS A4 //Left photoresistor pin
#define RS A5 //Right photoresistor pin

#define variance 0 //Amount of varience between photoresistors required to activate turning

void setup() {
  pinMode(LM, OUTPUT);
  pinMode(RM, OUTPUT);
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  Serial.begin(9600);
}

void loop() {
  int left = analogRead(LS);
  int right = analogRead(RS);
  Serial.print(left);
  Serial.print("    ");
  Serial.println(right);
  
  
  if (abs(left - right) < variance){
    digitalWrite(LM, HIGH);
    digitalWrite(RM, HIGH);
    Serial.println("equal");
  }
  else if (left > right) {
    digitalWrite(RM, HIGH);
    digitalWrite(LM, LOW);
    Serial.println("left > right");
  }
  else if (right > left) {
    digitalWrite(LM, HIGH);
    digitalWrite(RM, LOW);
    Serial.println("right < left");
  }
  else {
    digitalWrite(LM, LOW);
    digitalWrite(RM, LOW);
    Serial.println("???");
  }
}
