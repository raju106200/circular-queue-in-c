
#include <stdio.h>

#define MAX 5

int cq[MAX], front = -1, rear = -1;

void enqueue(int x)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Circular Queue Full\n");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    cq[rear] = x;
    printf("%d inserted\n", x);
}

void dequeue()
{
    if (front == -1)
    {
        printf("Circular Queue Empty\n");
        return;
    }

    printf("%d deleted\n", cq[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Circular Queue is empty\n");
        return;
    }

    printf("Circular Queue: ");
    i = front;

    while (1)
    {
        printf("%d ", cq[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

