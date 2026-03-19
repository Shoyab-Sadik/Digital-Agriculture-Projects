# Digital Agriculture System with Arduino & ESP32  

**Author:** M. Shoyab Sadik  
**Organization:** Pico Robotics & MSS ElectroTech  
**Contact:** 01575317604  

---

## Overview  

This project is a **Digital Agriculture System** designed to monitor soil moisture, rain levels, temperature, and humidity. It automatically controls a water pump based on soil moisture levels and triggers a buzzer alert if heavy rain is detected. Data is also displayed on a 20x4 I2C LCD.  

---

## Features  

- Measures **soil moisture** using an analog sensor.  
- Detects **rain intensity** with an analog rain sensor.  
- Measures **temperature and humidity** using a DHT11 sensor.  
- **Automatic pump control** for irrigation.  
- **Buzzer alerts** for dry soil or high rain probability.  
- Displays all data on a **20x4 LCD**.  
- Serial output for real-time monitoring.  

---

## Hardware Components  

- Arduino / ESP32 board  
- DHT11 Temperature & Humidity sensor  
- Soil Moisture Sensor  
- Rain Sensor  
- 20x4 I2C LCD  
- Water Pump (relay-controlled)  
- Buzzer  
- Connecting wires, breadboard, and power supply  

---

## Wiring  

| Component       | Pin Connection           |
|-----------------|------------------------|
| Soil Sensor     | A2                     |
| Rain Sensor     | A3                     |
| Pump            | D3                     |
| Buzzer          | D4                     |
| DHT11           | D2                     |
| LCD (I2C)       | SDA, SCL (0x27 address)|

---

## Code Overview  

- **setup()**  
  - Initializes pins, sensors, serial communication, and LCD.  
  - Displays welcome messages.  

- **loop()**  
  - Continuously reads sensor data and displays on the LCD.  
  - Controls pump and buzzer based on thresholds.  

- **Key Functions:**  
  - `welcome()` → Displays initial welcome message on LCD.  
  - `start()` → Shows the “Digital Agriculture” start screen.  
  - `datas()` → Reads sensors, calculates values, controls pump & buzzer, updates LCD.  
  - `buzzer_sound()` → Buzzer pattern for high rain alert.  
  - `soil_buzzer()` → Buzzer pattern for dry soil alert.  

---

## Thresholds  

- **Soil Moisture**  
  - 0–5% → Soil is very wet → Pump OFF  
  - 5–50% → Soil is dry → Pump ON + soil buzzer  

- **Rain Sensor**  
  - >60% → Buzzer alert for heavy rain  

---

## How to Use  

1. Connect all sensors, pump, and buzzer to the Arduino according to the wiring table.  
2. Upload the code to your Arduino board.  
3. Open the Serial Monitor at 9600 baud to see real-time readings.  
4. Observe the LCD for current temperature, humidity, soil moisture, and rain values.  
5. The pump will automatically water the soil when moisture is low, and buzzer alerts will trigger for rain and dry soil conditions.  

---

## Notes  

- Ensure that the **I2C address of LCD (0x27)** matches your hardware.  
- Adjust soil moisture and rain thresholds based on your environment and crops.  
- The buzzer patterns can be customized by modifying `buzzer_sound()` and `soil_buzzer()` functions.  

---

## Author  

**M. Shoyab Sadik** – Pico Robotics & MSS ElectroTech  
