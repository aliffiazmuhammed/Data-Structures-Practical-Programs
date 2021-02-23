//DEQueue

#include<stdio.h>
#include<stdlib.h>

int a[20],front=-1,rear=-1;

void display(int n)
{
	int f=front, r=rear;
	printf ("\nThe queue is:\n");
	if(f!=-1)
	{
		if(f<=r)
		{
			for(int i=f;i<=r;i++)
				printf("%d ", a[i]);
		}
		else
		{
			for(int i=f;i<=n-1;i++)
				printf("%d ", a[i]);
			f=0;
			for(int i=f;i<=r;i++)
				printf("%d ", a[i]);
		}
		printf("\n");
	}
	else
		printf("empty\n");
}

void insertFront(int n)
{
	if ((front==0 && rear==n-1) || front==rear+1)
		printf("Queue overflow\n");
	else
	{
		if(front==-1)
			front=rear=0;
		else if(front==0)
			front=n-1;
		else
			front--;
	
	printf("\nEnter the element to be inserted\n");
	scanf("%d",&a[front]);
	display(n);
	}
}

void insertRear(int n)
{
	if ((front==0 && rear==n-1) || front==rear+1)
		printf ("Queue overflow\n");
	else
	{
		if(front==-1)
			front=rear=0;
		else if(rear==n-1)
			rear=0;
		else
			rear++;

		printf("\nEnter the element to be inserted\n");
		scanf("%d", &a[rear]);
		display(n);
	}
}

void deleteFront(int n)
{
	if(front==-1)
		printf ("Queue underflow\n");
	else
	{
		printf("\nDeleted element %d from queue\n", a[front]);
		if (front==rear)
			front=rear=-1;
		else if(front==n-1)
			front=0;
		else
			front++;
	}
	display(n);
}

void deleteRear(int n)
{
	if(front==-1)
		printf("Queue underflow\n");
	else
	{
		printf("\nDeleted element %d from queue\n", a[rear]);
		if(front==rear)
			front=rear=-1;
		else if(rear==0)
			rear=n-1;
		else
			rear--;
	}
	display(n);
}

void main()
{
	int n, choice;
	
	printf("Enter the size of double ended queue\n");
	scanf("%d", &n);
	while(1)
	{
		printf("\nDouble Ended Queue\n__________________\n");
		printf("1. Insert at front end\n2. Insert at rear end\n3. Delete at front end\n4. Delete at rear end\n5. Display\n6. Exit\n");
		printf("\nEnter your choice\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:	insertFront(n);
					break;
			case 2:	insertRear(n);
					break;
			case 3: deleteFront(n);
					break;
			case 4:	deleteRear(n);
					break;
			case 5:	display(n);
					break;
			case 6:	exit(0);
			default:printf("Invalid choice\n");
					
		}
	}
}





