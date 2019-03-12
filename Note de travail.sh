Structure principale de la fonction:

ft_printf --> pf_manager
(si pas de %) -> pf_str_manager(va ecrire chaque caractere de la chaine)

(si un %) --> ft_parsing(a renommer): Initialise flag
	-> fill_parsing: va prendre la section entre le % et les conversions)
et l isole dans une chaine(flag.parsing)
	-> fill_flag: A partir de flag.parsing, il va trier toute les informations
dans une structure.

	--> ft_conversion (fonction a separer): une fonction est dédiée
a chaque conversion, qui contient tout les options qui lui sont propres.
	-> Pour chaque conversion, une fonction revient, il s agit de handle_field:
Son role est de mettre en place les regles de la taille minimum de champs en fonction
des options. Ces regles sont communes à chaqu un des flags.


NB 
	- Toute les fonctions que vous allez trouvé dans (conversion/parsing)_utils sont des
fonctions simples assujetties aux fonctions principales de parsing/conversion.

	- Pour certain tests, il faut enlever __attribute__ (quand on teste dans son coin)

	- Les tests faux de basic tests portent sur des fonctionnalitées que nous n avons pas encore
codées.

	- Certain tests de moulitest sortent de l espace...

	- J ai fait un microscript (launch_test) pour lancer des tests :) c est de la demer mais ca fait gagner du
temps ;). Par contre , pour le moment pour l utiliser j ai du créer un autre main de test (main1.c)
que j ai pas mis dans le git pour que ça reste propre. 

	- Oui, dans l etat ft_printf est plus une clio qu une ferrari, mais je pense que notamment fill_flag
peut etre grave ameliorer comme on avait parlé avec Cam!

Si on se revoit pas avant que je parte, plein de bonne chose et on se voit a NOISY LE CHAMPS 💥💥



Pommedepin
- c, p & d : quand tu leur envoie un argument qui est égal 0, ils sont censé renvoyer qqchose qu on ne fait pas
- #, les modifieurs hh ouxXf à gérer

A rajouter dans la fonction pour les basic test :
ulltoa pour positif
lltoa pour négatif --> à gérer pour Chewie

16 pour hexadecimal
8 pour octal
_x_ pour minuscules
_X_ pour majuscule

Pbs detectés :
