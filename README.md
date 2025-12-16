# PLC Projects

5-week deep dive into PLC programming focused on building automation and HVAC controls.

## Tools
| Tool | Purpose |
|------|---------|
| OpenPLC Editor | Ladder logic on real hardware (Nucleo F411RE) |
| CODESYS | Industry-standard simulation and debugging |
| STM32CubeProgrammer | Firmware uploads |

## Hardware
- STM32 Nucleo F411RE
- Buttons, LEDs, resistors, temp sensors
- [Pin Mapping Reference](Nucleo_F411RE_Pinout.xlsx)

## Projects

| # | Project | Description |
|---|---------|-------------|
| 01 | Button LED | Basic digital I/O |
| 02 | Latch Circuit | Start/stop seal-in circuit |
| 03 | Timers | TON, TOF, TP timer instructions |
| 04 | Counters | CTU, CTD, CTUD counter instructions |
| 05 | Analog I/O | Temp sensing and proportional control |
| 06 | Chiller Plant | Capstone - multi-stage HVAC system |

## What I'm Learning
- IEC 61131-3 ladder logic
- Real hardware wiring and troubleshooting
- Industrial control patterns
- Industry-standard software (CODESYS)

## Why Two Platforms
OpenPLC + Nucleo gives me hands-on hardware experience - actual wiring, real I/O, debugging with a multimeter. CODESYS adds industry familiarity since it's what many commercial PLCs run on. Both use the same IEC 61131-3 standards.