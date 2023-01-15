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
    gpio_config_t* port;
}GPIO_struct_t;


/////////////////////////////////////////////////////////////
//  FUNCTION PROTOTYPES
/////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
//   Function name: Driver_GPIO_create_instance
//   Description: 
//   Reçoit un port et retourne 
//   
//   Author: Jacques Veneziano
//   Returns: 
//            
//            
///////////////////////////////////////////////////////////////
GPIO_struct_t Driver_GPIO_create_instance(int gpio_port_nb, uint64_t pin_position, int MODE, int PUSHPULL_config, int INTERRUPT_TYPE);

///////////////////////////////////////////////////////////////
//    Function name: Port_GPIO_create_instance
//    Description: Initialisation du tableau de port 
//   
//   Author: Philippe Rochefort
//   Returns: Une structure de port initialisé ne contenant
//            aucune information
//            
///////////////////////////////////////////////////////////////
GPIO_port_t Port_GPIO_create_instance(void);

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