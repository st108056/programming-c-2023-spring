#include <iostream>
#include <string>

struct Animal
{
	std::string type;
	std::string name;
	int age;

	Animal(std::string type = "zebra", std::string name = "Marti", int age = 13)
	{
		this->type = type;
		this->name = name;
		this->age = age;
	}

	Animal(const Animal& creature)
	{
		this->type = creature.type;
		this->name = creature.name;
		this->age = creature.age;
	}

	~Animal()
	{

	}
};

void printAnimal(Animal a)
{
	std::cout << "It\'s name is " << a.name << '.' << std::endl;
	std::cout << a.name << " is " << a.type << '.' << std::endl;
	std::cout << "It is " << a.age << " years old." << std::endl;
}

void ElderAnimal(Animal& a)
{
	a.age += 1;
}

int main(int argc, char* argv[])
{
	Animal tyk;
	ElderAnimal(tyk);
	printAnimal(tyk);

	return EXIT_SUCCESS;
}