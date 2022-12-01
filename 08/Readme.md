Standard Template Library
=========================

La STL contient principalement deux choses intéressantes :

CONTAINERS
==========

Listes :
--------

Les conteneurs `list` sont une représentation templatée des listes.
Il est possible de faire des listes d'à peu près tout et n'importe quoi, le type des éléments de la liste est à définir lors de la déclaration de la liste.

![alt text](https://upload.cppreference.com/mwiki/images/1/1b/range-begin-end.svg)

```C++
std::list<T> list_name;
```

Exemple :

```C++
#include <list>

int main()
{
	std::list<int>	list1;
}
```
Il est possible d'intéragir avec les listes via différentes fonctions :
```C++
#include <list>

int main()
{
	std::list<T> my_list;

	my_list.front(); // Retourne le premier élément de la liste
	my_list.back();  // Retourne le dernier élement de la liste
	my_list.begin();
}


ALGORITHMS
==========

