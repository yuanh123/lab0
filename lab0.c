// ******************************************************************************************* //
//
// File:         lab0.c
// Date:         
// Authors:      
//
// Description:  Lab 0 assignment for ECE 372 Spring 2015.
// ******************************************************************************************* //

#include "p24fj64ga002.h"
#include "initLab0.h"
#include <stdio.h>

// ******************************************************************************************* //
// Configuration bits for CONFIG1 settings.
//
// These settings are appropriate for debugging the PIC microcontroller. If you need to
// program the PIC for standalone operation, change the COE_ON option to COE_OFF.

_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF &
          BKBUG_ON & COE_ON & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )



typedef enum stateTypeEnum{
    led4, led4wait, led5, led5wait, led6, led6wait, led7, led7wait
} stateType;

volatile stateType curState;
volatile int i=0;
int main(void)
{

    //TODO: Finish these functions in the provided c files
    initLEDs();
    initTimer1();
    initSW1();
    curState = led4;
    while(1)
    {
        switch(curState)
        {
                case led4:
                turnOnLED(4);
                break;
                case led4wait:
                   turnOnLED(41); 
                break;
                case led5:
                   turnOnLED(5); 
                break;
                case led5wait:
                   turnOnLED(51);
                break;
                case led6:
                   turnOnLED(6);
                break;
                case led6wait:
                   turnOnLED(61);
                break;
                case led7:
                   turnOnLED(7);
                break;
                case led7wait:
                   turnOnLED(71);
                break;
        }
        if(PORTBbits.RB5 == PRESSED )
        {
        if(curState==led4)curState=led4wait;
        else if(curState==led5)curState=led5wait;
        else if(curState==led6)curState=led6wait;
        else if(curState==led7)curState=led7wait;
        else if(curState==led4wait)curState=led4wait;
        else if(curState==led5wait)curState=led5wait;
        else if(curState==led6wait)curState=led6wait;
        else if(curState==led7wait)curState=led7wait;
        }
        else if(i>=50 && PORTBbits.RB5 == RELEASED)
        {
        if(curState==led4wait)curState=led7;
        else if(curState==led5wait)curState=led4;
        else if(curState==led6wait)curState=led5;
        else if(curState==led7wait)curState=led6;
         }
        else if(i<50 && PORTBbits.RB5 == RELEASED)
        {
         if (curState==led4wait)curState=led5;
        else if(curState==led5wait)curState=led6;
        else if(curState==led6wait)curState=led7;
        else if(curState==led7wait)curState=led4;
        
        }
        }
    
    return 0;
}

void _ISR _T1Interrupt(){
    //TODO: Put down the timer 1 flag first!
    IFS0bits.T1IF = 0;
    if(PORTBbits.RB5 == PRESSED)i=i+1;
    if(PORTBbits.RB5 == RELEASED)i=0;
}
