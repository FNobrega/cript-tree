
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvB.c"
#include "tabFunc.c"

#define MAX_TAM 60

int main()
{
	//==================================================================================
	//Declaracoes
	char letras[MAX_TAM];
    char string_copia[MAX_TAM];
    int frequencia[MAX_TAM]= {0};
    char ordenado[MAX_TAM];

    //==================================================================================
	// Abertura de arquivo
	FILE *ptr_file;
	char buf[1000];
	ptr_file =fopen("input.txt","r");
	if (!ptr_file)
		return 1;

	//==================================================================================
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

	//==================================================================================
	//Arvore B
	TAB * arvore = Inicializa();
	printf("flag 101\n");
	int tam = strlen(letras);
	for (int i = 0; i <tam; ++i)
	{
		arvore = Insere(arvore, letras[i], t);
	}
	printf("flag 102\n");
	Imprime(arvore, 0);
	printf("flag103\n");
	ImprimeInt(arvore, 0);


	return 0;
}
