#include "Scroll.h"

Scroll::Scroll() {
	WIN_WIDTH = 1970;
	ngh[0] = LoadGraph("Resources/l1.png");
	ngh[1] = LoadGraph("Resources/l2.png");
	ngh[2] = LoadGraph("Resources/l3.png");
	ngh[3] = LoadGraph("Resources/l4.png");
	ngh[4] = LoadGraph("Resources/l5.png");
	ngh[5] = LoadGraph("Resources/l6.png");

	//アニメーション
	LoadDivGraph("Resources/dorako_A.png", 6, 6, 1, 128, 128, plGh);
	LoadDivGraph("Resources/dorako_AG.png", 6, 6, 1, 128, 128, plGh_G);

	for (int i = 0; i < 18; i++) {
		hx[i] = 0;
		hx2[i] = 1970;
		hx3[i] = -1970;
	}
}

//げったー
int Scroll::getPosx() { return posx; }
int Scroll::getPosy() { return posy; }
int	Scroll::getPosr() { return posr; }
int Scroll::getFlag() { return flag; }
int Scroll::getSx() { return sx; }
int Scroll::getSx2() { return sx2; }

//プレイヤー移動
void Scroll::pmove(char keys[255]) {
	if (keys[KEY_INPUT_UP] == 1) {
		posy = posy - 14;
	}
	if (keys[KEY_INPUT_DOWN] == 1) {
		posy = posy + 14;
	}
}

//プレイヤー描画
void Scroll::pdraw() {
	//アニメーション処理
	ATCount--;
	if (ATCount == 0) {
		ATCount = 7;
		AT++;
	}

	if (AT == 5) {
		AT = 0;
	}

	SetDrawArea(-3940, 0, 3940, 1080);
	if (flag == 0) {
		DrawExtendGraph(posx, posy, posx + posr, posy + posr, plGh_G[AT], TRUE);
	}

	if (flag == 1) {
		if (sx < posx) {
			//色をつける
			DrawExtendGraph(posx, posy, posx + posr, posy + posr, plGh[AT], TRUE);
		} else if (sx >= posx) {
			DrawExtendGraph(posx, posy, posx + posr, posy + posr, plGh_G[AT], TRUE);
		}
	}

	if (flag == 3) {
		if (sx2 < posx) {
			DrawExtendGraph(posx, posy, posx + posr, posy + posr, plGh_G[AT], TRUE);
		} else if (sx2 >= posx) {
			DrawExtendGraph(posx, posy, posx + posr, posy + posr, plGh[AT], TRUE);
		}

	}

}

//背景移動
void Scroll::hmove(char keys[255]) {
	if ((flag == 0 || flag == 3) && sx >= 1920) {
		if (keys[KEY_INPUT_SPACE] == 1) {
			flag = 1;//灰色

		}
	}

	if (flag == 0) { sx = 1970; }//flagが０のときグレースケールの画像見えなくする

	if (flag == 1 && sx <= 0) {
		if (keys[KEY_INPUT_SPACE] == 1) {
			flag = 3;//黄色
		}
	}

	if (flag == 1 && sflag != 1 && 0 < sx) {
		sx -= 30;
	}

	if (flag == 3 && sflag != 1 && 0 < sx2) {
		sx2 -= 30;
	}

	if (sx2 <= 0 && sx <= 0) {
		if (keys[KEY_INPUT_SPACE] == 1) {
			sflag = 1;
			sx = 1920;
			sx2 = 1920;
		}
	}

	//切り替え
	if (sflag == 1) {
		if (keys[KEY_INPUT_SPACE] == 1) {
			flag = 1;
			sflag = 0;
		}
	}

	//スクロール 普通の画像
	for (int i = 3; i < 6; i++) {
		hx[i] = hx[i] - 2;
		hx2[i] = hx2[i] - 2;
		hx3[i] = hx3[i] - 2;
	}
	for (int i = 6; i < 9; i++) {
		hx[i] = hx[i] - 5;
		hx2[i] = hx2[i] - 5;
		hx3[i] = hx3[i] - 5;
	}
	for (int i = 9; i < 12; i++) {
		hx[i] = hx[i] - 10;
		hx2[i] = hx2[i] - 10;
		hx3[i] = hx3[i] - 10;
	}
	for (int i = 12; i < 15; i++) {
		hx[i] = hx[i] - 10;
		hx2[i] = hx2[i] - 10;
		hx3[i] = hx3[i] - 10;
	}
	for (int i = 15; i < 18; i++) {
		hx[i] = hx[i] - 10;
		hx2[i] = hx2[i] - 10;
		hx3[i] = hx3[i] - 10;
	}

	if (flag == 2) {
		for (int i = 3; i < 6; i++) {
			hx[i] = hx[i] - 2;
			hx2[i] = hx2[i] - 2;
			hx3[i] = hx3[i] - 2;
		}
		for (int i = 6; i < 9; i++) {
			hx[i] = hx[i] - 5;
			hx2[i] = hx2[i] - 5;
			hx3[i] = hx3[i] - 5;
		}

		//速度は一緒(マイナスする数)
		for (int i = 9; i < 12; i++) {
			hx[i] = hx[i] - 10;
			hx2[i] = hx2[i] - 10;
			hx3[i] = hx3[i] - 10;
		}
		for (int i = 12; i < 15; i++) {
			hx[i] = hx[i] - 10;
			hx2[i] = hx2[i] - 10;
			hx3[i] = hx3[i] - 10;
		}
		for (int i = 15; i < 18; i++) {
			hx[i] = hx[i] - 10;
			hx2[i] = hx2[i] - 10;
			hx3[i] = hx3[i] - 10;
		}
	}

	//背景ループ
	for (int i = 0; i < 18; i++) {
		if (hx[i] <= -3940) {
			hx[i] = 1945;
		}
		if (hx2[i] <= -3940) {
			hx2[i] = 1945;
		}
		if (hx3[i] <= -3940) {
			hx3[i] = 1945;
		}

		//実際はいらない部分　デバッグ用
		if (hx2[i] >= 3940) {
			hx2[i] = -1945;
		}
		if (hx[i] >= 3940) {
			hx[i] = -1945;
		}
		if (hx3[i] >= 3940) {
			hx3[i] = -1945;
		}
	}
}

//背景描画
void Scroll::hdraw() {
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

	if (flag == 1 || flag == 3) {
		SetDrawArea(sx, sy, sx2, sy2);
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

		DrawGraph(0, 0, gh7, TRUE);
	}

	SetDrawArea(-3940, 0, 3940, 1080);
	DrawGraph(0, 0, gh7, TRUE);
	DrawFormatString(20, 60, GetColor(255, 255, 255), "flag=%d", flag);
	DrawFormatString(20, 80, GetColor(255, 255, 255), "sx=%d", sx);
	DrawFormatString(20, 100, GetColor(255, 255, 255), "sx2=%d", sx2);

	
	/*if (sx <= 0) {
		DeleteGraph(gh);
		DeleteGraph(gh2);
		DeleteGraph(gh3);
		DeleteGraph(gh4);
		DeleteGraph(gh5);
		DeleteGraph(gh6);
	}*/
}
