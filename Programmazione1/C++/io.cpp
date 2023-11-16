#include <cmath>
#include <string>
#include <typeinfo>
#include <cstdlib>
#include <iostream>
#define DIM 50

using namespace std;
class A{
    private:
        char *str; //
        short len; // 

    public: //
        // A(short m, string source){
        //     this->len=m; 
        //     this->str= new char [len];
        //     int index=0; //
            
        //     for(int i=0; i<source.length() && index<len; i++){

        //         if(source[i]=='A' || source[i]=='a' || source[i]=='E' || source[i]=='e' || source[i]=='I' || source[i]=='i' || source[i]=='O' || source[i]=='o' || source[i]=='U' || source[i]=='u'){
        //             str[index]= source[i];
        //             index++; 
        //         }
        //     }

        //     for(int i=0; i<source.length() && index<len; i++){
        //         if(source[i]!='A' || source[i]!='a' || source[i]!='E' || source[i]!='e' || source[i]!='I' || source[i]!='i' || source[i]!='O' || source[i]!='o' || source[i]!='U' || source[i]!='u'){
                    
        //             str[index]= source[i];
        //             index++; 
        //         }
        //     }

        // }
/*
Inizializza str con
la stringa formata da
tutte le vocali e a seguire 
tutte le consonanti contenute 
in source, nell’ordine in 
cui si trovano,
nel limite massimo
rappresentato dal valore m. 
Pone m in len.
*/
        A(short m, string source) {
            len=m;
            str=new char[len];
            int index=0;
            for(int i=0; i<source.length(); i++){
                switch(toupper(source[i])){
                    case 'A':
                        str[index]=source[i];
                        index++;
                        break;
                    case 'E':
                        str[index]=source[i];
                        index++;
                        break;
                    case 'I':
                        str[index]=source[i];
                        index++;
                        break;
                    case 'O':
                        str[index]=source[i];
                        index++;
                        break;
                    case 'U':
                        str[index]=source[i];
                        index++;
                        break;
                }
                if (index>m){
                    break;
                }
            }

            for(int i=0; i<source.length(); i++){
                switch(toupper(source[i])){
                    case 'A':
                    case 'E':
                    case 'I':
                    case 'O':
                    case 'U':
                        break;
                    default:
                        str[index]=source[i];
                        index++;
                        break;
                }
                if (index>m){
                    break;
                }
            }

        }

        short getLen(){ return len;}; 

        virtual string func(short k)=0; 

       // 0)1B, str = eiieocrkmplzxxqr , q=14, func(3)=qxx
        virtual ostream& put(ostream& os){
            os<<typeid(*this).name()<<", str = ";
            for(int i=0; i<len; i++){
                os<<str[i];
            } 
            os<<" , ";

            return os; //va nell'overloading dell'operatore <<
        }

    protected:
        char get(short i){
            return str[i%len]; //
        }
};

class B: public A{
  private:
    short q; 
  public:

    B(short m, string source):A(m, source){
        this->q= 1 + rand() % getLen();
    }

    string func(short k){
        //restituisce la sottostringa
        string inversa="";
        for(int i=getLen()-1; i>=k; i--){
            inversa[i]+=get(i); //
        }
        return inversa;
    }

    // 0)1B, str = eiieocrkmplzxxqr , q=14, func(3)=qxx
    ostream& put(ostream& os){
        A::put(os); 
        os<<"q="<<this->q<<", func(3)="<< func(3); 
        return os; 
    }

};

class C: public A{
    private:
        char y;
    public:
        C(short n, string source, char y):A(n, source){
            this ->y=y;
        }

        string func(short k){
            string invers="";
            for(int i=getLen()-1; i>=k; i--){
                invers+=get(i);
            }

            return invers; //
        }

        string g(char c){
            string s = "";
            for(int i = 0; i < getLen(); i++) s+= get(i);
            string nuova= y+s+c; 
            return nuova; // 
        }

        //4)1C, str = aieiaialph , y=d, func(3)=plaiai
        ostream& put(ostream& os){
        A::put(os); 
        os<<"y="<<this->y<<", func(3)="<<func(3); 
        return os; 
        }
}; 

//overloading
ostream& operator<< (ostream& os, A& obj){
    return obj.put(os);
}

int main(){
    srand(111222333);    
      string S;
      short fa = 3;

    A* vett[DIM];

    for(int i=0; i<DIM; i++){
	    short n=10+rand()%10;
	    S=""; 

	    for(int k = 0; k< 20; k++){
	         S+=rand()%('z'-'a'+1)+'a'; 
	            if(rand()%2==0)
	                vett[i]= new B(n, S);
	            else
	                vett[i]= new C(n, S, (char) (rand()%('z'-'a'+1)+'a'));
        }
    }

    for(int i=0; i<DIM; i++){
        cout<<i<<")"<<*vett[i]<<endl;
    }        


    
}


/*PUNTO 1
1B o 1C typeid 

0)1B, str = eiieocrkmplzxxqr , q=14, func(3)=qxx
1)1B, str = eetptcgcwr , q=5, func(3)=wcg
2)1C, str = eoybgxfqkhjgvhm , y=l, func(3)=hvgjhkqfxgb
3)1B, str = euxmsstnclzl , q=10, func(3)=zlc
4)1C, str = aieiaialph , y=d, func(3)=plaiai
5)1B, str = oiaiairfvgnvjsswbxr , q=1, func(3)=xbw
6)1C, str = auexwhxhrzx , y=c, func(3)=zrhxhwx
7)1B, str = ieaikmbnpmmj , q=6, func(3)=mmp
8)1C, str = ouqqrkqbybjmztjnw , y=o, func(3)=njtzmjbybqkrq
9)1B, str = ugvchfgwwgglrqppdj , q=4, func(3)=dpp
10)1C, str = iaaieqwznr , y=t, func(3)=nzwqei
11)1B, str = ecvnvbzrkgzsl , q=2, func(3)=szg
12)1B, str = eiqsfkfhgkzbrw , q=9, func(3)=rbz
13)1C, str = ooeioomwwjrfxs , y=d, func(3)=xfrjwwmooi
14)1B, str = asdflqvsvtdkhwcj , q=1, func(3)=cwh
15)1C, str = aefzdkhznhncj , y=t, func(3)=cnhnzhkdz
16)1C, str = ooizqfcjvlcjjy , y=c, func(3)=jjclvjcfqz
17)1C, str = ouhbvzrwfprxcb , y=f, func(3)=cxrpfwrzvb
18)1B, str = eueuebqptsnglph , q=11, func(3)=plg
19)1B, str = ihqdkchgvzwsxb , q=8, func(3)=xsw
20)1B, str = eoakgdttvwwcqdthrs , q=12, func(3)=rht
21)1C, str = ieouasspjncbd , y=p, func(3)=bcnjpssau
22)1C, str = ajpvpggcgvqjtx , y=d, func(3)=tjqvgcggpv
23)1C, str = eaeuoesnmwrd , y=o, func(3)=rwmnseou
24)1C, str = aauyjbyhgxcjc , y=j, func(3)=jcxghybjy
25)1C, str = aafbyjldtrsfhnnfvrs , y=x, func(3)=rvfnnhfsrtdljyb
26)1C, str = iouomljjkrj , y=v, func(3)=rkjjlmo
27)1B, str = aouaogckypvkyl , q=7, func(3)=ykv
28)1C, str = augzpnkghfxjvwvhx , y=l, func(3)=hvwvjxfhgknpz
29)1B, str = eueoibbhrbwmmcbpmdx , q=13, func(3)=dmp
30)1B, str = ouuwtjwqwxl , q=9, func(3)=xwq
31)1B, str = iiavgmhhtgzthvwl , q=15, func(3)=wvh
32)1C, str = ooueuqmwmqtcldrh , y=e, func(3)=rdlctqmwmque
33)1B, str = euuovpffzwpnyqxf , q=3, func(3)=xqy
34)1B, str = oahtdyxkrpbrgr , q=1, func(3)=grb
35)1C, str = aieaibfvrdfdv , y=t, func(3)=dfdrvfbia
36)1C, str = aoeashdprqpqfs , y=j, func(3)=fqpqrpdhsa
37)1C, str = aoaeomyjwswrftmq , y=i, func(3)=mtfrwswjymoe
38)1C, str = iiewytdzcnwt , y=r, func(3)=wnczdtyw
39)1B, str = oaeaounxqvnbqpvbzfb , q=9, func(3)=fzb
40)1C, str = uiamfkdldngryh , y=u, func(3)=yrgndldkfm
41)1B, str = aaioorbjbzprzlnq , q=1, func(3)=nlz
42)1C, str = eaaanqcvkspnqwhmmyz , y=v, func(3)=ymmhwqnpskvcqna
43)1B, str = aoooafgyxfdnjsmyg , q=13, func(3)=yms
44)1B, str = eoaueoeykvpyvyjfysl , q=5, func(3)=syf
45)1C, str = uuaiifmppqgdgzyfyy , y=y, func(3)=yfyzgdgqppmfii
46)1B, str = oiaihzsmzxfkd , q=11, func(3)=kfx
47)1C, str = oaprjfnnjhcvvr , y=j, func(3)=vvchjnnfjr
48)1B, str = aeargpdhjzswzy , q=9, func(3)=zws
49)1C, str = oaiirpphkh , y=p, func(3)=khppri

 PUNTO 2
j= 49, g('X')=poaiirpphkX

 PUNTO 3
*vett[5]=1B, str = oiaiairfvgnvjsswbxr , q=1
vett[5](1,3)=ia */