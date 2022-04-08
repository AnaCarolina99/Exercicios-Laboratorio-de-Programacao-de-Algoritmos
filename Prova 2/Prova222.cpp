/*
 * @author Ana Carolina Medeiros Gonçalves
 * Matricula: 591513
 * Turma: 01
 * Complexidade: A operação relevante é o numero de vezes em que o laço que percorre o grafo é percorrido, 
 * sendo assim a ordem de complexidade fica Θ(V^2WA).
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

//Variaveis pre-definidas
#define Vertex int

//Variaveis globais
map<string, int>mapa;
int start=0;
int matrix[30][30];
int lig[30];
int V,A;
int seg;

//Classe para criar as arestas do grafo
class Aresta{
    
    //Aresta possui Vertice de Origem,Vertice de Destino e Peso
    int verticeO,verticeD,peso;
    
    public:
    Aresta(int v1, int v2, int peso)
	{
		verticeO = v1;
		verticeD = v2;
		this->peso = peso;
	}

	int obterVerticeO()
	{
		return verticeO;
	}

	int obterVerticeD()
	{
		return verticeD;
	}

	int obterPeso()
	{
		return peso;
	}

	//Sobrescrita do Operador "<"
    //Cria pesos nas arestas
	bool operator < (const Aresta& aresta2) const
	{
		return (peso < aresta2.peso);
	}
};

//Conjuntos Disjuntos
struct ConjuntosDisjuntos 
{ 
    //Componentes Pai Rank e numero de Vertices(n)
    int *pai, *rank; 
    int n; 
  
    //Construtor 
    ConjuntosDisjuntos(int n) 
    { 
        //Alocar Memoria
        this->n = n; 
        pai = new int[n+1]; 
        rank = new int[n+1]; 
  
        //Todos os Vertices em diferentes sets e Rank 0
        for (int i = 0; i <= n; i++) 
        { 
            rank[i] = 0; 
            //Todo elemento eh pai dele mesmo
            pai[i] = i; 
        } 
    } 
  
    //Achar pai do elemento "u"
    //Compressao de Caminho
    int buscar(int u) 
    { 
        //Fazer com que o pai do elemento no caminho
        //u->pai[u] apontar para pai[u]
        if (u != pai[u]){
            pai[u] = buscar(pai[u]); 
        }
        return pai[u]; 
    } 
  
    //Se Rank igual Juntar
    //Uniao por Rank
    void juntar(int x, int y) 
    { 
        x = buscar(x), y = buscar(y); 
    
        //Fazer com que a Arvore de menor Rank 
        //seja uma subArvore da outra Arvore
        if (rank[x] > rank[y]) {
            pai[y] = x; 
        }
        else {
            pai[x] = y; 
        }
        if (rank[x] == rank[y]) {
            rank[y]++; 
        }
    } 
}; 
  
//Classe para criar grafo
class Grafo
{
    
    //Quantidades de Vertice do Grafo
	int V; 
	//Vetor de Arestas = Grafo
	vector<Aresta> arestas; 

    public:
	//Soma dos tamanhos
	int soma=0;

	Grafo(int V)
	{
		this->V = V;
	}

	//Adicionar Aresta
	void inserir(int v1, int v2, int peso)
	{
		Aresta aresta(v1, v2, peso);
		arestas.push_back(aresta);
	}

	///Kruskal
	void kruskal(int start)
	{
	    //Grafo Resultante
		vector<Aresta> arvore;
		
		int size_arestas = arestas.size();

		//Ordenar por Menor Peso
		sort(arestas.begin(), arestas.end());

        ConjuntosDisjuntos ds(V); 

		for(int i = start; i < size_arestas; i++)
		{
			int v1 = ds.buscar(arestas[i].obterVerticeO());
			int v2 = ds.buscar(arestas[i].obterVerticeD());

			if(v1 != v2)
			{
				//Se forem Diferentes -> Nao forma ciclo -> Insere no vetor
				arvore.push_back(arestas[i]);
				ds.juntar(v1,v2);
			}
		}

        //Passar por Todos os Membros da Arvore Geradora
		int size_arvore = arvore.size();

		//Mostrar Resultante
		for(int i = 0; i < size_arvore; i++)
		{
			soma+=arvore[i].obterPeso();
		}
	}
};

//Percorrer o caminho do vertice escolhido
void caminhoV (Vertex v) {
    //Cria Vertice
    Vertex w;
    //Muda Valor para Falar que existe ligacao
    lig[v] = 1;
    for (w = 0; w < V; w++) {
        //Verifica se exite ligacao na matrix adj
        if (matrix[v][w] == 1) {
            //Verifica se nao passou por esse caminho e vai para proximo
            if (lig[w] == -1) {
                caminhoV(w);
            }
        }
    }
}

//Percorrer o caminho do grafo
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
            //Com o Lista de Adj ja criada, imprime os vertices conexos
            for (int i = 0; i < V; i++) {
                //Verifica se existe "filhos" e os imprime
                if (lig[i] > 0)   {
                    lig[i]=0;
                }
            }
        }
    }
}


//Limpar o Map
void limpar(){
    mapa.clear();
}

int main(){

    int vertice,aresta,peso;
    string str, origem, destino,comeco;

    cin>>vertice;
    cin>>aresta;

    //Laço que percorre enquanto as arestas e vertices forem diferentes de 0
    while(vertice!=0&&aresta!=0){

        V=vertice;
        A=aresta;
        seg=0;

        //Zerar matrix
        for (int j=0; j<V; j++) {
            for (int k=0; k<V; k++) {
                matrix[j][k]=0;
            }
        }
        Grafo g(vertice);
        limpar();
        for(int i = 0; i < vertice; i++){
            cin>>str;

            mapa[str]=i;
        }
        for(int t = 0; t < aresta; t++){
            cin>>origem;
            cin>>destino;
            cin>>peso;

            matrix[mapa[origem]][mapa[destino]]++;
            matrix[mapa[destino]][mapa[origem]]++;

            g.inserir(mapa[origem],mapa[destino],peso);
        }
        cin>>comeco;

        start=0;

        caminho();
 
 //Chama o algoritmo de Kruskal para percorrer o grafo
        g.kruskal(start);
        
        if(g.soma>0&&seg==1){
        cout<<g.soma<<endl;
        }
        else{
        cout<<"Impossible"<<endl;
        }
        cin>>vertice;
        cin>>aresta;
    }

return 0;
}

