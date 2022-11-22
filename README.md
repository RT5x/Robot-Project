# Robot Arm Project

This project relates to the specifications for a personal project I did over Summer 2022.

___
Mechanics: [SOLIDWORKS Student Edition 2020](https://www.solidworks.com/product/students?utm_campaign=202203_glo_cnbstud_3dxp_quantads_en&utm_medium=cpc&utm_source=google&utm_content=search&utm_term=I3W-STU-AC&gclid=CjwKCAjwt7SWBhAnEiwAx8ZLantEhRNsnldlx7fjr6bOHHKIJc0X3DjjxlUbtb59N-aEO6ivGEbntBoCzHIQAvD_BwE) to design CAD models for all physical components and Engineering Drawings.
___
3D Printer: Prusa i3 Mk3S

Slicer Software: [PrusaSclicer 2.4.2](https://github.com/prusa3d/PrusaSlicer/releases)
___
Electronics: Used Arduino microcontrollers to convert electrical signals from analog controllers to pitch and rotation of the arm.

  Components used:
  
   - [SG90 MicroServo motors (claw pitch and extension)](https://www.amazon.com/Micro-Servos-Helicopter-Airplane-Controls/dp/B07MLR1498/ref=sr_1_1_sspa?crid=SWBML466W8I1&keywords=sg90&qid=1657681563&sprefix=sg90%2Caps%2C143&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEzNEYzUTkwWkNEWTFHJmVuY3J5cHRlZElkPUEwNTM4NjAzTjhJNDY1UVk3TDQyJmVuY3J5cHRlZEFkSWQ9QTA2NTg2NDYyVUFaNVFaVlozUDlUJndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==)
    
   - [HC-05 Bluetooth module for Arduino]([https://www.amazon.com/KY-023-Joystick-Sensor-Module-Arduino/dp/B01M5L1BMS/ref=asc_df_B01M5L1BMS/?tag=hyprod-20&linkCode=df0&hvadid=194024095585&hvpos=&hvnetw=g&hvrand=8385209886003373967&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9032043&hvtargid=pla-311062729090&psc=1](https://www.amazon.com/Wireless-Bluetooth-Receiver-Transceiver-Transmitter/dp/B01MQKX7VP/ref=asc_df_B01MQKX7VP/?tag=hyprod-20&linkCode=df0&hvadid=167146065113&hvpos=&hvnetw=g&hvrand=6544565807263131200&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9032043&hvtargid=pla-362748457327&psc=1))
    
   - [Elegoo Arduino Uno R3](https://www.amazon.com/ELEGOO-Board-ATmega328P-ATMEGA16U2-Compliant/dp/B01EWOE0UU/ref=sr_1_1_sspa?crid=L6T8HLK0TKNU&keywords=uno+arduino&qid=1657681464&s=electronics&sprefix=uno+arduino%2Celectronics%2C122&sr=1-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUExTVZXOVg3NFZZTkw1JmVuY3J5cHRlZElkPUExMDM1NTMyMUQ5S0U1ODVEVkNLUiZlbmNyeXB0ZWRBZElkPUEwNDgzODMzMUlIN1I4WVRSM0w1UiZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU=)
    
   - [KY-023 PS2 Joystick Sensor Module](https://www.amazon.com/KY-023-Joystick-Sensor-Module-Arduino/dp/B01M5L1BMS/ref=asc_df_B01M5L1BMS/?tag=hyprod-20&linkCode=df0&hvadid=194024095585&hvpos=&hvnetw=g&hvrand=8385209886003373967&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9032043&hvtargid=pla-311062729090&psc=1)
    
   - 5V 2A DC Power Supply (Used [arduino extension cable](https://www.amazon.com/USB-2-0-Interface-Keyboard-Microphone-Instrument/dp/B01BIE98PO/ref=sxin_16_pa_sp_search_thematic_sspa?content-id=amzn1.sym.b245e49f-68a4-4489-b1f9-81f4034255f5%3Aamzn1.sym.b245e49f-68a4-4489-b1f9-81f4034255f5&crid=VOHTW8IIAFBO&cv_ct_cx=arduino+cable&keywords=arduino+cable&pd_rd_i=B01BIE98PO&pd_rd_r=5940e4fe-174a-4694-9a8a-c63df9280cb3&pd_rd_w=lsODJ&pd_rd_wg=DDYkN&pf_rd_p=b245e49f-68a4-4489-b1f9-81f4034255f5&pf_rd_r=QT4KM861HSS1F7Z6W1FM&qid=1657681694&sprefix=arduino+cable%2Caps%2C136&sr=1-2-a73d1c8c-2fd2-4f19-aa41-2df022bcb241-spons&psc=1&smid=A3RPN0HBLXDN8Z&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUExQUNXTjFDSTdTWUMyJmVuY3J5cHRlZElkPUEwOTMzMTI4MUZMUjdPQ1ZCT1M5UyZlbmNyeXB0ZWRBZElkPUEwODY1OTc4M0QyTjJQNUdRRE45MCZ3aWRnZXROYW1lPXNwX3NlYXJjaF90aGVtYXRpYyZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU=) connected to laptop USB)
    
   - [Arduino Breadboard](https://www.amazon.com/Qunqi-point-Experiment-Breadboard-5-5%C3%978-2%C3%970-85cm/dp/B0135IQ0ZC/ref=asc_df_B0135IQ0ZC/?tag=hyprod-20&linkCode=df0&hvadid=198091709182&hvpos=&hvnetw=g&hvrand=13329600099546597545&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9032043&hvtargid=pla-407203040794&psc=1)
    
   - [MG996R Servo Motor (Base rotation / azimuth)](https://www.amazon.com/MG996R-Torque-Digital-MELIFE-Helicopter/dp/B09BQP2F6M/ref=sr_1_8?keywords=mg996r&qid=1657681536&sr=8-8)
   - [Dupont Breadboard Pin Wires](https://www.amazon.com/Elegoo-EL-CP-004-Multicolored-Breadboard-arduino/dp/B01EV70C78/ref=asc_df_B01EV70C78/?tag=hyprod-20&linkCode=df0&hvadid=222785939698&hvpos=&hvnetw=g&hvrand=13579044309330366223&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9032043&hvtargid=pla-362913641420&psc=1)
___
Software: Used the [Arduino IDE](https://www.arduino.cc/en/software) to compile C++ code run by the microcontroller.
___
Miscellaneous Items:
  - [Dremel 100 Series 120 V](https://www.ebay.com/itm/165558436252?chn=ps&mkevt=1&mkcid=28)
  - [LCD Display Digital Calipers](https://www.amazon.com/Auto-Off-Conversion-Measuring-Household-Measurement/dp/B09M225ZP9/ref=asc_df_B09M225ZP9/?tag=hyprod-20&linkCode=df0&hvadid=598694042870&hvpos=&hvnetw=g&hvrand=16298055017569767196&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9032043&hvtargid=pla-1675873160099&psc=1)
  - M42 Hex Socket Cap Screws 
  
 ___
Data:
- Claw gripper torque 18 N⋅cm.
- Total arm rotation torque 54 N⋅cm.
- 10 N loads @min extension (5 cm).
- 2.4 N @max extension (23 cm).
- Base stepper motor ±1° precision (500 steps).
- 1.7 kg net weight.

