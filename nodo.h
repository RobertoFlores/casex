/*
  Nombre: CASE*c
  Copyright: RobertRevolver © 2004  
  Autor: Roberto Flores Santiago
  Email: robertrevolver@hotmail.com, robertrevolver@yahoo.com.mx
  fecha: 07/04/04 17:24
  Descripcion: CASE*c "Cálculos y Análisis de Sistemas Eléctricos por Computadora"
  Lugar: Cd. del Carmen Camp. México
  Nombre del Archivo: nodo.h
  
*/

/*inicio de la clase nodo, hereda de la clase dispositivo*/

//21/04/04 18:50
class nodo:public dispositivo{
    string tipo_nodo;
    int nodo_ref;
    int ramas_conect;
public:
    nodo(int nva_id, string t, string et, int e, string tn)
    :dispositivo(nva_id,t,et,e){
    tipo_nodo=tn;
    nodo_ref=0;
    ramas_conect=0;
    };
    void mete_tiponodo(string tnodo){
    tipo_nodo=tnodo;    
    }
    void activa_nodoref(int nref){//le metemos el numero de nodo 
    nodo_ref=nref;//de referencia que le corresponde
    }
    void adiciona_ramaconect(){
    ramas_conect++;
    }
    string saca_tiponodo(void){
    return tipo_nodo;
    }
    int checa_nodoref(void){
    return nodo_ref;
    }
    int checa_ramasconect(void){
    return ramas_conect;
    }

};

/*fin de la clase nodo*/
