
#ifndef __GRID_SCRIPT_H__
#define __GRID_SCRIPT_H__

#include "../Components/Script.h"

/* 
	Grid containing squares w/ towers.
*/
class Grid : public Script {

	public:
		Grid(GameObject *attachedGameObject);

		void Start(void);
		void Update(void);
		void OnCollision(Ogre::Vector3 point, GameObject* collidedWith);

	private:
		int width;
		int depth;
};


#endif