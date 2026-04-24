#include <iostream>
#include <deque>
#include <random> // probability
#include <string>
#include <array>
#include <cstdlib>
#include "Car.h"
using namespace std;

const int MAX_TIME = 20; // time periods

void printQueue(deque<Car> carQ); // prototype for printing car queue function

int main() {
    srand(time(0));

    array<deque<Car>, 4> tollBooth; // create toll booth array with 4 lanes

    for (int i = 0; i < tollBooth.size(); ++i) { // insert two initial cars
        tollBooth.at(i).push_back(Car());
        tollBooth.at(i).push_back(Car());
    }

    cout << "Initial queue:" << endl; // print initial queues
    for (int i = 0; i < tollBooth.size(); ++i) {
        cout << "Lane " << i + 1 << ":" << endl;
        printQueue(tollBooth.at(i));
    }

    int random;
    int count = 1;
    int lane = 1;

    for (int i = 0; i < MAX_TIME; ++i) {
        
        cout << "Time: " << count << endl; // print time interval

        lane = 1; // lane counter, setting lane to 1
        for (int j = 0; j < tollBooth.size(); ++j) {
            random = rand() % 100; // randomize probability for each lane
            cout << "Lane: " << lane;
            if (random <= 50 && !tollBooth.at(j).empty()) { // if car paid and lane is not empty
                cout << " Paid: ";
                tollBooth.at(j).front().print();
                tollBooth.at(j).pop_front();
            }
            else { // car joined
                cout << " Joined: ";
                tollBooth.at(j).push_back(Car());
                tollBooth.at(j).back().print();
            }
            ++lane;
        }
        for (int i = 0; i < tollBooth.size(); ++i) { // print queues
            cout << "Lane " << i + 1 << ":" << endl;
            printQueue(tollBooth.at(i));
        }
        ++count;
    }

    /* commenting out to test array
    while(!carQueue.empty()) {
        
        cout << "Time: " << count << " Operation: ";
        if (random <= 45) {
            cout << " Joined lane: ";
            carQueue.push_back(Car());
            carQueue.back().print();
        }
        else {
            cout << " Car paid: ";
            carQueue.front().print();
            carQueue.pop_front();
        }
        printQueue(carQueue);
        ++count;
    }
    */

    return 0;
}

void printQueue(deque<Car> carQ) {
    if (!carQ.empty()) {
        for (int i = 0; i < carQ.size(); ++i) {
            cout << "\t";
            carQ[i].print();
        }
    }
    else {
        cout << "\tEmpty" << endl;
    }
}