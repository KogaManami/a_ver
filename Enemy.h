#pragma once
class Enemy
{
private:
	//�G���W
	int ex;//x
	int ey;//y
	int er;//r
	//int alive;//�����t���O�@�����ĂȂ��ł�
	int espeed;//�G�l�~�[�̃X�s�[�h
	int isalive=1;//�����t���O
	
public:
	Enemy(int ex,int ey,int er,int espeed);//�Ƃ肠�����ʒu���߂�܂��@�G�̃t�@�C���̓��C�t�p�ɍ���������Ȃ̂Ŏg��Ȃ��Ă����v�ł�
	~Enemy();//�ł���

	//�������[
	int getEx();
	int getEy();
	int getEr();
	int getIsalive();

	//�������[
	void setIsalive(int isalive);
	void edraw();//�`��
	void emove();//�ړ�
};

