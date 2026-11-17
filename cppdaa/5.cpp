#include <iostream>
#include <vector>
using namespace std;

int n, solutions = 0;

// Function to check if a queen can safely be placed at (row, col)
bool safe(const vector<int>& q, int row, int col) {
    for(int r = 0; r < row; r++) {
        // Check if same column or same diagonal
        if(q[r] == col || abs(q[r] - col) == abs(r - row)) return false;
    }
    return true;
}

// Recursive backtracking function to place queens row by row
void place(vector<int>& q, int row) {
    if(row == n) {
        solutions++;
        cout << "Solution " << solutions << ":\n";
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) cout << (q[r] == c ? "Q " : " . ");
            cout << '\n';
        }
        cout << '\n';
        return;
    }
    for(int c = 0; c < n; c++) {
        if(safe(q, row, c)) {
            q[row] = c;       // Place queen
            place(q, row + 1); // Recurse to next row
        }
    }
}

int main() {
    cout << "Enter N (e.g. 4): ";
    cin >> n;
    if(n < 1 || n > 15) { cout << "Invalid N\n"; return 1; }
    vector<int> q(n, -1);
    place(q, 0);
    cout << "Total solutions = " << solutions << '\n';
}
