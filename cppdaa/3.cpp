#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item { 
    double value, weight, ratio; 
};

int main() {
    int n; 
    double capacity;
    cout << "Number of items: "; 
    cin >> n;
    
    vector<Item> a(n);
    for(int i = 0; i < n; i++) {
        cout << "Value and weight of item " << i + 1 << ": ";
        cin >> a[i].value >> a[i].weight;
        if(a[i].weight <= 0) { 
            cout << "Weight must be positive.\n"; 
            return 1; 
        }
        a[i].ratio = a[i].value / a[i].weight; // Calculate value-to-weight ratio
    }
    
    cout << "Knapsack capacity: "; 
    cin >> capacity;

    // Sort items in descending order of their value-to-weight ratio
    sort(a.begin(), a.end(), [](const Item& x, const Item& y) {
        return x.ratio > y.ratio;
    });

    double total = 0;
    for(auto &x : a) {
        if(capacity <= 0) break;
        double take = min(capacity, x.weight); // Take whole item or a fraction
        total += take * x.ratio;
        capacity -= take;
        cout << "Taken weight: " << take << ", value: " << take * x.ratio << '\n';
    }

    cout << fixed << setprecision(2) << "Maximum value = " << total << '\n';
}
