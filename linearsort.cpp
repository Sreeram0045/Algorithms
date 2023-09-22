#include <iostream>
class Array
{
protected:
    int *arr;
    int size{0};

public:
    Array() = default;
    Array(int s) : size(s) {}
    void getdetails();
    void print();
};
class Sort : public Array
{
public:
    Sort() = default;
    Sort(int s) : Array(s) {}
    void sort();
    void swap(int &a, int &b);
};
void Array::getdetails()
{
    int i;
    if (size == 0)
    {
        std::cout << "Enter the size of the array: ";
        std::cin >> size;
    }
    arr = new int[size];
    std::cout << "Enter the elements of the array: ";
    for (i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
}
void Array::print()
{
    std::cout << "The Sorted array is: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << "  ";
    }
    std::cout << "\n";
}
void Sort::swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void Sort::sort()
{
    int min, i, j, k;
    for (i = 0; i < size - 1; i++)
    {
        min = arr[i];
        k = i;
        for (j = i + 1; j < size; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                k = j;
            }
        }
        swap(arr[i], arr[k]);
    }
}
int main()
{
    Sort s1;
    s1.getdetails();
    s1.sort();
    s1.print();
}