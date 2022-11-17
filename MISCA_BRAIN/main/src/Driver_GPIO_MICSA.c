/************************************************************
*  File Name : Driver_GPIO_MICSA.c
*  Description: This module is a Driver implementation for 
*               the GPIO peripheral of the ESP32-S2 and is
*               used to simplify interaction with the material.

*  Author : Jacques Veneziano, Philippe Rochefort
*  Date: 2022-11-09
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
#include "Driver_GPIO_MICSA.h"

/////////////////////////////////////////////////////////////
//  VARIABLES & TYPES DECLARATIONS
/////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////
//  FUNCTION PROTOTYPES
/////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////
//  FUNCTION DECLARATION
/////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
//   Function name: 
//   Description: Sert à allouer de la mémoire
//   à la structure 
//   
//   Author: Jacques Veneziano
//   Returns: Une structure Driver_GPIO initialisée
//                        
///////////////////////////////////////////////////////////////
GPIO_struct_t Driver_GPIO_create_instance(int gpio_port_nb){
    
    if(gpio_port_nb =< 0){
        printf("Erreur, GPIO_port_nb plus petit ou egale a zero!");
        return NULL; 
    }
    
    //Creation de la structure
    GPIO_struct_t nouv_GPIO;
    
    //Allocation de memoire pour la structure GPIO
    nouv_GPIO = GPIO_struct_t * malloc(sizeof(struct GPIO_struct));

    //Initialisation avec gpio_port_nb de port pour le tableau
    nouv_GPIO->instance_number = gpio_port_nb;

    //Allocation de mémoire pour la structure de Port 
    nouv_GPIO->port = (GPIO_port_t*)malloc((nouv_GPIO->instance_number) * sizeof(GPIO_port_t));

    //Creation de tous les ports avec le tableau
    for(int i=0; i<gpio_port_nb; i++){
        nouv_GPIO->port[i] = Port_GPIO_create_instance();
    }
    
    //Retour de la structure initialise
    return nouv_GPIO; 
}

//Initisalisation du tableau de Port
GPIO_port_t Port_GPIO_create_instance{
    GPIO_port_t nouv_port;
    nouv_port = (GPIO_port_t)malloc(sizeof(struct GPIO_Port));

    //Initialiser le port en question
    if (nouv_port){
        nouv_port.name = NULL; 
        nouv_port.port_num = NULL;
    }

    //Retour de la structure initialise
    return nouv_port; 
}


///////////////////////////////////////////////////////////////
//    Function name: Driver_GPIO_write
//    Description: Sert à écrire dans la structure du GPIO
//    Reçoit le numéro du port et son nom
//   
//   Author: Philippe Rochefort
//   Returns: NULL 
//                     
///////////////////////////////////////////////////////////////
void Driver_GPIO_write(GPIO_struct_t gpio_instance, int port_number, char* port_name){
    //Écriture dans le tableau le port 
    gpio_instance->port(port_number).name = port_name;
    gpio_instance->port(port_number).port_number = port_number; 
}

///////////////////////////////////////////////////////////////
//    Function name: Driver_GPIO_read_numb(GPIO_struct_t gpio_instance)
//    Description: Lit et renvoie le nombre de port total dans la structure
//   Author: Jacques Veneziano
//   Returns: Nombre de Port total
///////////////////////////////////////////////////////////////
int Driver_GPIO_read_numb(GPIO_struct_t gpio_instance){
    return gpio_instance->instance_number; 
}

///////////////////////////////////////////////////////////////
//   Function name: Driver_GPIO_read_inst_numb(GPIO_struct_t gpio_instance)
//   Description: Lit et renvoie le nombre de port total dans la structure
//   Author: Philippe Rochefort
//   Returns: Information sur le nombre de port exacte
///////////////////////////////////////////////////////////////
int Driver_GPIO_read_inst_numb(GPIO_struct_t gpio_instance){
    return gpio_instance->instance_number; 
}

///////////////////////////////////////////////////////////////
//   Function name: Driver_GPIO_read_inst_numb(GPIO_struct_t gpio_instance)
//   Description: Lit et renvoie le nombre de port total dans la structure
//   Author: Philippe Rochefort
//   Returns: Information sur le nombre de port exacte
///////////////////////////////////////////////////////////////
int Driver_GPIO_read_inst_numb(GPIO_struct_t gpio_instance){
    return gpio_instance->instance_number; 
}

///////////////////////////////////////////////////////////////
//   Function name: Port_GPIO_read_name(GPIO_port_t port)
//   Description: Lit et retourne le nom du port dans la structure
//   Author: Philippe Rochefort
//   Returns: Le nom du port
///////////////////////////////////////////////////////////////
char* Port_GPIO_read_name(GPIO_port_t port){
    return port->name; 
}

///////////////////////////////////////////////////////////////
//   Function name: Port_GPIO_read_name(GPIO_port_t port)
//   Description: Lit et renvoie le nombre de port total dans la structure
//   Author: Philippe Rochefort
//   Returns: Le numéro du port
///////////////////////////////////////////////////////////////
int Port_GPIO_read_portnum(GPIO_port_t port){
    return port->port_num; 
}

///////////////////////////////////////////////////////////////
//   Function name: Port_GPIO_destruct(GPIO_port_t port)
//   Description: Libération de mémoire pour une structure Port_GPIO
//   Author: Philippe Rochefort
//   Returns: NULL
///////////////////////////////////////////////////////////////
void Port_GPIO_destroy(GPIO_port_t port){
    free(port->name);
    free(port->port_num);
    free(port);
}

///////////////////////////////////////////////////////////////
//   Function name: Driver_GPIO_destruct(GPIO_struct_t driver_gpio)
//   Description: Libération pour une structure Driver_GPIO
//   Author: Philippe Rochefort
//   Returns: NULL
///////////////////////////////////////////////////////////////
void Driver_GPIO_destruct(GPIO_struct_t driver_gpio){
    int i; //Variable itérative

    //Destruction de chacun des ports 
    for (i=0; i < driver_gpio; i++){
        Port_GPIO_destroy(driver_gpio->port[i]);
    }

    //Libération de la structure
    free(driver_gpio);
}

///////////////////////////////////////////////////////////////
//   Function name: 
//   Description: 
//   
//   Author: Jacques Veneziano
//   Returns: 
//            
///////////////////////////////////////////////////////////////
Driver_GPIO_PWM_(GPIO_struct_t gpio_instance, double frequency, int duty_cycle);