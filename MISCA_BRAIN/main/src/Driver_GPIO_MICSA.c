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
#include "components/driver/include/driver/gpio.h"

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
//   à la structure Driver_GPIO avec tous les ports initialisé
//   selon les paramètres fournis
//
//   Author: Jacques Veneziano et Philippe Rochefort
//   Returns: Une structure Driver_GPIO initialisant tous les ports 
//   selon le mode 
//                        
///////////////////////////////////////////////////////////////
GPIO_struct_t Driver_GPIO_create_instance(int gpio_port_nb, uint64_t pin_position, int MODE, int PUSHPULL_config, int INTERRUPT_TYPE){
    
    //Vérification si le tableau construit est plus grand que 1
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
    nouv_GPIO->port = port_GPIO_create_instance();


    /// On vient d'assigner les information du port avec si PULL

    //Retour de la structure initialise
    return nouv_GPIO; 
}

///////////////////////////////////////////////////////////////
//   Function name: port_GPIO_create_instance
//   Description: sert à allouer la mémoire à la 
//   structure gpio_config_t 
//   Author: Philippe Rochefort
//   Returns: gpio_config_t vide
//                     
///////////////////////////////////////////////////////////////
gpio_config_t* port_GPIO_create_instance() {
    gpio_config_t* nouv_port;
    
    //Allocation de mémoire
    nouv_port = (gpio_config_t*)malloc(sizeof(struct gpio_config_t));

    //Initialiser le port en question
    if (nouv_port){
        nouv_port.pint_bit_mask = NULL; 
        nouv_port.gpio_mode_t = NULL;
        nouv_port.pull_up_en = NULL;
        nouv_port.pull_down_en = NULL;
        nouv_port.intr_type = NULL;
    }

    //Retour de la structure initialise
    return nouv_port; 
}

///////////////////////////////////////////////////////////////
//   Function name: port_GPIO_config_init
//   Description: sert à créer un port possédant les variables 
//   demandées (gpio_config_t) 
//   Author: Philippe Rochefort
//   Returns: gpio_config_t possédant les variables choisies 
//                     
///////////////////////////////////////////////////////////////

void port_GPIO_config_init(gpio_config_t* gpio__port_instance,uint64_t pin_position, int MODE, int PUSHPULL_config, int INTERRUPT_TYPE){

    //Initialisation de chaque valeur dans la structure port 
    gpio_config_t_set_pin_position(gpio__port_instance, pin_position);
    gpio_config_t_set_mode(gpio__port_instance, MODE);
    gpio_config_t_set_intr_type(gpio__port_instance, INTERRUPT_TYPE);
    gpio_config_t_set_pullpush(gpio__port_instance, PUSHPULL_config);

} ;

/*étapes création d'un GPIO_struct_t
1. crée instance du port (gpio_instance)
2. configuration du port (gpio_instance), dire si PULL-UP, PULL-DOWN, etc...
3. crée l'instance GPIO_struct_t et tu lui associe le port instance
*/



///////////////////////////////////////////////////////////////
//   Function name: gpio_config_t set functions
//   Description: Sert à écrire dans la structure du Port (gpio_config_t)
//   
//   Author: Philippe Rochefort
//   Returns: NULL 
//                     
///////////////////////////////////////////////////////////////
void gpio_config_t_set_pin_position(gpio_config_t* port, uint64_t pin_position){
    port->pin_bit_mask = pin_position;
}

void gpio_config_t_set_mode(gpio_config_t* port, int mode){
    port->mode = mode;
}

void gpio_config_t_set_pullpush(gpio_config_t* port, int PUSHPULL_config){
        //Définition des deux variables
    int pull_up;
    int pull_down; 

    //Établir la configuration selon le code obtenu
    if(PUSHPULL_config == GPIO_PUSHPULL_PULLUP_MODE){
        pull_up = 1;
        pull_down = 0;
    }

    else if(PUSHPULL_config == GPIO_PUSHPULL_PULLDOWN_MODE){
        pull_up = 0;
        pull_down = 1;
    }

    //Message d'erreur si la configuration n'est pas reconnue
    else{
        printf("Erreur! Configuration non reconnu! -> (gpio_config_t_set_pullpush)");
        return;
    }

    //Stockage des valeurs recherchés
    nouv_port.pull_up_en = pull_up;
    nouv_port.pull_down_en = pull_down;
}

void gpio_config_t_set_intr_type(gpio_config_t* port, int INTERRUPT_TYPE){
    port->intr_type = INTERRUPT_TYPE;
}

///////////////////////////////////////////////////////////////
//   Function name: gpio_config_t get functions
//   Description: Sert à lire dans la structure du Port (gpio_config_t)
//
//   Author: Philippe Rochefort
//   Returns: NULL 
//                     
///////////////////////////////////////////////////////////////
uint64_t gpio_config_t_get_pin_position(gpio_config_t port){
    return port->pin_bit_mask;
}

gpio_mode_t gpio_config_t_get_mode(gpio_config_t port){
    return port->mode;
}

gpio_pullup_t gpio_config_t_get_pull_up(gpio_config_t port){
    return port->pull_up_en;
}

gpio_pulldown_t gpio_config_t_get_pull_down(gpio_config_t port){
    return port->pull_down_en;
}

gpio_int_type_t gpio_config_t_set_intr_type(gpio_config_t port){
    return port->intr_type;
}


///////////////////////////////////////////////////////////////
//   Function name: Driver_GPIO_write
//   Description: Sert à écrire dans la structure du GPIO
//   Reçoit le numéro du port et son nom
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
//   Function name: Driver_GPIO_read_numb(GPIO_struct_t gpio_instance)
//   Description: Lit et renvoie le nombre de port total dans la structure
//   Author: Jacques Veneziano
//   Returns: Nombre de Port total
///////////////////////////////////////////////////////////////
int Driver_GPIO_read_numb(GPIO_struct_t gpio_instance){
    return gpio_instance->instance_number; 
}

///////////////////////////////////////////////////////////////
//   Function name: Driver_GPIO_read_inst_numb(GPIO_struct_t gpio_instance)
//   Description: Lit et renvoie le nombre de port total dans la structure
//
//   Author: Philippe Rochefort
//   Returns: Information sur le nombre de port exacte
///////////////////////////////////////////////////////////////
int Driver_GPIO_read_inst_numb(GPIO_struct_t gpio_instance){
    return gpio_instance->instance_number; 
}

///////////////////////////////////////////////////////////////
//   Function name: Driver_GPIO_read_inst_numb(GPIO_struct_t gpio_instance)
//   Description: Lit et renvoie le nombre de port total dans la structure
//
//   Author: Philippe Rochefort
//   Returns: Information sur le nombre de port exacte
///////////////////////////////////////////////////////////////
int Driver_GPIO_read_inst_numb(GPIO_struct_t gpio_instance){
    return gpio_instance->instance_number; 
}

///////////////////////////////////////////////////////////////
//   Function name: Port_GPIO_destruct(GPIO_port_t port)
//   Description: Libération de mémoire pour une structure gpio_config_t
//
//   Author: Philippe Rochefort
//   Returns: NULL
///////////////////////////////////////////////////////////////
void Port_GPIO_destroy(gpio_config_t port){
    free(port->pin_bit_mask);
    free(port->mode);
    free(port->pull_up_en);
    free(port->pull_down_en);
    free(port->intr_type);
    free(port);
}

///////////////////////////////////////////////////////////////
//   Function name: Driver_GPIO_destruct(GPIO_struct_t driver_gpio)
//   Description: Libération pour une structure Driver_GPIO
//
//   Author: Philippe Rochefort
//   Returns: NULL
///////////////////////////////////////////////////////////////
void Driver_GPIO_destruct(GPIO_struct_t driver_gpio){
    int i; //Variable itérative

    //Destruction de chacun des ports 
    for (i=0; i < driver_gpio-> gpio_port_nb; i++){
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