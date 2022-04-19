/* Pressure measurement by Arduino nano 33 ble sense
*  mIv 10/02/2021 
*  fast - small delay, no serial
* mbar_arduino_nano3_stat.phyphox  mIv 30/08/2021
 */

#include <phyphoxBle.h>
char board_name[] = "Mobile"; 
// to change the name displayed by the board using BLE: 
// no space and no special character

#include <Arduino_LPS22HB.h> //ArduinoLPS22HB library
// Absolute pressure range: 260 to 1260 hPa 

void setup() {
  
  // Serial.begin(9600);

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  
  if (!BARO.begin()) {
    // Serial.println("Failed to initialize pressure sensor!");
    digitalWrite(LED_BUILTIN, HIGH); 
    while (1);
  }
 
  // Serial.println("Pressure (hPa) = ");

  PhyphoxBLE::start(board_name);                //Start the BLE server
}

void loop() {

  float pressure = BARO.readPressure()*10; // kPa -> hPa

  // Serial.println(pressure);

  PhyphoxBLE::write(pressure);    //Send pressure value (hPa) to phyphox
  // delay(100); // 100 ms as the fastest pressure of SensorTag
  delay(50); // max ODR of Arduino presure sensor (13.3333)
}
