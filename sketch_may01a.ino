#define TRIGGER_PIN  11  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     9  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define V_CC 5
#define MOTOR_PIN 8
#define BUZZER_PIN 7 

int OMG_GONNA_HIT = 0;

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  digitalWrite(TRIGGER_PIN, LOW);
  digitalWrite(MOTOR_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  delay(5000);
}

void loop() {

  if(!OMG_GONNA_HIT) {
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    digitalWrite(MOTOR_PIN, HIGH);
    
    long duration = pulseIn(ECHO_PIN, HIGH);
    Serial.print("duration = ");
    Serial.println(duration);
    long distance = 1.0 * duration * 0.000001 * (34000 / 2);
    Serial.print("distance = ");
    Serial.println(distance);

    if(duration == 0)
      return;

    if(distance < 10) {
      OMG_GONNA_HIT = 1;
      digitalWrite(MOTOR_PIN, LOW);
      digitalWrite(BUZZER_PIN, HIGH);
      Serial.println("BUZZER start");
      delay(2000);
      Serial.println("BUZZER stop");
      digitalWrite(BUZZER_PIN, LOW);
    }
    else if(distance < 150) {
      delay(600);
      digitalWrite(MOTOR_PIN, LOW);
      digitalWrite(BUZZER_PIN, HIGH);
      Serial.println("BUZZER start");
      delay(500);
      Serial.println("BUZZER stop");
      digitalWrite(BUZZER_PIN, LOW);
    }
    else {
      delay(100);
    }
  } 
}
