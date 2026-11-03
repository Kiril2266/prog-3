#include <bits/stdc++.h>
using namespace std;

int binary_search(int *arr, int l, int r, int x)
{
    int m;

    if(l > r)
    {
        return -1;
    }
        m = (l + r)/2;

        if(x == *(arr+m))
        {
            return m;
        }
        if(x < *(arr+m))
        {
            return binary_search(arr, l, m - 1, x);
        }
        if(x > *(arr+m))
        {
            return binary_search(arr, m + 1 , r, x);
        }
}

int main()
{

int n, x;
cin >> n;
int arr[n];
for(int i=0; i<n; i++)
{
    cin >> *(arr+i);
}

cin >> x;

sort(arr, arr+n);

int rez = binary_search(arr, 0, n-1, x);

if(rez == -1)
{
    cout << "Not Found";
}
else
{
    cout << "Found";
}

return 0;
}
