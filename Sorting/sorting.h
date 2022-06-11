#ifndef SORTING_H
#define SORTING_H

namespace sorting{

    void swap(int& x, int& y){
        int temp=x;
        x=y;
        y=temp;
    }

    bool dicotomicaRicorsiva(int vett[], int key, int start, int end){
    if(start>end){
        return false;
    }

    int m = (end+start)/2;

    if(vett[m]==key){
        return true;
    }

    if(key<vett[m]){
        return dicotomicaRicorsiva(vett,key,start,m-1);
    }

    if(key>vett[m]){
        return dicotomicaRicorsiva(vett,key,m+1,end);
    }

    return false;
}

    bool dicotomicaIterativa(int vett[], int size, int key){
        int start=0;
        int end=size-1;
        int midpoint;
        bool found=false;

        while(!found && start<=end){
            midpoint= (start+end)/2;

            if(vett[midpoint]==key)
                found=true;

            if(key<vett[midpoint])
                end=midpoint-1;
            
            if(key>vett[midpoint])
                start=midpoint+1;
        }

        return found;
    }

    void ordinamentoPerScambio(int vett[], int size){
        for(int i=0; i<size-1;i++){
            for(int j=i+1;j<size;j++){
                if(vett[j]<vett[i])
                    swap(vett[i],vett[j]);
            }
        }
    }

    void selectionSort(int vett[], int dim){
        int indexMin;
        for(int i=0; i<dim-1;i++){
            indexMin=i;
            for(int j=i+1;j<dim;j++){
                if(vett[j]<vett[i])
                    indexMin=j;
            }
            swap(vett[i],vett[indexMin]);
        }
    }
}
#endif