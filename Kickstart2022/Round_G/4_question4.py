import sys
import math
import random
import functools, itertools, collections, heapq, bisect
from collections import Counter, defaultdict, deque, OrderedDict

# class Flower:
#     def __init__(self, x, y, energy):
#         self.x = x
#         self.y = y
#         self.energy = energy

#     def __str__(self):
#         return f"[(x,y) = ({self.x},{self.y})| Energy: {self.energy}]"

#     ## Sort the flowers w.r.t to descending order of height and ascending order of value.
#     def __lt__(self, other):
#         return self.x < other.x if self.y == other.y else self.y < other.y
    
#     def __eq__ (self, other):
#         return self.x == other.x and self.y == other.y

# class Point:
#     def __init__(self, x,y):
#         self.x = x
#         self.y = y
#     def __eq__(self, other):
#         return self.x == other.x and self.y == other.y 

POS_INF = float('inf')
NEG_INF = float('-inf')
INT_MAX = sys.maxsize
INT_MIN = -sys.maxsize

## Add globals
MAX_ENERGY = 0
VISITED = None

def read_matrix(rows):
    return [list(map(int, input().split())) for _ in range(rows)]

def read_strings(rows):
    return [input().strip() for _ in range(rows)]

def minus_one(arr):
    return [x-1 for x in arr]

def minus_one_matrix(mrr):
    return [[x-1 for x in row] for row in mrr]

def create_matrix(rows, cols, default_val = 0):
    """
    Creates a matrix filled with default_val
        :param rows: the number of rows the matrix should have
        :param cols: the number of columns the matrix should have

        :return: list of lists that form the matrix
    """
    M = []
    while len(M) < rows:
        M.append([])
        while len(M[-1]) < cols:
            M[-1].append(default_val)

    return M

def cuteButterflyHelper(x, y, is_right, curr_e):
    global MAX_ENERGY
    global VISITED
    MAX_ENERGY = max(MAX_ENERGY, curr_e)
    for i in range(len(X)):
        if not VISITED[i] and Y[i] <= y:
            VISITED[i] = True
            if (is_right and X[i] < x) or (not is_right and X[i] > x):
                ## Butterfly changes direction
                cuteButterflyHelper(X[i], Y[i], not is_right, curr_e + C[i] - e)
            else:
                ## Can reach flower just by moving in the original direction
                cuteButterflyHelper(X[i], Y[i], is_right, curr_e + C[i])
            ## Backtrack
            VISITED[i] = False

# ================= TEMPLATE ENDS HERE ==================
def cuteButterfly(X,Y,C,e):
    ### Implemenation
    global MAX_ENERGY
    ## Sort flowers in ascending order of x value.
    ## Find max x value and max y value
    max_x, max_y = max(X), max(Y)
    # max_e = 0 # energy will be at least 0, cuz the butterfly need not move at all 
    cuteButterflyHelper(0, max_y+1, True, 0)

    return MAX_ENERGY
    # pass

### Read first line of input
if __name__ == '__main__':
    t = int(sys.stdin.readline())
    for i in range(1, t+1):
        ### Question IO here 
        ## a,b,c,d = map(int, sys.stdin.readline().split())
        n, e = map(int, sys.stdin.readline().split())
        VISITED = [False]*n
        MAX_ENERGY = 0
        X, Y, C = list(), list(), list() #i-th index represents x[i], y[i], c[i]
        for j in range(n): ## Describes flowers
            x, y, c = map(int, sys.stdin.readline().split())
            X.append(x); Y.append(y); C.append(c)
        ### ==========================
        cuteButterfly(X, Y, C, e)
        print("Case #{}: {}".format(i, MAX_ENERGY))

