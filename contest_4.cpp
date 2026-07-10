#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long total_sum = 0;

    for (int i = 0; i < n; ++i) {
        // левая граница подмассива
        long long current_max = a[i]; 
        
        // правая граница подмассива
        for (int j = i; j < n; ++j) {
            if (a[j] > current_max) {
                current_max = a[j];
            }
            
            total_sum += current_max;
        }
    }

    cout << total_sum << "\n";

    return 0;
}