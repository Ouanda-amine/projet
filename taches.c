#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define Max 100

struct tache {
    int id ;
    char titre[30];
    char description[100];
    char dateEch[100];
    char priorite[20];
};

void CreerTache( struct tache *t , int id ){

    t->id=id;
    printf("entrez le titre du tache : ");
    scanf("%s",t->titre);
    printf("entrez la description du tache : ");
    scanf("%s",t->description);
    printf("entrez la date d'échéance du tache : ");
    scanf("%s",t->dateEch);
    printf("entrez la priorité du tache : ");
    scanf("%s",t->priorite);


}
void afficherTaches(struct tache t){
    printf("id __ : %d  . \n",t.id);

    printf("Le titre   __ : %s  . \n",t.titre);

    printf("la description __ : %s  . \n",t.description);

    printf("la date d'échéance : %s  . \n",t.dateEch);

    printf("la priorité  __ : %s  . \n",t.priorite);


}
void modifierTache(struct tache *t , int monchoix , char nouvelleV[]){
    switch(monchoix){
        case 1 : 
        strcpy(t->description,nouvelleV);
        break;
        case 2 : 
        strcpy(t->dateEch,nouvelleV);
        break;
        case 3 :
        strcpy(t->priorite,nouvelleV);
        break;

        default : 
        printf("choix indisponible");
        break;


    }
}

int main(){

    struct tache  lestaches[Max];
    int choix;
    int id =0;

    do{
        printf("entrez 1 pour la creation d'une tache . \n  entrez 2 pour l'affichage d'une tache . \n  entrez 3 pour la modification d'une tache . \n  __________  :  ");
        scanf("%d",&choix);

        switch(choix){
            case 1 : 
            CreerTache(&lestaches[id],id +1);
            id++;
            break;
            case 2 : 
            for (int i = 0;i<id;i++){
                afficherTaches(lestaches[i]);
                break;
            }
            break;
            
            case 3 :
            char new[100];
            int idchange;
            int lechoix;

            printf("entrez l'id du tache");
            scanf("%d",idchange);

            printf("pour modifier la discription entrez 1  . \n pour modifier la  date d'échéance entrez 2  . \n pour modifier la priorite entrez 3  . \n entrez votre choix__ : ");
            scanf("%d",&lechoix);

            printf("entrez votre modification : ");
            scanf("%s",&new);

            modifierTache(&lestaches[idchange-1],lechoix,new);

            
        }


    }while(choix !=0);


}


