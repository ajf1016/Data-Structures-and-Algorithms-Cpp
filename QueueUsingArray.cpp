#include <iostream>
using namespace std;

class Queue{
public:
	int cap,f,r;
	int *arr;

	Queue(int c){
		cap = c;
		f = r = -1;
		arr = new int[cap];
	}

	bool isEmpty(){
		return f==-1;
	};
	bool isFull(){
		return (r + 1) % cap == f;
	};

	void enq(int val){
		if(isFull()){
			cout<<"Q is full..\n";
			return;
		}

		if(isEmpty()){
			r = f = 0;
		}else{
			r = (r + 1) % cap;
		}
		arr[r] = val;
	};

	void deq(){
		if(isEmpty()){
			cout<<"Q is empty..\n";
			return;
		}

		if(f == r){
			f = r = -1; 
		}else{
			f = (f + 1) % cap;
		}
	};
	int peek(){
		if(isEmpty()){
			cout<<"Q is empty..\n";
			return -1;
		}

		return arr[f];
	};

	void display(){
		if(isEmpty()){
			cout<<"Q is empty..\n";
			return;
		}
		int i = f;
		cout<<"Q : elmes.. : ";
		do{
			 cout << arr[i] << " ";
        	i = (i + 1) % cap;
		}while(i != (r + 1) % cap);
	}
};

int main(){
	cout<<"Hello world..\n";
	Queue q1(100);
	q1.enq(1);
	q1.enq(2);
	q1.enq(3);
	q1.enq(4);
	q1.display();
	q1.deq();
	q1.display();
	cout<<"PEEK : "<<q1.peek();

	return 0;
}