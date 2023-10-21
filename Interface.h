//
// Created by João Carvalho on 21/10/2023.
//

#ifndef POO_23_24_INTERFACE_H
#define POO_23_24_INTERFACE_H

#include <string>

class Habitacao;

using namespace std;

class Interface {
private:
    Habitacao* habitacao;
    //conjunto de habitaçoes --> como nao existe nenhum numero default de habitaçoes a interface nao vai começar com nenhuma habitaçao no construtor
    //depois vao sendo adicionadas com comandos tendo em conta o numero de zonas que existe

public:
    Interface(Habitacao* habitacao);

    void menu();
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

    //processador de regras --> TODO verificar depois na funcao comandos se estamos nessa fase de introduzir regras
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



};


#endif //POO_23_24_INTERFACE_H
