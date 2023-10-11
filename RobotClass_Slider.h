/*!
 *  @file RobotClass_Slider.h
 *  QIIC Slider joystick library
 *  Written by Oleg Evsegneev for RobotClass (2023).
 *  e-mail: oleg.evsegneev@gmail.com
 */
 
#include <Arduino.h>
#include <Wire.h>

#define BASE_I2C_ADDR 0x20

#define REGISTER_GET_SENSOR 0xBA

class RobotClass_Slider {
	uint16_t axis[2] = {0,0};

	TwoWire* _wire = NULL;
	uint8_t _addr = BASE_I2C_ADDR;

	uint8_t _status = 0x00;

public:
	RobotClass_Slider();
	void begin(uint8_t addr = BASE_I2C_ADDR, TwoWire *wire = &Wire);
	uint8_t getXY(uint16_t *x, uint16_t *y);
	uint8_t i2c_error();

private:
    int8_t read_bytes(const uint8_t dev, const uint8_t reg, uint8_t* data, const uint8_t size);
    bool write_bytes(const uint8_t dev, const uint8_t reg, const uint8_t* data, const uint8_t size);
};
