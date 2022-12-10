# TP_ProgProc
Devoir de programmation procédural du binôme Yanis Aissaoui et Nicolas Ussont à rendre pour la date du 10 décembre


Introduction:
Afin d'exécuter ce programme on se servira de la commande make pour compiler puis make run pour exécuter.

__ Sujet2 __

Le sujet demande de mettre en place un ordonnanceur qui exécute en priorité selon l’ordre de priorité (entier de 0 à 6) puis selon l’ordre d'arrivé fifo (premier entré premier sortie) et pour cela nous devons mettre en place une file.

La stratégie que nous avons adoptée pour répondre au cahier des charges est un tableau de file de taille 6, donc chaque file correspond à un et seulement un ordre de priorité.
Chaque file est construite avec le principe d’une liste chaînée dont on garde le dernier élément. La structure de la liste chainé permet en effet de garantir un pop et un push (ajout et retrait d'élément) en temps constant selon le principe fifo.

Nous avons choisi cette structure parce qu'en plus d’être simple, elle exploite parfaitement les propriétés de la file pour que le step et que l’ajout_activite soit en temps constant. Les complexités temporelles et spatiales sont minimales.

Pour ajout_activite, on va simplement rajouter le processus à la file correspondant à son ordre de priorité. Pour le step, on va parcourir le tableau de 0 à 5 jusqu’à ce qu’on trouve une file non vide. Dans ce cas on pop le processus de la file et on l'exécute. Comme demandé par le sujet, les processus prioritaires sont exécutés en premier et la structure de file permet que pour de processus au même ordre de priorité, ce soit le plus récent qui soit exécuté.
La fonction step renvoie un booléen pour permettre à la fonction run de savoir si l'ordonnanceur est vide.
