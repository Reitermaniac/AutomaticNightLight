#ifdef LIGHT_SENSOR
uint16_t Light_sensor::getLightIntensitiy()
{
  return analogRead(LIGHT_SENSOR_ANALOG_PIN);
}
#endif

