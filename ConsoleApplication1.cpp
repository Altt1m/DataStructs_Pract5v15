#include <iostream>;

using namespace std;

int LinearSearch(int arr[], int x)
{
    int i = 0;
    do
    {
        if (arr[i] == x)
        {
            cout << "Amount of iterations is " << i + 1 << endl;
            return i;
        }
        i++;
    } while (i != 12);

    cout << "Amount of iterations is " << i << endl;
    cout << "Number not found :(" << endl;
    return -1;
}

void Task1()
{
    int arr[12] = { -10, -3, -1, 7, 8, 12, 18, 27, 44, 46, 55, 58 };

    cout << LinearSearch(arr, 7) << endl;
}

int RecursiveBinarySearch(int arr[], int left, int right, int x, int iter, int equal)
{
    iter++;
    equal++; // right < left
    if (right < left)
    {
        cout << "Iterations: " << iter << endl;
        cout << "Equations: " << equal << endl;
        cout << "Number not found :(" << endl;
        return -1;
    }

    int mid = (left + right) / 2;

    equal++; // x == arr[mid]
    if (x == arr[mid])
    {
        cout << "Iterations: " << iter << endl;
        cout << "Equations: " << equal << endl;
        return mid;
    }
    else if (x < arr[mid])
    {
        equal++; // x < arr[mid]
        return RecursiveBinarySearch(arr, left, mid - 1, x, iter, equal);
    }
    else
    {
        equal++; // !(x < arr[mid])
        return RecursiveBinarySearch(arr, mid + 1, right, x, iter, equal);
    }

}

void Task2()
{
    int arr[12] = { -10, -3, -1, 7, 8, 12, 18, 27, 44, 46, 55, 58 };
    int iter = 0, equal = 0;

    cout << RecursiveBinarySearch(arr, 0, 11, 45, iter, equal) << endl;
}

int main()
{
    Task1();
    //Task2();

    return 0;
}
