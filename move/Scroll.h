#pragma once
#include "dxlib.h"
#include "Scene.h"

class Scroll {
private:
	int WIN_WIDTH = 1970;
	int posx = 360;//プレイヤーの座標
	int posy = 400;
	int pgh=0;//プレイヤーの描画
	int gpgh=0;
	int posr = 128;//extend用プレイヤーの半径
	int gh = LoadGraph("Resources/gl1.png");
	int gh2 = LoadGraph("Resources/gl2.png");
	int gh3 = LoadGraph("Resources/gl3.png");
	int gh4 = LoadGraph("Resources/gl4.png");
	int gh5 = LoadGraph("Resources/gl5.png");
	int gh6 = LoadGraph("Resources/gl6.png");
	int gh7= LoadGraph("Resources/vignette.png");
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

	int uiflag = 0;
	int sflag = 0;
	int uigh = LoadGraph("Resources/all.png");
	int uigh2 = LoadGraph("Resources/nored.png");
	int uigh3 = LoadGraph("Resources/noblue.png");
	int uigh4 = LoadGraph("Resources/nogreen.png");
	int uigh5 = LoadGraph("Resources/noyellow.png");
	int uiposx = posx - 40;
	int uiposy = posy - 40;
	int text = 0;

	//コントローラー
	int Pad = 0;
public:
	Scroll();
	~Scroll();
	
	int getPosx();
	int getPosy();
	int getPosr();
	int getFlag();
	int getSx();
	int getSx2();
	int getText();

	void setText(int text);
	
	void pdraw();
	void pmove(char keys[255]);
	void uidraw(char keys[255]);
	void uimove(char keys[255]);
	void hdraw();
	void hmove(char keys[255]);

	//色の切り替え
	void controllerNo1(Scene* scene);
	void controllerNo2(Scene* scene);
};