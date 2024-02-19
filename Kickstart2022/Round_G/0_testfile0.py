import sys
import math
import random
import functools, itertools, collections, heapq, bisect
from collections import Counter, defaultdict, deque

POS_INF = float('inf')
NEG_INF = float('-inf')
INT_MAX = sys.maxsize
INT_MIN = -sys.maxsize
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

# ================= TEMPLATE ENDS HERE ==================
def solve(PARAMS):
    ### Implemenation
    pass
    





### Read first line of input
t = int(sys.stdin.readline())
for i in range(1, t+1):
    ### Question IO here
    ## a,b,c,d = map(int, sys.stdin.readline().split())





    ### ==========================
    ans = solve()
    print("Case {}: {}".format(i, ans))

