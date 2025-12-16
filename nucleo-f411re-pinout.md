# Nucleo F411RE Master I/O Reference

## Quick Reference - OpenPLC Mapping

### Digital Inputs (Current Config)
| Address | STM32 Pin | Arduino | Connector | Current Use | Notes |
|---------|-----------|---------|-----------|-------------|-------|
| %IX0.0 | PC13 | - | Onboard | User Button B1 | Active LOW, onboard |
| %IX0.1 | PA8 | D7 | CN9-8 | Button Input | Pull-down required |
| %IX0.2 | PB6 | D10 | CN9-3 | Button Input | Pull-down required |
| %IX0.3 | PA12 | - | CN10-12 | Available | Morpho only |
| %IX0.4 | PB3 | D3 | CN9-4 | Available | |
| %IX0.5 | PB4 | D5 | CN9-6 | Available | |
| %IX0.6 | PB5 | D4 | CN9-5 | Available | |
| %IX0.7 | PB8 | D15 | CN5-10 | Available | I2C SCL |
| %IX1.0 | PB9 | D14 | CN5-9 | Available | I2C SDA |

### Digital Outputs (Current Config)
| Address | STM32 Pin | Arduino | Connector | Current Use | Notes |
|---------|-----------|---------|-----------|-------------|-------|
| %QX0.0 | PA5 | D13 | CN5-6 | Onboard LED LD2 | Directly on board |
| %QX0.1 | PB10 | D6 | CN9-7 | LED Output | |
| %QX0.2 | PB12 | - | CN10-16 | LED Output | Morpho only |
| %QX0.3 | PB13 | - | CN10-30 | LED Output | Morpho only |
| %QX0.4 | PB14 | - | CN10-28 | Available | Morpho only |
| %QX0.5 | PB15 | - | CN10-26 | Available | Morpho only |
| %QX0.6 | PC14 | - | CN7-25 | Available | Morpho only |
| %QX0.7 | PC15 | - | CN7-27 | Available | Morpho only |

### Analog Inputs
| Address | STM32 Pin | Arduino | Connector | Current Use | Notes |
|---------|-----------|---------|-----------|-------------|-------|
| %IW0 | PA0 | A0 | CN8-1 | Available | ADC1_IN0 |
| %IW1 | PA1 | A1 | CN8-2 | Available | ADC1_IN1 |
| %IW2 | PA4 | A2 | CN8-3 | Available | ADC1_IN4 |
| %IW3 | PA6 | - | CN5-5 | Available | ADC1_IN6 |
| %IW4 | PA7 | - | CN5-4 | Available | ADC1_IN7 |

### Analog Outputs (PWM)
| Address | STM32 Pin | Arduino | Connector | Current Use | Notes |
|---------|-----------|---------|-----------|-------------|-------|
| %QW0 | PB0 | A3 | CN8-4 | Available | PWM capable |
| %QW1 | PB1 | - | CN10-24 | Available | PWM capable |

---

## Power Pins
| Pin | Connector | Description |
|-----|-----------|-------------|
| +3V3 | CN6-4 | 3.3V output (max 500mA) |
| +5V | CN6-5 | 5V output (from USB) |
| VIN | CN6-8 | External power input (7-12V) |
| GND | CN6-6, CN6-7 | Ground |
| GND | CN5-8, CN9-7 | Ground (Arduino headers) |
| AVDD | CN5-8 | Analog reference voltage |
| AGND | CN10-32 | Analog ground |

---

## Full Connector Pinout

### CN5 (Arduino Right - Top)
| Pin | STM32 | Arduino | Function |
|-----|-------|---------|----------|
| 1 | - | NC | Not connected |
| 2 | - | IOREF | I/O reference |
| 3 | - | RESET | Reset |
| 4 | - | +3V3 | 3.3V power |
| 5 | - | +5V | 5V power |
| 6 | - | GND | Ground |
| 7 | - | GND | Ground |
| 8 | - | VIN | External power |

### CN9 (Arduino Right - Bottom)
| Pin | STM32 | Arduino | Function |
|-----|-------|---------|----------|
| 1 | PA3 | D0 | USART2_RX |
| 2 | PA2 | D1 | USART2_TX |
| 3 | PA10 | D2 | GPIO |
| 4 | PB3 | D3 | PWM/GPIO |
| 5 | PB5 | D4 | GPIO |
| 6 | PB4 | D5 | PWM/GPIO |
| 7 | PB10 | D6 | PWM/GPIO |
| 8 | PA8 | D7 | GPIO |
| 9 | PA9 | D8 | GPIO |
| 10 | PC7 | D9 | PWM/GPIO |

### CN5 (Arduino Right - Continued)
| Pin | STM32 | Arduino | Function |
|-----|-------|---------|----------|
| 1 | PB6 | D10 | PWM/SPI_CS |
| 2 | PA7 | D11 | PWM/SPI_MOSI |
| 3 | PA6 | D12 | SPI_MISO |
| 4 | PA5 | D13 | SPI_SCK/LED LD2 |
| 5 | - | GND | Ground |
| 6 | PA5 | D13 | LED LD2 |
| 7 | - | AVDD | Analog VDD |
| 8 | - | GND | Ground |
| 9 | PB9 | D14 | I2C_SDA |
| 10 | PB8 | D15 | I2C_SCL |

### CN8 (Arduino Left - Analog)
| Pin | STM32 | Arduino | Function |
|-----|-------|---------|----------|
| 1 | PA0 | A0 | ADC |
| 2 | PA1 | A1 | ADC |
| 3 | PA4 | A2 | ADC |
| 4 | PB0 | A3 | ADC |
| 5 | PC1 | A4 | ADC |
| 6 | PC0 | A5 | ADC |

### CN10 (Morpho Right)
| Pin | STM32 | Pin | STM32 |
|-----|-------|-----|-------|
| 1 | - | 2 | PC8 |
| 3 | - | 4 | PC6 |
| 5 | - | 6 | PC5 |
| 7 | U5V | 8 | - |
| 9 | - | 10 | - |
| 11 | PA12 | 12 | PA11 |
| 13 | PB12 | 14 | - |
| 15 | PB12 | 16 | PB12 |
| 17 | - | 18 | - |
| 19 | GND | 20 | PB2 |
| 21 | PB1 | 22 | PB1 |
| 23 | PB15 | 24 | PB15 |
| 25 | PB14 | 26 | PB14 |
| 27 | PB13 | 28 | PB13 |
| 29 | - | 30 | PB13 |
| 31 | AGND | 32 | PC4 |
| 33 | - | 34 | - |
| 35 | - | 36 | - |
| 37 | - | 38 | - |

### CN7 (Morpho Left)
| Pin | STM32 | Pin | STM32 |
|-----|-------|-----|-------|
| 1 | PC10 | 2 | PC11 |
| 3 | PC12 | 4 | PD2 |
| 5 | VDD | 6 | E5V |
| 7 | BOOT0 | 8 | GND |
| 9 | - | 10 | - |
| 11 | - | 12 | IOREF |
| 13 | PA13 | 14 | RESET |
| 15 | PA14 | 16 | +3V3 |
| 17 | PA15 | 18 | +5V |
| 19 | GND | 20 | GND |
| 21 | PB7 | 22 | GND |
| 23 | PC13 | 24 | VIN |
| 25 | PC14 | 26 | - |
| 27 | PC15 | 28 | PA0 |
| 29 | PH0 | 30 | PA1 |
| 31 | PH1 | 32 | PA4 |
| 33 | VBAT | 34 | PB0 |
| 35 | PC2 | 36 | PC1 |
| 37 | PC3 | 38 | PC0 |

---

## OpenPLC I/O Configuration String

Copy these into OpenPLC I/O Config:

**Digital Inputs:**
```
PC13, PA8, PB6, PA12, PB3, PB4, PB5, PB8, PB9
```

**Digital Outputs:**
```
PA5, PB10, PB12, PB13, PB14, PB15, PC14, PC15
```

**Analog Inputs:**
```
PA0, PA1, PA4, PA6, PA7
```

**Analog Outputs:**
```
PB0, PB1
```

---

## Project Pin Assignments

### P1: Button LED
| Function | Address | Pin | Arduino |
|----------|---------|-----|---------|
| Button B1 | %IX0.0 | PC13 | Onboard |
| LED LD2 | %QX0.0 | PA5 | D13/Onboard |

### P2: Latch Circuit
| Function | Address | Pin | Arduino |
|----------|---------|-----|---------|
| START Button | %IX0.1 | PA8 | D7 |
| STOP Button | %IX0.2 | PB6 | D10 |
| LED | %QX0.1 | PB10 | D6 |

### P3: Timers
| Function | Address | Pin | Arduino |
|----------|---------|-----|---------|
| Button | %IX0.1 | PA8 | D7 |
| TON LED | %QX0.1 | PB10 | D6 |
| TOF LED | %QX0.2 | PB12 | Morpho |
| TP LED | %QX0.3 | PB13 | Morpho |

### P4: Counters (Planned)
| Function | Address | Pin | Arduino |
|----------|---------|-----|---------|
| Count Button | %IX0.1 | PA8 | D7 |
| Reset Button | %IX0.2 | PB6 | D10 |
| Count LED | %QX0.1 | PB10 | D6 |

### P5: Analog I/O (Planned)
| Function | Address | Pin | Arduino |
|----------|---------|-----|---------|
| Temp Sensor | %IW0 | PA0 | A0 |
| Potentiometer | %IW1 | PA1 | A1 |
| PWM Output | %QW0 | PB0 | A3 |

---

## Notes

1. **Morpho vs Arduino Headers:** Not all pins have Arduino labels. PB12, PB13, etc. are only on morpho connectors.

2. **Pull-down Resistors:** External buttons need 10kΩ pull-down to GND. Connect button between pin and 3.3V.

3. **LED Wiring:** Anode (long leg) → output pin, Cathode (short leg) → resistor (220-330Ω) → GND.

4. **Onboard Resources:**
   - B1 (Blue button): PC13, active LOW
   - LD2 (Green LED): PA5, active HIGH

5. **Clock Issue:** Using Blackpill profile causes ~3x timer slowdown. Adjust presets accordingly.

6. **Reserved Pins:** PA2/PA3 are used for USART2 (ST-Link virtual COM port). Avoid using these.
