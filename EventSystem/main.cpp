#include <iostream>
#include <string>
#include "event_system.h"

using std::string;
using std::cout;    using std::endl;


void DoSomething4();
void add_num_to_end(int num);


int main(int argc, char* argv[]) {
    cout << endl << "Testing Event System." << endl << endl;
    
    Event SomeEvent{};
    int num = 42;

    cout << "Creating DoSomething1 - ";
    EventHandler DoSomething1 = []() {
        cout << "DoSomething1 notified! - ";
    };
    cout << "Creating DoSomething2 - ";
    // Note: Capturing by value so will grab their current state.
    EventHandler DoSomething2 = [=]() {
        cout << "DoSomething2 notified! - ";
        add_num_to_end(num);
    };

    cout << "Adding DoSomething1" << endl;
    SomeEvent.addHandler(DoSomething1);
    cout << "Adding DoSomething2" << endl;
    SomeEvent += DoSomething2;

    // Change number and show that previous capture doesn't change.
    num = 58;
    // You may add like this as well, however you can't remove it.
    cout << "Creating+Adding DoSomething3 - ";
    // Note: Capturing by reference now so any changes to num will be reflected in this.
    SomeEvent += [&]() {
        cout << "DoSomething3 notified! - ";
        add_num_to_end(num);
    };

    cout << endl << "Triggering Event! (handlers: " << SomeEvent.totalHandlers() << ")" << endl;
    SomeEvent();

    cout << endl << "Removing DoSomething1 - ";
    SomeEvent -= DoSomething1;
    cout << "Removing DoSomething2 - ";
    SomeEvent -= DoSomething2;

    cout << endl << "Triggering Event! (handlers: " << SomeEvent.totalHandlers() << ")" << endl;
    SomeEvent();

    // Creating and adding a handler that has no callable attached.
    cout << endl << "Creating DoSomethingButNotReally" << endl;
    EventHandler DoSomethingButNotReally;
    cout << "Adding DoSomethingButNotReally" << endl;
    SomeEvent += DoSomethingButNotReally;

    cout << "Adding lambda(DoSomething4) - ";
    SomeEvent += DoSomething4;

    cout << endl << "Triggering Event! (handlers: " << SomeEvent.totalHandlers() << ")" << endl;
    SomeEvent();

    cout << endl << "Testing Complete." << endl;
    
    return 0;
}

void DoSomething4() {
    cout << "DoSomething4 notified! - ";
}

void add_num_to_end(int num) {
    cout << "num = " << num << " - ";
}