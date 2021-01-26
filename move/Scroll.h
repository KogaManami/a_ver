#pragma once
#include"dxlib.h"
class Scroll
{
private:
	int WIN_WIDTH = 1970;
	int posx = 360;//プレイヤーの座標
	int posy = 400;
	int pgh;//プレイヤーの描画
	int gpgh;
	int posr = 128;//extend用プレイヤーの半径
	int gh = LoadGraph("gl1.png");
	int gh2 = LoadGraph("gl2.png");
	int gh3 = LoadGraph("gl3.png");
	int gh4 = LoadGraph("gl4.png");
	int gh5 = LoadGraph("gl5.png");
	int gh6 = LoadGraph("gl6.png");
	int gh7= LoadGraph("vignette.png");
	int ngh[7];
	int flag = 0;
	int timer = 420;
	
	int hx[18];
	int hy = 0;
	int hx2[18]; //= 1920;
	int hy2 = 0;
	int hx3[18]; //= -1920;
	int hy3 = 0;
	int sx = 1970;//グレースケール用の変数(setdrawAreaの座標)
	int sy = 0;
	int sx2 = 1970;
	int sy2 = 1080;
	int plGh[6];
	int plGh_G[6];

	int ATCount = 7;
	int AT = 0;
public:
	Scroll();
	~Scroll();
	int getPosx();
	int getPosy();
	int getPosr();
	void pdraw();
	void pmove(char keys[255]);
	void hdraw();
	void hmove(char keys[255]);
};

