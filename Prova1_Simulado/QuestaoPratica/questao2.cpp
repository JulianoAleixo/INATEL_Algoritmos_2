#include <iostream>
#include <string>
using namespace std;

struct Aluno {
    string nome;
    int matricula;
    float nota;
};

void ordena_alunos_por_nota(Aluno vetor[], int inicio, int fim){
    if (inicio < fim) {
        float pivo = vetor[(inicio + fim) / 2].nota;
        int i = inicio;
        int j = fim;
        Aluno aux;
        while (i <= j) {
            while (vetor[i].nota < pivo)
                i++;
            while (vetor[j].nota > pivo)
                j--;
            if (i <= j) {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
                i++;
                j--;
            }
        }
        ordena_alunos_por_nota(vetor, inicio, j);
        ordena_alunos_por_nota(vetor, i, fim);
    }
}

void ordena_alunos_por_matricula(Aluno vetor[], int inicio, int fim){
    if (inicio < fim) {
        int pivo = vetor[(inicio + fim) / 2].matricula;
        int i = inicio;
        int j = fim;
        Aluno aux;
        while (i <= j) {
            while (vetor[i].matricula < pivo)
                i++;
            while (vetor[j].matricula > pivo)
                j--;
            if (i <= j) {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
                i++;
                j--;
            }
        }
        ordena_alunos_por_matricula(vetor, inicio, j);
        ordena_alunos_por_matricula(vetor, i, fim);
    }
}

int busca_aluno(Aluno alunos[], int tamanho, int matricula_buscada){
    int inicio = 0, fim = tamanho - 1, metade;
    while (inicio <= fim) {
        metade = (inicio + fim) / 2;
        if (alunos[metade].matricula == matricula_buscada) {
            return metade;
        } else if (alunos[metade].matricula > matricula_buscada) {
            fim = metade - 1;
        } else {
            inicio = metade + 1;
        }
    }
    return -1;
}

int main(){
    int num_alunos;
    cin >> num_alunos;

    Aluno *alunos = new Aluno[num_alunos];

    for (int i = 0; i < num_alunos; i++) {
        cin >> alunos[i].matricula;
        cin.ignore();
        getline(cin, alunos[i].nome);
        alunos[i].nota = 0.0;
    }

    int num_exercicios, matricula;
    float nota;
    cin >> num_exercicios;

    for (int j = 0; j < (num_alunos * num_exercicios); j++) {
        cin >> matricula;
        cin >> nota;
        ordena_alunos_por_matricula(alunos, 0, num_alunos);
        int pos = busca_aluno(alunos, num_alunos, matricula);
        if (pos != -1) {
            if (alunos[pos].nota == 0)
                alunos[pos].nota = nota;
            else
                alunos[pos].nota = (alunos[pos].nota + nota) / 2.0;
        }
    }

    ordena_alunos_por_nota(alunos, 0, num_alunos - 1);

    for (int i = 3; i >= 0; i--) {
        cout << alunos[i].nome << ' ' << alunos[i].nota << endl;
    }
    delete[] alunos; // Liberando a memória alocada dinamicamente
}
