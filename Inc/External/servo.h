#ifndef __SERVO_H
#define __SERVO_H

#include "stm32f1xx_hal.h"

// Motor numaraları
typedef enum {
    MOTOR_1 = 1,
    MOTOR_2,
    MOTOR_3,
    MOTOR_4,
    MOTOR_5,
    MOTOR_6,
    MOTOR_7,
    MOTOR_8
} ServoMotor_t;

// Fonksiyonlar
void Servo_Init(ServoMotor_t motor);              // Tek motoru başlat
void Servo_Write(ServoMotor_t motor, uint16_t pulse_width_us); // Konum ayarla
void Servo_Calibrate(ServoMotor_t motor);        // Kalibre et (orta pozisyon)

#endif
