#pragma once
#include"dxlib.h"
class Scroll
{
private:
	int WIN_WIDTH = 1920;
	int WIN_HEIGHT = 1080;
	int posx = 40;
	int posy = 400;
	int posr = 126;
	int gh = LoadGraph("a.png");
	int gh2 = LoadGraph("a.png");
	int gh3 = LoadGraph("a.png");
	int hx = 0;
	int hy = 0;
	int hx2 = 1920;
	int hy2 = 0;
	int hx3 = -1920;
	int hy3 = 0;

public:
	Scroll();
	~Scroll();
	int getPosx();
	int getPosy();
	int getPosr();

	void setPosx(int posx);
	void setPosy(int posy);
	void pdraw();
	void pmove(char keys[255]);
	void hdraw();
	void hmove(char keys[255]);
};

