#pragma once
#include "Scroll.h"

class Enemy
{
private:
	//敵座標
	int ex;//x
	int ey;//y
	int er;//r
	int espeed;//エネミーのスピード
	int isalive = 1;//生存フラグ

	int bullPosX = 0;
	int bullPosY = 0;
	int bullR = 32;
	int iaActive = 0;
	//色
	int color = 0;
	
public:
	Enemy(int ex, int ey, int er, int espeed,int color);//とりあえず位置決めれます　敵のファイルはライフ用に作っただけなので使わなくても大丈夫です
	~Enemy();//ですち

	//げったー
	int getEx();
	int getEy();
	int getEr();
	int getIsalive();
	int getColor();

	//せったー
	void setIsalive(int isalive);
	void setColor(int color);

	//メンバ関数
	void grayDraw();
	void yellowDraw(Scroll* scroll);
	void redDraw();
	void buleDraw();
	void greenDraw();
	void emove();
	void homing();
	void gun();
	void sin();

};

