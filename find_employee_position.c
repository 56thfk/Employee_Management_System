/*
	EMS - find_employee_position.c
	ID와 일치하는 Employee의 텍스트 시작 위치와 끝 위치를 계산
	ID 끝 위치의 뒤 데이터를 시작 위치에 덮어쓰는 기능
	Copyright (C) Naive-C naive.c.cell@gmail.com
*/
#include <stdio.h>
#include "file_length.c"

size_t find_employee_position(const char* id ,FILE* employee_fp) 
{
	size_t seek, start, id_position,filelength;
	char buf[1024];

	start = filelength = id_position = 0;
	filelength = file_length(fileno(employee_fp));

	while(1){	
		seek = ftell(employee_fp);

		if(fgets(buf, 1024, employee_fp) == NULL) { break; }
		
		if(strstr(buf, id) != NULL){  
			start = seek;
			id_position = filelength - ftell(employee_fp); 
		}
	}

	fclose(employee_fp);	
	//return ;	
}
