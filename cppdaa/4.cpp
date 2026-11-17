#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, W; 
    cout << "Enter number of items and capacity: ";
    cin >> n >> W;
    
    vector<int> wt(n), val(n);
    for(int i = 0; i < n; i++) {
        cout << "Weight and value of item " << i + 1 << ": ";
        cin >> wt[i] >> val[i];
    }

    // Create a 2D DP table with dimensions (n + 1) x (W + 1) initialized to 0
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the DP table bottom-up
    for(int i = 1; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w]; // Case 1: Exclude current item
            if(wt[i - 1] <= w) {
                // Case 2: Include current item if it fits, take maximum
                dp[i][w] = max(dp[i][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            }
        }
    }

    cout << "Maximum value = " << dp[n][W] << '\n';
}
