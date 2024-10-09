#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include "L298N.h"

struct MotorControllerConfig {
    uint8_t pin_IN1_Front;
    uint8_t pin_IN2_Front;
    uint8_t pin_IN3_Front;
    uint8_t pin_IN4_Front;
    uint8_t pin_ENA_Front;
    uint8_t pin_ENB_Front;
    uint8_t pin_IN1_Rear;
    uint8_t pin_IN2_Rear;
    uint8_t pin_IN3_Rear;
    uint8_t pin_IN4_Rear;
    uint8_t pin_ENA_Rear;
    uint8_t pin_ENB_Rear;
};

class MotorController {
public:
    MotorController() : enabled(false) {};
    MotorController(MotorControllerConfig motor_config);
    void configure(MotorControllerConfig motor_config);
    void brake();
    void forward(int speed);
    void backward(int speed);
    void left(int speed);
    void right(int speed);
    void forwardLeft(int speed);
    void forwardRight(int speed);
    void backwardLeft(int speed);
    void backwardRight(int speed);
    void setSpeed(int speed) {};
    void setEnabled() { this->enabled = true; this->front.setEnabled(); this->rear.setEnabled();};
    void setDisabled() { this->enabled = false; this->front.setDisabled(); this->rear.setDisabled();};
    bool isEnabled() { return enabled; }
private:
    MotorControllerConfig motor_config;
    L298N front;
    L298N rear;
    bool enabled;
};

#endif // MOTORCONTROLLER_H