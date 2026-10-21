#!/bin/sh
nmcli --terse --fields=name con show --active | while read name; do nmcli con down $name; done 
