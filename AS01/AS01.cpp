/*
 * @author Ana Carolina Medeiros Gon�alves 
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

    //Entrada para o n�mero de testes
    cin >> n;

    // La�o for para percorrer a quantidade de testes solicitados
    for (int i = 0; i < n; i++) {
        
        //Entrada para informar a quantidade de comida dispon�vel
        cin >> c;

        j = 0;

        /*La�o while para percorrer a quantidade de comida dispon�vel
        * A cada dia a quantidade de comida ser� dividida pela metade
        * Ao final, quando a quantidade de comida for menor ou igual a 1, o la�o para
        * A vari�vel j tem a fun��o de acumular a quantidade de dias
        * No final ser� printado a variavel J com os dias percorridos
        */ 
        while (c >= 1) {
            c = c / 2;
                j = j + 1;
        }

        cout << j <<" dias" << endl;
    }


    return 0;
}