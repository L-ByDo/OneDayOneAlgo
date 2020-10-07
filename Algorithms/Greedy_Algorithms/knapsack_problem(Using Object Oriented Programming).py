class total:
    def __init__(self,weight,value,index):   #setting instance variables to objects
        self.weight=weight
        self.value=value
        self.index=index
        self.cost=value/weight

    def __lt__(self, other):   #operator overloading to compare two objects' costs. Called whenever objects will be
        # comapred
        return self.cost < other.cost

class final_value:
    @staticmethod  #can be used by any member thats why called static method
    def get_max(weights,values):
        max_weight_per_unit=[]
        for i in range(0,len(weights)):
            max_weight_per_unit.append(total(weights[i],values[i],i))
        print(max_weight_per_unit)
        #initialize instance variables of objects and place them in this list
        max_weight_per_unit.sort(reverse=True)  #sort the objects
        print(max_weight_per_unit)
        for objct in max_weight_per_unit:
            print(objct.value, objct.weight, objct.cost)

        total_value=0 
        capacity=50

        for objct in max_weight_per_unit:
            
            if capacity>=int(objct.weight):   #if more capacity than current object's weight, then simply add the value
                # to total value
                total_value=total_value+int(objct.value)
                capacity-=int(objct.weight)

            else:
                total_value+=int(objct.value)*(int(capacity)/int(objct.weight))  #else add some part of value of the object
                break

        return total_value
weights=[10,40,20,30]
values=[60,40,100,120]
max_value=final_value.get_max(weights,values)
print(max_value)
