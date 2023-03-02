/************************************************************
*  File Name : Driver_LED_MICSA_c
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
#include "Driver_LED_MICSA.h"

/////////////////////////////////////////////////////////////
//  VARIABLES & TYPES DECLARATIONS
/////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////
//  FUNCTION PROTOTYPES
/////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////
//  FUNCTION DECLARATION
/////////////////////////////////////////////////////////////

/*******************************************************************
  * @brief  Creates the LED instance with the LED parameters to
  *         be able manipulate LED number X on board
  *
  * @author Jacques Veneziano and charles Marton Lacoursiere
  * 
  * @param  IO_struct_t IO_PORT_NUMBER // MCU pin corresponding to LED
  * 
  * @param  LED_status_t status     // Set the status of the LED ON/OFF
  * 
  * @param  double frequency        // frequency of blink in milliseconds
  *                                0 if no blink 
  * 
  * @param  double timeout          //  timeout in millisecond, 
  *                                 0 if no timeout
  * 
  * @param  int color               // 256 bit values for color palette
  *
  * @return 0 for FAILURE
  *         1 for SUCCESS
  *
*******************************************************************/
LED_struct_t Driver_LED_create_instance(IO_struct_t IO_PORT_NUMBER, LED_status_t status, double frequency, double timeout, int color){
  //Creation de la structure
  LED_struct_t nouv_LED;

  //Allocation de memoire pour la structure LED
  nouv_LED=(LED_struct_t)malloc(sizeof(struct LED_struct));

  if(nouv_LED){
    //Initilaisation des champs avec parameteres de la fonction
    nouv_LED->IO_PORT_NUMBER=IO_PORT_NUMBER;
    nouve_LED->status=status;
    nouv_LED->frequency=frequency;
    nouv_LED->timeout=timeout;
    nouv_LED->color=color;

    gpio_pad_select_gpio(IO_PORT_NUMBER);
    gpio_set_direction(IO_PORT_NUMBER,0);
  }

  //Retour de la structure initialise
  return nouv_LED;
};


/*******************************************************************
  * @brief Blink LED function
  *
  * @author Jacques Veneziano and charles Marton Lacoursiere
  * 
  * @param  LED_struct_t instance   // instance of the LED you want
  *                                    modifiy
  * @param  double frequency    // frequency of blink in milliseconds
  *                                0 if no blink
  * 
  * @param  double timeout      //  timeout in millisecond, 
  *                                 0 if no timeout
  *
  * @return 0 for FAILURE
  *         1 for SUCCESS
  *
*******************************************************************/
int Driver_LED_blink(LED_struct_t instance, double frequency, double timeout){
  
  //Verification que l'instance LED existe
  if(instance==NULL){
    printf("Erreur, instance LED non initialise.\n");
    return 0;
  }

  instance->frequency=frequency;
  instance->timeout=timeout;
  instance->status=3;

  int ON=0;
  while(true){
    ON=!ON;
    gpio_set_level(instance->IO_PORT_NUMBER,ON);
    vTaskDelay(frequency/timeout);
  }
  

  return 1;
};


/*******************************************************************
  * @brief Blink LED function
  *
  * @author Jacques Veneziano and charles Marton Lacoursiere
  * 
  * @param  LED_struct_t instance   // instance of the LED you want
  *                                    modifiy
  * @param  int color               // 256 bit values for color palette
  *
  * @return 0 for FAILURE
  *         1 for SUCCESS
  *
*******************************************************************/
int Driver_LED_set_color(LED_struct_t instance, int color){
  //Verification que l'instance LED existe
  if(instance==NULL){
    printf("Erreur, instance LED non initialise.\n");
    return 0;
  }

  instance->color=color;
  return 1;
};


/*******************************************************************
  * @brief Turn ON LED function
  *
  * @author Jacques Veneziano and charles Marton Lacoursiere
  * 
  * @param  LED_struct_t instance   // instance of the LED you want
  *                                 // modifiy
  *
  * @return 0 for FAILURE
  *         1 for SUCCESS
  *
*******************************************************************/
int Driver_LED_turn_ON(LED_struct_t instance){
  //Verification que l'instance LED existe
  if(instance==NULL){
    printf("Erreur, instance LED non initialise.\n");
    return 0;
  }

  //On met le sortie du pin a HIGH
  gpio_set_level(instance->IO_PORT_NUMBER,1);
  return 1;
};


/*******************************************************************
  * @brief Turn OFF LED function
  *
  * @author Jacques Veneziano and charles Marton Lacoursiere
  * 
  * @param  LED_struct_t instance   // instance of the LED you want
  *                                 // modifiy
  *
  * @return 0 for FAILURE
  *         1 for SUCCESS
  *
*******************************************************************/
int Driver_LED_turn_OFF(LED_struct_t instance){
  //Verification que l'instance LED existe
  if(instance==NULL){
    printf("Erreur, instance LED non initialise.\n");
    return 0;
  }

  //On met le sortie du pin a HIGH
  gpio_set_level(instance->IO_PORT_NUMBER,0);
  return 1;
};