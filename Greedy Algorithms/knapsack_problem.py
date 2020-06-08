# Knapsack is a common Greedy Algo problem.
'''
You have bags of wheat with different weights and a different profits for each.
eg.
profit 5 8 7 1 12 3 4
weight 2 7 1 6 4  2 5
max_weight 100
Calculate the max profit the shopkeeper can make for the given max_weight that could be carried.
'''

#Importing copy module for deepcopy operations
import copy

def calcprofit(profit,weight,max_weight):
    # List created to store profit gained for the 1kg in case of each weight repectively
    prof_by_wei = list()

    # Calculate and append profit/weight for each
    for i in range(len(weight)):
        prof_by_wei.append(profit[i] / weight[i])

    # Creating a copy of the list and sorting proit/weight in ascending order
    temp_pbw = copy.deepcopy(prof_by_wei)
    temp_pbw.sort()

    # declaring useful variables
    l = len(temp_pbw)
    limit = 0
    cost = 0
    i = 0

    # loop till the total weight do not reach max limit i.e. 15 kg and till i<l
    while (limit <= 15 and i < l):

        # flag value for encountered greatest element in temp_pbw
        flag = temp_pbw[l - i - 1]
        '''
        calculating index of the same flag in prof_by_wei list. 
        This will give the index of the first encountered element which is same as of flag. 
        There may be one or more values same as that of flag but .index always encounter the very first element only.
        To curb this, alter the values in prof_by_wei once they are used. Here it is done to -1 because neither profit
        nor weight can be in negative.
        '''
        index = prof_by_wei.index(flag)
        prof_by_wei[index] = -1

        # check if the weight encountered is less than the total weight encountered before.
        if (15 - limit >= weight[index]):

            limit += weight[index]
            # Adding profit gained for the given weight 1 === weight[index]/weight[index]
            cost += 1 * profit[index]

        else:
            # Since the weight encountered is greater than limit, therefore take the required number of remaining kgs and calculate profit for it.
            # weight remaining/ weight[index]
            cost += ((15 - limit) / weight[index]) * profit[index]
            break
        i += 1

    return cost

# print(calcprofit([10,20,30,40,50,60], [2, 4, 6, 8, 10, 12],100))
    # Input profit and weight in form of list
    # profit = [int(x) for x in input().split()]
    # weight = [int(x) for x in input().split()]

