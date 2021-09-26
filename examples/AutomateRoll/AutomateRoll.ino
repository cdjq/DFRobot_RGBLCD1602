/*!
 * @file AutomateRoll.ino
 * @brief Automate Roll.
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
}

void loop() {
   /**
    *  @brief 设置光标位置
    *  @param col 列数 可选范围 0-15
    *  @param row 行数 可选范围 0-1，0代表了第一行，1代表了第二行
    */
    lcd.setCursor(0, 0);
    // print from 0 to 9:
    for (int thisChar = 0; thisChar < 10; thisChar++){
        lcd.print(thisChar);
        delay(500);
    }

    lcd.setCursor(16,1);// set the cursor to (16,1):

    /**
     *  @brief This will 'right justify' text from the showCursor
     */
    lcd.autoscroll(); // set the show to automatically scroll
    // print from 0 to 9:
    for (int thisChar = 0; thisChar < 10; thisChar++){
        lcd.print(thisChar);
        delay(500);
    }

    /**
     *  @brief This will 'left justify' text from the showCursor
     */
    lcd.noAutoscroll();// turn off automatic scrolling

    /**
     *  @brief 清除显示并将光标回到初始位置（0位置）
     */
    lcd.clear();// clear screen for the next loop
}

