#pragma once
#include "../css-math/matrix.h"
#include "../css-math/vec.h"
#include "../css-math/color.h"


class client_mode
{
public:
	//virtual			~client_mode() {}

	//// Called before the HUD is initialized.
	//virtual void	InitViewport() = 0;

	//// One time init when .dll is first loaded.
	//virtual void	Init() = 0;

	//// Called when vgui is shutting down.
	//virtual void	VGui_Shutdown() = 0;

	//// One time call when dll is shutting down
	//virtual void	Shutdown() = 0;

	//// Called when switching from one IClientMode to another.
	//// This can re-layout the view and such.
	//// Note that Enable and Disable are called when the DLL initializes and shuts down.
	//virtual void	Enable() = 0;

	//// Called when it's about to go into another client mode.
	//virtual void	Disable() = 0;

	//// Called when initializing or when the view changes.
	//// This should move the viewport into the correct position.
	//virtual void	Layout() = 0;

	//// Gets at the viewport, if there is one...
	//virtual vgui::Panel *GetViewport() = 0;

	//// Gets at the viewports vgui panel animation controller, if there is one...
	//virtual vgui::AnimationController *GetViewportAnimationController() = 0;

	//// called every time shared client dll/engine data gets changed,
	//// and gives the cdll a chance to modify the data.
	//virtual void	ProcessInput(bool bActive) = 0;

	//// The mode can choose to draw/not draw entities.
	//virtual bool	ShouldDrawDetailObjects() = 0;
	//virtual bool	ShouldDrawEntity(void *pEnt) = 0;
	//virtual bool	ShouldDrawLocalPlayer(void *pPlayer) = 0;
	//virtual bool	ShouldDrawParticles() = 0;

	//// The mode can choose to not draw fog
	//virtual bool	ShouldDrawFog(void) = 0;

	//virtual void	OverrideView(CViewSetup *pSetup) = 0;
	//virtual int		KeyInput(int down, ButtonCode_t keynum, const char *pszCurrentBinding) = 0;
	//virtual void	StartMessageMode(int iMessageModeType) = 0;
	//virtual vgui::Panel *GetMessagePanel() = 0;
	//virtual void	OverrideMouseInput(float *x, float *y) = 0;
	//virtual bool	CreateMove(float flInputSampleTime, CUserCmd *cmd) = 0;

	//virtual void	LevelInit(const char *newmap) = 0;
	//virtual void	LevelShutdown(void) = 0;
};