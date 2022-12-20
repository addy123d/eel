import eel
import serial
import time

ser = serial.Serial('/dev/ttyS0', 9600, timeout=1) #9600 is baud rate(must be same with that of NodeMCU)
ser.flush()


eel.init('web')

# Two tasks,
# 1. Send data to UI (User Interface).
# 2. Receive data from UI (User Interface).

# Receiving Data
@eel.expose
def get_data(value):
    print('%s' % value)
    string = value
    string = string +"\n" #"\n" for line seperation
    string = string.encode('utf_8')
    ser.write(string) #sending over UART
    line = ser.readline().decode('utf-8').rstrip()
    print("received: ",line)
    
    eel.send_data(line)

    
eel.start('index.html')

    





