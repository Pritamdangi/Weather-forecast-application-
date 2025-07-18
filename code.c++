#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
using namespace std;
using namespace std::chrono;

void showIndianTime() {
    time_t now = time(0);
    now += 19800; 

    tm *ltm = gmtime(&now); 

    cout << "Indian Standard Time (IST): ";
    cout << (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour << ":"
         << (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min << ":"
         << (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec << "\n";
}

int main() {
    bool running = false;
    steady_clock::time_point startTime, endTime;
    duration<double> elapsed = seconds(0);

    int choice;

    do {
        cout << "\n===== Stopwatch & Clock Application (IST) =====\n";
        showIndianTime();
        cout << "Stopwatch Elapsed Time: " << elapsed.count() << " seconds\n";

        cout << "\nChoose an option:\n";
        cout << "1. Start Stopwatch\n";
        cout << "2. Stop Stopwatch\n";
        cout << "3. Reset Stopwatch\n";
        cout << "4. Show Current IST Time\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (!running) {
                    startTime = steady_clock::now();
                    running = true;
                    cout << "Stopwatch started.\n";
                } else {
                    cout << "Stopwatch is already running.\n";
                }
                break;

            case 2:
                if (running) {
                    endTime = steady_clock::now();
                    elapsed += endTime - startTime;
                    running = false;
                    cout << "Stopwatch stopped.\n";
                } else {
                    cout << "Stopwatch is not running.\n";
                }
                break;

            case 3:
                elapsed = seconds(0);
                running = false;
                cout << "Stopwatch reset.\n";
                break;

            case 4:
                showIndianTime();
                break;

            case 5:
                cout << "Exiting application.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

        this_thread::sleep_for(milliseconds(5000)); // small delay

    } while (choice != 5);

    return 0;
}
