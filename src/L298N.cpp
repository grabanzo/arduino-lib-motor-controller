#include <Arduino.h>

#include "L298N.h"


L298N::L298N(uint8_t pin_IN1, uint8_t pin_IN2, uint8_t pin_IN3, uint8_t pin_IN4, uint8_t pin_ENA, uint8_t pin_ENB) {
    this->enabled = false;
    this->configure(pin_IN1, pin_IN2, pin_IN3, pin_IN4, pin_ENA, pin_ENB);
}

void L298N::configure(uint8_t pin_IN1, uint8_t pin_IN2, uint8_t pin_IN3, uint8_t pin_IN4, uint8_t pin_ENA, uint8_t pin_ENB) {
    this->pin_ENA = pin_ENA;
    this->pin_ENB = pin_ENB;
    this->pin_IN1 = pin_IN1;
    this->pin_IN2 = pin_IN2;
    this->pin_IN3 = pin_IN3;
    this->pin_IN4 = pin_IN4;

    pinMode(this->pin_ENA, OUTPUT);
    pinMode(this->pin_ENB, OUTPUT);
    pinMode(this->pin_IN1, OUTPUT);
    pinMode(this->pin_IN2, OUTPUT);
    pinMode(this->pin_IN3, OUTPUT);
    pinMode(this->pin_IN4, OUTPUT);
}

void L298N::forwardA(int speed) {
    digitalWrite(this->pin_IN1, HIGH);
    digitalWrite(this->pin_IN2, LOW);

    analogWrite(this->pin_ENA, speed);
}

void L298N::forwardB(int speed) {
    digitalWrite(this->pin_IN3, HIGH);
    digitalWrite(this->pin_IN4, LOW);

    analogWrite(this->pin_ENB, speed);
}

void L298N::backwardA(int speed) {
    digitalWrite(this->pin_IN1, LOW);
    digitalWrite(this->pin_IN2, HIGH);

    analogWrite(this->pin_ENA, speed);
}

void L298N::backwardB(int speed) {
    digitalWrite(this->pin_IN3, LOW);
    digitalWrite(this->pin_IN4, HIGH);

    analogWrite(this->pin_ENB, speed);
}

void L298N::stopA() {
    digitalWrite(this->pin_IN1, LOW);
    digitalWrite(this->pin_IN2, LOW);

    analogWrite(this->pin_ENA, 255);
}

void L298N::stopB() {
    digitalWrite(this->pin_IN3, LOW);
    digitalWrite(this->pin_IN4, LOW);

    analogWrite(this->pin_ENB, 255);
}

void L298N::speedA(int speed) {
    if(this->enabled)
        analogWrite(this->pin_ENA, speed);
    else
        analogWrite(this->pin_ENA, 255);
}

void L298N::speedB(int speed) {
    if(this->enabled)
        analogWrite(this->pin_ENB, speed);
    else
        analogWrite(this->pin_ENB, 255);
}
