# -*- coding: utf-8 -*-
'''file button.py
 # @brief 本实例实现了按键状态显示，被按下的按键将会在LCD中显示
 # @copyright	Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 # @licence     The MIT License (MIT)
 # @maintainer [yangfeng](feng.yang@dfrobot.com)
 # @version  V1.0
 # @date  2021-09-26
 # @url https://github.com/DFRobot/DFRobot_RGBLCD1602
'''
import sys
sys.path.append('../')
import RPi.GPIO as GPIO
from DFRobot_RGBLCD1602 import *
import time

lcd=DFRobot_RGBLCD1602(col= 16,row = 2)                               #create LCD object,specify col and row
GPIO.setmode(GPIO.BCM)
# Define keys
lcd_key     = 0
key_in  = 0

btnRIGHT  = 0
btnUP     = 1
btnDOWN   = 2
btnLEFT   = 3
btnSELECT = 4

GPIO.setup(16, GPIO.IN)
GPIO.setup(17, GPIO.IN)
GPIO.setup(18, GPIO.IN)
GPIO.setup(19, GPIO.IN)
GPIO.setup(20, GPIO.IN)


#Read the key value
def read_LCD_buttons():
  key_in16 = GPIO.input(16)
  key_in17 = GPIO.input(17)
  key_in18 = GPIO.input(18)
  key_in19 = GPIO.input(19)
  key_in20 = GPIO.input(20)
 
  if (key_in16 == 1):
    return btnSELECT
  if (key_in17 == 1):
    return btnUP
  if (key_in18 == 1):
    return btnDOWN
  if (key_in19 == 1):
    return btnLEFT
  if (key_in20 == 1):
    return btnRIGHT

'''
  @brief 设置光标位置
  @param col 列数 可选范围 0-15
  @param row 行数 可选范围 0-1，0代表了第一行，1代表了第二行
'''
lcd.set_cursor(0,0)
'''
  @brief 向液晶屏输出显示
  @param arg 输出的数据
'''
lcd.print_out("Push the buttons")
while True:
  lcd.set_cursor(0,1)
  lcd_key = read_LCD_buttons()  #  Reading keys
  time.sleep(0.2)
  lcd_key = read_LCD_buttons()

  if (lcd_key == btnRIGHT):
    lcd.print_out("RIGHT ")
  elif (lcd_key == btnLEFT):
    lcd.print_out("LEFT  ")
  elif (lcd_key == btnUP):
    lcd.print_out("UP    ")
  elif (lcd_key == btnDOWN):
    lcd.print_out("DOWN  ")
  elif (lcd_key == btnSELECT):
    lcd.print_out("SELECT")
