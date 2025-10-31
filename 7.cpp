#include <iostream>
#include <string>
int idCurso = 1;
int matricula = 1;
int posCurso = 0;
int posAluno = 0;
using namespace std;


struct Curso{
    int id;
    string nome;
    int cargaHoraria;
    int vagas;
    int matriculados = 0;
};

struct Aluno{
    int matricula;
    string nome;
    int idade;
    Curso curso;

};

void cadastrarCurso(Curso *c){
    cout << "Digite o nome do curso: \n";
    cin.ignore();
    getline(cin, c->nome);
    cout << "Digite a carga horaria do curso: \n";
    cin >> c->cargaHoraria;
    cout << "Digite o numero de vagas: \n";
    cin >>c->vagas;
    c->id = idCurso;
    idCurso++;
}

void adicionarCurso(Curso vet[], Curso c){
    if(posCurso<=1000){
        vet[posCurso++] = c;
    }
    else{
        cout << "Lista cheia";
    }

}

void mostrarCursos(Curso vet[]){
    for(int i = 0; i<posCurso; i++){
        cout << "ID: " << vet[i].id<< endl;
        cout << "Nome: " << vet[i].nome << endl;
        cout << "Carga Horaria: " << vet[i].cargaHoraria<< endl;
        cout << "Vagas: " << vet[i].vagas << endl;
        cout << endl;
    }
}

Curso buscarCurso(int idCurso, Curso vet[]){
    for(int i = 0;i<posCurso;i++){
        int id = vet[i].id;
        if(idCurso == id){
                vet[i].matriculados++;
            return vet[i];

        }
    }

}
void cadastrarAluno(Aluno *a, Curso vet[]){
    cout << "Digite o nome do aluno: \n";
    cin.ignore();
    getline(cin, a->nome);
    cout << "Digite a idade do aluno: \n";
    cin >> a->idade;
    cout << "Digite o id do curso do aluno: \n";
    int idCurso = 0;
    cin >> idCurso;
    a->curso = buscarCurso(idCurso, vet);
    a->matricula = matricula;
    matricula++;
}


void adicionarAluno(Aluno vet[], Aluno a){
    if(posAluno<=1000){
        vet[posAluno++] = a;
    }
    else{
        cout << "Lista cheia";
    }

}

void mostrarAlunos(Aluno vet[]){
    for(int i = 0; i<posAluno; i++){
        cout << "Matricula: " << vet[i].matricula<< endl;
        cout << "Nome: " << vet[i].nome << endl;
        cout << "Idade: " << vet[i].idade<< endl;
        cout << "Curso: " << vet[i].curso.nome<< endl;
        cout << endl;
    }
}

void buscarAlunoPorCodigo(int id, Aluno vet[]){
    for(int i = 0;i<posAluno;i++){
        if(id == vet[i].curso.id){
            cout << "Nome: " << vet[i].nome << endl;
        }
    }

}
/*
for(int i = 0;i<posAluno;i++){
        int id;
        id = vetA[i].curso.id;
        for(int c = 0;i<posCurso;c++){
            if(id == vetC[c].id){
                vetC[c].matriculados++;
            }
        }
    }
*/

void relatorio(Curso vet[]){
    for(int i = 0;i<posCurso;i++){
        cout << "Curso: " << vet[i].nome << endl;
        cout << vet[i].matriculados << " alunos matriculados" << endl;

    }
}

void menu(){
    cout << ".............Menu.............\n";
    cout << "..(1)Cadastrar Curso..........\n";
    cout << "..(2)Cadastrar Aluno..........\n";
    cout << "..(3)Listar Cursos............\n";
    cout << "..(4)Listar Alunos............\n";
    cout << "..(5)Buscar Alunos por Curso..\n";
    cout << "..(6)Relatorio Geral..........\n";
    cout << "..(0)Sair.....................\n";
    cout << "\n";
    cout << "Digite sua opcao....";
    cout << endl;
}

int main(){
    Curso curso;
    Curso vetCurso[1000];
    Aluno aluno;
    Aluno vetAluno[1000];
    menu();
    int escolha;
    cin >> escolha;
    while(escolha != 0){
        switch(escolha){
            case 1:
                cadastrarCurso(&curso);
                adicionarCurso(vetCurso, curso);
                break;
            case 2:
                cadastrarAluno(&aluno, vetCurso);
                adicionarAluno(vetAluno, aluno);
                break;
            case 3:
                mostrarCursos(vetCurso);
                break;
            case 4:
                mostrarAlunos(vetAluno);
                break;
            case 5:
                cout << "Digite o codigo do curso para ser buscado: ";
                int cod;
                cin >> cod;
                buscarAlunoPorCodigo(cod, vetAluno);
                break;
            case 6:
                relatorio(vetCurso);
                break;
            default:
                cout << "Opcao Invalida" << endl;
        }
        menu();
        cin >> escolha;


    }


    return 0;
}

