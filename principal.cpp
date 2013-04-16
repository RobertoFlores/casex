/*
  Nombre: CASE*c
  Copyright: RobertRevolver © 2004
  Autor: Roberto Flores Santiago
  Email: robertrevolver@hotmail.com, robertrevolver@yahoo.com.mx
  fecha: 07/04/04 17:24
  Descripcion: CASE*c "Cálculos y Análisis de Sistemas Eléctricos por Computadora"
  Lugar: Cd. del Carmen Camp. México
  Nombre del Archivo: principal.cpp


*/

#include <string>
#include <iostream>
# include <stdlib.h>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

/*los includes de archivos van despues del namespace, 
pinche errorcito de ubicacion*/

# include "dispositivo.h"
# include "nodo.h"
# include "rama.h"
# include "proyecto.h"
# include "matriz.h"
# include "menu.h" 


int main(void) {
entrada(); 
    flujo();    
       return 0;
       
} 
