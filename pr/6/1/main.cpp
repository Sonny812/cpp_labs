#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

namespace Genders
{
enum Gender
{
    Female = 1,
    Male = 0,
    Custom = 2
};

std::string genderToString(Gender gender)
{
    switch (gender)
    {
    case Female:
        return "female";
        break;
    case Male:
        return "male";
    default:
        return "custom";
        break;
    }
}
} // namespace Genders

struct Rabbit
{
private:
    Genders::Gender gender;
    int age;
    float weight;

public:
    Rabbit(){};
    Rabbit(Genders::Gender gender, int age, float weight) : gender(gender), age(age), weight(weight) {}

    Genders::Gender getGender()
    {
        return this->gender;
    }

    int getAge()
    {
        return this->age;
    }

    float getWeigth()
    {
        return this->weight;
    }

    void display()
    {
        std::cout << "Gender: " << Genders::genderToString(this->gender) << std::endl;
        std::cout << "Age: " << this->age << std::endl;
        std::cout << "Weight: " << this->weight << std::endl;
    }

    void write(std::ofstream &os)
    {
        os.write(reinterpret_cast<char *>(this), sizeof(Rabbit));
    }

    static Rabbit create(std::istream &is)
    {
        Rabbit rabbit;
        is.read(reinterpret_cast<char *>(&rabbit), sizeof(Rabbit));

        return rabbit;
    }
};

bool oldestRabbitCmp(Rabbit &a, Rabbit &b);

int main()
{
    const int count = 4;
    const std::string filename = "file.dat";

    Rabbit rabbits[count] = {
        Rabbit(Genders::Gender::Male, 4, 11),
        Rabbit(Genders::Gender::Female, 2, 10),
        Rabbit(Genders::Gender::Female, 5, 10),
        Rabbit(Genders::Gender::Custom, 2, 12)};

    std::ofstream os(filename, std::ios::binary);

    for (int i = 0; i < count; i++)
    {
        rabbits[i].write(os);
    }

    os.close();

    std::ifstream is(filename, std::ios::binary);

    std::vector<Rabbit> rabbitsVector;

    while (!is.eof())
    {
        Rabbit rabbit = Rabbit::create(is);
        if (!is.fail())
        {
            rabbit.display();
            std::cout << std::endl;
            rabbitsVector.push_back(rabbit);
        }
    }

    auto oldestRabbit = std::max_element(rabbitsVector.begin(), rabbitsVector.end(), oldestRabbitCmp);

    std::cout << "The oldest rabbit:" << std::endl;
    oldestRabbit->display();
}

bool oldestRabbitCmp(Rabbit &a, Rabbit &b)
{
    if (a.getAge() < b.getAge())
    {
        return true;
    }
    else if (a.getAge() == b.getAge())
    {
        return a.getWeigth() < b.getWeigth();
    }

    return false;
}