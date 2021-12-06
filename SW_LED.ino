#define SW1 digitalRead(9)
#define SW2 digitalRead(10)
#define BUZZER(x) digitalWrite(12, x)

void setup() {
  Serial.begin(9600);
  
  pinMode(2, OUTPUT);         // led1
  pinMode(3, OUTPUT);         // led2
  pinMode(4, OUTPUT);         // led3
  pinMode(5, OUTPUT);         // led4
  pinMode(6, OUTPUT);         // led5
  pinMode(7, OUTPUT);         // led6

  pinMode(12, OUTPUT);        // BUZZER
  
  pinMode(9, INPUT_PULLUP);   // SW1
  pinMode(10, INPUT_PULLUP);  // SW2
}

int led_control = 2;  // 2...7


void BUZ(int n, int c) {
  for (int i = 0; i < n; i++) {
    BUZZER(1);
    delay(c);
    BUZZER(0);
  }
}

void SW_Control(int *t) {
  if (SW1==0 ) {
    while(SW1==0) {}
    BUZ(1, 100);
    if (*t < 7)
      *t += 1;
    else
      BUZ(1,100);
  }
  if (SW2==0) {
    while(SW2==0) {}
    BUZ(1, 100);
    if (*t > 2)
      *t -= 1;
    else
      BUZ(1,100);
  }
}

void loop() {
  SW_Control(&led_control); 
  
  digitalWrite(2, led_control == 2);
  digitalWrite(3, led_control == 3);
  digitalWrite(4, led_control == 4);
  digitalWrite(5, led_control == 5);
  digitalWrite(6, led_control == 6);
  digitalWrite(7, led_control == 7);
}
