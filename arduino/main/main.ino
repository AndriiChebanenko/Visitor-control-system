/* Sensor 1 - outer side of entrance
   Sensor 2 - inner sensor of the entrance
*/

#define LED_PIN 2
#define SENSOR_1_PIN 5
#define SENSOR_2_PIN 8
#define TRACK_VISITORS_PRIORITY 1

typedef enum {COUNTER, ALARM} workmode;

int enters_counter;
int exits_counter;
TaskHandle_t track_visitors_handle;

void track_visitors(void* p_Parameters);

void setup() {
  pinMode(SENSOR_1_PIN, INPUT);
  pinMode(SENSOR_2_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  xTaskCreate(track_visitors, "Track visitors", 256, NULL, TRACK_VISITORS_PRIORITY, &track_visitors_handle);
}

void blink_led(void) {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);    
}

// the loop function runs over and over again forever
void loop() {
  workmode wmode = COUNTER;
  enters_counter = 0;
  exits_counter = 0;
  switch (wmode) {
    case COUNTER:
      break;
    case ALARM:
      break;
  }
}

void track_visitors(void* p_Parameters) {
  (void)p_Parameters;
  uint8_t sensor_1_read = LOW;
  uint8_t sensor_2_read = LOW;

  for (;;) {
    sensor_1_read = digitalRead(SENSOR_1_PIN);
    sensor_2_read = digitalRead(SENSOR_2_PIN);
    if (sensor_1_read == HIGH && sensor_2_read == LOW) {
      enters_counter++;
      delay(500);
    }
    if (sensor_1_read == LOW && sensor_2_read == HIGH) {
      exits_counter++;
      delay(500);
    }
  }
}
