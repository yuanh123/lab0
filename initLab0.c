/*
* File:   initLab0.c
* Author: 
*
* Created on December 27, 2014, 1:31 PM
*/

#include "p24fj64ga002.h"
#include "initLab0.h"

void initLEDs(){
    TRISBbits.TRISB15 = Output;
    TRISBbits.TRISB14 = Output;
    TRISBbits.TRISB13 = Output;
    TRISBbits.TRISB12 = Output;

    LATBbits.LATB15 = OFF;
    LATBbits.LATB14 = OFF;
    LATBbits.LATB13 = OFF;
    LATBbits.LATB12 = OFF;
}

void initSW1(){
    TRISBbits.TRISB5 = Input;
}


void initTimer1(){
    PR1= ((0.02*FCY)/PRS)-1;
    T1CONbits.TCKPS=0b11;
    IEC0bits.T1IE=1;
    IFS0bits.T1IF=0;
   T1CONbits.TON=1;
}

void turnOnLED (int led){
    if(led == 4)
    {
    LATBbits.LATB15 = ON;
    LATBbits.LATB14 = OFF;
    LATBbits.LATB13 = OFF;
    LATBbits.LATB12 = OFF;
    }
    else if(led == 41)
    {
    LATBbits.LATB15 = ON;
    LATBbits.LATB14 = OFF;
    LATBbits.LATB13 = OFF;
    LATBbits.LATB12 = OFF;
    }
     else if(led == 5)
    {
    LATBbits.LATB15 = OFF;
    LATBbits.LATB14 = ON;
    LATBbits.LATB13 = OFF;
    LATBbits.LATB12 = OFF;
    }
     else if(led == 51)
    {
    LATBbits.LATB15 = OFF;
    LATBbits.LATB14 = ON;
    LATBbits.LATB13 = OFF;
    LATBbits.LATB12 = OFF;
    }
     else if(led == 6)
    {
    LATBbits.LATB15 = OFF;
    LATBbits.LATB14 = OFF;
    LATBbits.LATB13 = ON;
    LATBbits.LATB12 = OFF;
    }
    else if(led == 61)
    {
    LATBbits.LATB15 = OFF;
    LATBbits.LATB14 = OFF;
    LATBbits.LATB13 = ON;
    LATBbits.LATB12 = OFF;
    }
    else if(led == 7)
    {
    LATBbits.LATB15 = OFF;
    LATBbits.LATB14 = OFF;
    LATBbits.LATB13 = OFF;
    LATBbits.LATB12 = ON;
    }
    else if(led == 71)
    {
    LATBbits.LATB15 = OFF;
    LATBbits.LATB14 = OFF;
    LATBbits.LATB13 = OFF;
    LATBbits.LATB12 = ON;
    }
}