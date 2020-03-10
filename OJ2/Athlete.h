#include <cstring>
class Athlete
{
public:

//Athlete类的构造函数,创建名字为name,国籍为nationality的对象
Athlete(const char* name, const char* nationality);
//向Athlete对象中添加运动员到访过的城市
void addVisitedPlace(const char* place);
//检查Athlete对象是否经过的城市
bool checkVisitedPlace(const char* place) const;
//返回Athlete对象的名字
const char* getName() const;
//返回Athlete对象的国籍
const char* getNationality() const;
~Athlete(); 
private:
    char ath_name[200];
    char ath_nation[200];
    char* cities[200];
    int city_max;
};