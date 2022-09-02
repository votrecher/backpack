/* A Naive recursive implementation of
 0-1 Knapsack problem */
#include <iostream>
#include <vector>
using namespace std;


int max(int a, int b) { return (a > b) ? a : b; }


int knapSack(int W, vector <int>&wt, vector <int>&val, int n)
{

    
    int i, w;
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                    K[i - 1][w - wt[i - 1]],
                    K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}


int main()
{
    int n, K;
    cin >> n >> K;
    vector<int> val(n);
    vector<int> wt(n);
    //int val[] = { 60, 100, 120 };
    //int wt[] = { 10, 20, 30 };
    //int W = 50;
    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> v >> w;
        val[i] = v;
        wt[i] = w;
    }
    cout << knapSack(K, wt, val, n);
    return 0;
}

