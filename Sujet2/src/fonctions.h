#ifndef PROJET_ORDO_STRUCTS_H
#define PROJET_ORDO_STRUCTS_H

#include <stdbool.h>


typedef struct process { //structure d'un processus
    char *name;
    unsigned time;
    unsigned priority;
} process;

typedef struct node { //structure d'un noeud de file
    struct node *next; //noeud suivant
    process *element; //contenu du noeud
} node;

typedef struct queue {//structure d'une file
    node *head; //debut de la file
    node *tail; //fin de la file
} queue;


typedef struct scheduler {//structure de l'ordanceur
    queue *queues[6];
} scheduler;





process *create_process(char *name, float time, unsigned priority);

void display_process(process *proc);

void execute_process(process *proc);

void display_node(node *no);

void display_next_and_node(node *no);

queue *create_queue();

bool empty_queue(queue *q);

void push_queue(queue *q, process *p);

process *pop_queue(queue *q);

void display_queue(queue *q);

void ajout_activite(scheduler *s, process *p);

bool step(scheduler *s);

void run_all(scheduler *s);

scheduler *create_scheduler();

#endif //PROJET_ORDO_STRUCTS_H