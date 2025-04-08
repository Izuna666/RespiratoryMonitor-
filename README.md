# RespiratoryMonitor
## This project aims to design and implement a system for monitoring respiratory parameters using *STM32 microcontroler*, *MS5837_30BA pressure and temperature sensor*, *AD8232 heart rate sensor*, *SCD41-D-R2 CO2 sesnor* and *HAL library* for STM32.
## The project's key goals are:
  * Airflow (detection of breathing through the nose/mouth).
  * Pressure (analysis of the strength and depth of the breath).
  * ECG (analysis of heart rate variability – HRV).
  * CO₂ level (analysis of gas exchange).
  * Design the electrical schematic of the system integrating these sensors with a microcontroller (ESP32 or STM32).
  * Develop the communication method (I2C) between the sensors and the microcontroller.
## To Do:
* finish SCD41-D-R2 Driver
* add CRC checking for MS5837_30BA Driver
