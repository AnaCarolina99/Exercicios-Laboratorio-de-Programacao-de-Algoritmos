/*
 * @author Ana Carolina Medeiros Gonçalves
 * Matricula: 591513
 * Turma: 01
 * Complexidade: A operação relevante é o numero de vezes em que são percorridos os laços, com o intuito de encontrar os conjuntos distintos mais caros, utilizando o
 * algoritmo de força bruta, aprendido em PAA. Para ambos os casos, pior ou melhor caso, a ordem de complexidade fica Θ(n^5).
*/

#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

//Variavel pre definida 
#define linha 5

int main(){
    
    //Quantidade
    int quant;
    
    cin >> quant;
    
    //Matriz pre definida, seguindo o problema
    int matriz[linha][quant];
    
    int value;
    
    int n = 0;
    
    //Laço para percorrer a 1 linha de livros
    while(n < quant){
        cin>> value;
        matriz[0][n]=value;
        n++;
    }

    // Laço para percorrer o restante das linhas de livros
    for(int i = 1; i< 5; i++){
        cin >> quant;
        for(int j = 0; j<quant;j++){
            cin>> value;
            matriz[i][j] = value;
        }
    }
    
    //Quantidade de conjuntos distintos
    int k;

    cin>> k;
    
    //Variaveis de cada materia
    int port;
    int mat;
    int fis;
    int qui;
    int bio;

    //Contador
    int count = 0;
    
    //Cria o tamanho do vetor sendo sempre quant^5
    int somaTipos[(int)pow(quant,5)];

    //Algoritmo de força bruta para percorrer a quantidade de livros distintos de cada materia
    for(int i=0;i<quant;i++){
        port = matriz[0][i];
        for(int j=0;j<quant;j++){
            mat = matriz[1][j];
            for(int k=0;k<quant;k++){
                fis = matriz[2][k];
                for(int l=0;l<quant;l++){
                    qui = matriz[3][l];
                    for(int m=0;m<quant;m++){
                        somaTipos[count] = port+mat+fis+qui+ matriz[4][m];
                        count++;
                    }
                }            
            }   
        }    
    }

    //Pegar o tamanho do vetor somaTipos
    int size = sizeof(somaTipos)/ sizeof(somaTipos[0]);
    
    //Ordenar os livros
    sort(somaTipos, somaTipos+ size,greater<int>());
    
    int sum = 0;
    count = 0;

    //For para percorrer e somar os valores de k
    for(int i = k; i>0;i--){
        sum= sum + somaTipos[count];
        count++;
    }

    //Printar soma dos valores de K
    cout << sum;

    return 0;
}