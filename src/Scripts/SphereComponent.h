#ifndef __Sphere_SCRIPT_H__
#define __Sphere_SCRIPT_H__

#include "../Components/Script.h"

/* 
	Blocks that add points to player when hit.
*/
class SphereComponent : public Script {

	public:
		SphereComponent(GameObject *attachedGameObject);

		void Update();
		void OnCollision(Ogre::Vector3 point, GameObject* collidedWith);
	private:
		float speed;

};
#endif