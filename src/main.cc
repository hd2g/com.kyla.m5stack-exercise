/** M5Stack Fireで使うIMUを定義する(らしい)
 */
#define M5Stack_MPU6886

#include <M5Stack.h>

const laptop_cover<m5stack_fire::device> laptop_cover;

void setup() {
  M5.begin();
  M5.Power.begin();

  M5.IMU.Init();

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE, BLACK);
  M5.Lcd.setTextSize(2);

  laptop_cover.attached_device.begin();

  laptop_cover.events.on_open([](coodinate_axis& axis) {
    laptop_cover.attached_device.display.info << axis;
    const auto sent_json = timerecorder::stamp(
      work::in,
      get_current_datetime()
    );
    laptop_cover.attached_device.display.info << sent_json;
  });

  laptop_cover.attached_device.events.on_close([](coodinate_axis& axis) {
    laptop_cover.attached_device.display.info << axis;
    const auto sent_json = timerecorder::stamp(
      work::out,
      get_current_datetime()
    );
    laptop_cover.attached_device.display.info << sent_json;
  });
}

void loop() {
  laptop_cover.events.join();
  delay(1);
}
