#pragma once
#include"Scroll.h"
#include"Enemy.h"
#include"dxlib.h"
class Life
{
private:
	//���C�t�̈ʒu�@�Œ�ł悳��������������W�����Ă��܂���
	int htx = 80;
	int hty = 30;
	int htx2 = 200;
	int hty2 = 30;
	int htx3 = 340;
	int hty3 = 30;
	int htr = 32;
	int gh = LoadGraph("hart.png");
	int flag = 0;//�Ă����������̃t���O
	int lifepoint = 3;//���C�t�|�C���g

public:
	Life();//����
	~Life();//�ł���

	int getHtx();//�������[
	int getHty();//�������[

	void ldraw();//�`��ł�
	void lif(Scroll* scroll, Enemy* enemy);//�����蔻������˂Ă܂�

};

