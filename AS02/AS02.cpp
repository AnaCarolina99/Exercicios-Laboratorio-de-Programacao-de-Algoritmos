
/*
 * @author Ana Carolina Medeiros Gonçalves
 * Matricula: 591513
 * Turma: 01
 * Complexidade: A operação relevante é o numero de vezes em que o laço que percorre o grafo é percorrido, 
 * sendo assim a ordem de complexidade fica Θ(V^2XA).
*/

#include <iostream>
#include <string>

using namespace std;

/* Metodo que conta quantos caracteres tem a senha solicitada pelo usuário
*  Retorna a quantidade em um integer 
*/
int tamanho(string letra) {
    int cont = 0;
    for (int i = 0; i < letra.length(); i++) {
        cont = cont + 1;
    }

    return cont;
}

/* Metodo que verifica se a senha tem pelo menos 1 número
*  Retorna um boolean dizendo se há número ou não 
*/
bool numero(char letra) {
    bool b = false;
    if (letra >= '0' && letra <= '9') {
        b = true;
    }
    return b;
}


/* Metodo que verifica se a senha tem pelo menos 1 letra maiuscula
*  Retorna um boolean dizendo se há letra maiuscula ou não
*/
bool maiusculo(char letra){
    bool b = false;
    if ((letra >= 'A') and (letra <= 'Z')) {
        b = true;
    }
    return b;
}

/* Metodo que verifica se a senha tem pelo menos 1 letra minuscula
*  Retorna um boolean dizendo se há 1 letra minuscula ou não
*/
bool minusculo(char letra) {
    bool b = false;
    if (letra >= 'a' && letra <= 'z') {
        b = true;
    }
    return b;
}



int main()
{
    string senha = "";



/* Laço while responsável pelas entradas do código
*  E a verificação se uma senha é valida ou não
*  Função getline percorre todo o arquivo até nao ter mais linha
*/
    while(getline(cin, senha)){

        bool maius = false;
        bool min = false;
        bool number = false;
        bool valido = true;
        bool tam;

        // Verifica se a quantidade de caracteres da entrada é permitido
        if (tamanho(senha) >= 6 && tamanho(senha) <= 32) {
            tam = true;
        }
        else {
            tam = false;
        }

        /* O laço for coloca a entrada em todos os metodos nescessários para a verificação
         * Os metodos retornam se é valido ou nao a senha em cada situação
        */
        for (int i = 0; i < senha.length(); i++) {

            if (maiusculo(senha[i]) == true) {
                maius = true;
            }
            else if (minusculo(senha[i]) == true) {
                min = true;
            }
            else if (numero(senha[i]) == true) {
                number = true;
            }
            else {
                valido = false;
            }
        }

        // Verifica todos os paramentros nescessarios para validar a senha e printa se é valido ou não 
        if (valido == true && maius == true && min == true && number == true && tam == true) {
            cout << "Senha valida." << endl;
        }
        else {
            cout << "Senha invalida." << endl;
        }
    }

}


