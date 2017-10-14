#http://stackoverflow.com/questions/8458315/more-elegant-way-to-create-a-2d-matrix-in-python
'''	
You can use below code snippet to read line by line, till end of file

line = obj.readline()
while(line != ''):

    # Do Something

    line = obj.readline()
'''
#http://mathworld.wolfram.com/BishopsProblem.html
# ^ best explaination

#http://stackoverflow.com/questions/24089090/in-python-how-to-check-the-end-of-standard-input-streams-sys-stdin-and-do-som

import sys

for p in sys.stdin:
	if int(p)==1 :
		print(int(p))
	else:
		print(2*int(p)- 2)
