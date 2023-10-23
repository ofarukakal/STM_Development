#include "main.h"
#include "stdint.h"

#define LD3_ON HAL_GPIO_WritePin(LD3_GPIO_Port,LD3_Pin,GPIO_PIN_SET)
#define LD3_OFF HAL_GPIO_WritePin(LD3_GPIO_Port,LD3_Pin,GPIO_PIN_RESET)
#define LD3_Toggle HAL_GPIO_TogglePin(LD3_GPIO_Port,LD3_Pin)

#define LD4_ON HAL_GPIO_WritePin(LD4_GPIO_Port,LD4_Pin,GPIO_PIN_SET)
#define LD4_OFF HAL_GPIO_WritePin(LD4_GPIO_Port,LD4_Pin,GPIO_PIN_RESET)
#define LD4_Toggle HAL_GPIO_TogglePin(LD4_GPIO_Port,LD4_Pin)

#define LD5_ON HAL_GPIO_WritePin(LD5_GPIO_Port,LD5_Pin,GPIO_PIN_SET)
#define LD5_OFF HAL_GPIO_WritePin(LD5_GPIO_Port,LD5_Pin,GPIO_PIN_RESET)
#define LD5_Toggle HAL_GPIO_TogglePin(LD5_GPIO_Port,LD5_Pin)


#define LD6_ON HAL_GPIO_WritePin(LD6_GPIO_Port,LD6_Pin,GPIO_PIN_SET)
#define LD6_OFF HAL_GPIO_WritePin(LD6_GPIO_Port,LD6_Pin,GPIO_PIN_RESET)
#define LD6_Toggle HAL_GPIO_TogglePin(LD6_GPIO_Port,LD6_Pin)

#define ReadButton HAL_GPIO_ReadPin(B1_GPIO_Port,B1_Pin)

Controller;
