#ifndef LSM6DS0_H
#define LSM6DS0_H

#include <Arduino.h>

#define LSM6DS0_ACC_GYRO_ACT_THS  	0X04

#define LSM6DS0_ACC_GYRO_ACT_DUR  	0X05

#define LSM6DS0_ACC_GYRO_INT_GEN_CFG_XL  	0X06

#define LSM6DS0_ACC_GYRO_INT_GEN_THS_X_XL  	0X07

#define LSM6DS0_ACC_GYRO_INT_GEN_THS_Y_XL  	0X08

#define LSM6DS0_ACC_GYRO_INT_GEN_THS_Z_XL  	0X09

#define LSM6DS0_ACC_GYRO_INT_GEN_DUR_XL  	0X0A

#define LSM6DS0_ACC_GYRO_REFERENCE_G  	0X0B

#define LSM6DS0_ACC_GYRO_INT_CTRL  	0X0C

#define LSM6DS0_ACC_GYRO_WHO_AM_I_REG  	0X0F

#define LSM6DS0_ACC_GYRO_CTRL_REG1_G  	0X10

#define LSM6DS0_ACC_GYRO_CTRL_REG2_G  	0X11

#define LSM6DS0_ACC_GYRO_CTRL_REG3_G  	0X12

#define LSM6DS0_ACC_GYRO_ORIENT_CFG_G  	0X13

#define LSM6DS0_ACC_GYRO_INT_GEN_SRC_G  	0X14

#define LSM6DS0_ACC_GYRO_OUT_TEMP_L  	0X15

#define LSM6DS0_ACC_GYRO_OUT_TEMP_H  	0X16

#define LSM6DS0_ACC_GYRO_OUT_X_L_G  	0X18

#define LSM6DS0_ACC_GYRO_OUT_X_H_G  	0X19

#define LSM6DS0_ACC_GYRO_OUT_Y_L_G  	0X1A

#define LSM6DS0_ACC_GYRO_OUT_Y_H_G  	0X1B

#define LSM6DS0_ACC_GYRO_OUT_Z_L_G  	0X1C

#define LSM6DS0_ACC_GYRO_OUT_Z_H_G  	0X1D

#define LSM6DS0_ACC_GYRO_CTRL_REG4  	0X1E

#define LSM6DS0_ACC_GYRO_CTRL_REG5_XL  	0X1F

#define LSM6DS0_ACC_GYRO_CTRL_REG6_XL  	0X20

#define LSM6DS0_ACC_GYRO_CTRL_REG7_XL  	0X21

#define LSM6DS0_ACC_GYRO_CTRL_REG8  	0X22

#define LSM6DS0_ACC_GYRO_CTRL_REG9  	0X23

#define LSM6DS0_ACC_GYRO_CTRL_REG10  	0X24

#define LSM6DS0_ACC_GYRO_INT_GEN_SRC_XL  	0X26

#define LSM6DS0_ACC_GYRO_STATUS_REG  	0X27

#define LSM6DS0_ACC_GYRO_OUT_X_L_XL  	0X28

#define LSM6DS0_ACC_GYRO_OUT_X_H_XL  	0X29

#define LSM6DS0_ACC_GYRO_OUT_Y_L_XL  	0X2A

#define LSM6DS0_ACC_GYRO_OUT_Y_H_XL  	0X2B

#define LSM6DS0_ACC_GYRO_OUT_Z_L_XL  	0X2C

#define LSM6DS0_ACC_GYRO_OUT_Z_H_XL  	0X2D

#define LSM6DS0_ACC_GYRO_FIFO_CTRL  	0X2E

#define LSM6DS0_ACC_GYRO_FIFO_SRC  	0X2F

#define LSM6DS0_ACC_GYRO_INT_GEN_CFG_G  	0X30

#define LSM6DS0_ACC_GYRO_INT_GEN_THS_XH_G  	0X31

#define LSM6DS0_ACC_GYRO_INT_GEN_THS_XL_G  	0X32

#define LSM6DS0_ACC_GYRO_INT_GEN_THS_YH_G  	0X33

#define LSM6DS0_ACC_GYRO_INT_GEN_THS_YL_G  	0X34

#define LSM6DS0_ACC_GYRO_INT_GEN_THS_ZH_G  	0X35

#define LSM6DS0_ACC_GYRO_INT_GEN_THS_ZL_G  	0X36

#define LSM6DS0_ACC_GYRO_INT_GEN_DUR_G  	0X37

    enum regAddr
    {
      WHO_AM_I    = 0x0F,

      CTRL_REG1_G   = 0x10,
      CTRL_REG6_XL  = 0x20,
      CTRL_REG3   = 0x22,
      CTRL_REG4   = 0x23,
      CTRL_REG5   = 0x24,

      STATUS_REG  = 0x27,
      OUT_X_G     = 0x18,
      OUT_Y_G     = 0x1A,
      OUT_Z_G     = 0x1C,
      OUT_X_XL    = 0x28,
      OUT_Y_XL    = 0x2A,
      OUT_Z_XL    = 0x2C,
      TEMP_OUT_L  = 0x2E,
      TEMP_OUT_H  = 0x2F,
      INT_CFG     = 0x30,
      INT_SRC     = 0x31,
      INT_THS_L   = 0x32,
      INT_THS_H   = 0x33,
    };

enum FS_G {
	FS_G_245_DPS = 0x00,
	FS_G_500_DPS = 0x01,
	FS_G_2000_DPS = 0x3,
};

enum FS_XL {
	FS_XL_2G = 0x00,
	FS_XL_4G = 0x02,
	FS_XL_8G = 0x03,
};

class LSM6DS0
{
public:

  LSM6DS0(void);
  virtual ~LSM6DS0(void);

	void writeReg(uint8_t reg, uint8_t value);
	uint8_t readReg(uint8_t reg);

	//void read(void);
	int16_t readG_X(void);
	int16_t readG_Y(void);
	int16_t readG_Z(void);
	int16_t readA_X(void);
	int16_t readA_Y(void);
	int16_t readA_Z(void);
	void readXYZ(uint16_t val[3]);
	void setA_ODR(uint8_t odr);
	void setG_ODR(uint8_t odr);
	void setScale_G(uint8_t scale);
	void setScale_XL(uint8_t scale);
	float getScaled_G(int16_t raw);
	float getScaled_XL(int16_t raw);
	

private:
    uint8_t address;
	uint8_t last_status;
	// odr
	// scale
	uint8_t scale_G;
	uint8_t scale_XL;

};

#endif /* LSM6DS0_H */