#include <iostream>
#include <ncurses.h>

#include "Interface.h"
#include "Terminal.h"

using namespace std;
using namespace term;

int main() {

    Terminal &terminal = Terminal::instance();

    Interface* interface = new Interface(terminal);

    interface->menu();

    delete interface;

    return 0;
}
