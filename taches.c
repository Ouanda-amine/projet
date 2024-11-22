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
    char statut[30];
};
void CreatTache(struct tache *t, int idd){
    t->id=idd;
    printf("entrez le titre du tache :  ");
    scanf(" %[^\n]",t->titre);
    printf("entrez la description tache :  ");
    scanf(" %[^\n]",t->description);
    printf("entrez la  date d'echeance du tache :  ");
    scanf(" %[^\n]",t->dateEch);
    while (1) {       
        printf("Entrer le statut ( complete / incomplte): ");
        scanf("%s", t->statut);

        if (strcmp(t->statut, "complete") == 0 || strcmp(t->statut, "incomplete") == 0) {
            break;                                                             
        } else {
            printf("choix indisponible , entrez 'complete' ou 'incomplete'.\n");
        }
    }
   

   while (1) {       
        printf("Entrer la the priorite ( high / low): ");
        scanf("%s", t->priorite);

        if (strcmp(t->priorite, "high") == 0 || strcmp(t->priorite, "low") == 0) {
            break;                                                             
        } else {
            printf("choix indisponible , entrez 'high' ou 'low'.\n");
        }
    }

}
void afficherTache(struct tache t ){
  if(t.id != 0 ){
    printf("l'id _  : %d \n",t.id);

    printf("la tache _  : %s \n",t.titre);

    printf("la description _  : %s \n",t.description);

    printf("la date _  : %s \n",t.dateEch);

    printf("le statut _  : %s \n",t.statut);

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
        printf("indisponible ");
        break;
    }
}
void supprimerTache(struct tache *t){
    t->id=0;
    printf("suppression avec succes");

}
void filtreTache(struct tache *t , char prio[20]){
    if(strcmp(t->priorite,prio)==0){
        printf("l'id _  : %d \n",t->id);

        printf("la tache _  : %s \n",t->titre);

        printf("la description _  : %s \n",t->description);

        printf("la date _  : %s \n",t->dateEch);

        printf("la date _  : %s \n",t->statut);

        printf("la priorite _  : %s \n",t->priorite);
    }
}

void filtrerParStatut(struct tache *t , char stat[20]){

    if(strcmp(t->statut,stat)==0){

        printf("l'id _  : %d \n",t->id);

        printf("la tache _  : %s \n",t->titre);

        printf("la description _  : %s \n",t->description);

        printf("la date _  : %s \n",t->dateEch);

        printf("la e statut _  : %s \n",t->statut);

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
    char lestatut[30];

            
    

    do {
        printf(" 1 creer \n 2 afficher \n 3 modifier \n 4 supprimer  \n 5 filtrer par priorité \n 6 filtrer par statut \n   ");
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
            printf("entrez la priorite (high ou low) : ");
            scanf("%s",laprio);
            if(strcmp(laprio,"high")==0  || strcmp(laprio,"low")==0){
                for (int i  =0 ; i<id ; i++){
                    filtreTache(&lestaches[i],laprio);

                }
            }else{
                printf("hors ch !!!");
            
            
             
                    
            }
            break;
            case 6 :
            printf("entrez le statut  : ");
            scanf("%s",lestatut);
            if(strcmp(lestatut,"complete")==0  || strcmp(lestatut,"incomplete")==0){
                for (int i  =0 ; i<id ; i++){
                    filtrerParStatut(&lestaches[i],lestatut);

                }
            }else{
                printf("hors choix !!!");
            
            
             
                    
            }
            break;




    

           
            default : 
            printf("error");
            break;

            
        }
    }while(choix != 0);
}