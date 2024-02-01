/***********************************************************************
 * Module:  Datos.h
 * Author:  Edison Verdesoto
 * Modified: sábado, 6 de enero de 2024 20:56:35
 * Purpose: Declaration of the class Datos
 ***********************************************************************/

#if !defined(__Datos_Datos_h)
#define __Datos_Datos_h

class Datos
{
public:
   std::string getCedula(void);
   void setCedula(std::string newCedula);
   std::string getID(void);
   void setID(std::string newID);
   std::string getNombre(void);
   void setNombre(std::string newNombre);
   std::string getApellido(void);
   void setApellido(std::string newApellido);
   Datos();
   ~Datos();

protected:
private:
   std::string cedula;
   std::string ID;
   std::string nombre;
   std::string apellido;


};

#endif
