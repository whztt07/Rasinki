
#ifndef __PHYSICS_COMPONENT_H__
#define __PHYSICS_COMPONENT_H__

#include <btBulletDynamicsCommon.h>
#include "GameObject.h"
#include "Transform.h"

/* Forward Declarations */
class GameObject;
class Transform;
/* 
	A Component encapsulates some functionality of a GameObject, such as the
	rendering, physics, or sound.
*/
class Physics {
	
	public:
		Physics(){}
		Physics(GameObject& attachedGameObject, float mass = 1, btCollisionShape* collider = new btSphereShape(1));
		~Physics();

		void Start();
		void FixedUpdate();

		void setLinearVelocity(const Ogre::Vector3& veloc) { mRigidBody->setLinearVelocity(btVector3(veloc.x, veloc.y, veloc.z)); }
		const Ogre::Vector3 getLinearVelocity() const { 
			btVector3 veloc = mRigidBody->getLinearVelocity();
			return Ogre::Vector3(veloc.x(), veloc.y(), veloc.z());
		}
		void setLinearFactor(const Ogre::Vector3& factor) { mRigidBody->setLinearFactor(btVector3(factor.x, factor.y, factor.z)); }

		void setAngularVelocity(const btVector3& veloc) { mRigidBody->setAngularVelocity(veloc); }
		const btVector3& getAngularVelocity() const { return mRigidBody->getAngularVelocity(); }

		void setScale(const Ogre::Vector3& scale) { mRigidBody->getCollisionShape()->setLocalScaling(btVector3(scale.x, scale.y, scale.z)); }
		void setWorldPosition(const Ogre::Vector3& pos) { assert (mRigidBody != NULL); mRigidBody->getWorldTransform().setOrigin(btVector3(pos.x, pos.y, pos.z)); }
	protected:
		btRigidBody* mRigidBody;
		Transform* mTransform;
		GameObject* gameObject;
};
#endif