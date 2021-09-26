/*!
 * @file CustomSymbol.ino
 * @brief Custom Symbol.
 * @copyright	Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @maintainer [yangfeng](feng.yang@dfrobot.com)
 * @version  V1.0
 * @date  2021-09-24
 * @url https://github.com/DFRobot/DFRobot_RGBLCD1602
 */

#include "DFRobot_RGBLCD1602.h"

DFRobot_RGBLCD1602 lcd(/*lcdCols*/16,/*lcdRows*/2);  //16 characters and 2 lines of show

// make some custom characters:
byte heart[8] = {
    0b00000,
    0b01010,
    0b11111,
    0b11111,
    0b11111,
    0b01110,
    0b00100,
    0b00000
};

byte smiley[8] = {
    0b00000,
    0b00000,
    0b01010,
    0b00000,
    0b00000,
    0b10001,
    0b01110,
    0b00000
};

byte frownie[8] = {
    0b00000,
    0b00000,
    0b01010,
    0b00000,
    0b00000,
    0b00000,
    0b01110,
    0b10001
};

byte armsDown[8] = {
    0b00100,
    0b01010,
    0b00100,
    0b00100,
    0b01110,
    0b10101,
    0b00100,
    0b01010
};

byte armsUp[8] = {
    0b00100,
    0b01010,
    0b00100,
    0b10101,
    0b01110,
    0b00100,
    0b00100,
    0b01010
};


void setup() {
    /**
     *  @brief 液晶屏以及主控IIC的初始化
     */ 
    lcd.init();
 #if 1   // create a new character
  /**
   *  @brief Allows us to fill the first 8 CGRAM locations with custom characters
   *  @param location 代替字符 范围（0-7）
   *  @param charmap  字符数组 大小8个字节
   */
    lcd.customSymbol(0, heart);
    lcd.customSymbol(1, smiley);
    lcd.customSymbol(2, frownie);
    lcd.customSymbol(3, armsDown);
    lcd.customSymbol(4, armsUp);
#endif 
    // set up the lcd's number of columns and rows:
    
    /**
     *  @brief 设置光标位置
     *  @param col 列数 可选范围 0-15
     *  @param row 行数 可选范围 0-1，0代表了第一行，1代表了第二行
     */
    lcd.setCursor(0, 0);
    // Print a message to the lcd.
    lcd.print("I ");
    lcd.write((unsigned char)0);
    lcd.print(" Arduino! ");
    lcd.write(1);
}

void loop() {
    // read the potentiometer on A0:
    int sensorReading = analogRead(A0);
    // map the result to 200 - 1000:
    int delayTime = map(sensorReading, 0, 1023, 200, 1000);
    // set the cursor to the bottom row, 5th position:
    lcd.setCursor(4, 1);
    // draw the little man, arms down:
    lcd.write(3);
    delay(delayTime);
    lcd.setCursor(4, 1);
    // draw him arms up:
    lcd.write(4);
    delay(delayTime);
}
