/*
  Nombre: CASE*c
  Copyright: RobertRevolver © 2004  
  Autor: Roberto Flores Santiago
  Email: robertrevolver@hotmail.com, robertrevolver@yahoo.com.mx
  fecha: 07/04/04 17:24
  Descripcion: CASE*c "Cálculos y Análisis de Sistemas Eléctricos por Computadora"
  Lugar: Cd. del Carmen Camp. México
  Nombre del Archivo: anlisis_vectores.h
*/


/*Inicio de la clase analisis de vectores*/
class analisis_vectores{
    vector<nodo> vnodo_AUX;//recibe un vector con la informacion de nodos
    vector<rama> vrama_AUX;//recibe un vector con la informacion de ramas
    vector<double> aux;//vector auxiliar de doubles
    vector< vector < double > > Ybus; //matriz -> vector de vectores
    vector<int> vnodosref_aux; //vector de nodos de referencia del sistema 
    //int num_nodos;
public:
    analisis_vectores(vector<int> nr, vector<nodo> vnodo, vector<rama> vrama){
    vnodosref_aux=nr;//este vector de nodos de referencia (vector de enteros, con 0 en la posicion 1)
    vnodo_AUX=vnodo;//copiamos el contenido del vector de nodos del proyecto
    vrama_AUX=vrama;//copiamos el contenido del vector de ramas del proyecto
    aux.push_back(0);//inicializamos el vector auxiliar
    Ybus.clear();//inicializamos el vector de vectores (o la matriz)
    }
    void crea_matriz(vector<int> nr, vector<nodo> vnodo, vector<rama> vrama){//d
    double elem=0.0;//auxiliar para meter datos a la matriz
    
    /*Nota: Hy que recordar que estos vectores traen un objeto dummy en 
    la posicion cero*/
    int n=0;
    int k=0;
    elem = 0;
    int num_nodos=vnodo_AUX.size()-1;//obtenemos el num de nodos del tamaño del vector
    int num_ramas=vrama_AUX.size()-1;
    }

};

/*Final de la clase analisis de vectores*/
