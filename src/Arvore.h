#ifndef ARVORE_H
#define ARVORE_H

#include <vector>
#include "Tabulerio.h"

struct Node {
  Tabuleiro* jogo;
  Node* pai;
  std::vector<Node*> filhos;
};

class Arvore {
  private:
    struct Node* raiz;
    int quantidade;
  public:
    Arvore(Tabuleiro*);
    bool vazia();
    Node* buscar_node(Node*, Tabuleiro*) const;
    int contar_nodes(Node*) const;
    int tamanho() const;
    int altura_node(Node* n) const;
    int altura() const;
    bool inserir(Tabuleiro*, Tabuleiro*);
    bool existe(Tabuleiro*) const;
    int grau(Tabuleiro*) const;
    bool verificar_terminal(Tabuleiro*) const;
    bool remover(Tabuleiro*);
    int profundidade(Tabuleiro*) const;    
};

#endif