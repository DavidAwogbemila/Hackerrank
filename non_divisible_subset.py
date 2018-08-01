#!/bin/python3

"""
Given a set of distinct integers, print the size of a maximal subset of S' where the sum of any 2 numbers
in S' is not evenly divisible by K.
"""

import math
import os
import random
import re
import sys

# Complete the nonDivisibleSubset function below.
def nonDivisibleSubset(k, S):
    freqs = [0] * k
    for i in S:
        freqs[i%k] += 1
    
    count = min(freqs[0], 1)
    print(range(1, k//2 + 1))
    for i in range(1, k//2 + 1):
        if i != k - i:
            print("for", i, "<=>", k-i, ": ", max(freqs[k-i], freqs[i]))
            count += max(freqs[i], freqs[k - i])
    
    if k%2 == 0:
        count +=1
    
    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    S = list(map(int, input().rstrip().split()))

    result = nonDivisibleSubset(k, S)

    fptr.write(str(result) + '\n')

    fptr.close()
