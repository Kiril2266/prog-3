#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

bool isSafe(vector<vector<int>>& mat, int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        if (mat[i][b]) return false;
    }
    for (int i = a-1, j = b-1; i >= 0 && j >= 0; i--, j--)
    {
        if (mat[i][j]) return false;
    }
    for (int i = a-1, j = b+1; j < mat.size() && i >= 0; i--, j++)
    {
        if (mat[i][j]) return false;
    }
    return true;
}

void placeQueens(vector<vector<int>>& mat, int a, uint64_t& ans)
{
    if (a == mat.size())
    {
        ans++;
        return;
    }

    for (int i = 0; i < mat.size(); i++)
    {
        if (isSafe(mat, a, i))
        {
            mat[a][i] = 1;
            placeQueens(mat, a+1, ans);
            mat[a][i] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector <int> (n, 0));

    uint64_t ans = 0;

    auto start = high_resolution_clock::now();
    placeQueens(mat, 0, ans);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast < microseconds > (end - start).count();

    cout << ans << endl;
    cout << duration << " " << "microseconds";

    return 0;
}
