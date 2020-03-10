#include "Athlete.h"

//Athlete类的构造函数,创建名字为name,国籍为nationality的对象
Athlete::Athlete(const char* name, const char* nationality)
    {
        strcpy(ath_name,name);
        strcpy(ath_nation,nationality);
        city_max = 0;
        for(int i=0;i<200;i++)
        {
            cities[i]=NULL;
        }
    }
//向Athlete对象中添加运动员到访过的城市
void Athlete::addVisitedPlace(const char* place)
    {
        cities[city_max] = new char[200];
        strcpy(cities[city_max],place);
        city_max++;
    }
//检查Athlete对象是否经过的城市
bool Athlete::checkVisitedPlace(const char* place) const
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
//返回Athlete对象的名字
const char* Athlete::getName() const
    {
        return ath_name;
    }
//返回Athlete对象的国籍
const char* Athlete::getNationality() const
    {
        return ath_nation;
    }
 Athlete::~Athlete()    
    {
        for(int i=0;i<city_max;i++)
        {
            delete[] cities[i];
        }
    }
