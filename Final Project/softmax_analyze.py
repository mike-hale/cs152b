import numpy as np
def toNum (lst):
    numList = []
    for i in lst: 
        numList.append(i/2**15)
    print(numList)
    return numList

def expList (lst):
    eList = []
    for i in lst:
        eList.append(np.e ** i)
    return eList
def softMax(lst):
    numList = toNum(lst)
    softList = []
    eList = expList(numList)
    for i in eList:
        softList.append(hex(int(i * 2**15 / sum(eList))))
    print(softList)

softMax([0x8000, 0x10f00, 0x19e00, 0x22d00])
softMax([0x2bc00, 0x2bb10, 0x2ba20, 0x2b930])
softMax([0x2b840, 0x34740, 0x3d640, 0x46540])