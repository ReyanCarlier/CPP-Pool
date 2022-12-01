Standard Template Library
=========================

La STL contient principalement deux choses intéressantes :

CONTAINERS
==========

Listes :
--------

Les conteneurs `list` sont une représentation templatée des listes.
Il est possible de faire des listes d'à peu près tout et n'importe quoi, le type des éléments de la liste est à définir lors de la déclaration de la liste.

![alt text](https://www.alphacodingskills.com/cpp/img/cpp-rbegin-rend.PNG)

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

	// ACCES
	my_list.front();	// Retourne le premier élément de la liste.
	my_list.back();		// Retourne le dernier élement de la liste.

	// ITERATORS
	my_list.begin();	// Retourne un itérateur sur le début de la liste.
	my_list.end();		// Retourne un itérateur sur la fin de la liste.
	my_list.rbegin();	// Retourne le dernier élément de la liste non-inversée.
	my_list.rend();		// Retourne l'élement précédent le premier élément d'une liste non inversée. Il s'agit d'un placeholder, essayer d'accéder à son contenu est un UB.

	// CAPACITY
	my_list.empty();	// Retourne true si la liste est vide, false au contraire.
	my_list.size();		// Retourne le nombre d'éléments présents dans la liste.
	my_list.max_size();	// Retourne le nombre maximum d'éléments possibles.

	// MODIFIERS
	my_list.clear();	// Vide le contenu de la liste.
	my_list.insert(const_iterator pos, const T& value);	// Insert un élément à l'emplacement pos.
	my_list.erase(const_iterator pos);	// Supprime l'élément à l'emplacement pos.
	my_list.push_back(const T& value); // Insert l'élément à la fin de la liste.
	my_list.pop_back();	// Supprime le dernier élément de la liste.
	my_list.push_front(const T& value); // Insert l'élément au début de la liste.
	my_list.pop_front();	// Supprime le premier élément de la liste.
	my_list.resize(size_t count, T value = T()); // Modifie la taille de la liste. Si la taille indiquée est plus grande que la taille actuelle de la liste, la taille est augmentée et des éléments par défaut sont ajoutés pour compléter.
	my_list.swap(std::list& other_list); // Inverse le contenu des deux listes.
}
```

ALGORITHMS
==========

