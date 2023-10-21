#include <iostream>

#include "Interface.h"
#include "Habitacao.h"

using namespace std;

int main() {

    Habitacao* habitacao = new Habitacao();
    Interface* interface = new Interface(habitacao);

    interface->menu();

    delete habitacao;
    delete interface;

    return 0;
}
