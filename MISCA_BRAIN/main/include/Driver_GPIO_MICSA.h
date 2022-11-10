/************************************************************
*  File Name : Driver_GPIO_MICSA.h
*  Description: This module is a Driver implementation for 
*               the GPIO peripheral of the ESP32-S2 and is
*               used to simplify interaction with the material.
*
*  Author : Jacques Veneziano, Philippe Rochefort, Myiah 
			Catwell
*  Date: 2022-11-09
************************************************************/
#ifndef Driver_GPIO_MICSA_H_
#define Driver_GPIO_MICSA_H_


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

/////////////////////////////////////////////////////////////
//  VARIABLES & TYPES DECLARATIONS
/////////////////////////////////////////////////////////////
typedef struct GPIO_struct {
    int instance_number;
}GPIO_struct_t;

/////////////////////////////////////////////////////////////
//  FUNCTION PROTOTYPES
/////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
//    Function name: 
//    Description: 
//   
//   
//   Author: Jacques Veneziano
//   Returns: 
//            
//            
///////////////////////////////////////////////////////////////
Driver_GPIO_create_instance( int gpio_port_nb);


///////////////////////////////////////////////////////////////
//    Function name: 
//    Description: 
//   
//   
//   Author: Jacques Veneziano
//   Returns: 
//            
//            
///////////////////////////////////////////////////////////////
Driver_GPIO_write(GPIO_struct_t gpio_instance);


///////////////////////////////////////////////////////////////
//    Function name: 
//    Description: 
//   
//   
//   Author: Jacques Veneziano
//   Returns: 
//            
//            
///////////////////////////////////////////////////////////////
Driver_GPIO_read(GPIO_struct_t gpio_instance);


///////////////////////////////////////////////////////////////
//    Function name: 
//    Description: 
//   
//   
//   Author: Jacques Veneziano
//   Returns: 
//            
//            
///////////////////////////////////////////////////////////////
Driver_GPIO_PWM_(GPIO_struct_t gpio_instance, double frequency, int duty_cycle);


/////////////////////////////////////////////////////////////
//  FUNCTION DECLARATION
/////////////////////////////////////////////////////////////







#endif  /* !Driver_GPIO_MICSA_H_ */