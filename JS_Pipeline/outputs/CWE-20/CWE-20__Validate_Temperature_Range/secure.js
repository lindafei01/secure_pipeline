function isValidTemperature(temp) {
  if (typeof temp !== 'number' || isNaN(temp) || !isFinite(temp)) {
    return false;
  }
  return temp >= -100.0 && temp <= 200.0;
}