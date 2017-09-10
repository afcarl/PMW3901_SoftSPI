# Arduino SoftwareSPI driver for PMW3901 optical flow sensor

Arduino driver for the Pixart PMW3901 optical flow sensor. The driver
is developed to support the [Bitcraze Flow Breakout board](https://wiki.bitcraze.io/breakout:flow). 
It communicates with the sensor using Software SPI.

This library is a modification of the [Bitcraze_PWM3901 library](https://github.com/bitcraze/Bitcraze_PMW3901), 
for use with Software SPI instead
of ordinay SPI.  If your microcontroller provides ordinary (hardware) SPI access, you should
use the original Bitcraze library instead of this one.

## Additional libraries required

For SoftwareSPI support you should clone [this library](https://github.com/simondlevy/DigitalIO).

## Electrical connection

MISO, MOSI, and SCK, and CS (chip select) can be any four digital pins.

## Usage

Look at the [flow](examples/flow/flow.ino) example for basic usage.

You can create a sensor by passing the chip select pin number:

``` C++
// Using digital pin 10 for chip select
Bitcraze_PMW3901 flow(10);
```

Initializing the sensor is done by calling *begin*, it returns *true* if the
sensor is detected and initialized, *false* otherwise:

``` C++
  if (!flow.begin()) {
    Serial.println("Initialization of the flow sensor failed");
    while(1) { }
  }
```

As soon as it is initialized, the sensor will start accumulating motion count.
Calling the *readMotionCount* function allows to get the value of the motion
counters and resets the counters. So each time the function is called you get
the motion count since the last call:

``` C++
  // Get motion count since last call
  flow.readMotionCount(&deltaX, &deltaY);
```
