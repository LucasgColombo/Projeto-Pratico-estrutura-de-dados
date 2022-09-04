#ifndef FUNCOES_HPP

#define FUNCOES_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

struct Call_911
{
    unsigned int id;
    float lat;
    float lgn;
    char desc[120];
    float zip;
    char title[75];
    char timeStamp[75];
    char twp[40];
    char addr[75];
    int e;
    bool flag;
};
void menu();
void lerRegistros();
void lerPos(int p1, int p2);
void alterarDados(int pos0,Call_911 New);
void alterarPos(int p1, int p2);
void inserirNovoRegistro(int posicaoInsercao, Call_911 New);
void deletar(int p_delete);



#endif