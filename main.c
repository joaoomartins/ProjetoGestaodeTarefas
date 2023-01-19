#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define TAM_TASKS 1000
#define TAM_EMPLOYEES 100
#define TAM_BIRTHDATE 9
#define TAM_NAME_EMPLOYEES 255
#define TAM_EMAIL 255
#define TAM_CELLPHONE 9
#define TAM_PLACE 255
#define TAM_DEPARTMENT 50
#define TAM_DATE 10
#define TAM_HOUR 5
#define TAM_DESCRIPTION 255

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
    int option;
    
    system("cls");

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

    printf("Opcao:");
    scanf("%d", &option);
    return option;   
}

int timer() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("%02d-%02d-%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    return 0;
}

int menuEmployees(){
    int option;
    
    system("cls");
    
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

    printf("Opcao:");
    scanf("%d", &option);
    return option;
}

int menuTasks(){
    int option;
    
    system("cls");

    printf(" *****************************************************************\n");
    printf("**------------------------- MENU TAREFAS ------------------------**\n");
    printf("                             ");
    timer();
    printf("\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
    printf("**                               **                              **\n");
    printf("**   {1} - Inserir Tarefas       **     {2} - Listar Tarefas     **\n");
    printf("**                               **                              **\n");
    printf("**   {3} - Editar Tarefas        **     {4} - Apagar Tarefas     **\n");
    printf("**                               **                              **\n");
    printf("**                          {0} - Sair                           **\n");
    printf("**                               **                              **\n");
    printf(" *****************************************************************\n");

    printf("Opcao:");
    scanf("%d", &option);
    return option;
}

int getEmployees(){

    int idEmployee;

    system("cls");

    printf(" ******************************************************************\n");
    printf("**------------------------- FUNCIONARIOS ------------------------**\n");
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
    
    printf("Introduza o ID do Funcionario:");
    scanf("%d", &idEmployee);
    
    return idEmployee;
}

int listEmployees(){

    system("cls");

    printf(" ******************************************************************\n");
    printf("**------------------------- FUNCIONARIOS ------------------------**\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
    printf("**|   ID   |                 NOME                 |              **\n");
    for (int i = 0; i < TAM_EMPLOYEES; i++)
    {
        if (employees[i].id != 0)
        {
            printf("**|   %d   |                 %c                 |**\n", employees[i].id, employees[i].name);
        }
    }
    printf(" *****************************************************************\n");
    
    system("pause");
    return 0;
}

int resume(){
	
	system("cls");
	
    printf(" ***************************************************************\n");
    printf("**-------------------- Resumo das Tarefas -------------------- **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
    printf("**    Tarefa do dia: ");   
    timer();
    printf("                                **\n");
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

int getEmployeesInfo() {
	
	system("cls");
	
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

int getTaksInfo() {
	
	system("cls");
	
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
    return 0;
}

int countEmployees() {
    
    int count = 0;

    for (int i = 0; i < TAM_EMPLOYEES; i++)
    {
        if (employees[i].id != 0)
        {
            count += 1;
        }
        
    }
    return count;
}

int countTasks() {
    
    int count = 0;

    for (int i = 0; i < TAM_TASKS; i++)
    {
        if (tasks[i].id != 0)
        {
            count += 1;
        }
        
    }
    return count;
}

int stats(){

    system("cls");

    int countNumEmployees = countEmployees(), countNumTasks = countTasks();

    printf(" **************************************************************** \n");
    printf("**------------------------ Estatisticas ----------------------- **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
    printf("**    Numero de Funcionarios: %d                                **\n", countNumEmployees); 
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
    printf("**    Numero de Tarefas: %d                                     **\n",countNumTasks);
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
    printf("**    Tarefas Abertas:                                          **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
    printf("**    Memoria Livre Funcionarios: %d                            **\n", TAM_EMPLOYEES - countNumEmployees);
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
    printf("**    Memoria Livre Tarefas: %d                                **\n", TAM_TASKS - countNumTasks);
    printf("**                                                              **\n");
    printf(" ***************************************************************\n");
    system("pause");
    return 0;
}

// Se esta funcao retornar 1 significa que conseguiu inserir o funcionario com sucesso
// Se retornar 0 significa que ja nao ha espaco para mais funcionarios
int insertEmployee(){
	for (int i = 0; i < TAM_EMPLOYEES; i++) {
		if (employees[i].id == 0) {
			fflush(stdin);
			printf("\nIntroduza o nome do funcionario: ");
			fgets(employees[i].name, TAM_NAME_EMPLOYEES, stdin);
			fflush(stdin);
			
			printf("\nIntroduza a data de nascimento do funcionario no formato (dd-mm-aaaa): ");
			scanf("%c", &employees[i].birthdate);
			fgets(employees[i].birthdate, TAM_BIRTHDATE, stdin);
			fflush(stdin);
			
			printf("\nIntroduza o numero de telemovel do funcionario (so sao aceitos formatos de numeros portugueses): ");
			fgets(employees[i].numCellphone, TAM_CELLPHONE, stdin);
			fflush(stdin);
			
			printf("\nIntroduza o email do funcionario: ");
			fgets(employees[i].email, TAM_EMAIL, stdin);
			fflush(stdin);
			
			printf("\nIntroduza o nome do departamento do funcionario: ");
			fgets(employees[i].department, TAM_DEPARTMENT, stdin);
			
			return 1;
		}
		
	}
	
	printf("\nAcabei");
	system("pause");
	
	return 0;
}

//Se a funcao retornar 0 e porque nao encontrou o ID do funcinario
//Se retornar 1 significa que editou o funcionario com sucesso
int editEmployee(int idEmployee){
	for (int i = 0; i < TAM_EMPLOYEES; i++) {
		if (employees[i].id == idEmployee) {
			fflush(stdin);
			
			printf("\nIntroduza o nome do funcionario: ");
			fgets(employees[i].name, TAM_NAME_EMPLOYEES, stdin);
			fflush(stdin);
			
			printf("\nIntroduza a data de nascimento do funcionario no formato (dd-mm-aaaa): ");
			scanf("%c", &employees[i].birthdate);
			fgets(employees[i].birthdate, TAM_BIRTHDATE, stdin);
			fflush(stdin);
			
			printf("\nIntroduza o numero de telemovel do funcionario (so sao aceitos formatos de numeros portugueses): ");
			fgets(employees[i].numCellphone, TAM_CELLPHONE, stdin);
			fflush(stdin);
			
			printf("\nIntroduza o email do funcionario: ");
			fgets(employees[i].email, TAM_EMAIL, stdin);
			fflush(stdin);
			
			printf("\nIntroduza o nome do departamento do funcionario: ");
			fgets(employees[i].department, TAM_DEPARTMENT, stdin);
			
			employees[i].id = i;
			
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
			fflush(stdin);
			
			printf("\nIntroduza a data da tarefa no formato (dd-mm-aaaa): ");
			fgets(tasks[i].date, TAM_DATE, stdin);
			fflush(stdin);
			
			printf("\nIntroduza a hora da tarefa no formato (hh:mm): ");
			fgets(tasks[i].hour, TAM_HOUR, stdin);
			fflush(stdin);
			
			printf("\nIntroduza a descricao da tarefa: ");
			fgets(tasks[i].description, TAM_DESCRIPTION, stdin);
			fflush(stdin);
			
			printf("\nIntroduza o tipo de frequencia que quer que a sua tarefa tenha");
			printf("\n0 = Pontual\n1 = Mensal:");
			scanf("%d", &tasks[i].frequency);
			fflush(stdin);
			
			tasks[i].eStatus = 1; // Quando a tarefa e criada o estado e aberto
			tasks[i].id = i;
      
			return 1;
		}
	}
	
	return 0;
}

int insertFileEmployee(FILE *employeeFile) {
    for (int i = 0; i < TAM_EMPLOYEES; i++)
    {
        if (employees[i].id != 0)
        {
            fprintf(employeeFile, "%d\n", i);
            fprintf(employeeFile, "%c\n", employees[i].name);
            fprintf(employeeFile, "%c\n", employees[i].email);
            fprintf(employeeFile, "%c\n", employees[i].birthdate);
            fprintf(employeeFile, "%c\n", employees[i].numCellphone);
            fprintf(employeeFile, "%c\n", employees[i].place);
            fprintf(employeeFile, "%c\n", employees[i].department);
            fprintf(employeeFile, "\n");
        }
        
    }
    
}

int insertFileTask(FILE *taskFile) {
	for (int i = 0; i < TAM_TASKS; i++) {
		if (tasks[i].id != 0) {
			fprintf(taskFile, "%d\n", i);
			fprintf(taskFile, "%c\n", tasks[i].date);
			fprintf(taskFile, "%c\n", tasks[i].hour);
			fprintf(taskFile, "%c\n", tasks[i].description);
			fprintf(taskFile, "%i\n", tasks[i].frequency);
			fprintf(taskFile, "%i\n", tasks[i].eStatus);
			fprintf(taskFile, "%i\n", tasks[i].fkIdEmployee);
			fprintf(taskFile, "\n");
		}
	}
    return 0;
}

int main() {
	int option = 10, optionEmployee = 10, optionTasks = 10, idEmployee;
  	FILE *employeFile, *taskFile;

	employeFile = fopen("./employeesTable.txt", "w");
	
	taskFile = fopen("./tasksTable.txt", "w");

    while (option != 0)
    {
        fflush(stdin);

        option = menu();

        switch (option)
        {
        case 0:
            break;
            
        case 1:
            while (optionEmployee != 0)
            {
            	fflush(stdin);
            	
            	optionEmployee = menuEmployees();
            	
                switch (optionEmployee)
                {

                    case 0:
                        break;
                    case 1:
                        insertEmployee();
                        break;
                        
                    case 2:
                        listEmployees();
                        break;
                        
                    case 3:
                        idEmployee = getEmployees();
                        editEmployee(idEmployee);
                        break;
                        
                    case 4:
                        idEmployee = getEmployees();
                        deleteEmployee(idEmployee);
                        break;            
                        
	                default:
	                    printf("\nOpcao invalida, introduza uma opcao valida!");
	                    system("pause");
	                    break;
                }
            }
            break;
        case 2:
            while (optionTasks != 0)
            {
            	
            	fflush(stdin);
            	
            	optionTasks = menuTasks();
            	
                switch (optionTasks)
                {               	
	                case 0:
                        break;
                    case 1:
	                    insertTask();
	                    break;
	                    
	                case 2:
	                	break;
	                	
	                case 3:
	                	break;
	                	
	                case 4:
	                	break;
	                
	                default:
	                	printf("\nOpcao invalida, introduza uma opcao valida!");
	                    system("pause");
	                    break;
                }
            }
            
            break;
        case 3:
            stats();
            break;
        case 4:
            break;
        case 5:
            break;            
        default:
            printf("\nOpcao invalida, introduza uma opcao valida!");
            system("pause");
            break;
        }
    }
    return 0;
}
