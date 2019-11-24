 void BuscaCaminho(TAB* x, char ch, char* letra){
  //printf("%s", letra);
  char temp[1];


  if(!x){
    //caso em que a árvore é vazia
    //printf("flag: 201\n");
    return;
  }

  int i = 0;
  while(i< x->nchaves && ch> x->chave[i]) i++;
  if(i<x->nchaves && ch==x->chave[i]){
      //printf("flag 202\n");
      

      snprint(temp, 10,"%d", i);
      strcat(letra, temp);
  }

  if(x->folha) {
    //printf("flag: 203\n");
    snprint(temp, 10,"%d", i);
    strcat(letra, temp);
  }
  snprint(temp, 10,"%d", i);
  strcat(letra, temp);
  BuscaCaminho(x->filho[i], ch, letra);
  //printf("flag 204");
}


// essa parte aqui da main:
/*
printf("flag: 102\n");
	Imprime(arvore, 0);
	printf("flag: 103\n");
	ImprimeInt(arvore, 0);
	printf("flag: 104\n");
	char* letraEnc = malloc(sizeof(char*)*50);
	strcpy(letraEnc, "\0");
	BuscaCaminho(arvore, 'v', letraEnc);
	printf("caminho: %s\n", letraEnc);

	return 0;
}
*/