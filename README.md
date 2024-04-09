# MLX90393_Teensy4_0
1 Sensor Runs at 300Hz. It should run at the same speed as Arduino (Check the Pin diagram for I2C).
Replace the Adafruit_MLX90393 .cpp and .h files in Documents\Arduino\libraries\Adafruit_MLX90393 folder.

This program uses Adafruit Library, Teensy4.0, Arduino IDE, MLX90393 (Magnetometer 5-50mT Range)

The following links may help
https://forum.pjrc.com/index.php?threads/just-getting-started-with-teensy-looking-for-background-docs.70256/#post-305996

Pin connection
MLX90393 - Teensy4.0
(Red Wire)    Vcc-3.3V
(Black)       Gnd-Gnd
(Yellow)      SCL - Pin19
(Blue)        SDA - Pin18

For Two sensors its runs at 150Hz, I2C as the delay is sequential.

Default I2C address for this board - 0x18 (https://www.adafruit.com/product/4022)
Connect A0 pin to 3.3V to get a different I2C address (0X19)

