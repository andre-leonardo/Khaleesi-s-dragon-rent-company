#include <stdio.h>

int main(int argc, char *argv[]){
    
    int arrSize = 5;
    char nomeGuerreiro[arrSize][20], reino[arrSize][20], titulo[arrSize][20], nomeDrake[arrSize][20], elementoDrake[arrSize][20];
    int drakeLock[arrSize], data[arrSize], checarCadastroGuerreiro[arrSize];
    int opcao, i, codigoGuerreiro = 0, tentarNovamente = 0;
	
	void funcaoCadastro()
	{
				printf("Digite o nome do guerreiro: ");
                scanf("%s", &nomeGuerreiro[codigoGuerreiro]);
                
                printf("Digite o reino do guerreiro: ");
                scanf("%s", &reino[codigoGuerreiro]);
                
                printf("Digite o titulo do guerreiro: ");
                scanf("%s", &titulo[codigoGuerreiro]);
	}

    printf("-------------------\n");
    printf("LOCADORA DA KALEESI\n");
    printf("-------------------\n");

    do
    {
        printf("0 - Sair\n1 - Listar Guerreiros\n2 - Cadastrar guerreiro via codigo\n3 - Pesquisar guerreiro via nome\n4 - Excluir guerreiro via codigo\n5 - Listar dragoes\n6 - Cadastrar dragao via codigo\n7 - Pesquisar dragao via nome\n8 - Excluir dragao via codigo\n9 - Listar dragoes locados\n10 - Locar dragao\n11 - Devolver dragao via codigo do guerreiro\n");
        scanf("%d", &opcao);
        if (opcao == 0)
        {
            printf("Obrigado por utilizar esse programa!");
            break;
        }

        //preciso fazer com que o programa liste os nomes apenas se já estiverem cadastrados
        if (opcao == 1)
        {
            for(i = 0; i < arrSize; i++)
            {
                printf("%s\n", nomeGuerreiro[i]);
            }
        }

        if (opcao == 2)
        {
        	while(tentarNovamente == 0)
            {
            printf("Digite o codigo do guerreiro que não esteja sendo usado(um numero de 0 ate %d): ", arrSize-1);
            scanf("%d", &codigoGuerreiro);
            if (codigoGuerreiro >= 0 && codigoGuerreiro < arrSize)
            {
            	if (checarCadastroGuerreiro[codigoGuerreiro] == 1)
            	{
            		printf("Um guerreiro ja esta cadastrado com esse codigo, digite 0 para tentar novamente ou qualquer outro numero para voltar ao menu principal: ");
            		scanf("%d", &tentarNovamente); 
				}
				else
				{
					funcaoCadastro();
					checarCadastroGuerreiro[codigoGuerreiro] = 1;
                	break;
				}
            }
            else
            {
                printf("Codigo invalido, digite 0 para tentar novamente ou qualquer outro numero para voltar ao menu principal: ");
                scanf("%d", &tentarNovamente); 
            }
            }
            tentarNovamente = 0;
        }
        
    }
    while(opcao != 0);

    return 0;
}