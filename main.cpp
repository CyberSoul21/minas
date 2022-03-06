  #include <iostream> //Librería necesaria para usar cout y cin
    #include <cstdlib>//Libreria necesaria para utilizar rand()
    #include <stdio.h>
    #include <conio.h>
    #include<time.h>

    //#include "tablero.h"//Libreria que incluye los prototipos de las funciones a utilizar

    #define KEY_UP 72 //Definición del valor que toma el char que alberga la tecla UP

    using namespace std;

    struct casilla {
     char posicion;
     char *nombre=new char[30];
    };
    struct almacena_nombres {
     char *nombres=new char[30];
    };
    struct almacena_nombres *pnombres;
    struct almacena_nombres reg[5];


    casilla*  crear_columnas(int n); //función del tipo  arreglo char que crea un arreglo de char con un tamaño entero n, que respresenta a las columnas de la matriz
    casilla** crear_matriz(int n, int m);//Función del tipo matriz charr que crea una matriz a partir de un tamaño de columna de y de fila n y m
    casilla ** escribir(casilla **a,int n,int m);//Función del tipo matriz char que recibe una matriz a, un tamaño de columna n y de fila m y pone valores dentro de cada casilla de las columnas y las filas


    char* crear_cadena(int n);//crea una cadena de caracteres la cual va a ser usada para almacenar el nombre
    char* leer_nombre_de_ficha(istream& is,char* nombre_de_ficha,int n);//sirve para leer la cadena que corresponde al nombre de la ficha ingresada desde el teclado
    ostream& escribir_nombre(ostream&, char* nombre_de_ficha);//escribe el nombre de la ficha


    void imprimir_tablero(casilla**a,int n,int m);//Función del tipo void que recibe una matriz a, un tamaño de columna n y fila m e imprime en consola la matriz a.

    int* random(int* r);//función del tipo Arreglo entero que llena un arreglo de 2 posiciones con números de 0 a 7

    casilla** mov_caballo(casilla** a,int n,int m);//Función del tipo matriz char que recibe la matriz a, y los tamaños de columna y fila n y m para retornar los valores que puede tomar el movimiento del grupo armado el cual se mueve como caballo de ajedrez

    casilla** crear_campesinos(casilla**a);//Función del tipo matriz de char que recibe una matriz a de char y retorna los valores que corresponden a las coordenadas de donde salen cada uno de los 4 campesinos

    casilla** mov_campesino(casilla**a);//Función del tipo matriz de char que recibe una matriz char y genera valores en los cuales puede caer un campesino al realizar un movimiento

    casilla** crear_antiexplosivos(casilla**a);//Función del tipo matriz de char que recibe una matriz char a para retornar los valores que corresponden a las coordenadas en donde es creado el antiexplosivo

    casilla** poner_antiexplosvo(casilla** a,int m,int k,int l);//Función del tipo matriz de char la cual recibe tres enteros m,k,l lo cuales corresponden al movimiento elegido, la coordenada que correponde a las columnas, y la coordenada de las filas respectivamente

    casilla** poner_caballo(casilla **a,int v,int k, int l);//Función del tipo matriz de char que recibe los entreos v,k,l que corresponden al movimiento elegito(v), la coordenada en columnas (k) y la coordenada en fila (l)

    int* buscar_ficha(int* c,casilla** a,char b);//

    int aleatorio(int n);//Funcion del tipo entero que retorna un aleatorio entre 1 y en numero deseado

    bool buscar_ficha_bool(casilla** a,char camp);

    casilla** poner_campesino(casilla** a,int m,char camp,int f,int c);//Función del tipo matriz de char que recibe la matriz a, el movimiento m, el campesino a posicionar, la coordenada fila f y la coordenadan fila c que le genera la función mov_campesino para imprimir dicho movimiento en pantalla

    int localiza_campesinos(casilla** a,int f,int c);//Función del tipo entero que recibe una matriz a, y los enteros f y c para buscar en cual casilla hay un campesino, en caso de encontaro, retorna un valor entero para indicar si hay o no un campesino en la casilla

    int no_hay_mina(casilla** a,int f,int c);//Fnción del tipo entero muy similar a la función localiza campesinos, pero en lugar de buscar campesinos, comprueba si en una casilla hay una bomba

    casilla** muere_campesino(casilla** a,int f,int c);//Función del tipo matriz de char que recibe una matriz a, y los enteros f y c. Que retorna un valor NULL para reemplazar a un campesino que haya caido en una casilla ocupada por una bomba

    casilla** elimina_mina(casilla** a,int f,int c);//Función del tipo matriz de Entero que recibe la matriz a, y los entero f y c. Cambia el valor 'B' de una casilla por un 'A' en caso de que el antiexplosivos caiga sobre una bomba

    casilla** mov_antiexplosivo(casilla**a);//Función del tipo matriz de char que recibe una matriz a, y retorna las coordenadas que corresponden al movimiento en forma de alfil o de torre de un antiexplosivo

    void pulsa_tecla();//Función del tipo void que corre el programa cuando se le presiona únicamente la tecla UP, en caso de contrario no reacciona

    int exito_NoExito(casilla** a);//función del tipo entero que recibe la matriz a y evalua 2 condiciones mediante un IF-ELSE para determinar si el juego acaba o no

    void buscar_ficha(casilla** pmatriz,char b);
    char *buscar_ficha2(char b);

    int main()
    {
        pnombres=&reg[0];

        //Variables declaradas globalmente
        casilla **a;   //Matriz que representa el tablero
        bool flag = true; //Variable del tipo Boolean, utilizado como condicional para romper algunos ciclos
        char* nombre_antiexplosivo=crear_cadena(30);
        char* nombre_grupo_armado=crear_cadena(30);
        char* nombre_campesino1=crear_cadena(30);
        char* nombre_campesino2=crear_cadena(30);
        char* nombre_campesino3=crear_cadena(30);
        char* nombre_campesino4=crear_cadena(30);


        a = crear_matriz(8,8);  //Se iguala la matriz tablero a la función crear filas, para que tenga 8 filas y 8 columnas
        a = escribir(a,8,8);  //Se iguala la matriz tablero a la función escribir para imrpimir en pantalla el tablero
        char c1=3,c2=4,c3=5,c4=6;  //Variables del tipo char que representan los simbolos que corresponden a los campesinos en codigo AISCII
        system("cls");  //Función que limpia el tablero luego de la presentaicón
        cout<<"INTEGRANTES: "<<endl; //Inicio de la presentación del progreama
        cout<<"-> David Camilo Perez Beltran"<<endl;
        cout<<"-> Nicolas Gonzalez"<<endl;
        cout<<"-> Wilson J. Almario R."<<endl;
        cout<<"-> Sebastian Chavez"<<endl;
        cout<<endl;
        cout<<"\t\t     ***********************************  "<<endl;
        cout<<"\t\t     ***                             ***  "<<endl;
        cout<<"\t\t     ***     BIENVENIDO AL JUEGO     ***  "<<endl;
        cout<<"\t\t     ***             MINAS           ***  "<<endl;
        cout<<"\t\t     ***                             ***  "<<endl;
        cout<<"\t\t     ***********************************  "<<endl<<endl;
        cout<<endl;

        cout<<"\t\t                 INSTRUCCIONES           "<<endl;
        cout<<"\t\t                                         "<<endl;
        cout<<"1.Digite la tecla UP o flecha arriba para comenzar"<<endl;
        cout<<"2.Despues de digitada, aparecera la primera mina aleatoriamente"<<endl;
        cout<<"3.Para cada movimiento de la ficha se debe oprimir la tecla UP o flecha arriba"<<endl;
        cout<<"4.La representacion de las minas es: M"<<endl;
        cout<<"5.La representacion del anti-explosivo es: B (bomba)"<<endl;
        cout<<"6.Los campesinos seran representados asi: 1="<<c1<<" 2="<<c2<<" 3="<<c3<<" 4="<<c4<<endl<<endl;
        cout<<endl; //Final de la presentación del programa

        cout<<"Digite UP para continuar: "<<endl; //Instrucción al Usuario para inciar o seguir con el juego
        pulsa_tecla(); //Función del tipo void que permite que el programa solo corra cuando se oprime la tecla UP unicamente

        cout<<"Ingrese el nombre de grupo armado:  ";
        nombre_grupo_armado=leer_nombre_de_ficha(cin,nombre_grupo_armado,30);
        (*pnombres).nombres=nombre_grupo_armado;
        cout<<endl;


        cout<<"Ingrese el nombre de Antiexplosivos:  ";
        nombre_antiexplosivo=leer_nombre_de_ficha(cin,nombre_antiexplosivo,30);
        (*(pnombres+1)).nombres=nombre_antiexplosivo;
        cout<<endl;

        cout<<"Ingrese el nombre de campesino 1:  "<<c1<<":  ";
        nombre_campesino1=leer_nombre_de_ficha(cin,nombre_campesino1,30);
        (*(pnombres+2)).nombres=nombre_campesino1;
        cout<<endl;

        cout<<"Ingrese el nombre de campesino 2:  "<<c2<<":  ";
        nombre_campesino2=leer_nombre_de_ficha(cin,nombre_campesino2,30);
        (*(pnombres+3)).nombres=nombre_campesino2;
        cout<<endl;

        cout<<"Ingrese el nombre de campesino 3:  "<<c3<<":  ";
        nombre_campesino3=leer_nombre_de_ficha(cin,nombre_campesino3,30);
        (*(pnombres+4)).nombres=nombre_campesino3;
        cout<<endl;

        cout<<"Ingrese el nombre de campesino 4:  "<<c4<<":  ";
        nombre_campesino4=leer_nombre_de_ficha(cin,nombre_campesino4,30);
        (*(pnombres+5)).nombres=nombre_campesino4;
        cout<<endl;

        pulsa_tecla();

        imprimir_tablero(a,8,8); //Función del tipo Void que recibe la matriz, y los tamaños de la matriz para imprimir en pantalla
        pulsa_tecla(); //Función del tipo void que permite que el programa solo corra cuando se oprime la tecla UP unicamente
        a = mov_caballo(a,8,8);  //Llama a la función mov_caballo que recibe una matriz junto con su tamaño para generar al grupo armado y que se mueva en en forma de caballo de ajedrez para colocar las bombas

        //imprimir_tablero(a,8,8); //Función del tipo Void que recibe la matriz, y los tamaños de la matriz para imprimir en pantalla
        //pulsa_tecla();//Función del tipo void que permite que el programa solo corra cuando se oprime la tecla UP unicamente
        a = crear_antiexplosivos(a);//Llama a la función crear_antiexplosivo y lo iguala a la matriz para tomar los parámetros de ésta
        a = mov_antiexplosivo(a);
        pulsa_tecla();
        //imprimir_tablero(a,8,8); //Imprime la matriz tablero ahora con el antiexplosivo, los campesinos y las bombas
        a = crear_campesinos(a);//Llama a la función crear_campesinos que recibe la matriz para ubicar las coordenadas que corresponden a los puntos de salida de los 4 campesinos
        //imprimir_tablero(a,8,8);//Imprime los campesinos en sus posiciones iniciales
        //pulsa_tecla();//Función del tipo void que permite que el programa solo corra cuando se oprime la tecla UP unicamente



        do{//Ciclo Do while que llama a las funciones mov_campesino,mov_antiexplosivo, imprimir_tablero y pulsar_tecla, mientras el juego no acabe
            cout<<"Digite UP para movimiento de campesino: "<<endl;//Instrucción al Usuario para inciar o seguir con el juego
            pulsa_tecla();
            a = mov_campesino(a);
            //imprimir_tablero(a,8,8);
            cout<<"Digite UP para movimiento de Anti-explosivo: "<<endl;//Instrucción al Usuario para inciar o seguir con el juego
            pulsa_tecla();
            a = mov_antiexplosivo(a);
            //imprimir_tablero(a,8,8);
            if(exito_NoExito(a)==1){//Ciclo IF-ElSE que evalua si ya murieron 2 campesinos, si por el contrario, el antiexplosivos ya quitó 5 bombas
                flag=false;//Se hace a la bandera flag falsa para que no rompa el ciclo
                imprimir_tablero(a,8,8);
                cout<<"EXITO, el numero de minas es igual a 5 o menor y existen minimo 3 campesinos"<<endl;//En caso de que el antiexplosivo elimine 5 bombas antes de que mueran 2 campesinos
            }
            else if(exito_NoExito(a)==2){
                flag=false;
                imprimir_tablero(a,8,8);
                cout<<"NO EXITO, murieron 2 campesinos :("<<endl;//En caso de que mueran dos campesinos

            };
        }while(flag);
        pulsa_tecla();//Llama a la función para que pida que el usuario digita una ultma vez la tecla Up antes de que el programa termine

        return 0;
    }


    char* crear_cadena(int n){
      return new char [n];
    };

    char* leer_nombre_de_ficha(istream& is,char* nombre_de_ficha,int n){//sirve para leer la cadena que corresponde al nombre
      n=30;
      is.getline(nombre_de_ficha,n);
      return nombre_de_ficha;
    };

    ostream& escribir_nombre(ostream& os, char* nombre_de_ficha){
      os<<nombre_de_ficha;
      return os;
    };

    casilla* crear_columnas(int numero_de_columnas){//Creacion de columnas con vectores unidimensionales
        return new casilla[numero_de_columnas];
    };

    casilla** crear_matriz(int numero_de_columnas, int numero_de_filas){//Se crea la matriz a partir de los vectores, es como si se creara un vector, y cada posicion del vector tuviera un vectro unidimensional (columnas).
        casilla **pmatriz = new struct casilla*[numero_de_filas];
        for(int i=0; i<numero_de_filas;i++){
            *(pmatriz + i)=crear_columnas(numero_de_columnas);
        };
        return pmatriz;
    };

    casilla ** escribir(casilla **pmatriz,int columna,int fila){//Funcion utilizada para modificar el arreglo

        for(int i=0;i<fila;i++){
            for(int j=0; j<columna;j++){
                (*(*(pmatriz+i)+j)).posicion =' ';
            }
        };
        return pmatriz;
    };


    void imprimir_tablero(casilla **pmatriz,int columna,int fila){//Impresion de la matrix en consola, visualmente crea un tablero 8x8
       system("cls");//Limpia impresion anterior
        printf("\n------------------------------\n");
        for(int i=0;i<fila;i++){
            for(int j=0; j<columna;j++){
                if(j<7){
                cout<<" "<<(*(*(pmatriz+i)+j)).posicion<<" |";
                }else{
                    cout<<" "<<(*(*(pmatriz+i)+j)).posicion<<"  ";
                };
            };
            if(i<7){
                printf("\n------------------------------\n");
            };
        };
        printf("\n------------------------------\n");
        cout<<endl;
        cout<<endl;
    };


    int* random(int* prandom){//devuellve un vector de 2 posiciones y cada uno con numeros al azar creados
        prandom= new int[2];
        srand(time(0)); //semilla
        for(int i=0;i<2;i++){
        *(prandom + i)=rand()%8; //rellena con numeros entre 0 y 7
        }
        return prandom;
    };

    int* buscar_ficha(int* pposicion,casilla** pmatriz,char ficha){//Busca la ficha en la matriz, se deben pasar como parametros, el vector donde se guardaran los valores, lamatriz en la cual se va a buscar
                                              //el caracter que se quiere buscar en la matriz
        pposicion = new int[2];//Creacion del vector donde se guardaran las posiciones
        for(int i = 0; i<8;i++){//Realiza la busqueda con un ciclo for.
            for(int j = 0; j<8;j++){
                 if((*(*(pmatriz+i)+j)).posicion == ficha){
                    *pposicion=i;
                    *(pposicion + 1)=j;
                    //cout<<"Lo encontro"<<endl;
                 };
            }
        };
        return pposicion;//Devuelve un vector de tres posiciones 0 y 1 tienen las coordenadas del caracter buscado
    };

    casilla** crear_campesinos(casilla** pmatriz){//Funcion para crear los caracteres que representan los campesinos en las cuatro esquinas
        int cont=0; // Bandera para la impresión de cuántos campesinos murieron en la salida
        int muere=0;
        if(((**pmatriz).posicion=='B')||((**pmatriz).posicion=='W')){//Se determina si existe mina en la posicion inicial de el campesino, si existe entoncesse elimina.
            (**pmatriz).posicion=' ';
            cont++;
            muere=3;
        }else{
            (**pmatriz).posicion=3;
        };

        if(((*(*pmatriz+7)).posicion=='B')||((*(*pmatriz+7)).posicion=='W')){//Se determina si existe mina en la posicion inicial de el campesino, si existe entoncesse elimina.
            (*(*pmatriz+7)).posicion=' ';
            cont++;
            muere=4;
        }else{
            (*(*pmatriz+7)).posicion=4;
        };

        if(((**(pmatriz+7)).posicion=='B')||((**(pmatriz+7)).posicion=='W')){//Se determina si existe mina en la posicion inicial de el campesino, si existe entoncesse elimina.
            (**(pmatriz+7)).posicion=' ';
            cont++;
            muere=5;
        }else{
            (**(pmatriz+7)).posicion=5;
        };

        if(((*(*(pmatriz+7)+7)).posicion=='B')||((*(*(pmatriz+7)+7)).posicion=='W')){//Se determina si existe mina en la posicion inicial de el campesino, si existe entoncesse elimina.
            (*(*(pmatriz+7)+7)).posicion=' ';
            cont++;
            muere=6;
        }else{
            (*(*(pmatriz+7)+7)).posicion=6;
        };
        if(cont==0){
            imprimir_tablero(pmatriz,8,8);//Impresion de tablero
            cout<<"Salida de 4 campesinos en cada esquina"<<endl;//Impresion de los movimientos realizados
            cout<<"Llamados "<<(*(pnombres+2)).nombres<<", "<<(*(pnombres+3)).nombres<<", "<<(*(pnombres+4)).nombres<<", "<<(*(pnombres+5)).nombres<<endl;
            //pulsa_tecla();//Funcion para que solo reciba la flecha arriba como entrada
        }else{
            imprimir_tablero(pmatriz,8,8);//Impresion de tablero
            cout<<"Salida de 4 campesinos en cada esquina"<<endl;//Impresion de los movimientos realizados
            cout<<"Mueren "<<cont<<" campesino en la salida"<<endl;//Impresion de los movimientos realizados
            //pulsa_tecla();//Funcion para que solo reciba la flecha arriba como entrada
        };
        return pmatriz;

    };

    casilla** mov_caballo(casilla** pmatriz,int n,int m){//Funcion que coloca las minas con movimientos de caballo
        int aleatorio_fila,aleatorio_columna,movimiento_aleatorio=0,cont=1;
        int* aleatorio_1=new int[2];//Uso del random
        int* aleatorio_2=new int[2];
        aleatorio_1=random(aleatorio_1);
        aleatorio_fila=*aleatorio_1;
        aleatorio_columna=*(aleatorio_1+1);
        (*(*(pmatriz+aleatorio_fila)+aleatorio_columna)).posicion='W';

        srand(time(NULL));
        do{
            imprimir_tablero(pmatriz,8,8);
            if(cont==1){
                buscar_ficha(pmatriz,'W');
                cout<<"NOMBRE: "<<(*(*(pmatriz+aleatorio_fila)+aleatorio_columna)).nombre<<endl;
                cout<<"Se coloca aleatoriamente la mina en: Fila "<<aleatorio_fila<<" Columna "<<aleatorio_columna<<endl;
            }else{
                buscar_ficha(pmatriz,'W');
                cout<<"NOMBRE: "<<(*(*(pmatriz+aleatorio_fila)+aleatorio_columna)).nombre<<endl;
                cout<<"Se realiza el movimiento: "<<movimiento_aleatorio<<" Para el grupo armado."<<endl;
                cout<<"Se coloca mina en: Fila "<<*aleatorio_2<<" Columna "<<*(aleatorio_2 + 1)<<endl;
            };
            pulsa_tecla();
            movimiento_aleatorio = rand()%8+1;
            aleatorio_2 = buscar_ficha(aleatorio_2,pmatriz,'W');
            pmatriz = poner_caballo(pmatriz,movimiento_aleatorio,*aleatorio_2,*(aleatorio_2 + 1));
            cont++;
        }while(cont<=9);
        aleatorio_2 = buscar_ficha(aleatorio_2,pmatriz,'W');
        (*(*(pmatriz+*aleatorio_2)+*(aleatorio_2+1))).posicion='B';
        imprimir_tablero(pmatriz,8,8);
        buscar_ficha(pmatriz,'W');
        cout<<"NOMBRE: "<<(*(*(pmatriz+aleatorio_fila)+aleatorio_columna)).nombre<<endl;
        cout<<"Se realiza el movimiento: "<<movimiento_aleatorio<<" Para el grupo armado."<<endl;
        cout<<"Se coloca mina en: Fila "<<*aleatorio_2<<" Columna "<<*(aleatorio_2 + 1)<<endl;
        cout<<"Termina de colocar minas "<<endl;
        pulsa_tecla();
        return pmatriz;
    };

    casilla** poner_caballo(casilla **pmatriz,int v,int k, int l){//Funcion con todos los movimientos posibles de una ficha de caballo en ajedrez, según el parametro v este busca elmovimiento a realizar
                                                     //Si no lo puede hacer salta al siguiente movimiento usando la recursion como metodo de programacion
        int c=0,f=0;
        switch(v){//Cada caso es un movimiento, 8 en total.
            case 1:
                if((0<=(k-2))&&(0<=(l+1))&&(7>=(k-2))&&(7>=(l+1))&&((*(*(pmatriz+(k-2))+(l+1))).posicion==' ')){
                    f=k-2;
                    c=l+1;
                    //cout<<"Entro";
                    (*(*(pmatriz+f)+c)).posicion='W';
                    (*(*(pmatriz+k)+l)).posicion='B';
                }else{
                   pmatriz = poner_caballo(pmatriz,v+1,k,l);
                };
                break;
            case 2:
                if((0<=(k-2))&&(0<=(l-1))&&(7>=(k-2))&&(7>=(l-1))&&((*(*(pmatriz+(k-2))+(l-1))).posicion==' ')){
                    f=k-2;
                    c=l-1;
                    //cout<<"Entro";
                    (*(*(pmatriz+f)+c)).posicion='W';
                    (*(*(pmatriz+k)+l)).posicion='B';
                }else{
                    pmatriz = poner_caballo(pmatriz,v+1,k,l);
                };
                break;
            case 3:
                if((0<=(k+1))&&(0<=(l-2))&&(7>=(k+1))&&(7>=(l-2))&&((*(*(pmatriz+(k+1))+(l-2))).posicion==' ')){
                    f=k+1;
                    c=l-2;
                    //cout<<"Entro";
                    (*(*(pmatriz+f)+c)).posicion='W';
                    (*(*(pmatriz+f)+c)).posicion='B';
                }else{
                    pmatriz = poner_caballo(pmatriz,v+1,k,l);
                };
                break;
            case 4:
                if((0<=(k-1))&&(0<=(l-2))&&(7>=(k-1))&&(7>=(l-2))&&((*(*(pmatriz+(k-1))+(l-2))).posicion==' ')){
                    f=k-1;
                    c=l-2;
                    //cout<<"Entro";
                    (*(*(pmatriz+f)+c)).posicion='W';
                    (*(*(pmatriz+k)+l)).posicion='B';
                }else{
                    pmatriz = poner_caballo(pmatriz,v+1,k,l);
                };
                break;
            case 5:
                if((0<=(k+2))&&(0<=(l+1))&&(7>=(k+2))&&(7>=(l+1))&&((*(*(pmatriz+(k+2))+(l+1))).posicion==' ')){
                    f=k+2;
                    c=l+1;
                    //cout<<"Entro";
                    (*(*(pmatriz+f)+c)).posicion='W';
                    (*(*(pmatriz+f)+c)).posicion='B';
                }else{
                    pmatriz = poner_caballo(pmatriz,v+1,k,l);
                };
                break;
            case 6:
                if((0<=(k+2))&&(0<=(l-1))&&(7>=(k+2))&&(7>=(l-1))&&((*(*(pmatriz+(k+2))+(l-1))).posicion==' ')){
                    f=k+2;
                    c=l-1;
                    //cout<<"Entro";
                    (*(*(pmatriz+f)+c)).posicion='W';
                    (*(*(pmatriz+k)+l)).posicion='B';
                }else{
                    pmatriz = poner_caballo(pmatriz,v+1,k,l);
                };
                break;
            case 7:
                if((0<=(k+1))&&(0<=(l+2))&&(7>=(k+1))&&(7>=(l+2))&&((*(*(pmatriz+(k+1))+(l+2))).posicion==' ')){
                    f=k+1;
                    c=l+2;
                    //cout<<"Entro";
                    (*(*(pmatriz+f)+c)).posicion='W';
                    (*(*(pmatriz+k)+l)).posicion='B';
                }else{
                   pmatriz = poner_caballo(pmatriz,v+1,k,l);
                };
                break;
            case 8:
                if((0<=(k-1))&&(0<=(l+2))&&(7>=(k-1))&&(7>=(l+2))&&((*(*(pmatriz+(k-1))+(l+2))).posicion==' ')){
                    f=k-1;
                    c=l+2;
                    //cout<<"Entro";
                    (*(*(pmatriz+f)+c)).posicion='W';
                    (*(*(pmatriz+k)+l)).posicion='B';
                }else{
                    pmatriz = poner_caballo(pmatriz,1,k,l);
                };
                break;
            };
            return pmatriz;
    };

    casilla** mov_campesino(casilla** pmatriz){//Funcion que selecciona aleatoriamente que campesino mover y en que movimiento
        int camp=0,m=0;
        int* c=new int[2];

        do{
            camp = aleatorio(4)+2;
        }while(buscar_ficha_bool(pmatriz,camp)==false);

        c = buscar_ficha(c,pmatriz,camp);

        m = rand()%8+1;
        pmatriz = poner_campesino(pmatriz,m,camp,*c,*(c+1));
        return pmatriz;
    }

    casilla** crear_antiexplosivos(casilla** pmatriz){
        int k,l;
        bool flag = true;
        int* b=new int[2];//Uso del random
        do{
            b=random(b);
            k=*b;
            l=*(b+1);
            if((*(*(pmatriz+k)+l)).posicion==' '){
                (*(*(pmatriz+k)+l)).posicion='A';
                flag = false;
            };
        }while(flag);
        imprimir_tablero(pmatriz,8,8);
        buscar_ficha(pmatriz,'A');
        cout<<"NOMBRE: "<<(*(*(pmatriz+k)+l)).nombre<<endl;
        cout<<"Crea Anti-Explosivo en fila: "<<k<<" columna: "<<l<<endl;
        pulsa_tecla();//Funcion para que solo reciba la flecha arriba como entrada
        return pmatriz;
    };

    casilla** mov_antiexplosivo(casilla** pmatriz){//Funcion que selecciona aleatoriamente elmovimientodel antiexplosivo

        int m = 0;
        int* c = new int[2];

        c = buscar_ficha(c,pmatriz,'A');

        m = rand()%8+1;

        pmatriz = poner_antiexplosvo(pmatriz,m,*c,*(c+1));

        return pmatriz;
    }

    casilla** poner_antiexplosvo(casilla** pmatriz,int m,int k,int l){//Funcion con todos los movimientos posibles del anti-explosivo, para este caso se mueve como alfil y torre
        int* ci = new int[2];
        int aux_k=0,aux_l=0,elimi=0;
        bool flag = true;
        switch(m){
                case 1://Se mueve como Alfil
                     aux_k=k;
                     aux_l=l;
                    do{
                        if((k-1>=0)&&(l+1<=7)){
                            if(((*(*(pmatriz+(k-1))+(l+1))).posicion==' ')){
                                k--;
                                l++;
                            }
                            else{
                                if(no_hay_mina(pmatriz,k-1,l+1)==0){
                                    pmatriz = elimina_mina(pmatriz,k-1,l+1);
                                    k--;
                                    l++;
                                    flag = false;
                                    elimi=1;
                                }else{
                                    flag = false;
                                    (*(*(pmatriz+k)+l)).posicion='A';
                                };
                            };
                        }
                        else{
                          flag = false;
                          (*(*(pmatriz+k)+l)).posicion='A';
                        };
                       }while(flag);
                       if((aux_k==k)&&(aux_l==l)){
                            pmatriz = poner_antiexplosvo(pmatriz,m+1,k,l);
                       }else{
                           (*(*(pmatriz+(aux_k))+(aux_l))).posicion=' ';
                       };
                        break;
                case 2://Se mueve como Torre
                     aux_k=k;
                     aux_l=l;
                    do{
                        if((k>=0)&&(l+1<=7)){
                            if(((*(*(pmatriz+(k))+(l+1))).posicion==' ')){
                                l++;
                            }
                            else{
                                if(no_hay_mina(pmatriz,k,l+1)==0){
                                    pmatriz = elimina_mina(pmatriz,k,l+1);
                                    l++;
                                    flag = false;
                                    elimi=1;
                                }else{
                                    flag = false;
                                    (*(*(pmatriz+k)+l)).posicion='A';
                                };
                            };
                        }
                        else{
                          flag = false;
                          (*(*(pmatriz+k)+l)).posicion='A';
                        };
                       }while(flag);
                       if((aux_k==k)&&(aux_l==l)){
                            pmatriz = poner_antiexplosvo(pmatriz,m+1,k,l);
                       }else{
                           (*(*(pmatriz+(aux_k))+(aux_l))).posicion=' ';
                       };
                        break;
                case 3://Se mueve como Alfil
                     aux_k=k;
                     aux_l=l;
                    do{
                        if((k+1<=7)&&(l+1<=7)){
                            if(((*(*(pmatriz+(k+1))+(l+1))).posicion==' ')){
                                k++;
                                l++;
                            }
                            else{
                                if(no_hay_mina(pmatriz,k+1,l+1)==0){
                                    pmatriz = elimina_mina(pmatriz,k+1,l+1);
                                    k++;
                                    l++;
                                    flag = false;
                                    elimi=1;
                                }else{
                                    flag = false;
                                    (*(*(pmatriz+k)+l)).posicion='A';
                                };
                            };
                        }
                        else{
                          flag = false;
                          (*(*(pmatriz+k)+l)).posicion='A';
                        };
                       }while(flag);
                       if((aux_k==k)&&(aux_l==l)){
                            pmatriz = poner_antiexplosvo(pmatriz,m+1,k,l);
                       }else{
                           (*(*(pmatriz+(aux_k))+(aux_l))).posicion=' ';
                       };
                       break;
                case 4://Se mueve como Torre
                     aux_k=k;
                     aux_l=l;
                    do{
                        if((k+1<=7)&&(l<=7)){
                            if(((*(*(pmatriz+(k+1))+(l))).posicion==' ')){
                                k++;
                            }
                            else{
                                if(no_hay_mina(pmatriz,k+1,l)==0){
                                    pmatriz = elimina_mina(pmatriz,k+1,l);
                                    flag = false;
                                    k++;
                                    elimi=1;
                                }else{
                                    flag = false;
                                    (*(*(pmatriz+k)+l)).posicion='A';
                                };
                            };
                        }
                        else{
                          flag = false;
                          (*(*(pmatriz+k)+l)).posicion='A';
                        };
                       }while(flag);
                       if((aux_k==k)&&(aux_l==l)){
                            pmatriz = poner_antiexplosvo(pmatriz,m+1,k,l);
                       }else{
                           (*(*(pmatriz+(aux_k))+(aux_l))).posicion=' ';
                       };
                       break;
                case 5://Se mueve como Alfil
                     aux_k=k;
                     aux_l=l;
                    do{
                        if((k+1<=7)&&(l-1>=0)){
                            if(((*(*(pmatriz+(k+1))+(l-1))).posicion==' ')){
                                k++;
                                l--;
                            }
                            else{
                                if(no_hay_mina(pmatriz,k+1,l-1)==0){
                                    pmatriz = elimina_mina(pmatriz,k+1,l-1);
                                    flag = false;
                                    k++;
                                    l--;
                                    elimi=1;
                                }else{
                                    flag = false;
                                    (*(*(pmatriz+k)+l)).posicion='A';
                                };
                            };
                        }
                        else{
                          flag = false;
                          (*(*(pmatriz+k)+l)).posicion='A';
                        };
                       }while(flag);
                       if((aux_k==k)&&(aux_l==l)){
                            pmatriz = poner_antiexplosvo(pmatriz,m+1,k,l);
                       }else{
                           (*(*(pmatriz+(aux_k))+(aux_l))).posicion=' ';
                       };
                       break;
                case 6://Se mueve como Torre
                     aux_k=k;
                     aux_l=l;
                    do{
                        if((k>=0)&&(l-1>=0)){
                            if(((*(*(pmatriz+k)+(l-1))).posicion==' ')){
                                l--;
                            }
                            else{
                                if(no_hay_mina(pmatriz,k,l-1)==0){
                                    pmatriz = elimina_mina(pmatriz,k,l-1);
                                    flag = false;
                                    l--;
                                    elimi=1;
                                }else{
                                    flag = false;
                                    (*(*(pmatriz+k)+l)).posicion='A';
                                };
                            };
                        }
                        else{
                          flag = false;
                          (*(*(pmatriz+k)+l)).posicion='A';
                        };
                       }while(flag);
                       if((aux_k==k)&&(aux_l==l)){
                            pmatriz = poner_antiexplosvo(pmatriz,m+1,k,l);
                       }else{
                           (*(*(pmatriz+(aux_k))+(aux_l))).posicion=' ';
                       };
                       break;

                case 7://Se mueve como Alfil
                     aux_k=k;
                     aux_l=l;
                    do{
                        if((k-1>=0)&&(l-1>=0)){
                            if(((*(*(pmatriz+(k-1))+(l-1))).posicion==' ')){
                                k--;
                                l--;
                            }
                            else{
                                if(no_hay_mina(pmatriz,k-1,l-1)==0){
                                    pmatriz = elimina_mina(pmatriz,k-1,l-1);
                                    k--;
                                    l--;
                                    flag = false;
                                    elimi=1;
                                }else{
                                    flag = false;
                                    (*(*(pmatriz+k)+l)).posicion='A';
                                };
                            };
                        }
                        else{
                          flag = false;
                          (*(*(pmatriz+k)+l)).posicion='A';
                        };
                       }while(flag);
                       if((aux_k==k)&&(aux_l==l)){
                            pmatriz = poner_antiexplosvo(pmatriz,m+1,k,l);
                       }else{
                           (*(*(pmatriz+(aux_k))+(aux_l))).posicion=' ';
                       };
                        break;
                case 8://Se mueve como Torre
                     aux_k=k;
                     aux_l=l;
                    do{
                        if((k-1>=0)&&(l<=7)){
                            if(((*(*(pmatriz+(k-1))+(l))).posicion==' ')){
                                k--;
                            }
                            else{
                                if(no_hay_mina(pmatriz,k-1,l)==0){
                                    pmatriz = elimina_mina(pmatriz,k-1,l);
                                    flag = false;
                                    k--;
                                    elimi=1;
                                }else{
                                    flag = false;
                                    (*(*(pmatriz+k)+l)).posicion='A';
                                };
                            };
                        }
                        else{
                          flag = false;
                          (*(*(pmatriz+k)+l)).posicion='A';
                        };
                       }while(flag);
                       if((aux_k==k)&&(aux_l==l)){
                            pmatriz = poner_antiexplosvo(pmatriz,1,k,l);
                       }else{
                           (*(*(pmatriz+(aux_k))+(aux_l))).posicion=' ';
                       };
                        break;
        }
        if(elimi==1){//Segun si elimino mina o no, imprime el mensaje
            imprimir_tablero(pmatriz,8,8);
            ci = buscar_ficha(ci,pmatriz,'A');
            buscar_ficha(pmatriz,'A');
            cout<<"NOMBRE: "<<(*(*(pmatriz+*ci)+*(ci+1))).nombre<<endl;
            cout<<"Se realiza el movimiento: "<<m<<" Para el Anti-explosivo."<<endl;
            cout<<"Se mueve el Anti-Explosivo a la Fila: "<<*ci<<" Columna: "<<*(ci+1)<<" y elimina Mina"<<endl;
        }else{
            imprimir_tablero(pmatriz,8,8);
            ci = buscar_ficha(ci,pmatriz,'A');
            buscar_ficha(pmatriz,'A');
            cout<<"NOMBRE: "<<(*(*(pmatriz+*ci)+*(ci+1))).nombre<<endl;
            cout<<"Se realiza el movimiento: "<<m<<" Para el Anti-explosivo."<<endl;
            cout<<"Se mueve el Anti-Explosivo a la Fila: "<<*ci<<" Columna: "<<*(ci+1)<<endl;
        };

        return pmatriz;
    };

    casilla** poner_campesino(casilla** pmatriz,int m,char camp,int f,int c){//Funcion con todos los movimientos posibles del campesino, para este caso se mueve como un un rey
        int camp_int=0;
        int muere_camp=0;                                                         //Si no lo puede hacer salta al siguiente movimiento usando la recursion como metodo de programacion
        int* ci = new int[2];
        switch (m){
            case 1:
                if((localiza_campesinos(pmatriz,f-1,c+1)==1)&&((f-1)>=0)&&((f-1)<8)&&((c+1)>=0)&&((c+1)<8)){
                    (*(*(pmatriz+f)+c)).posicion=' ';
                    f = f-1;
                    c = c+1;
                    if(no_hay_mina(pmatriz,f,c)==0){
                        pmatriz = muere_campesino(pmatriz,f,c);
                        muere_camp=1;
                    }else{
                        (*(*(pmatriz+f)+c)).posicion=camp;
                    };
                }else{
                    pmatriz = poner_campesino(pmatriz,m+1,camp,f,c);

                };
                break;
            case 2:
                if((localiza_campesinos(pmatriz,f,c+1)==1)&&((f)>=0&&(f)<8)&&((c+1)>=0)&&((c+1)<8)){
                    (*(*(pmatriz+f)+c)).posicion=' ';
                    f = f;
                    c = c+1;
                    if(no_hay_mina(pmatriz,f,c)==0){
                        pmatriz=muere_campesino(pmatriz,f,c);
                        muere_camp=1;
                    }else{
                        (*(*(pmatriz+f)+c)).posicion=camp;
                    };
                }else{
                    pmatriz = poner_campesino(pmatriz,m+1,camp,f,c);

                };
                break;
            case 3:
                if((localiza_campesinos(pmatriz,f+1,c+1)==1)&&((f+1)>=0)&&((f+1)<8)&&((c+1)>=0)&&((c+1)<8)){
                    (*(*(pmatriz+f)+c)).posicion=' ';
                    f=f+1;
                    c = c+1;
                    if(no_hay_mina(pmatriz,f,c)==0){
                        pmatriz = muere_campesino(pmatriz,f,c);
                        muere_camp=1;
                    }else{
                        (*(*(pmatriz+f)+c)).posicion=camp;
                    };
                }else{
                    pmatriz = poner_campesino(pmatriz,m+1,camp,f,c);

                };
                break;
            case 4:
                if((localiza_campesinos(pmatriz,f+1,c)==1)&&((f+1)>=0)&&((f+1)<8)&&((c)>=0)&&((c)<8)){
                    (*(*(pmatriz+f)+c)).posicion=' ';
                    f = f+1;
                    c = c;
                    if(no_hay_mina(pmatriz,f,c)==0){
                        pmatriz = muere_campesino(pmatriz,f,c);
                        muere_camp=1;
                    }else{
                        (*(*(pmatriz+f)+c)).posicion=camp;
                    };
                }else{
                    pmatriz = poner_campesino(pmatriz,m+1,camp,f,c);

                };
                break;
            case 5:
                if((localiza_campesinos(pmatriz,f+1,c-1)==1)&&((f+1)>=0)&&((f+1)<8)&&((c-1)>=0)&&((c-1)<8)){
                    (*(*(pmatriz+f)+c)).posicion=' ';
                    f = f+1;
                    c = c-1;
                    if(no_hay_mina(pmatriz,f,c)==0){
                        pmatriz = muere_campesino(pmatriz,f,c);
                        muere_camp=1;
                    }else{
                        (*(*(pmatriz+f)+c)).posicion=camp;
                    };
                }else{
                    pmatriz = poner_campesino(pmatriz,m+1,camp,f,c);

                };
                break;
            case 6:
                if((localiza_campesinos(pmatriz,f,c-1)==1)&&((f)>=0)&&((f)<8)&&((c-1)>=0)&&((c-1)<8)){
                    (*(*(pmatriz+f)+c)).posicion=' ';
                    f = f;
                    c = c-1;
                    if(no_hay_mina(pmatriz,f,c)==0){
                        pmatriz = muere_campesino(pmatriz,f,c);
                        muere_camp=1;
                    }else{
                        (*(*(pmatriz+f)+c)).posicion=camp;
                    };
                }else{
                    pmatriz = poner_campesino(pmatriz,m+1,camp,f,c);

                };
                break;
            case 7:
                if((localiza_campesinos(pmatriz,f-1,c-1)==1)&&((f-1)>=0)&&((f-1)<8)&&((c-1)>=0)&&((c-1)<8)){
                    (*(*(pmatriz+f)+c)).posicion=' ';
                    f = f-1;
                    c =c-1;
                    if(no_hay_mina(pmatriz,f,c)==0){
                        pmatriz=muere_campesino(pmatriz,f,c);
                        muere_camp=1;
                    }else{
                        (*(*(pmatriz+f)+c)).posicion=camp;
                    };
                }else{
                    pmatriz = poner_campesino(pmatriz,m+1,camp,f,c);

                };
                break;
            case 8:
                if((localiza_campesinos(pmatriz,f-1,c)==1)&&((f-1)>=0)&&((f-1)<8)&&((c)>=0)&&((c)<8)){
                    (*(*(pmatriz+f)+c)).posicion=' ';
                    f = f-1;
                    c = c;
                    if(no_hay_mina(pmatriz,f,c)==0){
                        pmatriz=muere_campesino(pmatriz,f,c);
                        muere_camp=1;
                    }else{
                        (*(*(pmatriz+f)+c)).posicion=camp;
                    };
                }else{
                    pmatriz = poner_campesino(pmatriz,1,camp,f,c);

                };
                break;
        };
        if(buscar_ficha_bool(pmatriz,camp)){
            camp_int = camp-2;
            imprimir_tablero(pmatriz,8,8);
            ci = buscar_ficha(ci,pmatriz,camp);
            cout<<"El campesino hace el movimiento "<<m<<endl;
            cout<<"Se mueve campesino "<<camp_int<<" "<<camp<<" a la Fila: "<<*ci<<" Columna: "<<*(ci+1)<<endl;
            buscar_ficha(pmatriz,camp);
            cout<<"El Campesino se llama "<<(*(*(pmatriz+*ci)+*(ci+1))).nombre<<endl;

        }else{
            camp_int = camp-2;
            imprimir_tablero(pmatriz,8,8);
            cout<<"El campesino "<<camp_int<<" "<<camp<<"hace el movimiento "<<m<<endl;
            cout<<"¡EL CAMPESINO "<<camp_int<<" "<<camp<<" MUERE PORQUE HABIA UNA MINA!"<<endl;
            cout<<"El Campesino que murio se llamaba "<<buscar_ficha2(camp)<<endl;
        }

        return pmatriz;
    };

    int aleatorio(int n)        //retorna un aleatorio entre 1 y en numero deseado
    {
        srand(time(NULL));
        return 1 + rand() % n;
    }

    bool buscar_ficha_bool(casilla** pmatriz,char b){//funcion quebusca una ficha recibe como parametro l matriz en la cual debe buscar y que caracter, si la encuentra devuelve un valor Bool
        bool flag = false;
        for(int i = 0; i<8;i++){//Recorre lamatriz con un ciclo for
            for(int j = 0; j<8;j++){
                 if((*(*(pmatriz+i)+j)).posicion==b){
                    flag=true;
                 };
            }
        };
        return flag;
    };

    int localiza_campesinos(casilla** pmatriz,int f,int c){//Funcion utilizada por el antiexplosivo y los mismos campesinos para que los movimientos no se sobrepongan
        int p=1;
        if(((f)>=0)&&((f)<8)&&((c)>=0)&&((c)<8)){
            if(((*(*(pmatriz+f)+c)).posicion==3)||((*(*(pmatriz+f)+c)).posicion=='A')||((*(*(pmatriz+f)+c)).posicion==4)||((*(*(pmatriz+f)+c)).posicion==5)||((*(*(pmatriz+f)+c)).posicion==6))
            {
                p=0;
            }else{
                p=1;
            };

        };
        return p;
    };

    int no_hay_mina(casilla** pmatriz,int f,int c){//Funcion que busca s hay mina o no, utilizada por el antiexplosivo para determinar si elimina o no

        int p=1;
        if(((f)>=0)&&((f)<8)&&((c)>=0)&&((c)<8)){
            if(((*(*(pmatriz+f)+c)).posicion=='B')||((*(*(pmatriz+f)+c)).posicion=='W'))
            {
                p=0;
            }else{
                p=1;
            };
        };
        return p;
    };
    casilla** muere_campesino(casilla** pmatriz,int f,int c){//Funcion que elimina un campesino, elimina el caracter de la matriz
        (*(*(pmatriz+f)+c)).posicion=' ';
        return pmatriz;
    };
    casilla** elimina_mina(casilla** pmatriz,int f,int c){//Funcion que elimina un mina, elimina el caracter de la matriz
        (*(*(pmatriz+f)+c)).posicion='A';
        return pmatriz;
    };

    void pulsa_tecla(){//Funcion que espera y solo permite digitar la tecla UP,es llamada cada vez que se va hacer el siguiente movimiento
        char tecla=' ';
        tecla = getch();
       // cout<<"va aqui"<<endl;
        //cout<<tecla<<endl;
        if(tecla!=KEY_UP){

                while(tecla!=KEY_UP){
                    tecla = getch();
                    if(tecla!=KEY_UP){
                        cout<<"Tecla incorrecta, digite UP para continuar: "<<endl;
                    };

                };
        };
        //cout<<tecla<<endl;
        tecla = ' ';
    };

    int exito_NoExito(casilla** pmatriz){//Funcion que determina si el juego tuvo exito o no exito

        int c = 0,m=0;
        int e = 0;
        for(int i=0; i<8;i++){
            for(int j=0;j<8;j++){
                if(((*(*(pmatriz+i)+j)).posicion==3)||((*(*(pmatriz+i)+j)).posicion==4)||((*(*(pmatriz+i)+j)).posicion==5)||((*(*(pmatriz+i)+j)).posicion==6)){
                    c++;
                };
                if(((*(*(pmatriz+i)+j)).posicion=='B')||((*(*(pmatriz+i)+j)).posicion=='W')){
                    m++;
                };
            };
        };
        if((c==3)&&(m==5)){//Exito//retorna un aleatorio entre 1 y en numero deseado si existen tres campessinos y 5 minas
            e=1;
        };
        if((c==4)&&(m<=5)){//Exito//retorna un aleatorio entre 1 y en numero deseado si existen tres campessinos y menos de 5 minas
            e=1;
        };
        if(c==2){//No exito, si han muerto dos campesinos
            e=2;
        };
        return e;
    };
    void buscar_ficha(casilla** pmatriz,char b){//funcion quebusca una ficha recibe como parametro l matriz en la cual debe buscar y que caracter, si la encuentra devuelve un valor Bool




    char *buscar_ficha2(char b){//funcion quebusca una ficha recibe como parametro l matriz en la cual debe buscar y que caracter, si la encuentra devuelve un valor Bool


                    if(b=='W'){
                        return (*pnombres).nombres;
                    };
                    if(b=='A'){
                        return (*(pnombres+1)).nombres;
                    };
                    if(b==3){
                        return (*(pnombres+2)).nombres;
                    };
                    if(b==4){
                        return (*(pnombres+3)).nombres;
                    };
                    if(b==5){
                        return (*(pnombres+4)).nombres;
                    };
                    if(b==6){
                        return (*(pnombres+5)).nombres;
                    };

    };



