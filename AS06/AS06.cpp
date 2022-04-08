/*
 * @author Ana Carolina Medeiros Gonçalves
 * Matricula: 591513
 * Turma: 01
 * Complexidade: A operação relevante é o numero de vezes em que o laço que percorre o grafo é percorrido, 
 * sendo assim a ordem de complexidade fica Θ(V^2XA).
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

//Variaveis pre-definidas
#define max 225
#define Vertice int

//Variaveis globais
int liga[max];
int matrix[225][225];
int V;
int A;
int K;
int segment;
int tp;

//Classe para criar as arestas do grafo
class Aresta{
    int vertice1;
    int vertice2;
    int peso;

    
    public: Aresta(int v1, int v2, int peso){
            vertice1 =v1;
            vertice2 = v2;
            this->peso = peso;
        
    }

    int obterVertice1(){
        return vertice1;
    }

    int obterVertice2(){
        return vertice2;
    }

    int obterPeso(){
        return peso;
    }

    //Cria pesos nas arestas
    bool operator <(const Aresta& aresta2) const{
        return(peso< aresta2.peso);
    }
    
};

//Classe que cria o conjunto disjuntos
struct Conjunto{
    int *dad;
    int *ranking;
    int n;

    Conjunto(int n){
        this->n = n;
        dad = new int[n+1];
        ranking = new int[n+1];

        for(int i = 0; i<=n;i++){
            ranking[i] = 0;
            dad[i] = i;
        }
    }

    //Procurar vertices pais
    int search(int n){
        if(n!=dad[n]){
            dad[n] = search(dad[n]);
        }
        return dad[n];
    }

    //Juntas os vertices do mesmo componente
    void juntar(int i, int j){
        i = search(i);
        j = search(j);

        if(ranking[i] > ranking[j]){
            dad[j] = i;
        }else{
            dad[i] = j;
        }
        if(ranking[i] == ranking[j]){
                ranking[j]++;
        }
    }
};

//Percorrer o caminho do vertice escolhido
void caminhoVert(Vertice v){
    Vertice x;
    liga[v]=1;
    for(x=0;x< V;x++){
        if(matrix[v][x]==1){
            if(liga[x]==-1){
                caminhoVert(x);
            }
        }
    }
}

//Percorrer o caminho do grafo
void caminho(){
    segment = 0;

    Vertice v;

    for(v = 0; v< V;v++){
        liga[v] = -1;
    }

    for(v=0; v<V;v++){
        if(liga[v] == -1){
            segment++;

            caminhoVert(v);

            for(int i = 0; i< V;i++){
                if(liga[i]>0){
                    liga[i] = 0;
                }
            }
        }
    }
}

//Classe para criar grafo
class Grafo{

    
    int V;
    vector<Aresta> arestas;
    public:
    int sum = 0;

    Grafo(int V){
        this->V=V;
    }

    void inserir(int v1, int v2, int peso){
        Aresta aresta(v1,v2,peso);
        arestas.push_back(aresta);
    }

    void Kruskal(){
        caminho();

        vector<Aresta> arvore;
        int size = arestas.size();
        sort(arestas.begin(), arestas.end());

        Conjunto deep(V);

        for(int i =0; i<size;i++){
            int v1 = deep.search(arestas[i].obterVertice1());
            int v2 = deep.search(arestas[i].obterVertice2());

            if(v1!= v2){
                arvore.push_back(arestas[i]);
                deep.juntar(v1,v2);
            }
        }

        int sizeV = arvore.size();
        int min = arvore[0].obterPeso();

        for(int i = 0;i<sizeV;i++){
            char v1 = 'A' + arvore[i].obterVertice1()-1;
            char v2 = 'A' + arvore[i].obterVertice2()-1;

            sum+= arvore[i].obterPeso();

        }

        if(segment>1){
            tp=tp-segment+1;

        }else{
            if(V==3){
                sum+= min;
            }
        }
        for(int i = tp;i>0;i--){
            sum = sum -arvore[sizeV-1].obterPeso();
            sizeV--;
        }
    }
};

//Metodo para dividir o grafo 
vector<int> split(const string &s, char demilitado){
    vector<int> tokens;
    string token;
    istringstream tokenStream(s);
    while(getline(tokenStream,token, demilitado)){
        tokens.push_back(stoi(token));
    }
    return tokens;
}

int main(){
    int vertice;
    int aresta;
    int pulos;
    int vet1;
    int vet2;
    int val;
    int casos;

    string x;
    getline(cin,x);
    istringstream(x)>> casos;

    //Laço que percorre até quando os casos forem maiores do que 0
    while(casos>0){

        getline(cin,x);
        vector<int> grafo = split(x, ' ');

        vertice = grafo[0];

        V=vertice;
        A= aresta;

        aresta=grafo[1];
        pulos=grafo[2];

            //Zerar o grafo para começar novamente
            for(int i=0; i<vertice;i++){
                for(int j=0; j<vertice;j++){
                    matrix[i][j] = 0;
                }
            }
        //Inicializar o struct grafo
        Grafo g(vertice);

        //Laço que percorre até existir aresta
        while(aresta>0){

            getline(cin,x);
            vector<int>line= split(x,' ');

            vet1=line[0];
            vet2=line[1];
            val=line[2];

            matrix[vet1-1][vet2-1]++;
            matrix[vet2-1][vet1-1]++;

            g.inserir(vet1,vet2,val);

            aresta--;
        }
        //Executa os pulos do codigo 
        tp=pulos;

        //Chama o algoritmo de Kruskal para percorrer o grafo
        g.Kruskal();

            if(pulos<segment-1){
                cout<<"-1"<<'\n';

            }
            else{
                cout<<g.sum<<'\n';
            }
            casos--;
    }
    return 0;
}