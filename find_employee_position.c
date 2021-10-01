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
