#ifndef _RDB_EVENT_SYSTEM_BASIC_H_
#define _RDB_EVENT_SYSTEM_BASIC_H_

#include <vector>
#include <memory>

// Create the function pointer to be used by the Event.
using EventHandler = void(*)();

class Event {
    std::vector<std::unique_ptr<EventHandler>> handlers;

    void notifyHandlers();
public:
    void addHandler(const EventHandler &handler);
    void removeHandler(const EventHandler &handler);
    void operator()();
    Event &operator+=(const EventHandler &handler);
    Event &operator-=(const EventHandler &handler);
};

#endif // _RDB_EVENT_SYSTEM_BASIC_H_
