#ifndef MATRICE3D_H
#define MATRICE3D_H

class Matrice3D{
    private:
        int x;
        int y;
        int z;
        double*** data;
    public:
        //Matrice3D();
        Matrice3D(int,int,int,double);
        int getDimX();
        int getDimY();
        int getDimZ();

        Matrice3D* sommaByPtr(Matrice3D*,Matrice3D*);
        Matrice3D& sommaByReference(Matrice3D&,Matrice3D&);
        double& getElement(int,int,int);
        double getValue(int,int,int);
};

#endif