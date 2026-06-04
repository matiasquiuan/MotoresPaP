#include "motorpap.h"

void pasoNormal_init(int IN0, int IN1, int IN2, int IN3){
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

void pasoNormal(int IN0, int IN1, int IN2, int IN3, int pasos){
    int pines[4]={IN0,IN1,IN2,IN3};
    int est_pasos[4][4]={
        {1,1,0,0},
        {0,1,1,0},
        {0,0,1,1},
        {1,0,0,1}
    };
    for(int i=0;i<pasos;i++){
        for(int j=0;j<4;j++){
            if(est_pasos[i%4][j]) GPIOA->BSRR|=(1<<pines[j]);
            else GPIOA->BSRR|=(1<<(pines[j]+16));
        }
    }
}

void pasoCompleto_init(int IN0, int IN1, int IN2, int IN3){
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

void pasoCompleto(int IN0, int IN1, int IN2, int IN3, int pasos){
    int pines[4]={IN0,IN1,IN2,IN3};
    int est_pasos[4][4]={
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
    };
    for(int i=0;i<pasos;i++){
        for(int j=0;j<4;j++){
            if(est_pasos[i%4][j]) GPIOA->BSRR|=(1<<pines[j]);
            else GPIOA->BSRR|=(1<<(pines[j]+16));
        }
    }
}

void pasoMedio_init(int IN0, int IN1, int IN2, int IN3){
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

void pasoMedio(int IN0, int IN1, int IN2, int IN3, int pasos){
    int pines[4]={IN0,IN1,IN2,IN3};
    int est_pasos[8][4]={
        {1,0,0,0},
        {1,1,0,0},
        {0,1,0,0},
        {0,1,1,0},
        {0,0,1,0},
        {0,0,1,1},
        {0,0,0,1},
        {1,0,0,1},
    };
    for(int i=0;i<pasos;i++){
        for(int j=0;j<4;j++){
            if(est_pasos[i%8][j]) GPIOA->BSRR|=(1<<pines[j]);
            else GPIOA->BSRR|=(1<<(pines[j]+16));
        }
    }
}
