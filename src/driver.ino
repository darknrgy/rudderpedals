#include "Joystick.h" // ArduinoJoystickLibrary
Joystick_ Joystick;

void setup() {
  Serial.begin(9600);
 
  Joystick.setXAxisRange(0, 512);
  Joystick.setYAxisRange(0, 512);
  Joystick.setZAxisRange(-512, 512);
  Joystick.begin(false);
}

void loop() {
	rightBrake();
	leftBrake();
	yaw();
	Joystick.sendState();
	delay(10);

}

float rightBrake() {
	float top = 483;
	float bottom = 323;
	float expoV = 2;

	int sensorValue = analogRead(A1);

	/*Serial.print(sensorValue);
	Serial.print("\t");*/

	float value = normalizeOne(sensorValue, top, bottom);

	value = expo(value, expoV);
	value *= 512;
	value = limit(value, 512, 0);

	Joystick.setXAxis((int) value);
}

float leftBrake() {
	float top = 492;
	float bottom = 300;
	float expoV = 3;

	int sensorValue = analogRead(A2);

	/*Serial.print(sensorValue);
	Serial.print("\t");*/

	float value = normalizeOne(sensorValue, top, bottom);

	value = expo(value, expoV);
	value *= 512;

	value = limit(value, 512, 0);

	Joystick.setYAxis((int) value);
}

int yaw() {
	float top = 860;
	float bottom = 300;
	float center = 525;
	float expoV = 0.625;

	int sensorValue = analogRead(A3);

/*	Serial.print(sensorValue);
	Serial.print("\n");*/

	float value = normalize(sensorValue, top, bottom, center);

	value = expo(value, expoV);
	value *= 512; 

	value = limit(value, 512, -512);

	Joystick.setZAxis((int) value);
}

float normalize(float value, float top, float bottom, float center) {
	
	if (value == center) {
		return 0;
	}

	if (value > center) {
		return normalizeOne(value, top, center);
	} else {
		return - (1 - normalizeOne(value, center, bottom));
	}
}

float normalizeOne(float value, float top, float bottom) {
	if (value > top) value = top;
	if (value < bottom) value = bottom;
	value = value - bottom;
	return value / (top - bottom);
}

float expo(float input, float expo) {
	float value = pow(abs(input), expo);
	if (input < 0) value *= -1;
	return value;

}

int limit(int value, int top, int bottom) {
	if (value > top) return top;
	if (value < bottom) return bottom;
	return value;
}
