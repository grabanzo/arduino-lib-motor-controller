#include <Arduino.h>

#include "MotorController.h"
#include "L298N.h"


MotorController::MotorController(MotorControllerConfig motor_config) : enabled(false) {
    this->configure(motor_config);
}

void MotorController::configure(MotorControllerConfig motor_config) {
    this->motor_config = motor_config;
    this->front.configure(
        this->motor_config.pin_IN1_Front,
        this->motor_config.pin_IN2_Front,
        this->motor_config.pin_IN3_Front,
        this->motor_config.pin_IN4_Front,
        this->motor_config.pin_ENA_Front,
        this->motor_config.pin_ENB_Front
    );
    this->rear.configure(
        this->motor_config.pin_IN1_Rear,
        this->motor_config.pin_IN2_Rear,
        this->motor_config.pin_IN3_Rear,
        this->motor_config.pin_IN4_Rear,
        this->motor_config.pin_ENA_Rear,
        this->motor_config.pin_ENB_Rear
    );
    // Cambiar frecuencia pwm pin ENA_Front, ENB_Front, ENA_Rear, ENB_Rear
}

void MotorController::forward(int speed) {
    this->front.forwardA(speed);
    this->front.forwardB(speed);
    this->rear.forwardA(speed);
    this->rear.forwardB(speed);
}

void MotorController::backward(int speed) {
    this->front.backwardA(speed);
    this->front.backwardB(speed);
    this->rear.backwardA(speed);
    this->rear.backwardB(speed);
}

void MotorController::left(int speed) {
    this->front.backwardA(speed);
    this->front.forwardB(speed);
    this->rear.backwardA(speed);
    this->rear.forwardA(speed);
}

void MotorController::right(int speed) {
    this->front.forwardA(speed);
    this->front.backwardA(speed);
    this->rear.backwardA(speed);
    this->rear.forwardA(speed);    
}

void MotorController::forwardLeft(int speed) {
    this->front.stopA();
    this->front.forwardB(speed);
    this->rear.stopA();
    this->rear.forwardB(speed);
}

void MotorController::forwardRight(int speed) {
    this->front.forwardA(speed);
    this->front.stopB();
    this->rear.forwardA(speed);
    this->rear.stopB();
}

void MotorController::backwardLeft(int speed) {
    this->front.backwardA(speed);
    this->front.stopB();
    this->rear.backwardA(speed);
    this->rear.stopB();
}

void MotorController::backwardRight(int speed) {
    this->front.stopA();
    this->front.backwardA(speed);
    this->rear.stopA();
    this->rear.backwardB(speed);
}

void MotorController::brake() {
    this->front.stopA();
    this->front.stopB();
    this->rear.stopA();
    this->rear.stopB();
}