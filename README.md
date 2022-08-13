# ESP 8266 and Arduino IoT

## IoT
The Internet of things (IoT) describes physical objects (or groups of such objects) with sensors, processing ability, software, and other technologies that connect and exchange data with other devices and systems over the Internet or other communications networks. Internet of things has been considered a misnomer because devices do not need to be connected to the public internet, they only need to be connected to a network and be individually addressable.

![sketch](https://raw.githubusercontent.com/Brijeshkrishna/esp8266-arduino-IoT/main/imgs/sketch.png)
## Working
In this project with use of iot technology ,we control the motion of led ,it need not to an led we can control any device.ESP 8266 has a built in wifi , with that we communicate with the internet,In this  project we used telegram for communicating with esp8266.esp8266 is connected to the arduino with serial communication to send data from esp8266,indirectly from telegram to arduino esp8266 as an intermediate.
We see commands from telegram to arduino to turn on or off or blink a specific led ,for example if we send `/led_1_on` it will turn on the  led 1  to turn off `/led_1_off` . With the help of this we can blink a led by `/led_1_blink` . There is no restriction of number led except the pin in arduino,we demonstrated how we individually control the leds.you can add your own style of blink.

![working](https://raw.githubusercontent.com/Brijeshkrishna/esp8266-arduino-IoT/main/imgs/model%20(1).jpg)
## Hardware Components

- Arduino UNO
- Breadboard
- Led lights (2)
- Wires 
- ESP 8266 node MCU wifi module
- Mobile phone

## Additional
- Telegram bot token 
- Telegram user id 

## Output
![working](https://raw.githubusercontent.com/Brijeshkrishna/esp8266-arduino-IoT/main/imgs/working.jpeg)

## Telegram
![telegram](https://raw.githubusercontent.com/Brijeshkrishna/esp8266-arduino-IoT/main/imgs/telegram.jpeg)
