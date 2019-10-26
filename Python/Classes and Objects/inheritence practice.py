class books:
    title=''
    author=''
    price=0
    def read(self):
        books.title = input()
        books.author = input()
        books.price = int(input())
    def display(self):
        print('Books title:',end="")
        print(books.title,end=" ")
        print('Author:',end="")
        print(books.author,end=" ")
        print('Price:',end="")
        print(books.price)
listO=[]
j=1
print('1:Add or 2:display')
while(1):
    ch=int(input())
    if(ch==1):
        ob = books()
        ob.read()
        listO.append(ob)
    elif(ch==2):
        for i in listO:
            i.display()
    else:
        print('1:Add or 2:display')
        ch=int(input())

