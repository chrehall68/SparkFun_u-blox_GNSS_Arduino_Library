/*
  Get the high position accuracy of the RTK enhanced position from HPPOSECEF
  By: Nathan Seidle
  SparkFun Electronics
  Date: January 3rd, 2019
  License: MIT. See license file for more information but you can
  basically do whatever you want with this code.

  This example shows how to inspect the accuracy of the high-precision
  positional solution.

  Feel like supporting open source hardware?
  Buy a board from SparkFun!
  ZED-F9P RTK2: https://www.sparkfun.com/products/15136
  NEO-M8P RTK: https://www.sparkfun.com/products/15005
  SAM-M8Q: https://www.sparkfun.com/products/15106

  Hardware Connections:
  Plug a Qwiic cable into the GNSS and a BlackBoard
  If you don't have a platform with a Qwiic connection use the SparkFun Qwiic Breadboard Jumper (https://www.sparkfun.com/products/14425)
  Open the serial monitor at 115200 baud to see the output
*/

#include <ublox/serialstream.h>
#include <ublox/SparkFun_u-blox_GNSS_Arduino_Library.h> //http://librarymanager/All#SparkFun_u-blox_GNSS
#include <iostream>

using namespace std;

int main()
{
  SerialStream serialStream("/dev/ttyACM0", 115200);
  SFE_UBLOX_GNSS myGNSS;
  cout << "SparkFun u-blox Example" << endl;

  if (myGNSS.begin(serialStream) == false) // Connect to the u-blox module using Wire port
  {
    cout << "u-blox GNSS not detected at default I2C address. Please check wiring. Exiting." << endl;
    exit(1);
  }

  myGNSS.enableDebugging();
  myGNSS.setUART1Output(COM_TYPE_UBX); // Set the I2C port to output UBX only (turn off NMEA noise)
  // myGNSS.saveConfiguration(); //Optional: Save the current settings to flash and BBR

  while (1)
  {
    // Query module only every second. Doing it more often will just cause I2C traffic.
    // The module only responds when a new position is available
    long latitude = myGNSS.getLatitude();
    cout << "Lat: ";
    cout << latitude;

    long longitude = myGNSS.getLongitude();
    cout << (" Long: ");
    cout << longitude;
    cout << (" (degrees * 10^-7)");

    long altitude = myGNSS.getAltitude();
    cout << " Alt: ";
    cout << altitude;
    cout << " (mm)";

    long accuracy = myGNSS.getPositionAccuracy();
    cout << (" 3D Positional Accuracy: ");
    cout << (accuracy);
    cout << (" (mm)") << endl;
  }
}
