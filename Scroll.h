#pragma once
#include"dxlib.h"
class Scroll
{
private:
	int WIN_WIDTH=1970;
	int posx=40;//�v���C���[�̍��W
	int posy=400;
	int pgh;//�v���C���[�̕`��
	int gpgh;
	int posr = 128;//extend�p�v���C���[�̔��a
	int gh = LoadGraph("gl1.png");
	int gh2 = LoadGraph("gl2.png");
	int gh3 = LoadGraph("gl3.png");
	int gh4 = LoadGraph("gl4.png");
	int gh5 = LoadGraph("gl5.png");
	int gh6 = LoadGraph("gl6.png");
	int ngh[7];
	int flag = 0;
	int timer = 420;
	//ngh[0] = LoadGraph("l1.png");
	//int ngh2 = LoadGraph("l2.png");
	//int ngh3 = LoadGraph("l3.png");
	//int ngh4 = LoadGraph("l4.png");
	//int ngh5 = LoadGraph("l5.png");
	//int ngh6 = LoadGraph("l6.png");
	int hx[18];
	int hy = 0;
	int hx2[18]; //= 1920;
	int hy2 = 0;
	int hx3[18]; //= -1920;
	int hy3 = 0;
	int sx = 1920;//�O���[�X�P�[���p�̕ϐ�(setdrawArea�̍��W)//����1970
	int sy = 0;
	int sx2 = 1920;//����1920;
	int sy2 = 1080;
	int tou;//����Ȃ�
	int uiflag = 0;
	int sflag = 0;
	int uigh = LoadGraph("all.png");
	int uigh2 = LoadGraph("nored.png");
	int uigh3 = LoadGraph("noblue.png");
	int uigh4 = LoadGraph("nogreen.png");
	int uigh5 = LoadGraph("noyellow.png");
	int uiposx = posx - 40;
	int uiposy = posy - 40;
public:
	Scroll();
	~Scroll();
	int getPosx();
	int getPosy();
	int getPosr();
	void pdraw();
	void pmove(char keys[255]);
	void uidraw(char keys[255]);
	void uimove(char keys[255]);
	void hdraw();
	void hmove(char keys[255]);
};

