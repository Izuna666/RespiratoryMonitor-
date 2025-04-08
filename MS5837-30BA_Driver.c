/*
 * MS5837-30BA_Driver.c
 *
 *      Author: Izuna
 */
#include "MS5837-30BA_Driver.h"

HAL_StatusTypeDef MS5837_Init(MS5837 *dev, I2C_HandleTypeDef *i2cHandle)
{
    HAL_StatusTypeDef status;
    uint8_t command;
    uint8_t rx_buf[2];			//2-bytes array for raw data storing

    dev->i2cHandle = i2cHandle;

    // Reset the sensor
    command = MS5837_RESET;
    status = HAL_I2C_Master_Transmit(i2cHandle, MS5837_ADDR, &command, 1, HAL_MAX_DELAY);
    if (status != HAL_OK) return status;

    HAL_Delay(10); // Wait for sensor to reset

    // Read 6 calibration values from PROM (C1 to C6, addresses 0xA2 to 0xAC)
    for (uint8_t i = 0; i < 6; i++) {
    	command = MS5837_PROM_READ + (2 * (i + 1));  // Skip 0xA0 (reserved)

        status = HAL_I2C_Master_Transmit(i2cHandle, MS5837_ADDR, &command, 1, HAL_MAX_DELAY);
        if (status != HAL_OK) return status;

        status = HAL_I2C_Master_Receive(i2cHandle, MS5837_ADDR, rx_buf, 2, HAL_MAX_DELAY);
        if (status != HAL_OK) return status;

        dev->C[i + 1] = (rx_buf[0] << 8) | rx_buf[1];  // This line is converting two 8-bit values from the sensor
        											   //into a single 16-bit unsigned integer, and storing it into the calibration array
    }

    return HAL_OK;
}

HAL_StatusTypeDef MS5837_ReadData(MS5837 *dev, I2C_HandleTypeDef *i2cHandle)
{
    HAL_StatusTypeDef status;
    uint8_t command;
    uint8_t adc[3];

    dev->i2cHandle = i2cHandle;

    // ---- Read Pressure (D1) ----
    command = MS5837_CONVERT_D1;
    status = HAL_I2C_Master_Transmit(i2cHandle, MS5837_ADDR, &command, 1, HAL_MAX_DELAY);
    if (status != HAL_OK) return status;
    HAL_Delay(20);  // Max conversion time for OSR=4096

    command = MS5837_ADC_READ;
    status = HAL_I2C_Master_Transmit(i2cHandle, MS5837_ADDR, &command, 1, HAL_MAX_DELAY);
    if (status != HAL_OK) return status;

    status = HAL_I2C_Master_Receive(i2cHandle, MS5837_ADDR, adc, 3, HAL_MAX_DELAY);
    if (status != HAL_OK) return status;

    dev->D1 = (adc[0] << 16) | (adc[1] << 8) | adc[2];

    // ---- Read Temperature (D2) ----
    command = MS5837_CONVERT_D2;
    status = HAL_I2C_Master_Transmit(i2cHandle, MS5837_ADDR, &command, 1, HAL_MAX_DELAY);
    if (status != HAL_OK) return status;
    HAL_Delay(20);  // Max conversion time

    command = MS5837_ADC_READ;
    status = HAL_I2C_Master_Transmit(i2cHandle, MS5837_ADDR, &command, 1, HAL_MAX_DELAY);
    if (status != HAL_OK) return status;

    status = HAL_I2C_Master_Receive(i2cHandle, MS5837_ADDR, adc, 3, HAL_MAX_DELAY);
    if (status != HAL_OK) return status;

    dev->D2 = (adc[0] << 16) | (adc[1] << 8) | adc[2];

    return HAL_OK;
}
