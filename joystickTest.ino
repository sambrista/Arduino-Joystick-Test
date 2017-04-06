int joy_hor = 0;
int joy_ver = 1;
int pin_up = 6;
int pin_down = 3;
int pin_left = 9;
int pin_right = 5;
int pin_led = 12;
int pin_boton = 7;


int value_up = 0;
int value_down = 0;
int value_left = 0;
int value_right = 0;

int value1 = 0;
int value2 = 0;

void setup() {
  pinMode(pin_led, OUTPUT);
  pinMode(pin_boton, INPUT);
}

void loop() {
 value1 = analogRead(joy_hor) - 512;
 if (abs(value1) < 50) {
    value_left= value_right = 0; 
 } else if (value1 > 0) {
 value_right = map(value1, 0, 512, 0,255); 
 value_left = 0; 
 } else {
   value1 = abs(value1);
 value_left = map(value1, 0, 512, 0,255); 
 value_right = 0; 
 }
 delay(100);
  value2 = analogRead(joy_ver) - 512;
 if (abs(value2) < 50) {
    value_up = value_down = 0; 
 } else if (value2 > 0) {
 value_up = map(value2, 0, 512, 0,255); 
 value_down = 0; 
 } else {
   value2 = abs(value2);
 value_down = map(value2, 0, 512, 0,255); 
 value_up = 0; 
 }
 analogWrite(pin_up, value_up); 
 analogWrite(pin_down, value_down); 
 analogWrite(pin_left, value_left); 
 analogWrite(pin_right, value_right);
 digitalWrite(pin_led,digitalRead(pin_boton));
}
