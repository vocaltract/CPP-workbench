#include "Transport.h"
#include "Manager.h"
#include <iostream>

Manager::Manager()
{
    max = 0;
    for (int i = 0; i < 40; i++)
    {
        all_trucks[i] = NULL;
    }
}

void Manager::addTruck(Truck *t)
{
    all_trucks[max] = t;
    max++;
}
Truck *Manager::transport(int targetDistance, int weight)
{
    Truck *target_truck = all_trucks[0];
    int count = 0;
    while (count < max)
    {
        for (int i = count; i < max; i++)
        {
            if (all_trucks[i]->price(targetDistance) != -1)
            {
                count = i;
                break;
            }
        }
        if (max == count)
            break;
        if (all_trucks[count]->price(targetDistance) < target_truck->price(targetDistance)||target_truck->price(targetDistance)==-1)
        {
            target_truck = all_trucks[count];
        }
        count++;
    }
    for (int i = 0; i < max; i++)
    {
        if (target_truck->getTotalIncome() >= all_trucks[i]->getTotalIncome() && target_truck->price(targetDistance) == all_trucks[i]->price(targetDistance))
        {
            target_truck = all_trucks[i];
        }
    }
    for(int i=0;i<max;i++)
    {
        if (target_truck->getID()>=all_trucks[i]->getID()&&target_truck->getTotalIncome() == all_trucks[i]->getTotalIncome() && target_truck->price(targetDistance) == all_trucks[i]->price(targetDistance))
        {
            target_truck = all_trucks[i];
        }        
    }

    target_truck->transport(targetDistance, weight);
    return target_truck;
}
double Manager::getAllIncome()
{
    double sum = 0;
    for (int i = 0; i < max; i++)
    {
        sum += all_trucks[i]->getTotalIncome();
    }
    return sum;
}

double Manager::getAllCost()
{
    double sum = 0;
    for (int i = 0; i < max; i++)
    {
        sum += all_trucks[i]->getTotalCost();
    }
    return sum;
}
