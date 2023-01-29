#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define TAM_TASKS 1000
#define TAM_EMPLOYEES 100
#define TAM_BIRTHDATE 11
#define TAM_NAME_EMPLOYEES 255
#define TAM_EMAIL 255
#define TAM_CELLPHONE 10
#define TAM_PLACE 255
#define TAM_DEPARTMENT 50
#define TAM_DATE 11
#define TAM_HOUR 6
#define TAM_DESCRIPTION 255

int biggestIDTasks, biggestIDEmployees;

struct tasksTable {
	int id;
	char date[TAM_DATE];
	char hour[TAM_HOUR];
	char description[TAM_DESCRIPTION];
	int frequency;
	int eStatus;
	int fkIdEmployee;
};

struct employeeTable {
	int id;
	char name[TAM_NAME_EMPLOYEES];
	char birthdate[TAM_BIRTHDATE];
	char numCellphone[TAM_CELLPHONE];
	char email[TAM_EMAIL];
	char place[TAM_PLACE];
	char department[TAM_DEPARTMENT];
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
    printf("**   {5} - Editar Status         **     {0} - Sair               **\n");
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
            printf("**|   %d   |                 %s                 |**\n", employees[i].id, employees[i].name);
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
            printf("**|   %d   |                 %s                 |**\n", employees[i].id, employees[i].name);
        }
    }
    printf(" *****************************************************************\n");
    
    system("pause");
    return 0;
}

int listTasks() {
	
	system("cls");
	
    printf(" ***************************************************************************\n");
    printf("**--------------------------------- Tarefas -------------------------------**\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
    printf("**|   ID   |                NOME                |       ID FUNCIONARIO       |**\n");
    for (int i = 0; i < TAM_TASKS; i++)
    {

        if (tasks[i].id != 0)
        {
            printf("**|   %d   |               %s               |        %s         |**\n", tasks[i].id, tasks[i].description, employees[i].name);

        }
    }
    printf(" **************************************************************************\n");
    system("pause");
    return 0;
}

int getTasks(){

    int idTask;

    system("cls");

    printf(" ******************************************************************\n");
    printf("**------------------------- TAREFAS ------------------------**\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
    printf("**|   ID   |                 NOME                 |    STATUS   |**\n");
    for (int i = 0; i < TAM_TASKS; i++)
    {
        if (tasks[i].id != 0)
        {
            printf("**|   %d   |                 %s                 |   %d**\n", tasks[i].id, tasks[i].description, tasks[i].eStatus);
        }
    }
    printf("**                                                              **\n");
    printf("**              Status : 0 = Fechado e 1 = Aberto               **\n");
    printf(" *****************************************************************\n");

    
    printf("Introduza o ID da Tarefa:");
    scanf("%d", &idTask);
    
    return idTask;
}

int editStatusTasks(int idTasks){

    for (int i = 0; i < TAM_TASKS; i++)
    {
        if (tasks[i].id == idTasks)
        {
            if (tasks[i].eStatus == 0)
            {
                tasks[i].eStatus = 1;

                return 1;
            }
            else {
                tasks[i].eStatus = 0;
                
                return 1;
            }
            
        }
    }
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

int getTasksInfo() {
	
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

int countOpenTasks(){
    
    int count = 0;

    for (int i = 0; i < TAM_TASKS; i++)
    {
        if (tasks[i].eStatus != 0)
        {
            count += 1;
        }
    }
    return count;
}

int stats(){

    system("cls");

    int countNumEmployees = countEmployees(), countNumTasks = countTasks(), countNumOpenTasks = countOpenTasks();

    printf(" **************************************************************** \n");
    printf("**------------------------ Estatisticas ----------------------- **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
    printf("**    Numero de Funcionarios: %d                                **\n", countNumEmployees); 
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
    printf("**    Numero de Tarefas: %d                                     **\n",countNumTasks);
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
    printf("**    Tarefas Abertas: %d                                       **\n", countNumOpenTasks);
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
			strtok(employees[i].name, "\n");
			fflush(stdin);
			
			
			printf("\nIntroduza a data de nascimento do funcionario no formato (dd-mm-aaaa): ");
			fgets(employees[i].birthdate, TAM_BIRTHDATE, stdin);
			strtok(employees[i].birthdate, "\n");
			fflush(stdin);
			
			
			printf("\nIntroduza o numero de telemovel do funcionario (so sao aceitos formatos de numeros portugueses): ");
			fgets(employees[i].numCellphone, TAM_CELLPHONE, stdin);
			strtok(employees[i].numCellphone, "\n");
			fflush(stdin);
			
			
			printf("\nIntroduza o email do funcionario: ");
			fgets(employees[i].email, TAM_EMAIL, stdin);
			strtok(employees[i].email, "\n");
			fflush(stdin);
			
			
            printf("\nIntroduza a localidade do funcionario: ");
            fgets(employees[i].place, TAM_PLACE, stdin);
            strtok(employees[i].place, "\n");
            fflush(stdin);


			printf("\nIntroduza o nome do departamento do funcionario: ");
			fgets(employees[i].department, TAM_DEPARTMENT, stdin);
			strtok(employees[i].department, "\n");
            fflush(stdin);
			
			employees[i].id = biggestIDEmployees + 1;
			
			biggestIDEmployees += 1;
			
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
			fflush(stdin);
			
			printf("\nIntroduza o nome do funcionario: ");
			fgets(employees[i].name, TAM_NAME_EMPLOYEES, stdin);
			strtok(employees[i].name, "\n");
			fflush(stdin);
			
			printf("\nIntroduza a data de nascimento do funcionario no formato (dd-mm-aaaa): ");
			fgets(employees[i].birthdate, TAM_BIRTHDATE, stdin);
			strtok(employees[i].birthdate, "\n");
			fflush(stdin);
			
			printf("\nIntroduza o numero de telemovel do funcionario (so sao aceitos formatos de numeros portugueses): ");
			fgets(employees[i].numCellphone, TAM_CELLPHONE, stdin);
			strtok(employees[i].numCellphone, "\n");
			fflush(stdin);
			
			printf("\nIntroduza o email do funcionario: ");
			fgets(employees[i].email, TAM_EMAIL, stdin);
			strtok(employees[i].email, "\n");
			fflush(stdin);
			
			printf("\nIntroduza a localidade do funcionario: ");
            fgets(employees[i].place, TAM_PLACE, stdin);
            strtok(employees[i].place, "\n");
            fflush(stdin);
			
			printf("\nIntroduza o nome do departamento do funcionario: ");
			fgets(employees[i].department, TAM_DEPARTMENT, stdin);
			strtok(employees[i].department, "\n");
			
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
			strtok(tasks[i].date, "\n");
			fflush(stdin);
			
			printf("\nIntroduza a hora da tarefa no formato (hh:mm): ");
			fgets(tasks[i].hour, TAM_HOUR, stdin);
			strtok(tasks[i].hour, "\n");
			fflush(stdin);
			
			printf("\nIntroduza a descricao da tarefa: ");
			fgets(tasks[i].description, TAM_DESCRIPTION, stdin);
			strtok(tasks[i].description, "\n");
			fflush(stdin);
			
			printf("\nIntroduza o tipo de frequencia que quer que a sua tarefa tenha");
			printf("\n0 = Pontual\n1 = Mensal:");
			scanf("%d", &tasks[i].frequency);
			fflush(stdin);
			
			int idEmployee = getEmployees();
			
			tasks[i].fkIdEmployee = idEmployee;
			
			tasks[i].eStatus = 1; // Quando a tarefa e criada o estado e aberto
			tasks[i].id = biggestIDTasks + 1;
			
			biggestIDTasks += 1;
      
			return 1;
		}
	}
	
	return 0;
}

int editTasks(int idTask){
	for (int i = 0; i < TAM_EMPLOYEES; i++) {
		if (tasks[i].id == idTask) {
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
			
			return 1;
		}
	}
	
	return 0;
}

int deleteTask(int idTask) {
	for (int i = 0; i < TAM_TASKS; i++) {
		if (tasks[i].id == idTask) {
			tasks[i].id = 0;
			
			return 1;
		}
	}
	
	return 0;
}

int insertFileEmployee(FILE *employeeFile) {
	int employeeInsertion = 0;
	
	employeeFile = fopen("./employeesTable.txt", "w");
	
    for (int i = 0; i < TAM_EMPLOYEES; i++) {
        if (employees[i].id != 0) {
            fprintf(employeeFile, "%d\n", employees[i].id);
            fprintf(employeeFile, "%s\n", employees[i].name);
            fprintf(employeeFile, "%s\n", employees[i].email);
            fprintf(employeeFile, "%s\n", employees[i].birthdate);
            fprintf(employeeFile, "%s\n", employees[i].numCellphone);
            fprintf(employeeFile, "%s\n", employees[i].place);
            fprintf(employeeFile, "%s\n", employees[i].department);
            
            employeeInsertion = 1;
        }
        
    }
    
    return employeeInsertion;
}

int insertFileTask(FILE *taskFile) {
	int taskInsertion = 0;
	
	taskFile = fopen("./tasksTable.txt", "w");
	
	for (int i = 0; i < TAM_TASKS; i++) {
		if (tasks[i].id != 0) {
			fprintf(taskFile, "%d\n", tasks[i].id);
			fprintf(taskFile, "%s\n", tasks[i].date);
			fprintf(taskFile, "%s\n", tasks[i].hour);
			fprintf(taskFile, "%s\n", tasks[i].description);
			fprintf(taskFile, "%d\n", tasks[i].frequency);
			fprintf(taskFile, "%d\n", tasks[i].eStatus);
			fprintf(taskFile, "%d\n", tasks[i].fkIdEmployee);			

			taskInsertion = 1;
		}
	}
    return taskInsertion;
}

int insertBiggestIdTasks(FILE *IDTasksTable) {
	
	IDTasksTable = fopen("./IDsTasksTable.txt", "w");
	
	fprintf(IDTasksTable, "%d", biggestIDTasks);
	
	return 1;
	
}

int insertBiggestIdEmployees(FILE *IDsEmployeesTable) {
	
	IDsEmployeesTable = fopen("./IDsEmployeesTable.txt", "w");
	
	fprintf(IDsEmployeesTable, "%d", biggestIDEmployees);
	
	return 1;
	
}

//A ideia e que as funcoes acima retornem 1 se o insert funcionar e 0 caso nao tenha sido possivel guardar os novos dados
int save(FILE *employeeFile, FILE *taskFile, FILE *IDsEmployeesTable, FILE *IDsTasksTable) {
	int employeeInsertion = 0, taskInsertion = 0, biggesIdTasksInsertion = 0, biggesIdEmployeesInsertion = 0;
	
	employeeInsertion = insertFileEmployee(employeeFile);
	
	taskInsertion = insertFileTask(taskFile);
	
	biggesIdTasksInsertion = insertBiggestIdTasks(IDsTasksTable);
	
	biggesIdEmployeesInsertion = insertBiggestIdEmployees(IDsEmployeesTable);
	
	if (employeeInsertion == 1 || taskInsertion == 1 || biggesIdTasksInsertion == 1 || biggesIdEmployeesInsertion == 1) {
		return 1;
	}
	
	return 0;
}

//TO DO: Quando se grava a 1º vez ele guarda os dados, se guardamos a 2º vez ele vai repetir os dados
// IF para resolver erro xD

int main() {
	int option = 10, optionEmployee = 10, optionTasks = 10, idEmployee, sizeEmployeFile, sizeTaskFile, saveReturn = 0, idTask = 0;
  	FILE *employeFile, *taskFile, *IDTasksTable, *IDsEmployeesTable;
  	char line[255];
  	
	employeFile = fopen("./employeesTable.txt", "r");
	
	taskFile = fopen("./tasksTable.txt", "r");
	
	IDsEmployeesTable = fopen("./IDsEmployeesTable.txt", "r");
	
	IDTasksTable = fopen("./IDsTasksTable.txt", "r");
	
	if (IDTasksTable == NULL) {
		IDTasksTable = fopen("./IDsTasksTable.txt", "w");
		
	} else {
		fscanf(IDTasksTable, "%d", &biggestIDTasks);
	}
	
	if (IDsEmployeesTable == NULL) {
		IDsEmployeesTable = fopen("./IDsEmployeesTable.txt", "w");
		
	} else {
		fscanf(IDsEmployeesTable, "%d", &biggestIDEmployees);
	}
	
	if (employeFile == NULL) {
		employeFile = fopen("./employeesTable.txt", "w");
		
	} else {
		for (int i = 0; i < TAM_EMPLOYEES; i++) {
	        fscanf(employeFile, "%d", &employees[i].id);
			fscanf(employeFile, " %[^\n]", employees[i].name);
			fscanf(employeFile, " %[^\n]", employees[i].birthdate);
			fscanf(employeFile, " %[^\n]", employees[i].numCellphone);
			fscanf(employeFile, " %[^\n]", employees[i].email);
			fscanf(employeFile, " %[^\n]", employees[i].place);
			fscanf(employeFile, " %[^\n]", employees[i].department);
	    }
	}
		
	if (taskFile == NULL) {
		taskFile = fopen("./tasksTable.txt", "w");
		
	} else {
	    for (int i = 0; i < TAM_TASKS; i++) {
	        fscanf(taskFile, "%d", &tasks[i].id);
			fscanf(taskFile, " %[^\n]", tasks[i].date);
			fscanf(taskFile, " %[^\n]", tasks[i].hour);
			fscanf(taskFile, " %[^\n]", tasks[i].description);
			fscanf(taskFile, "%d", &tasks[i].frequency);
			fscanf(taskFile, "%d", &tasks[i].eStatus);
			fscanf(taskFile, "%d", &tasks[i].fkIdEmployee);
	    }

	}
		
    while (option != 0)
    {
    	optionEmployee = 10;
    	optionTasks = 10;
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
	                    printf("\nOpcao invalida, introduza uma opcao valida!\n");
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
                        listTasks();
	                	break;
	                	
	                case 3:
                        idTask = getTasks();
                        editTasks(idTask);
	                	break;
	                	
	                case 4:
                        idTask = getTasks();
                        deleteTask(idTask);
	                	break;

                    case 5:    
                        idTask = getTasks();
                        editStatusTasks(idTask);
                        break;
	                default:
	                	printf("\nOpcao invalida, introduza uma opcao valida!\n");
	                    system("pause");
	                    break;
                }
            }

            break;
        case 3:
            stats();
            break;
        case 4:
        	saveReturn = save(employeFile, taskFile, IDsEmployeesTable, IDTasksTable);
        	
        	if (saveReturn == 1) {
        		printf("\nAlteracoes guardadas com sucesso");
        		system("pause");
			} else {
				printf("\nErro ao guardar as alteracoes");
				system("pause");
			}
            break;
            
        case 5:
        	saveReturn = save(employeFile, taskFile, IDsEmployeesTable, IDTasksTable);
        	
        	if (saveReturn == 1) {
        		printf("\nAlteracoes guardadas com sucesso");
        		system("pause");
			} else {
				printf("\nErro ao guardar as alteracoes");
				system("pause");
			}
        	option = 0;
            break;
            
        default:
            printf("\nOpcao invalida, introduza uma opcao valida!\n");
            system("pause");
            break;
        }
    }
    return 0;
}
