/***********************************************************************
 * Module:  Stack_operations.h
 * Author:  Edison Verdesoto
 * Modified: viernes, 20 de diciembre de 2023 11:05:38 a. m.
 * Purpose: Operaciones usadas con el codigo Stacks.h y Node.h
 ***********************************************************************/

#ifndef STACKS_OPERATIONS_H_INCLUDED
#define STACKS_OPERATIONS_H_INCLUDED

#include "Stack.cpp"
#include "Node.h"
#include <string>
#include <math.h>
#include "Matematica.h"
#include <conio.h>

template <typename T>
void cantidad_primos_rec(Stack<T>* original_stack, int aux, Stack<T>* count_stack, Stack<T>* dest_stack, int *contador, int exp);

void reverse_stack_rec(Stack<char>* original_stack, Stack<char>* aux_stack1, Stack<char>* aux_stack2, bool is_reversed);
void hanoi_stack_p(int n, Stack<int>* stack_A, Stack<int>* stack_B, Stack<int>* stack_C);
void print_hanoi_stacks(Stack<int>* stack_A, Stack<int>* stack_B, Stack<int>* stack_C);
double operar(char operador, double num1, double num2);

void hanoi_stack(int disks_number){
    Stack<int>* stack_A = new Stack<int>();
    Stack<int>* stack_B = new Stack<int>();
    Stack<int>* stack_C = new Stack<int>();
    for(int i = 0; i<disks_number; i++){
        stack_A->aggregate(disks_number-i);
    }

    hanoi_stack_p(disks_number, stack_A, stack_B, stack_C);

}

void hanoi_stack_p(int n, Stack<int>* stack_A, Stack<int>* stack_B, Stack<int>* stack_C){
    print_hanoi_stacks(stack_A, stack_B, stack_C);

    auto hanoi_stack_rec = [&stack_A, &stack_B, &stack_C](int n, Stack<int>* stack_orig, Stack<int>* stack_aux, Stack<int>* stack_dest, auto&& hanoi_stack_rec)->void{
        if (n > 0) {
            hanoi_stack_rec(n - 1, stack_orig, stack_dest, stack_aux, hanoi_stack_rec);

            stack_dest->aggregate(stack_orig->take_off());

            print_hanoi_stacks(stack_A, stack_B, stack_C);

            hanoi_stack_rec(n - 1, stack_aux, stack_orig, stack_dest, hanoi_stack_rec);
        }
    };

    hanoi_stack_rec(n, stack_A, stack_B, stack_C, hanoi_stack_rec);
}

void print_hanoi_stacks(Stack<int>* stack_A, Stack<int>* stack_B, Stack<int>* stack_C){
    Node<int>* auxA = stack_A->get_top();
    Node<int>* auxB = stack_B->get_top();
    Node<int>* auxC = stack_C->get_top();
    printf("\n\n");
    while(auxA!=nullptr || auxB!=nullptr || auxC!=nullptr){
        if(auxA!=nullptr){
            std::cout<<auxA->get_value()<<"\t|\t";
            auxA = auxA->get_below();
        }
        else if(auxA==nullptr){
            std::cout<<"  \t|\t";
        }
        if(auxB!=nullptr){
            std::cout<<auxB->get_value()<<"\t|\t";
            auxB = auxB->get_below();
        }
        else if(auxB==nullptr){
            std::cout<<"  \t|\t";
        }
        if(auxC!=nullptr){
            std::cout<<auxC->get_value()<<"\t|\t";
            auxC = auxC->get_below();
        }
        else if(auxC==nullptr){
            std::cout<<"  \t|\t";
        }
        printf("\n");
    }
    printf("\n----------------------\n");
}

void reverse_stack(Stack<char>* original_stack){
    Stack<char>* aux_stack1 = new Stack<char>();
    Stack<char>* aux_stack2 = new Stack<char>();
    reverse_stack_rec(original_stack, aux_stack1, aux_stack2, false);
}

void reverse_stack_rec(Stack<char>* original_stack, Stack<char>* aux_stack1, Stack<char>* aux_stack2, bool is_reversing){
    if(!original_stack->is_stack_void() && !is_reversing){
        aux_stack1->aggregate(original_stack->take_off());
        reverse_stack_rec(original_stack, aux_stack1, aux_stack2, is_reversing);
    }
    else if(!aux_stack1->is_stack_void()){
        aux_stack2->aggregate(aux_stack1->take_off());
        reverse_stack_rec(original_stack, aux_stack1, aux_stack2, is_reversing);
    }
    else if(!aux_stack2->is_stack_void()){
        original_stack->aggregate(aux_stack2->take_off());
        reverse_stack_rec(original_stack, aux_stack1, aux_stack2, true);
    }
}

template <typename T>
bool esPrimo(T num) {
    if (num <= 1) {
        return false;
    }

    for (T i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

template <typename T>
int count_dig(T num) {
    if (num == 0) {
        return 1;
    }
    int counter = 0;
    num = std::abs(num);
    while (num > 0) {
        num /= 10;
        counter++;
    }

    return counter;
}

int reverse_num(int num) {
    int reversed_num = 0;
    while (num != 0) {
        int digit = num % 10;
        reversed_num = reversed_num * 10 + digit;
        num /= 10;
    }
    return reversed_num;
}

template <typename T>
void pass_dig_prime(int num, Stack<T>* count_stack) {
    int num_dig = count_dig(num);
    int prime_count = 0;

    for (int subchain_long = 1; subchain_long <= num_dig; ++subchain_long) {
        for (int subchain_start = 0; subchain_start <= num_dig - subchain_long; ++subchain_start) {
            int sub_num = 0;

            for (int actual_pos = subchain_start; actual_pos < subchain_start + subchain_long; ++actual_pos) {
                int power = static_cast<int>(pow(10, num_dig - actual_pos - 1));
                sub_num = (sub_num * 10) + ((num / power) % 10);
            }

            if (esPrimo(sub_num)) {
                prime_count++;
            }
        }
    }

    count_stack->aggregate(prime_count);
}

template <typename T>
void cantidad_primos_rec(Stack<T>* original_stack, int aux, Stack<T>* count_stack, Stack<T>* dest_stack) {
    if (!original_stack->is_stack_void()) {
        aux = original_stack->get_top()->get_value();
        dest_stack->aggregate(aux);
        Stack<T>* temp_count_stack = new Stack<T>();

        pass_dig_prime(aux, temp_count_stack);
        pass_dig_prime(reverse_num(aux), temp_count_stack);

        int total_prime_count = 0;
        while (!temp_count_stack->is_stack_void()) {
            total_prime_count += temp_count_stack->get_top()->get_value();
            temp_count_stack->remove_top(); //cambiar y hacer una funcion que se llame aqui que haga el conteo
        }
        count_stack->aggregate(total_prime_count);

        delete temp_count_stack;

        original_stack->remove_top();
        cantidad_primos_rec(original_stack, aux, count_stack, dest_stack);
    }
}

template <typename T>
void cantidad_Primos(Stack<T>* original_stack, Stack<T>* count_stack) {
    Stack<T>* dest_stack = new Stack<T>();
    int aux = 0;

    Stack<T> original_copy(*original_stack);

    cantidad_primos_rec(original_stack, aux, count_stack, dest_stack);

    original_stack->remove_all();

    while (!dest_stack->is_stack_void()) {
        original_stack->aggregate(dest_stack->get_top()->get_value());
        dest_stack->remove_top();
    }

    delete dest_stack;

}

bool es_operador(char op){
    if (op == '*')
        return true;
    else if (op == '+')
        return true;
    else if (op == '-')
        return true;
    else if (op == '/')
        return true;
    else if (op == '^')
        return true;
    else
        return false;
}

bool es_parentesis(char op){
    if (op == '('){
        return true;
        }
    else if (op == ')'){
        return true;
    }
    else
        return false;
}

int jerarquia(char operador) {
    if (operador == '+' || operador == '-') {
        return 1;
    }
    else if (operador == '*' || operador == '/') {
        return 2;
    }
    else if (operador == '^'){
        return 3;
    }
    return 0;
}

char sacar_operadores_del_parentesis(Stack<char>* operadores) {
    Stack<char>* resultado = new Stack<char>();
    while (!operadores->is_stack_void() && operadores->get_top()->get_value() != '(' && operadores->get_top()->get_value() != ')') {
        resultado->aggregate(operadores->get_top()->get_value());
        operadores->remove_top();
    }
    operadores->remove_top();
    return resultado->get_top()->get_value();
}

char sacar_operadores_jerarquia(char operador, Stack<char>* operadores) {
    Stack<char>* resultado = new Stack<char>();
    while (!operadores->is_stack_void() && jerarquia(operadores->get_top()->get_value()) >= jerarquia(operador)) {
        resultado->aggregate(operadores->get_top()->get_value());
        operadores->remove_top();
    }
    operadores->aggregate(operador);
    return resultado->get_top()->get_value();
}

void polaca_inversa_rec(Stack<char>* expresion, Stack<char>* operadores, int tam, Stack<char>* resultado) {
    if (tam >= 0) {
        polaca_inversa_rec(expresion, operadores, tam - 1, resultado);

        if (isdigit(expresion->get_top()->get_value()) || isalpha(expresion->get_top()->get_value()) || expresion->get_top()->get_value() == '.') {
            resultado->aggregate(expresion->get_top()->get_value());
        }
        else if (expresion->get_top()->get_value() == '(') {
            operadores->aggregate(expresion->get_top()->get_value());
        }
        else if (expresion->get_top()->get_value() == ')') {
            resultado->aggregate(sacar_operadores_del_parentesis(operadores));
        }
        else if (expresion->get_top()->get_value()) {
            resultado->aggregate(sacar_operadores_jerarquia(expresion->get_top()->get_value(), operadores));
        }
        expresion->remove_top();
    }
}

Stack<char>* polaca_inversa(Stack<char>* expresion, Stack<char>* resultado) {
    Stack<char>* operadores = new Stack<char>();
    polaca_inversa_rec(expresion, operadores, expresion->act_size(), resultado);

    while (!operadores->is_stack_void()) {
        resultado->aggregate(operadores->get_top()->get_value());
        operadores->remove_top();
    }
        return resultado;
}

void polaca_rec(Stack<char>* expresion, Stack<char>* operadores, int pos, Stack<char>* resultado, int tam, char tecla) {
    tam = expresion->act_size();
    if (pos < tam) {

        polaca_rec(expresion, operadores, pos + 1, resultado, tam, tecla);
        tecla = expresion->get_top()->get_value();
        if (isdigit(tecla) || isalpha(expresion->get_top()->get_value())|| expresion->get_top()->get_value()=='.'){
            resultado->aggregate(expresion->get_top()->get_value());
        }
        else if (tecla == ')') {
            operadores->aggregate(expresion->get_top()->get_value());
        }
        else if (tecla == '(') {
            resultado->aggregate(sacar_operadores_del_parentesis(operadores));
        }
        else if (es_operador(tecla)) {
            resultado->aggregate(sacar_operadores_jerarquia(tecla, operadores));
        }
        expresion->remove_top();
    }
}

Stack<char>* polaca(Stack<char>* expresion, Stack<char>* resultado) {
    Stack<char>* operadores = new Stack<char>();
    char tecla = expresion->get_top()->get_value();
    polaca_rec(expresion, operadores, 0, resultado, 0, ' ');

    while (!operadores->is_stack_void()) {
        resultado->aggregate(tecla);
        operadores->remove_top();
    }
    // Invertir el resultado porque se leyo de derecha a izquierda
    reverse_stack(resultado);
    return resultado;
}

double llamar_funcion(Stack<char>* funcion){
    Matematica matematica;
    double resultado, parametro;
    Stack<char>* nombre_funcion = new Stack<char>();
    Stack<int>* parametro_funcion = new Stack<int>();

    for(int i = 0; i<funcion->act_size(); i++){
        if(funcion->get_top()->get_value() == 'p' && funcion->get_top()->get_below()->get_value() == 'i'){
            if(i>0){
                parametro == matematica.getPI();
            }
            else{
                nombre_funcion->aggregate('p');
                nombre_funcion->aggregate('i');
                break;
            }
        }
        else if (isdigit(funcion->get_top()->get_value())){
            parametro_funcion->aggregate(funcion->get_top()->get_value());
        }
        else{
            nombre_funcion->aggregate(funcion->get_top()->get_value());
        }
    }

    if(nombre_funcion->get_top()->get_value() == 'i'){
        resultado = matematica.getPI();
    }
    else if(nombre_funcion->get_top()->get_value() == 'n' && nombre_funcion->get_top()->get_below()->get_value() == 'i'){
        resultado = matematica.sin(parametro);
    }
    else if(nombre_funcion->get_top()->get_value() == 's'){
        resultado = matematica.cos(parametro);
    }
    else if(nombre_funcion->get_top()->get_value() == 'n' && nombre_funcion->get_top()->get_below()->get_value() == 'a'){
        resultado = matematica.tan(parametro);
    }
    else if(nombre_funcion->get_top()->get_value() == 'g'){
        resultado = matematica.log(parametro);
    }
    else if(nombre_funcion->get_top()->get_value() == 'z'){
        resultado = matematica.sqrt(parametro);
    }

}

void agregar_valor_a_pila(Stack<char>* valor, Stack<double>* numeros_operar){
    if(!isdigit(valor->get_top()->get_value())){
        numeros_operar->aggregate(llamar_funcion(valor));
    }
    else {
        char caracter = valor->get_top()->get_value();
        int numero = caracter - '0';
        numeros_operar->aggregate(numero);
    }
}

void calculo_pre(Stack<char>* expresion, Stack<double>* numeros_operar, int tam, Stack<char>* valor, double aux){
    if(tam >= 0){

        if((isdigit(expresion->get_top()->get_value()) || isalpha(expresion->get_top()->get_value()) || expresion->get_top()->get_value() == '.')&& expresion->get_top()->get_value()!= ' '){
            valor->aggregate(expresion->get_top()->get_value());
            if(numeros_operar->is_stack_void()&& tam-1<0){
                agregar_valor_a_pila(valor, numeros_operar);
            }
        }
        else if(expresion->is_stack_void() && !valor->is_stack_void()){
            agregar_valor_a_pila(valor, numeros_operar);
            valor->take_off();
        }
        else if(es_operador(expresion->get_top()->get_value())){
            if(!valor->is_stack_void()){
                agregar_valor_a_pila(valor, numeros_operar);
                valor->take_off();
            }
            aux = numeros_operar->take_off()->get_value();

            numeros_operar->aggregate(operar(expresion->get_top()->get_value(), aux, numeros_operar->take_off()->get_value()));
        }
        calculo_pre(expresion, numeros_operar, tam-1, valor, aux);
    }
}

void calculo_post(Stack<char>* expresion, Stack<double>* numeros_operar, int pos, Stack<char>* valor, double aux){
    if(pos < expresion->act_size()){

        if((isdigit(expresion->get_top()->get_value()) || isalpha(expresion->get_top()->get_value()) || expresion->get_top()->get_value() == '.')&& expresion->get_top()->get_value()!= ' '){
            valor->aggregate(expresion->get_top()->get_value());
            if(numeros_operar->is_stack_void() && pos+1 == expresion->act_size()){
                agregar_valor_a_pila(valor, numeros_operar);
            }
        }
        else if(expresion->is_stack_void() && !valor->is_stack_void()){
            agregar_valor_a_pila(valor, numeros_operar);
           valor->take_off();
        }
        else if(es_operador(expresion->get_top()->get_value())){
            if(!valor->is_stack_void()){
                agregar_valor_a_pila(valor, numeros_operar);
                valor->take_off();
            }

            aux = numeros_operar->take_off()->get_value();

            if(expresion->get_top()->get_below()->get_value() == '-' && isdigit(expresion->get_top()->get_value())){
                if(numeros_operar->is_stack_void() || pos+1<expresion->act_size()){
                    numeros_operar->aggregate(aux*(-1));
                }
                else{
                    numeros_operar->aggregate(operar(expresion->get_top()->get_value(), numeros_operar->take_off()->get_value(), aux));
                }
            }
            else{
                numeros_operar->aggregate(operar(expresion->get_top()->get_value(), numeros_operar->take_off()->get_value(), aux));
            }

        }
        expresion->remove_top();
        calculo_post(expresion, numeros_operar, pos+1, valor, aux);
    }
}

void polaca_inversa_rec_impares(Stack<char>* expresion, Stack<char>* operadores, int tam, Stack<char>* resultado) {
    if (tam >= 0) {
        polaca_inversa_rec(expresion, operadores, tam - 1, resultado);

        if (isdigit(expresion->get_top()->get_value()) || isalpha(expresion->get_top()->get_value()) || expresion->get_top()->get_value()=='.' ){
            resultado->aggregate(expresion->get_top()->get_value());
        }
        else if (expresion->get_top()->get_value() == '(') {
            operadores->aggregate(expresion->get_top()->get_value());
        }
        else if (expresion->get_top()->get_value() == ')') {
            resultado->aggregate(sacar_operadores_del_parentesis(operadores));
        }
        else if (es_operador(expresion->get_top()->get_value())) {
            resultado->aggregate(sacar_operadores_jerarquia(expresion->get_top()->get_value(), operadores));
            if(operadores->act_size()%2==0){
                resultado->aggregate(sacar_operadores_jerarquia(expresion->get_top()->get_value(), operadores));
            }
            else{
                resultado->aggregate(' ');
            }
        }
        expresion->remove_top();
    }
}

void calculo_post_digitos_impares(Stack<char>* expresion, Stack<double>* numeros_operar, int pos, Stack<char>* valor, double aux){
    if(pos < expresion->act_size()){
        if( (isdigit(expresion->get_top()->get_value()) || isalpha(expresion->get_top()->get_value()) || expresion->get_top()->get_value() == '.') && expresion->get_top()->get_value()!=' '){
            valor->aggregate(expresion->get_top()->get_value());
            if(numeros_operar->is_stack_void() && pos+1 == expresion->act_size()){
                agregar_valor_a_pila(valor, numeros_operar);
            }
        }
        else if(expresion->is_stack_void() && valor->is_stack_void()){
            if(numeros_operar->act_size()%2 == 0){
                agregar_valor_a_pila(valor, numeros_operar);
            }
            valor->take_off();
        }
        else if(es_operador(expresion->get_top()->get_value())){
            if(!valor->is_stack_void()){
                agregar_valor_a_pila(valor, numeros_operar);
               valor->take_off();
            }
            aux = numeros_operar->take_off()->get_value();

            numeros_operar->aggregate(operar(expresion->get_top()->get_value(),  numeros_operar->take_off()->get_value(), aux));
        }
        calculo_post_digitos_impares(expresion, numeros_operar, pos+1, valor, aux);
        expresion->remove_top();
    }
}

void calc_impares(Stack<char>* expresion){
    double aux1;
    Stack<double> aux;
    char op_acomp;
    Stack<char>* valor1 = new Stack<char>();
    int posicion = 0;
    int cont_dig = 0;
    bool impar = true;
    while(posicion < expresion->act_size()){
        if(isdigit(expresion->get_top()->get_value()) || isalpha(expresion->get_top()->get_value())){
            valor1->aggregate(expresion->get_top()->get_value());
        }
        if(es_operador(expresion->get_top()->get_value()) || (posicion+1 == expresion->act_size())){
            if(!valor1->is_stack_void()){
                if((cont_dig + 1) % 2 != 0){
                    if(!isdigit(valor1->get_top()->get_value())){
                        aux1 = llamar_funcion(valor1);
                    }
                    else{
                        aux1 = valor1->get_top()->get_value();
                    }
                    if(aux.is_stack_void()){
                        op_acomp = expresion->get_top()->get_value();
                    }
                    aux.aggregate(aux1);
                }
                valor1->take_off();
                cont_dig++;

                if(aux.act_size()==2){
                    aux1 = aux.take_off()->get_value();
                    printf("%f\n", operar(op_acomp, aux.take_off()->get_value(), aux1));
                }
                else if(aux.act_size()==1 && posicion+1==expresion->act_size()){
                    printf("%f\n", aux.take_off()->get_value());
                }
            }
        }
        posicion++;
        expresion->remove_top();
    }
}

void calc_impares_recursiva( Stack<char>* expresion, int posicion, Stack<char>* valor1, int cont_dig, char op_acomp, Stack<double>& aux) {
    if (posicion < expresion->act_size()) {
        if (isdigit(expresion->get_top()->get_value()) || isalpha(expresion->get_top()->get_value())) {
            valor1->aggregate(expresion->get_top()->get_value());
        }

        if (es_operador(expresion->get_top()->get_value()) || (posicion + 1 == expresion->act_size())) {
            if (!valor1->is_stack_void()) {
                if ((cont_dig + 1) % 2 != 0) {
                    double aux1;
                    if (!isdigit(valor1->get_top()->get_value())) {
                        aux1 = llamar_funcion(valor1);
                    } else {
                        aux1 = valor1->get_top()->get_value();
                    }

                    if (aux.is_stack_void()) {
                        op_acomp = expresion->get_top()->get_value();
                    }

                    aux.aggregate(aux1);
                }

                cont_dig++;

                if (aux.act_size() == 2) {
                    double aux1 = aux.take_off()->get_value();
                    printf("%f\n", operar(op_acomp, aux.take_off()->get_value(), aux1));
                } else if (aux.act_size() == 1 && (posicion + 1) == expresion->act_size()) {
                    printf("%f\n", aux.take_off()->get_value());
                }
            }

            calc_impares_recursiva(expresion, posicion + 1, valor1, cont_dig, op_acomp, aux);
        }
    }
}

double calcular(Stack<char>* expresion, Stack<char>* pre_post){
    double resultado;
    Stack<double>* numeros_operar = new Stack<double>();
    if(pre_post->get_top()->get_value() == 'p' && pre_post->get_top()->get_value() == 'r'){
        calculo_pre(expresion, numeros_operar, expresion->act_size()-1, nullptr, 0);
    }
    else if(pre_post->get_top()->get_value() == 'p' && pre_post->get_top()->get_value() == 'o'){
        calculo_post(expresion, numeros_operar, 0, pre_post, 0);
    }

    resultado = numeros_operar->take_off()->get_value();
    delete numeros_operar;

    return resultado;
}

double operar(char operador, double num1, double num2){
    double resultado;
    Matematica matematica;
    if(operador == '+'){
        resultado = num1+num2;
    }
    else if(operador == '*'){
        resultado = num1*num2;
    }
    else if (operador == '/'){
        resultado = num1/num2;
    }
    else if (operador == '-'){
        resultado = num1-num2;
    }
    else if(operador == '^'){
        resultado = matematica.pow(num1, num2);
    }
    return resultado;
}

char conteo_menos (Stack<char>* expresion) {
    char signo1;
    char signo2;
    char resultado;
    int contador = 0;
    for (int i = 0; i < expresion->act_size(); i++){
        if( expresion->get_top()->get_value() == '-'){
            contador += 1;
            if (contador%2 == 0){
                resultado = '+';
            } else {
                resultado = '-';
            }
        }
        expresion->remove_top();
    }
    return resultado;
}

#endif // STACKS_OPERATIONS_H_INCLUDED
