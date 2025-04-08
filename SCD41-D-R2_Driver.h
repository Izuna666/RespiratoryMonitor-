/*
 * SCD41-D-R2_Driver.h
 *
 *      Author: Izuna
 */

#ifndef INC_SCD41_D_R2_DRIVER_H_
#define INC_SCD41_D_R2_DRIVER_H_

#include "stm32f4xx_hal.h"	//used for I2C communication

/*
* DEFINES
*/
#define SCD41_ADDR         (0x62 << 1)  // Shifted for HAL, since it's automatically sets Write or Read bit for us in HAL_I2C functions

/*
 * SCD41 Basic Commands
*/
#define SCD41_START_PERIODIC_MEASURE    0x21B1   ///< start periodic measurement, signal update interval is 5 seconds.
#define SCD41_READ_MEASUREMENT          0xEC05   ///< read measurement
#define SCD41_STOP_PERIODIC_MEASURE     0x3F86   ///< stop periodic measurement command

/*
 * SENSOR STRUCTURE
 */
typedef struct {
    I2C_HandleTypeDef *i2cHandle; // Takes I2C bus
    float humididty;
    float temperature;
    uint16_t CO2_ppm;
} SCD41;


/*
 * INITIALIZATION FUNCTION
 */
HAL_StatusTypeDef SCD41_StartPerodicMeasurement();

/*
 * READ SINGLE SHOT FUNCTION
 */
HAL_StatusTypeDef SCD41_MeasureSingleShot (SCD41 *dev, I2C_HandleTypeDef *i2cHandle);



#endif /* INC_SCD41_D_R2_DRIVER_H_ */
