import pymongo
import dns
import serial
from pymongo import MongoClient
import struct

cluster = MongoClient("")
serialPort = serial.Serial(port= "COM1", baudrate=9600 ,bytesize =8 , timeout =None, parity='N',stopbits=1)

db=cluster["<greenHouse>"]
collection = db["greenhouses"]


while serialPort.readline():
    results = collection.find({"greenHouseName" : "SERA 1" })
    for result in results:
        targetTemperature = abs(int(result.get("targetTemperature")))
     # declaring an integer value 
    int_val = targetTemperature

    # converting to string 
    str_val = str(targetTemperature) 

    # converting string to bytes 
    byte_val = str_val.encode() 

    serialPort.write(byte_val)
    getterThree = collection.update_one({"greenHouseName" : "SERA 1"},{"$set":{"targetTemperature" : targetTemperature }})
    getter = collection.update_one({"greenHouseName" : "SERA 1"},{"$set":{"currentTemperature" : float(serialPort.read() + serialPort.read()) }})
    
