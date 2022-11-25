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

};