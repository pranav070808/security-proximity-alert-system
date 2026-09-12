const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

const int LED_PIN = 7;
const int BUZZER_PIN = 8;

// Change this value to configure the alert threshold.
const int ALERT_DISTANCE_CM = 50;

long readDistanceCm() {
  // Send a 10-microsecond trigger pulse.
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the echo pulse.
  // Timeout prevents the program from waiting forever.
  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    return -1;  // No valid echo received.
  }

  // HC-SR04 distance conversion:
  // distance in cm = echo time in microseconds / 58
  return duration / 58;
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(TRIG_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
  noTone(BUZZER_PIN);

  Serial.begin(9600);

  Serial.println("================================");
  Serial.println(" SECURITY PROXIMITY ALERT SYSTEM");
  Serial.println("================================");
  Serial.print("Alert threshold: ");
  Serial.print(ALERT_DISTANCE_CM);
  Serial.println(" cm");
}

void loop() {
  long distance = readDistanceCm();

  if (distance < 0) {
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);

    Serial.println("Distance: No valid reading");
  }
  else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm");

    if (distance <= ALERT_DISTANCE_CM) {
      digitalWrite(LED_PIN, HIGH);
      tone(BUZZER_PIN, 1000);

      Serial.println("  -> ALERT: Object detected!");
    }
    else {
      digitalWrite(LED_PIN, LOW);
      noTone(BUZZER_PIN);

      Serial.println("  -> SAFE");
    }
  }

  delay(200);
}
