/*
 * SCD41-D-R2_Driver.c
 *
 *      Author: Izuna
 */

#include "SCD41-D-R2_Driver.h"

HAL_StatusTypeDef SCD41_Init(I2C_HandleTypeDef *i2cHandle)
{



}


HAL_StatusTypeDef SCD41_StartPerodicMeasurement()
{
	HAL_StatusTypeDef status;
	dev->i2cHandle = i2cHandle;
	uint8_t command[2];			//2-bytes array for splitting 16-bit commands to 8 bit ones

	command[0] = SCD41_START_PERIODIC_MEASURE <<8;
	command[1] = SCD41_START_PERIODIC_MEASURE & 0xFF;
	status = HAL_I2C_Master_Transmit(i2cHandle, SCD41_ADDR, command, 2, HAL_MAX_DELAY);
	if (status != HAL_OK) return status;

	return HAL_OK;

}
