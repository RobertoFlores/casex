/*
  Nombre: CASE*c
  Copyright: RobertRevolver © 2004  
  Autor: Roberto Flores Santiago
  Email: robertrevolver@hotmail.com, robertrevolver@yahoo.com.mx
  fecha: 11/06/04 17:24 <- inclusion al proyecto
  Descripcion: CASE*c "Cálculos y Análisis de Sistemas Eléctricos por Computadora"
  Lugar: Cd. del Carmen Camp. México
  Nombre del Archivo: matriz.h
  Descripcion: Manejo dinamico de matrices, calculo de matriz inversa
*/
class matriz{

public:

matriz(void){//constructor
}


double **crea_matriz(int r, int c){
  double **matriz;
  matriz = new double *[r];
  for (int i = 0; i < r; i++){
      matriz[i] = new double [c];
    }
  return(matriz);
  }//funcion crea matriz
  
void mete(double **m,int nr,int nc){
//ciclo desahabilitado por pruebas de matriz inversa
for(int i=0;i<nr;i++)
    for(int j=0;j<nc;j++){
    m[i][j]=i;
    }
    

}//mete

double **CreaMatrizAumentada(double **MatrizInicial, int r, int c){//matriz aumentada
  int ca=c*2;
  //igualamos los datos de la matriz inicial con la parte derecha de la martiz aumentada
  double **matriz;
  matriz = new double *[r];
  for (int i = 0; i < r; i++){
      matriz[i] = new double [ca];
    }
  //metemos los datos a la parte izquierda de la matriz aumentada
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        matriz[i][j]=MatrizInicial[i][j];
        }
    }
    //metemos ceros y unos convenientemente en la parte derecha de la matriz aumentada
    for(int i=0;i<r;i++){//recorrido de filas
        for(int j=c;j<ca;j++){//recorrido de columnas de la parte derecha de la matriz aumentada
                if(i+c==j){
                matriz[i][j]=1;//la diagonal principal es la unidad
                }else{
                matriz[i][j]=0;//triangular superior e inferior es 0
                }

        }
    }
    return(matriz);
  }//funcion crea matriz aumentada 
  

double **transpuesta(double **MatrizInicial, int f, int c)
{

  double **MatrizTrans = crea_matriz(f,c);

  for (int j = 0; j < c; j++)
  {
        for (int h = 0; h < f; h++)
        {
                MatrizTrans[j][h] = MatrizInicial[h][j];
        }
  }

return(MatrizTrans);
}//transpuesta

/*determinante*/

/*determinante*/

void muestra(double **m, int f, int c ){
for(int i=0;i<f;i++){
    for(int j=0;j<c;j++){
    cout<<m[i][j]<<" , ";
       }
     cout<<endl;
     }
}//muestra

/*-*-*-*-la inversa*-*-*-*-**/

double **GaussJordan(double **m, int f, int c){//recibe matriz aumentada


double tmp;//valor temporal

for (int z=0;z<f;z++){//ciclo principal
    tmp=m[z][z];
    for(int j=0;j<c;j++){
       m[z][j]=m[z][j]/tmp;
        }//for j
    for(int i=0;i<f;i++){
        if(i!=z){
        tmp=m[i][z];
        for (int j=0;j<c;j++){
     m[i][j]=m[i][j]-tmp*m[z][j];
        }
        }//if
    }
    }//ciclo principal z
    return (m);
}//GaussJordan
};//de la clase matriz

 /*Si quieres usar esta clase, las lineas siguientes
 muestran como declarar y utilizar la clase matriz*/
 /*
 
 double **M;
 matriz A;
 M=A.crea_matriz(3,3);
 A.mete(M,3,3);
 cout<<"La matriz original es: "<<endl;
 A.muestra(M,3,3);
 cout<<"La matriz transpuesta es: "<<endl;
 A.muestra(A.transpuesta(M,3,3),3,3);
 cout<<"la matriz aumentada es: "<<endl;
 A.muestra(A.CreaMatrizAumentada(M,3,3),3,6);
 cout<<"la matriz inversa es: "<<endl;
A.muestra(A.GaussJordan(A.CreaMatrizAumentada(M,3,3),3,6),3,6);

 */

 
