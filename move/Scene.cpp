#include "Scene.h"
#include "DxLib.h"

Scene::Scene() {
	LoadDivGraph("Resources/title.png", 17, 17, 1, 1920, 1080, title);

	//gray
	tyuta[0] = LoadGraph("Resources/tyuta_G.png");
	tyuta[1] = LoadGraph("Resources/tyuta_G.png");

	//red
	tyuta[2] = LoadGraph("Resources/tyuta_R.png");
	tyuta[3] = LoadGraph("Resources/tyuta_R.png");

	//green
	tyuta[4] = LoadGraph("Resources/tyuta_Green.png");
	tyuta[5] = LoadGraph("Resources/tyuta_Green.png");

	//blue
	tyuta[6] = LoadGraph("Resources/tyuta_B.png");
	tyuta[7] = LoadGraph("Resources/tyuta_B.png");

	//yellow
	tyuta[8] = LoadGraph("Resources/tyuta_E.png");
	tyuta[9] = LoadGraph("Resources/tyuta_E.png");

	scrollX[0] = 0;
	scrollX[1] = 1920;
	scrollX[2] = 0;
	scrollX[3] = 1920;
	scrollX[4] = 0;
	scrollX[5] = 1920;
	scrollX[6] = 0;
	scrollX[7] = 1920;
	scrollX[8] = 0;
	scrollX[9] = 1920;

	fillXS = 1920;
	fillR = 1920;
	fillXE = fillXS + fillR;

};

Scene::~Scene() {}

//‚°‚½
int Scene::getSceneNo() { return sceneNo; }
int Scene::getColor() { return color; }
int Scene::getFillXS() { return fillXS; }
int Scene::getFillXE() { return fillXE; }
int Scene::getUnder() { return under; }
int Scene::getUnderMemory() { return underMemory; }

//‚¹‚½
void Scene::setSceneNo(int sceneNo) { this->sceneNo = sceneNo; }
void Scene::setColor(int color) { this->color = color; }
void Scene::setFillXS(int fillXS) { this->fillXS = fillXS; }
void Scene::setFillXE(int fillXE) { this->fillXE = fillXE; }
void Scene::setUnder(int under) { this->under = under; }
void Scene::setUnderMemory(int underMemory) { this->underMemory = underMemory; }

void Scene::tyutaMove() {
	scrollX[0] = scrollX[0] - 6;
	scrollX[1] = scrollX[1] - 6;
	scrollX[2] = scrollX[2] - 6;
	scrollX[3] = scrollX[3] - 6;
	scrollX[4] = scrollX[4] - 6;
	scrollX[5] = scrollX[5] - 6;
	scrollX[6] = scrollX[6] - 6;
	scrollX[7] = scrollX[7] - 6;
	scrollX[8] = scrollX[8] - 6;
	scrollX[9] = scrollX[9] - 6;

	if (scrollX[0] == -1920) {
		scrollX[0] = 0;
		scrollX[2] = 0;
		scrollX[4] = 0;
		scrollX[6] = 0;
		scrollX[8] = 0;
	}
	if (scrollX[1] == 0) {
		scrollX[1] = 1920;
		scrollX[3] = 1920;
		scrollX[5] = 1920;
		scrollX[7] = 1920;
		scrollX[9] = 1920;
	}
}

void Scene::titleDraw() {
	aTCount--;
	if (aTCount == 0) {
		aT++;
		aTCount = 5;
	}

	if (aT == 16) {
		aT = 0;
	}

	DrawGraph(0, 0, title[aT], TRUE);
}

void Scene::tyutaDraw() {

	SetDrawArea(0, 0, 3840, 1080);

	fillXE = fillXS + fillR;

	if (fillXS == 0) {
		underMemory = under;
	}

	if (underMemory == 0) {
		DrawGraph(scrollX[0], 0, tyuta[0], TRUE);
		DrawGraph(scrollX[1], 0, tyuta[1], TRUE);
	}
	if (underMemory == 1) {
		DrawGraph(scrollX[2], 0, tyuta[2], TRUE);
		DrawGraph(scrollX[3], 0, tyuta[3], TRUE);

	}
	if (underMemory == 2) {
		DrawGraph(scrollX[4], 0, tyuta[4], TRUE);
		DrawGraph(scrollX[5], 0, tyuta[5], TRUE);

	}
	if (underMemory == 3) {
		DrawGraph(scrollX[6], 0, tyuta[6], TRUE);
		DrawGraph(scrollX[7], 0, tyuta[7], TRUE);

	}
	if (underMemory == 4) {
		DrawGraph(scrollX[8], 0, tyuta[8], TRUE);
		DrawGraph(scrollX[9], 0, tyuta[9], TRUE);
	}

	//gray
	if (color == 0) {
		DrawGraph(scrollX[0], 0, tyuta[0], TRUE);
		DrawGraph(scrollX[1], 0, tyuta[1], TRUE);
	}

	//red
	if (color == 1) {
		if (fillXS > 0) {
			fillXS -= 30;
		}

		if (under == 0) {
			DrawGraph(scrollX[0], 0, tyuta[0], TRUE);
			DrawGraph(scrollX[1], 0, tyuta[1], TRUE);
		}

		SetDrawArea(fillXS, 0, fillXE, 1080);
		DrawGraph(scrollX[2], 0, tyuta[2], TRUE);
		DrawGraph(scrollX[3], 0, tyuta[3], TRUE);
	}

	//green
	if (color == 2) {
		if (fillXS > 0) {
			fillXS -= 30;
		}
		if (under == 0) {
			DrawGraph(scrollX[0], 0, tyuta[0], TRUE);
			DrawGraph(scrollX[1], 0, tyuta[1], TRUE);
		}
		SetDrawArea(fillXS, 0, fillXE, 1080);


		DrawGraph(scrollX[4], 0, tyuta[4], TRUE);
		DrawGraph(scrollX[5], 0, tyuta[5], TRUE);
	}

	//blue
	if (color == 3) {
		if (fillXS > 0) {
			fillXS -= 30;
		}
		if (under == 0) {
			DrawGraph(scrollX[0], 0, tyuta[0], TRUE);
			DrawGraph(scrollX[1], 0, tyuta[1], TRUE);
		}
		SetDrawArea(fillXS, 0, fillXE, 1080);
		DrawGraph(scrollX[6], 0, tyuta[6], TRUE);
		DrawGraph(scrollX[7], 0, tyuta[7], TRUE);
	}

	//yellow
	if (color == 4) {
		if (fillXS > 0) {
			fillXS -= 30;
		}
		if (under == 0) {
			DrawGraph(scrollX[0], 0, tyuta[0], TRUE);
			DrawGraph(scrollX[1], 0, tyuta[1], TRUE);
		}
		SetDrawArea(fillXS, 0, fillXE, 1080);
		DrawGraph(scrollX[8], 0, tyuta[8], TRUE);
		DrawGraph(scrollX[9], 0, tyuta[8], TRUE);
	}
}
