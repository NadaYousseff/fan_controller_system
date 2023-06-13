/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Nada Youssef
 *
 *******************************************************************************/
#include "adc.h"

#include <avr/io.h>
#include "common_macros.h"
#include "avr/io.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr){
	/*Configure the reference volt*/
	ADMUX = (ADMUX & 0x3f) | ((Config_Ptr->ref_volt)<<6);

	/*Enable the ADC*/
	SET_BIT(ADCSRA,ADEN);

	/*Configure the ADC Clock */
	ADCSRA = (ADCSRA & 0xf8) | (Config_Ptr->prescaler);

}

uint16 ADC_readChannel(uint8 channel_num)
{
	/* configure the ADC channel */
	ADMUX =(ADMUX & 0xE0) |(channel_num & 0x07);
	/* Start conversion write '1' to ADSC */
	SET_BIT(ADCSRA,ADSC);
	/* Wait for the ADC to complete the conversion */
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	/* Clear the ADC flag */
	SET_BIT(ADCSRA,ADIF);
	/* Return the digital value from the data register */
	return ADC;

}

