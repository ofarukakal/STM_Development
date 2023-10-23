#include "controller.h"

SystemState current_state = STATE_INIT;

void System_Init(void) {
	uint32_t button_press_time;
	volatile uint16_t adc_value;
	while(1){
		LD3_ON;
		HAL_Delay(100);
		LD6_ON;
	}

	HAL_ADC_Start(&hadc1); // start the adc

}

uint16_t ADC_ReadValue(void) {

	HAL_ADC_PollForConversion(&hadc1, 100); // poll for conversion

	adc_value = HAL_ADC_GetValue(&hadc1); // get the adc value

	HAL_ADC_Stop(&hadc1); // stop adc

	HAL_Delay (500); // wait for 500ms

    return adcValue;
}

void System_Handler(void) {
    switch (current_state) {
        case STATE_INIT:
            if (butona_basılı()) {
                button_press_time++;
                if (button_press_time > 2000 && button_press_time < 4000) {
                    current_state = STATE_OLCUM;
                } else if (button_press_time > 4000) {
                    current_state = STATE_KALIBRASYON;
                }
            } else {
                button_press_time = 0;
            }
            break;

        case STATE_OLCUM:
            adc_value = ADC_ReadValue();
            uint32_t delay_time;
            if (0 <= adc_value < 50) delay_time = 50;
            else if(4000 <= adc_value <= 4096) delay_time = 2000;
            while(1){
                LD3_Toggle;
                HAL_Delay(delay_time);
                LD4_Toggle;
                HAL_Delay(delay_time);
                LD5_Toggle;
    			HAL_Delay(delay_time);
    			LD6_Toggle;
    			HAL_Delay(delay_time);

            }
            olcum_timer += 10;
			if (olcum_timer >= 20000) {
				olcum_timer = 0;
				current_state = STATE_INIT;
			}
            break;

        case STATE_KALIBRASYON:
            adc_value = ADC_ReadValue();
            if (adc_value > 3000) {
                // 2.5V yaklaşık olarak 2048 ADC değerine karşılık gelir.
                current_state = STATE_INIT;
            }
            break;
    }
}
