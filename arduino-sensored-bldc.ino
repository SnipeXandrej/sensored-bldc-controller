#define hall1 1 //A3 Int3
#define hall2 0 //A2 Int2
#define hall3 2 //A1 Int1
int stepstate;
bool hall1state;
bool hall2state;
bool hall3state;


void ExInt3() {
  hall1state = digitalRead(hall1);
  NextStep();
}

void ExInt2() {
  hall2state = digitalRead(hall2);
  NextStep();
}

void ExInt1() {
  hall3state = digitalRead(hall3);
  NextStep();
}

const int y_motor_lout = 10;
const int y_motor_pwm_hout = 3;
const int b_motor_lout = 4;
const int b_motor_pwm_hout = 5;
const int g_motor_lout = 6;
const int g_motor_pwm_hout = 9;


void NextStep() {
  if ((hall1state == 1) && (hall2state == 0) && (hall3state == 0)) {
    stepstate = 1;
  }
  if ((hall1state == 1) && (hall2state == 0) && (hall3state == 1)) {
    stepstate = 2;
  }
  if ((hall1state == 0) && (hall2state == 0) && (hall3state == 1)) {
    stepstate = 3;
  }
  if ((hall1state == 0) && (hall2state == 1) && (hall3state == 1)) {
    stepstate = 4;
  }
  if ((hall1state == 0) && (hall2state == 1) && (hall3state == 0)) {
    stepstate = 5;
  }
  if ((hall1state == 1) && (hall2state == 1) && (hall3state == 0)) {
    stepstate = 6;
  }
}

void setup()
{
  pinMode(y_motor_lout, OUTPUT);
  pinMode(y_motor_pwm_hout, OUTPUT);
  pinMode(b_motor_lout, OUTPUT);
  pinMode(b_motor_pwm_hout, OUTPUT);
  pinMode(g_motor_lout, OUTPUT);
  pinMode(g_motor_pwm_hout, OUTPUT);

  //half bridge driver, hi part is active high
  // lo part is active low
  digitalWrite(y_motor_pwm_hout, LOW);//set motor to stop
  digitalWrite(b_motor_pwm_hout, LOW);
  digitalWrite(g_motor_pwm_hout, LOW);

  digitalWrite(y_motor_lout, HIGH);
  digitalWrite(b_motor_lout, HIGH);
  digitalWrite(g_motor_lout, HIGH);
  
  attachInterrupt(digitalPinToInterrupt(1), ExInt3, CHANGE);
  attachInterrupt(digitalPinToInterrupt(0), ExInt2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(2), ExInt1, CHANGE);
  
  hall1state = digitalRead(hall1);
  hall2state = digitalRead(hall2);
  hall3state = digitalRead(hall3);
}

void loop() {
    switch (stepstate) {
    case 1:
    digitalWrite(y_motor_pwm_hout, HIGH);
    digitalWrite(b_motor_pwm_hout, LOW);
    digitalWrite(g_motor_pwm_hout, LOW);
    digitalWrite(y_motor_lout, HIGH);
    digitalWrite(b_motor_lout, HIGH);
    digitalWrite(g_motor_lout, LOW);
      break;
    case 2:
    digitalWrite(y_motor_pwm_hout, HIGH);
    digitalWrite(b_motor_pwm_hout, LOW);
    digitalWrite(g_motor_pwm_hout, LOW);
    digitalWrite(y_motor_lout, HIGH);
    digitalWrite(b_motor_lout, LOW);
    digitalWrite(g_motor_lout, HIGH);
      break;
    case 3:
    digitalWrite(y_motor_pwm_hout, LOW);
    digitalWrite(b_motor_pwm_hout, LOW);
    digitalWrite(g_motor_pwm_hout, HIGH);
    digitalWrite(y_motor_lout, HIGH);
    digitalWrite(b_motor_lout, LOW);
    digitalWrite(g_motor_lout, HIGH);
      break;
    case 4:
    digitalWrite(y_motor_pwm_hout, LOW);
    digitalWrite(b_motor_pwm_hout, LOW);
    digitalWrite(g_motor_pwm_hout, HIGH);
    digitalWrite(y_motor_lout, LOW);
    digitalWrite(b_motor_lout, HIGH);
    digitalWrite(g_motor_lout, HIGH);
      break;
    case 5:
    digitalWrite(y_motor_pwm_hout, LOW);
    digitalWrite(b_motor_pwm_hout, HIGH);
    digitalWrite(g_motor_pwm_hout, LOW);
    digitalWrite(y_motor_lout, LOW);
    digitalWrite(b_motor_lout, HIGH);
    digitalWrite(g_motor_lout, HIGH);
      break;
    case 6:
    digitalWrite(y_motor_pwm_hout, LOW);
    digitalWrite(b_motor_pwm_hout, HIGH);
    digitalWrite(g_motor_pwm_hout, LOW);
    digitalWrite(y_motor_lout, HIGH);
    digitalWrite(b_motor_lout, HIGH);
    digitalWrite(g_motor_lout, LOW);
      break;
  }
}
