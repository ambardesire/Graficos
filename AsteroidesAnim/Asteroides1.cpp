#include "gfx.h"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>
//#define NUMERO_ASTEROIDES 25
#define RADS_CONST 0.01745329252

using namespace std;
class Asteroide{
    private:
        int CoordX; //coordenadas del centro del poligono
        int CoordY; //coordenadas del centro del poligono
        int rad=10; //radio inicial del poligono
        int Cuadr; //Cuadrante del que va a salir el poligono
	float ArrY[60]; //arreglo de vertices en eje Y
        float ArrX[60]; //arreglo de vertices en eje X
        int Vert; //total de vertices del poligono
        int Tam;
        int maxRad;
        vector<int> Radios;
        
    public:
        vector<int> Tray(); //Trayectoria del vector
        void ImpAst(Asteroide[]);
        void Ast(int, int, int, int);
        void Ast2(int, int);
        int getMaxRad();
        int Cantidad=0;
};

int Asteroide::getMaxRad(){
    return maxRad;
}

void Asteroide::Ast(int Xo, int Yo, int lado, int tm){
    int i = 0, j = 0;
    int Cont = 0, Temp = 0;
    int n = 18;
    float Num=0;
    Cuadr = lado;
    CoordX = Xo;   CoordY = Yo;
    
        Radios.reserve(n);
        
//creacion del asteroide
        ArrX[Cont]=rad*cos(RADS_CONST*Num)+CoordX;
        ArrY[Cont]=rad*sin(RADS_CONST*Num)+CoordY;
        
        Cont++;
        
        while(Num<=340){    
            rad = rand() % 25 + n; 
            Radios[i] = rad; //Se añade el radio generado al vector que almacena todos los radios
            ArrX[Cont]=rad*cos(RADS_CONST*Num)+CoordX;
            ArrY[Cont]=rad*sin(RADS_CONST*Num)+CoordY;
                gfx_line(ArrX[Cont-1], ArrY[Cont-1], ArrX[Cont], ArrY[Cont]);
            Cont++;
            Num = Num+20;
            i++;
        }
 //Ordenamiento de los radios almacenados en Radios[]
        for (i=0; i<n; ++i){
            for (j=i+1; j<n; ++j){
               if (Radios[i] > Radios[j]){   
                   Temp =  Radios[i];
                   Radios[i] = Radios[j];
                   Radios[j] = Temp;
               }
           }
        }
 
    maxRad = Radios[n-1]; // Se asigna el  valor de radio mas grande a maxRad

    gfx_line(ArrX[0], ArrY[0], ArrX[Cont-1], ArrY[Cont-1]); //Termina la creacion de los asteroides
        Vert = Cont-1;
}

void Asteroide::Ast2(int Xo, int Yo){
    int Cont = 0, Rad2 = 10;
    float Num = 0;
    CoordX = Xo;
    CoordY = Yo;
	
	//creacion del asteroide
        ArrX[Cont]=Rad2*cos(RADS_CONST*Num)+CoordX;
        ArrY[Cont]=Rad2*sin(RADS_CONST*Num)+CoordY;
        Cont++;
        
        while(Num<=340){    
            Rad2 = rand() % 5 + 10;
            ArrX[Cont]=Rad2*cos(RADS_CONST*Num)+CoordX;
            ArrY[Cont]=Rad2*sin(RADS_CONST*Num)+CoordY;
                gfx_line(ArrX[Cont-1], ArrY[Cont-1], ArrX[Cont], ArrY[Cont]);
            Cont++;
            Num = Num+10;
                gfx_flush();
        }
       
        gfx_line(ArrX[0], ArrY[0], ArrX[Cont-1], ArrY[Cont-1]); //Termina 
        Vert = Cont-1;
}

// Actualiza las coordenadas del asteroide generando una trayectoria
vector<int> Asteroide::Tray(){
    
    vector <int> Coordenadas(3);    //Vector que almacena las coordenadas y el maxRad de un ast
    int Num1 = 0 , Num2 = 0;
    int k = 0;
    
    if (Cuadr==0){
        Num1 = rand() % 2;
        Num2 = rand() % 3-1;
        for(k=0; k<=Vert; k++){
            ArrX[k] = ArrX[k] + Num1;
            ArrY[k] = ArrY[k] + Num2;
            CoordX = CoordX+Num1;
            CoordY = CoordY+Num2;
        }
        for(k=1; k<=Vert; k++)
            gfx_line(ArrX[k-1], ArrY[k-1], ArrX[k], ArrY[k]); 
        
        gfx_line(ArrX[0], ArrY[0], ArrX[k-1], ArrY[k-1]);
        usleep(4166);
    }
    else if(Cuadr==1){
            Num1 = rand() % 3-1;
            Num2 = rand() % 2;
            ArrX[k] = ArrX[k] + Num1;
            ArrY[k] = ArrY[k] + Num2;
            
            for(k=1; k<=Vert; k++){
                ArrX[k] = ArrX[k] + Num1;
                ArrY[k] = ArrY[k] + Num2;
                CoordX = CoordX+Num1;
                CoordY = CoordY+Num2;            
            }
            for(k=1; k<=Vert; k++)
                gfx_line(ArrX[k-1], ArrY[k-1], ArrX[k], ArrY[k]);
            
            gfx_line(ArrX[0], ArrY[0], ArrX[k-1], ArrY[k-1]);
            usleep(4166);
    }
        else if(Cuadr==2){
            Num1 = rand() % 3-2;
            Num2 = rand() % 3-1;
            ArrX[k]= ArrX[k] + Num1;
            ArrY[k]= ArrY[k] + Num2;
            
            for(k=1; k<=Vert; k++){
                ArrX[k] = ArrX[k] + Num1;
                ArrY[k] = ArrY[k] + Num2;
                CoordX = CoordX+Num1;
                CoordY = CoordY+Num2;
            }
            for(k=1; k<=Vert; k++)
                gfx_line(ArrX[k-1], ArrY[k-1], ArrX[k], ArrY[k]);
            
            gfx_line(ArrX[0], ArrY[0], ArrX[k-1], ArrY[k-1]);
            usleep(4166);
        }
                else if(Cuadr==3){
                    Num1 = rand() % 3-1;
                    Num2 = rand() % 3-2;
                    ArrX[k] = ArrX[k] + Num1;
                    ArrY[k] = ArrY[k] + Num2;

                    for(k=1; k<=Vert; k++){
                        ArrX[k] = ArrX[k] + Num1;
                        ArrY[k] = ArrY[k] + Num2;
                        CoordX = CoordX+Num1;
                        CoordY = CoordY+Num2;
                    }
                    for(k=1; k<=Vert; k++)
                        gfx_line(ArrX[k-1], ArrY[k-1], ArrX[k], ArrY[k]);

                    gfx_line(ArrX[0], ArrY[0], ArrX[k-1], ArrY[k-1]);
                    usleep(4166);
                }

    Coordenadas[0] = CoordX;
    Coordenadas[1] = CoordY;
    Coordenadas[2] = maxRad;

    return Coordenadas;
}

void Asteroide::ImpAst(Asteroide a[]){
    int Cont = 0;
    vector<int> CoordAst(3);
    vector<vector<int> > CoordVector(Cantidad); // Vector de vectores de coordenadas

        CoordVector.reserve(Cantidad);

        for(Cont=0; Cont<Cantidad; Cont++){
            CoordAst = a[Cont].Tray();
            CoordVector[Cont] = CoordAst;
            //cout << "\nCoordenadas del asteroide" << CoordAst ", "<< CoordAst[1] <<endl;
            //cout << "Vector de coordenadas" << CoordVector[cont][0] << ", "<< CoordVector[cont][1] <<endl;
        }
}

int main(){
	int Num, Tam, CoorX, CoorY,Cantidad;
	cout << "Inserte el numero de asteroides que deberán aparecer" << endl;
	cin >> Cantidad;
	Asteroide a[Cantidad]; //Aparece 6 veces
	int Cont=0; 
    srand(time("NULL"));
    gfx_open(700, 700, "Asteroides");
    gfx_color(0, 250, 0);
    CoorY = rand()%601;
    
    while(Cont<Cantidad){
        Num = rand() % 4; //Elegir al azar el cuadrante del que saldra el poligono
        //Determinar cuadrante y punto por donde saldra el poligono
        if(Num==0){
            CoorX = 0;
            CoorY = rand()%601;
        }
        else if(Num==1){
            CoorX = rand()%801;
            CoorY = 0;
            }
                else if(Num==2){
                    CoorX = 800;
                    CoorY = rand()%601;
                }
                    else if(Num==3){
                        CoorX = rand()%801;
                        CoorY = 600;
                    }
        
        Tam = 1 + rand() % (6 - 1);
        a[Cont].Ast(CoorX, CoorY, Num, Tam);
        Cont++;
    }

    while(1){
        a[Cont].ImpAst(a);
        gfx_flush();
        gfx_clear();
    }
    return 0;
}
