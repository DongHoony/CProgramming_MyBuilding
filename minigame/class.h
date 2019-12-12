#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <malloc.h>
#include <stdlib.h>
#include "minigamegotoyx.h"

/* ������Ʈ ���� ��� */
#define COMPONENT_NUMBERS 7
#define RENDER_COMPONENT 0
#define INPUT_COMPONENT 1
#define ROLL_COMPONENT 2
#define TRIGGER_COMPONENT 3
#define ANIMATION_COMPONENT 4
#define TIME_COMPONENT 5
#define CURSOR_COMPONENT 6

/* ��ü ���� ��� */
#define PLAYER_GAMEOBJECT 100
#define COIN_GAMEOBJECT 101
#define SYSTEMMENU_GAMEOBJECT 102
#define SYSTEMCURSOR_GAMEOBJECT 103

/* Ű ���� ��� */
#define RIGHT_ARROW 77
#define LEFT_ARROW 75
#define ENTER 13

/* ��ü */
typedef struct _GameObject{

	struct _GameObject* cthis;

	struct _ComponentBase** Component_Table;	//index��ȣ�� component�� ID���� �� NULL������ ����
	int GameObjectID;	//�� �״�� GameObject�� ID

	int (*InsertComponent)(struct _GameObject *cthis, int ComponentID, struct _ComponentBase* pComponentBase);	//Component_Table[ComponentID]�� ComponentBase*���� ����
	int (*DeleteComponent)(struct _GameObject *cthis, int ComponentID);	//Component_Table[ComponentID]�� ���� NULL�� �ʱ�ȭ
	struct _ComponentBase* (*GetComponent)(struct _GameObject *cthis, int ComponentID);	//���ϴ� ID�� Component�� ComponentBase*�� ����ȯ�� �ּҰ� ��ȯ -> ���ٿ� �̿��� ��?

}GameObject;
typedef struct _ComponentBase{

	struct _ComponentBase *cthis;

	int ComponentID;	//Component�� ID - 0���� ����
	struct _GameObject *pOwner;	//�� Component�� ������ GameObject�� �ּڰ� - �ٸ� Component�� �����ϱ� ���� ��� ex)�ִϸ��̼� Component, Ʈ���� Component ��

	int (*SetpOwner)(struct _ComponentBase *cthis, struct _GameObject *pNewOwner);	//�Է¹��� GameObject�� �ּڰ��� pOwner������ �Ҵ�
	struct _GameObject* (*GetpOwner)(struct _ComponentBase *cthis);	//pOwner�� ��ȯ

}ComponentBase;
typedef struct _RenderComponent{	//ID - 0

	struct _RenderComponent* cthis;

	struct _ComponentBase* pComponentBase;

	char*** str;
	int input_height;
	int input_width;
	int calc_height;
	int fps; //calc_height / input_height

	int (*SetInputHeight)(struct _RenderComponent* cthis, int new_input_height);	//input_height = new_input_height;
	int (*SetInputWidth)(struct _RenderComponent* cthis, int new_input_width); 
	int (*GetData)(struct _RenderComponent* cthis, const char* FileName);	//���� ��������� ���� ���� ���� ��(calc_height) str[0]���� str[���� ���� - 1]���� ���ڿ� �ܾ���� - ��������� �� fgets�� �̿��ϸ� �� �� char* str[]�� ���� ���� �Է¹ް� render�Լ��� modeldata.str�� ����
	int (*Render)(struct _RenderComponent* cthis, int x, int y, int select_fps, int color);	//�� �����͸� �����ͼ� ���� �� ScreenWrite �Ѵ�. y ��ǥ�� height��ŭ �ϳ��� �÷����鼭

}RenderComponent;
typedef struct _InputComponent{	//ID - 1

	struct _InputComponent *cthis;

	struct _ComponentBase *pComponentBase;

	int input;

	int (*GetInput)(struct _InputComponent *cthis);	//if(_kbhit())���� �Է°� �޾ƿ���

}InputComponent;
typedef struct _RollComponent{	//ID - 2

	struct _RollComponent *cthis;

	struct _ComponentBase *pComponentBase;

	int random_number;

	int (*GetRandom)(struct _RollComponent *cthis, int n);	//rand()%n ��ȯ

}RollComponent;
typedef struct _TriggerComponent{	//ID - 3

	struct _TriggerComponent *cthis;

	struct _ComponentBase *pComponentBase;

	int (*SetValue)(struct _TriggerComponent *cthis, int* target, int adjustment);	//target������ adjust������ �ʱ�ȭ
	int (*AddValue)(struct _TriggerComponent *cthis, int* target, int adjustment);	//target������ adjust�� ��ŭ �� - ������ ����

}TriggerComponent;
typedef struct _AnimationComponent{	//ID - 4

	struct _AnimationComponent *cthis;

	struct _ComponentBase* pComponentBase;
	struct _RenderComponent *pRenderComponent;
	struct _TimeComponent *pTImeComponent;

	int animation_switch;
	int fps;
	int (*Animation)(struct _AnimationComponent* cthis, int lasting_time, const char* FileName, int x, int y, int new_input_height, int new_input_width, int color);	//�ð��� render�� ������ ����	- lasting_time�� �ϳ��� �̹��� ���� �ð�, full_time�� �� �ִϸ��̼� �ð�

}AnimationComponent;
typedef struct _TimeComponent{	//ID - 5

	struct _TimeComponent *cthis;

	ComponentBase* pComponentBase;

	clock_t PoTime, CurTime;

	int (*SetStdTime)(struct _TimeComponent *cthis);	//PoTime�� GetTick�Լ��� �̿��ؼ� �ð� ����
	int (*GetLapTime)(struct _TimeComponent *cthis);	//CurTimedp GetTick�Լ��� �̿��ؼ� ����ð� ���� �� PoTime���� ���� ���ؼ� ��ȯ

}TimeComponent;
typedef struct _CursorCopmonent {

	struct _CursorComponent* cthis;

	ComponentBase* pComponentBase;
	TriggerComponent* pTriggerComponent;

	int arrow;
	int max, min;

}CursorComponent;

/* ������ */
GameObject* NewGameObject(int NewGameObjectID);
ComponentBase* NewComponentBase(int NewComponentID);
RenderComponent* NewRenderComponent(int NewComponentID);
InputComponent* NewInputComponent(int NewComponentID);
RollComponent* NewRollComponent(int NewComponentID);
TriggerComponent* NewTriggerComponent(int NewComponentID);
AnimationComponent* NewAnimationComponent(int NewComponentID);
TimeComponent* NewTimeComponent(int NewComponentID);
CursorComponent* NewCursorComponent(int NewComponentID);

/* GameObject */
int InsertComponent_(GameObject* cthis, int ComponentID, ComponentBase* pComponentBase);
int DeleteComponent_(GameObject* cthis, int ComponentID);
ComponentBase* GetComponent_(GameObject* cthis, int ComponentID);

/* ComponentBase */
int SetpOwner_(ComponentBase* cthis, GameObject* pNewOwner);
GameObject* GetpOwner_(ComponentBase* cthis);

/* RenderComponent */
int SetInputHeight_(RenderComponent* cthis, int new_input_height);
int SetInputWidth_(RenderComponent* cthis, int new_input_width);
int GetData_(RenderComponent* cthis, const char* FileName);
int Render_(RenderComponent* cthis, int x, int y, int select_fps, int color);

/* InputComponent */
int GetInput_(InputComponent* cthis);

/* RollComponent */
int GetRandom_(RollComponent* cthis, int n);

/* TriggerComponent */
int SetValue_(TriggerComponent* cthis, int* target, int adjustment);
int AddValue_(TriggerComponent* cthis, int* target, int adjustment);

/* AnimationComponent */
int Animation_(AnimationComponent* cthis, int lasting_time, const char* FileName, int x, int y, int new_input_height, int new_input_width, int color);

/* TimeComponent */
int SetStdTime_(TimeComponent* cthis);
int GetLapTime_(TimeComponent* cthis);
