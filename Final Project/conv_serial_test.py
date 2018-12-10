import serial
from mnist import MNIST

def load_dataset():
    data = MNIST('../../../../../dataset_imgs')
    return data.load_training()

def open_port():
    return serial.Serial('COM4', 9600)

def float2fix(fl):
    fi = 0
    if fl < 0:
        fi += 1 << 31
    fi += int(abs(fl)) << 15
    fi += int((abs(fl) - int(abs(fl)))*32768)
    return fi
    
def save_image(image):
    f = open('input_image.coe', 'w')
    for i in range(32):
        for j in range(32):
            if i < 28 and j < 28:
                if image[i,j] >= 127:
                    val = (int(image[i,j]) & 0x7F) << 8
                else:
                    val = (127 - int(image[i,j])) << 8
                    val += (1 << 31)
            else:
                val = 0
            f.write('%08x,\n' % val)