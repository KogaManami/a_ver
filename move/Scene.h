#pragma once
class Scene {
private:
	int title[17];
	int aT = 0;
	int aTCount = 5;

	//�`���[�g���A��
	int tyuta[10];
	
	//�F
	int color = 0;
	int sceneNo = 0;

	//�w�i�X�N���[���ϐ�
	int scrollX[10];
	int fillXS = 1920;
	int fillR = 1950;
	int fillXE = fillXS + fillR;

	//���̉摜
	int under = 0;
	int underMemory = 0;
	
public:
	Scene();
	~Scene();
	
	//����
	int getSceneNo();
	int getColor();
	int getFillXS();
	int getFillXE();
	int getUnder();
	int getUnderMemory();
	
	//����
	void setSceneNo(int sceneNo);
	void setColor(int color);
	void setFillXS(int fillXS);
	void setFillXE(int fillXE);
	void setUnder(int under);
	void setUnderMemory(int underMemory);

	
	void tyutaMove();
	void titleDraw();
	void tyutaDraw();//�`���[�g���A��
};

