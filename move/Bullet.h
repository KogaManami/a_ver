#pragma once
#include"Scroll.h"
class Bullet {
private:
	float posX = 0;
	float posY = 0;
	float radius = 32;
	float speed = 6;
	int isAlive = 0;
	int isActive = 0;
	int timer = 10;
	int bflag = 1;

	int ATCount = 4;
	int AT = 0;
	int bullGh[9];
public:
	Bullet();
	~Bullet();

	int getIsActive();
	
	void activate(Scroll* scroll);
	void move(Scroll* scroll);
	void draw();
};

