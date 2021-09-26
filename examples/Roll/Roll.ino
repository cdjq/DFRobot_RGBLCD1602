/*!
 * @file Roll.ino
 * @brief Roll show 'hello, world!'.
 * @copyright	Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @maintainer [yangfeng](feng.yang@dfrobot.com)
 * @version  V1.0
 * @date  2021-09-24
 * @url https://github.com/DFRobot/DFRobot_RGBLCD1602
 */
#include "DFRobot_RGBLCD1602.h"

DFRobot_RGBLCD1602 lcd(/*lcdCols*/16,/*lcdRows*/2);  //16 characters and 2 lines of show

void setup() {
    /**
     *  @brief 液晶屏以及主控IIC的初始化
     */ 
    lcd.init();
    // Print a message to the LCD.
    lcd.print("hello, world!");
    delay(1000);
}

void loop() {
    // scroll 13 positions (string length) to the left
    // to move it offscreen left:
    for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
        /**
         *  @brief 向左滚动显示
         */
        lcd.scrollDisplayLeft();//scroll one position left
        // wait a bit:
        delay(150);
    }

    // scroll 29 positions (string length + show length) to the right
    // to move it offscreen right:
    for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
        /**
         *  @brief 向右滚动显示
         */
        lcd.scrollDisplayRight();//scroll one position right
        // wait a bit:
        delay(150);
    }

    // scroll 16 positions (show length + string length) to the left
    // to move it back to center:
    for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
        // scroll one position left:
        lcd.scrollDisplayLeft();
        // wait a bit:
        delay(150);
    }

    // delay at the end of the full loop:
    delay(1000);

}

