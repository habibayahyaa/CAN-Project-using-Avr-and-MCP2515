#include <std_types.h>
#include <Macros.h>
#include <Dio.h>
#include <Pwm.h>

void Timer0_PwmInit(void){

/* Waveform Generation Mode: Fast PWM */
        SET_BIT(TCCR0, TCCR0_WGM00);
        SET_BIT(TCCR0, TCCR0_WGM01);
        /* Clock Select: No Prescaler */
        SET_BIT(TCCR0, TCCR0_CS00);
        CLR_BIT(TCCR0, TCCR0_CS01);
        CLR_BIT(TCCR0, TCCR0_CS02);
        /* Set OC0 Pin as Output */
        Dio_SetPinMode(DIO_PORTB, DIO_PIN3, DIO_PIN_OUTPUT);
        /* Compare Match Output Mode:
         Clear OC0 on compare match, set OC0 at TOP */
        CLR_BIT(TCCR0, TCCR0_COM00);
        SET_BIT(TCCR0, TCCR0_COM01);

}


void Timer2_Pwm_Init(void) {

    /* Waveform Generation Mode: Fast PWM */
    SET_BIT(TCCR2, TCCR2_WGM20);
    SET_BIT(TCCR2, TCCR2_WGM21);

    /* Clock Select: No Prescaler */
    SET_BIT(TCCR2, TCCR2_CS20);
    CLR_BIT(TCCR2, TCCR2_CS21);
    CLR_BIT(TCCR2, TCCR2_CS22);

    /* Set OC2A Pin as Output */
    Dio_SetPinMode(DIO_PORTD, DIO_PIN7, DIO_PIN_OUTPUT);

    /* Compare Match Output Mode:
     * Clear OC2A on compare match, set OC2A at TOP */
    CLR_BIT(TCCR2, TCCR2_COM20);
    SET_BIT(TCCR2, TCCR2_COM21);
}


void Timer1A_Pwm_Init(void)
{
 /* Waveform Generation Mode: Fast PWM, TOP=ICR1 */
        CLR_BIT(TCCR1A, TCCR1A_WGM10);
        SET_BIT(TCCR1A, TCCR1A_WGM11);
        SET_BIT(TCCR1B, TCCR1B_WGM12);
        SET_BIT(TCCR1B, TCCR1B_WGM13);
        /* Clock Select: No Prescaler */
        SET_BIT(TCCR1B, TCCR1B_CS10);
        CLR_BIT(TCCR1B, TCCR1B_CS11);
        CLR_BIT(TCCR1B, TCCR1B_CS12);
            /* Compare Match Output Mode:
            Clear OC1A on compare match, set OC1A at TOP */
            CLR_BIT(TCCR1A, TCCR1A_COM1A0);
            SET_BIT(TCCR1A, TCCR1A_COM1A1);
            /* Set OC1A Pin as Output */
            Dio_SetPinMode(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);
        

}

void Pwm_SetTopValue(u16 value)
{
    ICR1 = value;
}

void Pwm_Timer0SetCompareValue(u16 value){
 OCR0 = value;

}

void Pwm_Timer1ASetCompareValue(u16 value){
   OCR1A = value;

}

void Pwm_Timer2SetCompareValue(u16 value){

 OCR2 = value;
}