
/*
 * @author Ana Carolina Medeiros Gonçalves
 * Matricula: 591513
 * Turma: 01
 * Complexidade: Usando como operação relevante a inserção e o percorrimento dos valores
 * na matriz a complexidade será Θ(n^3*l2*c2)
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

  //Variaveis n=tamanho,m=operações,x=input
  int n;
  int m;
  int x;

  //Variaveis de linhas e colunas para pesquisa
  int l1,l2,c1,c2;

  //Varaiveis das cordenadas das azeitonas a inserir
  int olive1,olive2;

  //Contador de azeitonas
  int count=0;

  while(cin>>n){

    cin>>m;

    //Criação do array Matrix 
    vector<vector<int>> matrix(n, vector<int>(n));
    
    //Laço para inserir e armazenar valores na Matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>x;
            matrix[i][j]=x;
        }
    }
    
    //Laço de testes
    for(int e=0;e<m;e++){
        //Programa repete para limpar contador
        count=0;

        cin>>olive1;
      
        cin>>olive2;

        matrix[olive1-1][olive2-1]=1;

        cin>>l1;
        
        cin>>c1;
        
        cin>>l2;
        
        cin>>c2;
       
        //laço para contar Azeitonas no intervalo estipulado na entrada
        for(int i=l1-1;i<l2;i++){
            for(int j=c1-1;j<c2;j++){
                if(matrix[i][j]==1){
                    count++;  
                }
            }
        }
        //printar numero de azeitonas
        cout<<count<<endl;
    }
  }
  return 0;
}