#ifndef fila
#define fila

#include <iostream>

namespace Estrutura {
    
    template<typename T>
    struct Node {
        T dado;
        Node<T>* prox;
        Node<T>* prev;
    };

    template<typename T>
    struct Fila {
        Node<T>* first;
        Node<T>* last;
    };

    template<typename T>
    void inicializar(Fila<T>& f) {
        f.first = nullptr;
        f.last = nullptr;
    }

    template<typename T>
    void queue(Fila<T>& f, T data) {
        Node<T>* el = new Node<T>;
        el->dado = data;
        if (f.first == NULL) {
            el->prev = nullptr;
            el->prox = nullptr;
            f.first = el;
            f.last = el;
        }
        else {
            el->prev = f.last;
            f.last->prox = el;
            el->prox = nullptr;
            f.last = el;
        }
    }

    template<typename T>
    void dequeue(Fila<T>& f) {
        f.first = f.first->prox;
        delete f.first->prev;
        f.first->prev = nullptr;
    }

    template<typename T>
    void print(Fila<T> f) {
        for (Node<T>* i = f.first; i != NULL; i = i->prox) {
            std::cout << i->dado << std::endl;
        }
    }
}

#endif
