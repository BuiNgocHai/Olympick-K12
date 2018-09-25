#include <ai/Game.h>
#include <ai/AI.h>
#include <time.h>
#include <vector>
#include <queue>

using namespace std;

struct ToaDo {
	int x, y, val;
	ToaDo(int x1, int y1, int val1) {
		x = x1;
		y = y1;
		val = val1;
	}
	
};

int _X[] = { 0,0,1,-1 };
int _Y[] = { 1,-1,0,0 };
int B[105][105];
int A[105][105];
int w = 20, h = 20;
bool valid(int x, int y) {
	return x >= 1 && x <= w && y >= 1 && y <= h;
}
int FindHuong(int x, int y) {
	if (A[x - 1][y] < A[x][y] && A[x - 1][y] >= 0 && valid(x - 1, y)) {
		return 1;
	}
	if (A[x][y + 1] < A[x][y] && A[x][y + 1] >= 0 && valid(x, y + 1)) {
		return 2;
	}
	if (A[x + 1][y] < A[x][y] && A[x + 1][y] >= 0 && valid(x + 1, y)) {
		return 3;
	}
	if (A[x][y - 1] < A[x][y] && A[x][y - 1] >= 0 && valid(x, y - 1)) {
		return 4;
	}
	return 0;
}

void outputB() {
	for (int i = 1; i <= 20; ++i) {
		for (int j = 1; j <= 20; ++j) {
			printf("%3d", B[i][j]);
		}
		printf("\n \n");
	}
	printf("=============================================");
}
void input() {
	AI *p_AI = AI::GetInstance();
	for (int i = 1; i <= 20; ++i) {
		for (int j = 1; j <= 20; ++j) {
			B[i][j] = p_AI->GetBlock(j, i);
		}
	}
	for (int i = 0; i<NUMBER_OF_TANK; i++) {
		Tank* tempTank = p_AI->GetEnemyTank(i);

		if (tempTank != NULL) {
			if (tempTank->GetHP() == 0) {
				B[(int)tempTank->GetY()][(int)tempTank->GetX()] = 1;
			}
			else {
				B[(int)tempTank->GetY()][(int)tempTank->GetX()] = 1;
			}
		}
	}
	for (int i = 0; i<NUMBER_OF_TANK; i++) {
		Tank* tempTank = p_AI->GetMyTank(i);

		if (tempTank != NULL) {
			if (tempTank->GetHP() == 0) {
				B[(int)tempTank->GetY()][(int)tempTank->GetX()] = 1;
			}
			else {
				B[(int)tempTank->GetY()][(int)tempTank->GetX()] = 1;
			}
		}
	}
}  
int endx, endy;

void BFS() {
	queue <ToaDo> Q;
	Q.push(ToaDo(endx, endy, 0));
	while (!Q.empty()) {
		ToaDo temp = Q.front();
		Q.pop();
		if (B[temp.x][temp.y] == 0) {

			B[temp.x][temp.y] = 1;
			A[temp.x][temp.y] = temp.val;
			for (int i = 0; i < 4; ++i) {
				int x = temp.x + _X[i];
				int y = temp.y + _Y[i];
				if (valid(x, y) && B[x][y] == 0) {
					Q.push(ToaDo(x, y, temp.val + 1));
				}
			}
		}
	}
}

/*void BuildListEnemy() {
	AI *p_AI = AI::GetInstance();
	
	for (int i = 0; i < NUMBER_OF_TANK; i++) {
		Tank* temp = p_AI->GetEnemyTank(i);
		if ((temp == NULL) || (temp->GetHP() == 0))
			continue;
		int y = temp->GetX();
		int x = temp->GetY();
		for (int i = 0; i < 4; ++i) {
			for (int j = 1; ; ++j) {
				ToaDo td = ToaDo(x + (j * _X[i]), y + (j* _Y[i]), 0);
				if (p_AI->GetBlock(td.y, td.x) != 0) {
					break;
				}
			}
		}
	}
}*/

void AI_Placement()
{
	AI *p_AI = AI::GetInstance();
	if (p_AI->GetMyTeam() == TEAM_1) {
		Game::PlaceTank(TANK_LIGHT, 7, 1);
		Game::PlaceTank(TANK_HEAVY, 7, 7);
		Game::PlaceTank(TANK_MEDIUM, 7, 15);
		Game::PlaceTank(TANK_HEAVY, 7, 20);
	}
	else if (p_AI->GetMyTeam() == TEAM_2) {
		Game::PlaceTank(TANK_MEDIUM, 14, 1);
		Game::PlaceTank(TANK_HEAVY, 14, 7);
		Game::PlaceTank(TANK_MEDIUM, 14, 15);
		Game::PlaceTank(TANK_LIGHT, 14, 20);
	}
}
void BuildMap() {

	for (int i = 1; i <= 20; ++i) {
		for (int j = 1; j <= 20; ++j) {
			B[i][j] = 0;
			A[i][j] = 0;
		}
	}
}

int milis = 0;
void AI_Update()
{
	milis++;
	if (milis % 10 == 0) {
		cout << milis << endl;
	}
	AI *p_AI = AI::GetInstance();
	
	vector<Strike*> strike = p_AI->GetIncomingStrike(); //viên đạn đang rơi thì sẽ có ở trong list strike
	for (int i = 0; i<strike.size(); i++)
	{
		float x = strike[i]->GetX();// cột của viên đạn
		float y = strike[i]->GetY();// hàng của viên đạn.
		int count = strike[i]->GetCountDown(); // Delay (in server loop) before the strike reach the battlefield.
		int type = strike[i]->GetType();

		if (type == POWERUP_AIRSTRIKE)
		{
			// You may want to do something here, like moving your tank away if the strike is on top of your tank.
		}
		else if (type == POWERUP_EMP)
		{
			// Run... RUN!!!!
		}
	}

	
	vector<PowerUp*>  powerUp = p_AI->GetPowerUpList();
	for (int i = 0; i<powerUp.size(); i++) {
		float x = powerUp[i]->GetX();
		float y = powerUp[i]->GetY();
		int type = powerUp[i]->GetType();
		if (type == POWERUP_AIRSTRIKE)
		{
			// You may want to move your tank to this position to secure this power up.
		}
		else if (type == POWERUP_EMP)
		{
			// Do something else
		}
	}

	input();
	//outputA();
	//outputB();
	for (int i = 0; i <4; i++) {
		Tank* tempTank = p_AI->GetMyTank(i);
		if ((tempTank == NULL) || (tempTank->GetHP() == 0))
			continue;

		
		if (i == 0) {
			for (int j = 0; j < 4; j++) {
				Tank* tempEnemy = p_AI->GetEnemyTank(j);
				if (p_AI->GetEnemyTank(j)->GetHP() != 0) {
					endx = tempEnemy->GetX();
					endy = tempEnemy->GetY();
					BuildMap();
					BFS();
					if (tempTank->GetX() == (int)tempEnemy->GetX()) {
						if ((int)tempTank->GetY() < (int)tempEnemy->GetY())
							Game::CommandTank(i, 3, false, true);
						else
							Game::CommandTank(i, 1, false, true);
					}
					else if ((int)tempTank->GetY() == (int)tempEnemy->GetY()){
						if (tempTank->GetX() < (int)tempEnemy->GetX()) {
							Game::CommandTank(i, 2, false, true);
						}	
						else {
							Game::CommandTank(i, 4, false, true);
						}
					}
				}
				else {
					int x = tempTank->GetX(); 
					int y = tempTank->GetY();
					Game::CommandTank(i, FindHuong(y,x), true, true);
				}
			}
		}
		if (i == 1) {
			for (int j = 0; j < 4; j++) {
				Tank* tempEnemy = p_AI->GetEnemyTank(j);
				if (p_AI->GetEnemyTank(j)->GetHP() != 0) {
					endx = tempEnemy->GetX();
					endy = tempEnemy->GetY();
					BuildMap();
					BFS();
					if (tempTank->GetX() == (int)tempEnemy->GetX()) {
						if ((int)tempTank->GetY() < (int)tempEnemy->GetY())
							Game::CommandTank(i, 3, false, true);
						else
							Game::CommandTank(i, 1, false, true);
					}
					else if ((int)tempTank->GetY() == (int)tempEnemy->GetY()) {
						if (tempTank->GetX() < (int)tempEnemy->GetX()) {
							Game::CommandTank(i, 2, false, true);
						}
						else {
							Game::CommandTank(i, 4, false, true);
						}
					}
				}
				else {
					int x = tempTank->GetX();
					int y = tempTank->GetY();
					Game::CommandTank(i, FindHuong(y, x), true, true);
				}
			}
		}
	}
       /*					if ((int)tempTank->GetX() == (int)tempEnemy->GetX()) {
						if ((int)tempTank->GetY() < (int)tempEnemy->GetY()) {
							Game::CommandTank(i, 3, false, true);
						}
						else {
							Game::CommandTank(i, 1, false, true);
						}
					}
					else if ((int)tempTank->GetY() == (int)tempEnemy->GetY()) {
						if ((int)tempTank->GetX() < (int)tempEnemy->GetX()) {
							Game::CommandTank(i, 2, false, true);
						}
						else {
							Game::CommandTank(i, 4, false, true);
						}
					}
				}
			}
			else {
				Game::CommandTank(i, FindHuong(y, x), true, true);
			}
		 //
		else {
			Game::CommandTank(i, 0, true, true);
		}
	}

*/
	
	if (p_AI->HasAirstrike())
	{
		for (int i = 0; i < NUMBER_OF_TANK; i++)
		{
			Tank* tempTank = p_AI->GetEnemyTank(i);
			if (tempTank->GetHP() > 0) {
				p_AI->UseAirstrike(tempTank->GetX(), tempTank->GetY());
			}
		}
	}
	else if (p_AI->HasEMP())
	{
		for (int i = 0; i < NUMBER_OF_TANK; i++)
		{
			Tank* tempTank = p_AI->GetEnemyTank(i);
			if (tempTank->GetHP() > 0)
			{
				p_AI->UseEMP(tempTank->GetX(), tempTank->GetY());
			}
		}
	}

	Game::GetInstance()->SendCommand();
}

////////////////////////////////////////////////////////////
//                DON'T TOUCH THIS PART                   //
////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	srand(clock());

#ifdef _WIN32
	INT rc;
	WSADATA wsaData;

	rc = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (rc) {
		printf("WSAStartup Failed.\n");
		return 1;
	}
#endif

	Game::CreateInstance();
	Game * p_Game = Game::GetInstance();

	// Create connection
	if (p_Game->Connect(argc, argv) == -1)
	{
		LOG("Failed to connect to server!\n");
		return -1;
	}

	// Set up function pointers
	AI::GetInstance()->PlaceTank = &AI_Placement;
	AI::GetInstance()->Update = &AI_Update;

	// Polling every 100ms until the connection is dead
	p_Game->PollingFromServer();

	Game::DestroyInstance();

#ifdef _WIN32
	WSACleanup();
#endif
	return 0;
}