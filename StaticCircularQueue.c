/******************************************************************************

Write a menu driven program to implement a static circular queue using counter method supporting following operations.
1. Create empty queue, 
2. Insert an element on the queue, 
3. Delete an element from the queue, 
4. Display front, rear element or 
5. Display all elements of the queue.

*******************************************************************************/
#include <stdio.h>
#define MAX 5
int front, rear, count, qu[MAX];

void createQueue(){
    front = -1;
    rear = -1;
    count = 0;
}

int size() {
    return count;
}

int isEmpty() {
    return size() == 0;
}

int isFull() {
    return size() == MAX;
}

void enqueue(int val) {
    if(isFull()) {
        printf("Stack Overflow.....\n");
        return;
    }else{
        front = front == -1 ? 0 : front;
        rear = (rear + 1)%MAX;
        qu[rear] = val;
        count++;
        printf("%d is successfully added to the end of the queue\n",val);
    }
}

int dequeue() {
    int d = NULL;
    if(isEmpty()) {
        printf("Stack underflow\n");
    }else {
        d = qu[front];
        if(front == rear) {
            front = -1;
            rear = -1;
        }else{
            front = (front + 1) % MAX;
        }
        count--;
    }
    return d;
}

int getFront() {
    if(!isEmpty())
        return qu[front];
    else
        return NULL;
}

int getRear() {
    if(!isEmpty())
        return qu[rear];
    else
        return NULL;
}

void displayAll() {
    int i = front,j = 0;
    while(i != -1 && j++ < size()) {
        printf("\t %d",qu[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    int choice = 0,val;
    createQueue();
    
    while(choice != 6){
        printf("1. Add data at the end of the end of queue\n");
        printf("2. Removes the data from the front of the Queue \n");
        printf("3. Display item present at front position \n");
        printf("4. Display item present at rear position \n");
        printf("5. Display all items \n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice){
        case 1:
            printf("Enter the value to be entered: ");
            scanf("%d",&val);
            enqueue(val);
            break;
        case 2:
            val = dequeue();
            if(val != NULL)
                printf("Item with data %d deleted from the front of the queue\n",val);
            break;
        case 3:
            if(getFront() == NULL)
                printf("Queue is empty\n");
            else
                printf("Data present at front end is: %d\n",getFront());
            break;
        case 4:
            if(getRear() == NULL)
                printf("Queue is empty\n");
            else
                printf("Data present at rear end is: %d\n",getRear());
            break;
        case 5:
            displayAll();
            break;
        case 6:
            printf("------------------Bye!!-------------------\n");
            return 0;
        default:
            printf("Input is invalid\n");
        }
    }
    return 0;
}


