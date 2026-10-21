from wifi import Cell, Scheme
from time import sleep
from termcolor import cprint

class WifiTool:

    def __init__(self,interface):
        cprint("Starting the WifiTool . . . \n","green")
        self.interface = interface

    def scanWifi(self):
        headings = ['SSID', 'SIGNAL', 'FREQUENCY', 'CHANNEL', '  MAC ADDRESS  ', 'ENCRYPTION']

        ssid = []
        encry = []
        connection = 0
        menu_list = []

        cprint("\n[*] Scanning for WiFi connections . . . \n","yellow")

        for cell in Cell.all(self.interface):
            connection += 1
            ssid.append(cell.ssid)
            encryp = cell.encryption_type if cell.encrypted == True else "open"
            encry.append(encryp.upper())

        if connection == 0:
            cprint("\n[-] No WiFi connection in your area\n", 'red')
        else:
            tmpSet = set(ssid)
            menu_list = list(tmpSet)
            cprint("\n[+] "+str(len(menu_list)) + " WiFi connection/s found\n",'cyan')
        return menu_list

    def connect_wifi(self,ssid,passkey):
        try:
            import subprocess
            output = subprocess.check_output(f"nmcli dev wifi connect '{ssid}' password '{passkey}'", shell=True)
            if f"Device '{self.interface}' successfully activated" in str(output):
                cprint(f"[+] WiFi '{ssid}' successfully connected with '{passkey}'\n","green")
                return True
            else:
                cprint(f"[-] Wrong password\n","red")
                return False
        except Exception as e:
            cprint("[!!] Connection Failed\n","yellow")

