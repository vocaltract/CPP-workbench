class Manager
{
public:
    Manager();
    void addTruck(Truck *t);
    Truck *transport(int targetDistance,int weight);
    double getAllIncome();
    double getAllCost();

private:
    Truck* all_trucks[40];
    int max;
};