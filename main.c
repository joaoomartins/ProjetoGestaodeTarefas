#include <stdio.h>
#define TAM_TASKS 1000
#define TAM_EMPLOYEES 100

struct tasksTable {
	int id;
	char date[10];
	char hour[5];
	char description[255];
	int frequency;
	int eStatus;
	int fkIdEmployee;
};

struct employeeTable {
	int id;
	char name[255];
	char birthdate[10];
	char numCellphone[9];
	char email[255];
	char place[255];
	char department[50];
};

struct employeeTable employees[TAM_EMPLOYEES];
struct tasksTable tasks[TAM_TASKS];

// Se esta funcao retornar 1 significa que conseguiu inserir o funcionario com sucesso
// Se retornar 0 significa que ja nao ha espaco para mais funcionarios
int insertEmployee(){
	for (int i = 0; i < TAM_EMPLOYEES; i++) {
		if (employees[i].id == 0) {
			printf("\nIntroduza o nome do funcionario: ");
			scanf("%d", &employees[i].name);
			printf("\nIntroduza a data de nascimento do funcionario no formato (dd-mm-aaaa): ");
			scanf("%d-%d-%d", &employees[i].birthdate);
			printf("\nIntroduza o numero de telemovel do funcionario (so sao aceitos formatos de numeros portugueses): ");
			scanf("%c", &employees[i].numCellphone);
			printf("\nIntroduza o email do utilizador: ");
			scanf("%c", &employees[i].email);
			printf("\nIntroduza o nome do departamento do funcionario: ");
			scanf("%c", employees[i].department);
			
			return 1;
		}
	}
	
	return 0;
}

//Se a funcao retornar 0 e porque nao encontrou o ID do funcinario
//Se retornar 1 significa que editou o funcionario com sucesso
int editEmployee(int idEmployee){
	for (int i = 0; i < TAM_EMPLOYEES; i++) {
		if (employees[i].id == idEmployee) {
			printf("\nIntroduza o novo nome do funcionario: ");
			scanf("%d", &employees[i].name);
			printf("\nIntroduza a nova data de nascimento do funcionario no formato (dd-mm-aaaa): ");
			scanf("%d-%d-%d", &employees[i].birthdate);
			printf("\nIntroduza o novo numero de telemovel do funcionario (so sao aceitos formatos de numeros portugueses): ");
			scanf("%c", &employees[i].numCellphone);
			printf("\nIntroduza o novo email do utilizador: ");
			scanf("%c", &employees[i].email);
			printf("\nIntroduza o novo nome do departamento do funcionario: ");
			scanf("%c", employees[i].department);
			
			return 1;
		}
	}
	
	return 0;
}

//Se a funcao retornar 0 e porque nao encontrou o ID do funcinario
//Se retornar 1 significa que apagar o funcionario com sucesso
int deleteEmployee(int idEmployee) {
	for (int i = 0; i < TAM_EMPLOYEES; i++) {
		if (employees[i].id == idEmployee) {
			employees[i].id = 0;
			
			return 1;
		}
	}
	
	return 0;
}

int insertTask() {
	for (int i = 0; i < TAM_TASKS; i++) {
		if (tasks[i].id == 0) {
			printf("\nIntroduza a data da tarefa no formato (dd-mm-aaaa): ");
			scanf("%c", &tasks[i].date);
			printf("\nIntroduza a hora da tarefa no formato (hh:mm): ");
			scanf("%c", &tasks[i].hour);
			printf("\nIntroduza a descricao da tarefa: ");
			scanf("%c", &tasks[i].description);
			printf("\nIntroduza o tipo de frequencia que quer que a sua tarefa tenha");
			printf("\n0 = Pontual\n1 = Mensal:");
			scanf("%d", tasks[i].frequency);
			tasks[i].eStatus = 1; // Quando a tarefa e criada o estado e aberto
		}
	}
}

int main() {
	
    return 0;
}
