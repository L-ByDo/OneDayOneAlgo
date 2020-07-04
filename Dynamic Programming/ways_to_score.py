
from threading import Lock,Thread
class Score:
    l=Lock()
    def __init__(self):
        pass 
    l.acquire()  #lock the thread
    def find_ways(self,arr,n,m):
        c = [0] * (m+1)  #initially,all will be zero except 1st
        c[0]=1
        for i in range(n):
            for j in range(len(c)):
                if j>=arr[i]:
                    c[j]+=c[j-arr[i]]
        print("Number of ways are",c[m])
    l.release()  #release the thread
a=Score()
t1=Thread(target=a.find_ways,args=([1,5,10],3,12))
t2=Thread(target=a.find_ways,args=([1,2,3],3,5))
t1.start()
t2.start()