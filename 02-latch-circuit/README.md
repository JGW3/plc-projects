# 02 - Latch Circuit (Seal-In)

Industrial start/stop circuit using two external buttons and an LED. This is the foundational control pattern used for motor starters, pumps, and conveyors in factories.

## What It Does
- Press START → LED turns ON and stays on
- Release START → LED remains ON (latched)
- Press STOP → LED turns OFF

## Hardware
- STM32 Nucleo F411RE
- 2x pushbuttons (external)
- 1x LED with 220Ω resistor
- 2x 10kΩ pull-down resistors
- Breadboard and jumper wires

## Wiring

| Component | Nucleo Pin | Arduino Label | Address |
|-----------|------------|---------------|---------|
| START button | PA8 | D7 | %IX0.1 |
| STOP button | PB6 | D10 | %IX0.2 |
| LED (+) | PB10 | D6 | %QX0.1 |
| Pull-down resistors | D7 → GND, D10 → GND | | |
| LED resistor | LED(-) → 220Ω → GND | | |
| Buttons | One leg → 3.3V, other leg → input pin | | |

## Ladder Logic
![Ladder Logic](p2_ladder_logic.png)
```
    +---| START |---+
    |               |
----+               +------|/ STOP |------( LED )
    |               |
    +----| LED |----+
```

The LED contact in parallel with START creates the "seal-in" - once energized, the LED output feeds back to keep itself on until STOP breaks the circuit.

## I/O Configuration
```
Digital Inputs:  PC13, PA8, PB6, PA12, PB3, PB4, PB5, PB8, PB9
Digital Outputs: PA5, PB10, PB12, PB13, PB14, PB15, PC14, PC15
```

## Lessons Learned

1. **Pin mapping confusion**: Arduino labels (D6, D7) don't match STM32 names (PB10, PA8). Had to cross-reference the Nucleo pinout diagram.

2. **Floating inputs**: Without pull-down resistors, inputs picked up electrical noise and the LED flickered randomly. Added 10kΩ pull-downs from each input pin to GND.

3. **Button wiring**: Initially wired buttons to GND (active-low), but internal pull-ups weren't enabled. Rewired to 3.3V with external pull-downs for clean HIGH when pressed.

4. **No live debugging**: OpenPLC's bare-metal upload doesn't support live debugging like industrial PLCs. Had to troubleshoot with multimeter and logic deduction.

## Industrial Application

This exact circuit pattern is used for:
- Motor start/stop stations
- Conveyor belt controls
- Pump controls
- Any equipment needing maintained contact (latch) behavior

The STOP contact is wired "normally closed" (negated) so that a broken wire fails safe - equipment stops rather than runs uncontrolled.
