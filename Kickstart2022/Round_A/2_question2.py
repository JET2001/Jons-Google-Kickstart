import sys
import math
def digitSum(num : list):
    ''' Calculates the digit sum of num'''
    sum = 0
    i = 0
    while (i < len(num)):
        sum += int(num[i])
    return sum

def challengeNine(N: list):
    digit_sum, digit_count = digitSum(N) ## O(log N)
    ## Corner case where N is a multiple of 9.
    if digit_sum % 9 == 0:
        ## insert a number at the position from the end.
        N.insert("0", 1)
        # print
        return N
    valueToAdd = (digit_sum//9 + 1) * 9 - digit_sum # formula to calculate how much to add.
    #print(valueToAdd)
    ## Insert the value to add at the location where the valueToAdd is smaller than currNum. 
    curr_num = digit_count

    while (curr_num > 0): ## O(log N)
        # print((N % (10**curr_num))//(10**(curr_num-1)))
        if (int(N[curr_num])) <= valueToAdd: curr_num-=1
        else: break
    ## Position to insert is 
    positionToInsert = curr_num
    N.insert(valueToAdd, positionToInsert)
    # small_num_part = N % (10**positionToInsert)
    # large_num_part = N // (10**(positionToInsert)) if positionToInsert < digit_count else 0
    # final_num = large_num_part*10**(positionToInsert+1) + valueToAdd*10**positionToInsert + small_num_part
    # print ("currNum: {} | pos: {} | small part: {} | large part: {} | final_num: {}".format(curr_num, positionToInsert, 
    # small_num_part, large_num_part, final_num))
    return N


T = int(input())
for i in range(1, T+1): 
    N = [c for c in sys.stdin.readline()]
    ans = challengeNine(N)
    print("Case #{}: {}".format(i, int(ans)))


