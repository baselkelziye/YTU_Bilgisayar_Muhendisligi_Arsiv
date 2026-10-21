import RPi.GPIO as GPIO

BTN_SEL = 0
BTN_DWN = 1
BTN_RST = 2

sel_pin=7
dwn_pin=8
rst_pin=9

def init():
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(sel_pin, GPIO.IN, GPIO.PUD_DOWN)
    GPIO.setup(dwn_pin, GPIO.IN, GPIO.PUD_DOWN)
    GPIO.setup(rst_pin, GPIO.IN, GPIO.PUD_DOWN)
     
def input():
    while GPIO.input(sel_pin) or GPIO.input(dwn_pin) or GPIO.input(rst_pin):
        pass
    while True:
        if GPIO.input(sel_pin):
            return BTN_SEL
        elif GPIO.input(dwn_pin):
            return BTN_DWN
        elif GPIO.input(rst_pin):
            return BTN_RST
