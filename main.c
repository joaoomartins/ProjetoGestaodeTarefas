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

int menu(){
    printf(" ***************************************************************\n");
    printf("**---------------------- MENU PRINCIPAL ---------------------- **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
    printf("**                             **                              **\n");
    printf("**   {1} - Funcionarios        **     {2} - Tarefas            **\n");
    printf("**                             **                              **\n");
    printf("**   {3} - Estatisticas        **     {4} - Gravar             **\n");
    printf("**                             **                              **\n");
    printf("**   {5} - Gravar/Sair         **     {0} - Sair               **\n");
    printf("**                             **                              **\n");
    printf(" ***************************************************************\n");
    
    return 0;
}

int funcionarios(){
    printf(" ********************************************************************\n");
    printf("**----------------------- MENU FUNCIONARIOS -----------------------**\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
    printf("**                                **                               **\n");
    printf("**   {1} - Inserir Funcionarios   **     {2} - Listar Funcionarios **\n");
    printf("**                                **                               **\n");
    printf("**   {3} - Editar Funcionario     **     {4} - Apagar Funcionario  **\n");
    printf("**                                **                               **\n");
    printf("**                           {0} - Sair                            **\n");
    printf("**                                **                               **\n");
    printf(" *******************************************************************\n");
    
	return 0;
}

int tarefas(){
    printf(" ******************************************************************\n");
    printf("**------------------------- MENU TAREFAS ------------------------**\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
    printf("**                               **                              **\n");
    printf("**   {1} - Inserir Tarefas       **     {2} - Listar Tarefas     **\n");
    printf("**                               **                              **\n");
    printf("**   {3} - Editar Tarefas        **     {4} - Apagar Tarefas     **\n");
    printf("**                               **                              **\n");
    printf("**                          {0} - Sair                           **\n");
    printf("**                               **                              **\n");
    printf(" *****************************************************************\n");
    
    return 0;
}

int apagar(){
    printf(" ******************************************************************\n");
    printf("**---------------------- APAGAR FUNCIONARIOS --------------------**\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
    printf("**|   ID   |                 NOME                 |**\n");
    for (int i = 0; i < TAM_EMPLOYEES; i++)
    {
        if (employees[i].id != 0)
        {
            printf("**|   %d   |                 %c                 |**\n", employees[i].id, employees[i].name);
        }
    }
    printf(" *****************************************************************\n");
    
    return 0;
}

int resumo(){
    printf(" ***************************************************************\n");
    printf("**-------------------- Resumo das Tarefas -------------------- **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
    printf("**    Tarefa do dia:                                           **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
    printf("**    Descricao:                                               **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
    printf("**    Numero de ordem:                                         **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
    printf("**    Horas:                                                   **\n");
    printf("**                                                             **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
    
    return 0;
    
}

int fichaFuncionarios() {
    printf(" ***************************************************************\n");
    printf("**-------------------- Ficha Funcionarios -------------------- **\n");
    printf("**------------------ Numero de ordem: 1234 --------------------**\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
    printf("**    Ficha do Funcionario: (Nome do Funcionario)              **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
    printf("**    Data de Nascimento: 12/12/1234                           **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
    printf("**    Telemovel: 123456789                                     **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
    printf("**    Email:                                                   **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
    printf("**    Localidade:                                              **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
    printf("**    Departamento:                                            **\n");
    printf("**                                                             **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
    
    return 0;
}

int fichaTarefas() {
    printf(" **************************************************************** \n");
    printf("**-------------------------- Tarefas -------------------------- **\n");
    printf("**------------------- Numero de ordem: 1234 --------------------**\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
    printf("**    Data: 12/12/1234                                          **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
    printf("**    Hora: hh:mm                                               **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
    printf("**    Descricao:                                                **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
    printf("**    Frequencia:                                               **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
    printf("**    Estado:                                                   **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
    printf("**    Funcionario:                                              **\n");
    printf("**                                                              **\n");
    printf(" ***************************************************************\n");
}

int estatisticas(){
    printf(" **************************************************************** \n");
    printf("**------------------------ Estatisticas ----------------------- **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
    printf("**    Numero de Funcionarios:                                   **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
    printf("**    Numero de Tarefas:                                        **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
    printf("**    Tarefas Abertas:                                          **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
    printf("**    Memoria Livre Funcionarios:                               **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
    printf("**    Memoria Livre Tarefas:                                    **\n");
    printf("**                                                              **\n");
    printf(" ***************************************************************\n");
}

int getEmployees(){
    printf(" **************************************************************** \n");
    printf("**------------------------ Funcionarios ----------------------- **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
    printf("**    ID:                                                       **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
    printf("**    Nome do Funcionario:                                      **\n");
    printf("**                                                              **\n");
    printf(" ***************************************************************\n");
}

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

//TODO Fazer uma funcao que procura o ultimo ID ocupado e adiciona 1
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
			
			return 1;
		}
	}
	
	return 0;
}

int insertFileEmployee(FILE *employeFile) {
    for (int i = 0; i < TAM_EMPLOYEES; i++)
    {
        if (employees[i].id != 0)
        {
            fprintf(employeFile, "ola\n");
        }
        
    }
    
}

int insertFileTask(FILE * taskFile) {
    for (int i = 0; i < TAM_TASKS; i++)
    {
        if (tasks[i].id != 0)
        {
            fprintf(taskFile, "Adeus\n");
        }
        
    }
    
}

int main() {
	FILE *employeFile, *taskFile;

	employeFile = fopen("./employeesTable.txt", "w");
	
	taskFile = fopen("./tasksTable.txt", "w");

    insertFileEmployee(employeFile);

    insertFileTask(taskFile);
	
    return 0;
}
