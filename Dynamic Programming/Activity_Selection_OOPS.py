class A:
    def __init__(self,starting,finishing):
        self.starting=starting
        self.finishing=finishing
    def __lt__(self,other): #operator overloading to sort objects according to finish time
        return self.finishing < other.finishing
class Find:
    
    def cal(self,start,finish):
        value=[]
        for i in range(0,len(start)):
            value.append(A(start[i],finish[i]))  #assigning instance variables to objects
        value.sort()
        count=1
        for i in range(1,len(value)):
            if value[i].starting>=value[i-1].finishing:  #comparing using finishing time
                count+=1
        return count+1

start=[1,3,0,5,8,5]
finish=[2,4,6,7,9,9]
obj=Find()
print(obj.cal(start,finish))
