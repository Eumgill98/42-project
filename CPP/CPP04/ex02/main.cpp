#include "Dog.hpp"
#include "Cat.hpp"
#include<iomanip>

int main()
{
	{
		std::cout << std::setw(15) << "================================" << std::endl;
		std::cout << "Base Case Check" << std::endl;

		std::cout << std::endl;

		std::cout << "(Constructor check)" << std::endl;
		
		std::cout << "1. Dog constructor" << std::endl;
		const AAnimal* j = new Dog();
		std::cout << "2. Cat constructor" << std::endl;
		const AAnimal* i = new Cat();

		std::cout << std::endl;

		std::cout << "(Deconstructor check)" << std::endl;

		std::cout << "1. Cat Deconstructor" << std::endl;
		delete j;
		std::cout << "2. Dog Deconstructor" << std::endl;
		delete i;
		std::cout << std::setw(15) << "================================" << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << std::setw(15) << "================================" << std::endl;
		std::cout << "Array Case Check" << std::endl;
		std::cout << std::endl;

		int MAX_ANIMALS = 10;
		AAnimal* animals[MAX_ANIMALS];

		int idx = 0;
		while (idx < MAX_ANIMALS)
		{
			std::cout << idx << " is create!" << std::endl;
			if (idx % 2 == 0)
				animals[idx] = new Dog();
			else
				animals[idx] = new Cat();
			idx++;
		}

		std::cout << std::endl;
		
		idx = 0;
		while (idx < MAX_ANIMALS)
		{
			std::cout << "This animal is " << animals[idx]->getType() << std::endl;
			animals[idx]->makeSound();
			idx++;
		}

		std::cout << std::endl;

		idx = 0;
		while (idx < MAX_ANIMALS)
		{
			std::cout << idx << " is delete!" << std::endl; 
			delete animals[idx];
			idx++;
		}

		std::cout << std::setw(15) << "================================" << std::endl;
	}

		std::cout << std::endl;

	{
		std::cout << std::setw(15) << "================================" << std::endl;
		std::cout << "Deep Copy Case Check (Copy Constructor)" << std::endl;
		std::cout << std::endl;

		Cat cat;
		Cat copy_cat(cat);

		std::cout << std::endl;

		std::cout << "[Before]" << std::endl;
		std::cout << "Original Cat idea 10 is : " << cat.getIdea(10) << std::endl;
		std::cout << "Copy Cat idea 10 is : " << copy_cat.getIdea(10) << std::endl;

		std::cout << std::endl;

		std::cout << "[After]" << std::endl;
		cat.setIdea(10, "new orignal cat idea");
		std::cout << "Original Cat idea 10 is : " << cat.getIdea(10) << std::endl;
		std::cout << "Copy Cat idea 10 is : " << copy_cat.getIdea(10) << std::endl;

		std::cout << std::endl;

		Dog dog;
		Dog copy_dog(dog);

		std::cout << std::endl;

		std::cout << "[Before]" << std::endl;
		std::cout << "Original Dog idea 11 is : " << dog.getIdea(11) << std::endl;
		std::cout << "Copy Dog idea 11 is : " << copy_dog.getIdea(11) << std::endl;

		std::cout << std::endl;

		std::cout << "[After]" << std::endl;
		dog.setIdea(11, "new orignal Dog idea");
		std::cout << "Original Dog idea 11 is : " << dog.getIdea(11) << std::endl;
		std::cout << "Copy Dog idea 11 is : " << copy_dog.getIdea(11) << std::endl;
		std::cout << std::endl;

	}

		std::cout << std::endl;

	{
		std::cout << std::setw(15) << "================================" << std::endl;
		std::cout << "Deep Copy Case Check (Assignment Constructor)" << std::endl;
		std::cout << std::endl;

		Cat cat;
		Cat assignation_cat(cat);

		std::cout << std::endl;

		std::cout << "[Before]" << std::endl;
		std::cout << "Original Cat idea 10 is : " << cat.getIdea(10) << std::endl;
		std::cout << "Assignation Cat idea 10 is : " << assignation_cat.getIdea(10) << std::endl;

		cat.setIdea(10, "Assignation new idea");

		std::cout << "[After]" << std::endl;
		std::cout << "Original Cat idea 10 is : " << cat.getIdea(10) << std::endl;
		std::cout << "Assignation Cat idea 10 is : " << assignation_cat.getIdea(10) << std::endl;
		
		std::cout << "[Assignation]" << std::endl;
		assignation_cat = cat;
		std::cout << "Assignation Cat idea 10 is : " << assignation_cat.getIdea(10) << std::endl;

		std::cout << "[Assignation Cat new idea]" << std::endl;
		assignation_cat.setIdea(11, "Assignation 11 new idea");
		std::cout << "Assignation Cat idea 11 is : " << assignation_cat.getIdea(11) << std::endl;
		std::cout << "Original Cat idea 11 is : " << cat.getIdea(11) << std::endl;

		std::cout << std::endl;
	}
}