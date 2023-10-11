/*!
 *  @file RobotClass_Slider.cpp
 *  QIIC Slider joystick library
 *  Written by Oleg Evsegneev for RobotClass (2023).
 *  e-mail: oleg.evsegneev@gmail.com
 */
#include "RobotClass_Slider.h"

RobotClass_Slider::RobotClass_Slider(){
}

void RobotClass_Slider::begin(uint8_t addr, TwoWire *wire){
	_wire = wire;
	_addr = addr;
	
	_wire->begin();
}

uint8_t RobotClass_Slider::getXY(uint16_t *x, uint16_t *y) {
	uint8_t data[4];
	uint8_t result = read_bytes(_addr, REGISTER_GET_SENSOR, data, 4);

    *x = data[0] | (data[1]<<8);
    *y = data[2] | (data[3]<<8);

	return result;
}

uint8_t RobotClass_Slider::i2c_error() {
	return _status;
}

int8_t RobotClass_Slider::read_bytes(const uint8_t dev, const uint8_t reg, uint8_t* data, const uint8_t size) {
	_wire->beginTransmission(dev);
	_wire->write(reg);
	_wire->endTransmission();
	_wire->requestFrom(dev, size);
	int8_t count = 0;
	while (_wire->available()) data[count++] = _wire->read();
	return count;
}

bool RobotClass_Slider::write_bytes(const uint8_t dev, const uint8_t reg, const uint8_t* data, const uint8_t size) {
	_wire->beginTransmission(dev);
	_wire->write(reg);
	for (uint8_t i = 0; i < size; i++) _wire->write(data[i]);
	_status = _wire->endTransmission();
	return (_status == 0);
}
