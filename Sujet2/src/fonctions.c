#include "fonctions.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>


/*--------------------------------------------------------------------------------------------*/


scheduler *create_scheduler() {
    scheduler *s = malloc(sizeof(scheduler));
    for (int i = 0; i < 6; i++) {
        s->queues[i] = create_queue();
    }
    return s;
}




void ajout_activite(scheduler *s, process *p) {//ajout d'un processus à l'ordonanceur

    unsigned prio = p->priority;
    queue *q = s->queues[prio];

    push_queue(q, p);// on ajoute l'element a la sous file correspondante
}




bool step(scheduler *s) {//execution du premier processus de l'ordonanceur
    for (unsigned i = 0; i < 6; i++) { //on parcours le tableau des sous file pour trouver un element
        queue *q = s->queues[i];
        if (!empty_queue(q)) { //si la file n'est pas vide
            process *p = pop_queue(q);//prelevement de l'element
            execute_process(p);//execution
            free(p);//desallocation de la memoir du processus
            return true;//confirmation de l'execution du debut de la file
        }//file vide donc passage à la file suivante
    }//l'ordonanceur n'a pas trouve d'element
    return false;// on previent qu'il n'y a pas d'element dans l'ordonanceur
}


void run_all(scheduler *s) {//execution de tous les elements de l'ordanceur jusqu'à ce qu'il soit vide
    while (step(s)) {} //execute step jusqu'à ce que step lui indique que l'ordonanceur est vide
}


/*--------------------------------------------------------------------------------------------*/






/**
 * Process methods
 */

process *create_process(char *name, float time, unsigned priority) {
    process *proc = malloc(sizeof(process));
    proc->name = name;
    proc->time = time;
    proc->priority = priority;
    return proc;
}

void display_process(process *proc) { // affiche les donees du processus
    printf("[%s, %u, %u] ", proc->name, proc->time, proc->priority);
}

void execute_process(process *proc) {// execute le processus
    display_process(proc);
    printf("\n");
    usleep(proc->time * 10000); //attend 10 fois time en milliseconde
}

/**
 * Node methods
 */

void display_node(node *no) { // affiche les donees du noeud
    display_process(no->element);
}

void display_next_and_node(node *no) { //affiche les donees du noeud et des suivants jusqu'au NULL
    display_process(no->element);
    if (no->next) {
        display_next_and_node(no->next);
    }
}

/**
 * Queue methods
 */

queue *create_queue() {
    queue *q = malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

bool empty_queue(queue *q) {
    return (q->head == NULL);
}

void push_queue(queue *q, process *p) { // ajoute un processus à la file
    node *new_node = malloc(sizeof(node)); //defini le nouveau noeud
    new_node->element = p; //defini p comme le contenu de ce noeud
    new_node->next = NULL; //defini le noeud comme une fin de file
    if (empty_queue(q)) { //cas d'une file vide
        q->head = new_node;
        q->tail = new_node;//la maille devient debut et fin
        return;
    }//cas file non vide
    q->tail->next = new_node;//la fin de la file pointe vers le nouveau noeud
    q->tail = new_node;//le nouveau neod devient la nouvelle fin
}

process *pop_queue(queue *q) {// retire le dernier entre dans la file
    if (empty_queue(q))
        return NULL;// si la file est vide on renvoie NULL
    node *head = q->head; //extraction du debut de la file
    q->head = head->next; //defini nouveau debut
    head->next = NULL;
    process *res = head->element; //defini la sorti
    head->element = NULL;
    free(head); //desalloue la mémoire de la maille
    if (q->head == NULL)
        q->tail = NULL; //si la nouvelle file est vide, on empeche que tail pointe une destination invalide
    return res;
}

void display_queue(queue *q) { //affiche les processus de la file : utilise pour les testes
    if (q->head)
        display_next_and_node(q->head);
    printf("\n\n");
}


/*--------------------------------------------------------------------------------------------*/













