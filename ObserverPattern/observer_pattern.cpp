#include <iostream>
#include "observer_pattern.h"

using std::vector;
using std::cout;    using std::endl;


void Observer::notify() {
    cout << "notified!" << endl;
}


void Subject::addObserver(Observer* observer) {
    this->observers.push_back(observer);
}

void Subject::removeObserver(Observer* observer) {
    vector<Observer*>::iterator to_remove = this->observers.begin();
    for(; to_remove != this->observers.end(); ++to_remove) {
        if(*to_remove == observer) {
            this->observers.erase(to_remove);
            break;
        }
    }
}

void Subject::notifyObservers() {
    for(auto o : this->observers) {
        if(o != nullptr)
            o->notify();
    }
}
