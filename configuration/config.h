#ifndef CONFIG_H
#define CONFIG_H

	/************************************************************************************************/
	// DEVICE SETTINGS
	/************************************************************************************************/
  #define PT_SETTING_BUTTON

  #ifdef PT_SETTING_BUTTON
    #define SETTING_BUTTON
    #define BUTTON_SENSOR_PIN   12
    #define BUTTON_PERM_PIN     13
  #endif


	/************************************************************************************************/
	// DEBUG SETTINGS
	/************************************************************************************************/

	#ifdef DEBUG
    #define DEBUG_BEGIN(x)  Serial.begin (x)
		#define DEBUG_PRINT(x)  Serial.print (x)
		#define DEBUG_PRINTLN(x)  Serial.println (x)
  #else
    #define DEBUG_BEGIN(x)
		#define DEBUG_PRINT(x)
		#define DEBUG_PRINTLN(x)
	#endif
#endif