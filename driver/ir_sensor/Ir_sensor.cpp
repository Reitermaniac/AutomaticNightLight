#ifdef IR_SENSOR
void Ir_sensor::begin()
{
  lastSignal = NO_SIGNAL;
}

unsigned long Ir_sensor::getLastSignalTimestamp()
{
  return lastSignalTimestamp;
}

void Ir_sensor::resetLastSignalTimestamp()
{
  lastSignalTimestamp = millis();
}

IrSignals_t Ir_sensor::getLastSignal()
{
  IrSignals_t returnValue = lastSignal;
  lastSignal = NO_SIGNAL;
  return returnValue;
}

IrSignals_t Ir_sensor::translate(unsigned long signal)
{
  switch(signal)
  {
    case 0xFFA25D:
      lastSignal = POWER;
      break;
    case 0xFFE21D:
      lastSignal = FUNC_STOP;
      break;
    case 0xFF629D:
      lastSignal = VOL_UP;
      break;
    case 0xFF22DD:
      lastSignal = FAST_BACK;
      break;
    case 0xFF02FD:
      lastSignal = PAUSE;
      break;
    case 0xFFC23D:
      lastSignal = FAST_FORWARD;
      break;
    case 0xFFE01F:
      lastSignal = DOWN;
      break;
    case 0xFFA857:
      lastSignal = VOL_DOWN;
      break;
    case 0xFF906F:
      lastSignal = UP;
      break;
    case 0xFF9867:
      lastSignal = EQ;
      break;
    case 0xFFB04F:
      lastSignal = ST_REPT;
      break;
    case 0xFF6897:
      lastSignal = ZERO;
      break;
    case 0xFF30CF:
      lastSignal = ONE;
      break;
    case 0xFF18E7:
      lastSignal = TWO;
      break;
    case 0xFF7A85:
      lastSignal = THREE;
      break;
    case 0xFF10EF:
      lastSignal = FOUR;
      break;
    case 0xFF38C7:
      lastSignal = FIVE;
      break;
    case 0xFF5AA5:
      lastSignal = SIX;
      break;
    case 0xFF42BD:
      lastSignal = SEVEN;
      break;
    case 0xFF4AB5:
      lastSignal = EIGHT;
      break;
    case 0xFF52AD:
      lastSignal = NINE;
      break;
    default:
      lastSignal = ERROR;
  }
  return lastSignal;
};
#endif

