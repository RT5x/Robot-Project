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


const int timeout = 10000;      
char menuOption = 0;
long time0;


void setup() 
{

    Serial.begin(9600);
    while (!Serial) ; 
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
        ledB.dim(i);                    
        delay(15);                              
    }                                          
    ledB.off();                    
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
