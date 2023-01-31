#include "file.h"
#include "screen.h"
void file_create(char *name)
{
	int c=0;
	if(i<10){
	
	while(name[c]){

	file[i].name[c]=name[c];
	c++;
	}

	file[i].name[c]='\0';
		new_line();	
			monitor_write("file create");
			new_line();	
			monitor_write("Os->");

	}else{
		new_line();	
		monitor_write(":no space left to create a file");
		new_line();	
		monitor_write("Os->");
	}

	i++;

}

void file_list()
{
	int k;

	for(k=0;k<i;k++){
		monitor_write(file[k].name);
		monitor_write("     ");
	}
	

	
}
