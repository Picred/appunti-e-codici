#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <cmath>
#include <cctype>

#define DIM 50
using namespace std;

class A{
    private:
        char* base;
        short len;
    
    public:
        A(short m){
            this->len=m;
            base=new char[len];

                for(int i=0; i<len; i++){
                    base[i]=rand()%('z' - 'a' + 1) + 'a';
                }
        }

        virtual string extract(short x)=0;

        short getLen() {
            return len;
        }

        virtual ostream& put(ostream& os){
            os << ": base=[";
                for(int i=0; i<getLen(); i++){
                    os << base[i] << " ";
                }
            os << "], ";
            return os; 
        }

        protected:
            char get(short i){
                return base[i%len];
            }


};


class B: public A{
    private:
        string str;
        double k;
    
    public:
        B(short m, double p) : A(m){
            for(int i=0; i<getLen(); i++){
                switch(toupper(A::get(i))){
                    case 'A':
                    case 'E':
                    case 'I':
                    case 'O':
                    case 'U':
                        str+=A::get(i);                    
                }
            }
            this->k=p;
        }

        double foo(short s){
            return (sin(k+s))/(log(s+1));
        }

        string extract(short x){
            string out="";
                for(int i=0; i<x; i++)
                    out+= get(rand()%(A::getLen())); // [0,getlen-1]
            return out;
        }

        ostream& put(ostream& os){
            A::put(os);

            os << "str= " << str << ", k=" << k << ", extract(3)=" << extract(3);
            return os;
        }
};

class C: public A{
    private:
        int y;
    
    public:
        C(short n, int k) : A(n){
            this->y = k;
        }

        string extract(short x){
            string out="";
            int counter=0;
            for(int i=0; i<x || counter<x ; i++){
                switch(toupper(A::get(i))){
                    case 'A':
                    case 'E':
                    case 'I':
                    case 'O':
                    case 'U':
                        break;
                    default:
                        out+=A::get(i);
                        counter++;
                }
            }
            return out;
        }
        
        double g(short w){
            return (sin(w+y));
        }

        ostream& put(ostream& os){
            A::put(os);

            os << "y= " << y << ", extract(3)=" << extract(3);
            return os;
        }

        // (*ptr):C: base=[r k m p l z x i x q i r d e j o ], y=4
        C operator++(int a){
            C aux= *this;
            y++;
            return aux;
        }
        
};


ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}


int main(){
    srand(111222333);
    A *vett[DIM];

    for (int i = 0; i < DIM; i++){
        short n = 10 + rand() % 10;
        switch (rand() % 2)
        {
        case 0:
            vett[i] = new C(n, rand() % 20 + 1);
            break;
        case 1:
            vett[i] = new B(n, rand() / (double)RAND_MAX);
            break;
        }
    }

    cout << "PUNTO 1" << endl;

    for (int i = 0; i < DIM; i++){
        cout << i << ")" <<( typeid(*vett[i])==typeid(B) ? "B" : "C")  << *vett[i] << endl; 
    }

    cout << endl << "PUNTO 2" << endl;
        //si calcoli una singola media di tutti i valori foo(5) e g(5) per tutti i gli oggetti di tipo B e C.
        double media=0.0;
        for (int i = 0; i < DIM; i++){
            if(typeid(*vett[i]) == typeid(B)){
                media+= ((B*)(vett[i]))-> foo(5);
            } else{
                 media+= ((C*)(vett[i]))-> g(5);
            }
        }
        media/=DIM;
        cout << "avg(g() + foo())=" << media;

    cout << endl << "PUNTO 3" << endl;
    //si implementi l’overloading dello operatore membro postfisso “++” per la classe C e lo si utilizzi nel
    //  main.
    C* auxx=nullptr;
    for(int i=0; i<DIM && auxx==nullptr;i++){
        if(typeid(*vett[i]) == typeid(C)){
            cout << "(*ptr)++: C: " << *vett[i] << endl;
            auxx= ((C*)vett[i]);
            (*auxx)++;
            cout << "(*ptr): C: " << *vett[i] << endl;
            // (*ptr)++: C: base=[r k m p l z x i x q i r d e j o ], y=3
            // (*ptr):C: base=[r k m p l z x i x q i r d e j o ], y=4
        }
    }

    return 0;

}

/*
PUNTO 1
0)C: base=[r k m p l z x i x q i r d e j o ], y=3, extract(3)=rkm
1)C: base=[i e t p t c g c w r n l e ], y=9, extract(3)=tpt
2)C: base=[s n b w m x e a l y b g x e f q k h j ], y=10, extract(3)=snb
3)B: base=[h m k j x n s j l w x m s s t n c l ], str=, k=0.140873, extract(3)=mmn
4)B: base=[y m v v g c g d u u h o ], str=uuo, k=0.79461, extract(3)=vuy
5)B: base=[h i e i d h d b a g c f b i ], str=ieiai, k=0.778069, extract(3)=ieb
6)B: base=[x d t r o f v i g n v a j ], str=oia, k=0.714133, extract(3)=fod
7)C: base=[s w i b x r x q m h x w h x h r z x ], y=15, extract(3)=swb
8)B: base=[a r m m u v e v x j c y i k e m ], str=aueie, k=0.877194, extract(3)=rum
9)B: base=[m m j w a m b r g y j i m k z p o ], str=aio, k=0.00759911, extract(3)=azg
10)C: base=[k q b y b j m z u t ], y=10, extract(3)=kqb
11)B: base=[g s x j o o g v c h f ], str=oo, k=0.487869, extract(3)=vof
12)C: base=[g g l r u q p p d j k d k n k q w i ], y=5, extract(3)=ggl
13)B: base=[a l n v a q y g i x z ], str=aai, k=0.0409864, extract(3)=vnv
14)C: base=[j t l c e v n v b z ], y=14, extract(3)=jtl
15)C: base=[z s l h t m g h p w q h o q s f e k f ], y=9, extract(3)=zsl
16)C: base=[z b i r w n j h x g h a v k m w w j o ], y=15, extract(3)=zbr
17)B: base=[e x s h i o v g g x o ], str=eioo, k=0.00915555, extract(3)=egh
18)B: base=[s s d f l q v s v t ], str=, k=0.47618, extract(3)=qqq
19)C: base=[w a c j w w x r w y h f z a d e k ], y=20, extract(3)=wcj
20)B: base=[h n c j d j b k v s f x t k z q f c j ], str=, k=0.815302, extract(3)=dcx
21)B: base=[j o j y x o i f d z x g n ], str=ooi, k=0.72689, extract(3)=yjj
22)C: base=[b v z o r w f p r x c b j u ], y=10, extract(3)=bvz
23)B: base=[d g j f h b q p t s ], str=, k=0.693594, extract(3)=ssq
24)C: base=[u l p h m z e u r c e q i m w ], y=11, extract(3)=lph
25)C: base=[k c h g v z w s x b r ], y=4, extract(3)=kch
26)B: base=[s v k e u k k g d t ], str=eu, k=0.886471, extract(3)=gkk
27)B: base=[w o w a c q d t h r s ], str=oa, k=0.964202, extract(3)=wct
28)B: base=[k d s s p i j e n o c b d q ], str=ieo, k=0.294687, extract(3)=qpq
29)C: base=[f s a b r j p g j p v p g g c g ], y=8, extract(3)=fsb
30)C: base=[t x t p x a n b p t d o s n e m w ], y=18, extract(3)=txt
31)C: base=[r o d e x v q q f d k l ], y=7, extract(3)=rdx
32)C: base=[a y j a b y h g x c j c v ], y=14, extract(3)=yjb
33)C: base=[u f n z p j t f b y j ], y=17, extract(3)=fnz
34)C: base=[a t r s f h n n f v r s x ], y=8, extract(3)=trs
35)B: base=[i m l j j o k r j u o r f s b c w ], str=iouo, k=0.362896, extract(3)=ilf
36)B: base=[d v k g c a k o y u p v a k y l ], str=aoua, k=0.956084, extract(3)=ukg
37)C: base=[r x g s m t p g z p n k a g h f ], y=7, extract(3)=rxg
38)B: base=[w v u h x y r x j l r e b ], str=ue, k=0.249794, extract(3)=yxv
39)B: base=[b u w m m c e b p m o d i x k u o v w ], str=ueoiuo, k=0.938414, extract(3)=kow
40)B: base=[q o w x l b n v k k u ], str=ou, k=0.522782, extract(3)=nwb
41)C: base=[j l w c w v g m h i i h ], y=7, extract(3)=jlw
42)C: base=[t h v w a l g b j w m ], y=10, extract(3)=thv
43)C: base=[m o o u w m q t e c l d r h u z n b d ], y=9, extract(3)=mwm
44)C: base=[v e p u f f z w p n y q x f n ], y=7, extract(3)=vpf
45)C: base=[y l u n y h t d y x o k r p ], y=11, extract(3)=yln
46)B: base=[r c m v a n s c m n l a b ], str=aa, k=0.89285, extract(3)=lcv
47)B: base=[d i f d v j h s x p v e a p i ], str=ieai, k=0.615467, extract(3)=pav
48)B: base=[s h d p r q a p q f s k n ], str=a, k=0.0867946, extract(3)=ark
49)B: base=[e t a t h j a m a y j w s w o ], str=eaaao, k=0.620136, extract(3)=sth

 PUNTO 2
avg(g() + foo())=-0.0616427

 PUNTO 3
(*ptr)++: C: base=[r k m p l z x i x q i r d e j o ], y=3
(*ptr):C: base=[r k m p l z x i x q i r d e j o ], y=4
*/