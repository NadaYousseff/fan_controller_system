/******************************************************************************
 *
 * Module: Fan Controller System
 *
 * File Name: Fan_controller.c
 *
 * Description: Source file for the Fan Controller System
 *
 * Author: Nada Youssef
 *
 *******************************************************************************/
#include <avr/io.h>

#include "adc.h"
#include "dc_motor.h"
#include "lm35_sensor.h"
#include "lcd.h"
#include "std_types.h"


int main (void){
	uint8 temperature;    /* variable to hold the temperature value read from the sensor */
	ADC_ConfigType Config;     /* structure of type ADC_ConfigType to hold the required properties of ADC */
	ADC_ConfigType * Config_Ptr = &Config;
	/* configure the required properties of the ADC */
	DcMotor_State state = Clock_Wise;
	Config_Ptr->ref_volt = INTERNAL;
	Config_Ptr->prescaler = F_CPU_8;

	ADC_init(Config_Ptr);        /* Initialize the ADC */
	DcMotor_Init();              /* Initialize the DC Motor */
	LCD_init();                  /* Initialize the LCD */

	LCD_displayStringRowColumn(0,0,"Fan is ");
	LCD_displayStringRowColumn(1,0,"Temperature=");


	while(1){
		/* Read the temperature value from the sensor */
		temperature=LM35_getTemperature();
		if(temperature < 30){
			/* turn off the DC Motor */
			DcMotor_Rotate( state,0);
			LCD_displayStringRowColumn(0,7,"OFF");
			LCD_moveCursor(1,12);
			LCD_intgerToString(temperature);
			if(temperature<100){
				LCD_displayStringRowColumn(1,14," ");
			}

		}
		else if(temperature >= 30 && temperature < 60){
			/* turn on the DC Motor at speed 25% */
			DcMotor_Rotate( state,25);
			LCD_displayStringRowColumn(0,7,"ON ");
			LCD_moveCursor(1,12);
			LCD_intgerToString(temperature);
			if(temperature<100){
				LCD_displayStringRowColumn(1,14," ");
			}

		}
		else if(temperature >= 60 && temperature < 90){
			/* turn on the DC Motor at speed 50% */
			DcMotor_Rotate( state,50);
			LCD_displayStringRowColumn(0,7,"ON ");
			LCD_moveCursor(1,12);
			LCD_intgerToString(temperature);
			if(temperature<100){
				LCD_displayStringRowColumn(1,14," ");
			}


		}
		else if(temperature >= 90 && temperature < 120){
			/* turn on the DC Motor at speed 75% */
			DcMotor_Rotate( state,75);
			LCD_displayStringRowColumn(0,7,"ON ");
			LCD_moveCursor(1,12);
			LCD_intgerToString(temperature);
			if(temperature<100){
				LCD_displayStringRowColumn(1,14," ");
			}


		}
		else{
			/* turn on the DC Motor at speed 100% */
			DcMotor_Rotate( state,100);
			LCD_displayStringRowColumn(0,7,"ON ");
			LCD_moveCursor(1,12);
			LCD_intgerToString(temperature);

		}

	}
}
