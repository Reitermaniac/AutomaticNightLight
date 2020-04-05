#ifdef IR_SENSOR
void Ir_sensor::begin()
{
  lastSignal = 0;
}

unsigned long Ir_sensor::getLastSignalTimestamp()
{
  return lastSignal;
}

void Ir_sensor::resetLastSignalTimestamp()
{
  lastSignal = millis();
}

IrSignals_t Ir_sensor::translate(unsigned long signal)
{
  switch(signal)
  {
    case 0xFFA25D: return POWER;
    case 0xFFE21D: return FUNC_STOP;
    case 0xFF629D: return VOL_UP;
    case 0xFF22DD: return FAST_BACK;
    case 0xFF02FD: return PAUSE;
    case 0xFFC23D: return FAST_FORWARD;
    case 0xFFE01F: return DOWN;
    case 0xFFA857: return VOL_DOWN;
    case 0xFF906F: return UP;
    case 0xFF9867: return EQ;
    case 0xFFB04F: return ST_REPT;
    case 0xFF6897: return ZERO;
    case 0xFF30CF: return ONE;
    case 0xFF18E7: return TWO;
    case 0xFF7A85: return THREE;
    case 0xFF10EF: return FOUR;
    case 0xFF38C7: return FIVE;
    case 0xFF5AA5: return SIX;
    case 0xFF42BD: return SEVEN;
    case 0xFF4AB5: return EIGHT;
    case 0xFF52AD: return NINE;
    default: return ERROR;
  }
};
#endif

