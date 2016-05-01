#define TRIGGER_PIN  11  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     9  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define V_CC 5
#define MOTOR_PIN 8

int OMG_GONNA_HIT = 0;

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(MOTOR_PIN, OUTPUT);
  
  digitalWrite(TRIGGER_PIN, LOW);
  digitalWrite(MOTOR_PIN, LOW);
}

void loop() {

//  digitalWrite(MOTOR_PIN, HIGH);
  if(!OMG_GONNA_HIT) {
    digitalWrite(TRIGGER_PIN, HIGH);
    digitalWrite(MOTOR_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);
    
    long duration = pulseIn(ECHO_PIN, HIGH);
    Serial.print("duration = ");
    Serial.println(duration);
    long distance = duration * 0.000001 * (34000 / 2);
    Serial.print("distance = ");
    Serial.println(distance);
    if(distance < 25) {
      OMG_GONNA_HIT = 1;
      digitalWrite(MOTOR_PIN, LOW);
    }
  } else {

    Serial.println("OMG!");
  }
  delay(500);
}
