# -*- coding: utf-8 -*-
'''file read_terminal_input.py
 # @brief  读取终端输入并显示到LCD
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

while True:
  data = raw_input()
  '''
    @brief 清除显示并将光标回到初始位置（0位置）
  '''
  lcd.clear()
  '''
    @brief 设置光标位置
    @param col 列数 可选范围 0-15
    @param row 行数 可选范围 0-1，0代表了第一行，1代表了第二行
  '''
  lcd.set_cursor(0,0)
  length = len(data)
  if length < 17:
    '''
      @brief 向液晶屏输出显示
      @param arg 输出的数据
    '''
    lcd.print_out(data)
  elif length >16:
    lcd.print_out(data[:16])
    lcd.set_cursor(0,1)
    lcd.print_out(data[16:])