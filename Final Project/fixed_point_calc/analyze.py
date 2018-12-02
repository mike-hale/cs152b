import pandas as pd
import numpy as np
import math


class fixedPoint:
    def __init__(self, decBits, totalBits):
        self.totalBits = totalBits
        self.intBits = totalBits - decBits - 1 #subtract the sign bit
        self.decBits = decBits
    
    #takes binary and returns fixed point decimal
    def binToDecimal(self,binStr):
        if binStr[0] == '1':
            sign = -1
        else:
            sign = 1
        intStr = binStr[1:self.intBits + 1]
        decimalStr = binStr[-self.decBits:]
        intRep = int(intStr, 2)
        decimalRep = 0.
        exp = -1
        for i in decimalStr:
            if i == '1':
                decimalRep += 2**exp
            exp -= 1
        return sign * (intRep + decimalRep)

    def decimalToFixedBin(self, floatNum):
        #how do we round???
        fixedBitStr = ""
        if(floatNum < 0):
            fixedBitStr += '1'
            floatNum *= -1
        else:
            fixedBitStr += '0'
        integralPart = int(floatNum)
        integralStr = bin(integralPart)[2:].zfill(self.intBits)
        fixedBitStr += integralStr
        #decimal portion... fuck LOL
        decimalPart = floatNum - integralPart
        #assuming this can be made...
        decimalStr = ""
        while decimalPart != 0.:
            if len(decimalStr) == self.decBits: #prevent hanging while loops
                return fixedBitStr + decimalStr
            decimalPart *= 2
            if decimalPart >= 1:
                decimalStr += "1"
                decimalPart -= 1
            else:
                decimalStr += "0"
        fixedBitStr += decimalStr
        while(len(fixedBitStr) < self.totalBits):
            fixedBitStr += "0"
        return fixedBitStr
        
    
translate = fixedPoint(7, 16)
'''
print(translate.binToDecimal("00000000000000000000000000000001"))
print(translate.binToDecimal("00000000000000000000000000000010"))
print(str(2 * 2**-19))


testFixed1 = 6.84
testFixed2 = 4.44
print("Sum: " + str(testFixed1 + testFixed2))
print(translate.binToDecimal("0000010110100011"))

print(translate.decimalToFixedBin(testFixed1))
print(translate.decimalToFixedBin(testFixed2))
print(translate.decimalToFixedBin(testFixed1 + testFixed2))

testFixed1 = 17.38
testFixed2 = 3.1111111111111111111
print("Sum: " + str(testFixed1 + testFixed2))
print("Result: ", str(translate.binToDecimal("0000101000111110")))
print("testFixed1: " + str(translate.decimalToFixedBin(testFixed1)))
print("testFixed2: " + str(translate.decimalToFixedBin(testFixed2)))
print(translate.decimalToFixedBin(testFixed1 + testFixed2))
'''

'''
testFixed1 = -4.35687
testFixed2 = 250.109471239
print("Sum: " + str(testFixed1 + testFixed2))
print("Result: ", str(translate.binToDecimal("0111101011100001")))
print("testFixed1: " + str(translate.decimalToFixedBin(testFixed1)))
print("testFixed2: " + str(translate.decimalToFixedBin(testFixed2)))


df = pd.read_csv("m_sim_results")
print(df)
pi = translate.binToDecimal('00000000000110010010000111111011')
df['expected'] = pd.Series(np.zeros(len(df)))
df.expected = df['multiplier'].apply(translate.binToDecimal) * math.pi
df['given'] = df['result'].apply(translate.binToDecimal)
df['difference'] = df['given'] - df['expected']
df['difference'] = df['difference'].apply(abs)
print(df)
'''

print(translate.decimalToFixedBin(1.23456))

df = pd.read_csv("m_sim_results", dtype=str)
print(df)
pi = 3.140625
df['expected'] = pd.Series(np.zeros(len(df)))
df.expected = df['multiplier'].apply(translate.binToDecimal) * df['multiplicand'].apply(translate.binToDecimal)
df['given'] = df['result'].apply(translate.binToDecimal)
df['difference'] = df['given'] - df['expected']
df['difference'] = df['difference'].apply(abs)
print(df)
df['multiplicand'] = df['multiplicand'].apply(translate.binToDecimal)
df['multiplier'] = df['multiplier'].apply(translate.binToDecimal)
print(df)

