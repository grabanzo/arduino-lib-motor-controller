#ifndef L298N_H
#define L298N_H

#include <Arduino.h>


class L298N {
public:
    L298N(): enabled(false) {}
    L298N(uint8_t pin_IN1, uint8_t pin_IN2, uint8_t pin_IN3, uint8_t pin_IN4, uint8_t pin_ENA, uint8_t pin_ENB);

    void configure(uint8_t pin_IN1, uint8_t pin_IN2, uint8_t pin_IN3, uint8_t pin_IN4, uint8_t pin_ENA, uint8_t pin_ENB);
    void forwardA(int speed);
    void forwardB(int speed);
    void backwardA(int speed);
    void backwardB(int speed);
    void stopA();
    void stopB();
    void speedA(int speed);
    void speedB(int speed);
    void setEnabled() { this->enabled = true; };
    void setDisabled() { this->enabled = false; this->stopA(); this->stopB(); };

private:
    uint8_t pin_IN1;
    uint8_t pin_IN2;
    uint8_t pin_IN3;
    uint8_t pin_IN4;
    uint8_t pin_ENA;
    uint8_t pin_ENB;
    bool enabled;
};

#endif // L298N_H