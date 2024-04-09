#include "Adafruit_MLX90393.h"

Adafruit_MLX90393 sensor_Main = Adafruit_MLX90393();
Adafruit_MLX90393 sensor_Ref = Adafruit_MLX90393();
#define MLX90393_CS 10

void setup(void)
{
  Serial.begin(115200);

  /* Wait for serial on USB platforms. */
  while (!Serial) {
      delay(10);
  }

  Serial.println("Starting Adafruit MLX90393 Demo");

  if (! sensor_Main.begin_I2C(0x18)) {          // hardware I2C mode, can pass in address & alt Wire
  //if (! sensor.begin_SPI(MLX90393_CS)) {  // hardware SPI mode
    Serial.println("No sensor found ... check your wiring?");
    while (1) { delay(10); }
  }
  Serial.println("Found a MLX90393 sensor for Main Task");

  if (! sensor_Ref.begin_I2C(0x19)) {          // hardware I2C mode, can pass in address & alt Wire
  //if (! sensor.begin_SPI(MLX90393_CS)) {  // hardware SPI mode
    Serial.println("No sensor found ... check your wiring?");
    while (1) { delay(10); }
  }
  Serial.println("Found a MLX90393 sensor for Reference Task");

  sensor_Main.setGain(MLX90393_GAIN_1X);
  // You can check the gain too
  Serial.print("Gain set to: ");
  switch (sensor_Main.getGain()) {
    case MLX90393_GAIN_1X: Serial.println("1 x"); break;
    case MLX90393_GAIN_1_33X: Serial.println("1.33 x"); break;
    case MLX90393_GAIN_1_67X: Serial.println("1.67 x"); break;
    case MLX90393_GAIN_2X: Serial.println("2 x"); break;
    case MLX90393_GAIN_2_5X: Serial.println("2.5 x"); break;
    case MLX90393_GAIN_3X: Serial.println("3 x"); break;
    case MLX90393_GAIN_4X: Serial.println("4 x"); break;
    case MLX90393_GAIN_5X: Serial.println("5 x"); break;
  }

  // Set resolution, per axis. Aim for sensitivity of ~0.3 for all axes.
  sensor_Main.setResolution(MLX90393_X, MLX90393_RES_17);
  sensor_Main.setResolution(MLX90393_Y, MLX90393_RES_17);
  sensor_Main.setResolution(MLX90393_Z, MLX90393_RES_16);

  // Set oversampling
  sensor_Main.setOversampling(MLX90393_OSR_0);

  // Set digital filtering
  sensor_Main.setFilter(MLX90393_FILTER_2);

  // ##################################
  sensor_Ref.setGain(MLX90393_GAIN_1X);
  // You can check the gain too
  Serial.print("Gain set to: ");
  switch (sensor_Ref.getGain()) {
    case MLX90393_GAIN_1X: Serial.println("1 x"); break;
    case MLX90393_GAIN_1_33X: Serial.println("1.33 x"); break;
    case MLX90393_GAIN_1_67X: Serial.println("1.67 x"); break;
    case MLX90393_GAIN_2X: Serial.println("2 x"); break;
    case MLX90393_GAIN_2_5X: Serial.println("2.5 x"); break;
    case MLX90393_GAIN_3X: Serial.println("3 x"); break;
    case MLX90393_GAIN_4X: Serial.println("4 x"); break;
    case MLX90393_GAIN_5X: Serial.println("5 x"); break;
  }

  // Set resolution, per axis. Aim for sensitivity of ~0.3 for all axes.
  sensor_Ref.setResolution(MLX90393_X, MLX90393_RES_17);
  sensor_Ref.setResolution(MLX90393_Y, MLX90393_RES_17);
  sensor_Ref.setResolution(MLX90393_Z, MLX90393_RES_16);

  // Set oversampling
  sensor_Ref.setOversampling(MLX90393_OSR_0);

  // Set digital filtering
  sensor_Ref.setFilter(MLX90393_FILTER_2);
}

void loop(void) {
  float x1, y1, z1, x2, y2, z2;
  if (sensor_Main.readData(&x1, &y1, &z1) && sensor_Ref.readData(&x2, &y2, &z2)) {
      Serial.print(x1, 3);
      Serial.print(",");
      Serial.print(x2, 3);
      Serial.print(",");
      Serial.print(y1, 3);
      Serial.print(",");
      Serial.print(y2, 3);
      Serial.print(",");
      Serial.print(z1, 3);
      Serial.print(",");
      Serial.println(z2, 3);
  } else {
      Serial.println("Unable to read XYZ data from the Main sensor or ref sensor.");
  }
/*
  if (sensor_Ref.readData(&x2, &y2, &z2)) {
      Serial.print(x2, 3);
      Serial.print(",");
      Serial.print(y2, 3);
      Serial.print(",");
      Serial.println(z2, 3);
  } else {
      Serial.println("Unable to read XYZ data from the Reference sensor.");
  }*/
}
