#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat& other);
		WrongCat& operator=(const WrongCat& rhs);
		~WrongCat();

		void makeSound() const;
	private:
		std::string _type;
};