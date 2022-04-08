/*
 * @author Ana Carolina Medeiros Gonçalves
 * Matricula: 591513
 * Turma: 01
 * Complexidade: A operação relevante é o número de comparações que sao realizadas entre os nomes proprios.
 * A ordem de complexidade no melhor caso, é quando há apenas 1 linha com o nome proprio1, parentesco e nome proprio2 que será 
 * passado apenas uma vez no "if(i==0)",a ordem de comlexidade então será Θ(mxn).
 * O pior caso ocorrerá quando a entrada terá mais de 1 linha com o nome proprio1, parentesco e nome proprio2, o codigo além
 * de passar pelo "if(i==0)", passará pelo else que acessará o metodo "achar", e além disso acessará mais um tanto de if e else,
 * resultando uma ordem de complexidade Θ(mxnxp), considerando p = people.size().
*/

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

//Variáveis já definidas
#define Vertex int
#define max 26

//Variáveis Globais
int matrix[26][26];
int lig[max];
int V,A;
int seg;
int c=0;

//Criando uma struct para os atributos numero e nome
struct pessoa {
    int numero;
    string nome;
};

//Metodo para percorrer um caminho do vertice 
void caminhoV (Vertex v) {
    //Cria Vertice
    Vertex w;

    //Muda Valor para Falar que existe ligacao
    lig[v] = 1;

    //Laço para verificar se existe adj ligado na matriz e ainda se nao passou pelo caminho e da um next
    for (w = 0; w < V; w++) {
        if (matrix[v][w] == 1) {
            if (lig[w] == -1) {
                caminhoV(w);
            }
        }
    }
}

//Metodo para percorrer um caminho e insere no vetor
void caminho (void) {
    //Cria Vertice Inicial
    Vertex v;
    //Apagar Valores Inseridos no Vetor
    for (v = 0; v < V; v++) {
        lig[v] = -1;
    }
    //Conta segmentos e vai recursivamente criando vertices
    for (v = 0; v < V; v++) {
        //Se ligacao inexistente
        if (lig[v] == -1) {
            seg++;
            //Recursivo criar vertices
            caminhoV(v);

        }
    }
}

//Metodo para verificar se ja existe o familiar na familia
int achar(vector<pessoa>&people,string x){
    for(int i=0;i<people.size();i++){
        if(people[i].nome.compare(x)==0){
            return i;
        }
    }
    return -1;
}

int main() {

    //Relaçoes = Arestas
    int n;
    //Pessoas = Vertices
    int m;

    //Flag achou
    int x1;
    int x2;

    //Variaveis de nomes proprios1,nomes proprios2 e o parentesco
    string n1;
    string n2;
    string p;

    //Laço para percorrer a quantidade de pessoas existentes na entrada
    while (cin>> m) {

        V=m;
        vector<pessoa> people(m);
        cin >> n;   
        A=n;
        seg=0;

        //Laço para zerar matriz, caso tenha outra entrada m e n
        for (int j=0; j<m; j++) {
            for (int k=0; k<m; k++) {
                matrix[j][k]=0;
            }
        }

        //Percorrer de acordo com o numero de relacoes existentes na entrada
        for (int i=0;i<n;i++) {

            //Variavel nome proprio1
            cin >> n1;

            //Variavel parentesco 
            cin >> p;

            //Variavel nome proprio1
            cin >> n2;

            //preencher a 1 linha com os nomes e parentesco
            if(i==0){
                people[c].nome=n1;
                people[c].numero=c;
                people[c+1].nome=n2;
                people[c+1].numero=c+1;
                           
                //Inserir Arestas
                matrix[people[c].numero][people[c+1].numero]++;
                matrix[people[c+1].numero][people[c].numero]++;

                c=c+2;
            
            //Preencher o resto das linhas com os nomes e parentescos
            }else{
                x1=achar(people,n1);
                x2=achar(people,n2);
             
                if(x1>-1&&x2==-1){
                    people[c].nome=n2;
                    people[c].numero=c;
                    //Inserir Arestas
                    matrix[people[x1].numero][people[c].numero]++;
                    matrix[people[c].numero][people[x1].numero]++;
                    c++;
                }
                else if(x1==-1&&x2>-1){
                    people[c].nome=n1;
                    people[c].numero=c;
                    //Inserir Arestas
                    matrix[people[c].numero][people[x2].numero]++;
                    matrix[people[x2].numero][people[c].numero]++;
                    c++;
                }
                else if(x1>-1&&x2>-1){
                    matrix[people[x1].numero][people[x2].numero]++;
                    matrix[people[x2].numero][people[x1].numero]++;
                }
                else{
                    people[c].nome=n1;
                    people[c].numero=c;
                    people[c+1].nome=n2;
                    people[c+1].numero=c+1;
                            
                    //Inserir Arestas
                    matrix[people[c].numero][people[c+1].numero]++;
                    matrix[people[c+1].numero][people[c].numero]++;
                    c=c+2;
                }
            }

        }
        //Chamar caminho para percorrer o caminhos dos vertices
        caminho();

        //Printar o numero de familias na tela
        cout <<seg<<endl;
    }
}