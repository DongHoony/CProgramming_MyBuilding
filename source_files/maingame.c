#include "..\\header_files\\maingame.h"
//
//int PlayMaingame() {
//
//	int (*PlayGame[GAME_NUMBER])();
//	int choose_game;
//	int multiple = 0;
//	int win_or_lose = 0;
//	int go_or_stop = 1;
//	int result;
//
//	PlayGame[0] = PlayHeadOrTail;
//
//	
//	while (multiple < 3 && win_or_lose == 0 && go_or_stop == 1) {
//
//		//choose_game = ChooseGame();
//
//		PlayGame[choose_game](&multiple, &win_or_lose);
//
//		if (win_or_lose == 0 && multiple <2)
//			GoOrStop(&go_or_stop);
//
//	}
//
//	gotoyx_clear();
//	gotoyx_set_color(C_WHITE);
//
//	result = SetResult(&multiple, &win_or_lose);
//
//	return multiple;
//}


int SetBet() {

	//����� �ϳ����̸� ���� ���ӿ�����Ʈ�� �������� ���� COMPONENT��ü�� ������Ʈ�� �� ó�� ��뵵 ����
	RenderComponent* Menu = NewRenderComponent(RENDER_COMPONENT);

	//����� �� �� �̻��̸� ���ӿ�����Ʈ�� �����ؾ���
	GameObject* Cursor = NewGameObject(SYSTEMCURSOR_GAMEOBJECT);

	//���� ����� �ϳ����� ���ӿ�����Ʈ�� �����ص� ��
	GameObject* Player = NewGameObject(PLAYER_GAMEOBJECT);

	//���ӿ�����Ʈ�� Cursor�� Render ������Ʈ�� InputComponent ������Ʈ, Trigger ������Ʈ �߰�
	RenderComponent* CursorRender = NewRenderComponent(RENDER_COMPONENT);
	Cursor->InsertComponent(Cursor->cthis, RENDER_COMPONENT, (ComponentBase*)CursorRender);
	CursorComponent* CursorCursor = NewCursorComponent(CURSOR_COMPONENT);
	Cursor->InsertComponent(Cursor->cthis, CURSOR_COMPONENT, (ComponentBase*)CursorCursor);

	InputComponent* PlayerInput = NewInputComponent(INPUT_COMPONENT);
	Player->InsertComponent(Player->cthis, INPUT_COMPONENT, (ComponentBase*)PlayerInput);
	
	/* Render ������Ʈ ������ �ҷ����� */
	Menu->SetInputHeight(Menu->cthis, 7);
	Menu->SetInputWidth(Menu->cthis, 100);
	Menu->GetData(Menu->cthis, "..\\data\\SetBetMenu.txt");
	((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->SetInputHeight(((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->cthis, 1);
	// CursorRender->SetInputHeight(CursorRender->cthis, 1);�� ����
	((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->SetInputWidth(((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->cthis, 3);
	((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->GetData(((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->cthis, "..\\data\\SetBetCursor.txt");
	// CursorRender->GetData(CursorRender->cthis, "SetBetCursor.txt");�� ����

	// Cursor ������Ʈ ����
	((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->max = 3;
	((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->min = 0;
	
	Menu->Render(Menu->cthis, 50, 17, 0, C_GREEN);
	((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->Render(((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->cthis, ((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->arrow * 7 + 54, 22, 0, C_BLUE);

	while (1) {

		//Player���� ������Ʈ���� InputComponent �̿��ؼ� �Է°� �޾ƿ���
		((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input = ((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->GetInput(((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->cthis);
		
		//�Է°��� ������ ȭ��ǥ�̸�
		if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == RIGHT_ARROW && ((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->arrow < ((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->max) {
			((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->arrow++;
			gotoyx_clear(); 
			Menu->Render(Menu->cthis, 50, 17, 0, C_GREEN);
			((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->Render(((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->cthis, ((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->arrow * 7 + 54, 22, 0, C_BLUE);

		}
		//�Է°��� ���� ȭ��ǥ�̸�
		else if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == LEFT_ARROW && ((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->arrow > ((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->min) {
			((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->arrow--;
			gotoyx_clear();
			Menu->Render(Menu->cthis, 50, 17, 0, C_GREEN);
			((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->Render(((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->cthis, ((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->arrow * 7 + 54, 22, 0, C_BLUE);

		}
		//�Է°��� �����̸�
		else if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == ENTER) {
			gotoyx_clear();
			break;
		}

		}

	gotoyx_clear();

	return (((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->arrow)*5000;
}
//
//int Square(int num, int times) {
//	
//	if (times == 0)
//		return 0;
//
//	int total = 1;
//
//	for (int i = 0; i < times; i++)
//		total *= num;
//
//	return total;
//}

int ChooseGame() {

	srand((unsigned)time(NULL));

	return rand() % GAME_NUMBER;
}
int GoOrStop() {

	int go_or_stop;

	GameObject* SystemMenu = NewGameObject(SYSTEMMENU_GAMEOBJECT);
	GameObject* SystemCursor = NewGameObject(SYSTEMCURSOR_GAMEOBJECT);
	GameObject* Player = NewGameObject(PLAYER_GAMEOBJECT);

	RenderComponent* SystemMenuRender = NewRenderComponent(RENDER_COMPONENT);
	SystemMenu->InsertComponent(SystemMenu->cthis, RENDER_COMPONENT, (ComponentBase*)SystemMenuRender);

	RenderComponent* SystemCursorRender = NewRenderComponent(RENDER_COMPONENT);
	SystemCursor->InsertComponent(SystemCursor->cthis, RENDER_COMPONENT, (ComponentBase*)SystemCursorRender);
	CursorComponent* SystemCursorCursor = NewCursorComponent(CURSOR_COMPONENT);
	SystemCursor->InsertComponent(SystemCursor->cthis, CURSOR_COMPONENT, (ComponentBase*)SystemCursorCursor);

	InputComponent* PlayerInput = NewInputComponent(INPUT_COMPONENT);
	Player->InsertComponent(Player->cthis, INPUT_COMPONENT, (ComponentBase*)PlayerInput);

	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->SetInputHeight((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 7);
	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->SetInputWidth((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 100);
	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->GetData((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), "..\\data\\GoOrStopMenu.txt");
	((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->SetInputHeight((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT), 1);
	((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->SetInputWidth((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT), 5);
	((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->GetData((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT), "..\\data\\GoOrStopCursor.txt");
	
	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render(((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->cthis, 50, 17, 0, C_GREEN);
	((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT), ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow * 11 + 58, 22, 0, C_BLUE);

	while (1) {

		
		((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input = ((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->GetInput((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT));
		if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == RIGHT_ARROW && ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow < 1) {
			((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->pTriggerComponent->AddValue(((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->pTriggerComponent->cthis, &((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow, 1);
			gotoyx_clear(); 
			((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render(((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->cthis, 50, 17, 0, C_GREEN);
			((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT), ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow * 11 + 58, 22, 0, C_BLUE);

		}
		else if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == LEFT_ARROW && ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow > 0) {
			((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->pTriggerComponent->AddValue(((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->pTriggerComponent->cthis, &((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow, -1);
			gotoyx_clear(); 
			((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render(((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->cthis, 50, 17, 0, C_GREEN);
			((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT), ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow * 11 + 58, 22, 0, C_BLUE);

		}
		else if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == ENTER) {
			go_or_stop = !(((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow);
			gotoyx_clear();
			gotoyx_set_color(C_WHITE);
			return go_or_stop;
		}
		

	}
}

int SetResult(int* multiple, int* win_or_lose) {

	if (*win_or_lose == 0) {
		return (*multiple);
	}
	else if (*win_or_lose == 1) {
		return 0;
	}
}

int PlayHeadOrTail() {

	//���� ������Ʈ ����
	GameObject* Player = NewGameObject(PLAYER_GAMEOBJECT);
	GameObject* Coin = NewGameObject(COIN_GAMEOBJECT);
	GameObject* SystemMenu = NewGameObject(SYSTEMMENU_GAMEOBJECT);
	GameObject* SystemCursor = NewGameObject(SYSTEMCURSOR_GAMEOBJECT);

	//Player ������Ʈ�� Input��� �߰�
	InputComponent* PlayerInput = NewInputComponent(INPUT_COMPONENT);
	Player->InsertComponent(Player->cthis, INPUT_COMPONENT, (ComponentBase*)PlayerInput);
	
	//Coin ������Ʈ�� Roll���, Animation��� �߰�
	RollComponent* CoinRoll = NewRollComponent(ROLL_COMPONENT);
	Coin->InsertComponent(Coin->cthis, CoinRoll->pComponentBase->ComponentID, (ComponentBase*)CoinRoll);
	AnimationComponent* CoinAnimation = NewAnimationComponent(ANIMATION_COMPONENT);
	Coin->InsertComponent(Coin->cthis, CoinAnimation->pComponentBase->ComponentID, (ComponentBase*)CoinAnimation);

	//SystemMenu������Ʈ�� Trigger���, Render��� �߰�
	TriggerComponent* SystemMenuTrigger = NewTriggerComponent(TRIGGER_COMPONENT);
	SystemMenu->InsertComponent(SystemMenu->cthis, SystemMenuTrigger->pComponentBase->ComponentID, (ComponentBase*)SystemMenuTrigger);
	RenderComponent* SystemMenuRender = NewRenderComponent(RENDER_COMPONENT);
	SystemMenu->InsertComponent(SystemMenu->cthis, SystemMenuRender->pComponentBase->ComponentID, (ComponentBase*)SystemMenuRender);

	//SystemCursor������Ʈ�� Render���, Cursor��� �߰�
	RenderComponent* SystemCursorRender = NewRenderComponent(RENDER_COMPONENT);
	SystemCursor->InsertComponent(SystemCursor->cthis, SystemCursorRender->pComponentBase->ComponentID, (ComponentBase*)SystemCursorRender);
	CursorComponent* SystemCursorCursor = NewCursorComponent(CURSOR_COMPONENT);
	SystemCursor->InsertComponent(SystemCursor->cthis, SystemCursorCursor->pComponentBase->ComponentID, (ComponentBase*)SystemCursorCursor);

	int guess = 0;
	int win_or_lose = 0;

	//RENDER ������ ����
	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->SetInputHeight((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 7);
	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->SetInputWidth((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT)->cthis, 100);
	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->GetData((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT)->cthis, "..\\data\\HeadOrTailSystemMenu.txt");
	((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->SetInputHeight((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT)->cthis, 1);
	((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->SetInputWidth((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT)->cthis, 3);
	((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->GetData((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT)->cthis, "..\\data\\HeadOrTailSystemCursor.txt");

	//ROll ������ ����
	((RollComponent*)Coin->GetComponent(Coin->cthis, ROLL_COMPONENT))->GetRandom((RollComponent*)Coin->GetComponent(Coin->cthis, ROLL_COMPONENT)->cthis, 2);

	guess = HeadOrTail0(SystemMenu, SystemCursor, Player);
	HeadOrTail1(SystemMenu, Coin);
	win_or_lose = HeadOrTail2(&guess, SystemMenu, Coin, Player);

	return win_or_lose;
}

HeadOrTail0(GameObject* SystemMenu, GameObject* SystemCursor, GameObject* Player) {
	
	int guess = 0;

	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 50, 17, 0, C_GREEN);
	((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT), ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow * 11 + 58, 22, 0, C_BLUE);

	while (1) {
		
		((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input = ((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->GetInput((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT));
		if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == RIGHT_ARROW && ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow < 1) {
			((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->pTriggerComponent->AddValue(((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->pTriggerComponent->cthis, &((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow, 1);
			gotoyx_clear();
			((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 50, 17, 0, C_GREEN);
			((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT), ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow * 11 + 58, 22, 0, C_BLUE);
		}
		else if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == LEFT_ARROW && ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow > 0) {
			((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->pTriggerComponent->AddValue(((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->pTriggerComponent->cthis, &((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow, -1);
			gotoyx_clear(); ((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 50, 17, 0, C_GREEN);
			((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT), ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow * 11 + 58, 22, 0, C_BLUE);

		}
		else if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == ENTER) {
			guess = ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow;
			((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input = 0;
			gotoyx_clear(); ((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 50, 17, 0, C_GREEN);
			((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT), ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow * 11 + 58, 22, 0, C_BLUE);

			return guess;
		}
	}
}
HeadOrTail1(GameObject* SystemMenu, GameObject* Coin) {

	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 50, 17, 1, C_GREEN);

	while (1) {
			
		((AnimationComponent*)Coin->GetComponent(Coin->cthis, ANIMATION_COMPONENT))->Animation((AnimationComponent*)Coin->GetComponent(Coin->cthis, ANIMATION_COMPONENT), 100, "..//data\\HeadOrTailCoinAnimation.txt", 68, 22, 1, 4, C_GREEN);

		if (((AnimationComponent*)Coin->GetComponent(Coin->cthis, ANIMATION_COMPONENT))->animation_switch == 2) {
			gotoyx_clear();
			return 0;
		}
	}

}
HeadOrTail2(int* guess, GameObject* SystemMenu, GameObject* Coin, GameObject* Player){
	
	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 50, 17, 2, C_GREEN);

	while (1) {

		((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input = ((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->GetInput(((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->cthis);
		if (*guess == ((RollComponent*)Coin->GetComponent(Coin->cthis, ROLL_COMPONENT))->random_number) {
			if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == ENTER) {
				gotoyx_clear();
				return 1;
			}
		}
		else {
			((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 50, 17, 3, C_GREEN);

			if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == ENTER) {
				gotoyx_clear();
				gotoyx_set_color(C_WHITE);
				return 0;
			}
		}
	}
}