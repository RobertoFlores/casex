/*
  Nombre: CASE*c
  Copyright: RobertRevolver © 2004
  Autor: Roberto Flores Santiago
  Email: robertrevolver@hotmail.com, robertrevolver@yahoo.com.mx
  fecha: 07/04/04 17:24
  Descripcion: CASE*c "Cálculos y Análisis de Sistemas Eléctricos por Computadora"
  Lugar: Cd. del Carmen Camp. México
  Nombre del Archivo: proyecto.h

*/

/*Inicio de la clase proyecto*/
class proyecto{
    int id_proy;
    string etiqueta;
    vector<nodo> vnodo_DU;//vector de nodos para el Diagrama Unifilar
                          //Solo existe uno ya que los nodos no se modifican
                          //solo las rmas al cobnvertirse en diagrama de
                          //impedancias y admitancias
    vector<rama> vrama_DU;//vector de ramas para el Diagrama Unifilar
    vector<rama> vrama_DI;//vector de ramas para el diagrama de impedancias
    vector<rama> vrama_DA;//vector de ramas para el diagrama de admitancias
                          //Las ramas se modifican al convertirse de la rama
                          //original al diagrama de impedancias/admitancias
                          //ya que se le suman la impedancias de los nodos de
                          //de cada uno de sus extremos
    int num_nodos,num_ramas,num_nodosref;
    vector<int> vnodosref;//vector de nodos de referencia
    vector< vector < double > > Ybus; //matriz -> vector de vectores
//  double Ybus2[10][10];//matriz para guardar las admitancias
  double **Ybus1;//martiz dinamica para guardar las admitancias
    vector<double> aux;//vector auxiliar de doubles para llenado de matriz
public:

    proyecto (int id, string et){    //constructor parametrizado
    id_proy=id;
    etiqueta=et;
    num_nodos=0;
    num_ramas=0;
    num_nodosref=0;
    //inicializamos el vector de nodos
     nodo dummy(0,"nodo","DUMMY",0,"NODO DUMMY");
     vnodo_DU.push_back(dummy);
     //inicializamos el vector de ramas
     rama rdummy(0,"rama","DUMMY",0,"RAMA DUMMY");
     vrama_DU.push_back(rdummy);
     //inicializamos el vector de nodos de referencia
     vnodosref.push_back(0);
     //inicializando la matriz Ybus "vector de vectores"
     Ybus.clear();
    }
    void mete_id(int id){
    id_proy=id;
    }
    void mete_etiqueta(string et){
    etiqueta=et;
    }
    void mete_nodo(nodo nn){
    vnodo_DU.push_back(nn);
    num_nodos++;
    }
    int muestra_id(void){
    return id_proy;
    }
    string muestra_etiqueta(void){
    return etiqueta;
    }
    void mete_rama(rama nr){
    vrama_DU.push_back(nr);
    num_ramas++;
    }
    void muestra_datos(void){    //muestra los datos del proyecto por la salida
    cout<<"El Num. de Id del proyecto es: "<<id_proy<<endl; //estandar
    cout<<"El nombre del proyecto es: "<<etiqueta<<endl;
    cout<<"El numero de nodos es: "<<num_nodos<<endl;
    cout<<"El numero de ramas es: "<<num_ramas<<endl;
    }

    void suma_impedancias(void){//23/04/04 13:24
    //lo que realiza este metodo, esta contenido tambien, en el metodo
    //calcula admitancias, por requerimiento del mismo
    //se deja este metodo por flexibilidad, em el caso en el que se quiere
    //formar solo el diagrama de impedancias
    //el diagrama de impedancias esta formado por los vectores: vnodo_DU y vrama_DI
    vrama_DI=vrama_DU;//compiamos el contenido de vrama_DU en vrama_DI
    int h;
        for(h=1;h<=num_ramas;h++){
            vrama_DI[h].mete_resist(vrama_DI[h].saca_resist()+vnodo_DU[vrama_DI[h].saca_nodoinicio()].saca_resist()
                +vnodo_DU[vrama_DI[h].saca_nodofinal()].saca_resist());
        }

    }
    void calcula_admitancias(void){ //28/04/2004
    //el siguiente codigo, se encarga de añadir las
    //impedancia de los nodos, a la rama a la que esta conectado.
    //para crear el diagrama de impedancias
    //el diagrama de impedancias esta formado por los vectores: vnodo_DU y vrama_DI
        vrama_DI=vrama_DU;//compiamos el contenido de vrama_DU en vrama_DI

        for(int h=1;h<=num_ramas;h++){
            vrama_DI[h].mete_resist(vrama_DI[h].saca_resist()+vnodo_DU[vrama_DI[h].saca_nodoinicio()].saca_resist()
                +vnodo_DU[vrama_DI[h].saca_nodofinal()].saca_resist());
        }
    //el siguiente codigo calcula las admitancias de las ramas
    //a partir de los datos del diagrama de impedancias
    //y forma el diagrama de admitancias
    //el diagrama de admitancias esta formado por los vectores: vnodo_DU y vrama_DA
        vrama_DA=vrama_DI;//compiamos el contenido de vrama_DI en vrama_DA
        for(int h=1;h<=num_ramas;h++){
                double aux=vrama_DA[h].saca_resist();
                   if(aux==0){//prevenimos la division por cero
                     vrama_DA[h].mete_resist(aux);
                   }else{
                     aux=-1/vrama_DA[h].saca_resist();
                     vrama_DA[h].mete_resist(aux);
                   }

        }

    }

    void marca_nodos_referencia(){//a-marca los nodos que son de referencia
                                    //o sea aquellos que tienen mas de una rama
                                    //conectada a si mismo
        for(int h=1;h<=num_nodos;h++){//b-recorrido del vector de nodos
                for(int i=1;i<=num_ramas;i++){//c-recorrido del vector de ramas
                                //comparamos el id de nodo con el id almacenado en la
                                //variable nodo inicio de la rama
                                if (vnodo_DU[h].saca_id()==vrama_DU[i].saca_nodoinicio()){
                                //incrementamos en uno la variable rama_conect
                                //dentro de nodo
                                vnodo_DU[h].adiciona_ramaconect();
                                }
                                //comparamos el id de nodo con el id almacenado en la
                                //variable nodo final de la rama
                                if (vnodo_DU[h].saca_id()==vrama_DU[i].saca_nodofinal()){
                                //incrementamos en uno la variable rama_conect
                                //dentro de nodo
                                vnodo_DU[h].adiciona_ramaconect();
                                }

                }//c-


        if (vnodo_DU[h].checa_ramasconect()>1){//condicion-comparamos el total de ramas
        //conectadas al nodo,si es mayor que 1 significa que es de referencia
                num_nodosref++;//incrementamos el contador de nodos de referencia
                vnodo_DU[h].activa_nodoref(num_nodosref);//activamos ese nodo como referencia

                }//condicion
        }//b-
    }//a-

    void muestra_impedancias_ramas(void){//metodo auxiliar temporal
    double aux;
        for(int j=1;j<=num_ramas;j++){
            aux=vrama_DU[j].saca_resist();
            cout<<"La impedancia de la rama " <<j<< "en el Diagrama Unifilar es: "<<aux<<endl;
            }
        for(int j=1;j<=num_ramas;j++){
            aux=vrama_DI[j].saca_resist();
            cout<<"La impedancia de la rama " <<j<< "para en el Diagrama de Impedancias es: "<<aux<<endl;
            }
        for(int j=1;j<=num_ramas;j++){
            aux=vrama_DA[j].saca_resist();
            cout<<"La Admitancia de la rama "<<j<< "en el Diagrama de Admitancias es: "<<aux<<endl;
            }

    }
    void muestra_nodos_referencia(void){//metodo auxiliar
        for(int m=1;m<=num_nodos;m++){
          if (vnodo_DU[m].checa_nodoref()!=0)
          cout<<"El Nodo con Id = "<<vnodo_DU[m].saca_id()<<"  Es un nodo de referencia"<<endl;
        }
    }
   int saca_num_nodosref(void){//devuelve el numero
     return num_nodosref;       //de nodos de referencia
                                //que a la vez es el orden de la matriz
                                //de Ybus
    }

    void llena_vnodosref(void){//llena el vector de nodos referencia utilizar despues de marcanodos de referencia
        for(int b=1;b<=num_nodosref;b++)//recorremos los nodos de referencia
        vnodosref.push_back(b);//los metemos al vector, inicializado con un 0 en la primer posicion
    }
    vector<int> saca_vnodosref(void){//devuelve el vector de nodos de referencia
    return vnodosref;
    }

    vector<nodo> saca_vnodo(void){
    return vnodo_DU;
    }
    vector<rama> saca_vrama(void){
    return vrama_DA;
    }
    int saca_numnodos(void){
    return num_nodos;
    }

    //iniciando metodos para llenado de matriz
/*La funcion llena matriz, tuvo un tiempo de desarrollo de aproximadamente 5 horas
  repartidas en una semana, se llevó 57 lineas de codigo y se terminó de realizar
  el dia 18 de mayo del 2004. Esta funcion es con mucho la mas complicada
  de todo el proyecto cualquier comentario enviarlo a: robertrevolver@hotmail.com */


   void llena_matriz(void){
     double elem=0;//inicializamos el elemento auxiliar

      Ybus.push_back(aux);//inicializamos la matriz
      aux.push_back(0.0);//iniciamos el vector auxiliar
     for(int i=1;i<=num_nodosref;i++){//recorremos los nodos de referencia para llenar las filas
      for(int j=1;j<=num_nodosref;j++){//recorremos el llenado de columnas
        if(i==j){//diagonal principal
        //si el id de este nodo encontrado es igual al de alguna rama , se suma la admitancia
                        for(int b=1;b<=num_ramas;b++){//recorrido del numero de ramas
                          if (vrama_DA[b].saca_nodoinicio() == sacaid_nodoref(i)){
                            elem=elem + vrama_DA[b].saca_resist();
                            }
                          if (vrama_DA[b].saca_nodofinal() == sacaid_nodoref(i)){

                            elem=elem + vrama_DA[b].saca_resist();
                            }


                        }//del for de recorrido de ramas

          }//del if de la diagonal principal

     /*Para todos los elementos donde i!=j i es diferente de j o sea todos
     aquellos elementos que no forman parte de la diagonal principal*/
       for(int h=1;h<=num_ramas;h++){//recorrido de ramas
               if((vrama_DA[h].saca_nodoinicio()==sacaid_nodoref(i))&&(vrama_DA[h].saca_nodofinal()==sacaid_nodoref(j))){

                  elem=vrama_DA[h].saca_resist()*-1;
                 }
              if((vrama_DA[h].saca_nodoinicio()==sacaid_nodoref(j))&&(vrama_DA[h].saca_nodofinal()==sacaid_nodoref(i))){

                  elem=vrama_DA[h].saca_resist()*-1;
                 }


       }//del for de recorrido de ramas



      if(elem==0){//si pasó por todos aquellos filtros y obtuvo valor
      aux.push_back(elem);//metemos ese valor
      }else{//en caso contrario, metemos elem con valor cero
              aux.push_back(elem);//metemos elem=0
              elem=0;//reasignamos el valor de elem a cero
            }


      }//for de columnas j

      Ybus.push_back(aux);//metemos el vector de filas en la matriz
      aux.clear();//limpiamos el vector auxiliar
      aux.push_back(0.00);//llenamos la primera posicion

     }//for de filas i


     }//de la funcion llena matriz
     
     //inicio de la funcion crea matriz
     double **crea_matriz(int r, int c){
     
     double **matriz;
     matriz = new double *[r];
     
     for (int i = 0; i < r; i++){
           matriz[i] = new double [c];
               }
  return(matriz);
  }//funcion crea matriz
     
     void llena_matriz2(void){
     
    
    Ybus1=crea_matriz(num_nodosref,num_nodosref);
     //inicializamos la matriz
     double elem=0;//inicializamos el elemento auxiliar
     for(int i=0;i<num_nodosref;i++){//recorremos los nodos de referencia para llenar las filas
      for(int j=0;j<num_nodosref;j++){//recorremos el llenado de columnas
            
            if (i==j){//diagonal principal i==j
            for(int b=1;b<=num_ramas;b++){//recorrido del numero de ramas
                          if (vrama_DA[b].saca_nodoinicio() == sacaid_nodoref(i+1)){
                            elem=elem + vrama_DA[b].saca_resist();
                            }
                          if (vrama_DA[b].saca_nodofinal() == sacaid_nodoref(i+1)){

                            elem=elem + vrama_DA[b].saca_resist();
                            }
                  }          
            }//del if (i==j)
            
            if(i<j){//triangular superior 
            for(int h=1;h<=num_ramas;h++){//recorrido de ramas
               if((vrama_DA[h].saca_nodoinicio()==sacaid_nodoref(i+1))&&(vrama_DA[h].saca_nodofinal()==sacaid_nodoref(j+1))){

                  elem=vrama_DA[h].saca_resist()*-1;
                 }
              if((vrama_DA[h].saca_nodoinicio()==sacaid_nodoref(j+1))&&(vrama_DA[h].saca_nodofinal()==sacaid_nodoref(i+1))){

                  elem=vrama_DA[h].saca_resist()*-1;
                 }


                        }//del for de recorrido de ramas
            
            }//triangular superior 
            
            if(i>j){//triangular inferior
            for(int h=1;h<=num_ramas;h++){//recorrido de ramas
               if((vrama_DA[h].saca_nodoinicio()==sacaid_nodoref(i+1))&&(vrama_DA[h].saca_nodofinal()==sacaid_nodoref(j+1))){

                  elem=vrama_DA[h].saca_resist()*-1;
                 }
              if((vrama_DA[h].saca_nodoinicio()==sacaid_nodoref(j+1))&&(vrama_DA[h].saca_nodofinal()==sacaid_nodoref(i+1))){

                  elem=vrama_DA[h].saca_resist()*-1;
                 }


                        }//del for de recorrido de ramas
            
            }//triangular inferior
            /*aqui*/
           if(elem==0){//si pasó por todos aquellos filtros y no obtuvo valor
                 Ybus1[i][j]=elem;//metemos ese valor
      }else{//en caso contrario, metemos elem con valor cero
              Ybus1[i][j]=elem;//metemos elem=0
              elem=0;//reasignamos el valor de elem a cero
            }
           
              }//del for de llenado de columnas j
             
    }//del for de llenado de filas i
     
     
     }//de la funcion llena matriz2
     
    int sacaid_nodoref(int id_nodoref){//muestra el id de nodo, que corresponde al nodo referencia que le pases

      for(int f=1;f<=num_nodos;f++){//recorrido de nodos
        if(vnodo_DU[f].checa_nodoref()==id_nodoref){
          return vnodo_DU[f].saca_id();
          }
        }

      }//finde la funcion sacaid_nodoref


    void muestra_matriz(void){

      for(int i=0;i<num_nodosref;i++){//recorremos los nodos de referencia para llenar las filas
          for(int j=0;j<num_nodosref;j++){//recorremos el llenado de columnas

              cout<<Ybus1[i][j]<<"   ";

          }
          cout<<endl;
        }

        }
      
      double **saca_matriz(void){
      return(Ybus1);
      }
      void calcula_cc(double **Ybus){
      //double **aux=crea_matriz(num_nodosref, num_nodosref);//<-mmmmmhhhh
      //empezando con un ciclo, recordando quela matriz que recibimos
      //inicia con subindice cero, o sea el primer dato esta en Ybus[0][0]
      int  dos_nr=num_nodosref*2;//este es el orden de la matriz recibida
      int nodos_Icc=1;
      for (int i=0;i<num_nodosref;i++){
            for(int j=num_nodosref;j<dos_nr;j++){
                  if(j==i+num_nodosref){
                  double Icc=-1/Ybus[i][j];
                  cout<<"Para el nodo de ref "<<i+1<<" la corriente de cc en P.U. Icc="<<Icc<<" P.U."; 
                  }//del if 
              }//del ciclo j
            cout<<endl;
            }// del ciclo i
      }


}; /*Fin de la clase proyecto*/


