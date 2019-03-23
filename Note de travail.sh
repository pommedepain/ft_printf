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



# Pommedepin
- c, p & d : quand tu leur envoie un argument qui est égal 0, ils sont censé renvoyer qqchose qu on ne fait pas
- '#', les modifieurs hh ouxXf à gérer


# A rajouter dans la fonction pour les basic test :
ulltoa pour positif
lltoa pour négatif --> à gérer pour Chewie

16 pour hexadecimal
8 pour octal
10 pour décimal
_x_ pour minuscules
_X_ pour majuscule


# Aide mémoire :
char	*ft_ulltoa_base(unsigned long long value, int base_size, char *base); pour pos
char	*ft_itoa(int n);
char	*ft_lltoa_base(long long value, int base_size, char *base); pour nég (à corriger par Chewie)
char	*ft_ltoa_base(long value, int base); base conversion to x pour pos
char	*ft_ltoa_base_2(long value, int base); base conversion to X
char	*ft_ltoa(long n) : long to char *




char	*ft_flag_d(va_list list, t_flag flag)
{
	if (flag.modif)
	{
		if (ft_strcmp(flag.modif, "ll") == 0)
			flag.to_print = ft_lltoa_base(va_arg(list, long long), 10, _x_);
		if (ft_strcmp(flag.modif, "h") == 0)
			flag.to_print = ft_itoa(va_arg(list, int));
		if (ft_strcmp(flag.modif, "l") == 0)
			flag.to_print = ft_ltoa_base(va_arg(list, long), 10);
		if (ft_strcmp(flag.modif, "hh") == 0)
			flag.to_print = ft_itoa(va_arg(list, int));
	}
	else
		flag.to_print = ft_itoa(va_arg(list, int));
	if (ft_chrstring(flag.option, "+ ") == 1)
		flag.to_print = add_sign(flag.to_print, flag.option);
	if (flag.precision >= 0)
		flag.to_print = zero_fill(flag.to_print, flag.precision);
	flag.to_print = handle_field(flag);
	return (flag.to_print);
}


# Pbs détectés :
- x & X : les valeurs négatives pas gérées. ft_ulltoa_base est celui qui y arrive le mieux mais bug;
- '#' à faire
- 0 et NULL comme valeurs doivent renvoyer ^@ au lieu de rien
- hd ou hhd inverse visiblement la valeur dans les basic test avec printf (ex : -42 devient 42) + peut la modifier (ex : -129 devient 127)
- u a l air d avoir un comportement différent en fonction des valeurs pos ou nég et du cast associé

# Corrigé :
- x : conversions l et ll en positif done
	--> dans flag_x, déclaration va_arg en variable silenced
	--> utilisation ft_ltoa_base_2

# Pour les leaks:

	Les leaks sont situés : Dans la structure et dans les fonctions de conversion_util.

	Probleme:
	- To_print est la "hot string" de la fonction, elle est souvent modifiées, mais parfois il n a pas ete aloués 
	avant de passer dans certaine fonction, meme jusqu a la fin de ft_printf. Ce qui fait aborté tout le bordel...
	Comment savoir si elle a ete deja alloué? (pour les strings par exemple elle n est pas nulle mais elle n a pas ete allouée..)

# Petit probleme de read / write dans ft_parsing

	if (!(dest = (char *)malloc(sizeof(char) * len + 2)))
		return (NULL);
	dest[len + 1] = '\0';

(rajouter 1 a la len et mettre un '/0' a len + 1). Je sais pas pourquoi mais ca enleve le probleme sans faire de leaks comme ca)
