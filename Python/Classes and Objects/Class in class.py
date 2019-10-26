#First method
"""class person:
    class dob:
        def __init__(self,date):
            self.date=date
        def display(self):
            print(self.date)
obj=person();
obj1=person().dob('01/11/1999')
obj1.display()"""

class person:
    def __init__(self):
        self.obj1=self.dob('01/04/1999')
    class dob:
        def __init__(self, date):
            self.date = date
            self.display()
        def display(self):
            print(self.date)
obj=person()