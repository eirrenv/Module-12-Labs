#include <iostream>
#include <deque>
#include <random> // probability
#include <string>
#include <array>
#include <cstdlib>
#include "Car.h"
using namespace std;

void printQueue(deque<Car> carQ); // prototype for printing car queue function

int main() {
    srand(time(0));

    array<deque<Car>, 4> tollBooth; // create toll booth array with 4 lanes

    for (int i = 0; i < tollBooth.size(); ++i) {
        tollBooth.at(i).push_back(Car());
        tollBooth.at(i).push_back(Car());
    }

    cout << "Initial queue:" << endl;
    for (int i = 0; i < tollBooth.size(); ++i) {
        cout << "Lane " << i + i << ":" << endl;
        printQueue(tollBooth.at(i));
    }

    /* commenting out to test array
    int random;

    int count = 1;
    while(!carQueue.empty()) {
        random = rand() % 100;
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