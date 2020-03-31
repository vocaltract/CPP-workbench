#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;
class Car
{
public:
    // fRadian:方向盘旋转角度；fSpeed:汽车行驶速度
    // fDeltaTime:每隔多久更新一次行驶状态
    void drive(float fRadian, float fSpeed, float fDeltaTime)
    {
        cout << "Driving..." << endl;
        cout << "Radian: " << fRadian << endl;
        cout << "Speed: " << fSpeed << endl;
        cout << "DeltaTime: " << fDeltaTime << endl;
    }
};

class AutopilotCar:public Car
{
public:
    void autoDrive()
    {
        cout<<"autoDriving..."<<endl;
    }
};


class UpgradedAutopilotCar:public AutopilotCar
{
public:
    void optimizedDrive(float fRadian, float fSpeed, float fDeltaTime)
    {
        drive(fRadian+(int)rand()%5,fSpeed,fDeltaTime);
    }
protected:
    AutopilotCar::drive;
};

class PerfectCar:private Car
{
public:
    void autoDrive()
    {
        cout<<"autoDriving..."<<endl;
    }
};
