#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int opcao_menu;
		FILE *fr;
		fr = fopen ("configurações", "r");
		if(fr==NULL){
       		printf("\nPrograma não configurado! Pressione Enter para ir até o menu de configurações!\n");
		getchar();
		system("clear");
		system("./config");
   		}
		else{
        system("clear");
        printf("\n\t\t\t\t\t\tGERENCIADOR DE ESTACIONAMENTO\n");
	system("date +%d/%m/%y");
        printf("\n\t\t1 - Cadastro de Clientes\t2 - Entrada de Cliente\t\t5 - Relatórios\t\t7 - Sair\n\t\t3 - Número de Vagas\t\t4 - Gerar Recibo\t\t6 - Configurações\n");
        printf("\nEntre com a opção: ");
        scanf("%d", &opcao_menu);
        getchar();
	system("clear");

    switch (opcao_menu){
        case 1:
        system("./cadastroclientes");
        break;

        case 2:
        system("./entradacliente");
        break;

        case 3:
	system("./numvagas");
        break;

        case 4:
	system("./gerarrecibo");
	break;

        case 5:
	system("./relatorios");
        break;

	case 6:
        system("./config");
        break;

	case 7:
	exit(0);
	break;

        default:
            printf("Opção inválida!\n");
    }
    return 0;
		}
}
