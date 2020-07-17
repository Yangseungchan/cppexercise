#include <iostream>

using namespace std;

class Animal
{
private:
    int food;
    int weight;

public:
    void set_animal(int _food, int _weight)
    {
        food = _food;
        weight = _weight;
    }

    void increase_food(int inc)
    {
        food += inc;
        weight += (inc / 3);
    }

    void view_stat()
    {
        cout << "food : " << food << endl;
        cout << "weight : " << weight << endl;
    }
};

int main(int argc, char *argv[])
{
    Animal animal;
    animal.set_animal(10, 100);
    animal.increase_food(10);
    animal.view_stat();
    return 0;
}