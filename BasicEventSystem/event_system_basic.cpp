#include "event_system_basic.h"

using std::vector;
using std::unique_ptr;


void Event::notifyHandlers() {
    vector<unique_ptr<EventHandler>>::iterator func = this->handlers.begin();
    for(; func != this->handlers.end(); ++func) {
        if(*func != nullptr) {
            (*(*func))();
        }
    }
}

void Event::addHandler(const EventHandler &handler) {
    this->handlers.push_back(unique_ptr<EventHandler>(new EventHandler{handler}));
}

void Event::removeHandler(const EventHandler &handler) {
    vector<unique_ptr<EventHandler>>::iterator to_remove = this->handlers.begin();
    for(; to_remove != this->handlers.end(); ++to_remove) {
        if(*(*to_remove) == handler) {
            this->handlers.erase(to_remove);
            break;
        }
    }
}

void Event::operator()() {
    this->notifyHandlers();
}

Event &Event::operator+=(const EventHandler &handler) {
    this->addHandler(handler);

    return *this;
}

Event &Event::operator-=(const EventHandler &handler) {
    this->removeHandler(handler);

    return *this;
}
