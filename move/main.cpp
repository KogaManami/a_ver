#include "DxLib.h"
#include"Scroll.h"
#include"Enemy.h"
#include"Life.h"
#include"Bullet.h"
#include "Scene.h"

const char TITLE[] = "Fill_Color";

const int WIN_WIDTH = 1970; //ウィンドウ横幅
const int WIN_HEIGHT = 1080;//ウィンドウ縦幅

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	ChangeWindowMode(TRUE);						//ウィンドウモードに設定
	//ウィンドウサイズを手動では変更できず、かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);
	SetMainWindowText(TITLE);					// タイトルを変更
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);	//画面サイズの最大サイズ、カラービット数を設定（モニターの解像度に合わせる）
	SetWindowSizeExtendRate(1.0);				//画面サイズを設定（解像度との比率で設定）
	SetBackgroundColor(0x33, 0x33, 0x33);		// 画面の背景色を設定する

	//Dxライブラリの初期化
	if (DxLib_Init() == -1) { return -1; }

	//（ダブルバッファ）描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	//画像などのリソースデータの変数宣言と読み込み
	int Pad = 0;
	int num = 0;
	const int BULLET_MAX = 20;
	int startTimer = 40;
	int timer = 40;
	Bullet* bullet[BULLET_MAX];

	Life* life = new Life();
	Enemy* enemy = new Enemy(1970, 400, 128, 4,1);
	Enemy* enemy2 = new Enemy(2300, 400, 128, 4,1);
	Enemy* enemy3 = new Enemy(1600, 400, 128, 10,1);
	Scroll* scroll = new Scroll();
	Scene* scene = new Scene();
	
	for (int i = 0; i < BULLET_MAX; i++) {
		bullet[i] = new Bullet();
	}

	//ゲームループで使う変数の宣言
	char keys[256] = { 0 }; //最新のキーボード情報用
	char oldkeys[256] = { 0 };//1ループ（フレーム）前のキーボード情報

	XINPUT_STATE Inputfuuma = { 0 };

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
		Pad = GetJoypadInputState(DX_INPUT_PAD1);
		//oneフレーム前のコントローラー情報
		XINPUT_STATE OldInput = Inputfuuma;
		//コントローラーのXINPUTから取得できる情報を得るふーま
		GetJoypadXInputState(DX_INPUT_PAD1, &Inputfuuma);

		//ゲームシーン
		if (scene->getSceneNo() == 0) {
			//タイトル
			if (Inputfuuma.Buttons[XINPUT_BUTTON_B] && !OldInput.Buttons[XINPUT_BUTTON_B]) {
				if (scene->getSceneNo() == 0) {
					scene->setSceneNo(1);
				}
			}
			scene->titleDraw();
		}
		if (scene->getSceneNo() == 1) {
			//チュートリアル
			
			if (scroll->getText() < 6 && Inputfuuma.Buttons[XINPUT_BUTTON_B] && !OldInput.Buttons[XINPUT_BUTTON_B]) {
				scroll->setText(scroll->getText() + 1);
			}

			if(scroll->getText() == 6) {
				startTimer--;
				if (startTimer == 0) {
					scroll->setText(7);
				}
			}

			//最初の色替え
			if (scroll->getText() == 7) {
				if (scene->getColor() == 0) {
					if (Inputfuuma.Buttons[XINPUT_BUTTON_B] && !OldInput.Buttons[XINPUT_BUTTON_B]) {
						scene->setColor(1);
						scene->setFillXS(1920);
						scene->setUnder(1);
					}
					if (Inputfuuma.Buttons[XINPUT_BUTTON_A] && !OldInput.Buttons[XINPUT_BUTTON_A]) {
						scene->setColor(2);
						scene->setFillXS(1920);
						scene->setUnder(2);
					}
					if (Inputfuuma.Buttons[XINPUT_BUTTON_X] && !OldInput.Buttons[XINPUT_BUTTON_X]) {
						scene->setColor(3);
						scene->setFillXS(1920);
						scene->setUnder(3);
					}
					if (Inputfuuma.Buttons[XINPUT_BUTTON_Y] && !OldInput.Buttons[XINPUT_BUTTON_Y]) {
						scene->setColor(4);
						scene->setFillXS(1920);
						scene->setUnder(4);
					}
				}

				//2回目以降,自由に色替え
				if (scene->getFillXS() == 0) {
					if (scene->getColor() != 1) {
						if (Inputfuuma.Buttons[XINPUT_BUTTON_B] && !OldInput.Buttons[XINPUT_BUTTON_B]) {
							//長押し判定
							scene->setColor(1);
							scene->setFillXS(1920);
							scene->setUnder(1);
						}
					}

					if (scene->getColor() != 2) {
						if (Inputfuuma.Buttons[XINPUT_BUTTON_A] && !OldInput.Buttons[XINPUT_BUTTON_A]) {
							//長押し判定
							scene->setColor(2);
							scene->setFillXS(1920);
							scene->setUnder(2);
						}
					}

					if (scene->getColor() != 3) {
						if (Inputfuuma.Buttons[XINPUT_BUTTON_X] && !OldInput.Buttons[XINPUT_BUTTON_X]) {
							//長押し判定
							scene->setColor(3);
							scene->setFillXS(1920);
							scene->setUnder(3);
						}
					}
				
					if (scene->getColor() != 4) {
						if (Inputfuuma.Buttons[XINPUT_BUTTON_Y] && !OldInput.Buttons[XINPUT_BUTTON_Y]) {
							//長押し判定
							scene->setColor(4);
							scene->setFillXS(1920);
							scene->setUnder(4);
						}
					}
					
				}
			}

			scene->tyutaMove();
			scene->tyutaDraw();
			SetDrawArea(-3940, 0, 3940, 1080);
			DrawFormatString(0, 80, GetColor(255, 255, 255), "fillXS=%d", scene->getFillXS());
			DrawFormatString(0, 100, GetColor(255, 255, 255), "fillXE=%d", scene->getFillXE());
			DrawFormatString(0, 120, GetColor(255, 255, 255), "under=%d", scene->getUnder());
			DrawFormatString(0, 140, GetColor(255, 255, 255), "underMemory=%d", scene->getUnderMemory());
			DrawFormatString(0, 160, GetColor(255, 255, 255), "startTimer=%d", startTimer);
		}
		if (scene->getSceneNo() == 2) {
			//ステージ1
		}
		if (scene->getSceneNo() == 3) {
			//ステージ2
			//弾のセットtimer
			timer--;

			//scrollのところにプレイヤー入れてます
			scroll->hmove(keys);
			scroll->pmove(keys);
			for (int i = 0; i < BULLET_MAX; i++) {
				if (timer == 0) {
					if (bullet[i]->getIsActive() == 0) {
						bullet[i]->activate(scroll);
						timer = 40;
						break;
					}
				}
			}

			enemy->emove();
			enemy2->emove();
			enemy3->gun();
			for (int i = 0; i < BULLET_MAX; i++) {
				bullet[i]->move(scroll);
			}
			life->lif(scroll, enemy);
			life->lif(scroll, enemy2);

			//描画処理
			scroll->hdraw();
			enemy->yellowDraw(scroll);
			enemy2->yellowDraw(scroll);
			enemy3->yellowDraw(scroll);
			life->ldraw();
			scroll->pdraw();
			for (int i = 0; i < BULLET_MAX; i++) {
				bullet[i]->draw();
			}
		}
		if (scene->getSceneNo() == 4) {
			//ステージ3
		}
		if (scene->getSceneNo() == 5) {
			//ステージ4
			
		}
		if (scene->getSceneNo() == 6) {
			//GAMEOVER画面(ここで初期化)
		}

		
		/*for (int i = 1; i < 4; i++) {
			DrawLine(480 * i, 0, 480 * i, 1080, GetColor(0, 0, 0), TRUE);
		}*/

		DrawFormatString(0, 0, GetColor(255, 255, 255), "SceneNo=%d", scene->getSceneNo());
		DrawFormatString(0, 20, GetColor(255, 255, 255), "text=%d", scroll->getText());
		DrawFormatString(0, 40, GetColor(255, 255, 255), "Input=%d", num);
		
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