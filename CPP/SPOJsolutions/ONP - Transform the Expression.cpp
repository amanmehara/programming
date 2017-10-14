#include <iostream>
#include <cctype>
#include <stdio.h>

using namespace std;
typedef char typ;
typedef int siz;

const siz stacksize = 401;

class stack{
    private:
	typ data[stacksize];
	siz top;
    public:
	stack(){
	    top = -1;	    
	}
	void push(typ);
	typ pop();
	typ get_top();
	typ size(){
	    return top+1;
	}
	void display();
	bool isempty();
};
bool stack::isempty(){
    return top==-1;
}

void stack::push(typ el){
    
    if(top == stacksize-1){
	cout<<"Error: Stack Full\n";
	return ;
    }
    else{
	//cout<<"top-"<<top<<endl;
	data[++top] = el;
    }
}

typ stack::pop(){
    //empty stack is taken care of while calling pop
	return data[top--];

}

typ stack::get_top(){
	//empty stack is taken care of while calling get_top
	return data[top];
}

void stack::display(){
    if(top == -1){
	cout<<"Stack Empty\n";
	return;
    }
    for(siz i=top;i>=0;--i)
	cout<<data[i]<<endl;
    
}

int opert (const char b)
{
  switch (b)
    {//+, -, *, /, ^
    case '+': return 1;
    case '-': return 2;
    case '*': return 3;
    case '/': return 4;
    case '^': return 5;
    case '(': return 10;
    case ')': return 11;
    default : return -1;
    }
}

void displayAR(typ ar[], siz size){
	for(siz i=0;i<size;++i)
		cout<<ar[i];
	cout<<endl;
	}

int main(){
    int t;
    cin>>t;
    cin.ignore('\n',10);
    while(t--){
	typ exp[401],str[401];
	siz s=0,k=0;
	cin>>exp;
	while(exp[k]!='\0')
	    k++;
	siz strsize = k;
		    // now i = size+1
	//cout<<strsize<<endl;	    
	//displayAR(exp,strsize);
	///*
	stack st;
	for(siz j=0;j<=strsize;j++){
	    //cout<<"inhand->"<<exp[j]<<endl;
	    //cout<<"top->"<<st.get_top()<<endl;
	    if(isalpha(exp[j])){
		str[s++] = exp[j];
		//cout<<"aplha-takn"<<endl;
	    }
	    else if(exp[j]!='(' && exp[j]!=')'){	// operators
		if(st.isempty() || opert(exp[j]) > opert(st.get_top()) || st.get_top()=='(')		// when 1st thing == 1 '||' dont check 2nd so no problem of empty stack pop
		    {st.push(exp[j]);
			//cout<<"op pushed in stack\n";
			}
		else if( opert(exp[j]) < opert(st.get_top()) ){
		    while((opert(exp[j]) < opert(st.get_top())) && !st.isempty() && st.get_top()!='('){
			//cout<<"poped"<<st.get_top()<<endl;
			if(st.get_top()!='(')
			    str[s++] = st.get_top();
			st.pop();
			//cout<<"poped"<<endl;
		    }
		    st.push(exp[j]);
		}
	    }
	    else{				// brackets
		if(exp[j]=='(')	st.push(exp[j]);
		else {
		    while(st.get_top() != '(' && !st.isempty()){
			if(st.get_top()!='(')
			    str[s++] = st.get_top();
			st.pop();
			//cout<<"popped\n";
		    }
		    if(!st.isempty())	st.pop();	//last ) remaining
		    
		    
		}	
	    }
	
	}
	while(!st.isempty()){
	    if(st.get_top()!='(')
		str[s++] = st.get_top();
		st.pop();
	}
	str[s] = '\0';
	
	//displayAR(str,strsize+1);
	cout<<str<<endl;
	//*/
    }
     /**/
    return 0;
}

