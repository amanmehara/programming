#Q-1
"""class student:
    def __init__(self,f_name,l_name):
        self.f_name=f_name
        self.l_name=l_name
    def display(self):
        print('Name:',end="")
        print(self.f_name+" "+self.l_name)
        print('Email:',end="")
        print(self.f_name+"."+self.l_name+"@chitkara.edu.in")
obj1=student('aryan','sohal')
obj1.display()"""

#Q-2
class emp:
    raise_qmt=0.10
    def __init__(self,name,age,pay):
        self.name=name
        self.age=age
        self.pay=float(pay)
    def display(self):
        print(self.name+" ",self.age,end="")
    def display2(self):
        print(self.pay,end="")
        self.pay=self.pay+emp.raise_qmt
        print(self.pay)
obj1=emp('Aryan','20','100000')
obj1.display()
obj1.display2()

