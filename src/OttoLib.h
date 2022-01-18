/**
 * @file    OttoLib.h
 * @author  David LEVAL (dleval@dle-dev.com)
 * @brief   Otto robot driver (Header)
 * @version 1.1
 * 
 * @copyright Copyright (c) 2022
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __OTTO_LIB_h
#define __OTTO_LIB_h

#include "OttoGlobal.h"
#include "OttoLib_Sound.h"
#include "OttoLib_Sensor.h"
#include "OttoLib_Servo.h"
#include "OttoLib_Gestures.h"
#include "OttoLib_Mouths.h"

#define _NBR_OF_SERVO   4

class Otto: public OttoSound, public OttoSensor, public OttoServo<_NBR_OF_SERVO>
{
    private:
        /* data */
    public:
        Otto(uint8_t legLeft, uint8_t legRight, uint8_t footLeft, uint8_t footRight, uint8_t pinNoiseSensor, uint8_t pinBuzzer, uint8_t pinUSTrigger, uint8_t pinUSEcho);
        //-- Otto initialization
        void init(bool load_calibration);

        //-- Predetermined Motion Functions
        void jump(float steps=1, uint16_t T = 2000);
        void walk(float steps=4, uint16_t T=1000, int8_t dir = FORWARD);
        void turn(float steps=4, uint16_t T=2000, int8_t dir = LEFT);
        void bend(uint16_t steps, uint16_t T, int8_t dir=LEFT);
        void shakeLeg(uint16_t steps=1, uint16_t T = 3000, int8_t dir=RIGHT);
        void updown(float steps=1, uint16_t T=1000, int16_t h = 20);
        void swing(float steps=1, uint16_t T=1000, int16_t h=20);
        void tiptoeSwing(float steps=1, uint16_t T=900, int16_t h=20);
        void jitter(float steps=1, uint16_t T=500, int16_t h=20);
        void ascendingTurn(float steps=1, uint16_t T=900, int16_t h=20);
        void moonwalker(float steps=1, uint16_t T=900, int16_t h=20, int dir=LEFT);
        void crusaito(float steps=1, uint16_t T=900, int16_t h=20, int dir=FORWARD);
        void flapping(float steps=1, uint16_t T=1000, int16_t h=20, int dir=FORWARD);

        //-- Gestures
        void playGesture(ottoGestures_t gesture);

        /* OttoDIYLib compability */
        Otto();
        void init(int YL, int YR, int RL, int RR, bool load_calibration, int Buzzer);

        //-- Mouth & Animations 
        //TODO : implement Otto Mouths class
        void putMouth(ottoMouths_t mouth, bool predefined = true);
        void putAnimationMouth(ottoAnimationMouths_t anim, int index);
        void clearMouth();
        void initMATRIX(int DIN, int CS, int CLK, int rotate);
        void matrixIntensity(int intensity);
        void setLed(byte X, byte Y, byte value);
        void writeText (const char * s, byte scrollspeed);
};




#endif //__OTTO_LIB_h