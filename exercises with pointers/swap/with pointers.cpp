#include <bits/stdc++.h>
using namespace std;

void swap_with_pointers(int *a, int *b)
{
    int x = *a;
    *a = *b;
    *b = x;
}

int main()
{
    int a, b;
    cin >> a >> b;
    swap_with_pointers(&a, &b);
    cout << a << " " << b;

return 0;
}
