class numbers:
    count=0
    def __init__(self,list1):
        self.list1=list1
    def display(self):
        if(numbers.count==0):
            for i in self.list1:
                if(i%2==0):
                    print(i,end="")
        else:
            print('\n')
            for i in self.list1:
                if(i%2!=0):
                    print(i,end="")
        numbers.count=numbers.count+1
list12=[]
for i in range(0,9):
    num=int(input())
    list12.append(num)
obj=numbers(list12)
obj1=numbers(list12)
obj.display()
obj1.display()