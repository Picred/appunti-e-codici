#include <iostream>
#include <fstream>
using namespace std;


template <class H>
class NodoA{
    protected:
        H elemento;
        NodoA<H>* padre;
        NodoA<H>* sx;
        NodoA<H>* dx;
    public:
        NodoA(H el): elemento(el){
            this->padre = NULL;
            this->dx = NULL;
            this->sx = NULL;
        }

        //Get
        H getElemento(){return elemento;}
        NodoA<H>* getPadre(){return padre;}
        NodoA<H>* getDx(){return dx;}
        NodoA<H>* getSx(){return sx;}

        //Set
        void setPadre(NodoA<H>* padre){this->padre = padre;}
        void setSx(NodoA<H>* sx){this->sx = sx;}
        void setDx(NodoA<H>* dx){this->dx = dx;}
};

template <class H>
class Albero{
    protected:
        NodoA<H>* radice;
        void Trapianta(NodoA<H>*, NodoA<H>*);   //OK
        NodoA<H>* Minimo(NodoA<H>*);    //OK
        void Preorder(NodoA<H>*, ofstream&);    //OK
    public:
        Albero(){this->radice = NULL;}  //OK

        void ins(H);    //OK
        void canc(H);   //OK
        NodoA<H>* search(H);    //OK
        void print(ofstream&);  //OK
        int _getK(NodoA<H>* ptr);
        int getK();
};

template <class H> void Albero<H>::ins(H x){
    NodoA<H>* nuovo = new NodoA<H>(x);

    if(radice == NULL)
        radice = nuovo;
    else{
        NodoA<H>* iter = radice;
        NodoA<H>* tmp = NULL;

        while(iter != NULL){
            tmp = iter;
            if(x > iter->getElemento())
                iter = iter->getDx();
            else
                iter = iter->getSx();
        }

        nuovo->setPadre(tmp);
        if(x > tmp->getElemento())
            tmp->setDx(nuovo);
        else
            tmp->setSx(nuovo);
    }
}

template <class H> int Albero<H>::_getK(NodoA<H>* ptr){
    if(ptr == NULL)
        return 0;
    else{
        int dimensionesx = _getK(ptr->getSx());
        int dimensionedx = _getK(ptr->getDx());
        return dimensionesx + dimensionedx + 1;
    }
}

template <class H> int Albero<H>::getK(){
    return _getK(radice);
}

template <class H> void Albero<H>::Trapianta(NodoA<H>* u, NodoA<H>* v){
    if(u->getPadre() == NULL)
        radice = v;
    else if(u == u->getPadre()->getDx())
        u->getPadre()->setDx(v);
    else
        u->getPadre()->setSx(v);
    
    if(v != NULL)
        v->setPadre(u->getPadre());
}

template <class H> NodoA<H>* Albero<H>::Minimo(NodoA<H>* ptr){
    NodoA<H>* iter = ptr;

    while(iter->getSx() != NULL)
        iter = iter->getSx();
    return iter;
}

template <class H> NodoA<H>* Albero<H>::search(H x){
    NodoA<H>* iter = radice;

    while(iter != NULL && iter->getElemento() != x){
        if(x > iter->getElemento())
            iter = iter->getDx();
        else
            iter = iter->getSx();
    }
    return iter;
}

template <class H> void Albero<H>::canc(H x){
    NodoA<H>* ptr = search(x);
    if(ptr != NULL){
        if(ptr->getDx() == NULL)
            Trapianta(ptr, ptr->getSx());
        else if(ptr->getSx() == NULL)
            Trapianta(ptr, ptr->getDx());
        else{
            NodoA<H>* y = Minimo(ptr->getDx());
            if(y->getPadre() != ptr){
                Trapianta(y, y->getDx());
                y->setDx(ptr->getDx());
                y->getDx()->setPadre(y);
            }
            Trapianta(ptr, y);
            y->setSx(ptr->getSx());
            y->getSx()->setPadre(y);
        }
    }
}

template <class H> void Albero<H>::Preorder(NodoA<H>* ptr, ofstream &out){
    if(ptr != NULL){
        out << ptr->getElemento() << " ";
        Preorder(ptr->getSx(), out);
        Preorder(ptr->getDx(), out);
    }
}

template <class H> void Albero<H>::print(ofstream &out){
    Preorder(radice, out);
}

template <class H>
class Nodo{
    protected:
        Albero<H>* albero;
        Nodo<H>* succ;
    public:
        Nodo(){
            this->succ = NULL;
            albero = new Albero<H>();
        }

        //Get
        Albero<H>* getAlbero(){return albero;}
        Nodo<H>* getSucc(){return succ;}

        //Set
        void setSucc(Nodo<H>* succ){this->succ = succ;}
};

template <class H>
class Lista{
    protected:
        Nodo<H>* testa;
        int k;
    public:
        Lista(int k){
            this->k = k;
            this->testa = NULL;
        }

        void ins(H);    //OK
        void canc(H);
        void print(ofstream&);
};

template <class H> void Lista<H>::ins(H x){
    if(testa == NULL){
        Nodo<H>* nuovo = new Nodo<H>();
        testa = nuovo;
    }
    else if(testa->getAlbero()->getK() == k){
        Nodo<H>* nuovo = new Nodo<H>();
        nuovo->setSucc(testa);
        testa = nuovo;
    }
       
    testa->getAlbero()->ins(x);
}

template <class H> void Lista<H>::print(ofstream &out){
    Nodo<H>* iter = testa;
    
    while(iter != NULL){
        iter->getAlbero()->print(out);

        iter = iter->getSucc();
    }
}

template <class H> void Lista<H>::canc(H x){
    Nodo<H>* iter = testa;

    while(iter != NULL){
        iter->getAlbero()->canc(x);
        iter = iter->getSucc();
    }

    if(testa->getAlbero()->getK() <= 0){
        //Nodo<H>* tmp = testa;
        testa = testa->getSucc();
        //delete tmp;
    }

    if(testa != NULL){
        iter = testa->getSucc();
        Nodo<H>* tmp = testa;
        while(iter != NULL){
            if(iter->getAlbero()->getK() <= 0){
                tmp->setSucc(iter->getSucc());
                delete iter;
                iter = tmp;
            }

            tmp = iter;
            iter = iter->getSucc();
        }
    }
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    for(int i = 0; i < 100; i++){
        string type; in >> type;
        int k; in >> k; 

        if(type == "int"){
            bool finito = 0;
            string op;
            Lista<int>* t = new Lista<int>(k);
            while(!finito){
                in >> op;
                if(op == "#")
                    finito = 1;
                else{
                    int val; in >> val;
                    if(op == "ins")
                        t->ins(val);
                    else
                        t->canc(val);
                }
            }
            t->print(out);
            out << endl;
        }
        else if(type == "double"){
            bool finito = 0;
            string op;
            Lista<double>* t = new Lista<double>(k);
            while(!finito){
                in >> op;
                if(op == "#")
                    finito = 1;
                else{
                    double val; in >> val;
                    if(op == "ins")
                        t->ins(val);
                    else
                        t->canc(val);
                }
            }
            t->print(out);
            out << endl;
        }
    }
}