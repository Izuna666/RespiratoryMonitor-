/*
 * MS5837-30BA_Driver for I2C communication
 *
 *      Author: Izuna
 */

#ifndef INC_MS5837_30BA_DRIVER_H_
#define INC_MS5837_30BA_DRIVER_H_

#include "stm32f4xx_hal.h"	//used for I2C communication

/*
* DEFINES
*/
#define MS5837_ADDR         (0x76 << 1)  // Shifted for HAL, since it's automatically sets Write or Read bit for us in HAL_I2C functions
#define MS5837_RESET        0x1E		 // Reset address
#define MS5837_PROM_READ    0xA0		 // Beginning of PROM address
#define MS5837_CONVERT_D1   0x48  		 // Pressure conversion (OSR=4096)
#define MS5837_CONVERT_D2   0x58  		 // Temperature conversion (OSR=4096)
#define MS5837_ADC_READ     0x00		 // Raw data from ADC

/*
 * SENSOR STRUCTURE
 */
typedef struct {
    I2C_HandleTypeDef *i2cHandle; // Takes I2C bus
    float pressure_mbar;          // Processed pressure in mbar
    float temp_C;                 // Processed temperature in Celsius
    uint16_t C[7];                // Calibration coefficients (C1..C6), we ignore C[8] CRC
    uint32_t D1;                  // Raw pressure value
    uint32_t D2;                  // Raw temperature value
} MS5837;


/*
 * INITIALIZATION FUNCTION
 * Resets sensor and reads PROM calibration data
 */
HAL_StatusTypeDef MS5837_Init(MS5837 *dev, I2C_HandleTypeDef *i2cHandle);

/*
 * READ FUNCTION
 * Initiates conversions and reads raw D1 and D2 values
 */
HAL_StatusTypeDef MS5837_ReadData(MS5837 *dev, I2C_HandleTypeDef *i2cHandle);


#endif /* INC_MS5837_30BA_DRIVER_H_ */
