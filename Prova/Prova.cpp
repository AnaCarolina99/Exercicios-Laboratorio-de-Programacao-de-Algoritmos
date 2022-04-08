/*
 * @author Ana Carolina Medeiros Gonçalves
 * Matricula: 591513
 * Turma: 01
 * Complexidade: Complexidade: Usando como operação relevante a comparação entre os restos, ambos os casos a comlexidade continua a mesma, gerando Θ(x^2)
*/
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

double saida(int a[], double media, int resto, int t)
{
    int soma = 0;
    for (int i = 0; i < t; i++)
    {
        //Se valor maior que media, significa que pessoa pagou 
        //mais e tem que tirar o valor que ela pagou para aproximar valores
        if (a[i] > media)
        {
            //Resto serve para arrumar valores quando temos centavos dentro
            //da conta
            if (resto > 0)
            {
                soma += a[i] - media - 1;
                resto--;
            }
            else
            {
                soma += a[i] - media;
            }
        }
    }
    return soma;
}

int main()
{
    int x;
    cin >> x;
    while (x != 0)
    {
        int t, resto, total = 0;
        double d, media, soma = 0;
        int a[100];
        //Ler Valores que cada um gastou
        for (t = 0; t < x; t++)
        {
            cin >> d;
            a[t] = round(d * 100);
            total += a[t];
        }
        //Media dos Valores
        media = total / t;
        //cout<<media<<endl;
        //Resto de Valores
        resto = total % x;
        //cout<<resto<<endl;
        soma = 0;
        //Metodo soma onde é passado array,media,resto,tamanho
        soma = saida(a, media, resto, t);
        cout << '$' << fixed << setprecision(2) << soma / 100 << endl;
        cin >> x;
    }
}