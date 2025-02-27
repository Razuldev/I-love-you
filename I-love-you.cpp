#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>

using namespace std;

int main() {
    double x, y, size = 10;
    char symbol = '*';
    string message = "I love you"; //an apple of my eyes🍎

    system("color c");  // Windows

    int message_line = 5;

    if (message.length() % 2 != 0) {
        message += " ";
    }
    for (x = 0; x < size; x++) {
        for (y = 0; y <= 4 * size; y++) {
            double d1 = sqrt(pow(x - size, 2) + pow(y - size, 2));
            double d2 = sqrt(pow(x - size, 2) + pow(y - 3 * size, 2));
            if (d1 < size + 0.5 || d2 < size + 0.5) {
                cout << symbol;
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }

    double total_time = 20.0;
    double lines = 2 * size;
    double delay = total_time / (lines * message.length());

    for (x = 1; x < 2 * size; x++) {
        for (y = 0; y < x; y++) {
            cout << " ";
        }
        for (y = 0; y < 4 * size + 1 - 2 * x; y++) {
            if (x >= message_line - 1 && x <= message_line + 1) {
                int idx = y - (4 * size - 2 * x - message.length()) / 2;
                if (idx >= 0 && idx < message.length()) {
                    cout << (x == message_line ? message[idx] : ' ');
                } else {
                    cout << symbol;
                }
            } else {
                cout << symbol;
            }
        }
        cout << endl;

        this_thread::sleep_for(chrono::milliseconds(static_cast<int>(delay * 1000)));
    }
    
    return 0;
}
