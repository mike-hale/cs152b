import serial
from mnist import MNIST

port = 'COM4'
baud = 9600

def main():
    data = MNIST('../../../../../dataset_imgs')
    images, labels = data.load_training()
    ser = serial.Serial(port, baud)

    if ser.isOpen():
        print(ser.name + " is open")

    image_counter = 0
    while 1:
        serial_line = ser.read(1)
        print(serial_line)
        if True:#serial_line == b'7':
            ba = bytearray(28*28 + 1)
            ba[0] = labels[0]
            for i in range(784):
                ba[i + 1] = images[0][i]
            ser.write(ba)
            image_counter++;
            print('Wrote an image!')
        if (image_counter % 1000 == 0):
            print("image number: " + image_counter)

    

if __name__=='__main__':
    main()




