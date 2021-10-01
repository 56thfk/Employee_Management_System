/*
	EMS - employee_management_system.c
	Employee Management
	Copyrigit (C) 2021 Naive-C <naive.c.cell@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#include "find_employee.c"

#define READ_FILE (employee_fp = fopen("Employee.txt", "r")) == NULL

FILE* employee_fp;
const int DEFAULT_STARTING_SALARY = 3000;

struct employee_information
{
	char		 id[10];
	char first_name[50];
	char  last_name[50];
	char   	  email[50];
	char 	  phone[12];

	size_t salary;

   	_Bool fire_flag;
	_Bool hire_flag;
};
struct employee_information Employee = {
	.id			= "",
	.first_name = "",
	.last_name  = "",
	.salary 	= DEFAULT_STARTING_SALARY,
	.fire_flag  = true,
	.hire_flag  = false
};

//TODO find_employee_position의 인자값 받는 구조체 생성

void print_header(const char* current_page);
void main_menu(const char* message);
void add();
void edit();
void delete();
void search();
void view_list();

int main()
{
    main_menu("");
	return 0;
}

void main_menu(const char* message)
{
    print_header("");
    printf("                    ▄   ▄  ▄▄   ▄ ▄▄▄   ▄▄▄▄   ▄▄  ▄▄▄  ▄  ▄                   \n");
    printf("                    █▀▄▀█ █  █  ▄ █  █  █ █ █ █▄▄█ █  █ █  █                   \n");
    printf("                    █   █ ▀▄▄▀▄ █ █  █  █ █ █ ▀▄▄  █  █ ▀▄▄▀▄                  \n");
    printf("             --------------------------------------------------------          \n");
    printf("                              <1> View Employee List                           \n");
    printf("                              <2> Search Employee                              \n");
    printf("                              <3> Edit Employee Info                           \n");
    printf("                              <4> Add Employee                                 \n");
    printf("                              <5> Delete Employee                              \n");
    printf("             --------------------------------------------------------          \n");
    printf("                                                             <0> Exit          \n");
    printf("             입력: ");

unknown_char_main_menu_retry:
    switch(getchar()){
        case '1':
			READ_FILE ? main_menu("") : view_list();
			break;
        case '2':
			READ_FILE ? main_menu("") : search();
			break;
        case '3':
			READ_FILE ? main_menu("") : edit();
			break;
        case '4':
			READ_FILE ? main_menu("") : add();
			break;
        case '5':
			READ_FILE ? main_menu("") : delete();
       		break; 
        case '0': 
            exit(0);
        default:
            goto unknown_char_main_menu_retry;
    }   
}

/* 직원 추가 기능*/
void add()
{
	print_header("		Employee >> Add\n\n");

	employee_fp = fopen("Employee.txt", "a+");

	printf("		>> ID: ");
	fflush(stdin);
	scanf("%10[^\n]", Employee.id);

	printf("		>> First Name: ");
	fflush(stdin);
	scanf("%50[^\n]", Employee.first_name);

	printf("		>> Last Name: ");
	fflush(stdin);
	scanf("%50[^\n]", Employee.last_name);

	//TODO: hire_flag는 true, fire_flag는 false로 변경

	printf("		>> Salary: ");
	fflush(stdin);
	scanf("%zu", &Employee.salary);

	printf("		ID		  : %s\n", Employee.id);
	printf("		First Name: %s\n", Employee.first_name);
	printf("		Last Name : %s\n", Employee.last_name);
	printf("		Salary    : %zu\n", Employee.salary);
	printf("        --------------------------------------------------------          \n");
	printf("		Record Data\n");
	printf("		<Y>Yes		<N>No\n");
	printf("		Choose Option: ");

add_employee_retry:
	switch(tolower(getchar())){
		case 'y':
			fprintf(employee_fp, "%s %s %s %zu\n", Employee.id, Employee.first_name, Employee.last_name, Employee.salary);
			fclose(employee_fp);
			main_menu("Sucess");
			break;
		case 'n':
			main_menu("");
			break;
		default:
			goto add_employee_retry;
	}
}

/* 직원 검색*/
void search()
{
//TODO
}

/* 직원 리스트 출력 */
void view_list()
{
	system("clear");

	int counter = 1, n = 0;

	print_header("			 Employee >> View List\n");

	while((n = fscanf(employee_fp, "%s %s %s %zu", 
		   Employee.id, Employee.first_name, Employee.last_name, &Employee.salary)) != EOF){
			printf("%s %s %s %zu\n", Employee.id, Employee.first_name, Employee.last_name, Employee.salary);
		counter++;
	}

	fclose(employee_fp);
	//TODO: main_menu 실행 
}

/* 직원 정보 수정*/
void edit()
{
//TODO
}

/* 직원 정보 삭제*/
void delete(const char* in_id)
{
//TODO
}

void print_header(const char* current_page)
{
    system("clear");
    printf("                  -----------------------------------------                  \n");
    printf("                         Employee Management System                          \n");
    printf("                  -----------------------------------------                  \n");
    printf("%s", current_page);
}
