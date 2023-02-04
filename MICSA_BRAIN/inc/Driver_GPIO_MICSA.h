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
//   Function name: 
//   Description: Sert à allouer de la mémoire
//   à la structure Driver_GPIO avec tous les ports initialisé
//   selon les paramètres fournis
//
//   Author: Jacques Veneziano et Philippe Rochefort
//   Returns: Une structure Driver_GPIO initialisant tous les ports 
//   selon le mode 
//                        
///////////////////////////////////////////////////////////////
GPIO_struct_t Driver_GPIO_create_instance(int gpio_port_nb, uint64_t pin_position, int MODE, int PUSHPULL_config, int INTERRUPT_TYPE);

///////////////////////////////////////////////////////////////
//   Function name: port_GPIO_create_instance
//   Description: sert à allouer la mémoire à la 
//   structure gpio_config_t 
//   Author: Philippe Rochefort
//   Returns: gpio_config_t vide
//                     
///////////////////////////////////////////////////////////////
gpio_config_t* port_GPIO_create_instance();


///////////////////////////////////////////////////////////////
//   Function name: port_GPIO_config_init
//   Description: sert à créer un port possédant les variables 
//   demandées (gpio_config_t) 
//   Author: Philippe Rochefort
//   Returns: gpio_config_t possédant les variables choisies 
//
//   Étapes création d'un GPIO_struct_t
//   1. crée instance du port (gpio_instance)
//   2. configuration du port (gpio_instance), dire si PULL-UP, PULL-DOWN, etc...
//   3. crée l'instance GPIO_struct_t et tu lui associe le port instance
//                     
///////////////////////////////////////////////////////////////
void port_GPIO_config_init(gpio_config_t* gpio__port_instance,uint64_t pin_position, int MODE, int PUSHPULL_config, int INTERRUPT_TYPE);

///////////////////////////////////////////////////////////////
//   Function name: gpio_config_t set functions
//   Description: Sert à écrire dans la structure du Port (gpio_config_t)
//   la position du PIN dans le port
//   
//   Author: Philippe Rochefort
//   Returns: NULL 
//   
///////////////////////////////////////////////////////////////
void gpio_config_t_set_pin_position(gpio_config_t* port, uint64_t pin_position);

///////////////////////////////////////////////////////////////
//   Function name: gpio_config_t set functions
//   Description: Sert à écrire dans la structure du Port (gpio_config_t)
//   le mode du port (input ou output)
//    
//   Author: Philippe Rochefort
//   Returns: NULL 
//                     
///////////////////////////////////////////////////////////////
void gpio_config_t_set_mode(gpio_config_t* port, int mode);

///////////////////////////////////////////////////////////////
//   Function name: gpio_config_t set functions
//   Description: Sert à écrire dans la structure du Port (gpio_config_t)
//   la configuration (PUSH ou PULL) du port 
//   
//   Author: Philippe Rochefort
//   Returns: NULL 
//                     
///////////////////////////////////////////////////////////////
void gpio_config_t_set_pullpush(gpio_config_t* port, int PUSHPULL_config);

///////////////////////////////////////////////////////////////
//   Function name: gpio_config_t set functions
//   Description: Sert à écrire dans la structure du Port (gpio_config_t)
//   le type d'interruption
//
//   Author: Philippe Rochefort
//   Returns: NULL 
//                     
///////////////////////////////////////////////////////////////
void gpio_config_t_set_intr_type(gpio_config_t* port, int INTERRUPT_TYPE);

///////////////////////////////////////////////////////////////
//   Function name: gpio_config_t get functions
//   Description: Sert à lire dans la structure du Port (gpio_config_t)
//   la position du PIN dans le port
//
//   Author: Philippe Rochefort
//   Returns: uint64_t (pin_position) 
//                     
///////////////////////////////////////////////////////////////
uint64_t gpio_config_t_get_pin_position(gpio_config_t port);


///////////////////////////////////////////////////////////////
//   Function name: Driver_GPIO_write
//   Description: Sert à écrire dans la structure du GPIO
//   Reçoit le numéro du port et son nom
//
//   Author: Philippe Rochefort
//   Returns: NULL 
//                     
///////////////////////////////////////////////////////////////
void Driver_GPIO_write(GPIO_struct_t gpio_instance, int port_number, char* port_name);

///////////////////////////////////////////////////////////////
//   Function name: Driver_GPIO_read_numb(GPIO_struct_t gpio_instance)
//   Description: Lit et renvoie le nombre de port total dans la structure
//   Author: Jacques Veneziano
//   Returns: Nombre de Port total
///////////////////////////////////////////////////////////////
int Driver_GPIO_read_numb(GPIO_struct_t gpio_instance);

///////////////////////////////////////////////////////////////
//   Function name: Driver_GPIO_read_inst_numb(GPIO_struct_t gpio_instance)
//   Description: Lit et renvoie le nombre de port total dans la structure
//
//   Author: Philippe Rochefort
//   Returns: Information sur le nombre de port exacte
///////////////////////////////////////////////////////////////
int Driver_GPIO_read_inst_numb(GPIO_struct_t gpio_instance);

///////////////////////////////////////////////////////////////
//   Function name: Driver_GPIO_read_inst_numb(GPIO_struct_t gpio_instance)
//   Description: Lit et renvoie le nombre de port total dans la structure
//
//   Author: Philippe Rochefort
//   Returns: Information sur le nombre de port exacte
///////////////////////////////////////////////////////////////
int Driver_GPIO_read_inst_numb(GPIO_struct_t gpio_instance);

///////////////////////////////////////////////////////////////
//   Function name: Port_GPIO_destruct(GPIO_port_t port)
//   Description: Libération de mémoire pour une structure gpio_config_t
//
//   Author: Philippe Rochefort
//   Returns: NULL
///////////////////////////////////////////////////////////////
void Port_GPIO_destroy(gpio_config_t port);

///////////////////////////////////////////////////////////////
//   Function name: Driver_GPIO_destruct(GPIO_struct_t driver_gpio)
//   Description: Libération pour une structure Driver_GPIO
//
//   Author: Philippe Rochefort
//   Returns: NULL
///////////////////////////////////////////////////////////////
void Driver_GPIO_destruct(GPIO_struct_t driver_gpio);

///////////////////////////////////////////////////////////////
//   Function name: 
//   Description: 
//   
//   Author: Jacques Veneziano
//   Returns: 
//            
///////////////////////////////////////////////////////////////
Driver_GPIO_PWM_(GPIO_struct_t gpio_instance, double frequency, int duty_cycle);



#endif  /* !Driver_GPIO_MICSA_H_ */