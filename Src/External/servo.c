#include "servo.h"

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

// Tek bir motoru başlatır
void Servo_Init(ServoMotor_t motor) {
    switch (motor) {
        case MOTOR_1: HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1); break;
        case MOTOR_2: HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2); break;
        case MOTOR_3: HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3); break;
        case MOTOR_4: HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4); break;
        case MOTOR_5: HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1); break;
        case MOTOR_6: HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2); break;
        case MOTOR_7: HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3); break;
        case MOTOR_8: HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4); break;
        default: break;
    }
}

// Servo konumunu ayarlar
void Servo_Write(ServoMotor_t motor, uint16_t pulse_width_us) {
    switch (motor) {
        case MOTOR_1: __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, pulse_width_us); break;
        case MOTOR_2: __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, pulse_width_us); break;
        case MOTOR_3: __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, pulse_width_us); break;
        case MOTOR_4: __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, pulse_width_us); break;
        case MOTOR_5: __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, pulse_width_us); break;
        case MOTOR_6: __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, pulse_width_us); break;
        case MOTOR_7: __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, pulse_width_us); break;
        case MOTOR_8: __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, pulse_width_us); break;
        default: break;
    }
}

// Kalibrasyon fonksiyonu
void Servo_Calibrate(ServoMotor_t motor) {
    Servo_Init(motor);           // Motoru başlat
    Servo_Write(motor, 1500);    // Orta pozisyona ayarla
}
