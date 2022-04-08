/*
 * @author Ana Carolina Medeiros Gonçalves
 * Matricula: 591513
 * Turma: 01
 * Complexidade: A operação relevante é o numero de comparacoes que o vertice "branco" realiza, como todos os vertices começam "brancos", então não existirá
 * pior ou melhor caso, sendo assim a ordem de complexidade fica Θ(nxmxtxf^2), considerando a variavel "vert" como "m" e a variavel "tam" como "f".
*/

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

//Variavel global
int index = 0;

//Classe para os componentes de um grafo
class Component{

public:char letter;
public:string color;

    Component(){
        letter = 'b';
        color = "WHITE";
    }
};

//Swap do bubblersort
void swap(char vertices1, char vertices2){
    cout << "Entrei no swap";
    char vertices = vertices1;
    vertices1 = vertices2;
    vertices2 = vertices;
}

//Bubblesort para ordenar as letras na saida
void bubblerSort(char letras[],int tam){
  for (int i = 0; i < tam-1; i++){
        for (int j = 0; j < tam-i-1; j++){
            if (letras[j] > letras[j+1]){
                char temp = letras[j];
                letras[j] = letras[j+1];
                letras[j+1] = temp;
            }
        }
    }
}


//Metodo void com o objetivo de visitar todo os vertices adjacentes que estao em branco
void visit(int i, Component vertices[], int** adj, int t, char letras[]){

    vertices[i].color = "GREY";
    letras[index] = vertices[i].letter;
    index++;

    for (int j = 0; j < t; j++)
    {
        if(adj[vertices[i].letter - 97][j] == 1){
            if (vertices[j].color == "WHITE")
            {
              
                visit(j,vertices,adj,t,letras);
                //bubblerSort(vertices,t);
            }

        }
    }
    vertices[i].color = "BLACK";
}

int main(){

    int n;

    int vert;
    int arest;

    int conect;
    int aux;

    int count = 1;

    char c1,c2;

    cin>> n;

    //Loop para percorrer a quantidade obtida pela entrada "n"
    while(n>0){

        cin>> vert;
        cin>> arest;

        aux = vert;
        int **matriz;

        char letras[vert];

        Component vertices[vert];
        matriz = (int**)malloc(vert*sizeof(vert * sizeof(int*)));

            //Loop com o objetivo de acessar todos os vertices do grafo e colocarem um valor incial
            for(int i = 0;i<vert;i++){

                matriz[i] = (int*)malloc(vert * sizeof(int));

                    for (int j = 0; j < vert; j++)
                    {
                        matriz[i][j] = 0;
                    }
            }

            //Loop para iniciar os vertices com a letra 'a'
            for (int i = 0; i < vert; i++)
            {
                vertices[i].letter = 97 + i;
                letras[i] = 0;
            }

            //Loop de leitura e escrita das arestas adjacentes ao vertice
            for (int i = 0; i < arest; i++)
            {
                cin >> c1;
                cin >> c2;

                matriz[c1-97][c2-97] = 1;
                matriz[c2-97][c1-97] = 1;
            }

            cout << "Case #" << count << ":" << endl;
            conect = 0;

            //Loop para visitar todos os vertices "brancos" e acessar o metodo visit e ordenar 
            for (int i = 0; i < vert; i++)
            {
                if(vertices[i].color == "WHITE"){
                    visit(i,vertices,matriz,aux,letras);
                    bubblerSort(letras,vert);
                    for (int i = 0; i < vert; i++) {
                        if(letras[i] != 0) {
                            cout << letras[i] << ",";
                        }
                        letras[i] = 0;
                    }
                    conect = conect + 1;

                    cout << endl;
                }
            }

            cout << conect << " connected components" << endl;
            cout << endl;

            //Decrementando a quantidade e incrementando os casos
            n--;
            count++;

            index = 0;
    }
    return 0;
}
