#include "matrice3d.h"


/*Matrice3D::Matrice3D(){
    x=1; y=1; z=1; valore=0;
}
*/

Matrice3D::Matrice3D(int x, int y, int z, double d){
    this->x=x;
    this->y=y;
    this->z=z;
    data = new double **[x];
        for (int i=0; i<x; i++){
            data[i]=new double *[y];
            for(int j=0; j<y; j++){
                data[i][j] = new double [z];
                for (int k=0; k<z; k++){
                    data[i][j][k]=d;
                }
            }
        }
}

int Matrice3D::getDimX(){return x;}
int Matrice3D::getDimY(){return y;}
int Matrice3D::getDimZ(){return z;}


double Matrice3D::getValue(int a, int b, int c){

}

Matrice3D* Matrice3D::sommaByPtr(Matrice3D* a,Matrice3D* b){
    Matrice3D *** back = new Matrice3D**[a->getDimX()];
    //inizializzo la nuova matrice 3d
    for (int i=0; i<a->getDimX(); i++){
        back[i] = new Matrice3D *[a->getDimY()];
        for (int j=0; j<a->getDimY();j++){
            back[i][j] = new Matrice3D[a->getDimZ()];
        }
    }
    //sommo i valori scorrendo una matrice

    for (int i=0; i<a->getDimX();i++){
        for (int j=0; j<a->getDimY();j++){
            for(int k=0; k<a->getDimZ();k++){
                // ... get valore contenuto in matrice
            }
        }
    }
}