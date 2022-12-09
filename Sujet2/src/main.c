#include <stdio.h>
#include <stdlib.h>

#include "fonctions.h"

/*
 * La stratégie pour répondre la problématique du sujet 2 va être de représenter
 * la file de l'ordonnanceur par 6 files dans un tableau (chacune file représente
 * un et un seul ordre de priorité).
 * Pour l'ajout il suffira de rajouter l'élément à la bonne file
 * Pour le step on parcourra le tableau de file de 0 à 6 jusqu'à trouver un
 * processus.
 */



int main() { 

    scheduler *s = create_scheduler();

    for (int j = 0; j < 8; j++)  {
        for (int i = 0; i < 6; i++){
            ajout_activite(s, create_process("nom_proc", 6+j-i, i));
        }
    }

    ajout_activite(s, create_process("nouveau_processus", 200, 2));
    run_all(s);

    return 0;
}

