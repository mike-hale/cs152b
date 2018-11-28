import serial

port = '/dev/ttyACM0'
baud = 9600

def main():
    ser = serial.Serial(port, baud)
    if ser.isOpen():
    	print(ser.name + " is open")

    while 1:
    	serial_line = ser.readline()
    	print serial_line 
    

if __name__=='__main__':
	main()




