#include <iostream>
#include "event_system_basic.h"

using std::cout;    using std::endl;


int main(int argc, char* argv[]) {
    Event SomeBasicEvent{};

    cout << endl << "Testing Basic Event System." << endl << endl;
    
    cout << "Triggering event: " << endl;
    SomeBasicEvent();

    cout << endl << "Creating DoSomething1 - ";
    EventHandler DoSomething1 = []() {
        cout << "DoSomething1 notified!" << endl;
    };
    cout << "Adding DoSomething1" << endl;
    SomeBasicEvent.addHandler(DoSomething1);

    cout << "Creating DoSomething2 - ";
    EventHandler DoSomething2 = []() {
        cout << "DoSomething2 notified!" << endl;
    };
    cout << "Adding DoSomething2" << endl;
    SomeBasicEvent += DoSomething2;

    cout << endl << "Triggering event: " << endl;
    SomeBasicEvent();

    cout << endl << "Removing DoSomething1" << endl;
    SomeBasicEvent -= DoSomething1;

    cout << endl << "Triggering event: " << endl;
    SomeBasicEvent();

    cout << endl << "Testing Complete." << endl;
    
    return 0;
}
