#include <LSM6DS0.h>
#include <Wire.h>

float fs_g_map[] = { 245, 0, 500, 2000 };
float fs_xl_map[] = { 2, 0, 4, 8 };
	
LSM6DS0::LSM6DS0(void)
{
  address = 0x6B;
  scale_G = 0;
  scale_XL = 0;
}

LSM6DS0::~LSM6DS0(void)
{
}

void LSM6DS0::writeReg(uint8_t reg, uint8_t value)
{
  Wire.beginTransmission(address);
  Wire.write(reg);
  Wire.write(value);
  last_status = Wire.endTransmission(true);
}

// Reads a mag register
uint8_t LSM6DS0::readReg(uint8_t reg)
{
  uint8_t value;

  Wire.beginTransmission(address);
  Wire.write(reg);
  last_status = Wire.endTransmission(false);
  Wire.requestFrom(address, (uint8_t)1);
  value = Wire.read();
  Wire.endTransmission(true);

  return value;
}

int16_t LSM6DS0::readG_X(void)
{
  Wire.beginTransmission(address);
  // assert MSB to enable subaddress updating
  Wire.write(OUT_X_G | 0x80);
  Wire.endTransmission();
  Wire.requestFrom(address, (uint8_t)2);

  while (Wire.available() < 2)
  {
  }

  uint8_t xlm = Wire.read();
  uint8_t xhm = Wire.read();

  return (xhm << 8 | xlm);
}

int16_t LSM6DS0::readG_Y(void)
{
  Wire.beginTransmission(address);
  // assert MSB to enable subaddress updating
  Wire.write(OUT_Y_G | 0x80);
  Wire.endTransmission();
  Wire.requestFrom(address, (uint8_t)2);

  while (Wire.available() < 2)
  {
  }

  uint8_t ylm = Wire.read();
  uint8_t yhm = Wire.read();

  return (yhm << 8 | ylm);
}

int16_t LSM6DS0::readG_Z(void)
{
  Wire.beginTransmission(address);
  // assert MSB to enable subaddress updating
  Wire.write(OUT_Z_G | 0x80);
  Wire.endTransmission();
  Wire.requestFrom(address, (uint8_t)2);

  while (Wire.available() < 2)
  {
  }

  uint8_t zlm = Wire.read();
  uint8_t zhm = Wire.read();

  return (zhm << 8 | zlm);
}

int16_t LSM6DS0::readA_X(void)
{
  Wire.beginTransmission(address);
  // assert MSB to enable subaddress updating
  Wire.write(OUT_X_XL | 0x80);
  Wire.endTransmission();
  Wire.requestFrom(address, (uint8_t)2);

  while (Wire.available() < 2)
  {
  }

  uint8_t xlm = Wire.read();
  uint8_t xhm = Wire.read();

  return (xhm << 8 | xlm);
}

int16_t LSM6DS0::readA_Y(void)
{
  Wire.beginTransmission(address);
  // assert MSB to enable subaddress updating
  Wire.write(OUT_Y_XL | 0x80);
  Wire.endTransmission();
  Wire.requestFrom(address, (uint8_t)2);

  while (Wire.available() < 2)
  {
  }

  uint8_t ylm = Wire.read();
  uint8_t yhm = Wire.read();

  return (yhm << 8 | ylm);
}

int16_t LSM6DS0::readA_Z(void)
{
  Wire.beginTransmission(address);
  // assert MSB to enable subaddress updating
  Wire.write(OUT_Z_XL | 0x80);
  Wire.endTransmission();
  Wire.requestFrom(address, (uint8_t)2);

  while (Wire.available() < 2)
  {
  }

  uint8_t zlm = Wire.read();
  uint8_t zhm = Wire.read();

  return (zhm << 8 | zlm);
}

void LSM6DS0::readXYZ(uint16_t val[3])
{
  Wire.beginTransmission(address);
  // assert MSB to enable subaddress updating
  Wire.write(OUT_X_G | 0x80);
  Wire.endTransmission();
  Wire.requestFrom(address, (uint8_t)6);

//  uint16_t millis_start = millis();
  while (Wire.available() < 6)
  {
//    if (io_timeout > 0 && ((uint16_t)millis() - millis_start) > io_timeout)
//    {
//      did_timeout = true;
//      return;
//    }
  }

  uint8_t xlm = Wire.read();
  uint8_t xhm = Wire.read();
  uint8_t ylm = Wire.read();
  uint8_t yhm = Wire.read();
  uint8_t zlm = Wire.read();
  uint8_t zhm = Wire.read();

  // combine high and low bytes
  val[0] = (uint16_t)(xhm << 8 | xlm);
  val[1] = (uint16_t)(yhm << 8 | ylm);
  val[2] = (uint16_t)(zhm << 8 | zlm);
}

void LSM6DS0::setA_ODR(uint8_t odr)
{
	// 10000000
	writeReg(CTRL_REG6_XL, 0x80);
}

void LSM6DS0::setG_ODR(uint8_t odr)
{
	// 11000000
	writeReg(CTRL_REG1_G, 0xC0);
}

void LSM6DS0::setScale_G(uint8_t scale)
{
	scale_G = scale;
}

void LSM6DS0::setScale_XL(uint8_t scale)
{
	scale_XL = scale;
}

float LSM6DS0::getScaled_G(int16_t raw)
{
	return (raw * fs_g_map[0]) / 32768.0;
}

float LSM6DS0::getScaled_XL(int16_t raw)
{
	return (raw * fs_xl_map[0]) / 32768.0;
}
	