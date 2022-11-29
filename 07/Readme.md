INTRODUCTION
============

Les templates sont une syntaxe du C++ permettant d'écrire des patrons / modèles de code, à la manière des textes à trous en introduisant des variables de type.
Les templates tirent leurs origines des MACRO paramétriques de C.
Il sera alors possible de définir des fonctions templates ainsi que des classes / structures templates.
Les templates pourront être alors utilisés par le compilateur pour instancier les variables de types.

SYNTAXE
======

```C++
// Sans template :
int		max(int x, int y)
{
	return (x >= y ? x : y);
}
// Avec template, T désignant un certain type (toujours le même) :
T		max(T x, T y)
{
	return (x >= y ? x : y);
}
```
Pour que le compilateur comprenne qu'il faut utiliser les templates (car le code précédent ne compilera pas), on doit procéder à l'ajout de certains éléments :
```C++
// On déclare le type T comme étant un template.
template<typename T>

T const	max(T const & x, T const & y)
{
	return (x >= y ? x : y);
}
```
*On favorise l'utilisation de références constantes s'il n'y a pas de modifications des paramètres.*

UTILISATION
===========

Il existe deux manières d'instancier un template, soit explicite soit implicite.

```C++
#include <iostream>

template<typename T> // Définition du template

T const	max(T const & x, T const & y)
{
	return (x >= y ? x : y);
}

int	foo(int x)
{
	std::cout << "On peut faire quelque chose ici..." << std::endl;
	return (x);
}

int main(void)
{
	{
		int	a = 21;
		int	b = 42;

		int	implicit_max = max(a,b); // Instanciation implicite

		std::cout << "La plus grande valeur entre " << a << " et " << b << " est " << implicit_max << std::endl;
	}
	{
		float a = 21.0f;
		float b = 42.0f;

		int	explicit_max = max<float>(a,b); // Instanciation explicite

		std::cout << "La plus grande valeur entre " << a << " et " << b << " est " << explicit_max << std::endl;
	}
	return (0);
}
```
*On favorisera l'utilisation d'instanciation explicite pour limiter les problèmes de conversions.*

Il est aussi possible d'utiliser les templates pour une utilisation sur des templates de classe :

```C++
template<typename T>

class List {
	public:
		List<T>(T const & content) {}; // Constructeur par défaut
		List<T>(List <T> const & list) {}; // Constructeur par copie
		~List<T>(void) {}; // Destructeur

	private:
		T			_content;
		List<T> *	_next;
};

int	main(void)
{
	List<int>		a(42);
	List<float>		b(3.14f);
	List<List<int>>	c(a);

	return (0);
}