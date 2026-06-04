#ifndef ELECCIONPAP_H //pregunto si esta declarado
#define ELECCIONPAP_H //la defino
//incluyo los recursos
#include "stm32f103xb.h"
#include "ctype.h"
#include "stdbool.h"

void MotorPaP_init(int IN0, int IN1, int IN2, int IN3);
void MotorPaP(int IN0, int IN1, int IN2, int IN3, char tipoPaso, int pasos);

#endif