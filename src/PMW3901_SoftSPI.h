/* PMW3901_SoftSPI.h
 * Copyright (c) 2017 Bitcraze AB, Simon D. Levy
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include "Arduino.h"
#include <DigitalIO.h>
#include <stdint.h>

// Modify these for your hardware setup
const uint8_t MISO_PIN = 5;
const uint8_t MOSI_PIN = 8;
const uint8_t SCK_PIN  = 9;

class PMW3901_SoftSPI {

public:

  PMW3901_SoftSPI(uint8_t cspin);

  boolean begin(void);

  void readMotionCount(int16_t *deltaX, int16_t *deltaY);

private:

  SoftSPI<MISO, MOSI, SCK, 3> _spi;

  uint8_t _cs;

  void registerWrite(uint8_t reg, uint8_t value);
  uint8_t registerRead(uint8_t reg);
  void initRegisters(void);
};
