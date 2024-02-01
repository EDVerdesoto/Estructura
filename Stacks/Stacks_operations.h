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
#include "Matematicas.h"
#include <cmath>
#include <string>

Matematica mat;
template <typename T>
void cantidad_primos_rec(Stack<T>* original_stack, int aux, Stack<T>* count_stack, Stack<T>* dest_stack, int *contador, int exp);
void reverse_stack_rec(Stack<int>* original_stack, Stack<int>* aux_stack1, Stack<int>* aux_stack2, bool is_reversed);
void hanoi_stack_p(int n, Stack<int>* stack_A, Stack<int>* stack_B, Stack<int>* stack_C);
void print_hanoi_stacks(Stack<int>* stack_A, Stack<int>* stack_B, Stack<int>* stack_C);
double operar(char operador, double numero1, double numero2);

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

void reverse_stack(Stack<int>* original_stack){
    Stack<int>* aux_stack1 = new Stack<int>();
    Stack<int>* aux_stack2 = new Stack<int>();
    reverse_stack_rec(original_stack, aux_stack1, aux_stack2, false);
}

void reverse_stack_rec(Stack<int>* original_stack, Stack<int>* aux_stack1, Stack<int>* aux_stack2, bool is_reversing){
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


std::string polaca_inversa(const std::string& expresion, Stack<char>* operadores) {
    std::string resultado;
    for (int i = 0; i < expresion.length(); i++) {
        if (isdigit(expresion[i])) {
            resultado += expresion[i];
            if (i + 1 < expresion.length() && !isdigit(expresion[i+1]) )
                resultado += " ";
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

std::string sacar_operadores_del_parentesis(Stack<char>* operadores) {
    std::string resultado = "";
    while (!operadores->is_stack_void() && operadores->get_top()->get_value() != '(' && operadores->get_top()->get_value() != ')') {
        resultado += operadores->get_top()->get_value();
        operadores->remove_top();
    }
    operadores->remove_top();
    return resultado;
}

std::string sacar_operadores_jerarquia(char operador, Stack<char>* operadores) {
    std::string resultado = " ";
    while (!operadores->is_stack_void() && jerarquia(operadores->get_top()->get_value()) >= jerarquia(operador)){
        resultado += operadores->get_top()->get_value();
        operadores->remove_top();
    }
    operadores->aggregate(operador);
    return resultado;
}

void polaca_inversa_rec(std::string expresion, Stack<char>* operadores, int tam, std::string* resultado) {
    if (tam >= 0) {
        //Acumular la pila de llamadas hasta la primera posicion
        polaca_inversa_rec(expresion, operadores, tam - 1, resultado);

        if (isdigit(expresion[tam]) || isalpha(expresion[tam]) || expresion[tam]=='.' ){
            *resultado += expresion[tam];
        }
        else if (expresion[tam] == '(') {
            operadores->aggregate(expresion[tam]);
        }
        else if (expresion[tam] == ')') {
            *resultado += sacar_operadores_del_parentesis(operadores);
        }
        else if (es_operador(expresion[tam])) {
            *resultado += sacar_operadores_jerarquia(expresion[tam], operadores);
        }
    }
}

std::string polaca_inversa(std::string expresion) {
    Stack<char>* operadores = new Stack<char>();
    std::string resultado = "";
    polaca_inversa_rec(expresion, operadores, expresion.length(), &resultado);

    while (!operadores->is_stack_void()) {
        resultado += operadores->get_top()->get_value();
        operadores->remove_top();
    }

    return resultado;
}

void polaca_rec(std::string expresion, Stack<char>* operadores, int pos, std::string* resultado) {
    if (pos < expresion.length()) {
        //Acumular la pila de llamadas hasta la ultima posicion
        polaca_rec(expresion, operadores, pos + 1, resultado);
        if (isdigit(expresion[pos]) || isalpha(expresion[pos])|| expresion[pos]=='.'){
            *resultado += expresion[pos];
        }
        else if (expresion[pos] == ')') {
            operadores->aggregate(expresion[pos]);
        }
        else if (expresion[pos] == '(') {
            *resultado += sacar_operadores_del_parentesis(operadores);
        }
        else if (es_operador(expresion[pos])) {
            *resultado += sacar_operadores_jerarquia(expresion[pos], operadores);
        }
    }
}

std::string polaca(std::string expresion) {
    Stack<char>* operadores = new Stack<char>();
    std::string resultado = "";

    polaca_rec(expresion, operadores, 0, &resultado);

    while (!operadores->is_stack_void()) {
        resultado += operadores->get_top()->get_value();
        operadores->remove_top();
    }

    // Invertir el resultado porque se leyo de derecha a izquierda
    for (int i = 0; i < resultado.length()/2; ++i) {
        std::swap(resultado[i], resultado[resultado.length() - i - 1]);
    }

    return resultado;
}

double llamar_funcion(std::string funcion){
    Matematica matematica;
    double resultado, parametro;
    std::string nombre_funcion = "";
    std::string parametro_funcion = "";

    for(int i = 0; i<funcion.length(); i++){
        if(funcion[i] == 'p' && funcion[i+1] == 'i'){
            if(i>0){
                parametro == matematica.getPI();
            }
            else{
                nombre_funcion = "pi";
                break;
            }
        }
        else if (isdigit(funcion[i])){
            parametro_funcion += funcion[i];
        }
        else{
            nombre_funcion += funcion[i];
        }
    }
    if(parametro_funcion!=""){
        parametro = std::stof(parametro_funcion);
    }

    if(nombre_funcion == "pi"){
        resultado = matematica.getPI();
    }
    else if(nombre_funcion == "sin"){
       resultado = matematica.sin(parametro);
    }
    else if(nombre_funcion == "cos"){
        resultado =matematica.cos(parametro);
    }
    else if(nombre_funcion == "tan"){
       resultado = matematica.tan(parametro);
    }

    return resultado;
}

void agregar_valor_a_pila(std::string valor, Stack<double>* numeros_operar){
    if(!isdigit(valor[0])){
        numeros_operar->aggregate(llamar_funcion(valor));
    }
    else {
        numeros_operar->aggregate(std::stof(valor));
    }
}

void calculo_pre(std::string expresion, Stack<double>* numeros_operar, int tam, std::string valor, double aux){
    if(tam >= 0){

        if((isdigit(expresion[tam]) || isalpha(expresion[tam]) || expresion[tam] == '.')&& expresion[tam]!= ' '){
            valor = expresion[tam]+valor;
            if(numeros_operar->is_stack_void()&& tam-1<0){
                agregar_valor_a_pila(valor, numeros_operar);
            }
        }
        else if(expresion[tam] == ' ' && valor != ""){
            agregar_valor_a_pila(valor, numeros_operar);
            valor = "";
        }
        else if(es_operador(expresion[tam])){
            if(valor!=""){
                agregar_valor_a_pila(valor, numeros_operar);
                valor = "";
            }
            aux = numeros_operar->take_off()->get_value();

            numeros_operar->aggregate(operar(expresion[tam], aux, numeros_operar->take_off()->get_value()));
        }
        calculo_pre(expresion, numeros_operar, tam-1, valor, aux);
    }
}
char ultimo (std::string* expresion){
    int tam = expresion.length();
    char utlimo = expresion[tam];
    return ultimo;
}
void polaca_inversa_impares_rec(std::string expresion, Stack<char>* operadores, int pos, std::string* resultado, char numeros, char op, int contador_num, int contador_op) {
    if (pos < expresion.length()) {
        if (isdigit(expresion[pos]) || isalpha(expresion[pos]) || expresion[pos]=='.' ){
            numeros = expresion[pos];
            contador_num += 1;
            if(contador_num%2!=0){
                *resultado += numeros;
            }
        }
        else if (expresion[pos] == ')') {
            operadores->aggregate(expresion[pos]);
        }
        else if (expresion[pos] == '(') {
            *resultado += sacar_operadores_del_parentesis(operadores);
        }
        else if (es_operador(expresion[pos]) {
            op = expresion[pos];
            contador_op += 1;
            if(contador_op%2!=0 && es_operador(ultimo(expresion))){
                *resultado += op;
            }
        }
        polaca_inversa_impares_rec(expresion, operadores, pos + 1, resultado, numeros, op, contador_num, contador_op);
    }
}
std::string polaca_inversa_impares(std::string expresion) {
    Stack<char>* operadores = new Stack<char>();
    std::string resultado = "";
    std::string resultado_ordenado;
    double num1;
    double num2;
    char op_f;
    char numeros;
    char op;
    polaca_inversa_impares_rec(expresion, operadores, 0, &resultado, numeros, op, 0, 0);

    return resultado;
}

void calculo_post(std::string expresion, Stack<double>* numeros_operar, int pos, std::string valor, double aux){
    if(pos<expresion.length()){
        if( (isdigit(expresion[pos]) || isalpha(expresion[pos]) || expresion[pos] == '.') && expresion[pos]!=' '){
            valor += expresion[pos];
            if(numeros_operar->is_stack_void()&& pos+1==expresion.length()){
                agregar_valor_a_pila(valor, numeros_operar);
            }
        }
        else if(expresion[pos] == ' ' && valor != ""){
            agregar_valor_a_pila(valor, numeros_operar);
            valor = "";
        }
        else if(es_operador(expresion[pos])){
            if(valor!=""){
                agregar_valor_a_pila(valor, numeros_operar);
                valor = "";
            }

            aux = numeros_operar->take_off()->get_value();

            numeros_operar->aggregate(operar(expresion[pos],  numeros_operar->take_off()->get_value(), aux));
        }
        calculo_post(expresion, numeros_operar, pos+1, valor, aux);
    }
}

double calcular(std::string expresion, std::string pre_post){
    double resultado;
    Stack<double>* numeros_operar = new Stack<double>();
    if(pre_post == "pre"){
        calculo_pre(expresion, numeros_operar, expresion.length()-1, "", 0);
    }
    else if(pre_post == "post"){
        calculo_post(expresion, numeros_operar, 0, "", 0);
    }

    resultado = numeros_operar->take_off()->get_value();
    delete numeros_operar;

    return resultado;
}

double operar(char operador, double num1, double num2){
    double resultado;
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
    return resultado;
}


#endif // STACKS_OPERATIONS_H_INCLUDED
