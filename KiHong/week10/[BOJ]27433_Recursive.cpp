#include <iostream>

using namespace std;


long long Recursive(int n) {
    if (n < 2) return 1;
    return n * Recursive(n-1);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n = 0;
    cin >> n;
    
    cout << Recursive(n) << '\n';
    
    return 0;
}