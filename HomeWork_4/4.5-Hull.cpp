#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point
{
	int x, y;
	Point(int x = 0, int y = 0): x(x), y(y) {}
};

bool isInside(const Point &p1, const Point &p, const Point &p2)
{
    int dist1 = sqrt((p1.x-p.x)*(p1.x-p.x) + (p1.y-p.y)*(p1.y-p.y));
    int dist2 = sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
    return dist2 > dist1;
}

int main()
{
	int N;
	double answer = 0;
	int P = 0;
	scanf("%d", &N);
	vector<Point> points(N);
	vector<int> Hull;
	for(int i = 0; i < N; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		points[i].x = x;
		points[i].y = y;
		if(y < points[P].y)
			P = i;
		else if(y == points[P].y && x < points[P].x)
			P = i;
	}

	Hull.push_back(P);

	int first = P;
 	int cur = P;
	do
  	{
    	int next = (cur + 1) % N;
    	for (int i = 0; i < N; i++)
    	{
    		int sign = (points[cur].x-points[next].x)*(points[i].y-points[next].y) - (points[cur].y-points[next].y)*(points[i].x-points[next].x);
		    if (sign < 0)
		        next = i;
     		else if (sign == 0)
      		{
        		if (isInside(points[cur],points[next],points[i]))
          		next = i;
      		}
    	}
    	cur = next;
    	Hull.push_back(next);
	}
  	while (cur != first);

	for(int i = 0; i < Hull.size()-1; ++i)
		answer += sqrt((points[Hull[i]].x - points[Hull[i+1]].x)*(points[Hull[i]].x - points[Hull[i+1]].x) + (points[Hull[i]].y - points[Hull[i+1]].y)*(points[Hull[i]].y - points[Hull[i+1]].y));
	
	printf("%.2f\n", answer);

	return 0;
}