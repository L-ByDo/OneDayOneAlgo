# -*- coding: utf-8 -*-
"""odd_even_sort_second_last_elem.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1f4f4hb5QIOEJANOnEfnj05tc328ioEwX
"""

#the code is to print second largest number in a given array
#logic is to sort an array and print second last elements
#the algorithm used is brick sort
#this will seperately sort odd and even index and then finally print the list 
arr=[1,43,23,87,5]
for round in range(0,len(arr),1):
    for even_index in range(0,len(arr)-1,2):
        if arr[even_index+1]<arr[even_index]:
            arr[even_index],arr[even_index+1]=arr[even_index+1],arr[even_index]
    for odd_index in range(1,len(arr)-1,2):
        if arr[odd_index+1]<arr[odd_index]:
            arr[odd_index],arr[odd_index+1]=arr[odd_index+1],arr[odd_index]
print(arr[-2])  #print second last element