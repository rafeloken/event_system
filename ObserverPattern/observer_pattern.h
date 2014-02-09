#ifndef _RDB_OBSERVER_PATTERN_H_
#define _RDB_OBSERVER_PATTERN_H_

#include <vector>

class Observer {
public:
    void notify();
};

class Subject {
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObservers();
};

#endif // _RDB_OBSERVER_PATTERN_H_
