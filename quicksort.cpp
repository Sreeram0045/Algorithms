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
    int getsize()
    {
        return size;
    }
    int partition(int start, int end);
    void quicksort(int l, int h);
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
void Array::swap(int &v1, int &v2)
{
    int temp;
    temp = v1;
    v1 = v2;
    v2 = temp;
}
void Array::quicksort(int l, int h)
{
    if (l < h)
    {
        int j = partition(l, h);
        quicksort(l, j - 1);
        quicksort(j + 1, h);
    }
}
int Array::partition(int start, int end)
{
    int pivot = arr[start], i = start, j = end;
    while (i < j)
    {
        while (arr[i] <= pivot)
        {
            ++i;
        }
        while (arr[j] > pivot)
        {
            --j;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[start], arr[j]);
    return j;
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
    Array s1(5);
    s1.getdetails();
    s1.quicksort(0, s1.getsize() - 1);
    s1.print();
}