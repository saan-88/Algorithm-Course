# Write a Python function frequency(l) that takes as input a list of integers and
# returns a pair of the form (minfreqlist,maxfreqlist) where

# minfreqlist is a list of numbers with minimum frequency in l, sorted in ascending order
# maxfreqlist is a list of numbers with maximum frequency in l, sorted in ascending order
#
# Examples: 
#
# >>> frequency([13,12,11,13,14,13,7,11,13,14,12])
# ([7], [13])

# >>> frequency([13,12,11,13,14,13,7,11,13,14,12,14,14])
# ([7], [13, 14])

# >>> frequency([13,12,11,13,14,13,7,11,13,14,12,14,14,7])
# ([7, 11, 12], [13, 14])
##############################


def minList(H):
    minimum = min([H[key] for key in H])
    return sorted([key for key in H if H[key]==minimum])

def maxList(H):
    maximum = max([H[key] for key in H])
    return sorted([key for key in H if H[key]==maximum])
  
  
def frequency(l):
    """This function takes a list of integers and returns a dictionary with keys 
    the integers in the list and values their number of appearence in the list"""
    H={}
    for i in l:
        if i not in H:
            H[i]=1
        else:
            H[i]+=1
    return (minList(H), maxList(H))