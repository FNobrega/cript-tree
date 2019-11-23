
#include <stdio.h>
#include <stdlib.h>
#define MAX_TAM 60

void removeDuplicates(char * str);
void removeAll(char * str, const char toRemove, int index);
void ordenaLetras(const char str[], char sup[]);

int main()
{
	char letras[MAX_TAM];
    char string_copia[MAX_TAM];
    int frequencia[MAX_TAM]= {0};
    char ordenado[MAX_TAM];

	FILE *ptr_file;
	char buf[1000];
	printf("Hello World\n");
	ptr_file =fopen("input.txt","r");
	if (!ptr_file){
		printf("Hello 1\n");
		return 1;
	}

	while (fgets(letras,1000, ptr_file)!=NULL){
		strcpy(string_copia, letras);
		printf("Antes: %s ", letras);
		removeDuplicates(letras);
		printf("\nApos: %s ", letras);
		int tam = strlen(letras);
		ordenaLetras(letras, ordenado);
		printf("\nOrdenado: ");

		for(int i=0; i<tam;i++){
		    printf("%c", ordenado[i]);
		}
		for(int i=0;i<tam; i++) {
	        for(int j=0;j<strlen(string_copia);j++){
	            if(ordenado[i]==string_copia[j]) frequencia[i]++;
	        }
	    }
	    //==================================================================================
	    //imprime as frequencias
	    printf("\nfrequencia: ");
	    for(int i=0;i<tam;i++){
	        printf("%d ", frequencia[i]);
	    }
	    printf("\n");

	}

	fclose(ptr_file);
	return 0;
}

void removeDuplicates(char * str){
    int i = 0;

    while(str[i] != '\0')
    {
        /* Remove all duplicate of character string[i] */
        removeAll(str, str[i], i + 1);
        i++;
    }
}

void removeAll(char * str, const char toRemove, int index){
    int i;

    while(str[index] != '\0')
    {
        /* If duplicate character is found */
        if(str[index] == toRemove)
        {   
            /* Shift all characters from current position to one place left */
            i = index;
            while(str[i] != '\0')
            {
                str[i] = str[i + 1];
                i++;
            }
        }
        else
        {
            index++;
        }
    }
}

void ordenaLetras(const char a[], char b[]){
    char temp;
    int i,j;

    for (i = 0; i < strlen(a); i++){
        b[i] = a[i];
    }

    for(i = 0; i < strlen(a); i++){
        for(j = 1; j < strlen(a); j++){
            //printf("%d\n", b[j-1]);
            //printf("%d\n", b[j]);
            if((int)b[j-1] > (int)b[j]){
                temp = b[j];
                b[j] = b[j-1];
                b[j-1] = temp;
            }
        }   
    }
}