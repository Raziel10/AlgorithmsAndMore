#!/usr/bin/env python3

def CycleNotation(perm):
    perm_cpy = perm.copy()
    cycles = []
    while(len(perm_cpy) > 0):
        element = perm_cpy.pop(0)
        cycle =[element]
        start = element
        j = None
        while((j != start) and (len(perm_cpy) > 0)):
            j = perm[element - 1]
            cycle.append(j)
            if(j in perm_cpy):
                perm_cpy.remove(j)
            element = j 
        if(len(cycle) > 1):
            cycles.append(cycle)
    print(str(cycles))
    return cycles

def permutationParity(cycles):
    parity = 1
    for c in cycles:
        if((len(c) % 2) == 0):
            parity = parity * (-1)
    if(parity == -1):
        print("odd")
    else:
        print("even")
    return parity

# For list of integers
permutation = []  
permutation = [int(item) for item in input("Enter the permutation : ").split()]
print(permutation)
cyc = CycleNotation(permutation)
permutationParity(cyc)