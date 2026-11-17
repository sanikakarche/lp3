#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

long long fibRecursive(int n) {
    if (n <= 1) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

long long fibIterative(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        long long c = a + b; 
        a = b; 
        b = c;
    }
    return b;
}

int main() {
    int n;
    cout << "Enter n (0 to 45 for recursive timing): ";
    cin >> n;
    
    if (n < 0 || n > 45) { 
        cout << "Enter n between 0 and 45.\n"; 
        return 1; 
    }

    auto s1 = high_resolution_clock::now();
    long long r = fibRecursive(n);
    auto e1 = high_resolution_clock::now();

    auto s2 = high_resolution_clock::now();
    long long it = fibIterative(n);
    auto e2 = high_resolution_clock::now();

    cout << "Recursive Fibonacci: " << r << "\nIterative Fibonacci: " << it << '\n';
    cout << "Recursive time: " << duration<double, milli>(e1 - s1).count() << " ms\n";
    cout << "Iterative time: " << duration<double, milli>(e2 - s2).count() << " ms\n";
    cout << "Recursive space: O(n) stack; iterative space: O(1)\n";
}
