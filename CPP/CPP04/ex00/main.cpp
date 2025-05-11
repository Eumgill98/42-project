#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongDog.hpp"

int main()
{
	std::cout << "[+++++Right Cases+++++]" << std::endl;
	std::cout << "1. Declaring Variables" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "++++++++++++++++++++++++" << std::endl;

	std::cout << "2. Name Check" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "++++++++++++++++++++++++" << std::endl;

	std::cout << "3. Sound Check" << std::endl;
	std::cout << "[Will output the Cat sound!]" << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << "[Will output the Dog sound!]" << std::endl;
	j->makeSound();
	std::cout << "[Will output the Aniaml sound]" << std::endl;
	meta->makeSound();
	std::cout << "++++++++++++++++++++++++" << std::endl;

	std::cout << "4. Deconstructor Check" << std::endl;
	std::cout << "[Aniaml Deconstructor]" << std::endl;
    delete meta;
	std::cout << "[Dog Deconstructor]" << std::endl;
    delete j;
	std::cout << "[Cat Deconstructor]" << std::endl;
    delete i;
	std::cout << "++++++++++++++++++++++++" << std::endl << std::endl;

	std::cout << "[+++++Wrong Cases+++++]" << std::endl;
	std::cout << "1. Declaring Variables" << std::endl;
	const WrongAnimal* wrongmeta = new WrongAnimal();
	const WrongAnimal* k = new WrongDog();
	std::cout << "++++++++++++++++++++++++" << std::endl;

	std::cout << "2. Name Check" << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << "++++++++++++++++++++++++" << std::endl;

	std::cout << "3. Sound Check" << std::endl;
	std::cout << "[Will output the WrongDog sound! But,]" << std::endl;
	k->makeSound();
	std::cout << "[Will output the WrongAniaml sound]" << std::endl;
	wrongmeta->makeSound();
	std::cout << "++++++++++++++++++++++++" << std::endl;

	std::cout << "4. Deconstructor Check" << std::endl;
	std::cout << "[WrongAniaml Deconstructor]" << std::endl;
    delete wrongmeta;
	std::cout << "[WrongDog Deconstructor]" << std::endl;
    delete k;
	std::cout << "++++++++++++++++++++++++" << std::endl;

    return 0;
}