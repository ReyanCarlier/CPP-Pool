**5 actions de cast disponibles :**

- Les conversions
- Les réinterprétations
- Les changements de type qualifier
- Les downcasts
- Les upcasts

**Taille des types :**
- char : 1 octet
- int : 4 octets
- long : 4 octets
- double : 8 octets

**Définitions :**
=================

Démotion :
----------
La démotion consiste à la conversion d'une variable d'un type plus gros vers un type plus petit, induisant une perte de précision.

Promotion :
-----------
La promotion consiste à la conversion d'une variable d'un type plus petit vers un type plus gros, sans perte de précision.


**STATIC CAST**
---------------

Le static cast permet de faire un certain nombre de conversions simples, mais également de pouvoir naviguer dans l'arbre d'héritage.
La conversion est effectuée même dans le cas d'une démotion.

En pratique, le static cast s'écrit de la manière suivante :

```C++
int	main(void)
{	
	int		a = 42; // Valeur de référence
	double	b = a; // Promotion implicite -> OK

	int		c = b; // Démotion implicite -> NON
	int		d = static_cast<int>(b); // Démotion explicite -> OK

	return 0;
}
```

Dans le cas d'utilisation de classes mères / enfants, le static cast est utilisé de la manière suivante :

```C++
class Parent				{}
class Child1: public Parent	{};
class Child2: public Parent {};

class Unrelated				{};

int	main(void)
{
	Child1		a; // Valeur de référence

	Parent *	b = &a; // Promotion implicite -> OK

	Child1 *	c = b;  // Démotion implicite -> NON
	Child2 * 	d = static_cast<Child2 *>(b); -> // Démotion explicite -> OK

	Unrelated * e = static_cast<Unrelated *>(&a); // Conversion explicite -> NON

	return 0;
}
```
Il n'est pas possible de convertir via static cast deux éléments de classes différentes non affiliées.
Il est possible de convertir une classe enfant vers la classe mère, sans précision du cast.
Il est possible de convertir une classe mère en classe enfant, avec précision du cast (et perte de précision).

L'avantage du static cast réside dans le fait qu'il est en mesure de détecter si les deux éléments de la conversion appartiennent ou non à un même arbre d'héritage.

**DYNAMIC CAST**
----------------

Il s'agit du seul cast en C++ qui est exécuté au runtime (à l'exécution). Tous les autres casts sont faits à la compilation.
Le dynamic cast ne bloquera pas la compilation du programme, mais peut échouer lors de son exécution, il devient alors possible de créer toute une gestion d'erreur dans le cas où notre dynamic cast ne fonctionnerait pas correctement.

Le dynamic cast ne fonctionne que dans le cas d'une **instance polymorphique**, cela signifie qu'au moins une des fonctions membres de la classe en question devra être virtuelle.

L'utilisation du dynamic cast ne se fait que dans le cas d'une démotion et vérifie si ce downcast est possible ou non, et **uniquement dans le cas d'utilisation de pointeurs ou de références**.

Dans le cas d'une démotion explicite par pointeur, le dynamic cast nous renverra NULL en cas d'échec.
A l'inverse, dans le cas d'utilisation par référence, *une référence ne pouvant être null*, il faut procéder à un try&catch.

Utilisation :

```C++
#include <iostream>
#include <typeinfo>
#include <exception>

class Parent {
	public:
		virtual ~Parent(void) {};
}

class Child1: public Parent {};
class Child2: public Parent {};

int	main(void)
{
	Child1		a;		// Valeur de référence
	Parent *	b = &a; // Promotion implicite -> OK

	// Démotion explicite par pointeur :
	Child1 *	c = dynamic_cast<Child1 *>(b);
	std::cout << (c == NULL ? " Conversion impossible" : "Conversion OK") << std::endl;

	// Démotion explicite par référence :
	try {
		Child2 &	d = dynamic_cast<Child2 &>(*b);
		std::cout << "Conversion OK" << std::endl;
	}
	catch (std::bad_cast &bc) {
		std::cout << "Conversion impossible: " << bc.what() << std::endl;
		return 0;
	}
	return 0;
}
```
Dans notre exemple 1, la conversion sera un succès, car le type réel de **b** est en réalité Child1.
Dans notre exemple 2, la conversion va échouer, car Child2 n'est pas le type réel de **b**.