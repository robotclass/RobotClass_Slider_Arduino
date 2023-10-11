#include <RobotClass_Slider.h>

RobotClass_Slider slider;
MbedI2C i2c(2,3);

uint16_t x,y;

void setup() {
    Serial.begin(9600);
    delay(2000);

    i2c.begin();

    slider.begin(0x20, &i2c);
}

void loop() {
    uint8_t cc = slider.getXY(&x, &y); 
    Serial.print("count=");
    Serial.print(cc);
    Serial.print("x=");
    Serial.print(x);
    Serial.print(", y=");
    Serial.println(y);
    delay(100);
}
