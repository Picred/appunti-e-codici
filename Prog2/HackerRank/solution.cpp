//Fonte: https://www.hackerrank.com/challenges/virtual-functions/problem?isFullScreen=true

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
    protected:
        int age;
        string name;
    public:
        Person(){}
        
        void setName(string n){
            this->name=n;
        }
        
        void setage(int a){
            this->age=a;
        }
        
        virtual void getdata()=0;
        virtual void putdata()=0;
};

class Professor : public Person{
    private:
        int publications;
        static int cur_id;
    public:
        Professor():Person(){}
        void getdata(){
            string nome="";
            int eta=0,pub=0;
            cin >> nome >> eta >> pub;
            setName(nome);
            setage(eta);
            this->publications=pub;
        }
        
        void putdata(){
            cout << name << " " << age << " " << publications << " " << cur_id++ << endl;
        }
};


class Student : public Person{
    private:
        int* marks;
        static int cur_id;
    public:
        Student():Person(){
            marks=new int[6];
        }
        
        void getdata(){
            string nome="";
            int eta=0;
            
            cin >> nome >> eta;
            setName(nome);
            setage(eta);
            
            int voti;
            
            for(int i=0; i<6;i++){
                cin >> voti;
                marks[i]=voti;
            }
            
        }
        
        void putdata(){
            cout << name << " " << age<< " ";
            
            int sum=marks[0];
            
            for(int i=1; i<6; i++){
                sum+=marks[i];
            }
            
            cout << sum<< " " << this->cur_id++ << endl;
            
        }
};

int Student::cur_id=1;
int Professor::cur_id=1;
int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
