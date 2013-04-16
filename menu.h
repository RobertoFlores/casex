/*
  Nombre: CASE*c
  Copyright: RobertRevolver © 2004
  Autor: Roberto Flores Santiago
  Email: robertrevolver@hotmail.com, robertrevolver@yahoo.com.mx
  fecha: 07/04/04 17:24
  Descripcion: CASE*c "Cálculos y Análisis de Sistemas Eléctricos por Computadora"
  Lugar: Cd. del Carmen Camp. México
  Nombre del Archivo: menu.h

*/

void entrada()
{

  cout << "Bienvenido al Software para Calculo de Sistemas Electricos por Computadora" << endl<<endl;
  cout << "                 >>>>>>>>>>>>>  CASE*c  <<<<<<<<<<<<<<                    " << endl<<endl;
  cout << "   Teclea ayuda para ver la ayuda y una lista de los comandos existentes   " << endl;
  cout << endl;
  cout << "               ** Ultima version v 0.1   16 Junio 2004 **                " << endl;
  cout << "     ** Este programa es desarrollado por: Roberto Flores Santiago **    " << endl;
  cout << " ** Contacto: robertrevolver@hotmail.com, robert@linuxcampeche.com.mx **  " << endl;


  return;
}
void ayuda(){
    cout << "                  Comandos           "<<endl<<endl;
    cout << "     inicio      ->     Muestra Informacion de Entrada "<<endl;
    cout << "     nuevo       ->     Adiciona un nuevo proyecto "<<endl;
    cout << "     nodo        ->     Adiciona nodos al proyecto "<<endl;
    cout << "     rama        ->     Adiciona ramas al proyecto "<<endl;
    cout << "     ver         ->     Ver los datos del proyecto "<<endl;
    cout << "     abrir       ->     Abrir proyecto existente "<<endl; 
    cout << "     guardar     ->     Guardar cambios del proyecto "<<endl;
    cout << "     calcular    ->     Calcula el cortocircuito "<<endl;
    cout << "     ayuda       ->     Muestra lista de comandos "<<endl;
    cout << "     salir       ->     Salir del programa "<<endl;
    return;

}



int flujo(void)
 {
  char* car_entrado;
  char* car_arg;

  int num_args = 0;
  
  proyecto *nvo_proy=new proyecto(1,"Nuevo proyecto");
  car_entrado = new char[200];
  car_arg = new char[20];



do
{
  cout << "\ncase*c> ";
  cin.getline(car_arg, 200);
  
  if(strcmp(car_arg, "inicio") == 0){
  entrada();
  
  }
  

	//---------------------- nuevo------------------------------
	else if (strcmp(car_arg, "nuevo") == 0)
	{
	cout << "Crear un proyecto nuevo" << endl<<endl;
	
	   
    cout<<"Dame el Id del proyecto: ";
    int aux;//declaramos una var entera auxiliar
    cin>>aux;//leemos aux
    nvo_proy->mete_id(aux);//metemos el id del proyecto
 
    string etiq;
    cout<<"Dame el Nombre del Proyecto: ";
    cin>>etiq;
    nvo_proy->mete_etiqueta(etiq);
    cout<<endl;
    
     
	}
	//---------------------- nodo------------------------------
	else if (strcmp(car_arg, "nodo") == 0)
	{
	cout << "Adicionar un nodo al proyecto" << endl;
	int id,edo;//id y estado del  dispositivo
	string tipo, etiq_nodo, tipo_nodo;//tipo de dispositivo y etiqueta
	double resist;//resistencia del nodo
	nodo *a=new nodo(1,"nodo","Dummy",0,"no-contribuye");//datos para inicializar el nodo
    cout<<"Dame el id del nodo: ";
    cin>>id;
    a->mete_id(id);
    //metemos automaticamente el tipo de dispositivo que es nodo
    tipo="nodo";
    a->mete_tipo(tipo);
    //metemos la etiqueta del nodo, gen-1, fict-1 o motor 2, etc.
    cout<<"dame la etiqueta del nodo: ";
    cin>>etiq_nodo;
    a->mete_etiqueta(etiq_nodo);
    //metemos el estado del nodo
    cout<<"Dame el estado del nodo, 1=on y 0=off: ";
    cin>>edo;
    a->mete_edo(edo);
    //metemos el tipo de nodo: gen, no-contrib, motor etc.
    cout<<"dame el tipo de nodo: ";
    cin>>tipo_nodo;
    a->mete_tiponodo(tipo_nodo);
    //metemos la resistencia del nodo
    cout<<"Dame la resistencia del nodo: ";
    cin>>resist;
    a->mete_resist(resist);
    //metemos el nodo al proyecto
    nvo_proy->mete_nodo(*a);
    //destruimos el nodo
    delete a;
    
	}
	//---------------------- rama------------------------------
	else if (strcmp(car_arg, "rama") == 0)
	{
	cout << "Adicionar una rama al proyecto" << endl<<endl;
	int id,edo,nodo_inicio,nodo_final;//id y estado del  dispositivo
	string tipo, etiq_rama, tipo_rama;//tipo de dispositivo, etiqueta y tipo de rama
	double resist;//resistencia de la rama
	rama *b=new rama(1,"rama","rama_dummy",1,"alim");//creamos la rama dinamicamente
	cout<<"Dame el id de la rama: ";
    cin>>id;
    b->mete_id(id);
    //metemos automaticamente el tipo de dispositivo que es rama
    //tipo="rama";
    b->mete_tipo("rama");
    //metemos la etiqueta de la rama, gen-1, fict-1 o motor 2, etc.
    cout<<"dame la etiqueta de la rama: ";
    cin>>etiq_rama;
    b->mete_etiqueta(etiq_rama);
    
    //metemos el estado de la rama
    cout<<"Dame el estado de la rama, 1=cerrada y 0=abierta: ";
    cin>>edo;
    b->mete_edo(edo);
    //metemos el tipo de rama: int, tr, alim etc.
    cout<<"dame el tipo de rama: ";
    cin>>tipo_rama;
    b->mete_tiporama(tipo_rama);
    //metemos la resistencia de la rama
    cout<<"Dame la resistencia de la rama: ";
    cin>>resist;
    b->mete_resist(resist);
    cout<<"Dame el nodo inicial de la rama: ";
    cin>>nodo_inicio;
    b->mete_nodoinicio(nodo_inicio);
    cout<<"Dame el nodo final de la rama: ";
    cin>>nodo_final;
    b->mete_nodofinal(nodo_final);
    //metemos la rama al proyecto
    nvo_proy->mete_rama(*b);
    //destruimos la rama dinamica
     delete b;
	}
	//---------------------- ver------------------------------
	else if (strcmp(car_arg, "ver") == 0)
	{
	cout<<"Los datos almacenados del proyecto son: "<<endl<<endl;
    nvo_proy->muestra_datos();
	}
	//---------------------- abrir ---------------------------
	else if (strcmp(car_arg, "abrir") == 0)
	{
		cout << "Abrir proyecto existente" << endl;
	}
	//---------------------- guardar ---------------------------
	else if (strcmp(car_arg, "guardar") == 0)
	{
		cout << "Guarda proyecto" << endl;
	}
	//---------------------- calcular ---------------------------
	else if (strcmp(car_arg, "calcular") == 0)
	{
		cout << "Calcula el Cortocircuito" << endl;
		nvo_proy->calcula_admitancias();//esta funcion forma el diagrama de impedancias
                                //despues calcula las admitancias de las ramas
                                //y forma el diagrama de admitancias
        nvo_proy->muestra_impedancias_ramas();//autoexplicativa
 
        nvo_proy->marca_nodos_referencia();//marcamos los nodos referencia
        nvo_proy->muestra_nodos_referencia();//mostramos los nodos que son de referencia
                            //o sea los que tienen mas de una rama conectada
  
        cout<<"La cantidad de nodos de referencia es: "<<nvo_proy->saca_num_nodosref()<<endl;
        cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
        nvo_proy->muestra_datos();//mostramos datos del proyecto
        nvo_proy->llena_matriz2();
        nvo_proy->muestra_matriz();
        //vinculacion a la clase matriz
        matriz A;//creamos un objeto tipo matriz
        cout<<"Muestra matriz con objetos"<<endl;
        int nr=nvo_proy->saca_num_nodosref();//variable auxiliar que contiene el num nodos referencia
        A.muestra(nvo_proy->saca_matriz(),nr,nr);
        double **MA=A.CreaMatrizAumentada(nvo_proy->saca_matriz(),nr,nr);
        cout<<"La matriz aumentada es: "<<endl; 
        A.muestra(MA,nr,2*nr);
        cout<<"La inversa de la matriz es: "<<endl;
        A.GaussJordan(MA,nr,2*nr);
        A.muestra(MA,nr,2*nr);
        nvo_proy->calcula_cc(MA);//entrega las corrientes de cortocircuito en por unidad

	}
	//---------------------- ayuda ------------------------------

    else if(strcmp(car_arg, "ayuda") == 0)
    {
      ayuda();
    }
   //---------------------- salir ------------------------------

    else if(strcmp(car_arg, "salir") == 0)
    {
      //borramos el proyecto creado
      delete nvo_proy;
      cout << "Saliendo del Programa..." << endl;
    }

   
    else// if (flag == 0)
    {
      cout << "\nComando Invalido: " << car_arg << endl;
    }



  }
  while (strcmp(car_arg, "salir") != 0);


  delete[] car_entrado;
  delete[] car_arg;
  return 0;
 }
