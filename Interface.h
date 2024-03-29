//
// Created by João Carvalho on 21/10/2023.
//

#ifndef POO_23_24_INTERFACE_H
#define POO_23_24_INTERFACE_H

#include <string>

#include "GestorHabitacao.h"
#include "Terminal.h"

//class Habitacao;

using namespace std;
using namespace term;

class Interface {
private:
    GestorHabitacao* gestorHabitacao;

    Terminal& terminal;
    Window windowInstante;
    Window windowComandos;
    Window windowHabitacao;
    Window windowLogs;

    int contador;

public:
    Interface(Terminal& terminal, GestorHabitacao* gestorHabitacao);
    ~Interface() = default;

    void menu();
    void printaHabitacao();
    bool comandos(const string& comando);

    //tempo
    void comandoProx();
    void comandoAvanca(istringstream& iss);

    //gerir habitacao e zonas
    void comandoHnova(istringstream& iss);
    void comandoHrem();
    void comandoZnova(istringstream& iss);
    void comandoZrem(istringstream& iss);
    void comandoZlista();

    //gerir zonas e o seu conteudo
    void comandoZcomp(istringstream& iss);
    void comandoZprops(istringstream& iss);
    void comandoPmod(istringstream& iss);
    void comandoCnovo(istringstream& iss);
    void comandoCrem(istringstream& iss);

    //processador de regras
    void comandoRnova(istringstream& iss);
    void comandoPmuda(istringstream& iss);
    void comandoRlista(istringstream& iss);
    void comandoRrem(istringstream& iss);
    void comandoAsoc(istringstream& iss);
    void comandoAdes(istringstream& iss);

    //interagir com aparelhos
    void comandoAcom(istringstream& iss);

    //salvar/recuperar processador de regras
    void comandoPsalva(istringstream& iss);
    void comandoPrepoe(istringstream& iss);
    void comandoPrem(istringstream& iss);
    void comandoPlista();

    //gerais
    void comandoExec(istringstream& iss); //ficheiro
    void comandoSair();

    void checkWindowLogsFull();
};


#endif //POO_23_24_INTERFACE_H
