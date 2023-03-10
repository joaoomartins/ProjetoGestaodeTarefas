#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
#define TAM_SEARCH 255

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
    
    printf(" ***************************************************************\n");
    printf("**---------------------- MENU PRINCIPAL ---------------------- **\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
    printf("**                             **                              **\n");
    printf("**   {1} - Funcionarios        **     {2} - Tarefas            **\n");
    printf("**                             **                              **\n");
    printf("**   {3} - Estatisticas        **     {4} - Gravar/Sair        **\n");
    printf("**                             **                              **\n");
    printf("**                         {0} - Sair                          **\n");
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
    
    printf(" ******************************************************************\n");
    printf("**--------------------------- MENU FUNCIONARIOS ------------------------**\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
    printf("**                                   **                                   **\n");
    printf("**    {1} - Inserir Funcionarios     **     {2} - Listar Funcionarios     **\n");
    printf("**                                   **                                   **\n");
    printf("**    {3} - Detalhes do Funcionario  **     {4} - Editar Funcionario      **\n");
    printf("**                                   **                                   **\n");
    printf("**    {5} - Apagar Funcionario       **     {0} - Sair                    **\n");
    printf("**                                   **                                   **\n");
    printf(" *************************************************************************\n");

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
    printf("**   {3} - Detalhes da Tarefa    **     {4} - Editar Tarefas     **\n");
    printf("**                               **                              **\n");
    printf("**   {5} - Apagar Tarefas        **     {6} - Editar Status      **\n");
    printf("**                           {0} - Sair                          **\n");
    printf("**                               **                              **\n");
    printf(" *****************************************************************\n");

    printf("Opcao:");
    scanf("%d", &option);
    return option;
}

int getEmployees(){


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
    
    return 0;
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
    printf("**|   ID   |          DESCRICAO          |          FUNCIONARIO          |      **\n");
    for (int i = 0; i < TAM_TASKS; i++)
    {
        if (tasks[i].id != 0)
        {
            for (int j = 0; j < TAM_EMPLOYEES; j++)
            {
                if (employees[j].id != 0 && tasks[i].fkIdEmployee == employees[j].id)
                {
                    printf("**|   %d   |          %s          |          %s          |    **\n", tasks[i].id, tasks[i].description, employees[j].name);
                }  
            }
        }
        }
    printf(" **************************************************************************\n");
    system("pause");
    return 0;
}

int getTasks(){

    system("cls");

    printf(" ****************************************************************************************\n");
    printf("**-------------------------------------- TAREFAS ---------------------------------------**\n");
    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
    printf("**|   ID   |                 NOME                 |    ESTADO    |   DATA   |   HORA   |**\n");
    for (int i = 0; i < TAM_TASKS; i++)
    {
        if (tasks[i].id != 0)
        {
            printf("**|   %d   |                 %s                 |    %d    |   %s   |   %s   |**\n", tasks[i].id, tasks[i].description, tasks[i].eStatus, tasks[i].date, tasks[i].hour);
        }
    }
    printf("**                                                              **\n");
    printf("**                         Estado : 0 = Fechado e 1 = Aberto                           **\n");
    printf(" ****************************************************************************************\n");
    
    return 0;
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
	
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    char date[TAM_DATE];
    int returnValue = 0;

    strftime(date, TAM_DATE, "%d/%m/%Y", &tm);
    for (int i = 0; i < TAM_TASKS; i++)
    {
        if (strstr(tasks[i].date, date) != NULL)
        {
            for (int j = 0; j < TAM_EMPLOYEES; j++)
            {
                if (tasks[i].fkIdEmployee == employees[j].id)
                { 
                    returnValue = 1;

                    printf(" ***************************************************************\n");
                    printf("**-------------------- Resumo das Tarefas -------------------- **\n");
                    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
                    printf("**    Tarefa do dia: ");   
                    timer();
                    printf("                                **\n");
                    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
                    printf("**    Hora: %s                                               **\n", tasks[i].hour);
                    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
                    printf("**    Descricao: %s                            **\n", tasks[i].description);
                    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
                    printf("**    Frequencia: %d                                           **\n", tasks[i].frequency);
                    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
                    printf("**    Estado: %d                                               **\n", tasks[i].eStatus);
                    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
                    printf("**    Funcionario: %s                                           **\n", employees[j].name);
                    printf("**                                                              **\n");
                    printf(" ***************************************************************\n");
                }
            }
        }
        
    }    
    return returnValue;
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

int tasksInfo(int idTask) {
	
	system("cls");

    for (int i = 0; i < TAM_TASKS; i++)
    {
       if (tasks[i].id == idTask)
        {
            for (int j = 0; j < TAM_EMPLOYEES; j++)
            {
                if (tasks[i].fkIdEmployee == employees[j].id)
                { 
                    printf(" **************************************************************** \n");
                    printf("**-------------------------- Tarefa --------------------------- **\n");
                    printf("**---------------------------- ID: %d -------------------------**\n", tasks[i].id);
                    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
                    printf("**    Data: %s                                          **\n", tasks[i].date);
                    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
                    printf("**    Hora: %s                                               **\n", tasks[i].hour);
                    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
                    printf("**    Descricao: %s                            **\n", tasks[i].description);
                    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
                    printf("**    Frequencia: %d                                           **\n", tasks[i].frequency);
                    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
                    printf("**    Estado: %d                                               **\n", tasks[i].eStatus);
                    printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=**\n");
                    printf("**    Funcionario: %s                                           **\n", employees[j].name);
                    printf("**                                                              **\n");
                    printf(" ***************************************************************\n");
                
                    return 1;
                }
            }
        }
    }
    return 0;
}

int employeeInfo(int idEmployee) {
	
	system("cls");

    for (int i = 0; i < TAM_EMPLOYEES; i++)
    {
        if (employees[i].id == idEmployee)
        {
            
            printf(" ******************************************************************* \n");
            printf("**------------------------ Funcionario --------------------------- **\n");
            printf("**--------------------------- ID: %d ------------------------------**\n", employees[i].id);
            printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
            printf("**    Nome: %s                                                     **\n", employees[i].name);
            printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
            printf("**    Data de Nascimento: %s                                       **\n", employees[i].birthdate);
            printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
            printf("**    Telemovel: %s                                                **\n", employees[i].numCellphone);
            printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
            printf("**    Email: %s                                                    **\n", employees[i].email);
            printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
            printf("**    Localidade: %s                                               **\n", employees[i].place);
            printf("**-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-**\n");
            printf("**    Departamento: %s                                             **\n", employees[i].department);
            printf("**                                                                 **\n");
            printf(" ***************************************************************\n");
        
            return 1;
        }
                         
    }
    return 0;
}
//Retorna a id do employee se encontrar a string
//Senao retorna 0
int searchEmployee() {
    char search[TAM_SEARCH];

    getEmployees();
    fflush(stdin);
    printf("\nInsira o nome/departamento/email/localidade do funcionario que deseja associar a tarefa: ");
    fgets(search, TAM_SEARCH, stdin);
    strtok(search, "\n");
	for (int i = 0; i < TAM_EMPLOYEES; i++) {
		if (strstr(employees[i].name, search) != NULL || strstr(employees[i].email, search) != NULL || strstr(employees[i].department, search) != NULL || strstr(employees[i].numCellphone, search) != NULL || strstr(employees[i].place, search) != NULL) {
			return employees[i].id;
		}
	}
	
	return 0;
}

int searchTask() {
    char search[TAM_SEARCH];
    getTasks();
    fflush(stdin);
    printf("\nInsira a descricao/Data/Hora da tarefa que deseja ver: ");
    fgets(search, TAM_SEARCH, stdin);
    strtok(search, "\n");
	for (int i = 0; i < TAM_TASKS; i++) {
		if (strstr(tasks[i].date, search) != NULL || strstr(tasks[i].hour, search) != NULL || strstr(tasks[i].description, search) != NULL) {
			return tasks[i].id;
		}
	}
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
			
			
			printf("\nIntroduza a data de nascimento do funcionario no formato (dd/mm/aaaa): ");
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
			
			printf("\nIntroduza a data de nascimento do funcionario no formato (dd/mm/aaaa): ");
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

int insertTask() {
    int  month = 0, 
	day = 0,
	year = 0,
	frequency = 0,
    idEmployee = 0;
	struct tm date;

    char inputDate[TAM_DATE],
	hour[TAM_HOUR],
	description[TAM_DESCRIPTION],
    search[TAM_SEARCH];

	for (int i = 0; i < TAM_TASKS; i++) {
		if (tasks[i].id == 0) {
			fflush(stdin);
			
			printf("\nIntroduza a data da tarefa no formato (dd/mm/aaaa): ");
			fgets(inputDate, TAM_DATE, stdin);
			strtok(inputDate, "\n");
			strcpy(tasks[i].date, inputDate);
			fflush(stdin);
			
			printf("\nIntroduza a hora da tarefa no formato (hh:mm): ");
			fgets(hour, TAM_HOUR, stdin);
			strtok(hour, "\n");
			strcpy(tasks[i].hour, hour);
			fflush(stdin);
			
			printf("\nIntroduza a descricao da tarefa: ");
			fgets(description, TAM_DESCRIPTION, stdin);
			strtok(description, "\n");
			strcpy(tasks[i].description, description);
			fflush(stdin);
			
			printf("\nIntroduza o tipo de frequencia que quer que a sua tarefa tenha");
			printf("\n0 = Pontual\n1 = Mensal: ");
			scanf("%d", &frequency);
			fflush(stdin);
			
			while (1)
            {
                idEmployee = searchEmployee();

                if (idEmployee != 0)
                {
                    break;
                }
                
            }

			
			tasks[i].fkIdEmployee = idEmployee;
			tasks[i].frequency = frequency;
			tasks[i].eStatus = 1; // Quando a tarefa e criada o estado e aberto
			tasks[i].id = biggestIDTasks + 1;
			
			biggestIDTasks += 1;

            if (frequency == 1) {
            	printf("\nData base: %s\n", inputDate);
            	fflush(stdin);
                sscanf(inputDate, "%d/%d/%d", &day, &month, &year);
                
                date.tm_mday = day;
				date.tm_mon = month - 1;
   				date.tm_year = year - 1900;
   				
                for (int j = 1; j < 13; j++) {
                    date.tm_mon += 1;

                    mktime(&date);

					if (date.tm_mon == 0) {
						date.tm_year += 1;
					}

					tasks[i + j].id = biggestIDTasks + 1;
					strftime(tasks[i + j].date, TAM_DATE, "%d/%m/%Y", &date);
                    strcpy(tasks[i + j].hour, hour);
                    strcpy(tasks[i + j].description, description);
                    tasks[i + j].frequency = 1;
                    tasks[i + j].eStatus = 1;
                    tasks[i + j].fkIdEmployee = idEmployee;
					biggestIDTasks += 1;

					printf("Tarefa para a data %s criada\n", tasks[i + j].date);
                    system("pause");
                }
            }
            

			return 1;
		}
	}
	
	return 0;
}

int editTasks(int idTask){

    int  month = 0, 
	day = 0,
	year = 0,
	frequency = 0,
    idEmployee = 0;
	struct tm date;

    char inputDate[TAM_DATE],
	hour[TAM_HOUR],
	description[TAM_DESCRIPTION],
    search[TAM_SEARCH];

	for (int i = 0; i < TAM_EMPLOYEES; i++) {
		if (tasks[i].id == idTask) {
			fflush(stdin);
			
			printf("\nIntroduza a data da tarefa no formato (dd/mm/aaaa): ");
			fgets(inputDate, TAM_DATE, stdin);
			strtok(inputDate, "\n");
			strcpy(tasks[i].date, inputDate);
			fflush(stdin);
			
			printf("\nIntroduza a hora da tarefa no formato (hh:mm): ");
			fgets(hour, TAM_HOUR, stdin);
			strtok(hour, "\n");
			strcpy(tasks[i].hour, hour);
			fflush(stdin);
			
			printf("\nIntroduza a descricao da tarefa: ");
			fgets(description, TAM_DESCRIPTION, stdin);
			strtok(description, "\n");
			strcpy(tasks[i].description, description);
			fflush(stdin);
			
			printf("\nIntroduza o tipo de frequencia que quer que a sua tarefa tenha");
			printf("\n0 = Pontual\n1 = Mensal: ");
			scanf("%d", &frequency);
			fflush(stdin);
			
            while (1)
            {
                idEmployee = searchEmployee();

                if (idEmployee != 0)
                {
                    break;
                }
                
            }

			tasks[i].fkIdEmployee = idEmployee;
			tasks[i].frequency = frequency;
			tasks[i].eStatus = 1; // Quando a tarefa e criada o estado e aberto
			tasks[i].id = biggestIDTasks + 1;
			
			biggestIDTasks += 1;

            if (frequency == 1) {
            	printf("\nData base: %s\n", inputDate);
            	fflush(stdin);
                sscanf(inputDate, "%d/%d/%d", &day, &month, &year);
                
                date.tm_mday = day;
				date.tm_mon = month - 1;
   				date.tm_year = year - 1900;
   				
                for (int j = 1; j < 13; j++) {
                    date.tm_mon += 1;

                    mktime(&date);

					if (date.tm_mon == 0) {
						date.tm_year += 1;
					}

					tasks[i + j].id = biggestIDTasks + 1;
					strftime(tasks[i + j].date, TAM_DATE, "%d/%m/%Y", &date);
                    strcpy(tasks[i + j].hour, hour);
                    strcpy(tasks[i + j].description, description);
                    tasks[i + j].frequency = 1;
                    tasks[i + j].eStatus = 1;
                    tasks[i + j].fkIdEmployee = idEmployee;
					biggestIDTasks += 1;

					printf("Tarefa para a data %s criada\n", tasks[i + j].date);
                    system("pause");
                }
            }
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
		if (tasks[i].id != 0 && tasks[i].eStatus != 0) {
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

int main() {
	int option = 10,
	optionEmployee = 10, 
	optionTasks = 10, 
	idEmployee, 
	sizeEmployeFile, 
	sizeTaskFile, 
	saveReturn = 0, 
	idTask = 0, 
	contador = 0, 
	returnResult = 0;
	
    char exit, search[TAM_SEARCH];
    
  	FILE *employeFile, *taskFile, *IDTasksTable, *IDsEmployeesTable;
  	
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
		
    while (option != 0) {
        fflush(stdin);
        optionEmployee = 10;
    	optionTasks = 10;
        system("cls");
        returnResult = resume();
        if (returnResult == 0)
        {
            printf("\nNao existem tarefas para hoje.\n");
        }
        
        option = menu();

        switch (option) {
	        case 0:
	        	do {
	        		fflush(stdin);
			        printf("\nPodera ter efetuado alteracoes e nao ter guardado, quer sair mesmo assim? (Sim/Nao): ");
			        scanf("%c", &exit);
			        switch (exit) {
			            case 's':
			            case 'S':
			                return 0;
			            case 'n':
			            case 'N':
			                break;
			            default:
			                printf("\nOpcao invalida");
			                break;
		        	}
		        	
		        	if (exit == 'n') {
		        		option = 10;
		        		break;
					}
				} while (exit != 's');
	    		
	    		break;
        case 1:
            while (optionEmployee != 0) {
            	fflush(stdin);
            	
            	optionEmployee = menuEmployees();
            	
                switch (optionEmployee) {

                    case 0:
                        break;
                        
                    case 1:
                        returnResult = insertEmployee();
                        
                        if (returnResult == 0) {
                        	printf("\nNao e possivel inserir mais funcionarios\n");
						} else {
							printf("\nFuncionario inserido com sucesso\n");
						}
						
						system("pause");                        
                        break;
                        
                    case 2:
                        listEmployees();
                        break;

                    case 3:
                        idEmployee = searchEmployee();
                        
                        if (idEmployee == 0) {
                        	printf("\nFuncionario nao encontrado\n");
						} else {
							employeeInfo(idEmployee);
						}
	                	break;
	                	
                    case 4:
                        idEmployee = searchEmployee();
                        
                        if (idEmployee == 0) {
                        	printf("\nFuncionario nao encontrado\n");
						} else {
							returnResult = editEmployee(idEmployee);
							if (returnResult != 0) {
								printf("\nFuncionario editado com sucesso\n");
							} else {
								printf("\nErro ao editar o funcionario\n");
							}
						}
						
						system("pause");
                        break;
                        
                    case 5:
                        idEmployee = searchEmployee();
                        
                        if (idEmployee == 0) {
                        	printf("\nFuncionario nao encontrado\n");
						} else {
							returnResult = deleteEmployee(idEmployee);
							
							if (returnResult != 0) {
								printf("\nFuncionario apagado com sucesso\n");
							} else {
								printf("\nErro ao apagar o funcionario\n");
							}
						}          
                        system("pause");
                        break;
	                default:
	                    printf("\nOpcao invalida, introduza uma opcao valida!\n");
	                    system("pause");
	                    break;
                }
            }
            break;
        case 2:
            while (optionTasks != 0) {
            	
            	fflush(stdin);
            	
            	optionTasks = menuTasks();
            	
                switch (optionTasks)
                {               	
	                case 0:
                        break;
                    case 1:
	                    returnResult = insertTask();
	                    
						if (returnResult == 0) {
	                    	printf("\nNao ha espaco para inserir novas tarefas\n");
						} else {
							printf("\nTarefa adicionada com sucesso.\n");
						}
	                    
	                    system("pause");
	                    break;
	                    
	                case 2:
                        listTasks();
	                	break;

                    case 3:
                        idTask = searchTask();
                        if (idTask == 0) {
                        	printf("\nNao foi possivel encontrar a tarefa\n");
						} else {
							tasksInfo(idTask);
						}
                        system("pause");
	                	break;    
	                	
	                case 4:                       
                        idTask = searchTask();
                        if (idTask == 0) {
                        	printf("\nNao foi possivel encontrar a tarefa\n");
						} else {
							returnResult = editTasks(idTask);
							if (returnResult != 0) {
								printf("\nTarefa editada com sucesso\n");;
							} else {
								printf("\nErro ao editar a tarefa");
							}
						}
                        system("pause");
	                	break;
	                	
	                case 5:
                        idTask = searchTask();
                        if (idTask == 0) {
                        	printf("\nNao foi possivel encontrar a tarefa\n");
						} else {
							deleteTask(idTask);
							printf("\nTarefa apagada com sucesso\n");
						}
                        system("pause");
	                	break;

                    case 6:
                        idTask = searchTask();
                        if (idTask == 0) {
                        	printf("\nNao foi possivel encontrar a tarefa\n");
						} else {
							editStatusTasks(idTask);
							printf("\nEstado da tarefa editado com sucesso\n");
						}
                        system("pause");
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
