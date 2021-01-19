#include "Scroll.h"
#include"dxlib.h"

Scroll::Scroll() {
	WIN_WIDTH = 1920;
	ngh[0] = LoadGraph("l1.png");
	ngh[1] = LoadGraph("l2.png");
	ngh[2] = LoadGraph("l3.png");
	ngh[3] = LoadGraph("l4.png");
	ngh[4] = LoadGraph("l5.png");
	ngh[5] = LoadGraph("l6.png");

	for (int i = 0; i < 18; i++) {
		hx[i] = 0;
		hx2[i] = 1920;
		hx3[i] = -1920;
	}
}

int Scroll::getPosx() { return posx; }
int Scroll::getPosy() { return posy; }
int	Scroll::getPosr() { return posr; }

//プレイヤー移動
void Scroll::pmove(char keys[255]) {
	if (posx < WIN_WIDTH / 8) {
		if (keys[KEY_INPUT_RIGHT] == 1) {
			posx = posx + 9;
		}
	}

	if (posx >0) {
		if (keys[KEY_INPUT_LEFT] == 1) {
			posx = posx - 9;
		}
	}
	if (keys[KEY_INPUT_UP] == 1) {
		posy = posy - 9;
	}
	if (keys[KEY_INPUT_DOWN] == 1) {
		posy = posy + 9;
	}
}

//プレイヤー描画
void Scroll::pdraw() {
	SetDrawArea(-3840, 0, 3840, 1080);
	DrawBox(posx, posy, posx + posr, posy + posr, GetColor(255, 255, 255), TRUE);
}

//背景移動
void Scroll::hmove(char keys[255]) {
	//if (keys[KEY_INPUT_RIGHT] == 1) {
	if (keys[KEY_INPUT_SPACE] == 1) { flag = 1; }
	if (flag == 1) {//グレースケールの画像が表示されてる時間
		
		timer--;
	} 
	
	if (timer <= 0) { //0になったらタイマーを０に
	
	flag = 0;
	timer = 420;

	}
	
	if (flag == 0) { sx = 1920; }//flagが０のときグレースケールの画像見えなくする

	//スクロール 普通の画像
	for (int i = 0; i < 3; i++) {
	hx[i] = hx[i] - 6;
		hx2[i] = hx2[i] - 6;
		hx3[i] = hx3[i] - 6;
	}
	for (int i = 3; i < 6; i++) {
		hx[i] = hx[i] - 2;
		hx2[i] = hx2[i] - 2;
		hx3[i] = hx3[i] - 2;
	}
	for (int i = 6; i < 9; i++) {
		hx[i] = hx[i] - 3;
		hx2[i] = hx2[i] - 3;
		hx3[i] = hx3[i] - 3;
	}
	for (int i = 9; i < 12; i++) {
		hx[i] = hx[i] - 6;
		hx2[i] = hx2[i] - 6;
		hx3[i] = hx3[i] - 6;
	}
	for (int i = 12; i < 15; i++) {
		hx[i] = hx[i] - 6;
		hx2[i] = hx2[i] - 6;
		hx3[i] = hx3[i] - 6;
	}
	for (int i = 15; i < 18; i++) {
		hx[i] = hx[i] - 6;
		hx2[i] = hx2[i] - 6;
		hx3[i] = hx3[i] - 6;
	}

	//if (keys[KEY_INPUT_LEFT] == 1) {
	//	hx = hx + 3;
	//	hx2 = hx2 + 3;
		//hx3 = hx3 + 3;
	//}

	if (flag == 2) {
		DrawFormatString(0, 0, GetColor(0, 0, 0), "%d", timer);
		for (int i = 0; i < 3; i++) {
			hx[i] = hx[i] - 6;
			hx2[i] = hx2[i] - 6;
			hx3[i] = hx3[i] - 6;
		}
		for (int i = 3; i < 6; i++) {
			hx[i] = hx[i] - 2;
			hx2[i] = hx2[i] - 2;
			hx3[i] = hx3[i] - 2;
		}
		for (int i = 6; i < 9; i++) {
			hx[i] = hx[i] - 3;
			hx2[i] = hx2[i] - 3;
			hx3[i] = hx3[i] - 3;
		}
		for (int i = 9; i < 12; i++) {
			hx[i] = hx[i] - 6;
			hx2[i] = hx2[i] - 6;
			hx3[i] = hx3[i] - 6;
		}
		for (int i = 12; i < 15; i++) {
			hx[i] = hx[i] - 6;
			hx2[i] = hx2[i] - 6;
			hx3[i] = hx3[i] - 6;
		}
		for (int i = 15; i < 18; i++) {
			hx[i] = hx[i] - 6;
			hx2[i] = hx2[i] - 6;
			hx3[i] = hx3[i] - 6;
		}

	}
	//背景ループ
		for (int i = 0; i < 18; i++) {
			if (hx[i] <= -3840) {
				hx[i] = 1920;
			}
			if (hx2[i] <= -3840) {
				hx2[i] = 1920;
			}
			if (hx3[i] <= -3840) {
				hx3[i] = 1920;
			}

			//実際はいらない部分　デバッグ用
			if (hx2[i] >= 3840) {
				hx2[i] = -1920;
			}
			if (hx[i] >= 3840) {
				hx[i] = -1920;
			}
			if (hx3[i] >= 3840) {
				hx3[i] = -1920;
			}
		}
}
//
//背景描画
void Scroll::hdraw() {
	for (int i = 0; i < 18; i++) {
		SetDrawArea(-3840, 0, 3840, 1080);
		DrawGraph(hx[0], hy, ngh[0], TRUE);
		DrawGraph(hx2[1], hy2, ngh[0], TRUE);
		DrawGraph(hx3[2], hy3, ngh[0], TRUE);


		DrawGraph(hx[3], hy, ngh[1], TRUE);
		DrawGraph(hx2[4], hy2, ngh[1], TRUE);
		DrawGraph(hx3[5], hy3, ngh[1], TRUE);

		DrawGraph(hx[6], hy, ngh[2], TRUE);
		DrawGraph(hx2[7], hy2, ngh[2], TRUE);
		DrawGraph(hx3[8], hy3, ngh[2], TRUE);


		DrawGraph(hx[9], hy, ngh[3], TRUE);
		DrawGraph(hx2[10], hy2, ngh[3], TRUE);
		DrawGraph(hx3[11], hy3, ngh[3], TRUE);


		DrawGraph(hx[12], hy, ngh[4], TRUE);
		DrawGraph(hx2[13], hy2, ngh[4], TRUE);
		DrawGraph(hx3[14], hy3, ngh[4], TRUE);


		DrawGraph(hx[15], hy, ngh[5], TRUE);
		DrawGraph(hx2[16], hy2, ngh[5], TRUE);
		DrawGraph(hx3[17], hy3, ngh[5], TRUE);

	}

	if (flag == 1) {
		sx -= 6;
		SetDrawArea(sx, sy, sx2, sy2);
		//グレースケール
		DrawGraph(hx[0], hy, gh, TRUE);
		DrawGraph(hx2[1], hy2, gh, TRUE);
		DrawGraph(hx3[2], hy3, gh, TRUE);
		//グレースケール
		DrawGraph(hx[3], hy, gh2, TRUE);
		DrawGraph(hx2[4], hy2, gh2, TRUE);
		DrawGraph(hx3[5], hy3, gh2, TRUE);
		//グレースケール
		DrawGraph(hx[6], hy, gh3, TRUE);
		DrawGraph(hx2[7], hy2, gh3, TRUE);
		DrawGraph(hx3[8], hy3, gh3, TRUE);
		//gray
		DrawGraph(hx[9], hy, gh4, TRUE);
		DrawGraph(hx2[10], hy2, gh4, TRUE);
		DrawGraph(hx3[11], hy3, gh4, TRUE);
		//グレースケール
		DrawGraph(hx[12], hy, gh5, TRUE);
		DrawGraph(hx2[13], hy2, gh5, TRUE);
		DrawGraph(hx3[14], hy3, gh5, TRUE);
		//グレースケール
		DrawGraph(hx[15], hy, gh6, TRUE);
		DrawGraph(hx2[16], hy2, gh6, TRUE);
		DrawGraph(hx3[17], hy3, gh6, TRUE);
		
	}
}
