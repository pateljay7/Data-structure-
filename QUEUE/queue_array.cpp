#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 1024
int arr[MAX_SIZE];
int front=0;
int rear=0;

void enQueue(int x){
        arr[front++]=x;
        cout<<x<<" is enQueued\n";
}

bool isEmpty(){
  if(front==rear)
  return true;
  return false;
}

bool isFull(){
  if(front==MAX_SIZE)
  return true;
  return false;
}

void deQueue(){
        if(isEmpty()){
          cout<<"Empty Queue\n";
          cout << INT_MIN;
        }
        int val=arr[rear++];
        cout<<val<<" is deQueued\n";
}

int queue_front(){
  if(isEmpty()){
        cout<<"Empty Queue\n";
        return INT_MIN;
  }
  return arr[front-1];
}
void Display()
{
    printf("\ndisplay");
    printf("\nfront=%d,rear=%d",arr[front],arr[rear]);
    for(int i=front;i<rear;i++)
        printf("\t%d",arr[i]);
}

int main(){
	bool x = isFull();
	cout << x <<endl;
	enQueue(10);
	enQueue(20);
	enQueue(30);
	//deQueue();
	isFull();
	Display();
}
