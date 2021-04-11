# 3D Printed Flight Simulator Rudder Pedals

This is a set of flight simulator rudder pedals that I built from scratch. My copy is currently functional and being used in Microsoft Flight Simulator. This is a fairly crude design and is provided as-is with no support. Expect to iterate and improve the design. 

https://youtu.be/vinw3yeDGUQ

## Materials
- All parts printed in PLA on an Anycubic Chiron
- Shims - https://www.amazon.com/gp/product/B004K1FF0K/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1
- Bearings - https://www.amazon.com/gp/product/B07GT739PV/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1
- Shaft - https://www.mcmaster.com/catalog/127/1241
- Collar - https://www.mcmaster.com/catalog/127/1335
- Hall sensor - https://www.digikey.com/en/products/detail/honeywell-sensing-and-productivity-solutions/SS49E/701361
- Main Spring - https://www.thespringstore.com/pe076-718-24014-mw-2750-mh-n-in.html
- Pedal Spring Options - https://www.amazon.com/gp/product/B008RG8LXW/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1
- Magnets - Search amazon for "5mm cube magnets" for the lowest price
- Arduino Micro
- Various wires, header pins, usb cable, nuts and bolts

## Construction Notes
- Reference the youtube video for additional notes
- Reference the included images
- The arms are 300mm long and will dictate the minimum size printer (but they can be printed diaganoally)
- The shafts must be cut to size and their diameter must be ground down to fit in the bearings. I put the cut shafts into a drill press and ground them with sand paper. 
- There are 8 shafts total:
  - 61mm rail shaft X4
  - 57mm pedal shaft X2
  - 72mm center shaft X2
- Some pieces are glued together with super thin cyanoacrolate (superglue). For best adhesion, sand the mating surfaces down to a very fine grain - 1000 git or more, and apply a thin and even layer of glue. 
  - Pedal is glued to Pedal Hinge
  - Rail Top is glued to Rail Bottom
  - Hall Sensor Mount is glued to Frame
  - Magnet Mount is glued to one of the Arms
- The hall sensor I chose may not be the best candidate. I get less resolution than I would really want. One of the parameters in the datasheet is "Magnetic Range", which for the SS49E is +/- 1000 Gauss. If I were to do it again, I would choose a smaller magnetic range for higher resolution. 
- The magnets interact with the sensor in a way that requires a specific orientation and distances. Experiment with a simple test setup to familiarize yourself with the behavior. 
- The circuit is very simple. It is powered by the usb port. The hall sensors require 5V, ground, and output a 0-5v signal that is read with analogRead(). 
- Pay special attention to how the springs are mounted in the video - they are latching and will self center. 
- The assembled product was mounted to a board with screws. The Spring Posts are hot glued to the board. 

## Programming Notes
- This project uses Arduino Joystick Library https://github.com/MHeironimus/ArduinoJoystickLibrary
- ArduinoJoystickLibrary requires an arduino or clone that uses the ATmega32u4, although I expect that the library could be ported if you have more programming skill than ATmega32u4 buying skills. 
- There is a physical calibration step that is independent of Windows joystick calibration. I printed values from within the microcontroller over serial and tuned these values for each axis:
  -	top - the highest raw ADC value
  - bottom - the lowest raw ADC value
  - expoV - exponential curve coefficient, 1 is linear, see source for my values. You may find a more formal way of finding this value but I just used trial and error. 





