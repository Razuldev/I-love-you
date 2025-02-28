#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>

#ifdef _WIN32
#include <windows.h>
void enableConsoleColors() {
    SetConsoleOutputCP(65001);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}
#else
void enableConsoleColors() {}
#endif

using namespace std;

class LoveSimulator {
    string soulmate;
    const string pink = "\033[38;5;206m";
    const string red = "\033[31m";
    const string cyan = "\033[36m";
    const string reset = "\033[0m";

    struct MemoryFragment {
        string content;
        bool unlocked;
    };

    vector<MemoryFragment> memories = {
        {"template<typename T> T dedication;", false},
        {"while(time.exists()) { heart.beat_for(you); }", false},
        {"constexpr auto forever = []{ return true; };", false}
    };

public:
    LoveSimulator() {
        enableConsoleColors();
        cout << cyan << R"(
        ***************************************
        *                                     *
        *        Love Simulation v1.0         *
        *      A Journey Through Emotions     *
        *                                     *
        ***************************************
        )" << reset << endl;
    }

    void start() {
        cout << pink << "\nHey! What's your name? ";
        getline(cin, soulmate);

        cout << cyan << "\nInitializing heart modules..." << reset;
        for (int i = 0; i < 3; ++i) {
            this_thread::sleep_for(chrono::seconds(1));
            cout << "❤ ";
        }

        cout << "\n\n" << soulmate << ", your emotional engine is ready.\n";
        this_thread::sleep_for(chrono::seconds(2));

        unlockMemories();
    }

private:
    void unlockMemories() {
        cout << pink << "\nRetrieving memories...\n" << reset;

        for (auto &fragment : memories) {
            cout << cyan << "\nProcessing: ";
            for (int i = 0; i < 20; ++i) {
                cout << "✨";
                this_thread::sleep_for(chrono::milliseconds(100));
            }

            fragment.unlocked = true;
            cout << "\n" << red << fragment.content << " [LOADED]" << reset;
        }

        cout << "\n\nExecute love.exe? (yes/no): ";
        string response;
        cin >> response;

        if (response == "yes") {
            runLoveProgram();
        } else {
            cout << red << "\n[ERROR] EmotionalCoreException: Connection not established\n" << reset;
        }
    }

    void runLoveProgram() {
        cout << "\n\n" << pink << R"(
        Compiling love algorithm...

        #include <eternity>
        using namespace emotions;

        int main() {
            constexpr auto my_heart = [this]{
                return std::make_shared<Commitment>(
                    "Unbreakable promises",
                    "Handling life's exceptions",
                    "Optimized for happiness"
                );
            };

            while(you.exist()) {
                sync(heartbeat);
                create(memories);
                cherish(new std::promise("us"));
            }

            return forever;
        }
        )" << reset << endl;

        cout << "\n\nExecuting... ";
        this_thread::sleep_for(chrono::seconds(2));
        cout << red << "❤ Love Compiled Successfully ❤\n" << reset;

        cout << "\n" << soulmate << ", will you be my ";
        cout << pink << "partner";
        cout << reset << " in this ";
        cout << cyan << "adventure";
        cout << reset << " called life? (yes/no) ";

        string answer;
        cin >> answer;

        if (answer == "yes") {
            cout << "\n\n" << pink << R"(
            ***********************
            *                     *
            *   CONNECTION MADE!  *
            *     LOVE FOUND!     *
            *   (You said yes)    *
            *                     *
            ***********************
            )" << reset << endl;
        } else {
            cout << red << "\n[CRITICAL ERROR] LoveNotDetectedException\n" << reset;
        }
    }
};

int main() {
    LoveSimulator simulation;
    simulation.start();
    return 0;
}
