int d = 2;
int led = 13;
int r = 3;


void setup() {
  pinMode(led, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Serial.begin(9600);
}

void loop() {
  r = digitalRead(3);
  d = digitalRead(2);
  if(d == LOW){
    delay(500);
    digitalWrite(led, HIGH);
    Serial.println('a');
    Serial.println("MOVEMENT");
    digitalWrite(led, LOW);
    d = HIGH;
  }
  else if (r == LOW){
    delay(500);
    digitalWrite(led, HIGH);
    Serial.println('r');
    digitalWrite(led, LOW);
    r = HIGH;    
  }
}
