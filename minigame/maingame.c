#include "maingame.h"

int PlayMaingame() {

	int (*PlayGame[GAME_NUMBER])(int bet, int* multiple, int* win_or_lose);
	int choose_game;
	int bet;
	int multiple = 0;
	int win_or_lose = 0;


	PlayGame[0] = PlayHeadOrTail;

	SetBet(&bet);

	
	while (multiple < 3 && win_or_lose == 0) {

		choose_game = ChooseGame();

		PlayGame[choose_game](bet, &multiple, &win_or_lose);


	}

	return multiple;
}
int SetBet(int* bet) {

	int arrow = 0;

	//����� �ϳ����̸� ���� ���ӿ�����Ʈ�� �������� ���� COMPONENT��ü�� ������Ʈ�� �� ó�� ��뵵 ����
	RenderComponent* Menu = NewRenderComponent(RENDER_COMPONENT);

	//����� �� �� �̻��̸� ���ӿ�����Ʈ�� ����
	GameObject* Cursor = NewGameObject(SYSTEMCURSOR_GAMEOBJECT);

	//���ӿ�����Ʈ�� Cursor�� Render ������Ʈ�� InputComponent ������Ʈ, Trigger ������Ʈ �߰�
	RenderComponent* CursorRender = NewRenderComponent(RENDER_COMPONENT);
	Cursor->InsertComponent(Cursor->cthis, RENDER_COMPONENT, (ComponentBase*)CursorRender);
	InputComponent* CursorInput = NewInputComponent(INPUT_COMPONENT);
	Cursor->InsertComponent(Cursor->cthis, INPUT_COMPONENT, (ComponentBase*)CursorInput);
	CursorComponent* CursorCursor = NewCursorComponent(CURSOR_COMPONENT);
	Cursor->InsertComponent(Cursor->cthis, CURSOR_COMPONENT, (ComponentBase*)CursorCursor);
	
	/* Render ������Ʈ ������ �ҷ����� */
	Menu->SetInputHeight(Menu->cthis, 7);
	Menu->SetInputWidth(Menu->cthis, 100);
	Menu->GetData(Menu->cthis, "SetBetMenu.txt");
	((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->SetInputHeight(((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->cthis, 1);
	// CursorRender->SetInputHeight(CursorRender->cthis, 1);�� ����
	((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->SetInputWidth(((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->cthis, 3);
	((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->GetData(((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->cthis, "SetBetCursor.txt");
	// CursorRender->GetData(CursorRender->cthis, "SetBetCursor.txt");�� ����

	// Cursor ������Ʈ ����
	((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->max = 2;
	((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->min = 0;

	while (1) {

		//Cursor���� ������Ʈ���� InputComponent �̿��ؼ� �Է°� �޾ƿ���
		((InputComponent*)Cursor->GetComponent(Cursor->cthis, INPUT_COMPONENT))->input = ((InputComponent*)Cursor->GetComponent(Cursor->cthis, INPUT_COMPONENT))->GetInput(((InputComponent*)Cursor->GetComponent(Cursor->cthis, INPUT_COMPONENT))->cthis);
		
		//�Է°��� ������ ȭ��ǥ�̸�
		if (((InputComponent*)Cursor->GetComponent(Cursor->cthis, INPUT_COMPONENT))->input == RIGHT_ARROW && ((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->arrow < ((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->max) {
			((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->arrow++;
			gotoyx_clear();
		}
		//�Է°��� ���� ȭ��ǥ�̸�
		else if (((InputComponent*)Cursor->GetComponent(Cursor->cthis, INPUT_COMPONENT))->input == LEFT_ARROW && ((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->arrow > ((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->min) {
			((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->arrow--;
			gotoyx_clear();
		}
		//�Է°��� �����̸�
		else if (((InputComponent*)Cursor->GetComponent(Cursor->cthis, INPUT_COMPONENT))->input == ENTER) {
			*bet = ( ((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->arrow + 1 ) * 1000;
			gotoyx_clear();
			break;
		}

		Menu->Render(Menu->cthis, 0, 0, 0,  15);
		((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->Render(((RenderComponent*)Cursor->GetComponent(Cursor->cthis, RENDER_COMPONENT))->cthis, ((CursorComponent*)Cursor->GetComponent(Cursor->cthis, CURSOR_COMPONENT))->arrow *3, 20, 0, 8);
		((InputComponent*)Cursor->GetComponent(Cursor->cthis, INPUT_COMPONENT))->input = 0;
	}

	gotoyx_clear();

	return 0;
}

int ChooseGame() {

	srand((unsigned)time(NULL));

	return rand() % GAME_NUMBER;
}
int PlayHeadOrTail(int bet, int* multiple, int* win_or_lose) {

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

	//SystemCursor������Ʈ�� Render��� �߰�
	RenderComponent* SystemCursorRender = NewRenderComponent(RENDER_COMPONENT);
	SystemCursor->InsertComponent(SystemCursor->cthis, SystemCursorRender->pComponentBase->ComponentID, (ComponentBase*)SystemCursorRender);
	CursorComponent* SystemCursorCursor = NewCursorComponent(CURSOR_COMPONENT);
	SystemCursor->InsertComponent(SystemCursor->cthis, SystemCursorCursor->pComponentBase->ComponentID, (ComponentBase*)SystemCursorCursor);

	int menu = 0;
	int guess = 0;

	//RENDER ������ ����
	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->SetInputHeight((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 7);
	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->SetInputWidth((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT)->cthis, 100);
	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->GetData((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT)->cthis, "HeadOrTailSystemMenu.txt");
	((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->SetInputHeight((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT)->cthis, 1);
	((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->SetInputWidth((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT)->cthis, 3);
	((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->GetData((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT)->cthis, "HeadOrTailSystemCursor.txt");

	//ROll ������ ����
	((RollComponent*)Coin->GetComponent(Coin->cthis, ROLL_COMPONENT))->random_number = ((RollComponent*)Coin->GetComponent(Coin->cthis, ROLL_COMPONENT))->GetRandom((RollComponent*)Coin->GetComponent(Coin->cthis, ROLL_COMPONENT)->cthis, 2);

	while (1) {
		/*switch (menu) {
		case 0: HeadOrTail0(&menu, &guess, SystemMenu, Player, SystemCursor,Player);
		case 1: HeadOrTail1(&menu, &guess, SystemMenu, Coin);
		case 2:	HeadOrTail2(&menu, SystemMenu);
		}*/

		if (menu == 0) {
			HeadOrTail0(&menu, &guess, SystemMenu, SystemCursor, Player);
		}
		else if (menu == 1) {
			HeadOrTail1(&menu, SystemMenu, Coin);
		}
		else if (menu == 2) {
			((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 0, 0, 2, 15);
			if (((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow == ((RollComponent*)Coin->GetComponent(Coin->cthis, ROLL_COMPONENT))->random_number) {
				((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 10, 10, 3, 15);
				((TriggerComponent*)SystemMenu->GetComponent(SystemMenu->cthis, TRIGGER_COMPONENT))->AddValue((TriggerComponent*)SystemMenu->GetComponent(SystemMenu->cthis, TRIGGER_COMPONENT), multiple, 1);
				while (1) {}
			}
			else {
				((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 10, 10, 4, 15);
				((TriggerComponent*)SystemMenu->GetComponent(SystemMenu->cthis, TRIGGER_COMPONENT))->SetValue((TriggerComponent*)SystemMenu->GetComponent(SystemMenu->cthis, TRIGGER_COMPONENT), win_or_lose, 1);
				while (1) {}
			}
		}
	}
}

HeadOrTail0(int* guess, int* menu, GameObject* SystemMenu, GameObject* SystemCursor, GameObject* Player) {

	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 0, 0, 0, 15);
	
	((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input = ((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->GetInput((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT));
	if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == RIGHT_ARROW && ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow < 1) {
		((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow++;
		gotoyx_clear();
	}
	else if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == LEFT_ARROW && ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow > 0) {
		((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow--;
		gotoyx_clear();
	}
	else if (((InputComponent*)Player->GetComponent(Player->cthis, INPUT_COMPONENT))->input == ENTER) {
		*menu += 1;
		*guess = ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow;
		gotoyx_clear();
	}
	((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemCursor->GetComponent(SystemCursor->cthis, RENDER_COMPONENT), ((CursorComponent*)SystemCursor->GetComponent(SystemCursor->cthis, CURSOR_COMPONENT))->arrow * 3, 20, 0, 8);

	return 0;
}

HeadOrTail1(int* menu, GameObject* SystemMenu, GameObject* Coin) {

	((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT))->Render((RenderComponent*)SystemMenu->GetComponent(SystemMenu->cthis, RENDER_COMPONENT), 0, 0, 1, 15);
	((AnimationComponent*)Coin->GetComponent(Coin->cthis, ANIMATION_COMPONENT))->Animation((AnimationComponent*)Coin->GetComponent(Coin->cthis, ANIMATION_COMPONENT), 1000, "HeadOrTailCoinAnimation.txt", 0, 10, 1, 5, 15);
	if (((AnimationComponent*)Coin->GetComponent(Coin->cthis, ANIMATION_COMPONENT))->animation_switch == 2)
		*menu += 1;

	return 0;
}