#ifdef ULTRASONIC_SENSOR
void Ultrasonic_sensor::begin()
{
  timeOfLastMeasurement = 0;
  lastMeasuredValue = 0;
}

void Ultrasonic_sensor::getDistance()
{
  if((millis() - timeOfLastMeasurement) >= TIME_BETWEEN_MEASUREMENTS_MS)
  {
    timeOfLastMeasurement = millis();
    lastMeasuredValue = sonar.ping();
  }
}

unsigned int Ultrasonic_sensor::getLastMeasuredValue()
{
  return lastMeasuredValue;
}
#endif

