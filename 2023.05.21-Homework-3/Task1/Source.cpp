#include <iostream>
#include <math.h>

struct Point {
private:
	int x;
	int y;

public:
	Point(int x = 0, int y = 0) : x(x), y(y) {} 

	Point(const Point& p) : 
		x(p.x), y(p.y) {}

	~Point() {}; 

	double Distance()
	{
		return(sqrt(x * x + y * y));
	}

	void sayCords()
	{
		std::cout << x << ' ' << y << std::endl;
	}
};

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	Point* a = new Point[n];

	for (int i = 0; i < n; ++i) 
	{
		int x;
		int y;
		std::cin >> x >> y;
		a[i] = Point(x, y);
	}

	for (int i = 0; i < n; ++i) 
	{
		for (int j = n - 1; j > i; --j)
		{
			if (a[j - 1].Distance() > a[j].Distance())
			{
				Point temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; ++i) 
	{
		a[i].sayCords();
	}

	delete[] a;

	return EXIT_SUCCESS;
}