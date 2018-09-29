//TRABALHO 1 - Estrutura de dados
//Aluno: Lucas de Paula
//Linguagem: C++
//Objetivo:
//1 - Criar uma classe “Matriz” que encapsula a memória alocada dinamicamente para uma matriz mxn. 
//2 - Fazer “overload” do operador “[]”!

#include <iostream>

using namespace std;

class Matriz
{
    public: 
    
        Matriz(int l, int c)
        {
            mat = new int*[l];
            for (i=0; i < l; i++)
            {
                mat[i] = new int[c];
            }
            m = l;
            n = c;
        };
        
        void valorMatrix()
        {
            for (i = 0; i < m; i++)
            {
                for (j =0; j < n; j++)
                {
                    mat[i][j] = i + j;
                }
            }
        };
        
        void imprimeMatriz()
        {
            for (i = 0; i < m; i++)
            {
                for (j =0; j < n; j++)
                {
                   cout << mat[i][j] << " ";
                }
                cout << endl;
            }
        };
        
        int *operator [] (int valor)
        {
               return mat[valor];
        };
        
        ~Matriz()
        {
            for (i = 0; i < n; i++)
            {
                delete mat[i];
            }
            delete[] mat;
        };
        
    private:
        int **mat;
        int i, j;
        int n, m;
};

int main()
{
    int l, c;
    
    cout << "Entre com o número de linhas: " << endl;
    cin  >> l;
    cout << "Entre com o número de colunas: " << endl;
    cin >> c;
    
    Matriz matrix(l, c);
    
    matrix.valorMatrix();
    
    matrix.imprimeMatriz();
    
    return 0;
}