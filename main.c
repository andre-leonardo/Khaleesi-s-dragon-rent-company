#include <stdio.h>
#include <string.h>
#include <time.h>
#define ARRSIZE 8
#define ARRSIZEGUERREIRO 8
#define ARRSIZEDRAKE 8
#define TAMANHOHISTORICO 6



char terra[5][20] = {"earth","fire","water","ice","wind"};
char nomeGuerreiro[ARRSIZEGUERREIRO][20], reino[ARRSIZEGUERREIRO][20], titulo[ARRSIZEGUERREIRO][20], elementoDrakeString[ARRSIZEDRAKE][20], nomeDrake[ARRSIZEDRAKE][20], guerreiroProcurado[1][20], drakeProcurado[1][20], drakeLocado[ARRSIZE][20], alugadores[ARRSIZE][20], historicoGuerreiro[TAMANHOHISTORICO][20], historicoDrake[TAMANHOHISTORICO][20];
int idadeDrake[ARRSIZEDRAKE],elementoDrake[ARRSIZEDRAKE], data[ARRSIZE][3], checarCadastroGuerreiro[ARRSIZEGUERREIRO], checarCadastroDrake[ARRSIZEDRAKE], checarSeDragaoJaEstaLocado[ARRSIZEDRAKE], checarSeGuerreiroJaTemDragao[ARRSIZEGUERREIRO];
int contar = 0, contarDrake = 0, opcao, i, e, d = TAMANHOHISTORICO, codigoGuerreiro, codigoDrake, guerreiroExcluido, drakeExcluido, tentarNovamente = 0;

//pre registered
char guerreiro[2][20] = {"Jagunco", "Pierre"}, preReino[2][20] = {"Falconia", "Saint Paul"}, preTitulo[2][20] = {"O Pepino","Folgado"}, drake[2][20] = {"Fogareu", "Almofadinha"}, preElemento[2][20] = {"fire", "water"};
int preIdade[2] = {25, 890};

void funcaoCadastroGuerreiro()
	{
		fflush(stdin);
		printf("Type the name of the warrior: ");
        scanf("%[^\n]s", nomeGuerreiro[codigoGuerreiro]);
        fflush(stdin);

        printf("Type the kingdom of the warrior: ");
        scanf("%[^\n]s", reino[codigoGuerreiro]);
        fflush(stdin);

        printf("Type the title of the warrior: ");
        scanf("%[^\n]s", titulo[codigoGuerreiro]);
        fflush(stdin);
	}

int main(int argc, char *argv[]){
	//system time
	struct tm *tempo;
	time_t segundos;
	time(&segundos); 
	tempo = localtime(&segundos);  
	printf("%d/%d/%d\n", tempo->tm_mday, tempo->tm_mon+1, tempo->tm_year+1900);

	

    for (i = 0; i < ARRSIZEGUERREIRO; i++)//THE ARRAYS WILL START WITH \0 FOR CONDITIONAL CHECKS
    {
    	checarSeDragaoJaEstaLocado[i] = 0;
    	checarSeGuerreiroJaTemDragao[i] = 0;
    	idadeDrake[i] = 0;
    	for (e = 0; e < 1; e++)
    	{
    		nomeGuerreiro[i][e] = '\0';
    		nomeDrake[i][e] = '\0';
    		drakeLocado[i][e] = '\0';
    		alugadores[i][e] = '\0';
    		data[i][e] = '\0';
    		historicoGuerreiro[i][e] = '\0';
			historicoDrake[i][e] = '\0';
			elementoDrakeString[i][e] = '\0';
		}
	}
	strcpy(nomeGuerreiro[1], guerreiro[0]);
	strcpy(nomeGuerreiro[4], guerreiro[1]);
	strcpy(reino[1], preReino[0]);
	strcpy(reino[4], preReino[1]);
	strcpy(titulo[1], preTitulo[0]);
	strcpy(titulo[4], preTitulo[1]);
	
	strcpy(nomeDrake[3], drake[0]);
	strcpy(nomeDrake[0], drake[1]);
	idadeDrake[3] = preIdade[0];
	idadeDrake[0] =  preIdade[1];
	strcpy(elementoDrakeString[3], preElemento[0]);
	strcpy(elementoDrakeString[0], preElemento[1]);
	checarCadastroGuerreiro[1] = 1;
	checarCadastroGuerreiro[4] = 1;
	checarCadastroDrake[3] = 1;
	checarCadastroDrake[0] = 1;
	

    printf("-------------------\n");
    printf(" Kahleesi's Rental Company'\n");
    printf("-------------------\n");

    do
    {
        printf("0 - Exit\n1 - List warriors\n2 - Register warrior by code\n3 - Search warrior by name\n4 - Delete warrior by code\n5 - List dragons\n6 - Register dragon by code\n7 - Search dragon by name\n8 - Delete dragon by code\n9 - List rented dragons\n10 - Rent dragon\n11 - Give gack dragon by warrior's code\n12 - Rents history\n\n\n");//Menu options
        scanf("%d", &opcao);
        if (opcao == 0)
        {
            printf("Thank you for using this programm!");
            break;
        }

        if (opcao == 1)//list warriors
        {
			for (i = 0; i < ARRSIZEGUERREIRO; i++)
			{
				if (nomeGuerreiro[i][0] != '\0')
				{
					contar++;
				}
			}
			
        	if (contar == 0)
        	{
        		printf("No warriors registered at the moment\n\n");
			}
			else
            {
                for(i = 0; i < ARRSIZEGUERREIRO; i++)
                {
                    printf("%d - %s\n", i, nomeGuerreiro[i]);
                }
			}
			contar = 0;
        }

        if (opcao == 2)//register warriors
        {
        	while(tentarNovamente == 0)
            {
	            printf("Type a warrior's code that is not being used(a number between 0 and %d): ", ARRSIZEGUERREIRO-1);
	            scanf("%d", &codigoGuerreiro);
	            if (codigoGuerreiro >= 0 && codigoGuerreiro < ARRSIZEGUERREIRO)
            	{
	            	if (checarCadastroGuerreiro[codigoGuerreiro] == 1)
	            	{
	            		printf("A warrior is already registered with this code, type 0 to try again or any other number to return to the main menu: ");
	            		scanf("%d", &tentarNovamente);
					}
					else
					{
						funcaoCadastroGuerreiro();
						checarCadastroGuerreiro[codigoGuerreiro] = 1;
	                	break;
					}
            	}
	            else
	            {
	                printf("Invalid code, type 0 to try again or any other number to return to the main menu: ");
	                scanf("%d", &tentarNovamente);
	            }
            }
        }

        if (opcao == 3)//search warriors
        {
			for (i = 0; i < ARRSIZEGUERREIRO; i++)
			{
				if (nomeGuerreiro[i][0] != '\0')
				{
					contar++;
				}
			}
			
        	if (contar == 0)
        	{
        		printf("No warriors registered at the moment\n\n");
			}
			else
			{
				while (tentarNovamente == 0)
				{
					fflush(stdin);
					printf("Type the name of the warrior: ");
					scanf("%[^\n]s", guerreiroProcurado[0]);

					for (i = 0; i < ARRSIZEGUERREIRO; i++)
					{
						if (strcmpi(guerreiroProcurado[0], nomeGuerreiro[i]) == 0)
						{
							printf("Warrior found at position/code %d\n", i);
							printf("His/her kingdom is: %s\n", reino[i]);
							printf("His/her title is: %s\n", titulo[i]);
							tentarNovamente = 1;
							i = ARRSIZEGUERREIRO + 1;
							break;
						}
					}
					if (i!=ARRSIZEGUERREIRO+1)
					{
							
						printf("Warrior's name not found, type 0 to try again or any other number to return to the main menu: ");
						scanf("%d", &tentarNovamente);		
					}
				}
			}
		}

		if (opcao == 4)//Delete warrior by code
		{
			for (i = 0; i < ARRSIZEGUERREIRO; i++)
			{
				if (nomeGuerreiro[i][0] != '\0')
				{
					contar++;
				}
			}
			
        	if (contar == 0)
				{
					printf("No warriors registered at the moment\n\n");
				}
			else
			{
				while (tentarNovamente == 0)
				{
					for(i = 0; i < ARRSIZEGUERREIRO; i++)//Print the warriors 
					{
						printf("%d - %s\n", i, nomeGuerreiro[i]);
					}
					printf("Type the code of the warrior that you want to delete: ");
					scanf("%d", &guerreiroExcluido);
					
					if (guerreiroExcluido >= 0 && guerreiroExcluido < ARRSIZEGUERREIRO)
					{
						if (checarSeGuerreiroJaTemDragao[guerreiroExcluido] == 1)
						{
							printf("This warrior has a rented dragon, the dragon must be given back first.\n");
							break;
						}
					    else if (nomeGuerreiro[guerreiroExcluido][0] == '\0')
	                    {
	                        printf("No warrior registered in this code.\n");
	                        break;
	                    }
	                    else
	                    {
	                        for (i = 0; i <= 20; i++)
	                        {
	                            nomeGuerreiro[guerreiroExcluido][i] = '\0';
	                        }
		                    printf("Warrior deleted successfully\n");
		                    checarCadastroGuerreiro[guerreiroExcluido] = 0;
							break;
	                    }
					}
				}
			}
		}

		if (opcao == 5)//list dragons
		{
		     for (i = 0; i < ARRSIZEDRAKE; i++)
				{
					if (nomeDrake[i][0] != '\0')
					{
						contar++;
					}
				}
			
        	if (contar == 0)
				{
					printf("No dragons registered at the moment\n\n");
				}
            else
            {
                for(i = 0; i < ARRSIZEDRAKE; i++)
                {
                    printf("%d - %s\n", i, nomeDrake[i]);
                }
            }
		}

		if (opcao == 6)//register dragons
        {
            while(tentarNovamente == 0)
            {
	            printf("Type a dragon's code that is not being used(a number between 0 and %d): ", ARRSIZEDRAKE-1);
	            scanf("%d", &codigoDrake);
	            if (codigoDrake >= 0 && codigoDrake < ARRSIZEDRAKE)
            	{
	            	if (checarCadastroDrake[codigoDrake] == 1)
	            	{
	            		printf("A dragon is already registered with this code, type 0 to try again or any other number to return to the main menu: ");
	            		scanf("%d", &tentarNovamente);
					}
					else
					{
						fflush(stdin);
						printf("Type the dragon's name: ");
                        scanf("%[^\n]s", nomeDrake[codigoDrake]);
						fflush(stdin);
                        printf("Type the dragon's age: ");
                        scanf("%d", &idadeDrake[codigoDrake]);
						
                        while (tentarNovamente == 0)
                        {
                            printf("Type the number of the dragon's element\n1 - earth\n2 - fire\n3 - water\n4 -  ice\n5 - wind: ");
                            scanf("%d", &elementoDrake[codigoDrake]);
                            if (elementoDrake[codigoDrake] >= 0 && elementoDrake[codigoDrake] <= 5)
                            {
                                printf("Dragon registered successfully\n\n");
                                checarCadastroDrake[codigoDrake] = 1;
                                switch (elementoDrake[codigoDrake])
                                {
                                case 1:
                                    strcpy(elementoDrakeString[codigoDrake], terra[0]);
                                    break;
                                case 2:
                                    strcpy(elementoDrakeString[codigoDrake], terra[1]);
                                    break;
                                case 3:
                                    strcpy(elementoDrakeString[codigoDrake], terra[2]);
                                    break;
                                case 4:
                                    strcpy(elementoDrakeString[codigoDrake], terra[3]);
                                    break;
                                default:
                                    strcpy(elementoDrakeString[codigoDrake], terra[4]);
                                    break;
                                }
                                break;
                            }
                            else
                            {
                                printf("Invalid element number, type 0 to try again or any other number to return to the main menu: ");
                                scanf("%d", &tentarNovamente);
                            }
                        }
                        break;
					}
            	}
	            else
	            {
	                printf("Invalid code, type 0 to try again or any other number to return to the main menu: ");
	                scanf("%d", &tentarNovamente);
	            }
            }
        }

        if (opcao == 7)//search dragon by name
        {
            while (tentarNovamente == 0)
			{
				fflush(stdin);
				printf("Type the dragon's name: ");
				scanf("%[^\n]s", drakeProcurado[0]);

				for (i = 0; i < ARRSIZEDRAKE; i++)
				{
					if (strcmpi(drakeProcurado[0], nomeDrake[i]) == 0)
					{
						printf("Dragon foun at position %d\n", i);
						printf("It's age is: %d years\n", idadeDrake[i]);
						printf("It's element is: %s\n", elementoDrakeString[i]);
						tentarNovamente = 1;
						i = ARRSIZEDRAKE+1;
						break;
					}
				}
				if (i!=ARRSIZEDRAKE+1)
				{
						
					printf("Dragon's name not found, type 0 to try again or any other number to return to the main menu: ");
					scanf("%d", &tentarNovamente);		
				}
       		}
       }

        if (opcao == 8)//delete dragon by code
        {
        	for (i = 0; i < ARRSIZEDRAKE; i++)
				{
					if (nomeDrake[i][0] != '\0')
					{
						contar++;
					}
				}
			
        	if (contar == 0)
				{
					printf("No dragons registered at the moment\n\n");
				}
			else
			{
				while (tentarNovamente == 0)
				{
					for(i = 0; i < ARRSIZEDRAKE; i++)
					{
						printf("%d - %s\n", i, nomeDrake[i]);
					}
					printf("Type the dragon's code: ");
					scanf("%d", &drakeExcluido);
					
					if (checarSeDragaoJaEstaLocado[drakeExcluido] == 1)
					{
						printf("This dragon is currently rented, it must be given back to be deleted.\n");
						break;
					}
	
					if (drakeExcluido >= 0 && drakeExcluido < ARRSIZEDRAKE)
					{
					    if (nomeDrake[drakeExcluido][0] == '\0')
	                    {
	                        printf("No dragons registered in this code.\n");
	                        break;
	                    }
	                    else
	                    {
	                        for (i = 0; i <= 1; i++)
	                        {
	                            nomeDrake[drakeExcluido][i] = '\0';
	                            elementoDrakeString[drakeExcluido][i] = '\0';
	                            idadeDrake[i] = 0;
	                        }
	                    printf("Dragon %s deleted successfully\n", nomeDrake[drakeExcluido]);
	                    checarCadastroDrake[drakeExcluido] = 0;
						break;
	                    }
					}
				}
			}
        }

        if (opcao == 9)//list rented dragon
        {
            for (i = 0; i < ARRSIZEDRAKE; i++)
				{
					if (drakeLocado[i][0] != '\0')
					{
						contar++;
					}
				}
			
        	if (contar == 0)
				{
					printf("No dragons rented at the moment\n\n");
				}
			else
            {
                for(i = 0; i < ARRSIZE; i++)
                {
                    printf("Dragon: %s, warrior that rented: %s, devolution limit date: ", drakeLocado[i], alugadores[i]);
                    for (e = 0; e < 3; e++)
                    {
                    	printf("%d/", data[i][e]);
					}
					printf("\n");
                }
			}
        }

        if (opcao == 10)//rent dragon
        {	
			for (i = 0; i < ARRSIZEGUERREIRO; i++)
				{
					if (nomeGuerreiro[i][0] != '\0')
					{
						contar++;
					}
				}
			for (i = 0; i < ARRSIZEDRAKE; i++)
				{
					if (nomeDrake[i][0] != '\0')
					{
						contarDrake++;
					}
				}
			
        	if (contar == 0 || contarDrake == 0)
				{
					printf("No warrior and(or) dragon registered\n");
				}
			
			else
			{
				while (tentarNovamente == 0)
				{
					printf("Type the warrior's code: ");
					scanf("%d", &codigoGuerreiro);
					if (!(codigoGuerreiro >=0 && codigoGuerreiro < ARRSIZEGUERREIRO))
					{
						printf("Invalid code, type 0 to try again or any other number to return to the main menu: ");
						scanf("%d", &tentarNovamente);
					}
					else if (nomeGuerreiro[codigoGuerreiro][0] == '\0')
					{
						printf("No warrior registered with this code, type 0 to try again or any other number to return to the main menu: ");
						scanf("%d", &tentarNovamente);
					}
					else if (checarSeGuerreiroJaTemDragao[codigoGuerreiro] == 1)
					{
						printf("This warrior already has a rented dragon, type 0 to try again or any other number to return to the main menu: ");
						scanf("%d", &tentarNovamente);
					}
					else
					{
						printf("Type the dragon's code: ");
						scanf("%d", &codigoDrake);
						if (nomeDrake[codigoDrake][0] == '\0')
						{
							printf("No dragon registered with this code, type 0 to try again or any other number to return to the main menu: ");
							scanf("%d", &tentarNovamente);
						}
						else if (!(codigoDrake >=0 && codigoDrake < ARRSIZEDRAKE))
						{
							printf("Invalid code, type 0 to try again or any other number to return to the main menu: ");
							scanf("%d", &tentarNovamente);
						}
						else if (checarSeDragaoJaEstaLocado[codigoDrake] == 1)
						{
							printf("This dragon is already rented, type 0 to try again or any other number to return to the main menu: ");
							scanf("%d", &tentarNovamente);
						}
						else 
						{
							strcpy(drakeLocado[codigoGuerreiro], nomeDrake[codigoDrake]);
							strcpy(alugadores[codigoGuerreiro], nomeGuerreiro[codigoGuerreiro]);
							checarSeDragaoJaEstaLocado[codigoDrake] = 1;
							checarSeGuerreiroJaTemDragao[codigoGuerreiro] = 1;
							data[codigoGuerreiro][0] = tempo->tm_mday;
							data[codigoGuerreiro][1] = tempo->tm_mon+1;
							data[codigoGuerreiro][2] = tempo->tm_year+1901;
							
							d--;
							strcpy(historicoGuerreiro[d], alugadores[codigoGuerreiro]);
							strcpy(historicoDrake[d], drakeLocado[codigoGuerreiro]);
							
							printf("Dragon rented successfully!\n\n");
							break;
						}
					}
            	}
			}
        }
        
        if (opcao == 11)//give rented dragon back
        {
			for (i = 0; i < ARRSIZEGUERREIRO; i++)
				{
					if (nomeGuerreiro[i][0] != '\0')
					{
						contar++;
					}
				}
			for (i = 0; i < ARRSIZEDRAKE; i++)
				{
					if (nomeDrake[i][0] != '\0')
					{
						contarDrake++;
					}
				}
			
        	if (contar == 0 || contarDrake == 0)
				{
					printf("No warrior and(or) dragon registered\n");
				}
			
			else
			{
				while (tentarNovamente == 0)
				{
				
					printf("Type the warrior's code: ");
					scanf("%d", &codigoGuerreiro);
					if (!(codigoGuerreiro >=0 && codigoGuerreiro < ARRSIZEGUERREIRO))
						{
							printf("Invalid code, type 0 to try again or any other number to return to the main menu: ");
							scanf("%d", &tentarNovamente);
						}
						
					else if (nomeGuerreiro[codigoGuerreiro][0] == '\0')
						{
							printf("No warrior registered with this code, type 0 to try again or any other number to return to the main menu: ");
							scanf("%d", &tentarNovamente);
						}
		
					else if (checarSeGuerreiroJaTemDragao[codigoGuerreiro] == 0)
					{
						printf("This warrior doesn't have a rented dragon, type 0 to try again or any other number to return to the main menu: ");
						scanf("%d", &tentarNovamente);
					}
						else
						{
							drakeLocado[codigoGuerreiro][0] = '\0';
							alugadores[codigoGuerreiro][0] = '\0';
							checarSeDragaoJaEstaLocado[codigoDrake] = 0;
							checarSeGuerreiroJaTemDragao[codigoGuerreiro] = 0;
							data[codigoGuerreiro][0] = '\0';
							data[codigoGuerreiro][1] = '\0';
							data[codigoGuerreiro][2] = '\0';
							printf("Dragon given back successfully\n\n");
							break;
						}
				}
			}	
	    }
	    
	    if (opcao == 12)//history
	    {
	    	for (i = 0; i < TAMANHOHISTORICO; i++)
				{
					if (historicoGuerreiro[i][0] != '\0')
					{
						contar++;
					}
				}
			if (contar == 0)
				{
					printf("No transactions made at the moment\n");
				}
			else
			{
		    	for (i = TAMANHOHISTORICO-1; i >= 0; i--)
		    	{
		    		printf("%s was rented by %s\n ", historicoDrake[i], historicoGuerreiro[i]);
				}
			}
		}
		tentarNovamente = 0;
		contarDrake = 0;
		contar = 0;
    }
    while(opcao != 0);
    return 0;
}
