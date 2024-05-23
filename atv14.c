// Questão 1

#include <stdio.h>

struct Horario {
    int hora;
    int minuto;
    int segundo;
};

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Compromisso {
    struct Data data;
    struct Horario horario;
    char descricao[100];
};

int main() {
    struct Horario horario = {10, 30, 0}; 
    struct Data data = {22, 5, 2024};
    struct Compromisso compromisso = {data, horario, "Comer pipoca doce com coca-cola"};

    
    printf("Compromisso: %s\n", compromisso.descricao);
    printf("Data: %02d/%02d/%d\n", compromisso.data.dia, compromisso.data.mes, compromisso.data.ano);
    printf("Horario: %02d:%02d:%02d\n", compromisso.horario.hora, compromisso.horario.minuto, compromisso.horario.segundo);

    return 0;
}

// Questão 2
#include <stdio.h>

#define MAX_LENGTH 100

struct Pessoa {
    char nome[MAX_LENGTH];
    int idade;
    char endereco[MAX_LENGTH];
};

int main() {
    struct Pessoa pessoa; 

    printf("Digite o nome da pessoa: ");
    fgets(pessoa.nome, MAX_LENGTH, stdin); 

    printf("Digite a idade da pessoa: ");
    scanf("%d", &pessoa.idade);
    
    printf("Digite o endereco da pessoa: ");
    getchar(); 
    fgets(pessoa.endereco, MAX_LENGTH, stdin);

    printf("\nDados da pessoa:\n");
    printf("Nome: %s", pessoa.nome);
    printf("Idade: %d\n", pessoa.idade);
    printf("Endereco: %s", pessoa.endereco);

    return 0;
}

// Questão 3
#include <stdio.h>

#define MAX_LENGHTH 100

struct Aluno {
    char nome[MAX_LENGHTH];
    int matricula;
    char curso[MAX_LENGHTH];
};

int main() {
    struct Aluno alunos[5];

    for(int i = 0; i < 5; i++){
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);

        printf("Digite o numero da matricula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);

        while (getchar() != '\n');

        printf("Digite o curso do aluno %d: ", i + 1);
        scanf("%s", alunos[i].curso);
    }  

    printf("\nDados dos alunos:\n");

    for (int i = 0; i < 5; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Curso: %s\n", alunos[i].curso);
    }
    
    return 0;
}

// Questão 4
#include <stdio.h>

#define NUM_ALUNOS 5

struct Aluno {
    int matricula;
    char nome[100];
    float nota1;
    float nota2;
    float nota3;
    float media;
};

float calcularMedia(struct Aluno aluno) {
    return (aluno.nota1 + aluno.nota2 + aluno.nota3) / 3.0;
}

int main() {
    struct Aluno alunos[NUM_ALUNOS];
    float maiorNota1 = 0;
    float maiorMedia = 0;
    int indiceMaiorNota1 = 0;
    int indiceMaiorMedia = 0;

    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("Digite a matricula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);

        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);

        printf("Digite a nota da primeira prova do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota1);

        printf("Digite a nota da segunda prova do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota2);

        printf("Digite a nota da terceira prova do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota3);

        alunos[i].media = calcularMedia(alunos[i]);

        if (alunos[i].nota1 > maiorNota1) {
            maiorNota1 = alunos[i].nota1;
            indiceMaiorNota1 = i;
        }

        if (alunos[i].media > maiorMedia) {
            maiorMedia = alunos[i].media;
            indiceMaiorMedia = i;
        }

        printf("\n");
    }

    printf("Aluno com maior nota na primeira prova:\n");
    printf("Matricula: %d\n", alunos[indiceMaiorNota1].matricula);
    printf("Nome: %s\n", alunos[indiceMaiorNota1].nome);
    printf("Nota da primeira prova: %.2f\n", alunos[indiceMaiorNota1].nota1);
    printf("\n");

    printf("Aluno com maior media geral:\n");
    printf("Matricula: %d\n", alunos[indiceMaiorMedia].matricula);
    printf("Nome: %s\n", alunos[indiceMaiorMedia].nome);
    printf("Media geral: %.2f\n", alunos[indiceMaiorMedia].media);
    printf("\n");

    printf("Situacao dos alunos:\n");
    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("Aluno %s - ", alunos[i].nome);
        if (alunos[i].media >= 6) {
            printf("Aprovado\n");
        } else {
            printf("Reprovado\n");
        }
    }

    return 0;
}

// Questão 5
#include <stdio.h>

struct Vetor {
    float x;
    float y;
    float z;
};

int main() {
    struct Vetor vetor1, vetor2, soma;

    printf("Digite as coordenadas do primeiro vetor (x y z): ");
    scanf("%f %f %f", &vetor1.x, &vetor1.y, &vetor1.z);

    printf("Digite as coordenadas do segundo vetor (x y z): ");
    scanf("%f %f %f", &vetor2.x, &vetor2.y, &vetor2.z);

    soma.x = vetor1.x + vetor2.x;
    soma.y = vetor1.y + vetor2.y;
    soma.z = vetor1.z + vetor2.z;

    printf("A soma dos vetores resulta em: %.2f %.2f %.2f\n", soma.x, soma.y, soma.z);

    return 0;
}

// Questão 6
#include <stdio.h>

#define MAX_ALUNOS 10

struct Aluno {
    int matricula;
    char nome[100];
    int codigoDisciplina;
    float nota1;
    float nota2;
    float mediaFinal;
};

int main() {
    struct Aluno alunos[MAX_ALUNOS];
    int numAlunos;

    printf("Digite o número de alunos (até %d): ", MAX_ALUNOS);
    scanf("%d", &numAlunos);

    for (int i = 0; i < numAlunos; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Matrícula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Nome: ");
        scanf("%s", alunos[i].nome);

        printf("Código da Disciplina: ");
        scanf("%d", &alunos[i].codigoDisciplina);

        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);

        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);

        alunos[i].mediaFinal = (alunos[i].nota1 * 1.0 + alunos[i].nota2 * 2.0) / 3.0;
        printf("\n");
    }

    printf("\nLista de Alunos e Médias Finais:\n");
    for (int i = 0; i < numAlunos; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Matrícula: %d\n", alunos[i].matricula);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Código da Disciplina: %d\n", alunos[i].codigoDisciplina);
        printf("Nota 1: %.2f\n", alunos[i].nota1);
        printf("Nota 2: %.2f\n", alunos[i].nota2);
        printf("Média Final: %.2f\n", alunos[i].mediaFinal);
        printf("\n");
    }

    return 0;
}

// Questão 7
#include <stdio.h>

#define MAX_LENGTH 30

struct Funcionario {
    char nome[MAX_LENGTH];
    int idade;
    char sexo;
    char cpf[12];
    char dataNascimento[11];
    int codigoSetor;
    char cargo[MAX_LENGTH];
    float salario;
};

int main() {
    struct Funcionario funcionario;

    printf("Digite o nome do funcionario: ");
    scanf("%s", funcionario.nome);

    printf("Digite a idade do funcionario: ");
    scanf("%d", &funcionario.idade);

    printf("Digite o sexo do funcionario (M/F): ");
    scanf(" %c", &funcionario.sexo);

    printf("Digite o CPF do funcionario: ");
    scanf("%s", funcionario.cpf);

    printf("Digite a data de nascimento do funcionario (DD/MM/AAAA): ");
    scanf("%s", funcionario.dataNascimento);

    printf("Digite o codigo do setor onde trabalha (0-99): ");
    scanf("%d", &funcionario.codigoSetor);

    printf("Digite o cargo que o funcionario ocupa (ate %d caracteres): ", MAX_LENGTH);
    scanf("%s", funcionario.cargo);

    printf("Digite o salario do funcionario: ");
    scanf("%f", &funcionario.salario);

    printf("\nDados do Funcionario:\n");
    printf("Nome: %s\n", funcionario.nome);
    printf("Idade: %d\n", funcionario.idade);
    printf("Sexo: %c\n", funcionario.sexo);
    printf("CPF: %s\n", funcionario.cpf);
    printf("Data de Nascimento: %s\n", funcionario.dataNascimento);
    printf("Codigo do Setor: %d\n", funcionario.codigoSetor);
    printf("Cargo: %s\n", funcionario.cargo);
    printf("Salario: %.2f\n", funcionario.salario);

    return 0;
}

// Questão 8
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100
#define NUM_PESSOAS 5

struct Pessoa {
    char nome[MAX_LENGTH];
    char endereco[MAX_LENGTH];
    char telefone[MAX_LENGTH];
};

int main() {
    struct Pessoa pessoas[NUM_PESSOAS];
    int i, j;
    struct Pessoa temp;

    for (i = 0; i < NUM_PESSOAS; i++) {
        printf("Digite o nome da pessoa %d: ", i + 1);
        scanf("%s", pessoas[i].nome);

        printf("Digite o endereco da pessoa %d: ", i + 1);
        scanf("%s", pessoas[i].endereco);

        printf("Digite o telefone da pessoa %d: ", i + 1);
        scanf("%s", pessoas[i].telefone);
    }

    for (i = 0; i < NUM_PESSOAS - 1; i++) {
        for (j = i + 1; j < NUM_PESSOAS; j++) {
            if (strcmp(pessoas[i].nome, pessoas[j].nome) > 0) {
                temp = pessoas[i];
                pessoas[i] = pessoas[j];
                pessoas[j] = temp;
            }
        }
    }

    printf("\nDados das pessoas em ordem alfabetica:\n");
    for (i = 0; i < NUM_PESSOAS; i++) {
        printf("Nome: %s, Endereco: %s, Telefone: %s\n", pessoas[i].nome, pessoas[i].endereco, pessoas[i].telefone);
    }

    return 0;
}

// Questão 9
#include <stdio.h>

#define NUM_ALUNOS 10
#define MAX_LENGTH 100

struct Aluno {
    char nome[MAX_LENGTH];
    int matricula;
    float mediaFinal;
};

int main() {
    struct Aluno alunos[NUM_ALUNOS], aprovados[NUM_ALUNOS], reprovados[NUM_ALUNOS];
    int numAprovados = 0, numReprovados = 0;

    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);

        printf("Digite a matricula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);

        printf("Digite a media final do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].mediaFinal);

        if (alunos[i].mediaFinal >= 5.0) {
            aprovados[numAprovados] = alunos[i];
            numAprovados++;
        } else {
            reprovados[numReprovados] = alunos[i];
            numReprovados++;
        }
    }

    printf("\nAlunos Aprovados:\n");
    for (int i = 0; i < numAprovados; i++) {
        printf("Nome: %s, Matricula: %d, Media Final: %.2f\n", aprovados[i].nome, aprovados[i].matricula, aprovados[i].mediaFinal);
    }

    printf("\nAlunos Reprovados:\n");
    for (int i = 0; i < numReprovados; i++) {
        printf("Nome: %s, Matricula: %d, Media Final: %.2f\n", reprovados[i].nome, reprovados[i].matricula, reprovados[i].mediaFinal);
    }

    return 0;
}

// Questão 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARTAS 52
#define NUM_JOGADORES 2
#define CARTAS_POR_JOGADOR 5

char *naipes[] = {"Paus", "Ouros", "Copas", "Espadas"};
char *valores[] = {"Ás", "Dois", "Três", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"};

struct Carta {
    int naipe;
    int valor;
};

void inicializarBaralho(struct Carta *baralho) {
    int i, j, k = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 13; j++) {
            baralho[k].naipe = i;
            baralho[k].valor = j;
            k++;
        }
    }
}

void embaralharCartas(struct Carta *baralho) {
    int i, j;
    struct Carta temp;
    for (i = 0; i < NUM_CARTAS; i++) {
        j = rand() % NUM_CARTAS;
        temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

void distribuirCartas(struct Carta *baralho, struct Carta mao[][CARTAS_POR_JOGADOR]) {
    int i, j, k = 0;
    for (i = 0; i < CARTAS_POR_JOGADOR; i++) {
        for (j = 0; j < NUM_JOGADORES; j++) {
            mao[j][i] = baralho[k++];
        }
    }
}

void exibirMao(struct Carta mao[]) {
    for (int i = 0; i < CARTAS_POR_JOGADOR; i++) {
        printf("%s de %s\n", valores[mao[i].valor], naipes[mao[i].naipe]);
    }
    printf("\n");
}

int main() {
    struct Carta baralho[NUM_CARTAS];
    struct Carta mao[NUM_JOGADORES][CARTAS_POR_JOGADOR];

    srand(time(NULL));

    inicializarBaralho(baralho);
    embaralharCartas(baralho);
    distribuirCartas(baralho, mao);

    printf("Jogador 1:\n");
    exibirMao(mao[0]);

    printf("Jogador 2:\n");
    exibirMao(mao[1]);

    return 0;
}

// Questão 11
#include <stdio.h>
#include <string.h>

#define MAX_CARROS 5
#define MAX_MARCA 15

struct Carro {
    char marca[MAX_MARCA];
    int ano;
    float preco;
};

int main() {
    struct Carro carros[MAX_CARROS];
    float p;

    for (int i = 0; i < MAX_CARROS; i++) {
        printf("Digite a marca do carro %d: ", i + 1);
        scanf("%s", carros[i].marca);

        printf("Digite o ano do carro %d: ", i + 1);
        scanf("%d", &carros[i].ano);

        printf("Digite o preco do carro %d: ", i + 1);
        scanf("%f", &carros[i].preco);
    }

    do {
        printf("\nDigite um valor para p (0 para sair): ");
        scanf("%f", &p);

        if (p != 0) {
            printf("\nCarros com preco menor que %.2f:\n", p);
            for (int i = 0; i < MAX_CARROS; i++) {
                if (carros[i].preco < p) {
                    printf("Marca: %s, Ano: %d, Preco: %.2f\n", carros[i].marca, carros[i].ano, carros[i].preco);
                }
            }
        }
    } while (p != 0);

    return 0;
}

// Questão 12
#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 5
#define MAX_TITULO 30
#define MAX_AUTOR 15

struct Livro {
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int ano;
};

int main() {
    struct Livro livros[MAX_LIVROS];
    char busca[MAX_TITULO];
    int encontrados = 0;

    for (int i = 0; i < MAX_LIVROS; i++) {
        printf("Digite o titulo do livro %d: ", i + 1);
        scanf("%s", livros[i].titulo);

        printf("Digite o autor do livro %d: ", i + 1);
        scanf("%s", livros[i].autor);

        printf("Digite o ano do livro %d: ", i + 1);
        scanf("%d", &livros[i].ano);
    }

    printf("\nDigite o titulo do livro que deseja buscar: ");
    scanf("%s", busca);

    printf("\nLivros encontrados com o titulo '%s':\n", busca);
    for (int i = 0; i < MAX_LIVROS; i++) {
        if (strcmp(livros[i].titulo, busca) == 0) {
            printf("Titulo: %s, Autor: %s, Ano: %d\n", livros[i].titulo, livros[i].autor, livros[i].ano);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum livro encontrado com o titulo '%s'\n", busca);
    }

    return 0;
}

// Questão 13
#include <stdio.h>

#define MAX_ELETRODOMESTICOS 5
#define MAX_NOME 15

struct Eletrodomestico {
    char nome[MAX_NOME];
    float potencia; // em kW
    float tempoAtivo; // em horas
};

int main() {
    struct Eletrodomestico eletrodomesticos[MAX_ELETRODOMESTICOS];
    float tempoTotal, consumoTotal = 0.0;

    for (int i = 0; i < MAX_ELETRODOMESTICOS; i++) {
        printf("Digite o nome do eletrodomestico %d: ", i + 1);
        scanf("%s", eletrodomesticos[i].nome);

        printf("Digite a potencia do eletrodomestico %d (em kW): ", i + 1);
        scanf("%f", &eletrodomesticos[i].potencia);

        printf("Digite o tempo ativo por dia do eletrodomestico %d (em horas): ", i + 1);
        scanf("%f", &eletrodomesticos[i].tempoAtivo);
    }

    printf("\nDigite o tempo em dias: ");
    scanf("%f", &tempoTotal);

    for (int i = 0; i < MAX_ELETRODOMESTICOS; i++) {
        consumoTotal += eletrodomesticos[i].potencia * eletrodomesticos[i].tempoAtivo * tempoTotal;
    }

    printf("\nConsumo total na casa: %.2f kW\n", consumoTotal);
    printf("\nConsumo relativo de cada eletrodomestico:\n");
    for (int i = 0; i < MAX_ELETRODOMESTICOS; i++) {
        float consumoRelativo = (eletrodomesticos[i].potencia * eletrodomesticos[i].tempoAtivo * tempoTotal) / consumoTotal * 100.0;
        printf("Eletrodomestico %d: %.2f%%\n", i + 1, consumoRelativo);
    }

    return 0;
}

// Questão 14
#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 5
#define MAX_NOME 15

struct Produto {
    int codigo;
    char nome[MAX_NOME];
    float preco;
    int quantidade;
};

int main() {
    struct Produto produtos[MAX_PRODUTOS];
    int codigoPedido, quantidadePedido;

    for (int i = 0; i < MAX_PRODUTOS; i++) {
        printf("Digite o codigo do produto %d: ", i + 1);
        scanf("%d", &produtos[i].codigo);

        printf("Digite o nome do produto %d: ", i + 1);
        scanf("%s", produtos[i].nome);

        printf("Digite o preco do produto %d: ", i + 1);
        scanf("%f", &produtos[i].preco);

        printf("Digite a quantidade do produto %d: ", i + 1);
        scanf("%d", &produtos[i].quantidade);
    }

    do {
        printf("\nDigite o codigo do produto do pedido (ou zero para sair): ");
        scanf("%d", &codigoPedido);

        if (codigoPedido != 0) {
            printf("Digite a quantidade do produto do pedido: ");
            scanf("%d", &quantidadePedido);

            int encontrado = 0;
            for (int i = 0; i < MAX_PRODUTOS; i++) {
                if (produtos[i].codigo == codigoPedido) {
                    encontrado = 1;
                    if (produtos[i].quantidade >= quantidadePedido) {
                        produtos[i].quantidade -= quantidadePedido;
                        printf("Pedido atendido com sucesso!\n");
                    } else {
                        printf("Erro: Quantidade insuficiente em estoque.\n");
                    }
                    break;
                }
            }
            if (!encontrado) {
                printf("Erro: Produto nao encontrado.\n");
            }
        }
    } while (codigoPedido != 0);

    return 0;
}

// Questão 15
#include <stdio.h>
#include <string.h>

#define MAX_RECEITAS 5
#define MAX_NOME 25
#define MAX_INGREDIENTES 10

struct Ingrediente {
    char nome[MAX_NOME];
    int quantidade;
};

struct Receita {
    char nome[MAX_NOME];
    int quantidadeIngredientes;
    struct Ingrediente ingredientes[MAX_INGREDIENTES];
};

int main() {
    struct Receita receitas[MAX_RECEITAS];
    char busca[MAX_NOME];

    for (int i = 0; i < MAX_RECEITAS; i++) {
        printf("Digite o nome da receita %d: ", i + 1);
        scanf("%s", receitas[i].nome);

        printf("Digite a quantidade de ingredientes da receita %d: ", i + 1);
        scanf("%d", &receitas[i].quantidadeIngredientes);

        for (int j = 0; j < receitas[i].quantidadeIngredientes; j++) {
            printf("Digite o nome do ingrediente %d: ", j + 1);
            scanf("%s", receitas[i].ingredientes[j].nome);

            printf("Digite a quantidade do ingrediente %d: ", j + 1);
            scanf("%d", &receitas[i].ingredientes[j].quantidade);
        }
    }
    do {
        printf("\nDigite o nome da receita que deseja buscar (ou string vazia para sair): ");
        scanf("%s", busca);

        if (strlen(busca) > 0) {
            int encontrada = 0;
            for (int i = 0; i < MAX_RECEITAS; i++) {
                if (strcmp(receitas[i].nome, busca) == 0) {
                    encontrada = 1;
                    printf("Receita encontrada:\n");
                    printf("Nome: %s\n", receitas[i].nome);
                    printf("Ingredientes:\n");
                    for (int j = 0; j < receitas[i].quantidadeIngredientes; j++) {
                        printf("- %s: %d\n", receitas[i].ingredientes[j].nome, receitas[i].ingredientes[j].quantidade);
                    }
                    break;
                }
            }
            if (!encontrada) {
                printf("Receita nao encontrada.\n");
            }
        }
    } while (strlen(busca) > 0);

    return 0;
}

// Questão 16
#include <stdio.h>
#include <string.h>

#define MAX_DIRETORES 5
#define MAX_NOME 20
#define MAX_FILMES 10

struct Filme {
    char nome[MAX_NOME];
    int ano;
    int duracao;
};

struct Diretor {
    char nome[MAX_NOME];
    int quantidadeFilmes;
    struct Filme filmes[MAX_FILMES];
};

int main() {
    struct Diretor diretores[MAX_DIRETORES];
    char busca[MAX_NOME];

    for (int i = 0; i < MAX_DIRETORES; i++) {
        printf("Digite o nome do diretor %d: ", i + 1);
        scanf("%s", diretores[i].nome);

        printf("Digite a quantidade de filmes do diretor %d: ", i + 1);
        scanf("%d", &diretores[i].quantidadeFilmes);

        for (int j = 0; j < diretores[i].quantidadeFilmes; j++) {
            printf("Digite o nome do filme %d: ", j + 1);
            scanf("%s", diretores[i].filmes[j].nome);

            printf("Digite o ano do filme %d: ", j + 1);
            scanf("%d", &diretores[i].filmes[j].ano);

            printf("Digite a duracao do filme %d: ", j + 1);
            scanf("%d", &diretores[i].filmes[j].duracao);
        }
    }
    do {
        printf("\nDigite o nome do diretor que deseja buscar (ou string vazia para sair): ");
        scanf("%s", busca);

        if (strlen(busca) > 0) {
            int encontrado = 0;
            for (int i = 0; i < MAX_DIRETORES; i++) {
                if (strcmp(diretores[i].nome, busca) == 0) {
                    encontrado = 1;
                    printf("Diretor encontrado:\n");
                    printf("Nome: %s\n", diretores[i].nome);
                    printf("Filmes produzidos:\n");
                    for (int j = 0; j < diretores[i].quantidadeFilmes; j++) {
                        printf("- %s (%d), Duracao: %d minutos\n", diretores[i].filmes[j].nome, diretores[i].filmes[j].ano, diretores[i].filmes[j].duracao);
                    }
                    break;
                }
            }
            if (!encontrado) {
                printf("Diretor nao encontrado.\n");
            }
        }
    } while (strlen(busca) > 0);

    return 0;
}

// Questão 17
#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 100
#define MAX_NOME 50
#define MAX_EMAIL 50
#define MAX_ENDERECO 100
#define MAX_TELEFONE 15
#define MAX_OBSERVACOES 100

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Endereco {
    char rua[MAX_ENDERECO];
    int numero;
    char complemento[MAX_ENDERECO];
    char bairro[MAX_ENDERECO];
    char cep[MAX_ENDERECO];
    char cidade[MAX_ENDERECO];
    char estado[MAX_ENDERECO];
    char pais[MAX_ENDERECO];
};

struct Contato {
    char nome[MAX_NOME];
    char email[MAX_EMAIL];
    struct Endereco endereco;
    char telefone[MAX_TELEFONE];
    struct Data aniversario;
    char observacoes[MAX_OBSERVACOES];
};

struct Agenda {
    struct Contato contatos[MAX_CONTATOS];
    int numContatos;
};

void buscaPorNome(struct Agenda agenda, char nome[]);
void buscaPorMesAniversario(struct Agenda agenda, int mes);
void buscaPorDiaMesAniversario(struct Agenda agenda, int dia, int mes);
void insereContato(struct Agenda *agenda, struct Contato novoContato);
void retiraContato(struct Agenda *agenda, char nome[]);
void imprimeAgenda(struct Agenda agenda);

int main() {
    struct Agenda agenda = { .numContatos = 0 };
    int opcao;
    
    do {
        printf("\nMenu Principal:\n");
        printf("1. Buscar por nome\n");
        printf("2. Buscar por mes de aniversario\n");
        printf("3. Buscar por dia e mes de aniversario\n");
        printf("4. Inserir contato\n");
        printf("5. Retirar contato\n");
        printf("6. Imprimir agenda\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: {
                char nomeBusca[MAX_NOME];
                printf("Digite o nome a ser buscado: ");
                scanf("%s", nomeBusca);
                buscaPorNome(agenda, nomeBusca);
                break;
            }
            case 2: {
                int mesBusca;
                printf("Digite o mes de aniversario a ser buscado: ");
                scanf("%d", &mesBusca);
                buscaPorMesAniversario(agenda, mesBusca);
                break;
            }
            case 3: {
                int diaBusca, mesBusca;
                printf("Digite o dia de aniversario a ser buscado: ");
                scanf("%d", &diaBusca);
                printf("Digite o mes de aniversario a ser buscado: ");
                scanf("%d", &mesBusca);
                buscaPorDiaMesAniversario(agenda, diaBusca, mesBusca);
                break;
            }
            case 4: {
                struct Contato novoContato;
                printf("Digite o nome do novo contato: ");
                scanf("%s", novoContato.nome);
                printf("Digite o email do novo contato: ");
                scanf("%s", novoContato.email);
                printf("Digite o endereco do novo contato:\n");
                printf("Rua: ");
                scanf("%s", novoContato.endereco.rua);
                printf("Numero: ");
                scanf("%d", &novoContato.endereco.numero);
                printf("Complemento: ");
                scanf("%s", novoContato.endereco.complemento);
                printf("Bairro: ");
                scanf("%s", novoContato.endereco.bairro);
                printf("CEP: ");
                scanf("%s", novoContato.endereco.cep);
                printf("Cidade: ");
                scanf("%s", novoContato.endereco.cidade);
                printf("Estado: ");
                scanf("%s", novoContato.endereco.estado);
                printf("Pais: ");
                scanf("%s", novoContato.endereco.pais);
                printf("Digite o telefone do novo contato: ");
                scanf("%s", novoContato.telefone);
                printf("Digite o dia de aniversario do novo contato: ");
                scanf("%d", &novoContato.aniversario.dia);
                printf("Digite o mes de aniversario do novo contato: ");
                scanf("%d", &novoContato.aniversario.mes);
                printf("Digite o ano de aniversario do novo contato: ");
                scanf("%d", &novoContato.aniversario.ano);
                printf("Digite observacoes especiais do novo contato: ");
                scanf("%s", novoContato.observacoes);
                insereContato(&agenda, novoContato);
                break;
            }
            case 5: {
                char nomeRetira[MAX_NOME];
                printf("Digite o nome do contato a ser retirado: ");
                scanf("%s", nomeRetira);
                retiraContato(&agenda, nomeRetira);
                break;
            }
            case 6: {
                imprimeAgenda(agenda);
                break;
            }
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
        
    } while (opcao != 0);
    
    return 0;
}

void buscaPorNome(struct Agenda agenda, char nome[]) {
    printf("Resultados da busca por nome '%s':\n", nome);
    for (int i = 0; i < agenda.numContatos; i++) {
        if (strcmp(agenda.contatos[i].nome, nome) == 0) {
            printf("Nome: %s\n", agenda.contatos[i].nome);
            printf("Email: %s\n", agenda.contatos[i].email);
            printf("Endereco: %s, %d - %s, %s, %s, %s, %s, %s\n", agenda.contatos[i].endereco.rua, agenda.contatos[i].endereco.numero, agenda.contatos[i].endereco.complemento, agenda.contatos[i].endereco.bairro, agenda.contatos[i].endereco.cep, agenda

.contatos[i].endereco.cidade, agenda.contatos[i].endereco.estado, agenda.contatos[i].endereco.pais);
            printf("Telefone: %s\n", agenda.contatos[i].telefone);
            printf("Data de aniversario: %d/%d/%d\n", agenda.contatos[i].aniversario.dia, agenda.contatos[i].aniversario.mes, agenda.contatos[i].aniversario.ano);
            printf("Observacoes: %s\n", agenda.contatos[i].observacoes);
            printf("\n");
        }
    }
}

void buscaPorMesAniversario(struct Agenda agenda, int mes) {
    printf("Resultados da busca por mes de aniversario %d:\n", mes);
    for (int i = 0; i < agenda.numContatos; i++) {
        if (agenda.contatos[i].aniversario.mes == mes) {
            printf("Nome: %s\n", agenda.contatos[i].nome);
            printf("Email: %s\n", agenda.contatos[i].email);
            printf("Endereco: %s, %d - %s, %s, %s, %s, %s, %s\n", agenda.contatos[i].endereco.rua, agenda.contatos[i].endereco.numero, agenda.contatos[i].endereco.complemento, agenda.contatos[i].endereco.bairro, agenda.contatos[i].endereco.cep, agenda.contatos[i].endereco.cidade, agenda.contatos[i].endereco.estado, agenda.contatos[i].endereco.pais);
            printf("Telefone: %s\n", agenda.contatos[i].telefone);
            printf("Data de aniversario: %d/%d/%d\n", agenda.contatos[i].aniversario.dia, agenda.contatos[i].aniversario.mes, agenda.contatos[i].aniversario.ano);
            printf("Observacoes: %s\n", agenda.contatos[i].observacoes);
            printf("\n");
        }
    }
}

void buscaPorDiaMesAniversario(struct Agenda agenda, int dia, int mes) {
    printf("Resultados da busca por dia %d e mes %d de aniversario:\n", dia, mes);
    for (int i = 0; i < agenda.numContatos; i++) {
        if (agenda.contatos[i].aniversario.dia == dia && agenda.contatos[i].aniversario.mes == mes) {
            printf("Nome: %s\n", agenda.contatos[i].nome);
            printf("Email: %s\n", agenda.contatos[i].email);
            printf("Endereco: %s, %d - %s, %s, %s, %s, %s, %s\n", agenda.contatos[i].endereco.rua, agenda.contatos[i].endereco.numero, agenda.contatos[i].endereco.complemento, agenda.contatos[i].endereco.bairro, agenda.contatos[i].endereco.cep, agenda.contatos[i].endereco.cidade, agenda.contatos[i].endereco.estado, agenda.contatos[i].endereco.pais);
            printf("Telefone: %s\n", agenda.contatos[i].telefone);
            printf("Data de aniversario: %d/%d/%d\n", agenda.contatos[i].aniversario.dia, agenda.contatos[i].aniversario.mes, agenda.contatos[i].aniversario.ano);
            printf("Observacoes: %s\n", agenda.contatos[i].observacoes);
            printf("\n");
        }
    }
}

void insereContato(struct Agenda *agenda, struct Contato novoContato) {
    int i;
    for (i = 0; i < agenda->numContatos; i++) {
        if (strcmp(novoContato.nome, agenda->contatos[i].nome) < 0) {
            break;
        }
    }
    
    for (int j = agenda->numContatos; j > i; j--) {
        agenda->contatos[j] = agenda->contatos[j - 1];
    }
    
    agenda->contatos[i] = novoContato;
    agenda->numContatos++;
    
    printf("Contato inserido com sucesso!\n");
}

void retiraContato(struct Agenda *agenda, char nome[]) {
    int i;
    for (i = 0; i < agenda->numContatos; i++) {
        if (strcmp(nome, agenda->contatos[i].nome) == 0) {
            for (int j = i; j < agenda->numContatos - 1; j++) {
                agenda->contatos[j] = agenda->contatos[j + 1];
            }
            agenda->numContatos--;
            printf("Contato retirado com sucesso!\n");
            return;
        }
    }
    printf("Contato nao encontrado.\n");
}

void imprimeAgenda(struct Agenda agenda) {
    printf("Agenda:\n");
    for (int i = 0; i < agenda.numContatos; i++) {
        printf("Nome: %s\n", agenda.contatos[i].nome);
        printf("Telefone: %s\n", agenda.contatos[i].telefone);
        printf("Email: %s\n", agenda.contatos[i].email);
        printf("\n");
    }
}