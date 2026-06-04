#include "eleccionpap.h" 
#include "motorpap.h" //incluimos el motorpap para usar sus funciones

void MotorPaP_init(int IN0, int IN1, int IN2, int IN3){
    int pines[4]={IN0,IN1,IN2,IN3};
    RCC->APB2ENR|=RCC_APB2ENR_IOPAEN;
    for(int i=0; i<4; i++){
        if(pines[i]<8){
            GPIOA->CRL&=~(0xf<<(pines[i]*4));
            GPIOA->CRL|=(0X1<<(pines[i]*4));
        }
        else{
            GPIOA->CRH&=~(0xf<<((pines[i]%8)*4));
            GPIOA->CRH|=(0X1<<((pines[i]%8)*4));
        }
    }
}

void MotorPaP(int IN0, int IN1, int IN2, int IN3, char tipoPaso, int pasos){
    if(tipoPaso=='N') pasoNormal(IN0, IN1, IN2, IN3, pasos);
    else if(tipoPaso=='C') pasoCompleto(IN0, IN1, IN2, IN3, pasos);
    else if(tipoPaso=='M') pasoMedio(IN0, IN1, IN2, IN3, pasos);
}
    