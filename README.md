# Demineur-AURELIEN & PAUL MI7


Bienvenue à toi jeune démineur !

Paul et Aurélien sont heureux de te présenter leur jeu du démineur. 

Pour jouer, il te suffit de télécharger tous les fichiers dans ce dépôt. Ensuite il faut que tu te rendes sur ton terminal, et tu te places dans le même fichier où tu as téléchargé nos fichiers.

Pour compiler, rien de plus ne simule : rentre "make" et ça marche ! Pas besoin de d'inquiéter, il n'y a pas de rm* 

Enfin, tu rentres "./demineur" et c'est bon. Profite à fond de notre jeu !!!

PS : 

1) Concernant la partie personnalisée : nous savons comment faire, mais nous n'avons pas eu le temps pour. Pour ce faire, il faut créer une condition sur la taille du tableau comme nous l'avons faire pour qu'elle soit supérieure à 0 et inférieure à 26. Ensuite, il faut générer des bombes par rapport au nombre de lignes du tableau.

2) On a remarqué un problème qui n'est pas présent sur Xcodes (plateformes sur Mac-Os où l'on code et où l'on teste notre programme moduler) sur Mac mais qui est présent sur Linux. Sur Xcodes, lorsque l'on rentre une valeur différente de int (entiers), c'est-à-dire un char (caractères) par exemple, alors cela indique que ce n'est pas une bonne valeur et qu'il faut ressaisir une autre valeur, or sur Linux lorsque l'on applique le Makefile (fichier qui permet de faire fonctionner notre programme à partir de terminal) et qu’on lance notre programme et que l'on rentre une valeur différente de int (entiers) cela tourne en boucle c'est pourquoi nous prenons la décision de stopper le programme d'afficher un message qui indique à l'utilisateur de relancer le programme (retapez "./demineur" en saisissant cette fois des int (entiers).

