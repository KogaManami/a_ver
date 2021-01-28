#pragma once
#include "Scroll.h"

class Enemy
{
private:
	//�G���W
	int ex;//x
	int ey;//y
	int er;//r
	int espeed;//�G�l�~�[�̃X�s�[�h
	int isalive = 1;//�����t���O

	int bullPosX = 0;
	int bullPosY = 0;
	int bullR = 32;
	int iaActive = 0;
	//�F
	int color = 0;
	
public:
	Enemy(int ex, int ey, int er, int espeed,int color);//�Ƃ肠�����ʒu���߂�܂��@�G�̃t�@�C���̓��C�t�p�ɍ���������Ȃ̂Ŏg��Ȃ��Ă����v�ł�
	~Enemy();//�ł���

	//�������[
	int getEx();
	int getEy();
	int getEr();
	int getIsalive();
	int getColor();

	//�������[
	void setIsalive(int isalive);
	void setColor(int color);

	//�����o�֐�
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

