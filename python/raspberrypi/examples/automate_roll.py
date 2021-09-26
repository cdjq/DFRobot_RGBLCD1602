# -*- coding: utf-8 -*-
'''file automate_roll.py
 # @brief Automate Roll.
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

lcd=DFRobot_RGBLCD1602(col= 16,row = 2)                               #create LCD object,specify col and row


while True:

  '''
    @brief 设置光标位置
    @param col 列数 可选范围 0-15
    @param row 行数 可选范围 0-1，0代表了第一行，1代表了第二行
  '''
  lcd.set_cursor(0, 0)
  #print from 0 to 9:
  for thisChar in range(0,10):
    '''
      @brief 向液晶屏输出显示
      @param arg 输出的数据
    '''
    lcd.print_out(thisChar)
    time.sleep(0.5)

  # set the cursor to (16,1):
  lcd.set_cursor(16,1)

  '''
    @brief This will 'right justify' text from the showCursor
  '''
  # set the show to automatically scroll:
  lcd.autoscroll()
  # print from 0 to 9:
  for thisChar in range (0,10):
    lcd.print_out(thisChar)
    time.sleep(0.5)
  '''
    @brief This will 'left justify' text from the showCursor
  '''
  # turn off automatic scrolling
  lcd.no_autoscroll()

  '''
    @brief 清除显示并将光标回到初始位置（0位置）
  '''
  lcd.clear()
