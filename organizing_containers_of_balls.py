#!/bin/python3

"""


"""


import math
import os
import random
import re
import sys

# Complete the organizingContainers function below.
def organizingContainers(container):
    number_of_containers = len(container)
    number_of_ball_types = number_of_containers
    
    container_sizes = [ sum(x) for x in container]
    ball_type_freqs = []
    for i in range(number_of_ball_types):
        ball_type_freqs.append(sum([x[i] for x in container]))
 
    container_sizes_to_frequency = dict()
    for i in container_sizes:
        if i in container_sizes_to_frequency:
            container_sizes_to_frequency[i] += 1
        else:
            container_sizes_to_frequency[i] = 1
    
    for i in ball_type_freqs:
        if i in container_sizes_to_frequency and container_sizes_to_frequency[i] > 0:
            container_sizes_to_frequency[i] -= 1
        else:
            return "Impossible"    
    return "Possible"
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        n = int(input())

        container = []

        for _ in range(n):
            container.append(list(map(int, input().rstrip().split())))

        result = organizingContainers(container)

        fptr.write(result + '\n')

    fptr.close()
