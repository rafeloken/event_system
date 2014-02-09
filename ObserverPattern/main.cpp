#include <iostream>
#include "observer_pattern.h"

using std::cout;    using std::endl;


int main(int argc, char* argv[]) {
    
    cout << "Testing Observer Pattern." << endl;
    Subject subject{};
    Observer ob1{};

    cout << "Adding Observer" << endl;
    subject.addObserver(&ob1);
    cout << "Notifying Observers" << endl;
    subject.notifyObservers();

    cout << "Testing Complete." << endl;
    
    return 0;
}
