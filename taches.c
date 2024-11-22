#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct tache {
    int id;
    char titre[30];
    char description[100];
    char  dateEch[100];
    char priorite[20];
};
void CreatTache(struct tache *t, int idd){
    t->id=idd;
    printf("entrez le titre du tache :  ");
    scanf("%s",t->titre);
    printf("entrez la description tache :  ");
    scanf("%s",t->description);
    printf("entrez la  date d'echeance du tache :  ");
    scanf("%s",t->dateEch);
    printf("entrez le priorite du tache :  ");
    scanf("%s",t->priorite);

}
void afficherTache(struct tache t ){
  if(t.id != 0 ){
    printf("l'id _  : %d \n",t.id);

    printf("la tache _  : %s \n",t.titre);

    printf("la description _  : %s \n",t.description);

    printf("la date _  : %s \n",t.dateEch);

    printf("la priorite _  : %s \n ___________________________ \n",t.priorite);
  }

}
void modifierTache(struct tache *t,int determin , char newval[]){
    switch(determin){
        case 1 :
        strcpy(t->description,newval);
        break;
        case 2 :
        strcpy(t->dateEch,newval);
        break;
        case 3 : 
        strcpy(t->priorite,newval);
        break;

        default : 
        printf("indisponible");
        break;
    }
}
void supprimerTache(struct tache *t){
    t->id=0;
    strcpy(t->titre,"");
    strcpy(t->description,"");
    strcpy(t->dateEch,"");
    strcpy(t->priorite,"");

    printf("suppression avec succes");

}
void filtreTache(struct tache *t , char prio[20]){
    if(strcmp(t->priorite,prio)==0){
        printf("l'id _  : %d \n",t->id);

        printf("la tache _  : %s \n",t->titre);

        printf("la description _  : %s \n",t->description);

        printf("la date _  : %s \n",t->dateEch);

        printf("la priorite _  : %s \n",t->priorite);
    }
}
int main(){
    struct tache lestaches[MAX];
    int id =0;
    int choix;
    int idmod,lechoix;
    char new[30];
    int idsup ;
    char laprio[20];

            
    

    do {
        printf(" 1 creer \n 2 afficher \n 3 modifier \n 4 supprimer     ");
        scanf("%d",&choix);

        switch (choix){
            case 1 :
             CreatTache(&lestaches[id],id+1);
            id++;
            break;
            case 2 : 
            for (int i  =0 ; i<id ; i++){
                    afficherTache(lestaches[i]);
                    
            }
            break;
            case 3 :
           

            printf("entrez l'id du tache a modifier : ");
            scanf("%d",&idmod);

            printf("1 modifier description \n 2 modifier dateEcheante \n 3 modifier priorite ");
            scanf("%d",&lechoix);

            printf("entrez votre modification : ");
            scanf("%s",new);

            modifierTache(&lestaches[idmod-1],lechoix,new);

            break;

            case 4 :
            printf("entrez l 'id du tache a supprimer : ");
            scanf("%d",&idsup);

            supprimerTache(&lestaches[idsup-1]);
            break;
            case 5 :
            printf("entrez la priorité (high ou low) : ");
            scanf("%s",laprio);
            
            
             for (int i  =0 ; i<id ; i++){
                    filtreTache(&lestaches[i],laprio);
                    
            }
            break;



    

           
            default : 
            printf("error");
            break;

            
        }
    }while(choix != 0);
}