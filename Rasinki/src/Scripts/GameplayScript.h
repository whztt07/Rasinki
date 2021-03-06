
#ifndef __GAMEPLAY_SCRIPT_H__
#define __GAMEPLAY_SCRIPT_H__

#include "../Components/Script.h"

/* 
	Code to control Gameplay behavior.
*/
class GameplayScript : public Script {

	public:
		GameplayScript(GameObject *attachedGameObject);
		~GameplayScript();


		void Start(void);
		void Update(void);

		static bool IsGameOver();
		static float GetGameOverTime();

	private:

		static float gameOverTime;
		static bool gameOver;

};


#endif