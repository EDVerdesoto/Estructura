/***********************************************************************
 * Module:  Persona.h
 * Author:  Edison Verdesoto
 * Modified: jueves, 11 de enero de 2024 0:14:48
 * Purpose: Declaration of the class Persona
 ***********************************************************************/

#include "Persona.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "validaciones.h"
#include "ListaDoble.h"

int Persona::contadorId = 0;


////////////////////////////////////////////////////////////////////////
// Name:       Persona::Persona()
// Purpose:    Implementation of Persona::Persona()
// Return:
////////////////////////////////////////////////////////////////////////

Persona::Persona()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::~Persona()
// Purpose:    Implementation of Persona::~Persona()
// Return:
////////////////////////////////////////////////////////////////////////

Persona::~Persona()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getNombre()
// Purpose:    Implementation of Persona::getNombre()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Persona::getNombre(void)
{
   return Nombre;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setNombre(std::string newNombre)
// Purpose:    Implementation of Persona::setNombre()
// Parameters:
// - newNombre
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setNombre(std::string newNombre)
{
   Nombre = newNombre;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getApellido()
// Purpose:    Implementation of Persona::getApellido()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Persona::getApellido(void)
{
   return Apellido;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setApellido(std::string newApellido)
// Purpose:    Implementation of Persona::setApellido()
// Parameters:
// - newApellido
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setApellido(std::string newApellido)
{
   Apellido = newApellido;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getCedula()
// Purpose:    Implementation of Persona::getCedula()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Persona::getCedula(void)
{
   return Cedula;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setCedula(std::string newCedula)
// Purpose:    Implementation of Persona::setCedula()
// Parameters:
// - newCedula
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setCedula(std::string newCedula)
{
   Cedula = newCedula;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getId()
// Purpose:    Implementation of Persona::getId()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Persona::getId(void)
{
   return Id;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setId(std::string newId)
// Purpose:    Implementation of Persona::setId()
// Parameters:
// - newId
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setId(std::string newId)
{
   Id = newId;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::Persona(const Persona& oldPersona)
// Purpose:    Implementation of Persona::Persona()
// Parameters:
// - oldPersona
// Return:
////////////////////////////////////////////////////////////////////////

Persona::Persona(std::string Nombre, std::string Apellido, std::string Cedula)
    : Nombre(Nombre), Apellido(Apellido), Cedula(Cedula) {
    this->id = generarSiguienteId();
}

Persona::Persona(std::string Nombre, std::string Apellido, std::string Cedula, std::string Id)
    : Nombre(Nombre), Apellido(Apellido), Cedula(Cedula), Id(Id) {
    int idValor = std::stoi(Id.substr(1));
    if (idValor > contadorId) {
        contadorId = idValor;
    }
}

std::string Persona::generarSiguienteId() {

    std::ostringstream oss;
    oss << "L" << std::setfill('0') << std::setw(6) << ++contadorId;
    return oss.str();
}

/**
 * @brief Ingresa una nueva persona y la guarda en un archivo de texto.
 */

Persona Persona::ingresarPersona(ListaDoble<Persona*>& listaPersonas) {

    std::string newCedula, newNombre, newApellido, newId;

    Persona nuevaPersona;

    do {
        newCedula = ingresar_numeros_como_string("\nIngrese el numero de cedula: ");

        if (validarCedula(newCedula)) {
            if (listaPersonas.buscarCedulaExistente(newCedula)) {
                nuevaPersona.setCedula(newCedula);
                break;
            } else {
                cout << "\nLa cedula ingresada ya existe. Vuelva a intentarlo." << endl;
            }
        } else {
            cout << "\nLa cedula ingresada es invalida. Vuelva a intentarlo." << endl;
        }
    } while (true);

    do {
        newNombre = mayusculas_primeras(ingresar_alfabetico_con_un_espacio("\nIngrese el nombre: "));
        if (newNombre.empty()) {
            cout << "\nEl nombre no puede estar vacio. Vuelva a intentarlo." << endl;
        } else {
            nuevaPersona.setNombre(newNombre);
            break;
        }
    } while (true);


    do {
        newApellido = mayusculas_primeras(ingresar_alfabetico_con_un_espacio("\nIngrese el apellido: "));
        if (newApellido.empty()) {
            cout << "\nEl apellido no puede estar vacio. Vuelva a intentarlo." << endl;
        } else {
            nuevaPersona.setApellido(newApellido);
            break;
        }
    } while (true);

    newId = Persona::generarSiguienteId();
    std::cout << "\nSu id unico es: " << newId << std::endl;

    nuevaPersona.setId(newId);

    return nuevaPersona;
}

