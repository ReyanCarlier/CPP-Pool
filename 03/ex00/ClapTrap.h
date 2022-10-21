#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# ifndef IOSTREAM_HPP
#  define IOSTREAM_HPP
#  include <iostream>
# endif

# ifndef STRING_HPP
#  define STRING_HPP
#  include <string>
# endif

void	attack(const std::string& target);
void	takeDamage(unsigned int amount);
void	beRepaired(unsigned int amount);

#endif