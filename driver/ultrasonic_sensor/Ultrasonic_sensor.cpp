#ifdef ULTRASONIC_SENSOR
void Ultrasonic_sensor::begin()
{
  timeOfLastMeasurement = 0;
}

unsigned int Ultrasonic_sensor::getDistance()
{
  if((millis() - timeOfLastMeasurement) >= TIME_BETWEEN_MEASUREMENTS_MS)
  {
    timeOfLastMeasurement = 0;
    return sonar.ping_cm();
  }
  else
  {
    return 0;
  }
}
#endif

