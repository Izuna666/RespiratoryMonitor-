# RespiratoryMonitor
## This project aims to Design and implement a system for monitoring respiratory parameters using *STM32 microcontroler*, *MS5837_30BA pressure and temperature sensor*, *BH1792GLC heart rate sensor* and *XENSIVTM_PAS_CO2_1.5 CO2 sesnor*.
## The project's key goals are:
  * Airflow (detection of breathing through the nose/mouth).
  * Pressure (analysis of the strength and depth of the breath).
  * ECG (analysis of heart rate variability – HRV).
  * CO₂ level (analysis of gas exchange).
  * Design the electrical schematic of the system integrating these sensors with a microcontroller (ESP32 or STM32).
  * Develop the communication method (I2C, UART, SPI) between the sensors and the microcontroller.
  * Design a low-pass filter to eliminate interference in the pressure signal.
  * Create a simulation in LTspice / Proteus and present the results.
