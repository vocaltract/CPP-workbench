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

