/*!
 * @file SetCursor.ino
 * @brief SetCursor.
 * @copyright	Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @maintainer [yangfeng](feng.yang@dfrobot.com)
 * @version  V1.0
 * @date  2021-09-24
 * @url https://github.com/DFRobot/DFRobot_RGBLCD1602
 */
#include "DFRobot_RGBLCD1602.h"

const int numRows = 2;
const int numCols = 16;

DFRobot_RGBLCD1602 lcd(/*lcdCols*/16,/*lcdRows*/2);  //16 characters and 2 lines of show

void setup() {
    /**
     *  @brief 液晶屏以及主控IIC的初始化
     */ 
    lcd.init();
}

void loop() {
    // loop from ASCII 'a' to ASCII 'z':
    for (int thisLetter = 'a'; thisLetter <= 'z'; thisLetter++) {
        // loop over the columns:
        for (int thisCol = 0; thisCol < numRows; thisCol++) {
            // loop over the rows:
            for (int thisRow = 0; thisRow < numCols; thisRow++) {
                /**
                 *  @brief 设置光标位置
                 *  @param col 列数 可选范围 0-15
                 *  @param row 行数 可选范围 0-1，0代表了第一行，1代表了第二行
                 */
                lcd.setCursor(thisRow,thisCol);// set the cursor position
                // print the letter:
                lcd.write(thisLetter);
                delay(200);
            }
        }
    }
}

