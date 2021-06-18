#include<stdio.h>
//#include<iostream>
using namespace std;

struct Queue
{
    // Initialize front and rear
    int rear, front;

    // Circular Queue
    int size;
    int *arr;

    Queue(int s)
    {
       front = rear = -1;
       size = s;
       arr = new int[s];
    }

    void enQueue(int value);
    int deQueue();
    void displayQueue();
    void frontEle();
};


/* Function to create Circular queue */
void Queue::enQueue(int value)
{
    if ((front == 0 && rear == size-1) ||
            (rear == (front-1)%(size-1)))
    {
        printf("\nQueue is Full");
        return;
    }

    else if (front == -1) /* Insert First Element */
    {
        front = rear = 0;
        arr[rear] = value;
    }

    else if (rear == size-1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }

    else
    {
        rear++;
        arr[rear] = value;
    }
}

// Function to delete element from Circular Queue
int Queue::deQueue()
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return 0;
    }

    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size-1)
        front = 0;
    else
        front++;

    return data;
}

// Function displaying the elements
// of Circular Queue
void Queue::displayQueue()
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ",arr[i]);
    }
    else
    {
        for (int i = front; i < size; i++)
            printf("%d ", arr[i]);

        for (int i = 0; i <= rear; i++)
            printf("%d ", arr[i]);
    }
}
void Queue::frontEle()
{
    printf("\nfront: %d",arr[front]);
}

/* Driver of the program */
int main()
{
    Queue q(4);

   /* // Inserting elements in Circular Queue
    q.enQueue(10);
    q.enQueue(50);
    q.enQueue(80);

    // Display elements present in Circular Queue
    q.displayQueue();

    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", q.deQueue());

    q.enQueue(200);
    q.enQueue(70);
    q.enQueue(150);

    q.displayQueue();

    printf("\nDeleted value = %d", q.deQueue());
    printf("\nDeleted value = %d", q.deQueue());
    printf("\nDeleted value = %d", q.deQueue());

    q.displayQueue();*/
    int choice;
    int n;
    printf("\n1.Enqueue\n2.Dequeue\n3.Front\n4.Display");
    do
    {
       printf("\nEnter Choice:");
       scanf("\n%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter data");
            scanf("\n%d",&n);
            q.enQueue(n);
            break;
        case 2:
            q.deQueue();
            q.displayQueue();
            break;
        case 3:
            q.frontEle();
            break;
        case 4:
            q.displayQueue();

        }
    }
    while(choice!=5);

    return 0;
}
