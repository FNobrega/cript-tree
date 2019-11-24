#include <stdio.h>
#include <stdlib.h>

void removeDuplicates(char * str);
void removeAll(char * str, const char toRemove, int index);
void ordenaLetras(const char str[], char sup[]);

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