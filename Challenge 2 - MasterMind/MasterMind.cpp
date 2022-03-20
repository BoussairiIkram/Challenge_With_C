#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void GenererCodeMystere(char* Color_Mystere, int Taille){
	srand(time(NULL));
	
    for(int i=0;i<Taille-1;i++)
      {switch (rand()%5) 
       {case 0 : Color_Mystere[i]={'R'};break;
    	case 1 : Color_Mystere[i]={'O'};break;
    	case 2 : Color_Mystere[i]={'J'};break;
    	case 3 : Color_Mystere[i]={'B'};break;
		case 4 : Color_Mystere[i]={'V'};break;}	
     }}

int main(){
	char Color_Mystere[5],Color[5];
    char Color_Vraie,Color_Exist;
    int Max_Tentatif,Tentatif=0,Rejouer;

do{	
    GenererCodeMystere(Color_Mystere,5);
	printf("%s.\n",Color_Mystere);
	
	printf("Donnez Le nombre de tentatif :");
	scanf("%d",&Max_Tentatif);

do{
	Color_Vraie=0,Color_Exist=0;
	printf("Tentatif: %d/%d ; Donnez Color Mystere : ",Tentatif+1,Max_Tentatif); scanf("%s",Color);
	
	for(int i=0;i<4;i++){
		if(Color[i]==Color_Mystere[i]) Color_Vraie++;  
	}
	if(Color_Vraie==4) {
		printf("Bravo! Le nombre Mystere est bien %s.\n",Color_Mystere);
		break;
	}
	
	for(int i=0;i<4;i++){
		if(strchr(Color_Mystere,Color[i])) Color_Exist++;
	}
    
    
	printf("Color Vraie : %d - Color mal place: %d.\n",Color_Vraie,Color_Exist-Color_Vraie);
	 /*Couleur mal placé = Couleur qui existe -couleur qui existe et vraie.*/
	Tentatif++;
	
}while(Tentatif<Max_Tentatif);

if(Tentatif == Max_Tentatif && Color_Vraie!=4) printf("Oups Vous avvez atteindre le nombre max des tentatif.\n");

printf("\nVoulez-vous Rejouer?   1=oui\t2=non \t\t");
scanf("%d",&Rejouer);
}
while(Rejouer==1);

printf("A Bien Tot!");
	return 0;
}
