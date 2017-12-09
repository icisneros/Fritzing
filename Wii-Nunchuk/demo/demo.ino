#include <Wire.h>
#include "Nunchuk.h"


// Prevents false positives (sometimes 
// joystick gets stuck at small numbers
// around 0)
int16_t j_thresh = 5;


void setup() {

    Serial.begin(9600);
    Wire.begin();
    // nunchuk_init_power(); // A1 and A2 is power supply
    nunchuk_init();
}

void loop() {

  // Original
//    if (nunchuk_read()) {
//        // Work with nunchuk_data
//        nunchuk_print();
//    }
//    delay(10);



    if (nunchuk_read()) {
        // Work with nunchuk_data
        int16_t jx = nunchuk_joystickX();
        int16_t jy = nunchuk_joystickY();

//        payload = (jx,jy);
        int16_t payload = jx + jy;

        if (abs(jx) > j_thresh  || abs(jy) > j_thresh)
        {
          // write out the payload
          Serial.print(payload, DEC);
          Serial.print("\n");
        }
    }
    delay(10);    
    Serial.print("nothing\n");
} 
