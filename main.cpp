#include <iostream>
#include <ctype.h>
#include "src/Tabulerio.h"
using namespace std;

int main(void) {
    Tabuleiro jogo;

    bool fim = false;
    bool jogada_valida;
    int pos;

    while(!fim) {
        jogo.imprimir_jogo();

        
        // Pedir jogada do X
        jogada_valida = false;
        while (!jogada_valida) {
            cout << "Jogador X, digite uma posicao valida: ";
            cin >> pos;

            jogada_valida = jogo.registrar_jogada(pos, 'X');
        }

        fim = !jogo.verificar_ganho();

        // Pedir jogada do X
        jogada_valida = false;
        while (!jogada_valida) {
            cout << "Jogador O, digite uma posicao valida: ";
            cin >> pos;

            jogada_valida = jogo.registrar_jogada(pos, 'O');
        }

        fim = !jogo.verificar_ganho();

        cout << endl;
        cout << "Ganhador: " << jogo.get_ganhador();
    }

    return 0;
}