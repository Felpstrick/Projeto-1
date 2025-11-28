#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#define MAX 2
int idCurso = 1;
int matricula = 1;
int idMateria = 1;
int posCurso = 0;
int posAluno = 0;
int posMateria =0;
using namespace std;






struct Curso{
    int id;
    char nome [100];
    int cargaHoraria;
    int vagas;
    int matriculados = 0;
};

struct Aluno{
    int matricula;
    char nome [100];
    int idade;
    Curso curso;

};

struct Materia{
    int id;
    char nome [100];
    Curso curso;
};

void cadastrarCurso(Curso *c){
    cout << "Digite o nome do curso: \n";
    cin.ignore();
    cin.getline(c->nome, 100);
    cout << "Digite a carga horaria do curso: \n";
    cin >> c->cargaHoraria;
    cout << "Digite o numero de vagas: \n";
    cin >>c->vagas;
    c->id = idCurso;
    idCurso++;
}

void adicionarCurso(Curso vet[], Curso c){
    if(posCurso<=MAX){
        vet[posCurso++] = c;
        strcpy(vet[posCurso].nome, vet[posCurso].nome);
    }
    else{
        cout << "Lista cheia";
    }

}

void mostrarCursos(Curso vet[], Materia vtm[]){
    for(int i = 0; i<posCurso; i++){
        cout << "ID: " << vet[i].id<< endl;
        cout << "Nome: " << vet[i].nome << endl;
        cout << "Carga Horaria: " << vet[i].cargaHoraria<< endl;
        cout << "Vagas: " << vet[i].vagas << endl;
        cout << "Materias cadastradas" << endl;
        for (int m = 0; m<posMateria; m++){
            int idm = vtm[m].curso.id;
            if(idm == vet[i].id){
                cout << vtm[m].nome << endl;
            }
        }
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
    cin.getline(a->nome, 100);
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



void cadastrarMateria(Materia *m, Curso vet[]){
    cout << "Digite o nome da materia: \n";
    cin.ignore();
    cin.getline(m->nome, 100);
    cout << "Digite o id do curso que a materia pertence: \n";
    int idCurso = 0;
    cin >> idCurso;
    m->curso = buscarCurso(idCurso, vet);
    m->id = idMateria;
    idMateria++;
}
void adicionarMateria(Materia vet[], Materia m){
    if(posMateria<=1000){
        vet[posMateria++] = m;
        strcpy(vet[posMateria].nome, vet[posMateria].nome);
    }
    else{
        cout << "Lista cheia";
    }

}

void relatorio(Curso vet[]){
    for(int i = 0;i<posCurso;i++){
        cout << "Curso: " << vet[i].nome << endl;
        cout << vet[i].matriculados << " alunos matriculados" << endl;

    }
}

void salvar(Curso vet[], Aluno veta[], Materia vetm[]) {
    fstream curso;
    fstream aluno;
    fstream materia;

    curso.open("curso.bin", ios::out | ios::binary);
    aluno.open("aluno.bin", ios::out | ios::binary);
    materia.open("materia.bin", ios::out | ios::binary);

    if(curso.is_open() && aluno.is_open() && materia.is_open()) {
        curso.write((char *) &posCurso, sizeof(int));
        aluno.write((char *) &posAluno, sizeof(int));
        materia.write((char *) &posMateria, sizeof(int));
        curso.write((char *) vet, sizeof(Curso) * posCurso);
        aluno.write((char *) veta, sizeof(Aluno) * posAluno);
        materia.write((char *) vetm, sizeof(Materia) * posMateria);
        curso.close();
        aluno.close();
        materia.close();
        cout << "Informacoes salvas com sucesso!!\n";
    }
    else {
        cout << "Falha ao gravar informacoes.\n";
    }
}

void carregar(Curso vet[], Aluno veta[], Materia vetm[]) {
    fstream curso;
    fstream aluno;
    fstream materia;

    curso.open("curso.bin", ios::in | ios::binary);
    aluno.open("aluno.bin", ios::in | ios::binary);
    materia.open("materia.bin", ios::in | ios::binary);


   if(curso.is_open() && aluno.is_open() && materia.is_open()) {
        curso.read((char *) &posCurso, sizeof(int));
        aluno.read((char *) &posAluno, sizeof(int));
        materia.read((char *) &posMateria, sizeof(int));
        curso.read((char *) vet, sizeof(Curso) * posCurso);
        aluno.read((char *) veta, sizeof(Aluno) * posAluno);
        materia.read((char *) vetm, sizeof(Materia) * posMateria);
        curso.close();
        aluno.close();
        materia.close();
        cout << "Informacoes carregadas com sucesso!!\n";
    } else {
        cout << "Falha ao carregar informacoes.\n";
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
    cout << "..(7)Cadastrar Materia........\n";
    cout << "..(8)Salvar Informacoes.......\n";
    cout << "..(9)Carregar Informacoes.....\n";
    cout << "..(0)Sair.....................\n";
    cout << "\n";
    cout << "Digite sua opcao....";
    cout << endl;
}

int main(){
    Curso curso;
    Curso vetCurso[MAX];
    Aluno aluno;
    Aluno vetAluno[MAX];
    Materia materia;
    Materia vetMateria[MAX];
    menu();

    int n = 1;
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
                mostrarCursos(vetCurso, vetMateria);
                cout << posCurso;
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
            case 7:
                cadastrarMateria(&materia, vetCurso);
                adicionarMateria(vetMateria, materia);
                break;
            case 8:
                salvar(vetCurso, vetAluno, vetMateria);
                break;
            case 9:
                carregar(vetCurso, vetAluno, vetMateria);
                break;
            default:
                cout << "Opcao Invalida" << endl;
        }
        menu();
        cin >> escolha;


    }


    return 0;
}

