void ler_config(int *ntotalvagas, float *precohora)
{
  FILE *tp;

  tp = fopen("configurações", "r");

      while (fscanf(tp, "%d\n%f", &*ntotalvagas, &*precohora) != EOF)
      {
          fclose(tp);
      }
}

void ler_vagaslivres(int *nvagasrestantes, int *ntotalvagas)
{
  FILE *fvl;

  fvl = fopen("vagaslivres", "rt");
  if(fvl==NULL){
         		nvagasrestantes=ntotalvagas;
  }
  else{

      while (fscanf(fvl, "%d", &*nvagasrestantes) != EOF)
      {
          fclose(fvl);
      }
  }
}

char *strlwr(char *str)
{
  size_t i;
  size_t len = strlen(str);

  for(i=0; i<len; i++)
  str[i]=tolower((unsigned char)str[i]);

  return str;
}

void calcular_tempo(int *duracao, int *duracao2) {

  	if (*duracao2<0){
  		duracao2=60+duracao2;
  		duracao=duracao-1;
  	}
    if(*duracao2>15){

  	duracao=(duracao+1);
  	}
}

void calcular_preco(int duracao, int duracao2, float *total, float precohora) {
  if(duracao2>15){

	  *total=(duracao+1)*precohora;
	}
	else{
		*total=duracao*precohora;
	}
}

void verificar_modelo(char modelo[], char carros_pequenos[], char carros_medios[], char carros_grandes[], float *precohora) {

  char *pos;

  if ((pos=strchr(modelo, '\n')) != NULL){
    *pos = '\0';
  }

  int tam = strlen(modelo);
  char *ret = strstr(carros_pequenos, modelo);
  char *ret2 = strstr(carros_medios, modelo);
  char *ret3 = strstr(carros_grandes, modelo);

  if (ret!=NULL) {
    printf("Achou em Carros pequenos!\n");
    *precohora=4.5;
  }
  if (ret2!=NULL) {
    printf("Achou em Carros médios!\n");
    *precohora=6.5;
  }
  if (ret3!=NULL) {
    printf("Achou em Carros grandes!\n");
    *precohora=8.5;
  }


printf("Tamanho = %d\n", tam);
}

void ler_clientes(int *nclientes) {
  FILE *tp;

  tp = fopen("clientes", "rt");
      if(tp==NULL){
             tp = fopen("clientes", "w");
      }

      while (fscanf(tp, "%d", &*nclientes) != EOF)
      {
          fclose(tp);
      }
}

void gravar_clientes(int *nclientes) {
   *nclientes=*nclientes+1;
   FILE *fcl;
   fcl=fopen("clientes","w");
   fprintf(fcl,"%d", *nclientes);
   fclose(fcl);
}

void gravar_dados(char cpfcliente[], char situacao[], char nomecliente[], char datadenascimento[], char enderecocliente[], char placacliente[], char modelo_carro[]) {
  FILE *fptr;
  fptr=fopen(cpfcliente,"w");
  fprintf(fptr,"Modalidade: %s", situacao);
  fprintf(fptr,"Nome: %s", nomecliente);
  fprintf(fptr,"Data de Nascimento: %s", datadenascimento);
  fprintf(fptr,"CPF: %s", cpfcliente);
  fprintf(fptr,"Endereço: %s", enderecocliente);
  fprintf(fptr,"Placa do Carro: %s", placacliente);
  fprintf(fptr,"Modelo do Carro: %s", modelo_carro);
  fclose(fptr);
}

void mostrar_dados(char cpfcliente[]) {
  		char linha[80];
  		FILE *fr;
  		fr = fopen (cpfcliente, "rt");
  		if(fr==NULL){
         		printf("\nCPF não existente no banco de dados!");
  		printf("\nPressione Enter para voltar e inserir os dados corretos");
  		getchar();
  		 system("clear");
  		 system("./entradacliente");
                  }
  		while(fgets(linha, 200, fr) != NULL){
  			printf ("%s", linha);
  		}
  		fclose(fr);
}

void gravar_hora_entrada(char cpfcliente[], int hentrada, int mentrada, int dia, int mes, int ano) {
  /*Começa a gravar a linha nova no arquivo*/
     		int i,n=9;
  		FILE *fptx;
  		fptx=(fopen(cpfcliente,"a"));
             fprintf(fptx, "Data: %d/%d/%d\n", dia, mes, ano);
      			 fprintf(fptx,"Hora de entrada: %d:%d\n", hentrada, mentrada);
    			 fclose(fptx);
}

void atualiza_vagaslivres(int nvagasrestantes, int ntotalvagas) {
     nvagasrestantes=ntotalvagas-1;
	   FILE *fptr;
	   fptr=fopen("vagaslivres","w");
	   fprintf(fptr,"%d", nvagasrestantes);
	   fclose(fptr);
}

void atualizar_vagasocupadas(int nvagasrestantes) {
    nvagasrestantes=nvagasrestantes+1;
    FILE *realoc_vagas;
    realoc_vagas=(fopen("vagaslivres","w+"));
    fprintf(realoc_vagas,"%d", nvagasrestantes);
    fclose(realoc_vagas);
}

void gravar_hora_saida(char cpfcliente[], int hsaida, int msaida) {
      FILE *ftprrr;
      ftprrr=(fopen(cpfcliente,"a"));
      fprintf(ftprrr,"Horário de Saída: %d:%d\n", hsaida, msaida);
    	fclose(ftprrr);

}

void busca_modelos(char carros_pequenos[200], char carros_medios[200], char carros_grandes[200]) {
  FILE *arq;
  arq = fopen ("carros_pequenos", "r");
  fscanf(arq,"%[^\n]", carros_pequenos);
  fclose(arq);
  arq = fopen ("carros_medios", "r");
  fscanf(arq,"%[^\n]", carros_medios);
  fclose(arq);
  arq = fopen ("carros_grandes", "r");
  fscanf(arq,"%[^\n]", carros_grandes);
     fclose(arq);

}

void tipo_cliente(char cpfcliente[], char arquivo[], char situacaocliente[], int *tipocliente) {
  		FILE *arq;
      int tipoc;
  		arq = fopen (cpfcliente, "r");
  		fscanf(arq,"%[^\n]",arquivo);
     		fclose(arq);
     		tipoc=strcmp(arquivo, situacaocliente);
     		/*sendo 0 horista e 1 mensalista*/
     		if(tipoc>0){
     			*tipocliente=1;
     		}
     		else{
     			*tipocliente=0;
     		}
}

void valor_total(int tipocliente, float total) {
  if(tipocliente==0){
    if(total!=0){
      printf("\nO valor a ser pago é de R$%.2f\n", total);
    }
    else{
    printf("\nPeríodo de cortesia.\n");
    }
  }
    else if (tipocliente!=0)
    {
      printf("\nO cliente é mensalista. Não é necessário calcular o valor total\n");
    }
}
