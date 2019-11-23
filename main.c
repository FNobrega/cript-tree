
#include <stdio.h>
#include <stdlib.h>
/*typedef struct letterStruct{
    char letter;
    int intVal;
    struct letterStruct *next;
} LS;

LS *Cria(int t){
  LS* novo = (LS*)malloc(sizeof(LS));
  novo->intVal=0;
  novo->next = (LS*)malloc(sizeof(LS*)*t);
  int i;
  return novo;
}*/

int main()
{
	char letras[50] ="";
	char comp ="";
	int frequencia[50] = {0};
	int j = 0;
	/*for (int i = 0; i < 50; ++i)
	{
		printf("%c\n",letras[i] );
		printf("%d\n", frequencia[i]);
	}*/
	FILE *ptr_file;
	char buf[1000];
	printf("Hello World\n");
	ptr_file =fopen("input.txt","r");
	if (!ptr_file){
		printf("Hello 1\n");
		return 1;
	}

	while (fgets(buf,1000, ptr_file)!=NULL){
		for (int i = 0; buf[i]!='\n'; ++i)
		{
			j=0;
			while(letras[j]!= letras[50] && letras[j]!=buf[i])
				j++;
			letras[j] = buf[i];
			frequencia[j]++;
			printf("%c\n", buf[i]);
		}
		printf("Hello 2\n");
	}
	for (int i = 0; i < 50; ++i)
	{
		printf("%c, ",letras[i] );
		printf("%d\n", frequencia[i]);
	}

	fclose(ptr_file);
		return 0;
}
