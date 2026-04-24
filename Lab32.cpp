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

    int random = rand() % 100;
    int count = 1;
    while(!carQueue.empty()) {
        cout << "Time: " << count << " Operation: ";
        if (random <= 45) {
            carQueue.push_back(Car());
            carQueue.back().print();
            cout << endl;
        }
    }

    return 0;
}

void printQueue(deque<Car> carQ) {
    for (int i = 0; i < carQ.size(); ++i) {
        cout << "\t";
        carQ[i].print();
    }
}