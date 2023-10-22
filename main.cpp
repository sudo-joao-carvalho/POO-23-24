#include <iostream>

#include "Interface.h"

using namespace std;

int main() {

    Interface* interface = new Interface();

    interface->menu();

    delete interface;

    return 0;
}
