#include <iostream>
#include <deque>
#include <random> // probability
#include <string>
#include <array>
#include <cstdlib>
#include "Car.h"
using namespace std;

const int MAX_TIME = 20; // time periods
const int PAY_LEAVE = 46; // paying and leaving probability
const int JOIN_QUEUE = 85; // joining queue probability
const int EMPTY_QUEUE = 50; // if queue empty, 50/50 probability of joining

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
    int laneShift = 0; // lane to shift to
    int count = 1;
    int lane = 1;

    for (int i = 0; i < MAX_TIME; ++i) {
        
        cout << "Time: " << count << endl; // print time interval

        lane = 1; // lane counter, setting lane to 1
        for (int j = 0; j < tollBooth.size(); ++j) {
            random = rand() % 100; // randomize probability for each lane
            cout << "Lane: " << lane;
            if (tollBooth.at(j).empty()) { // if lane empty, 50/50 new car enters queue
                if (random <= EMPTY_QUEUE) {
                    cout << " Joined: ";
                    tollBooth.at(j).push_back(Car());
                    tollBooth.at(j).back().print();
                }
                else {
                    cout << " No cars joined. " << endl;
                }
            }    
            else if (random <= PAY_LEAVE) { // if car paid
                cout << " Paid: ";
                tollBooth.at(j).front().print();
                tollBooth.at(j).pop_front();
            }
            else if (random <= JOIN_QUEUE){ // car joined
                cout << " Joined: ";
                tollBooth.at(j).push_back(Car());
                tollBooth.at(j).back().print();
            }
            else { // rear car shifts lanes
                if (!tollBooth.at(j).empty()) {
                    while (laneShift == j) { // get random lane other than current lane
                        laneShift = rand() % 4;
                    }
                    Car tmpCar = tollBooth.at(j).back();
                    cout << " Switched: ";
                    tmpCar.print();
                    tollBooth.at(laneShift).push_back(tmpCar);
                    tollBooth.at(j).pop_back();
                }
            }
            ++lane;
        }
        for (int i = 0; i < tollBooth.size(); ++i) { // print queues
            cout << "Lane " << i + 1 << " Queue:" << endl;
            printQueue(tollBooth.at(i));
        }
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