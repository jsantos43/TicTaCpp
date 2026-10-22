# Jogo da Velha
#   make                compila em build/ e gera o executavel ./jogo
#   make run            compila e executa

CXX       := g++
DIR_INC   := src/include
DIR_SRC   := src/source
DIR_BUILD := build

CXXFLAGS  := -std=c++17 -Wall

ALVO      := exec

CLANG_FORMAT := clang-format

.PHONY: all run

all: $(CXX) $(ALVO)

$(ALVO): $(OBJETOS)
        $(CXX) $(OBJETOS) -o $@ $(LDLIBS)
run: $(ALVO)
        ./$(ALVO)