#include "gfx.h"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>

#define NUMERO_ASTEROIDES 25

using namespace std;
class Poligono{
    private:
        int coordX;//coordenadas del centro del poligono
        int coordY;//coordenadas del centro del poligono
        int radio=10;//radio inicial del poligono
        int lado;//lado del que va a salir el poligono
        float yf[60];//arreglo de vertices en Y
        float xf[60];//arreglo de vertices en X
        int nvertices;//total de vertices del poligono
        int tamano;
        int maxRadio;
        vector<int> radios;
        
    public:
        vector<int> trayectoria();
        void encontrarColision(Poligono[]);
        void ast(int, int, int, int);
        void ast2(int, int);
        int getMaxRadio();
};

int Poligono::getMaxRadio(){
    return maxRadio;
}

void Poligono::ast(int xo, int yo, int ld, int tm){
    int conta=0;
    int i = 0;
    int j = 0;
    int temp = 0;
    float numa=0;
    lado=ld;
    coordX=xo;
    coordY=yo;
    int n = 18;
    radios.reserve(n);
//creacion del asteroide
    xf[conta]=radio*cos(0.01745329252*numa)+coordX;
    yf[conta]=radio*sin(0.01745329252*numa)+coordY;
    conta++;
 while(numa<=340){    
     radio = rand() % 20 + n;
     radios[i] = radio; //Se agrega el radio al vector que tendrá todos los radios de cada asteroide
     xf[conta]=radio*cos(0.01745329252*numa)+coordX;
     yf[conta]=radio*sin(0.01745329252*numa)+coordY;
     gfx_line(xf[conta-1],yf[conta-1],xf[conta],yf[conta]);
     conta++;
     numa=numa+20;
     i++;
 }

 // Se ordenan los radios almacenados en el vector
 for (i = 0; i < n; ++i) {
    for (j = i + 1; j < n; ++j)
    {
        if (radios[i] > radios[j]) 
        {   
            temp =  radios[i];
            radios[i] = radios[j];
            radios[j] = temp;
        }
    }
 }

 // Se asigna el radio mas grande a la variable maxRadio
 maxRadio = radios[n-1];


 gfx_line(xf[0],yf[0],xf[conta-1],yf[conta-1]); //termino de la creación del asteroide
 nvertices=conta-1;
}


void Poligono::ast2(int xo, int yo){
    int conta=0;
    float numa=0;
    int radio2=10;
    int var = rand() % 20;
    //lado=ld;
    coordX=xo;
    coordY=yo;
//creacion del asteroide
    xf[conta]=radio2*cos(0.01745329252*numa)+coordX;
    yf[conta]=radio2*sin(0.01745329252*numa)+coordY;
    conta++;
 while(numa<=340){    
     radio2 = rand() % 5 + 10;
    xf[conta]=radio2*cos(0.01745329252*numa)+coordX;
    yf[conta]=radio2*sin(0.01745329252*numa)+coordY;
     gfx_line(xf[conta-1],yf[conta-1],xf[conta],yf[conta]);
     conta++;
     numa=numa+10;
     gfx_flush();
 }
 gfx_line(xf[0],yf[0],xf[conta-1],yf[conta-1]); //termino de la creación del asteroide
 nvertices=conta-1;
}


/*
 Regresa las coordenadas de un asteroide cada que cambia de posicion
*/
vector<int> Poligono::trayectoria(){
    vector <int> parCoordenadas(3); //Vector que almacena las coordenadas y el radio mayor de un asteroide
    int aux1=0, aux2=0, num1=0,num2=0, h=0;
    if (lado==0){
        num1 = rand() % 2;
        num2 = rand() % 3-1;
        for(h=0; h<=nvertices; h++){
            xf[h]= xf[h] + num1;
            yf[h]= yf[h] + num2;
            coordX=coordX+num1;
            coordY=coordY+num2;
        }
        for(h=1;h<=nvertices;h++)
            gfx_line(xf[h-1],yf[h-1],xf[h],yf[h]);
        gfx_line(xf[0],yf[0],xf[h-1],yf[h-1]);
        usleep(4166);
    }else if(lado==1){
        num1 = rand() % 3-1;
        num2 = rand() % 2;
        xf[h]= xf[h] + num1;
        yf[h]= yf[h] + num2;
        for(h=1; h<=nvertices; h++){
            xf[h]= xf[h] + num1;
            yf[h]= yf[h] + num2;
            coordX=coordX+num1;
            coordY=coordY+num2;            
        }
        for(h=1;h<=nvertices;h++)
            gfx_line(xf[h-1],yf[h-1],xf[h],yf[h]);
        gfx_line(xf[0],yf[0],xf[h-1],yf[h-1]);
        usleep(4166);
    }else if(lado==2){
        num1 = rand() % 3-2;
        num2 = rand() % 3-1;
        xf[h]= xf[h] + num1;
        yf[h]= yf[h] + num2;
        for(h=1; h<=nvertices; h++){
            xf[h]= xf[h] + num1;
            yf[h]= yf[h] + num2;
            coordX=coordX+num1;
            coordY=coordY+num2;
        }
        for(h=1;h<=nvertices;h++)
            gfx_line(xf[h-1],yf[h-1],xf[h],yf[h]);
        gfx_line(xf[0],yf[0],xf[h-1],yf[h-1]);
        usleep(4166);
    }else if(lado==3){
        num1 = rand() % 3-1;
        num2 = rand() % 3-2;
        xf[h]= xf[h] + num1;
        yf[h]= yf[h] + num2;
        for(h=1; h<=nvertices; h++){
            xf[h]= xf[h] + num1;
            yf[h]= yf[h] + num2;
            coordX=coordX+num1;
            coordY=coordY+num2;
        }
        for(h=1;h<=nvertices;h++)
            gfx_line(xf[h-1],yf[h-1],xf[h],yf[h]);
        gfx_line(xf[0],yf[0],xf[h-1],yf[h-1]);
        usleep(4166);
    }

    parCoordenadas[0] = coordX;
    parCoordenadas[1] = coordY;
    parCoordenadas[2] = maxRadio;

    return parCoordenadas;
}

void Poligono::encontrarColision(Poligono a[]){
    int cont = 0;
    vector<int> coordenadasAsteroide(3);
    vector<vector<int> > vectorCoordenadas(NUMERO_ASTEROIDES); // Vector de vectores de coordenadas

    vectorCoordenadas.reserve(NUMERO_ASTEROIDES);

    for(cont=0; cont<NUMERO_ASTEROIDES; cont++){
        coordenadasAsteroide = a[cont].trayectoria();
        vectorCoordenadas[cont] = coordenadasAsteroide;
        //cout << "\nCoordenadas asteroide" << coordenadasAsteroide[0] << ", "<< coordenadasAsteroide[1] <<endl;
        //cout << "Vector coordenadas" << vectorCoordenadas[cont][0] << ", "<< vectorCoordenadas[cont][1] <<endl;
    }
}

int main(){
    int num, tam, coorX, coorY;
    Poligono a[NUMERO_ASTEROIDES];
    int cont=0;
    //char c;
    srand(time(NULL));
    gfx_open(700, 700, "Asteroides");
    gfx_color(0,250,0);
    coorY=rand()%601;

    while(cont<NUMERO_ASTEROIDES){
        num = rand() % 4;//elegir de que lado saldra el poligono
        //Determinar de que lado va a salir y en que punto saldra el poligono
        if(num==0){
        coorX=0;
        coorY=rand()%601;
        }else if(num==1){
            coorX=rand()%801;
            coorY=0;
        }else if(num==2){
            coorX=800;
            coorY=rand()%601;
        }else if(num==3){
            coorX=rand()%801;
            coorY=600;
        }
        tam = 1 + rand() % (6 - 1);
        a[cont].ast(coorX,coorY,num,tam);
        cont++;
    }

    while(1){
        a[cont].encontrarColision(a);
        gfx_flush();
        gfx_clear();
    }
    return 0;
}
