#include <iostream>
#include <algorithm>

using namespace std;

//структура нашей дыры
struct Hole {
    long long mass;
    int index;
};


bool cmp(const Hole& a, const Hole& b) {
    return a.mass < b.mass;
}

const int MAXN = 200005;
Hole holes[MAXN];   //  массив дыр
int order[MAXN];    // номера дыр

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long omega;
    if (!(cin >> n >> omega)) return 0;

    for (int i = 0; i < n; ++i) {
        cin >> holes[i].mass;
        holes[i].index = i + 1; 
    }

    sort(holes, holes + n, cmp);

    bool possible = true;

    //пытаемся съесть дыры
    for (int i = 0; i < n; ++i) {
        if (omega > holes[i].mass) {
            omega += holes[i].mass;         
            order[i] = holes[i].index;  
        } else {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << order[i];
            if (i < n - 1) cout << " ";
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}