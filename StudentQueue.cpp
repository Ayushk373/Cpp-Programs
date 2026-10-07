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
    void enqueue(int token)
    {
        if (rear == 5)
        {
          cout << "Queue is OverFlow\n";
          return;
        }
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        A[rear] = token;
        cout << "Student token " << token << " added\n";
    }
    void dequeue()
    {
        if (front == -1 || front > rear)
        {
          cout << "Queue is UnderFlow\n";
          return;
        }
        cout << "Student with token " << A[front]  << " is processed\n";
        front++;
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
    void peek()
    {
        if (front == -1)
        {
            cout << "Queue is UnderFlow\n";
            return;
        }
        cout << "Front token = " << A[front] << endl;
        cout << "Rear token = " << A[rear] << endl;
    }
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Complete Queue: ";
        for (int i = front; i <= rear; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    int choice, token;
    do
    {
        cout << "\n--- Student Admission Queue ---\n";
        cout << "1. Enqueue Student\n";
        cout << "2. Dequeue Student\n";
        cout << "3. Display Front and Rear\n";
        cout << "4. Display Complete Queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter student token number: ";
            cin >> token;
            q.enqueue(token);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
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

