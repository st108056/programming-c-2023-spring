#include <string>
#include <iostream>

struct Student {
private:
    std::string name;
    std::string surname;
    int math;
    int phys;
    int inf;

public:

    Student(std::string name = "Vasya", std::string surname = "Proshin", int math = 0, int phys = 0, int inf = 0) :
        name(name), surname(surname), math(math), phys(phys), inf(inf) {};

    Student(const Student& st) :
        name(st.name), surname(st.surname), math(st.math), phys(st.phys), inf(st.inf) {};

    ~Student() {};

    int Sum()
    {
        return(math + phys + inf);
    }

    void sayName()
    {
        std::cout << name << ' ' << surname << std::endl;
    }
};


int main(int argc, char* argv[])
{
    int n = 0;
    std::string name;
    std::string sname;
    int math;
    int ph;
    int inf;

    std::cin >> n;
    Student* sts = new Student[n];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> name;
        std::cin >> sname;
        std::cin >> math;
        std::cin >> ph;
        std::cin >> inf;
        sts[i] = Student(name, sname, math, inf, ph);
    }

    for (int i = 0; i < n; ++i) 
    {
        for (int j = n - 1; j > i; --j)
        {
            if (sts[j - 1].Sum() < sts[j].Sum())
            {
                Student temp = sts[j - 1];
                sts[j - 1] = sts[j];
                sts[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        sts[i].sayName();
    }

    delete[] sts;
    return EXIT_SUCCESS;
}