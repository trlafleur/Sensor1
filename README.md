# Sensor1
This is a PCB for a My-sensor network with a Moteino, RFM69 radio, Includes 2 relays, 24V AC power, Si7021 and MCP9800 and analog interface..

This is a prototype, not all function have been tested as of 14 June 2015

Sensor 1

Rev 2a

This device was designed to be a remote sensor in a MySensor or LowPower network, but can be adapted to any network that uses RFM69W(H) radios and a Moteino ATmega328 processor.

Basic functions:

1)	Carrier for a Moteino processor with a RFM69W(H) radio

2)	Power supply 7 to 32V AC or DC

3)	Condition pulse counter with 1st order pulse filtering

4)	2 Relay outputs, that can be converted to FET output with a jumper

5)	3 Analog input with scaling and filtering, can be converted to digital I/O

6)	4 LED’s for device status

7)	An MCP9800 temperature sensor, and or 

8)	An Si7021 temperature and humidity sensor

9)	Designed to fit in a Hammond 1554C water resistant case


The power supply is designed to be run from a standard irrigation 24V AC power source, but can be run from 7 to 32V AC or DC. Input power is fused with a PTC and then connected to a bridge rectifier, filtered with a large capacitor and then connected to a Pololu D24V6F5 ($6), 5V 600ma switching power supply or a 300ma version, D24V3F5 ($4), or there is also space to use a TI TL720M05 three terminal regulator in a TO252 package.

The pulse input provides a 1st order filtering of pulses from mechanical (reed) switch as found in many water meters. Switch de-bouncing-filtering is done by R7, D3, R9, C7 and U1. The 74AHC14 inverter has a Schmitt trigger input to help with noise immunity and will provide high voltage isolation on the input. (See the reference below on how it works.) 

The output of the 74ACH14 is connected to the T1, 16bit counter on the ATmega328 processor. This can be used with simple code to count pulses without the need for interrupts. This method also continues to operator during processor sleep.

This input can be converted to a conventional, input circuitry by selection components. IE: to use a hall effect sensor, you could remove R7, D3, C7 and replace R9 with a zero ohm resistor as needed.

http://www.ganssle.com/debouncing.htm

Relays are driven by a N-FET from the Moteino I/O pins. Diodes across the relay coils are for back EMF. An optional jumper connected across pins 6 and 7 of the relay bring the FET outputs to the “C” pin on J3 for direct FET connection.

On the analog inputs, two input resistors and the capacitor do analog input, filtering and scaling. Again, these components can be replaced as needed to provide a direct connection to the Moteino as analog or digital I/O pin.

If you don’t need all of the input pins on J2, you can stuff smaller connectors on the board.

Options for an MCP9800 temperature and/or a Si7021 temperature-humidity sensor. The I2C module of the processor controls these devices.


