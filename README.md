# DFRobot_RGBLCD1602

- [中文版](./README_CN.md)

见惯了千篇一律的LCD液晶屏，你是否也想来一次不一样的体验？DFRobot彩光LCD将给您带来全新的视觉感受，摆脱沉闷的单色背光，换上RGB全彩背光，能够提供1600万种颜色组合。 DFRobot Gravity I2C LCD1602彩色背光液晶屏采用通用Gravity i2C接口，仅需两根通信线，即可完成通信与背光控制。液晶屏可以显示2x16个字符，支持屏幕滚动，光标移动等功能。没有繁琐的接线，没有复杂的代码，通过专门的Arduino库，就可以完成所有的设计。


![](./resources/images/DFR0464.jpg)


## Product Link(https://www.dfrobot.com/product-1609.html)

    SKU：DFR0464

## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary

DFRobot Gravity I2C LCD1602彩色背光液晶屏可以显示2x16个字符，支持屏幕滚动，光标移动，背光颜色调节等功能

## Installation

使用此库前，请首先下载库文件，将其粘贴到\Arduino\libraries目录中，然后打开examples文件夹并在该文件夹中运行演示。

## Methods

```C++
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
  void setPWM(uint8_t color, uint8_t pwm);

  /**
   *  @brief 背光颜色
   *  @param color  背光颜色  参数选择： WHITE\RED\GREEN\BLUE
   */
  void setColor(uint8_t color);

  /**
   *  @brief 关闭背光
   */
  void closeBacklight();

  /**
   *  @brief 设置背光为白色
   */
  void setColorWhite();

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
```

## Compatibility

| Board         | Work Well | Work Wrong | Untested | Remarks |
| ------------- | :-------: | :--------: | :------: | ------- |
| Arduino uno   |     √     |            |          |         |
| Mega2560      |     √     |            |          |         |
| Leonardo      |     √     |            |          |         |
| ESP32         |     √     |            |          |         |
| micro:bit     |     √     |            |          |         |
| FireBeetle M0 |     √     |            |          |         |


## History

- Date 2021-9-26
- Version V1.0.0


## Credits

Written by yangfeng(feng.yang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))
