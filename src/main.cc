// M5Stack Fireで使うIMUを定義する(らしい)
#include "laptop_cover.hh"
#define M5Stack_MPU6886

#include <M5Stack.h>

void setup() {
  M5.begin();
  M5.Power.begin();

  M5.IMU.Init();

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE, BLACK);
  M5.Lcd.setTextSize(2);
}

void loop() {
}
