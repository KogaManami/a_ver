#include "DxLib.h"
#include"Scroll.h"
#include"Enemy.h"
#include"Life.h"
#include "Bullet.h"

const char TITLE[] = "学籍番号名前：タイトル";

const int WIN_WIDTH = 1920; //ウィンドウ横幅
const int WIN_HEIGHT = 1080;//ウィンドウ縦幅

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	ChangeWindowMode(TRUE);						//ウィンドウモードに設定
	//ウィンドウサイズを手動では変更できず、かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);
	SetMainWindowText(TITLE);					// タイトルを変更
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);	//画面サイズの最大サイズ、カラービット数を設定（モニターの解像度に合わせる）
	SetWindowSizeExtendRate(1.0);				//画面サイズを設定（解像度との比率で設定）
	SetBackgroundColor(150, 150, 150);		// 画面の背景色を設定する

	//Dxライブラリの初期化
	if (DxLib_Init() == -1) { return -1; }

	//（ダブルバッファ）描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	//画像などのリソースデータの変数宣言と読み込み
	Life* life = new Life();
	Enemy* enemy = new Enemy(400, 400, 30, 3);
	Enemy* enemy2 = new Enemy(800, 400, 30, 3);
	Scroll* scroll = new Scroll;
	Bullet* bullet = new Bullet;

	int x = 10;
	int y = 10;
	//ゲームループで使う変数の宣言
	char keys[256] = { 0 }; //最新のキーボード情報用
	char oldkeys[256] = { 0 };//1ループ（フレーム）前のキーボード情報

	bullet->init(scroll);

	// ゲームループ
	while (1)
	{
		//最新のキーボード情報だったものは１フレーム前のキーボード情報として保存

		//最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		//画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//
		//更新処理
		//scrollのところにプレイヤー入れてます

		bullet->alive(scroll);
		scroll->hmove(keys);
		scroll->pmove(keys);
		enemy->emove();
		enemy2->emove();
		bullet->move();
		life->lif(scroll, enemy);
		life->lif(scroll, enemy2);
		
		//描画処理
		scroll->hdraw();
		scroll->pdraw();
		enemy->edraw();
		enemy2->edraw();
		life->ldraw();
		bullet->draw();

		x = x + 1;

		DrawCircle(x, y, 16, GetColor(0, 0, 0), TRUE);
		//---------  ここまでにプログラムを記述  ---------//
		ScreenFlip();//（ダブルバッファ）裏面
		// 20ミリ秒待機（疑似60FPS）
		WaitTimer(20);
		// Windows システムからくる情報を処理する
		if (ProcessMessage() == -1)
		{
			break;
		}
		// ＥＳＣキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}
	//Dxライブラリ終了処理
	DxLib_End();

	return 0;
}