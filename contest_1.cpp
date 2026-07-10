#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    unsigned long long total_int = 0; 
    unsigned long long total_frac = 0;
    const unsigned long long MOD = 1000000000000000ULL; 

    while (cin >> s) {
        int dot_pos = s.find('.');
        
        string int_str = s.substr(0, dot_pos);
        string frac_str = s.substr(dot_pos + 1);

        unsigned long long i_part = stoull(int_str);
        unsigned long long f_part = stoull(frac_str);

        total_int += i_part;
        total_frac += f_part;
    }

    total_int += (total_frac / MOD);
    total_frac = total_frac % MOD;

    cout << total_int << ".";

    string frac_res = to_string(total_frac);
    
    for (int i = 0; i < 15 - frac_res.length(); ++i) {
        cout << "0";
    }
    
    cout << frac_res << "\n";

    return 0;
}