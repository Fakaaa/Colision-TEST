#include "raylib.h"

#include "objects/player.h"
#include "objects/arrows.h"
#include "objects/enemies.h"
#include "background/background.h"
#include "screens/all_the_screens.h"

//static const int SCREENWIDTH = 1600;
//static const int SCREENHEIGHT = 500;

static void Initialize();
static void UnloadAssets();

int main()
{
	Initialize();
	
	Screens::screenControler();

	UnloadAssets();

	return 0;
}

// ----------------------------

static void Initialize()
{
	InitWindow(GetScreenWidth(), GetScreenHeight(), "Into the Deep - Sumer Lab");
	HideCursor();

	ToggleFullscreen();

	SetExitKey(KEY_BACK);
	SetTargetFPS(60);

	Background::LoadBackground();

	Player::Initialize();
	Arrows::Initialize();
	Enemies::Initialize();
	Screens::Initialize();
}

static void UnloadAssets()
{
	Background::Unload();
	Player::Unload();
	Enemies::Unload();
	CloseWindow();
}