#include <iostream>
class Array
{
    int *arr;
    int size{0};

public:
    Array() = default;
    Array(int s) : size(s) {}
    void getdetails();
    void sort();
    void swap(int &v1, int &v2);
    void print();
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
    for (i = 0; i < size; i++)
    {
        std::cout << "Enter the Elements:";
        std::cin >> arr[i];
    }
}
void Array::sort()
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
void Array::swap(int &v1, int &v2)
{
    int temp;
    temp = v1;
    v1 = v2;
    v2 = temp;
}
void Array::print()
{
    int i;
    std::cout << "Array is: ";
    for (i = 0; i < size; i++)
    {
        std::cout << arr[i] << "  ";
    }
}
int main()
{
    Array s1;
    s1.getdetails();
    s1.sort();
    s1.print();
}