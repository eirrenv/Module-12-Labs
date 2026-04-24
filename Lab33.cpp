#include <iostream>
#include <deque>
#include <random> // probability
#include <string>
#include <cstdlib>
#include "Car.h"
using namespace std;

void printQueue(deque<Car> carQ); // prototype for printing car queue function

int main() {
    srand(time(0));

    deque<Car> carQueue(2); // create deque for car list

    cout << "Initial queue:" << endl;
    printQueue(carQueue);

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