#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include "GeoPoint.h"
#include "Area.h"
using namespace std;

class PointGridIndex
{
public:
	//设置网格索引必要的参数
	void setGridIndexParameters(Area* area, int gridWidth);//设置网格索引必要的参数
	//把坐标点放入网格索引中
	void createIndex(list<GeoPoint*>& pts, Area* area, int gridWidth);//把坐标点放入网格索引中	
	pair<int, int> getRowCol(GeoPoint* pt);
	//void drawGridLine(Gdiplus::Color color, MapDrawer& md);
	void getNearPts(GeoPoint* pt, double thresholdM, vector<GeoPoint*>& dest); //将距离pt不长于thresholdM米的所有点存入dest
	void getNearPts(GeoPoint* pt, int gridRange, vector<GeoPoint*>& dest); //将以pt所在网格为中心，边长为2*gridRange+1格中的所有点存入dest
	void kNN(GeoPoint* pt, int k, double thresholdM, vector<GeoPoint*>& dest);

//private:
	list<GeoPoint*>* **grid;
	int gridWidth;
	int gridHeight;
	double gridSizeDeg; //记录grid边长代表多少实际距离（单位为度）
	Area* area;

	void initialization();
	void insertOnePt(GeoPoint* pt);

};
