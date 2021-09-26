# -*- coding: utf-8 -*-
'''file hello_world.py
 # @brief 显示"hello,world!"
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

colorR = 255
colorG = 0
colorB = 0

lcd=DFRobot_RGBLCD1602(16,2)

'''
  @brief 设置RGB
  @param r  red   范围(0-255)
  @param g  green 范围(0-255)
  @param b  blue  范围(0-255)
'''
lcd.set_RGB(colorR, colorG, colorB)
    
# Print a message to the LCD.
'''
  @brief 向液晶屏输出显示
  @param arg 输出的数据
'''
lcd.print_out("hello, world!")

time.sleep(1)
i = 0

while True:
  i = i+1
  # set the cursor to column 0, line 1
  # (note: line 1 is the second row, since counting begins with 0):
  '''
    @brief 设置光标位置
    @param col 列数 可选范围 0-15
    @param row 行数 可选范围 0-1，0代表了第一行，1代表了第二行
  '''
  lcd.set_cursor(0, 1)
  # print the number of seconds since reset:
  lcd.print_out(i)
  time.sleep(1)

