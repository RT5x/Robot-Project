
#include "Arduino.h"
#include "BTHC05.h"
#include "Joystick.h"
#include "Servo.h"
#include "StepperMotor.h"

// Pins
#define BTHC05_PIN_TXD	11
#define BTHC05_PIN_RXD	10
#define JOYSTICKSF_PIN_SEL	2
#define JOYSTICKSF_PIN_VERT	A4
#define JOYSTICKSF_PIN_HORZ	A3
#define SERVO360MICRO1_1_PIN_SIG	3
#define SERVO360MICRO2_2_PIN_SIG	4
#define SERVO360MICRO3_3_PIN_SIG	5
#define STEPPERGEARED_PIN_STEP	7
#define STEPPERGEARED_PIN_DIR	6

#define stepperGearedDelayTime  1000

BTHC05 bthc05(BTHC05_PIN_RXD,BTHC05_PIN_TXD);
Joystick joystickSF(JOYSTICKSF_PIN_VERT,JOYSTICKSF_PIN_HORZ,JOYSTICKSF_PIN_SEL);
Servo servo360Micro1_1;
Servo servo360Micro2_2;
Servo servo360Micro3_3;
StepperMotor stepperGeared(STEPPERGEARED_PIN_STEP,STEPPERGEARED_PIN_DIR);


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    bthc05.begin(9600);
    //This example uses HC-05 Bluetooth to communicate with an Android device.
    //Download bluetooth terminal from google play store, https://play.google.com/store/apps/details?id=Qwerty.BluetoothTerminal&hl=en
    //Pair and connect to 'HC-05', the default password for connection is '1234'.
    //You should see this message from your arduino on your android device
    bthc05.println("Bluetooth On....");
    // enable the stepper motor, use .disable() to disable the motor
    stepperGeared.enable();
    // set stepper motor speed by changing the delay value, the higher the delay the slower the motor will turn
    stepperGeared.setStepDelay(stepperGearedDelayTime);
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1') {
    // HC - 05 Bluetooth Serial Module - Test Code
    String bthc05Str = "";
    //Receive String from bluetooth device
    if (bthc05.available())
    {
    //Read a complete line from bluetooth terminal
    bthc05Str = bthc05.readStringUntil('\n');
    // Print raw data to serial monitor
    Serial.print("BT Raw Data: ");
    Serial.println(bthc05Str);
    }
    //Send sensor data to Bluetooth device  
    bthc05.println("PUT YOUR SENSOR DATA HERE");
    }
    else if(menuOption == '2') {
    // Thumb Joystick - Test Code
    // Read Joystick X,Y axis and press
    int joystickSFX =  joystickSF.getX();
    int joystickSFY =  joystickSF.getY();
    int joystickSFSW =  joystickSF.getSW();
    Serial.print(F("X: ")); Serial.print(joystickSFX);
    Serial.print(F("\tY: ")); Serial.print(joystickSFY);
    Serial.print(F("\tSW: ")); Serial.println(joystickSFSW);

    }
    else if(menuOption == '3') {
    // Continuous Rotation Micro Servo - FS90R #1 - Test Code
    // The servo will rotate CW in full speed, CCW in full speed, and will stop  with an interval of 2000 milliseconds (2 seconds) 
    servo360Micro1_1.attach(SERVO360MICRO1_1_PIN_SIG);         // 1. attach the servo to correct pin to control it.
    servo360Micro1_1.write(180);  // 2. turns servo CW in full speed. change the value in the brackets (180) to change the speed. As these numbers move closer to 90, the servo will move slower in that direction.
    delay(2000);                              // 3. waits 2000 milliseconds (2 sec). change the value in the brackets (2000) for a longer or shorter delay in milliseconds.
    servo360Micro1_1.write(0);    // 4. turns servo CCW in full speed. change the value in the brackets (0) to change the speed. As these numbers move closer to 90, the servo will move slower in that direction.
    delay(2000);                              // 5. waits 2000 milliseconds (2 sec). change the value in the brackets (2000) for a longer or shorter delay in milliseconds.
    servo360Micro1_1.write(90);    // 6. sending 90 stops the servo 
    delay(2000);                              // 7. waits 2000 milliseconds (2 sec). change the value in the brackets (2000) for a longer or shorter delay in milliseconds.
    servo360Micro1_1.detach();                    // 8. release the servo to conserve power. When detached the servo will NOT hold it's position under stress.
    }
    else if(menuOption == '4') {
    // Continuous Rotation Micro Servo - FS90R #2 - Test Code
    // The servo will rotate CW in full speed, CCW in full speed, and will stop  with an interval of 2000 milliseconds (2 seconds) 
    servo360Micro2_2.attach(SERVO360MICRO2_2_PIN_SIG);         // 1. attach the servo to correct pin to control it.
    servo360Micro2_2.write(180);  // 2. turns servo CW in full speed. change the value in the brackets (180) to change the speed. As these numbers move closer to 90, the servo will move slower in that direction.
    delay(2000);                              // 3. waits 2000 milliseconds (2 sec). change the value in the brackets (2000) for a longer or shorter delay in milliseconds.
    servo360Micro2_2.write(0);    // 4. turns servo CCW in full speed. change the value in the brackets (0) to change the speed. As these numbers move closer to 90, the servo will move slower in that direction.
    delay(2000);                              // 5. waits 2000 milliseconds (2 sec). change the value in the brackets (2000) for a longer or shorter delay in milliseconds.
    servo360Micro2_2.write(90);    // 6. sending 90 stops the servo 
    delay(2000);                              // 7. waits 2000 milliseconds (2 sec). change the value in the brackets (2000) for a longer or shorter delay in milliseconds.
    servo360Micro2_2.detach();                    // 8. release the servo to conserve power. When detached the servo will NOT hold it's position under stress.
    }
    else if(menuOption == '5') {
    // Continuous Rotation Micro Servo - FS90R #3 - Test Code
    // The servo will rotate CW in full speed, CCW in full speed, and will stop  with an interval of 2000 milliseconds (2 seconds) 
    servo360Micro3_3.attach(SERVO360MICRO3_3_PIN_SIG);         // 1. attach the servo to correct pin to control it.
    servo360Micro3_3.write(180);  // 2. turns servo CW in full speed. change the value in the brackets (180) to change the speed. As these numbers move closer to 90, the servo will move slower in that direction.
    delay(2000);                              // 3. waits 2000 milliseconds (2 sec). change the value in the brackets (2000) for a longer or shorter delay in milliseconds.
    servo360Micro3_3.write(0);    // 4. turns servo CCW in full speed. change the value in the brackets (0) to change the speed. As these numbers move closer to 90, the servo will move slower in that direction.
    delay(2000);                              // 5. waits 2000 milliseconds (2 sec). change the value in the brackets (2000) for a longer or shorter delay in milliseconds.
    servo360Micro3_3.write(90);    // 6. sending 90 stops the servo 
    delay(2000);                              // 7. waits 2000 milliseconds (2 sec). change the value in the brackets (2000) for a longer or shorter delay in milliseconds.
    servo360Micro3_3.detach();                    // 8. release the servo to conserve power. When detached the servo will NOT hold it's position under stress.
    }
    else if(menuOption == '6') {
    // Small Reduction Stepper Motor with EasyDriver - 5VDC 32-Step 1/16 Gearing - Test Code
    // the higher the time value the slower the motor will run
    stepperGeared.step(1, 1000);  // move motor 1000 steps in one direction
    delay(1000);            // short stop
    stepperGeared.step(0, 1000);  // move motor 1000 steps in the other dirction
    delay(1000);            //short stop
    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) HC - 05 Bluetooth Serial Module"));
    Serial.println(F("(2) Thumb Joystick"));
    Serial.println(F("(3) Continuous Rotation Micro Servo - FS90R #1"));
    Serial.println(F("(4) Continuous Rotation Micro Servo - FS90R #2"));
    Serial.println(F("(5) Continuous Rotation Micro Servo - FS90R #3"));
    Serial.println(F("(6) Small Reduction Stepper Motor with EasyDriver - 5VDC 32-Step 1/16 Gearing"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
    			Serial.println(F("Now Testing HC - 05 Bluetooth Serial Module"));
    		else if(c == '2') 
    			Serial.println(F("Now Testing Thumb Joystick"));
    		else if(c == '3') 
    			Serial.println(F("Now Testing Continuous Rotation Micro Servo - FS90R #1"));
    		else if(c == '4') 
    			Serial.println(F("Now Testing Continuous Rotation Micro Servo - FS90R #2"));
    		else if(c == '5') 
    			Serial.println(F("Now Testing Continuous Rotation Micro Servo - FS90R #3"));
    		else if(c == '6') 
    			Serial.println(F("Now Testing Small Reduction Stepper Motor with EasyDriver - 5VDC 32-Step 1/16 Gearing"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}
