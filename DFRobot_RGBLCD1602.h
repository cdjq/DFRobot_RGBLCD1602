/*!
 * @file DFRobot_RGBLCD1602.h
 * @brief DFRobot_RGBLCD1602 类的基础结构
 * @copyright	Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @maintainer [yangfeng](feng.yang@dfrobot.com)
 * @version  V1.0
 * @date  2021-09-24
 * @url https://github.com/DFRobot/DFRobot_RGBLCD1602
 */

#ifndef __DFRobot_RGBLCD1602_H__
#define __DFRobot_RGBLCD1602_H__
#include<Arduino.h>
#include <Wire.h>
#include <inttypes.h>
#include "Print.h"
#include <stdio.h>
#include <string.h>

/*!
 *  @brief Device I2C Arress
 */
#define LCD_ADDRESS     (0x7c>>1)
#define RGB_ADDRESS     (0xc0>>1)

/*!
 *  @brief color define
 */ 
#define WHITE           0
#define RED             1
#define GREEN           2
#define BLUE            3

#define REG_RED         0x04        // pwm2
#define REG_GREEN       0x03        // pwm1
#define REG_BLUE        0x02        // pwm0

#define REG_MODE1       0x00
#define REG_MODE2       0x01
#define REG_OUTPUT      0x08

/*!
 *  @brief commands
 */
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

/*!
 *  @brief flags for display entry mode
 */
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

/*!
 *  @brief flags for display on/off control
 */
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

/*!
 *  @brief flags for display/cursor shift
 */
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

/*!
 *  @brief flags for function set
 */
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

class DFRobot_RGBLCD1602 : public Print 
{

public:

  /**
   *  @brief Constructor
   */
  DFRobot_RGBLCD1602(uint8_t lcdCols,uint8_t lcdRows,TwoWire *pWire=&Wire,uint8_t lcdAddr=LCD_ADDRESS,uint8_t RGBAddr=RGB_ADDRESS);

  /**
   *  @brief 液晶屏以及主控IIC的初始化
   */ 
  void init();

  /**
   *  @brief 清除显示并将光标回到初始位置（0位置）
   */
  void clear();

  /**
   *  @brief 将光标回到初始位置（0,0）
   */
  void home();

    /**
     *  @brief Turn off the display
     */
  void noDisplay();

  /**
   *  @brief Turn on the display
   */
  void display();

  /**
   *  @brief Turn  off the blinking showCursor
   */
  void stopBlink();

  /**
   *  @brief Turn on  the blinking showCursor
   */
  void blink();

  /**
   *  @brief Turn off the underline showCursor 
   */
  void noCursor();

  /**
   *  @brief Turn on the underline showCursor 
   */
  void cursor();

  /**
   *  @brief 向左滚动显示
   */
  void scrollDisplayLeft();

  /**
   *  @brief 向右滚动显示
   */
  void scrollDisplayRight();
 
  /**
   *  @brief This is for text that flows Left to Right
   */
  void leftToRight();
 
  /**
   *  @brief This is for text that flows Right to Left
   */
  void rightToLeft();

  /**
   *  @brief This will 'left justify' text from the showCursor
   */
  void noAutoscroll();
 
  /**
   *  @brief This will 'right justify' text from the showCursor
   */
  void autoscroll();
   
  /**
   *  @brief Allows us to fill the first 8 CGRAM locations with custom characters
   *  @param location 代替字符 范围（0-7）
   *  @param charmap  字符数组 大小8个字节
   */
  void customSymbol(uint8_t location, uint8_t charmap[]);

  /**
   *  @brief 设置光标位置
   *  @param col 列数 可选范围 0-15
   *  @param row 行数 可选范围 0-1，0代表了第一行，1代表了第二行
   */
  void setCursor(uint8_t col, uint8_t row);
  
  /**
   *  @brief 设置RGB
   *  @param r  red   范围(0-255)
   *  @param g  green 范围(0-255)
   *  @param b  blue  范围(0-255)
   */
  void setRGB(uint8_t r, uint8_t g, uint8_t b);

  /**
   *  @brief 设置背光PWM输出
   *  @param color  背光颜色  参数选择：REG_RED\REG_GREEN\REG_BLUE
   *  @param pwm  颜色强度值   范围(0-255)
   */
  void setPWM(uint8_t color, uint8_t pwm){setReg(color, pwm);}      // set pwm

  /**
   *  @brief 背光颜色
   *  @param color  背光颜色  参数选择： WHITE\RED\GREEN\BLUE
   */
  void setColor(uint8_t color);

  /**
   *  @brief 关闭背光
   */
  void closeBacklight(){setRGB(0, 0, 0);}

  /**
   *  @brief 设置背光为白色
   */
  void setColorWhite(){setRGB(255,255 , 255);}

  /**
   *  @brief blink the LED backlight
   */
  void blinkLED(void);

  /**
   *  @brief 不闪烁背光
   */
  void noBlinkLED(void);

  /**
   *  @brief write character
   *  @param data 写入的数据
   */
  virtual size_t write(uint8_t data);

  /**
   *  @brief send command
   *  @param data 发送的命令
   */
  void command(uint8_t data);

  /**
   *  @brief 设置背光
   *  @param mode  true代表开启背光并设置为白色，false代表关闭背光
   */
  void setBacklight(bool mode);

  using Print::write;
  
private:
  /**
   *  @brief 初始化函数
   *  @param col 列数 可选范围 0-15
   *  @param row 行数 可选范围 0-1，0代表了第一行，1代表了第二行
   *  @param charSize  字符尺寸 LCD_5x8DOTS\LCD_5x10DOTS
   */
  void begin(uint8_t cols, uint8_t rows, uint8_t charSize = LCD_5x8DOTS);

  /**
   *  @brief 设置光标
   *  @param data 要发送的数据
   *  @param len 数据长度
   */
  void send(uint8_t *data, uint8_t len);

  /**
   *  @brief 设置寄存器
   *  @param addr 寄存器地址
   *  @param data 数据
   */
  void setReg(uint8_t addr, uint8_t data);
  uint8_t _showFunction;
  uint8_t _showControl;
  uint8_t _showMode;
  uint8_t _initialized;
  uint8_t _numLines,_currLine;
  uint8_t _lcdAddr;
  uint8_t _RGBAddr;
  uint8_t _cols;
  uint8_t _rows;
  TwoWire *_pWire;
};

#endif
