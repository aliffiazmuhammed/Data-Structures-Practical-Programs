//Priority Queue

#include<stdio.h>
#include<stdlib.h>

struct pqueue
{
  int data, prio;
} p[10], temp;

int front=-1,rear=-1;

void display()
{
	printf("\nThe queue is:\n");

	if(rear==-1)
	{
		printf("empty\n");
		return;
	}

	for(int i=front; i<=rear; i++)
		printf("Element: %d\tPriority: %d\n", p[i].data, p[i].prio);
}

void push(int n)
{
	if(rear==n-1)
		printf("Queue overflow\n");
	else if(rear==-1)
	{
		front=rear=0;
		printf("\nEnter the element and priority\n");
		scanf("%d %d", &p[rear].data, &p[rear].prio);
		display();
	}
	else
	{
		rear++;
		printf("\nEnter the element and priority\n");
		scanf("%d %d", &p[rear].data, &p[rear].prio);

		for(int i=rear;i>front;i--)
		{
			if(p[i].prio > p[i-1].prio)
			{
				temp=p[i-1];
				p[i-1]=p[i];
				p[i]=temp;
			}
		}
		display();
	}
}

void pop(int n)
{
	if(front==-1)
		printf("Queue underflow\n");
	else if(front==rear)
	{
		front=rear=-1;
		display();
	}
	else
	{
		printf("\nPopped element %d of priority %d from queue\n", p[front].data, p[front].prio);
		front++;
		display();
	}
}

void main()
{
	int n, choice;

	printf("Enter the size of priority queue\n");
	scanf("%d", &n);
	while(1)
	{
		printf("\nPriority Queue\n______________\n");
		printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
		printf("\nEnter your choice\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:	push(n);
					break;
			case 2:	pop(n);
					break;
			case 3: display();
					break;
			case 4:	exit(0);
			default:printf("Invalid choice\n");			
		}
	}
}