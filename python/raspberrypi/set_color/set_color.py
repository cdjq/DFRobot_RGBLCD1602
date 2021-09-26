# -*- coding: utf-8 -*-
'''file set_color.py
 # @brief  设置背光颜色
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

lcd=DFRobot_RGBLCD1602(16,2)                               #create LCD object,specify col and row

# Print a message to the LCD.
'''
  @brief 向液晶屏输出显示
  @param arg 输出的数据
'''
lcd.print_out("set color")
print("set color")
while True:  
  while True:
    r = int(input("r = "))
    if r < 256 and r >= 0:
      break 
    else:
      print("r is wrong number,input r in 0 ~255")
  while True:
    g = int(input("g = "))
    if g < 256 and g >= 0:
      break 
    else:
      print("g is wrong number,input g in 0 ~255")
  while True:
    b = int(input("b = "))
    if b <256 and b >= 0:
      break
    else:
      print("b is wrong number,input b in 0 ~255")
  '''
    @brief 设置RGB
    @param r  red   范围(0-255)
    @param g  green 范围(0-255)
    @param b  blue  范围(0-255)
  '''
  lcd.set_RGB(r, g, b)
  print("get data:r = %s,g = %s,b = %s" %(r,g,b))


