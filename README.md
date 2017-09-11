# Arduino SoftwareSPI driver for PMW3901 optical flow sensor

PWM3901_SoftSPI is an Arduino library for the Pixart PMW3901 optical flow sensor. The driver
is developed to support the breakout boards from [Bitcraze](https://wiki.bitcraze.io/breakout:flow)
and [Pesky Products](https://oshpark.com/shared_projects/autoGC8x).  It
communicates with the sensor using Software SPI.  By using a header-only library we are able to 
exploit the compile-time optimizations in the header-only
[SoftSPI](https://github.com/simondlevy/DigitalIO/blob/master/src/SoftSPI.h)
class.

This library is a modification of the [Bitcraze_PWM3901](https://github.com/bitcraze/Bitcraze_PMW3901) library.
If your microcontroller provides ordinary (hardware) SPI access, you should use that original Bitcraze
library instead of this one.

## Additional libraries required

For SoftwareSPI support you should clone the [DigitalIO](https://github.com/simondlevy/DigitalIO) library, which
provides the SoftSPI class.

## Electrical connection

MISO, MOSI, and SCK, and CS (chip select) can be any four digital pins.

## Usage

Look at the [flow](examples/flow/flow.ino) example for basic usage.

You can create a sensor by using the MISO, MOSI and SCK values in the constructor template and passing the chip select pin number as an argument:

``` C++
// Using digital pin 5 for MISO, 8 for MOSI, 9 for SCK, 10 for chip select
PMW3901_SoftSPI<5,8,9> flow(10);
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
