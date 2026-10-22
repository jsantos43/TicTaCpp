#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <iostream>
#include <ctype.h>

class Tabuleiro {
  private:
    char valores[3][3];
    char ganhador;
    int total_jogadas;
  public:
    Tabuleiro();
    Tabuleiro(Tabuleiro&);
    void imprimir();
    void imprimir_jogo();
    void limpar_tela();
    bool verificar_fim();
    bool registrar_jogada(int, char);
    char get_ganhador();
};

#endif