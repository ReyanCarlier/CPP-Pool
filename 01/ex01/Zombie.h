#ifndef ZOMBIE_H
# define ZOMBIE_H

# ifndef ZOMBIE_HPP
#  define ZOMBIE_HPP
#  include "Zombie.hpp"
# endif

# ifndef STRING_HPP
#  define STRING_HPP
#  include <string>
# endif

# ifndef IOSTREAM_HPP
#  define IOSTREAM_HPP
#  include <iostream>
# endif

Zombie *newZombie(std::string name);
void	randomChump(std::string name);
Zombie*	zombieHorde(int N, std::string name);

#endif