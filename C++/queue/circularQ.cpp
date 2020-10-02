#include <iostream>
#define SIZE 5

using namespace std;

class Queue {
   private:
  int items[SIZE], front, rear;

   public:
  Queue() {
    front = -1;
    rear = -1;
  }

  bool isFull() {
    if (front == 0 && rear == SIZE - 1) {
      return true;
    }
    if (front == rear + 1) {
      return true;
    }
    return false;
  }

  bool isEmpty() {
    if (front == -1)
      return true;
    else
      return false;
  }

  void enQueue(int element) {
    if (isFull()) {
      cout << "Queue is full";
    } else {
      if (front == -1) front = 0;
      rear = (rear + 1) % SIZE;
      items[rear] = element;
      cout << endl;
         
    }
  }

  int deQueue() {
    int element;
    if (isEmpty()) {
      cout << "Queue is empty" << endl;
      return (-1);
    } 
	else {
      element = items[front];
      if (front == rear) {
        front = -1;
        rear = -1;
      }

      else {
        front = (front + 1) % SIZE;
      }
      return (element);
    }
  }

  void display() {
    int i;
    if (isEmpty()) {
      cout << endl
         << "Empty Queue" << endl;
    } else {
      for (i = front; i != rear; i = (i + 1) % SIZE)
        cout << items[i];
      cout << items[rear];
    }
  }
};

int main() {
  Queue q;
int o,n;
  	cout<<"**************MENU*****************"<<endl;
  	cout<<"1. ENQUEUE"<<endl<<"2. DEQUEUE"<<endl<<"3. EXIT"<<endl;
  while(o!=3){
        cout<<"enter your choice";
	cin>>o;
    	switch(o){
	case 1:
	    cout<<"enter element to enqueue";
	    cin>>n;
	    q.enQueue(n);
	    q.display();
	    break;
	case 2:
           int p=q.deQueue();
        if (p != -1)
       cout<<"Deleted Element is " << p<<endl;
       q.display();
	   cout<<endl;
        break;
    case 3:
        break;
	}
}

  return 0;
}

