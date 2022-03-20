#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int GenererNombreAleatoire(int Min, int Max){
	// Initialiser le générateur de nombre pseudo-aléatoires.
	srand(time(NULL));
	// Retourner une valeur aleatoire entre Min et Max
	return (rand()%(Max-Min+1))+Min;  
}

int main(){
    int MaxTentatif,Tentatif,n; // n : va contenir le nombre saisi par l'utilisateur.
    int Rejouer=2; 

do{
	int N_Mystere= GenererNombreAleatoire(0,100);
	Tentatif=1;
	printf("%d",N_Mystere);
	 
    printf("Choissisez le nombre maximal de tentative:");
    scanf("%d",&MaxTentatif);
    
    do{
    	printf("Tentative:%d \t Donnez le nombre Mystere : ",Tentatif);
    	scanf("%d",&n);
    
		if(n>N_Mystere) printf("***C'est Moins !***\n");
		else if(n<N_Mystere) printf("***C'est Plus !***\n");
		else{
			printf("\n***Bravo! Le Nombre Mystere est bien %d.***\n",n);
    		break;
		}
    	
    	Tentatif++; 
	}while(Tentatif<=MaxTentatif);
    
    if(Tentatif-1==MaxTentatif && n!=N_Mystere) 
	 printf("\n------OUPS Vous-avez atteindre le nombre maximal de tentative. le Nombre Mystere est : %d.-------\n",N_Mystere);
    
    printf("\nVoulez Vous rejouer? 1:Yes , 2: No  : ");
    scanf("%d", &Rejouer);
}while(Rejouer == 1);

printf("A Bien tot!\n");
 
 return 0;
}
