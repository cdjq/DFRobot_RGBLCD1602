# -*- coding: utf-8 -*-
'''file set_cursor.py
 # @brief  set cursor.
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

numRows = 2
numCols = 16
'''
  @brief 设置RGB
  @param r  red   范围(0-255)
  @param g  green 范围(0-255)
  @param b  blue  范围(0-255)
  
'''
lcd.set_RGB(0,100,0)
while True:
  # loop from ASCII 'a' to ASCII 'z':
  for thisLetter in range(ord('a'),ord('z')):
    #lcd.clear()
    # loop over the columns:
    for thisRow in range(0,numRows):
      # loop over the rows:
      for thisCol in range(0,numCols):
        # set the cursor position:
        '''
          @brief 设置光标位置
          @param col 列数 可选范围 0-15
          @param row 行数 可选范围 0-1，0代表了第一行，1代表了第二行
        '''
        lcd.set_cursor(thisCol,thisRow)
        # print the letter:
        '''
          @brief write character
          @param data 写入的数据
        '''
        lcd.write(thisLetter)
        time.sleep(0.2)
