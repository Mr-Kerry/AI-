#pragma once
#include <vector>
#include <graphics.h> //easyxͼ�ο��ͷ�ļ�

using namespace std;

//�����������λ�ýṹ��
struct ChessPos {
	int row;
	int col;

	ChessPos(int r = 0, int c = 0) :row(r), col(c) {};
};

typedef enum {
	CHESS_WHITE = -1,//����
	CHESS_BLACK = 1,
}chess_kind_t;

class Chess
{
public:
	Chess(int gradeSize, int marginX, int marginY, float chessSize);

	//���̳�ʼ�����������̵�ͼƬ��Դ����ʼ�����̵��������
	void init();

	/*
	�ж�ָ�����꣨x��y����λ�ã��Ƿ�����Ч���
	�������Ч���������Ч�����λ�ã��У��У������ڲ���pos��
	*/
	bool clickBoard(int x, int y, ChessPos* pos);
	void chessDown(ChessPos *pos, chess_kind_t kind);//�����̵�ָ��λ�ã�pos�������ӣ�kind��
	int getGradeSize(); //��ȡ���̵Ĵ�С��13�ߣ�15�ߣ�19�ߣ�
	int getChessData(ChessPos* pos);
	int getChessData(int row, int col);
	bool checkIsOver();

	/*ʹ��ͼ�ο⣬����ʾ���ǵ����̺����� */

private:
	IMAGE chessBlackImg;//��������
	IMAGE chessWhiteImg;//��������

	int gradeSize; //���̴�С��13��15��17��19��
	int margin_x;//���̵����߽�
	int margin_y;//���̵Ķ����߽�
	float chessSize;//���ӵĴ�С
	
	vector<vector<int>> chessMap;//�洢��ǰ������ӵķֲ�����0���հף�1�����ӣ�-1������

	//��ʾ���ڸ�˭����
	bool playerFlag;//true:�ú�����  false: �ð�����

	void updateGameMap(ChessPos* pos);

	bool checkWin();//�����Ӯ�����ʤ���ѷ־ͷ���true

	ChessPos lastPos;//������ӵ��λ��
};

