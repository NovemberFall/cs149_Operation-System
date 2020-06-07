#include <iostream>

using namespace std;

int main() {
    int baseChar;
    int headChar;

    cin >> baseChar >> headChar;

    cout << "     " << headChar << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cout << baseChar;
        }
        if (i == 0 || i == 2) {
            cout << headChar << headChar << endl;
        } else {
            cout << headChar << headChar << headChar << endl;
        }
    }
    cout << "     " << headChar << endl;
    return 0;
}