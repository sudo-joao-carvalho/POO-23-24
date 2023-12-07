#include <iostream>
#include <ncurses.h>

#include "Interface.h"
#include "Terminal.h"
#include "GestorHabitacao.h"

using namespace std;
using namespace term;

int main() {

    Terminal &terminal = Terminal::instance();

    GestorHabitacao* gestorHabitacao = new GestorHabitacao();

    Interface* interface = new Interface(terminal, gestorHabitacao);

    interface->menu();

    delete interface;
    delete gestorHabitacao;

    return 0;
}
