/*
 * @author Ana Carolina Medeiros Gonçalves
 * Matricula: 591513
 * Turma: 01
 * Complexidade: A operação relevante é o algoritmo de ordenação mergesort, tendo no melhor caso e no pior, a ordem de complexidade fica Θ(nlogn).
*/
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

//Variavel global
int quant = 0;

//Algoritmo de Merge sort, que faz parte do metodo de conqusita e divisão
void sortMerge(int esq, int meio, int dir, int tamanho[]){


    int direita = dir - meio;
    int esquerda = meio - esq+1;

    int vecDir[direita];
    int vecEsq[esquerda];


    //Laços para copiar 
    for(int i=0; i<esquerda; i++){
        vecEsq[i] = tamanho[esq+i];
    }
    for(int i=0; i<direita; i++){
        vecDir[i] = tamanho[meio+1+i];
    }
    
    int n1 = 0;
    int n2 = 0;

    int temp = esq;

    //Ordenar os numeros da entrada
    while (n1 < esquerda && n2 < direita){
        if(vecEsq[n1] <= vecDir[n2]){
            tamanho[temp] = vecEsq[n1];
            n1++;
        } else {
            tamanho[temp] = vecDir[n2];
            n2++;
           quant = quant + (esquerda-n1);
        }
        temp++;       
    }

    while (n1<esquerda){
        tamanho[temp] = vecEsq[n1];
        n1++; temp++;
    }
    while (n2<direita){
        tamanho[temp] = vecDir[n2];
        n2++; temp++;
    } 
}

// Metodo para chamar e ordenar os valores usando algoritmo de conquista e divisão
void merge_sort(int esq, int dir, int tamanho[]){

    int meio = 0;

    if(esq<dir){
        meio = (esq+dir)/2;
        merge_sort(esq, meio, tamanho);
        merge_sort(meio+1, dir, tamanho);
        sortMerge(esq, meio, dir, tamanho);
    }
}


//Metodo recursivo para chamar a função merge_sort
void mergeSort(int tamanho[], int n){
    merge_sort(0, n-1, tamanho);
}

int main(){

    int n = 0;
    int x = 0;

    cin >> n;

    //Laço que recebe a quantidade e os valores de cada linha, até chegar no numero 0
    while(n!=0){

        int tamanho[n];

        //Laço que recebe os valores do vetor 
        for(int i = 0; i<n;i++){
            cin>> x;
            tamanho[i] = x;
        }

            mergeSort(tamanho, n);

        //if que printa marcelo ou carlos, dependendo da soma
        if(quant %2 == 0){
            cout <<"Carlos" <<endl;
        }else{
            cout <<"Marcelo" <<endl;
        }

        cin >> n;

        quant =0;
    }
}