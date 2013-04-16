/*
  Nombre: CASE*c
  Copyright: RobertRevolver © 2004  
  Autor: Roberto Flores Santiago
  Email: robertrevolver@hotmail.com, robertrevolver@yahoo.com.mx
  fecha: 07/04/04 17:24
  Descripcion: CASE*c "Cálculos y Análisis de Sistemas Eléctricos por Computadora"
  Lugar: Cd. del Carmen Camp. México
  Nombre del Archivo: rama.h
  
*/

/*Inicio de la clase rama hereda de la clase dispositivo*/
/*22/04/04 18:18*/
class rama:public dispositivo{
    string tipo_rama;
    int nodo_inicio;
    int nodo_final;
     //vector<nodo> vnodo_tmp;
public:
    rama(int nva_id, string t, string et, int e, string tr)
    :dispositivo(nva_id,t,et,e){
    tipo_rama=tr;
    nodo_inicio=0;
    nodo_final=0;
    };
    void mete_tiporama(string trama){
    tipo_rama=trama;    
    }
    void mete_nodoinicio(int ni){
    nodo_inicio=ni;
    }
    void mete_nodofinal(int nf){
    nodo_final=nf;
    }
    string saca_tiporama(void){
    return tipo_rama;
    }
    int saca_nodoinicio(void){
    return nodo_inicio;
    }
    int saca_nodofinal(void){
    return nodo_final;
    }
  
};

/*Fin de la clase rama*/

