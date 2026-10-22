#include "Arvore.h"

// Criar raiz
Arvore::Arvore(Tabuleiro* t) {
  raiz = new Node;

  raiz->jogo = t;
  quantidade = 1;
}

// Verificar árvore vazia
bool Arvore::vazia() {
  return (raiz == nullptr);
}

// Buscar nó na árvore
Node* Arvore::buscar_node(Node* atual, Tabuleiro* t) const {
  if (!atual) return nullptr; // Caso não exista

  if (atual->jogo == t) return atual; // Caso é o próprio nó atual

  Node* achou {nullptr}; // Caso o nó esteja nos filhos
  for (int index {0}; index < atual->filhos.size(); index++) {
    achou = buscar_node(atual->filhos.at(index), t);

    if (achou != nullptr) return achou;
  }
  
  return nullptr; // Caso nó não foi encontrado
}

// Contar todos os nós abaixos
int Arvore::contar_nodes(Node* atual) const {
  int total {1};

  for (int index {0}; index < atual->filhos.size(); index++) {
    total += contar_nodes(atual->filhos.at(index));
  }

  return total;
}

// Contar os níveis abaixo de um nó
int Arvore::altura_node(Node* n) const {
  // Caso nó não exista, retirar um o antecessor apontava para um nó inexistente
  if (!n) return -1; 

  int maior = -1;
  for (int index {0}; index < n->filhos.size(); index++) {
    maior = std::max(maior, altura_node(n->filhos.at(index)));
  }
  return maior + 1;
}

// Contar a altura da árvore
int Arvore::altura() const {
  return altura_node(raiz);
}

// Contar o tamanho da árvore
int Arvore::tamanho() const {
  return quantidade;
}

// Adicione um tabuleiro como filho de outro tabuleiro
bool Arvore::inserir(Tabuleiro* anterior, Tabuleiro* jogo_atual) {
  Node *pai = buscar_node(raiz, anterior);

  // Caso nó pai não achado
  if (!pai) return false;

  // Cria um novo nó e configura ele
  Node* novo_node = new Node;
  novo_node->jogo = jogo_atual;
  novo_node->pai = pai;

  // Adiciona o novo nó na rede
  pai->filhos.push_back(novo_node);
  quantidade++;

  return true;
}

// Verifica se um tabuleiro existe dentro da árvore
bool Arvore::existe(Tabuleiro* jogo_procurado) const {
  Node* node_achado = buscar_node(raiz, jogo_procurado);

  return node_achado != nullptr;
}

// Achar Grau = número de filhos de um nó
int Arvore::grau(Tabuleiro* jogo_atual) const {
  Node* n = buscar_node(raiz, jogo_atual);
  
  return n ? n->filhos.size() : -1;
}

// Verificar se um tabuleiro é do nó terminal
bool Arvore::verificar_terminal(Tabuleiro* jogo_atual) const {
  return grau(jogo_atual) == 0;
}

// Remova um node e sua subárvore
bool Arvore::remover(Tabuleiro* jogo) {
    Node* alvo = buscar_node(raiz, jogo);

    // Caso o alvo desejado nem exista na árvore
    if (!alvo) return false;
    
    // Diminuir quantidade de nodes
    quantidade -= contar_nodes(alvo);

    // Caso o alvo seja a raiz
    if (alvo == raiz) { 
      raiz.reset(); return true; 
    }

    auto& irmaos = alvo->pai->filhos;
    irmaos.erase(std::remove_if(irmaos.begin(), irmaos.end(),
                      [alvo](const std::unique_ptr<No>& f) { return f.get() == alvo; }),
                  irmaos.end());   // unique_ptr libera a memória sozinho
    return true;
}

// Achar Profundidade = quantas arestas da raiz até o nó
int Arvore::profundidade(Tabuleiro* jogo) const {
  Node* no = buscar_node(raiz, jogo);
  
  if (!no) return -1; // Caso nó não exista
  
  int d = 0;
  while (no->pai) { // Faça uma busca e contando retrocendo até achar um nó que não exista  
    no = no->pai; 
    d++; 
  }
  
  return d;
}