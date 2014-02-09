#ifndef _RDB_EVENT_SYSTEM_H_
#define _RDB_EVENT_SYSTEM_H_

#include <vector>
#include <functional>
#include <memory>
#include <iostream>


class EventHandler {
public:
    using Func = std::function<void()>;

private:
    Func _func;

public:
    int id;
    static int counter;

    EventHandler() : id{0} {
    }

    EventHandler(const Func &func) : _func{func} {
        this->id = ++EventHandler::counter;
        std::cout << EventHandler::counter << std::endl;
    }

    void operator()();
    void operator=(const EventHandler &func);
    bool operator==(const EventHandler &del);
    bool operator!=(nullptr_t);
};


class Event {
    std::vector<std::unique_ptr<EventHandler>> handlers;

    void notifyHandlers();
public:
    void addHandler(const EventHandler &handler);
    void removeHandler(const EventHandler &handler);
    void operator()();
    Event &operator+=(const EventHandler &handler);
    Event &operator+=(const EventHandler::Func &handler);
    Event &operator-=(const EventHandler &handler);
    int totalHandlers() { return this->handlers.size(); }
};

#endif // _RDB_EVENT_SYSTEM_H_
