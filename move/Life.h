#pragma once
#include"Scroll.h"
#include"Enemy.h"
#include"dxlib.h"
class Life
{
private:
	//ライフの位置　固定でよさそうだから一個一個座標書いてきました
	int htx = 80;
	int hty = 30;
	int htx2 = 200;
	int hty2 = 30;
	int htx3 = 340;
	int hty3 = 30;
	int htr = 32;
	int gh = LoadGraph("hart.png");
	int flag = 0;//てき喰らった時のフラグ
	int lifepoint = 3;//ライフポイント

public:
	Life();//こんち
	~Life();//ですち

	int getHtx();//げったー
	int getHty();//げったー

	void ldraw();//描画です
	void lif(Scroll* scroll, Enemy* enemy);//当たり判定も兼ねてます

};

