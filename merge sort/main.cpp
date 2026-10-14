#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

void merge(int a[], int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = l;

    int temp[50000];

    while (i <= m && j <= r)
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= m)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    while (j <= r)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    for(int x=l; x<=r; x++)
    {
        a[x]=temp[x];
    }
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
    int m = (l + r) / 2;

    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    int n = 50000;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000 + 1;
    }

    auto start = high_resolution_clock::now();
    mergeSort(arr, 0, n - 1);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast < microseconds > (end - start).count();

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
        if (i % 10 == 9)
        {
            cout << endl;
        }
    }

    cout << "-> Time taken for n = " << n << ": " << duration << " microseconds\n";
    return 0;
}
