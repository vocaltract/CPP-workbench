struct Point
{
    int x;
    int y;
};

bool IsTrue(Point &rstCenter, int iRadius, Point &P1, Point &P2)
{
    auto PointInCircle = [rstCenter,iRadius](Point point)->bool
    {   
        return (point.x-rstCenter.x)*( point.x-rstCenter.x)+(point.y-rstCenter.y)*( point.y-rstCenter.y)<iRadius;
    };
    return PointInCircle(P1) != PointInCircle(P2);
}
