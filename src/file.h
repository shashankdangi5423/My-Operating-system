#include "types.h"



void file_list();
void file_create(char *name);
typedef struct file{
	char name[15];
	char content[100];
}file_format;

file_format file[10];

static int i=0;



