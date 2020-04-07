#include "Transport.h"
Truck::Truck(int id)
{
    ID = id;
    its_cost = 0;
    its_income = 0;
}
NormalTruck::NormalTruck(int id, int maxDistance)
    :Truck(id)
{
    max_distance = maxDistance;
}
AdvancedTruck::AdvancedTruck(int id)
    :NormalTruck(id,-1)
{
}
LongDistanceTruck::LongDistanceTruck(int id)
    :AdvancedTruck(id)
{
}
double NormalTruck::cost(int targetDistance, int weight)
{
    return targetDistance>max_distance?-1:weight*targetDistance;
}
double NormalTruck::price(int targetDistance)
{
    double money = targetDistance*5<100?100:targetDistance*5;
    return targetDistance>max_distance?-1:money;
}
void Truck::transport(int targetDistance, int weight)
{
    its_cost += cost(targetDistance, weight)==-1?0:cost(targetDistance, weight);
    its_income += price(targetDistance)==-1?0:price(targetDistance);
}
double Truck::getTotalCost() const
{
    return its_cost;
}
double Truck::getTotalIncome() const
{
    return its_income;
}
int Truck::getID() const
{
    return ID;
}

double AdvancedTruck::cost(int targetDistance, int weight)
{
    return 50+weight*targetDistance;
}
double AdvancedTruck::price(int targetDistance)
{
    double money = targetDistance*8<150?150:targetDistance*8;
    return money;
}


double LongDistanceTruck::cost(int targetDistance, int weight)
{
    return 50+weight*targetDistance;
}
double LongDistanceTruck::price(int targetDistance)
{
    double money = targetDistance*8<150?150:targetDistance*8;
    return targetDistance<30?money*1.1:money*0.9;
}