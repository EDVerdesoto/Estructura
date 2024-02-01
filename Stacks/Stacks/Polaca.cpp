#include "Stack.cpp"
#include "Node.h"
#include <cmath>
#include <string>

template <typename T>
std::string polaca_inversa(const std::string& expresion, Stack<T>* operadores) {
    std::string resultado;

    for (int i = 0; i < expresion.length(); i++) {
        if (!es_operador(expresion[i]) && expresion[i] != '(' && expresion[i] != ')') {
            resultado += expresion[i];
        } else if (expresion[i] == '(') {
            operadores->aggregate(expresion[i]);
        } else if (expresion[i] == ')') {
            while (!operadores->is_stack_void() && operadores->get_top()->get_value() != '(') {
                resultado += operadores->get_top()->get_value();
                operadores->remove_top();
            }
            operadores->remove_top(); // Este remove_top elimina el '(' de la pila
        } else if (es_operador(expresion[i])) {
            while (!operadores->is_stack_void() && jerarquia(operadores->get_top()->get_value()) >= jerarquia(expresion[i])){
                resultado += operadores->get_top()->get_value();
                operadores->remove_top();
            }
            operadores->aggregate(expresion[i]);
        }
    }

    while (!operadores->is_stack_void()) {
        resultado += operadores->get_top()->get_value();
        operadores->remove_top();
    }

    return resultado;
}
