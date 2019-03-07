// Dezyne Header Files
#include <dzn/runtime.hh>
#include <dzn/locator.hh>

//STL Header Files
#include <iostream>

// Model Header Files
#include "AlarmingSystem.hh"
#include "IController.hh"

int main() {

    dzn::locator loc;
    dzn::runtime rt;
    loc.set(rt);

    AlarmingSystem as(loc);
    as.iController.in.validPinCode();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}