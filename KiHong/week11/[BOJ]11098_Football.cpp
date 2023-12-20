/*

*/

#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n;
    cin >> n;

    while (n--) {
        int p = 0;
        int best = 0;
        string selected = "";

        cin >> p;

        while (p--) {
            int money = 0;
            string name = "";
            cin >> money >> name;

            if (money > best) {
                best = money;
                selected = name;
            }
        }

        cout << selected << '\n';
    }

    return 0;
}