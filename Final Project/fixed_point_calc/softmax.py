import math

def expApprox(x):
    numerator = x
    ret_val = 1 + x
    denominator = 1
    for i in range(2,20):
        denominator *= i
        numerator *= x
        ret_val += (numerator/ denominator)
    return ret_val

print(math.exp(5.2))
print(expApprox(5.2))

