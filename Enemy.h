#pragma once
class Enemy
{
private:
	//敵座標
	int ex;//x
	int ey;//y
	int er;//r
	//int alive;//生存フラグ　つかってないです
	int espeed;//エネミーのスピード
	int isalive=1;//生存フラグ
	
public:
	Enemy(int ex,int ey,int er,int espeed);//とりあえず位置決めれます　敵のファイルはライフ用に作っただけなので使わなくても大丈夫です
	~Enemy();//ですち

	//げったー
	int getEx();
	int getEy();
	int getEr();
	int getIsalive();

	//せったー
	void setIsalive(int isalive);
	void edraw();//描画
	void emove();//移動
};

