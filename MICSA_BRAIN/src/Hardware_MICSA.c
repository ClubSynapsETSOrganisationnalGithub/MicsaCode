/************************************************************
*  File Name : Hardware_MICSA_c
*  Description: 
*
*  Author : 
*  Date:    CURRENT_DATE-CURRENT_MONTH-CURRENT_YEAR  //DAY/MONTH/YEAR
************************************************************/

/////////////////////////////////////////////////////////////
//  INCLUDES
/////////////////////////////////////////////////////////////
#include "stdlib.h"
#include "stdio.h"
#include "stdarg.h"
#include "unistd.h"
#include "stdint.h"
#include "string.h"
#include "time.h"
#include "assert.h"
#include "ctype.h"
#include "math.h"
#include "Hardware_MICSA.h"
#include "components/driver/include/driver/gpio.h"

/////////////////////////////////////////////////////////////
//  VARIABLES & TYPES DECLARATIONS
/////////////////////////////////////////////////////////////

// Hardware memory variables are store here 
gpio_config_t ESP32_S2_PIN_1;
gpio_config_t ESP32_S2_PIN_2;
gpio_config_t ESP32_S2_PIN_3;
gpio_config_t ESP32_S2_PIN_4;
gpio_config_t ESP32_S2_PIN_5;
gpio_config_t ESP32_S2_PIN_6;
gpio_config_t ESP32_S2_PIN_7;
gpio_config_t ESP32_S2_PIN_8;
gpio_config_t ESP32_S2_PIN_9;
gpio_config_t ESP32_S2_PIN_10;
gpio_config_t ESP32_S2_PIN_11;
gpio_config_t ESP32_S2_PIN_12;


/////////////////////////////////////////////////////////////
//  FUNCTION PROTOTYPES
/////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////
//  FUNCTION DECLARATION
/////////////////////////////////////////////////////////////

int hardware _config(void){

    Driver_GPIO_MISCA_create_instante();
    // pin
}