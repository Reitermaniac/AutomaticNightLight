#ifndef CONFIG_H
#define CONFIG_H

	/************************************************************************************************/
	// DEVICE SETTINGS
	/************************************************************************************************/
  #define PT_SETTING_BUTTON
  #define PT_RGB_LED
  #define PT_ULTRASONIC_SENSOR
  #define PT_LIGHT_SENSOR
  #define PT_IR_SENSOR

  #ifdef PT_SETTING_BUTTON
    #define SETTING_BUTTON
    #define BUTTON_SENSOR_PIN                    2
    #define BUTTON_PERM_PIN                      4
  #endif

  #ifdef PT_RGB_LED
    #define RGB_LED
    #define RGB_LED_RED_PIN                      3
    #define RGB_LED_GREEN_PIN                    5
    #define RGB_LED_BLUE_PIN                     6
  #endif

  #ifdef PT_ULTRASONIC_SENSOR
    #define ULTRASONIC_SENSOR
    #define MAX_MEASURED_DISTANCE_CM             200
    #define ULTRASONIC_SENSOR_ECHO_PIN           11
    #define ULTRASONIC_SENSOR_TRIGGER_PIN        12
  #endif

  #ifdef PT_LIGHT_SENSOR
    #define LIGHT_SENSOR
    #define LIGHT_SENSOR_BORDER                  50
    #define LIGHT_SENSOR_ANALOG_PIN              0
  #endif

  #ifdef  PT_IR_SENSOR
    #define IR_SENSOR
    #define IR_SENSOR_TIME_BETWEEN_SIGNALS_MS     500
    #define IR_SENSOR_INPUT_PIN                   7
	  typedef enum {
      ERROR,
      NO_SIGNAL,
      POWER,
      FUNC_STOP,
      VOL_UP,
      FAST_BACK,
      PAUSE,
      FAST_FORWARD,
      DOWN,
      VOL_DOWN,
      UP,
      EQ,
      ST_REPT,
      ZERO,
      ONE,
      TWO,
      THREE,
      FOUR,
      FIVE,
      SIX,
      SEVEN,
      EIGHT,
      NINE
	  } IrSignals_t;
  #endif

	/************************************************************************************************/
	// DEBUG SETTINGS
	/************************************************************************************************/

	#ifdef DEBUG_PROJECT
    #define DEBUG_BEGIN(x)  Serial.begin (x)
		#define DEBUG_PRINT(x)  Serial.print (x)
		#define DEBUG_PRINTLN(x)  Serial.println (x)
  #else
    #define DEBUG_BEGIN(x)
		#define DEBUG_PRINT(x)
		#define DEBUG_PRINTLN(x)
	#endif
#endif