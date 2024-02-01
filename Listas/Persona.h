/***********************************************************************
 * Module:  Persona.h
 * Author:  Edison Verdesoto
 * Modified: jueves, 11 de enero de 2024 0:14:18
 * Purpose: Declaration of the class Persona
 ***********************************************************************/

#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

template <typename T>
class ListaDoble;

class Persona
{
public:
   Persona();
    // Constructores modificados
    Persona(std::string Nombre, std::string Apellido, std::string Cedula);
    Persona(std::string Nombre, std::string Apellido, std::string Cedula, std::string Id);
   // Método estático para obtener el siguiente ID
   static std::string generarSiguienteId();
   ~Persona();
   std::string getNombre(void);
   void setNombre(std::string newNombre);
   std::string getApellido(void);
   void setApellido(std::string newApellido);
   std::string getCedula(void);
   void setCedula(std::string newCedula);
   std::string getId(void);
   void setId(std::string newId);
   static Persona ingresarPersona(ListaDoble<Persona*>& listaPersonas);
   static int contadorId;
   std::string id;

protected:
private:
   std::string Nombre;
   std::string Apellido;
   std::string Cedula;
   std::string Id;

};

#endif // PERSONA_H_INCLUDED
