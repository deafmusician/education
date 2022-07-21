#include <iostream>
//для функции свап при удалении элемента
#include <algorithm>

struct Vektor
{
    //количество записей в массиве и область поиска
    int input = 0;
    //факт. длина массива
    int vlong = 0;
    int *mass = nullptr;
};

void input(Vektor *vektor)
{
    //для контроля еще с наработок. если то в функции не нужны
    if(vektor->input < vektor->vlong)
    {
        int in = 0;
        std::cout << "Enter a Data" << std::endl;
        std::cin >> in;
        //кол. записей есть индекс массива
        vektor->mass[vektor->input] = in;
        ++vektor->input;
    }
    //для контроля
    else
    {
        std::cout << "Vektor is full" << std::endl;
    }
}

void upControl(Vektor *vektor)
{
    //поменять местами с если
    if(!vektor->mass)
        {
            vektor->vlong = 5;
            vektor->mass = new int[5];
            input(vektor);
        }
    //удвоение массива
    if(vektor->input == vektor->vlong)
        {
            int *newmass = new int [vektor->vlong + vektor->input];
            vektor->vlong = vektor->vlong + vektor->input;
            for(int copy = 0; copy < vektor->input; ++copy)
                newmass[copy] = vektor->mass[copy];
            delete vektor->mass;
            vektor->mass = newmass;
            input(vektor);
        }
    else
    {
        input(vektor);
    }
}

void deleteData(Vektor *vektor)
{
    int del = 0;
    int index = 0;
    std::cout << "Enter a delete Nummber" << std::endl;
    std::cin >> del;
    while (index != vektor->input)
        {
            if(vektor->mass[index] == del)
                {
                    del = vektor->mass[vektor->input - 1];
                    std::swap(vektor->mass[index],del);
                    --vektor->input;
                    return;
                }
            ++index;
        }
    std::cout << "The Data is not fundet" << std::endl;
}

void downControl(Vektor *vektor)
{
    if(!vektor->mass)
    {
        std::cout << "Vektor is emply" << std::endl;
        return;
    }
    if(vektor->input == (vektor->vlong / 2))
    {
            int *newmass = new int [vektor->input];
            vektor->vlong = vektor->input;
            for(int copy = 0; copy < vektor->input; ++copy)
                newmass[copy] = vektor->mass[copy];
            delete vektor->mass;
            vektor->mass = newmass;
            deleteData(vektor);
    }
    else
    {
        deleteData(vektor);
    }
}

void print(const Vektor *vektor)
{
    std::cout << "Vektor:" << " ";
    for(int print = 0; print < vektor->input; ++print)
        {
            std::cout << vektor->mass[print]  << " ";
        }
    std::cout << "Vektor long is: " << vektor->vlong << std::endl;
    std::cout << std::endl;
}

//1.0
void massReverse(Vektor *vektor)
{
    int *newmass = new int [vektor->vlong];
    for(int back = vektor->input - 1, front = 0; back >= 0; --back, ++front)
        newmass[front] = vektor->mass[back];
    delete vektor->mass;
    vektor->mass = newmass;
}

int main()
{
    Vektor a;
    downControl(&a);
    upControl(&a);
    upControl(&a);
    upControl(&a);
    upControl(&a);
    upControl(&a);
    upControl(&a);
    print(&a);
    massReverse(&a);
    print(&a);
    downControl(&a);
    downControl(&a);
    downControl(&a);
    print(&a);
    return 0;
}