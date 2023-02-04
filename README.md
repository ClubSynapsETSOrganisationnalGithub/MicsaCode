# MicsaCode
MicsaCode is the repository for the development of the code for our ESP32 based EEG/EEC headset. 


# Core principals of MICSA CODE

1. Drivers pour interagir avec le matériel (DAC, ADC, USART, etc...) **BUT = simplifier l'interaction pour que l'on ait pas à interagir avec le layer HAL (HARDWARE ABSTRACTION LAYER)**
2. Data process application = code qui prend les données des ADCs et les transforment en les données pour extraire les valeurs des ondes delta,theta, gamma, etc...

3. Communication IoT (Internet of things), wifi connection et on envoit l'information en ligne à un serveur qui peuvent faire des calculs additionnels sur les données ou les transmettre à une application (BCI Brain computer Interface : [BCI](https://en.wikipedia.org/wiki/Brain%E2%80%93computer_interface)).


# Link to programming documentation 

1. Documentation expressif [ESP32-S2](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s2/api-reference/peripherals/adc_oneshot.html).
<<<<<<< HEAD
=======

# Drawio Code Diagram

![Code exploded diagram](C:\SynapseDev\MicsaCode\images\MICSA_UML.png)
>>>>>>> 3f1ef15236be1636c3f28c700f66e000254d6d75
