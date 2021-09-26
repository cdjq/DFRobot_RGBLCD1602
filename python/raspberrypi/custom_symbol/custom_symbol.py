# -*- coding: utf-8 -*-
'''file custom_symbol.py
 # @brief Custom Symbol.
 # @copyright	Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 # @licence     The MIT License (MIT)
 # @maintainer [yangfeng](feng.yang@dfrobot.com)
 # @version  V1.0
 # @date  2021-09-26
 # @url https://github.com/DFRobot/DFRobot_RGBLCD1602
'''
import sys
sys.path.append('../')
from DFRobot_RGBLCD1602 import *
import time

def _map(x,inMin,inMax,outMin,outMax):
  return (x-inMin)*(outMax-outMin)/(inMax-inMin)+outMin


# make some custom characters:
heart = [
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
]

smiley = [
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
]

frownie = [
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
]

armsDown = [
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
]

armsUp = [
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
]

lcd=DFRobot_RGBLCD1602(col= 16,row = 2)                               #create LCD object,specify col and row
# create a new character
'''
  @brief Allows us to fill the first 8 C
  @param location 代替字符 范围（0-7）
  @param charmap  字符列表 大小8个字节
'''
lcd.customSymbol(0, heart)
lcd.customSymbol(1, smiley)
lcd.customSymbol(2, frownie)
lcd.customSymbol(3, armsDown)
lcd.customSymbol(4, armsUp)
#set up the lcd's number of columns and rows:

'''
  @brief 设置光标位置
  @param col 列数 可选范围 0-15
  @param row 行数 可选范围 0-1，0代表了第一行，1代表了第二行
'''
lcd.set_cursor(0, 0)

'''
  @brief 向液晶屏输出显示
  @param arg 输出的数据
'''
# Print a message to the lcd.
lcd.print_out("I ")
lcd.write(0)
lcd.print_out(" raspberry ")
lcd.write(1)
while True:
  lcd.set_cursor(4, 1)
  lcd.write(3)
  time.sleep(0.5)
  lcd.set_cursor(4, 1)
  lcd.write(4)
  time.sleep(0.5)
