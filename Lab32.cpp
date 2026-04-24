#include <iostream>
#include <deque>
#include "Car.h"
using namespace std;

void printQueue(deque<Car> carQ); // prototype for printing car queue function

int main() {

    deque<Car> carQueue(2); // create deque for car list

    cout << "Initial queue:" << endl;
    printQueue(carQueue);
    
    return 0;
}

void printQueue(deque<Car> carQ) {
    for (int i = 0; i < carQ.size(); ++i) {
        cout << "\t";
        carQ[i].print();
    }
}