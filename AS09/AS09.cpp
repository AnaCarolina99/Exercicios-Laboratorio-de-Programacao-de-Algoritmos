/*
 * @author Ana Carolina Medeiros Gonçalves
 * Matricula: 591513
 * Turma: 01
 * Complexidade: Usando programação dinamica, a operação relevante tanto no melhor caso e no pior, a ordem de complexidade fica Θ(nm),
 * onde n é o número de posiçoes das maças e o m o número total de posições.
*/

#include <iostream>
#include <vector>

using namespace std;

//Metodo para reconhecer se um numero eh primo ou não, e retorna um vector com os valores da sequencia
vector<int> numPrimos(int n){
    bool resp = true;
    vector<int> numPrimos;

    for(int i = 2; n >1;i++){
        while(n %i ==0){
            if(resp == true){
                numPrimos.push_back(i);
            }
            resp = false;
            n /=i;
        }
        resp = true;
    }
    return numPrimos;
}

//Metodo que serve para receber a sequencia de numeros. Se esses numeros forem decompostos em numeros primos, os mesmos serao colocados no conjunto "N"
int sequencia(int m, int n){

    vector<int> novos_Numeros;
    vector<int> array_Num_Primos;

    int quant = 0;
    int primeiro = 0;
    bool resp = false;
    int resultado_final = 0;
    int x = 0;

    // Recebe os numeros e coloca em um vetor 
    while(x<n){
        cin >> primeiro;
        array_Num_Primos.push_back(primeiro);
        x = x + 1;
    }

    int aux = array_Num_Primos[0];    

    //Laço que percorre o "array_Num_Primos"
    for(int i = aux; quant<m;i++){
        //Atribuir valor do metodo que verificar quais sao os numeros primos e adicionar no vector "novos_Numeros"
        novos_Numeros = numPrimos(i);
        for(int j =0; j < novos_Numeros.size(); j++){
            for(int k = 0; k< array_Num_Primos.size(); k++){
                resp = false;

                // Caso os vetores sejam iguais a resposta eh true e o tamanho do array eh adicionado em k
                if(novos_Numeros[j]== array_Num_Primos[k]){
                    resp = true;
                    k = array_Num_Primos.size();
                }
            }

            if(resp == false){
               j = novos_Numeros.size();
            }
        }
        //Caso as respostas seja verdadeira o 1 for eh incrementado
            if(resp == true){
                quant = quant + 1;
            }
            // O valor da saida eh gerado 
            resultado_final = i;
    }

    return resultado_final;
}

int main(){
    int m;
    int n;
    int primos;

    cin >> n;
    cin >> m;

    // Laço para receber os valores de M e N, termina quando os valores do mesmo forem 0
    while(m!=0 && n!=0){
        
        primos = sequencia(m,n);

        //Print codigo semanal de Levi
        cout << primos << endl;

        cin >> n;
        cin >> m;
    }


}