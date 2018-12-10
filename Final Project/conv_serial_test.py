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
    