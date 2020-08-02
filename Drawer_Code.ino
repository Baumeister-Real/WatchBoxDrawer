 //Declare pin functions on RedBoard
#define stp 2
#define dir 3
#define MS1 4
#define MS2 5
#define EN 6
#define CT 8

void setup() {
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(EN, OUTPUT);
  digitalWrite(EN, HIGH);
  pinMode(CT, INPUT);
  resetEDPins();
  Serial.begin(9600);
}

void loop(){
  digitalWrite(dir, LOW);
  digitalWrite(MS1, HIGH);
  digitalWrite(MS2, HIGH);
  while(digitalRead(CT) == LOW){
    digitalWrite(stp, HIGH);
    delay(1);
    digitalWrite(stp, LOW);
    delay(1);
  }
}

//Reset Easy Driver pins to default states
void resetEDPins()
{
  digitalWrite(stp, LOW);
  digitalWrite(dir, LOW);
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  digitalWrite(EN, HIGH);
}
