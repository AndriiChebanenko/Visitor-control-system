#define LED_PIN 2
#define SENSOR_1_PIN 5
#define SENSOR_2_PIN 8

typedef enum {COUNTER, ALARM} workmode;

int enters_counter;
int exits_counter;

void setup() {
  pinMode(SENSOR_1_PIN, INPUT);
  pinMode(SENSOR_2_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
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