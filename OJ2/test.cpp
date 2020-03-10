#include <cstring>
#include <iostream>
using namespace std;

/*class Athlete
{
public:
    Athlete(const char* name, const char* nationality)
    {
        strcpy(ath_name,name);
        strcpy(ath_nation,nationality);
        city_max = 0;
        for(int i=0;i<200;i++)
        {
            cities[i]=NULL;
        }
    }

    void addVisitedPlace(const char* place)
    {
        cities[city_max] = new char[200];
        strcpy(cities[city_max],place);
        city_max++;
    }

    bool checkVisitedPlace(const char* place) const
    {
        for(int i=0;i<city_max;i++)
        {
            if(strcmp(place,cities[i])==0)
            {
                return true;
            }
        }
        return false;
    }

    const char* getName() const
    {
        return ath_name;
    }

    const char* getNationality() const
    {
        return ath_nation;
    }

    ~Athlete()
    {
        for(int i=0;i<city_max;i++)
        {
            delete[] cities[i];
        }
    }

private:
    char ath_name[200];
    char ath_nation[200];
    char* cities[200];
    int city_max;
};

class Administrator
{

public:
    Administrator()
    {
        for(int i=0;i<100;i++)
        {
            admin_ath[i] = NULL;
        }
        max_admin_ath = 0;
    }

    void addAthlete(Athlete *athlete)
    {
        admin_ath[max_admin_ath] = athlete;
        max_admin_ath++;
    }

    int findAthleteByNationality
    (const char* nationality, Athlete**resultList, int maxNum) const
    {
        int res = 0;
        for(int i=0;i<max_admin_ath&&i<maxNum;i++)
        {
            if(strcmp(nationality,admin_ath[i]->getNationality())==0)
            {
                resultList[res] = admin_ath[i];
                res++;
            }
        }
        return res;
    }
    int findAthleteByVisitedPlace(const char* place, 
    Athlete**resultList, int maxNum) const
    {
        int res = 0;
        for(int i=0;i<max_admin_ath&&i<maxNum;i++)
        {
            if(admin_ath[i]->checkVisitedPlace(place))
            {
                resultList[res] = admin_ath[i];
                res++;
            }
        }
        return res;        
    }
    ~Administrator()
    {
        for(int i=0;i<100;i++)
        {
            delete admin_ath[i];
        }
    }



private:
    Athlete* admin_ath[100];
    int max_admin_ath;

};






int main()
{
Athlete *athlete=new Athlete("James","America");
athlete->addVisitedPlace("Tokyo");//登记James曾前往过Tokyo
athlete->addVisitedPlace("Washington");//登记James曾前往过Washington
//athlete->getName()//获取James的名字
//athlete->getNationality()//获取James的国籍
bool check=athlete->checkVisitedPlace("Tokyo");//检查James是否曾前往过Tokyo

Administrator *admin=new Administrator();//创建一个Administrator对象
admin->addAthlete(athlete);//将athlete登记到admin中
const int MAXATH=100;
Athlete *resultList[MAXATH];//创建Athlete对象指针数组
int resultNum=admin->findAthleteByNationality("America",resultList,MAXATH);//查询
for(int i=0;i<resultNum;++i){
cout<<resultList[i]->getName()<<endl;//输出上述查找到的运动员的姓名
}



}*/

int main()
{
    
}