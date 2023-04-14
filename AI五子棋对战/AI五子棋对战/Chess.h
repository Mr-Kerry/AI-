#pragma once
#include <vector>
#include <graphics.h> //easyx图形库的头文件

using namespace std;

//构建棋子落点位置结构体
struct ChessPos {
	int row;
	int col;

	ChessPos(int r = 0, int c = 0) :row(r), col(c) {};
};

typedef enum {
	CHESS_WHITE = -1,//白棋
	CHESS_BLACK = 1,
}chess_kind_t;

class Chess
{
public:
	Chess(int gradeSize, int marginX, int marginY, float chessSize);

	//棋盘初始化，加载棋盘的图片资源，初始化棋盘的相关数据
	void init();

	/*
	判断指定坐标（x，y）的位置，是否是有效点击
	如果是有效点击，把有效点击的位置（行，列）保存在参数pos中
	*/
	bool clickBoard(int x, int y, ChessPos* pos);
	void chessDown(ChessPos *pos, chess_kind_t kind);//在棋盘的指定位置（pos），落子（kind）
	int getGradeSize(); //获取棋盘的大小（13线，15线，19线）
	int getChessData(ChessPos* pos);
	int getChessData(int row, int col);
	bool checkIsOver();

	/*使用图形库，来显示我们的棋盘和棋子 */

private:
	IMAGE chessBlackImg;//黑棋棋子
	IMAGE chessWhiteImg;//白棋棋子

	int gradeSize; //棋盘大小（13，15，17，19）
	int margin_x;//棋盘的左侧边界
	int margin_y;//棋盘的顶部边界
	float chessSize;//棋子的大小
	
	vector<vector<int>> chessMap;//存储当前棋局棋子的分布数据0：空白，1：黑子，-1：白子

	//表示现在该谁下棋
	bool playerFlag;//true:该黑子走  false: 该白子走

	void updateGameMap(ChessPos* pos);

	bool checkWin();//检查输赢，如果胜负已分就返回true

	ChessPos lastPos;//最近落子点的位置
};

