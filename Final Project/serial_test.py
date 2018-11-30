import serial
from mnist import MNIST

port = 'COM5'
baud = 9600

def main():
    data = MNIST('../../../../../dataset_imgs')
    images, labels = data.load_training()
    ser = serial.Serial(port, baud)
    if ser.isOpen():
        print(ser.name + " is open")

    idx = 0;
    while 1:
        serial_line = ser.read(1)
        print(serial_line)
        if serial_line == b'7':
            ba = bytearray(28*28*4)
            for i,pix in enumerate(images[idx]):
                pix = pix*2 - 255
                if pix < 0:
                    ba[i*4 + 3] = 128
                    ba[i*4 + 1] = (-pix) >> 1
                else:
                    ba[i*4 + 3] = 0
                    ba[i*4 + 1] = pix >> 1
                ba[i*4 + 2] = 0
                ba[i*4] = 0
            ser.write(ba)
            print('Wrote an image!')
    

if __name__=='__main__':
    main()




