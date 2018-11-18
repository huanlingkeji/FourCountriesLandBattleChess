#include "ChessComposition.h"
#include "Mediator.h"

enum SquareType {
	YIZHAN = 1 << 1,		//��վ
	BINGYING = 1 << 2,		//��Ӫ
	BINGZHAN = 1 << 3,		//��վ
	JUNYING = 1 << 4,		//��Ӫ
	QITA = 0				//����
};
enum ChessType {
	CHESS00,	//ը��	2
	CHESS31,	//����	3
	CHESS32,	//����	3
	CHESS33,	//�ų�	3
	CHESS34,	//����	3
	CHESS35,	//Ӫ��	2
	CHESS36,	//�ų�	2
	CHESS37,	//�ó�	2
	CHESS38,	//ʦ��	2
	CHESS39,	//����	1
	CHESS40,	//˾��	1
	CHESS41		//����	1
};

TCHAR ChessName[12][5] = {
	_T("ը"),
	_T("��"),
	_T("��"),
	_T("��"),
	_T("��"),
	_T("Ӫ"),
	_T("��"),
	_T("��"),
	_T("ʦ"),
	_T("��"),
	_T("˾"),
	_T("��")
};

TCHAR Lables[18][5] = {
	_T("��"),
	_T("��"),
	_T("С"),

	_T("��"),
	_T("��"),
	_T("-"),

	_T("��"),
	_T("��"),
	_T("��"),

	_T("Ӫ"),
	_T("��"),
	_T("��"),

	_T("ʦ"),
	_T("��"),
	_T("˾"),

	_T("ը"),
	_T("��"),
	_T("��")
};

int Colors[4] = { YELLOW ,BLUE ,RED,PURPLE };

const char *TYPE_FILE_NAME = "SquareTypeData.txt";
const char *DIRECTION_FILE_NAME = "SquareDirectionData.txt";
const char *POSITION_FILE_NAME = "ChessPiecesPositionData.txt";
const char *NUMBER_FILE_NAME = "ChessPiecesNumberData.txt";

ChessComposition::ChessComposition(Mediator *mediator1)
{
	mediator = mediator1;
	mediator->SetCCst(this);
	ordernum = mediator->GetOrdernum();

	loadimage(&img, _T("test.bmp"), 800, 800);
	InitSquare();
	InitChessPieces();
}

ChessComposition::~ChessComposition()
{

}

void ChessComposition::Update()
{
	putimage(0, 0, &img);
	Draw();
}

void ChessComposition::Draw()
{
	for (int i = 0; i < 4; i++)
	{
		//�жϴ�� ׼��
		if (i != ordernum && !mediator->RsPlayerReady(i))
		{
			continue;
		}
		for (int j = 0; j < 25; j++)
		{
			if (chesspieces[i][j].viable)
			{
				setfillcolor(Colors[chesspieces[i][j].camp]);
				int logicx, logicy;
				PposiToLposi(chesspieces[i][j].cx, chesspieces[i][j].cy, logicx, logicy);
				if (logicy < 7 || logicy>11)
				{
					fillrectangle(20 + logicy * 40, 15 + logicx * 40, 40 + logicy * 40, 45 + logicx * 40);//����ľ���
				}
				else
				{
					fillrectangle(15 + logicy * 40, 20 + logicx * 40, 45 + logicy * 40, 40 + logicx * 40);//����ľ���
				}
				if (chesspieces[i][j].camp == ordernum)
				{
					setcolor(BLACK);
					outtextxy(23 + logicy * 40, 23 + logicx * 40, ChessName[chesspieces[i][j].number]);
					setcolor(WHITE);
				}

				if (chesspieces[i][j].label >= 0)
				{
					setfillcolor(WHITE);
					fillrectangle(22 + logicy * 40, 22 + logicx * 40, 38 + logicy * 40, 38 + logicx * 40);//����ľ���
					setcolor(BLACK);
					outtextxy(23 + logicy * 40, 23 + logicx * 40, Lables[chesspieces[i][j].label]);
					setcolor(WHITE);
				}
			}
		}
	}
}

void ChessComposition::InitSquare()
{
	//��ʼ������  �����������ͺͷ�����ļ��л�ȡ
	ifstream typein;
	typein.open(TYPE_FILE_NAME, ios::in);
	if (!typein.is_open())
	{
		exit(0);
	}
	ifstream directionin;
	directionin.open(DIRECTION_FILE_NAME, ios::in);
	if (!directionin.is_open())
	{
		exit(0);
	}
	int squaretype = 0;
	int squaredirection = 0;
	for (int i = 0; i < SQUARE_ROW; i++)
	{
		for (int j = 0; j < SQUARE_ROW; j++)
		{
			typein >> squaretype;
			directionin >> squaredirection;
			squares[i][j].sx = i;
			squares[i][j].sy = j;
			squares[i][j].type = squaretype;
			squares[i][j].direction = squaredirection;
			squares[i][j].chesspieces = NULL;
		}
	}
}

void ChessComposition::InitChessPieces()
{
	//������������  //��ʼ������  �����������ͺͷ�����ļ��л�ȡ
	ifstream positionout;
	positionout.open(POSITION_FILE_NAME, ios::in);
	if (!positionout.is_open())
	{
		exit(0);
	}
	int px = 0;
	int py = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			positionout >> px;
			positionout >> py;
			chesspieces[i][j].cx = px;							//����
			chesspieces[i][j].cy = py;

			//	cout <<j << "->"<< px << "  " << py << endl;

			chesspieces[i][j].camp = i;							//��Ӫ
			chesspieces[i][j].ismove = true;					//���ƶ�	
			chesspieces[i][j].viable = true;					//���
			chesspieces[i][j].number = -1;						//���
			chesspieces[i][j].label = -1;						//��ע
			squares[px][py].chesspieces = &chesspieces[i][j];	//����ϵ�����
		}
		//	cout << endl;
	}
	positionout.close();
	//�����Լ����ӵı���Լ����ƶ���
	ifstream numberout;
	numberout.open(NUMBER_FILE_NAME, ios::in);
	if (!numberout.is_open())
	{
		exit(0);
	}
	int cnumber = 0;
	for (int i = 0; i < 25; i++)
	{
		numberout >> cnumber;
		chesspieces[ordernum][i].number = cnumber;
		if (cnumber == CHESS41 || cnumber == CHESS31)
		{
			chesspieces[ordernum][i].ismove = false;
		}
	}
	numberout.close();
}

void ChessComposition::LposiToPposi(int lx, int ly, int & px, int & py)
{
	LpToPp(ordernum, lx, ly, px, py);
}

void ChessComposition::PposiToLposi(int px, int py, int & lx, int & ly)
{
	PpToLp(ordernum, px, py, lx, ly);
}

ChessPieces * ChessComposition::GetChess(int x1, int y1)
{
	Square *square = GetSquare(x1, y1);
	if (square)
	{
		return square->chesspieces;
	}
	return NULL;
}

Square * ChessComposition::GetSquare(int x1, int y1)
{
	int rx = (y1 - 15) / 40;		//��
	int ry = (x1 - 15) / 40;		//��
	if (rx < 0 || rx >= SQUARE_ROW || ry < 0 || ry >= SQUARE_ROW)
	{
		return NULL;
	}
	//��ȡ��������
	int ox = 30 + ry * 40;
	int oy = 30 + rx * 40;

	//ѡ��ĳ�����
	if ((x1 - ox)*(x1 - ox) + (y1 - oy)*(y1 - oy) < 225)
	{
		//��ȡ��������
		int px, py;
		LposiToPposi(rx, ry, px, py);
		return &squares[px][py];
	}
	return NULL;
}

bool ChessComposition::ExchangeChess(ChessPieces * cps1, ChessPieces * cps2)
{
	if (cps1->number == CHESS41 && !RsPutChess41(cps2->cx, cps2->cy) ||
		cps2->number == CHESS41 && !RsPutChess41(cps1->cx, cps1->cy) ||
		cps1->number == CHESS00 && !RsPutChess00(cps2->cx, cps2->cy) ||
		cps2->number == CHESS00 && !RsPutChess00(cps1->cx, cps1->cy) ||
		cps1->number == CHESS31 && !RsPutChess31(cps2->cx, cps2->cy) ||
		cps2->number == CHESS31 && !RsPutChess31(cps1->cx, cps1->cy))
	{
		return false;
	}
	//���������ӵ�λ��
	int tempx = cps1->cx;
	int tempy = cps1->cy;
	cps1->cx = cps2->cx;
	cps1->cy = cps2->cy;
	cps2->cx = tempx;
	cps2->cy = tempy;
	//����Ӧ�����ˢ��ָ�������
	ChessPieces *tempcps = squares[cps1->cx][cps1->cy].chesspieces;
	squares[cps1->cx][cps1->cy].chesspieces = squares[cps2->cx][cps2->cy].chesspieces;
	squares[cps2->cx][cps2->cy].chesspieces = tempcps;
	return true;
}

bool ChessComposition::RsPutChess31(int x1, int y1)
{
	bool flag = true;
	switch (ordernum)
	{
	case 0:
		if (x1 > 2)
		{
			flag = false;
		}
		break;
	case 1:
		if (y1 > 2)
		{
			flag = false;
		}
		break;
	case 2:
		if (x1 < 16)
		{
			flag = false;
		}
		break;
	case 3:
		if (y1 < 16)
		{
			flag = false;
		}
		break;
	}
	if (!flag)
	{
		mediator->AddTip(_T("�����޷��ƶ�����λ��"));
		return false;
	}
	return true;
}

void ChessComposition::SaveChessPosition()
{
	ofstream numberout;
	numberout.open(NUMBER_FILE_NAME, ios::out);
	if (!numberout.is_open())
	{
		exit(0);
	}

	int array[2][4] = { { 6,6,12,12 },{ 11,7,7,11 } };
	int dir[2][4] = { { -1,-1,1,1 },{ -1,1,1,-1 } };
	int x, y;
	for (int j = 0; j < 6; j++)
	{
		for (int k = 0; k < 5; k++)
		{
			if (ordernum % 2 == 0)
			{
				x = array[0][ordernum] + j * dir[0][ordernum];
				y = array[1][ordernum] + k * dir[1][ordernum];
			}
			else
			{
				y = array[0][ordernum] + j * dir[0][ordernum];
				x = array[1][ordernum] + k * dir[1][ordernum];
			}
			if (squares[x][y].type > 0 && squares[x][y].type != BINGYING)//���̵���� �Ǳ�Ӫλ��
			{
				numberout << space << squares[x][y].chesspieces->number << NEWLINE;
			}
		}
	}
	numberout.close();
}

bool ChessComposition::RsPutChess00(int x1, int y1)
{
	bool flag = true;
	switch (ordernum)
	{
	case 0:
		if (x1 == 6)
		{
			flag = false;
		}
		break;
	case 1:
		if (y1 == 6)
		{
			flag = false;
		}
		break;
	case 2:
		if (x1 == 12)
		{
			flag = false;
		}
		break;
	case 3:
		if (y1 == 12)
		{
			flag = false;
		}
		break;
	}
	if (!flag)
	{
		mediator->AddTip(_T("ը���޷��ƶ�����λ��"));
		return false;
	}
	return true;
}

bool ChessComposition::RsPutChess41(int x1, int y1)
{
	int array[4][2][2] = {
	{ {  1, 1 },{  8,10 } },
	{ {  8,10 },{  1, 1 } },
	{ { 17,17 },{  8,10 } },
	{ {  8,10 },{ 17,17 } }
	};
	for (int i = 0; i < 2; i++)
	{
		if (x1 == array[ordernum][0][i] && y1 == array[ordernum][1][i])
		{
			return true;
		}
	}
	mediator->AddTip(_T("�����޷��ƶ�����λ��"));
	return false;
}

bool ChessComposition::CanMoveChess(ChessPieces * cps1, Square * square1)
{
	//�����ж������Ƿ�����ƶ���Ŀ�����
	int ox = cps1->cx;
	int oy = cps1->cy;
	int tox = square1->sx;
	int toy = square1->sy;
	if (ox == tox && oy == toy)
	{
		mediator->AddTip(_T("����ԭ���ƶ�"));
		return false;
	}
	if (!CanArrivePosition(cps1, square1))
	{
		mediator->AddTip(_T("Ŀ����޷��ﵽ�ƶ�"));
		return false;
	}
	ChessPieces *cps2 = square1->chesspieces;
	if (cps2)
	{
		int camp1 = cps1->camp;
		int camp2 = cps2->camp;
		if ((camp1 + camp2) % 2 == 0)
		{
			mediator->AddTip(_T("Ŀ�ĵ����ҷ�����"));
			return false;
		}
		else
		{
			if (square1->type == BINGYING)
			{
				mediator->AddTip(_T("Ŀ�ĵص������ܵ�����"));
				return false;
			}
			else
			{
				//ע���˲���Ϊ���������غ�����߼�
				int compresult = CompareChess(cps1->number, cps2->number);
				MoveChess(cps1, square1, compresult);
			}
		}
	}
	//ע���˲���Ϊ�������������ݺ�����߼�
	MoveChess(cps1, square1, 3);
	return true;
}

bool ChessComposition::CanArrivePosition(ChessPieces * cps1, Square * square1)
{
	//ע���ɴ���
	int x1 = cps1->cx;
	int y1 = cps1->cy;
	int x2 = square1->sx;
	int y2 = square1->sy;
	int lx1 = squares[x1][y1].type;
	int lx2 = square1->type;
	int biaoshi1 = cps1->number;

	int bianli[2][8] = { { 1,1,1,0,0,-1,-1,-1 },{ 1,0,-1,1,-1,1,0,-1 } };
	//���ݵص�1��������ͻ���
	switch (lx1)
	{
		//��վ
	case YIZHAN:
		//ֱ������Χ��
		if (abs(x1 - x2) < 2 && abs(y1 - y2) < 2)
		{
			if (lx2 == BINGYING)
				return true;
			if (x1 == x2 || y1 == y2)
				return true;
		}
		//��������Χ��
		//����������
		if (biaoshi1 == CHESS32)
		{
			if (lx1 == YIZHAN && lx2 == YIZHAN)
			{
				//��������Ѱ·�Ķ�ά��
				int tu[SQUARE_ROW][SQUARE_ROW];
				for (int i = 0; i < SQUARE_ROW; i++)
				{
					for (int j = 0; j < SQUARE_ROW; j++)
					{
						tu[i][j] = -1;
						if (!squares[i][j].chesspieces && squares[i][j].type == YIZHAN)
						{
							tu[i][j] = 0;
						}
					}
				}
				for (int k = 0; k < 3; k++)
				{
					//9Ϊ����
					tu[7 + k * 2][8] = 0;
					tu[7 + k * 2][10] = 0;
					//10Ϊ����
					tu[8][7 + k * 2] = 0;
					tu[10][7 + k * 2] = 0;
				}
				if (Chess32FindWay(tu, x1, y1, x2, y2))
				{
					return true;
				}
			}
		}
		//�ǹ���
		else
		{
			//ֱ������Χ��
			if (abs(x1 - x2) < 2 && abs(y1 - y2) < 2)
			{
				if (lx2 == BINGYING)
					return true;
				if (x1 == x2 || y1 == y2)
					return true;
			}
			//����·��
			if (CommonFindWay(x1, y1, x2, y2))
			{
				return true;
			}
		}
		break;
		//��Ӫ
	case BINGYING:
		if (abs(x1 - x2) < 2 && abs(y1 - y2) < 2)
		{
			return true;
		}
		break;
		//��վ�;�Ӫ
	case BINGZHAN:
	case JUNYING:
		if (abs(x1 - x2) < 2 && abs(y1 - y2) < 2)
		{
			if (lx2 == BINGYING)
				return true;
			if (x1 == x2 || y1 == y2)
				return true;
		}
		break;
	}
	return false;
}

bool ChessComposition::CommonFindWay(int x1, int y1, int x2, int y2)
{
	//ע���ɴ���
	int heng[6] = { 2,6,7,11,12,16 };
	for (int i = 0; i < 6; i++)
	{
		if (x1 == x2 && x1 == heng[i])
		{
			int min = y1 < y2 ? y1 : y2;
			int max = y1 < y2 ? y2 : y1;
			for (int j = min + 1; j <= max - 1; j++)
			{
				if (squares[x1][j].chesspieces)
				{
					return false;
				}
			}
			return true;
		}
		if (y1 == y2 && y1 == heng[i])
		{
			int min = x1 < x2 ? x1 : x2;
			int max = x1 < x2 ? x2 : x1;
			for (int j = min + 1; j <= max - 1; j++)
			{
				if (squares[j][y1].chesspieces)
				{
					return false;
				}
			}
			return true;
		}
	}
	//���ĵ�����
	if (y1 == y2 && y1 == 9 && x1 > 5 && x1 < 13 && x2>5 && x2 < 13)
	{
		int min = x1 < x2 ? x1 : x2;
		int max = x1 < x2 ? x2 : x1;
		for (int j = min + 1; j <= max - 1; j++)
		{
			if (squares[j][y1].chesspieces)
			{
				return false;
			}
		}
		return true;
	}
	//���ĵĺ���
	if (x1 == x2 && x1 == 9 && y1 > 5 && y1 < 13 && y2>5 && y2 < 13)
	{
		int min = y1 < y2 ? y1 : y2;
		int max = y1 < y2 ? y2 : y1;
		for (int j = min + 1; j <= max - 1; j++)
		{
			if (squares[x1][j].chesspieces)
			{
				return false;
			}
		}
		return true;
	}
	int pointx[4] = { 7,11,11,7 };
	int pointy[4] = { 7,7,11,11 };

	int dir[4][2][2] = {
		//����
		{ { 0,-1 },{ -1,0 } },
		//����
		{ { 0,1 },{ -1,0 } },
		//����
		{ { 0,1 },{ 1,0 } },
		//����
		{ { 0,-1 },{ 1,0 } }
	};
	for (int i = 0; i < 4; i++)
	{
		int n = 0;
		//��¼����·��һ���Ƿ��ҵ�����һ���ص�
		bool flag = false;
		for (int j = 1; j < 6; j++)
		{
			int x4 = pointx[i] + j * dir[i][0][0];
			int y4 = pointy[i] + j * dir[i][1][0];
			if (x1 == x4 && y1 == y4 || x2 == x4 && y2 == y4)
			{
				n++;
				break;
			}
			if (squares[x4][y4].chesspieces)
			{
				flag = true;
				break;
			}
		}
		if (flag)
			continue;
		for (int j = 1; j < 6; j++)
		{
			int x4 = pointx[i] + j * dir[i][0][1];
			int y4 = pointy[i] + j * dir[i][1][1];
			if (x1 == x4 && y1 == y4 || x2 == x4 && y2 == y4)
			{
				n++;
				break;
			}
			if (squares[x4][y4].chesspieces)
			{
				flag = true;
				break;
			}
		}
		if (n == 2)
			return true;
	}
	return false;
}

bool ChessComposition::Chess32FindWay(int tu[SQUARE_ROW][SQUARE_ROW], int x1, int y1, int x2, int y2)
{
	//ע���ɴ���
	int b8[2][8] = { { 1,1,-1,1,-1,-1,1,-1 },{ -1,1,-1,-1,1,-1,1,1 } };
	int b4[2][4] = { { -1,0,0,1 },{ 0,-1,1,0 } };
	int zy[2][2] = { { 0,0 },{ -1,1 } };
	int sx[2][2] = { { -1,1 },{ 0,0 } };
	int i = 0;
	stack<int> px;
	stack<int> py;
	px.push(x1);
	py.push(y1);
	tu[x1][y1] = -2;
	while (!px.empty())
	{
		int x = px.top();
		int y = py.top();
		bool flag = false;		//����Ƿ��ҵ�·��
		if (tu[x][y] != -1)
		{
			switch (squares[x][y].direction)
			{
			case 0:
				for (i = 0; i < 4; i++)
				{
					if (x + b4[0][i] == x2 && y + b4[1][i] == y2)
					{
						//����·��
						return true;
					}
					if (tu[x + b4[0][i]][y + b4[1][i]] >= 0)//0Ϊ����
					{
						px.push(x + b4[0][i]);
						py.push(y + b4[1][i]);
						tu[x + b4[0][i]][y + b4[1][i]] = -2;
						flag = true;		//�ҵ�·��
						break;
					}
				}
				break;
			case 9:
				//9Ϊ����
				for (i = 0; i < 2; i++)
				{
					if (x + zy[0][i] == x2 && y + zy[1][i] == y2)
					{
						return true;
					}

					if (tu[x + zy[0][i]][y + zy[1][i]] >= 0)//0Ϊ����
					{
						px.push(x + zy[0][i]);
						py.push(y + zy[1][i]);
						tu[x + zy[0][i]][y + zy[1][i]] = -2;
						flag = true;		//�ҵ�·��
						break;
					}
				}
				break;
			case 10:
				//����
				for (i = 0; i < 2; i++)
				{
					if (x + sx[0][i] == x2 && y + sx[1][i] == y2)
					{
						return true;
					}
					if (tu[x + sx[0][i]][y + sx[1][i]] >= 0)//0Ϊ����
					{
						px.push(x + sx[0][i]);
						py.push(y + sx[1][i]);
						tu[x + sx[0][i]][y + sx[1][i]] = -2;
						flag = true;		//�ҵ�·��
						break;
					}
				}
				break;
			default:
				for (i = 0; i < 4; i++)
				{
					if (x + b4[0][i] == x2 && y + b4[1][i] == y2)
					{
						return true;
					}
					if (tu[x + b4[0][i]][y + b4[1][i]] >= 0)//0Ϊ����
					{
						px.push(x + b4[0][i]);
						py.push(y + b4[1][i]);
						tu[x + b4[0][i]][y + b4[1][i]] = -2;
						flag = true;		//�ҵ�·��
						break;
					}
				}
				int x9 = x + b8[0][squares[x][y].direction - 1];
				int y9 = y + b8[1][squares[x][y].direction - 1];
				if (x9 == x2 && y9 == y2)
				{
					return true;
				}
				if (tu[x9][y9] >= 0)//0Ϊ����
				{
					px.push(x9);
					py.push(y9);
					tu[x9][y9] = -2;
					flag = true;		//�ҵ�·��
					break;
				}
				break;
			}
		}
		if (!flag)//����
		{
			px.pop();
			py.pop();
		}
	}
	return false;
}

void ChessComposition::MoveChess(ChessPieces * cps1, Square * square1, int movetype)
{
	//ע���˲���Ӧ���Ƿ��������߼�����
	switch (movetype)
	{
	case 0://A�ɵ�B
		squares[cps1->cx][cps1->cy].chesspieces = NULL;
		cps1->cx = square1->sx;
		cps1->cy = square1->sy;
		square1->chesspieces->viable = false;
		square1->chesspieces = cps1;
		break;
	case 1://A��Bͬ���ھ�
		cps1->viable = false;
		squares[cps1->cx][cps1->cy].chesspieces = NULL;
		square1->chesspieces->viable = false;
		square1->chesspieces = NULL;
		break;
	case 2://A��B�ɵ�
		cps1->viable = false;
		squares[cps1->cx][cps1->cy].chesspieces = NULL;
		break;
	case 3://ֱ���ƶ�
		squares[cps1->cx][cps1->cy].chesspieces = NULL;
		cps1->cx = square1->sx;
		cps1->cy = square1->sy;
		square1->chesspieces = cps1;
		break;
	}
}

int ChessComposition::CompareChess(int g, int s)
{
	//ע���˲���Ӧ��Ϊ�������߼�
	if (g == s || g == CHESS00 || s == CHESS00)
	{
		mediator->AddTip(_T("����ͬ���ھ�"));
		return 1;
	}
	if ((g == CHESS32 && s == CHESS31) || (g != CHESS00 && s == CHESS41) || (g > CHESS32 && g > s))
	{
		mediator->AddTip(_T("����A�ɵ�B"));
		return 0;
	}
	if ((g < s) || (g != CHESS32 && g != CHESS00 && s == CHESS31))
	{
		mediator->AddTip(_T("����A��B�ɵ�"));
		return 2;
	}
	return -1;
}

