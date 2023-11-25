#include "IRremote.h"
#include "ESP32Servo.h";

int IR_RECEIVE_PIN = 12;
int SERVO_PIN = 25;
int TARGET_RAW_DATA = 0xFC03EF00;

int servo_left = 120;
int servo_right = 180;

Servo servoMotor;

void setup() {
  Serial.begin(115200);
  pinMode(SERVO_PIN, OUTPUT);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK, SERVO_PIN);
  servoMotor.attach(SERVO_PIN);
}

void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.printIRResultShort(&Serial);

    if (IrReceiver.decodedIRData.decodedRawData == 0xFC03EF00) {
      Serial.printf("hello");
      servoMotor.write(servo_left);
      delay(1000);
      servoMotor.write(servo_right);
    }
    IrReceiver.resume();
  }
  delay(100);
}