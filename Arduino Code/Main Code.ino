#include "Arduino.h"
#include "BTHC05.h"
#include "Joystick.h"
#include "LED.h"
#include "Button.h"
#include "Servo.h"


// Pin Definitions
#define BTHC05_PIN_TXD	11
#define BTHC05_PIN_RXD	10
#define JOYSTICK_PIN_SW	2
#define JOYSTICK_PIN_VRX	A3
#define JOYSTICK_PIN_VRY	A4
#define LEDB_PIN_VIN	5
#define PUSHBUTTON_PIN_2	3
#define SERVO360MICRO_PIN_SIG	4
#define SERVOMD1_1_PIN_SIG	6
#define SERVOMD2_2_PIN_SIG	7
#define SERVOMD3_3_PIN_SIG	8



// Global variables and defines
const int servoMD1_1RestPosition   = 20;  //Starting position
const int servoMD1_1TargetPosition = 150; //Position when event is detected
const int servoMD2_2RestPosition   = 20;  //Starting position
const int servoMD2_2TargetPosition = 150; //Position when event is detected
const int servoMD3_3RestPosition   = 20;  //Starting position
const int servoMD3_3TargetPosition = 150; //Position when event is detected
// object initialization
BTHC05 bthc05(BTHC05_PIN_RXD,BTHC05_PIN_TXD);
Joystick joystick(JOYSTICK_PIN_VRX,JOYSTICK_PIN_VRY,JOYSTICK_PIN_SW);
LED ledB(LEDB_PIN_VIN);
Button pushButton(PUSHBUTTON_PIN_2);
Servo servo360Micro;
Servo servoMD1_1;
Servo servoMD2_2;
Servo servoMD3_3;


const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;


void setup() 
{

    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    bthc05.begin(9600);

    bthc05.println("Bluetooth On....");
    pushButton.init();
    servoMD1_1.attach(SERVOMD1_1_PIN_SIG);
    servoMD1_1.write(servoMD1_1RestPosition);
    delay(100);
    servoMD1_1.detach();
    servoMD2_2.attach(SERVOMD2_2_PIN_SIG);
    servoMD2_2.write(servoMD2_2RestPosition);
    delay(100);
    servoMD2_2.detach();
    servoMD3_3.attach(SERVOMD3_3_PIN_SIG);
    servoMD3_3.write(servoMD3_3RestPosition);
    delay(100);
    servoMD3_3.detach();
    menuOption = menu();
    
}


void loop() 
{
    
    
    if(menuOption == '1') {
 
    String bthc05Str = "";

    if (bthc05.available())
    {


    Serial.print("BT Raw Data: ");
    Serial.println(bthc05Str);
    }
    //Send sensor data to Bluetooth device  
    bthc05.println("PUT YOUR SENSOR DATA HERE");
    }
    else if(menuOption == '2') {

    int joystickX =  joystick.getX();
    int joystickY =  joystick.getY();
    int joystickSW =  joystick.getSW();
    Serial.print(F("X: ")); Serial.print(joystickX);
    Serial.print(F("\tY: ")); Serial.print(joystickY);
    Serial.print(F("\tSW: ")); Serial.println(joystickSW);

    }
    else if(menuOption == '3') {

    for(int i=255 ; i> 0 ; i -= 5)
    {
        ledB.dim(i);                      // 1. Dim Led 
        delay(15);                               // 2. waits 5 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    }                                          
    ledB.off();                        // 3. turns off
    }
    else if(menuOption == '4') {

    bool pushButtonVal = pushButton.read();
    Serial.print(F("Val: ")); Serial.println(pushButtonVal);

    }
    else if(menuOption == '5') {
    
    servo360Micro.attach(SERVO360MICRO_PIN_SIG);         // 1. attach the servo to correct pin to control it.
    servo360Micro.write(180);  // 2. turns servo CW in full speed. change the value in the brackets (180) to change the speed. As these numbers move closer to 90, the servo will move slower in that direction.
    delay(2000);                              // 3. waits 2000 milliseconds (2 sec). change the value in the brackets (2000) for a longer or shorter delay in milliseconds.
    servo360Micro.write(0);    // 4. turns servo CCW in full speed. change the value in the brackets (0) to change the speed. As these numbers move closer to 90, the servo will move slower in that direction.
    delay(2000);                              // 5. waits 2000 milliseconds (2 sec). change the value in the brackets (2000) for a longer or shorter delay in milliseconds.
    servo360Micro.write(90);    // 6. sending 90 stops the servo 
    delay(2000);                              // 7. waits 2000 milliseconds (2 sec). change the value in the brackets (2000) for a longer or shorter delay in milliseconds.
    servo360Micro.detach();                    // 8. release the servo to conserve power. When detached the servo will NOT hold it's position under stress.
    }
    else if(menuOption == '6') {
   
    servoMD1_1.attach(SERVOMD1_1_PIN_SIG);         // 1. attach the servo to correct pin to control it.
    servoMD1_1.write(servoMD1_1TargetPosition);  // 2. turns servo to target position. Modify target position by modifying the 'ServoTargetPosition' definition above.
    delay(500);                              // 3. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    servoMD1_1.write(servoMD1_1RestPosition);    // 4. turns servo back to rest position. Modify initial position by modifying the 'ServoRestPosition' definition above.
    delay(500);                              // 5. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    servoMD1_1.detach();                    // 6. release the servo to conserve power. When detached the servo will NOT hold it's position under stress.
    }
    else if(menuOption == '7') {
   
    servoMD2_2.attach(SERVOMD2_2_PIN_SIG);         // 1. attach the servo to correct pin to control it.
    servoMD2_2.write(servoMD2_2TargetPosition);  // 2. turns servo to target position. Modify target position by modifying the 'ServoTargetPosition' definition above.
    delay(500);                              // 3. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    servoMD2_2.write(servoMD2_2RestPosition);    // 4. turns servo back to rest position. Modify initial position by modifying the 'ServoRestPosition' definition above.
    delay(500);                              // 5. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    servoMD2_2.detach();                    // 6. release the servo to conserve power. When detached the servo will NOT hold it's position under stress.
    }
    else if(menuOption == '8') {


    servoMD3_3.attach(SERVOMD3_3_PIN_SIG);         // 1. attach the servo to correct pin to control it.
    servoMD3_3.write(servoMD3_3TargetPosition);  // 2. turns servo to target position. Modify target position by modifying the 'ServoTargetPosition' definition above.
    delay(500);                              // 3. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    servoMD3_3.write(servoMD3_3RestPosition);    // 4. turns servo back to rest position. Modify initial position by modifying the 'ServoRestPosition' definition above.
    delay(500);                              // 5. waits 500 milliseconds (0.5 sec). change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    servoMD3_3.detach();                    // 6. release the servo to conserve power. When detached the servo will NOT hold it's position under stress.
    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) HC - 05 Bluetooth Serial Module"));
    Serial.println(F("(2) PS2 X Y Axis Joystick Module"));
    Serial.println(F("(3) LED - Basic Blue 5mm"));
    Serial.println(F("(4) Mini Pushbutton Switch"));
    Serial.println(F("(5) Continuous Rotation Micro Servo - FS90R"));
    Serial.println(F("(6) Standard Size - High Torque - Metal Gear Servo - MG995 #1"));
    Serial.println(F("(7) Standard Size - High Torque - Metal Gear Servo - MG995 #2"));
    Serial.println(F("(8) Standard Size - High Torque - Metal Gear Servo - MG995 #3"));
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
    			Serial.println(F("Now Testing PS2 X Y Axis Joystick Module"));
    		else if(c == '3') 
    			Serial.println(F("Now Testing LED - Basic Blue 5mm"));
    		else if(c == '4') 
    			Serial.println(F("Now Testing Mini Pushbutton Switch"));
    		else if(c == '5') 
    			Serial.println(F("Now Testing Continuous Rotation Micro Servo - FS90R"));
    		else if(c == '6') 
    			Serial.println(F("Now Testing Standard Size - High Torque - Metal Gear Servo - MG995 #1"));
    		else if(c == '7') 
    			Serial.println(F("Now Testing Standard Size - High Torque - Metal Gear Servo - MG995 #2"));
    		else if(c == '8') 
    			Serial.println(F("Now Testing Standard Size - High Torque - Metal Gear Servo - MG995 #3"));
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
