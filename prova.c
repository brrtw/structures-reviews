/*Componentes:
Francisco de Assis Martins Barreto
Laura Beatriz Nogueira Pessoa
Rian Martins de Paula
*/


#include "stdio.h"
#include "math.h"
#include "string.h"

typedef struct{
double n1, n2, n3;
} Notas;

typedef struct{
char nome[50];
char cidade[50];
double media;
Notas notas;
} Aluno;



int main(){
	Aluno alunos[5];
	int j;
	unsigned short int opcao = -1;

	while (opcao != 0) {
		printf("+------------------------------+\n");
		printf("|            ESCOLAR           |\n");
		printf("+------------------------------+\n");
		printf("| %-28s |\n", "1 - Cadastrar aluno");
		printf("| %-28s |\n", "2 - Visualizar geral");
		printf("| %-28s |\n", "3 - Atualizar notas de aluno");
		printf("| %-28s |\n", "4 - Listar aprovados");
		printf("| %-28s |\n", "5 - Listar reprovados");
		printf("| %-28s |\n", "0 - Sair");
		printf("+------------------------------+\n");
		printf("O que deseja fazer? ");
		scanf("%hu", &opcao);

		switch (opcao) {
		case 1: {
			printf("Em qual indice deseja adicionar o novo aluno (0-4): ");
			scanf("%d", &j);
			getchar();
			if (j < 0 || j >= 5) {
    		printf("Indice invalido\n");
			}
			else{
				printf("Informe o nome do aluno: ");
				fgets(alunos[j].nome, 50, stdin);
				printf("Informe a cidade do aluno: ");
				fgets(alunos[j].cidade, 50, stdin);
				printf("Informe as 3 notas respectivamente: ");
				scanf("%lf %lf %lf", &alunos[j].notas.n1, &alunos[j].notas.n2, &alunos[j].notas.n3);
				alunos[j].media = cbrt(alunos[j].notas.n1 * alunos[j].notas.n2 * alunos[j].notas.n3);
			}
			break;
		}
		case 2: {
			for(int i = 0; i<5; i++){
				printf("Aluno %d\n", i+1);
				printf("Nome: %s", alunos[i].nome);
				printf("Cidade: %s", alunos[i].cidade);
				printf("%.2lf | %.2lf | %.2lf\n", alunos[i].notas.n1, alunos[i].notas.n2, alunos[i].notas.n3);
				printf("Media: %.2lf\n", alunos[i].media);
			}
			break;
		}
		case 3: {
				int k;
				printf("Informe o indice do aluno que deseja alterar as notas (0-4): ");
				scanf("%d", &k);
				getchar();
				if (k < 0 || k >= 5){
    			printf("Indice invalido\n");
				}
				if (strcmp(alunos[k].nome, "\n") == 0 || strcmp(alunos[k].nome, " ") == 0) {
    			printf("Aluno vazio, nao ha como alterar notas\n");
				}
				else{
				printf("Informe as 3 novas notas: ");
				scanf("%lf %lf %lf", &alunos[k].notas.n1, &alunos[k].notas.n2, &alunos[k].notas.n3);
				alunos[k].media = cbrt(alunos[k].notas.n1 * alunos[k].notas.n2 * alunos[k].notas.n3);
				}
			break;
		}
		case 4: {
			for(int i= 0; i<5 ; i++){
				if(alunos[i].media >= 6){
					printf("Aluno %d\n", i+1);
					printf("Aluno aprovado\n");
				}
			}
			break;
		}
		case 5: {
			for(int i= 0; i<5 ; i++){
				if(alunos[i].media < 6){
					printf("Aluno %d\n", i+1);
					printf("Aluno reprovado\n");
				}
			}
			break;
		}
		case 0: {
			printf("Programa encerrado.");
			return 0;
			break;
		}
		default:
			break;
		}

	}
}