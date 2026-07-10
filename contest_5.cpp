#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MOD = 1000000007;
//для a^(MOD-2)
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

//обратное число
long long modInverse(long long n) {
    return power(n, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    int n = s.length();
    
    vector<long long> fact(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    //частота каждой буквы
    vector<int> count(26, 0);
    for (char c : s) {
        count[c - 'a']++;
    }

    long long ans = fact[n];
    //делим на факториал повторяющихся 
    for (int i = 0; i < 26; i++) {
        if (count[i] > 1) { 
            ans = (ans * modInverse(fact[count[i]])) % MOD;
        }
    }

    cout << ans << "\n";

    return 0;
}