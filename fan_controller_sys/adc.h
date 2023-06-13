/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Nada Youssef
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum{
	AREF,AVCC,INTERNAL=3
}ADC_ReferenceVolatge;

typedef enum{
	F_CPU_1,F_CPU_2,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;


typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description : Function to initialize the ADC
 * 	1. Set the required Reference volt.
 * 	2. Set the required ADC Clock.
 * 	3. Enable the ADC.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function to read data from a specific ADC channel
 * and convert it to digital using the ADC.
 * input: the ADC channel number.
 * output: the digital data converted by ADC.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
