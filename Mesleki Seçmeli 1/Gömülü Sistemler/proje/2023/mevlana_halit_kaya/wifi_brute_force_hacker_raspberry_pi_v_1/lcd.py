# SPDX-FileCopyrightText: 2018 Mikey Sklar for Adafruit Industries
#
# SPDX-License-Identifier: MIT

import board
import digitalio
import adafruit_character_lcd.character_lcd as characterlcd


def message(line1, line2):
    global lcd

    lcd.message = f"{line1: <16}\n{line2: <16}"


def init():
    global lcd

    # Modify this if you have a different sized character LCD
    lcd_columns = 16
    lcd_rows = 2

    # compatible with all versions of RPI as of Jan. 2019
    # v1 - v3B+
    lcd_rs = digitalio.DigitalInOut(board.D22)
    lcd_en = digitalio.DigitalInOut(board.D17)
    lcd_d4 = digitalio.DigitalInOut(board.D25)
    lcd_d5 = digitalio.DigitalInOut(board.D24)
    lcd_d6 = digitalio.DigitalInOut(board.D23)
    lcd_d7 = digitalio.DigitalInOut(board.D18)


    # Initialise the lcd class
    lcd = characterlcd.Character_LCD_Mono(lcd_rs, lcd_en, lcd_d4, lcd_d5, lcd_d6,
                                          lcd_d7, lcd_columns, lcd_rows)
                                          
