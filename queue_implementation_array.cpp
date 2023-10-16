#include <iostream>
class Queue
{
    int arr[20];
    int front;
    int rear;
    int size{0};

public:
    Queue() = default;
    Queue(int s) : size(s)
    {
        rear = -1;
        front = -1;
    }
    void enqueue();
    void dequeue();
    bool isempty();
    bool isfull();
    void count();
    void adddetails();
};
bool Queue::isempty()
{
    if (rear == -1 && front == -1)
        return true;
    else
        return false;
}
bool Queue::isfull()
{
    if (size == rear + 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Queue::count()
{
    if (rear == -1 && front == -1)
    {
        std::cout << "There are no elements in the queue" << std::endl;
        return;
    }
    std::cout << "Elements of the queue are: ";
    for (int i = front; i < rear + 1; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "The number of elements in the queue is: " << (rear - front) + 1 << std::endl;
}
void Queue::adddetails()
{
    int option;
    while (true)
    {
        std::cout << "Enter 1.Enqueue 2.Dequeue 3.Exit:\n";
        std::cin >> option;
        if (option == 1)
        {
            enqueue();
        }
        else if (option == 2)
        {
            dequeue();
        }
        else
        {
            count();
            std::cout << "Successfully exited from the program" << std::endl;
            break;
        }
    }
}
void Queue::enqueue()
{
    int item;
    if (isfull())
    {
        std::cout << "The queue is full, Queue overflow" << std::endl;
        return;
    }
    std::cout << "Enter the element which needs to be entered into the queue: ";
    std::cin >> item;
    if (isempty())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        ++rear;
    }
    arr[rear] = item;
    count();
}
void Queue::dequeue()
{
    if (rear == -1 && front == -1)
    {
        std::cout << "Queue is empty.Queue underflow" << std::endl;
        return;
    }
    else if (rear == front)
    {
        std::cout << "Dequeued the following element: " << arr[front] << std::endl;
        arr[front] = 0;
        rear = -1;
        front = -1;
    }
    else
    {
        std::cout << "Dequeued the following element: " << arr[front] << std::endl;
        arr[front] = 0;
        ++front;
    }
}
int main()
{
    Queue s1(3);
    s1.adddetails();
}