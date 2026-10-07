
#include <iostream>
using namespace std;

class Queue
{
public:
    int A[6];
    int front;
    int rear;

    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int value)
    {
        if (rear == 5)
        {
            cout << "Queue is Overflow\n";
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        A[rear] = value;

        cout << "Element " << value << " is added in queue\n";
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is Underflow\n";
            return;
        }

        cout << "Element " << A[front] << " deleted\n";
        front++;

        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }

    void display()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue: ";

        for (int i = front; i <= rear; i++)
        {
            cout << A[i] << " ";
        }

        cout << endl;
    }

    void peek()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Front = " << A[front] << endl;
        cout << "Rear = " << A[rear] << endl;
    }
};

int main()
{
    Queue q;
    int choice, value;

    do
    {
        cout << "\n1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display Queue\n";
        cout << "4. Peek\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            q.peek();
            break;

        case 5:
            cout << "Program ended\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}

