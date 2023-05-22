#include<iostream>
#include<string>
#include<algorithm>

std::string Pets[] = { "None", "Cordyceps", "Insects", "Spider", "Mouse", "Frog", "Bird", "Snake", "Hedgehog", "Fox", "Hyena" };

int a[11][4] = {
	{}, {1}, {1, 2}, {2}, {2}, {2}, {3, 4, 5}, {6, 4, 5}, {4}, {6, 8, 9, 10}, {9, 6, 8}
};

class Animal
{
private:


public:

	int type;
	std::string name;
	int power;

	Animal();
	Animal(int type = 0, std::string name = "", int power = 0) :
		type(type), name(name), power(power) {}

	Animal(const Animal& animal) :
		type(animal.type), name(animal.name), power(animal.power) {}

	~Animal() {}

	int getType() { return type; }
	int getPower() { return power; }
	std::string getName() { return name; }

	void setPower() { power++; }

};

void printInfo(Animal st)
{
	std::cout << "The fighter for life " << st.name << " is " << st.power << " powerful " << Pets[st.type] << std::endl;
}

int naturalSelection(Animal* victim, Animal* aggressor)
{
	bool exist1 = std::count(std::begin(a[(*aggressor).getType()]), std::end(a[(*aggressor).getType()]), (*victim).getType()) > 0;
	bool exist2 = std::count(std::begin(a[(*victim).getType()]), std::end(a[(*victim).getType()]), (*aggressor).getType()) > 0;

	if ((exist1 and not exist2) or (exist1 and exist2 and (*victim).getPower() < (*aggressor).getPower()))
	{
		std::cout << (*victim).name << " the " << Pets[(*victim).type] << " was eaten by " << Pets[(*aggressor).type] << " named " << (*aggressor).name << std::endl;

		(*aggressor).setPower();

		return(1); // the victim is eaten by the aggressor
	}
	else if ((exist2 and not exist1) or (exist1 and exist2 and (*victim).getPower() > (*aggressor).getPower()))
	{
		std::cout << (*aggressor).name << " the " << Pets[(*aggressor).type] << " was eaten by " << Pets[(*victim).type] << " named " << (*victim).name << std::endl;

		(*victim).setPower();

		return(2); // the aggressor is eaten by the victim
	}
	else
	{
		return(0); // no one die
	}
}

void Fun(Animal** room, int first, int second, int n)
{
	int done = naturalSelection(room[first], room[second]);


	if (n == 1 or (n == 2 and done == 0))
	{
		std::cout << "The winner is " << (*room[n - 1]).getName() << " the " << Pets[(*room[n - 1]).getType()] << n;
	}
	else if (done == 1)
	{
		room[first] = room[--n];

		Fun(room, first % n, (++first) % n, n);

	}
	else if (done == 2)
	{
		std::swap(room[second], room[--n]);

		Fun(room, first % n, (++first) % n, n);
	}
	else if (done == 0)
	{
		Fun(room, first, (++second) % n, n);
	}
	else
	{
		std::cout << "error" << std::endl;
	}
}

int main(int argc, char* argv[])
{
	Animal* zoo[20];

	for (int i = 0; i < 20; ++i)
	{
		int type = std::rand() % 10 + 1;
		std::string name = "st" + std::to_string(107027 + i);
		int pow = std::rand() % 10 + 1;

		zoo[i] = new Animal(type, name, pow);
	}

	return EXIT_SUCCESS;
}