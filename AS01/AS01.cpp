/*
 * @author Ana Carolina Medeiros Gonçalves 
 * Matricula: 591513
 * Turma: 01
 * Complexidade: O(n)*O(log2 c)
*/
#include <iostream>

using namespace std;

int main() {

    
    int n = 0;
    float c = 0;
    int j = 0;

    //Entrada para o número de testes
    cin >> n;

    // Laço for para percorrer a quantidade de testes solicitados
    for (int i = 0; i < n; i++) {
        
        //Entrada para informar a quantidade de comida disponível
        cin >> c;

        j = 0;

        /*Laço while para percorrer a quantidade de comida disponível
        * A cada dia a quantidade de comida será dividida pela metade
        * Ao final, quando a quantidade de comida for menor ou igual a 1, o laço para
        * A variável j tem a função de acumular a quantidade de dias
        * No final será printado a variavel J com os dias percorridos
        */ 
        while (c >= 1) {
            c = c / 2;
                j = j + 1;
        }

        cout << j <<" dias" << endl;
    }


    return 0;
}