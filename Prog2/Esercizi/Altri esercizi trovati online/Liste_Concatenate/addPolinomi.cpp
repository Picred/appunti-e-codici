#include <fstream> //jRoe
#include <string>

using namespace std;

 class Monomio{
 public:
     
     Monomio *next, *prex;
        int val, exp;
     
     Monomio(){
         next = NULL;
         prex = NULL;
         val = 1;
         exp = 0;
     }
     
     void print(ostream &out){
         if (val!=0){
             
             if (val==-1){
                 out << "-";
             }
             else if ((val!=1) || exp==0)
                 out << val;
             if (exp==1){
                out << "x";
            }
            else if (exp>1){
                out << "x^" << exp;
            }
         }
     }
     
     Monomio *negative(){
         val = val*(-1);
         return this;
     }
     
     Monomio *read(string task){
         int size = (int) task.size(), i=0, neg=0;
         string temp = "";
         while(i<size){
             switch(task.at(i)){
                 case '-':
                     neg=1;
                     ++i;
                     break;
                     
                 case 'x':
                     exp=1;
                     ++i;
                     break;
                     
                 case '^':
                     ++i;
                     exp = atoi(task.substr(i, i).c_str());
                     i=size;
                     break;
                     
                 default:
                     if (task.at(i)!='+'){
                         temp += task.at(i);
                     }
                     ++i;
                     break;
             }
             
         }
         if (temp.size()>0){
             val = atoi(temp.c_str());
         }
         if (neg==1){
             val *= -1;
         }
         return this;
     }
};

class Polinomio{
    Monomio *head, *end, *current;
    
    void _insert(Monomio *m){
        Monomio *temp = head->next;
        while(temp!=end && temp->exp > m->exp){
            temp = temp->next;
        }
        m->next=temp;
        m->prex = temp->prex;
        temp->prex->next = m;
        temp->prex = m;
    }
    
    int _add(Monomio *m){
        Monomio *temp = head->next;
        while(temp!=end && temp->exp > m->exp){
            temp = temp->next;
        }
        if (temp == end || temp->exp < m->exp){
            return 0;
        }
        temp->val += m->val;
        return 1;
    }
    
public:
    
    Polinomio(){
        head = new Monomio;
        end = new Monomio;
        head->next = end;
        end->prex = head;
    }
    
    void reset(){
        current = head->next;
    }
    
    void next(){
        current = current->next;
    }
    
    Monomio *getCurrent(){
        if (current==end){
            return NULL;
        }
        return current;
    }
    
    void print(ostream &out){
        Monomio *temp = head->next;
        while(temp!=end){
            temp->print(out);
            temp = temp->next;
            if (temp!=end && temp->val>0){
                out << "+";
            }
        }
        out << endl;
    }
    
    Polinomio *insert(string task){
        task = task.substr(1, task.size()-2); //escludo le parentesi
        int i=0;
        string tempMonomio;
        int isNegative=0;
        while(i<task.size()){
            tempMonomio="";
            while((i<task.size()) && (task.at(i)!='+' && task.at(i)!= '-')){
                tempMonomio += task.at(i);
                ++i;
            }
            if (tempMonomio.size()>0){
                Monomio *m = new Monomio;
                m->read(tempMonomio);
                if (isNegative==1){
                    m->negative();
                }
                isNegative=0;
                _insert(m);
            }
            else{
                if (task.at(i++)=='-'){
                    isNegative=1;
                }
            }
        }
        return this;
    }
    
    Polinomio *add(Polinomio *p, int negative){
        p->reset();
        while(p->getCurrent()){
            if (negative==1){
                p->getCurrent()->negative();
            }
            if (_add(p->getCurrent())==0){
                Monomio *m = new Monomio;
                m->val=(p->getCurrent()->val);
                m->exp=(p->getCurrent()->exp);
                _insert(m);
            }
            p->next();
        }
        return this;
    }
};

int main(int argc, const char * argv[]) {
    string task;
    int dim, i, negative=0;
    ifstream *input = new ifstream("input.txt");
    ofstream *output = new ofstream ("output.txt");
    while(*input >> dim >> task){
        Polinomio *p = new Polinomio, *temp;
        i=1;
        p->insert(task);
        while(i<dim){
            *input >> task;
            if (task=="-"){
                negative=1;
            }
            else if (task == "+"){
                negative = 0;
            }
            else{
                temp = new Polinomio;
                temp->insert(task);
                p->add(temp, negative);
                ++i;
                delete temp;
            }
        }
        p->print(*output);
        delete p;
    }
    input->close();
    delete input;
    output->close();
    delete output;
    return 0;
}
