class Truck
{
public:
    Truck(int id);
    virtual double cost(int targetDistance, int weight)=0;
    virtual double price(int targetDistance)=0;
    void transport(int targetDistance, int weight);
    double getTotalCost() const;
    double getTotalIncome() const;
    int getID()const;
protected:
    int ID;
    double its_cost;
    double its_income;
};

class NormalTruck:public Truck
{
public:
    NormalTruck(int id, int maxDistance);
    virtual double cost(int targetDistance, int weight);
    virtual double price(int targetDistance);
private:
    int max_distance;
};

class AdvancedTruck:public NormalTruck
{
public:
    AdvancedTruck(int id);
    virtual double cost(int targetDistance, int weight);
    virtual double price(int targetDistance);
};



class LongDistanceTruck:public AdvancedTruck
{
public:
    LongDistanceTruck(int id);
    virtual double cost(int targetDistance, int weight);
    virtual double price(int targetDistance);
};

