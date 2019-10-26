#Q-1) Class Average
"""class Student:
    class_avg=0
    list12=[]
    def __init__(self,roll,name,list0):
        self.__roll=roll
        self.__name=name
        self.__list0=list0
    def avg(self):
        sum1=0
        res1=0
        for i in self.__list0:
            sum1=sum1+i
        res1=sum1/len(self.__list0)
        return res1
    def display(self):
        res=0
        sum12=0
        print('Name:' ,end="")
        print(self.__name, end="")
        print(' Roll:', end="")
        print(self.__roll, end=" ")
        print('Marks:', end="")
        print(self.__list0)
        print(' Average Marks:',end="")
        res=self.avg()
        Student.list12.append(res)
        print(res)
        for i in Student.list12:
            sum12=sum12+i
        Student.class_avg=sum12/len(Student.list12)
        print(Student.class_avg)
list1=[99,98,97,92]
list2=[100,100,100,103]
obj1=Student(1,"Aryan",list1)
obj2=Student(2,"Archit",list2)
obj1.display()
obj2.display()"""

#Q-2) instance variable
"""class ins:
    count=0
    def display(self):
        ins.count=ins.count+1
        print(ins.count)
Obj=ins()
Obj1=ins()
Obj.display()
Obj1.display()"""

#Q-3) Emp to my class
"""class emp:
    def __init__(self,name,eno):
        self.name=name
        self.eno=eno
    def display(self):
        print(self.name,end=" ")
        print(self.eno)
class myclass:
    def __init__(self):
        self.obj1=emp('Aryan',1123)
m=myclass()
m.obj1.display()"""


