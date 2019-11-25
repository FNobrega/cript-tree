
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvB.c"
#include "tabFunc.c"
#include "decripta.c"

#define MAX_TAM 60

int main()
{
	//==================================================================================
	//Declaracoes
	char letras[MAX_TAM];
    char string_copia[MAX_TAM];
    int frequencia[MAX_TAM]= {0};
    char ordenado[MAX_TAM];

    int tamletra=0;

	char delim[] = "*";
	//char decode[MAX_TAM];

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
	//printf("flag: 101\n");
	int tam = strlen(letras);
	for (int i = 0; i <tam; ++i)
	{
		arvore = Insere(arvore, ordenado[i], t);
	}
	//printf("flag: 102\n");
	Imprime(arvore, 0);
	//printf("flag: 103\n");
	//ImprimeInt(arvore, 0);
	//printf("flag: 104\n");
	char* letraEnc = malloc(sizeof(char*)*1000);
	strcpy(letraEnc, "\0");
	for(int i=0; i<strlen(string_copia); i++){
		if(string_copia[i]== ' '){
			strcat(letraEnc, " ");
		}
		else BuscaCaminho(arvore, string_copia[i], letraEnc);
	}
	printf("caminho: %s\n", letraEnc);
	//ImprimeInt(Busca(arvore, 'e'),0);
	//BuscaCaminho(arvore, string_copia[i], letraEnc);
	tamanhoLetra(arvore, &tamletra);
	printf("%i\n", tamletra );

	//printf(	"%c\n", BuscaLetra(arvore, "20"));

	decript(arvore,tamletra,letraEnc);
	char *ptr = strtok(letraEnc, delim);
	int init_size = strlen(letraEnc);
	//int cont =0;
	while(ptr != NULL)
	{
		if (ptr[0] == ' '){
			//printf("%s\n", ptr);
			//decode[cont] = ' ';
			//decode[cont+1] = BuscaLetra(arvore,++ptr);
			//decode[cont+2] = '\0';
			//cont = cont +2;
			printf(" %c", BuscaLetra(arvore,++ptr));
		} else {
			//printf("Aqui!\n");
			//decode[cont] = BuscaLetra(arvore,ptr);
			//decode[cont+1] = '\0';
			//printf("%s\n", ptr);
			printf("%c", BuscaLetra(arvore,ptr));
			//cont++;
		}
		
		ptr = strtok(NULL, delim);
	}
	//printf("%s\n", decode);
	/*for (int i = 0; i < init_size; i++)
	{
		//snprintf(temp, 10,"%d", i);
    	//strcat(letra, temp);
		//printf("%c", letraEnc[i]); /* Convert the character to integer, in this case
							   //the character's ASCII equivalent */
	//}*/
	printf("\n");

	return 0;
}
