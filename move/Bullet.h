#pragma once
#include "Scroll.h"

class Bullet {
private:
	float posX = 0;
	float posY = 0;
	float radius = 32;
	float speed = 10;
	int isAlive = 0;
	int timer = 100;

public:
	Bullet();
	~Bullet();
	void init(Scroll* scroll);
	void alive(Scroll* scroll);
	void move();
	void draw();
};

