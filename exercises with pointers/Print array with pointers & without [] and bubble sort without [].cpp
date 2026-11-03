#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int *a, int n)
{
   for(int i = 0; i < n; i++)
   {
       for(int j = 0; j < n - i - 1; j++)
       {
           if(*(a+j) > *(a+j+1))
           {
               int x = *(a+j);
               *(a+j) = *(a+j+1);
               *(a+j+1) = x;
           }
       }
   }
}

void print_arr(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << *(a+i)<< " ";
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> *(a+i);
    }
    bubble_sort(a, n);
    print_arr(a, n);

    return 0;
}
