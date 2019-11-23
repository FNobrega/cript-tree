#include <stdio.h>
#include <string.h>
#define MAX_TAM 60

void removeDuplicates(char * str);
void removeAll(char * str, const char toRemove, int index);
void ordenaLetras(const char str[], char sup[]);


    //Inserindo o algoritmo que cria dinamicamente a tabela de frequências e letras, a ser inputado na árvore B.
int main(int argc, char* argv[]){
    char letras[MAX_TAM];
    char string_copia[MAX_TAM];
    int frequencia[MAX_TAM]= {0};
    char ordenado[MAX_TAM];
    printf("Insira a palavra a ser codificada:\n");
    scanf("%[^\n]", &letras);

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
    //==================================================================================
    // for(int i=0;i<tam;i++){
    //     if(string_copia[i]==ordenado[i]) frequencia[i]++;
    //     //preenche o vetor com as primeiras ocorrências de cada letra
    // }
    
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