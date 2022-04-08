/*
 * @author Ana Carolina Medeiros Gonçalves
 * Matricula: 591513
 * Turma: 01
 * Complexidade: A operação relevante é o numero de vezes em que o laço decompoe o valor da entrada em moedas e cedulas, salvando em um vector
 * tanto no melhor caso e no pior, a ordem de complexidade fica Θ(nota[]^2),
*/

#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

//Valor pré definido do valor das cedulas e moedas 
vector <double> nota = {100.00, 50.00,20.00, 10.00, 5.00, 2.00, 1.00, 0.50, 0.25,0.10,0.05,0.01};

int main(){

    double valor = 0;

    //Valor de entrada do valor a ser decomposto
    cin >> valor;

    vector <double> array_de_Notas(12, 0.00);

    for(int i =0; i< nota.size();i++){

    //Laço para contar a quantidade de moedas e cedulas        
    while(valor>= nota[i]){
        array_de_Notas[i]++;
        valor= valor- nota[i];
        }
    }
    
    cout << "NOTAS:"<< endl;

    //Printar notas com 2 casas decimais
    for(int i =0; i< array_de_Notas.size() - 6;i++){
        cout << fixed << setprecision(0) << array_de_Notas[i] << " nota(s) de R$ ";
        cout << fixed << setprecision(2) << nota[i]  << endl;
    }
    
    cout << "MOEDAS:"<< endl;

    //Printar moedas com 2 casas decimais
    for(int i =6; i< array_de_Notas.size();i++){
        cout << fixed << setprecision(0) << array_de_Notas[i] << " moeda(s) de R$ ";
        cout << fixed << setprecision(2) << nota[i] << endl;
    }
    
}