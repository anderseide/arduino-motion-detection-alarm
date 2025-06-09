// Define pins that will be used
#define MOTION_SENSOR_PIN 2
#define ALARM_RESET_PIN 7
#define BUZZER_PIN 8
#define LED_RED_PIN 9
#define LED_GREEN_PIN 10
#define LED_BLUE_PIN 11

// Set some global variables to be used later on
int motion_detected = 0;
int alarm_state = 0;
int alarm_reset_button_state = 0;

void setup() {

  // Used to get serial output so we can understand 
  //what's going on
  Serial.begin(115200);

  // Set Pin port mode.
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(ALARM_RESET_PIN, INPUT);
  pinMode(MOTION_SENSOR_PIN, INPUT);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_BLUE_PIN, OUTPUT);

  // Make sure that the LED pins are turned off
  analogWrite(LED_RED_PIN, 0);
  analogWrite(LED_GREEN_PIN, 0);
  analogWrite(LED_BLUE_PIN, 0);

}

void loop() {
  
  // Get Motion Sensor state
  motion_detected = digitalRead(MOTION_SENSOR_PIN);
  Serial.print("Sensor val: ");
  Serial.println(motion_detected);

  // If motion is detected, trigger alarm
  if (motion_detected == HIGH) {
    alarm_state = 1;
  }

  Serial.print("Alarm state: ");
  Serial.println(alarm_state);

  // If alarm state is on, trigger alarms
  if (alarm_state == 1) {

    for (int i = 0; i < 100; i++) {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(1);
      digitalWrite(BUZZER_PIN, LOW);
      delay(1);
    }

    analogWrite(LED_RED_PIN, 255);
    delay(200);
    analogWrite(LED_RED_PIN, 0);
    delay(200);

    for (int i = 0; i < 100; i++) {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(1);
      digitalWrite(BUZZER_PIN, LOW);
      delay(1);
    }

    analogWrite(LED_GREEN_PIN, 255);
    delay(200);
    analogWrite(LED_GREEN_PIN, 0);
    delay(200);

    for (int i = 0; i < 100; i++) {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(1);
      digitalWrite(BUZZER_PIN, LOW);
      delay(1);
    }

    analogWrite(LED_BLUE_PIN, 255);
    delay(200);
    analogWrite(LED_BLUE_PIN, 0);
    delay(200);
  }
  

  // Reset alarm
  alarm_reset_button_state = digitalRead(ALARM_RESET_PIN);
  Serial.print("Alarm reset: ");
  Serial.println(alarm_reset_button_state);
  if (alarm_reset_button_state == 1) {
    alarm_state = 0;
  }

  // Just a small delay to avoid the loop to run to often
  if (alarm_state == 0) {
    delay(200);
  }
}

