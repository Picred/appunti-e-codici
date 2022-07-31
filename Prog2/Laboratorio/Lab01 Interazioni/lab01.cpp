#include <iostream>
using namespace std;


// #define DIM 10 //numero di interazioni totali

    float* computeFrequency(int timestamps[], int n){
        float * frequency = new float [n];

        frequency[0]= 0.0;

        float partialSum=0.0;

        for(int i=0; i<n; i++){
            partialSum += timestamps[i]-timestamps[i-1];
            frequency[i] = partialSum / i; //è diviso "i" perchè semanticamente ha piu senso calcolare la frequenza ottenuta fino a quel momento
                                            // e non per tutti gli n elementi
        }


        //soluzione piu costosa perchè c'è un secondo ciclo for
        /*for (int i=1; i<n; i++){
            frequency[i] = 0f;
        
            for(int j=1; j<=i; j++){
                frequency[i] += timestamps[j]-timestamps[j-1]; //calcolo prima la somma parziale
            }
            frequency[i] /= n; //moltiplico per 1/n // divido per n
        }*/

        return frequency;
    }

    float* computeScore(int interactions[],int n){
        float* score = new float [n];

        for(int i=0; i<n; i++){
        if(i<3)
            score[i]=interactions[i];
        else 
            score[i] = 0.25*interactions[i-3] + 0.3*interactions[i-2]+ 0.5*interactions[i-1]+interactions[i];

        }
        return score;
    }

    float* computePopularity(int interactions[],int timestamps[], int n){
        float* interactionScore = computeScore(interactions, n);
        float* frequencyScore = computeFrequency(timestamps, n);

        float* popularity = new float [n];

        float alpha = 0.66;
        for(int i=0; i<n; i++){
            popularity[i] = alpha+interactionScore[i]+(1-alpha)*frequencyScore[i];
        }

        return popularity;
         
    }   

int main(){
    //le prime 4 posizioni di I devono essere vuote o comunque calcolate in un altro modo visto che la formula di S
    //prende in considerazione I[t-3], quindi t deve essere minimo 3 perchè una posizione I[0-3] non esiste
    int n = 10;
    int interactions[n] = {-74,-22,28,34,1,68,98,-99,100,100};
    int timestamps[n] = {1,2,3,4,5,6,7,8,9,10};

    float* F = computeFrequency(timestamps, n);
    float* S = computeScore(interactions, n);
    float* popularity = computePopularity(interactions, timestamps, n);

    for(int i=0; i<n; i++){
        cout << popularity[i] << " ";
    }
}


float maxPopularity(float S[], int n,int& start, int& end){
    float _max = 0;
    float somma= _max;
    for(int j=0; j<n; j++){
        if(somma > 0) { 
            somma+=S[j];
        } else { //j è il punto di inizio del segmento di somma massima
            start=j;
            somma= S[j];
        }
        if(somma > _max){
            // j è il punto di fine del segmento di somma massima
            end=j;
            _max = somma;
        }
    }
    return _max;
}


