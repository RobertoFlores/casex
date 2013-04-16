/*
  Nombre: CASE*c
  Copyright: RobertRevolver © 2004
  Autor: Roberto Flores Santiago
  Email: robertrevolver@hotmail.com, robertrevolver@yahoo.com.mx
  fecha: 07/04/04 17:24
  Descripcion: CASE*c "Cálculos y Análisis de Sistemas Eléctricos por Computadora"
  Lugar: Cd. del Carmen Camp. México
  Nombre del Archivo: dispositivo.h
  
*/


/*inicio de la clase dispositivo*/
class dispositivo{
	int id;
	string etiqueta, tipo;
    int edo;
    /*variables electricas*/
    double P,I,V,X;/*P=potencia, I=corriente, V=voltaje, X=impedancia*/
public:
    //constructor con paso de parametros
	dispositivo (int nva_id, string t, string et, int e){
	id=nva_id;
	tipo=t;
    etiqueta=et;
    edo=e;
    P=0;
    I=0;
    V=0;
    X=0;
	}
	//constructor con valores por default
    dispositivo (void){
	id=0;
	tipo="fict";
	etiqueta="Nuevo Dispositivo";
	edo=1;
	P=0;
    I=0;
    V=0;
    X=0;
	}

    /*Manipulacion dato por dato de la informacion de los dispositivos
    sin interaccion de la salida y entrada estandar*/
    void mete_id(int nva_id){
    id=nva_id;
    }
    void mete_tipo(string nvo_tipo){
    tipo=nvo_tipo;
    }
    void mete_etiqueta(string nva_etiqueta){
    etiqueta=nva_etiqueta;
    }

    int saca_id(void){
    return id;
    }
    string saca_tipo(void){

    return tipo;
    }
    int estado(void){//consulta el estado del nodo
    return edo;
    }
    string saca_etiqueta(){
    return etiqueta;
    }

	void mete_pot(double pot){
    P=pot;
    }
	void mete_volts(double volts){
	V=volts;
    }
	void mete_amps(double amps){
	I=amps;
    }
	void mete_resist(double resist){
	X=resist;
    }
	double saca_pot(void){
    return P;
    }
	double saca_volts(void){
	return V;
    }
	double saca_amps(void){
	return I;
    }
	double saca_resist(void){
	return X;
    }
    void mete_edo(int e){
    edo=e;
    }
	void cambia_edo(void){
	if (edo == 0)
		edo=1;
	else
    edo=0;
    }


};
