#pragma once

#include <stdint.h>
#include <vector>

namespace PhysicsEngine {

	class Engine {
	public:
		static void init(float gravity, float airDrag, float friction, float elasticity);
		static void init();

		// TODO: Create a properties struct to avoid having so many separate parameters to pass through (and will also reduce the number of required functions)
		static uint32_t createRigidBodyQuad(float xPos, float yPos, bool dynamic, float rot, bool canRot, float width, float height, float mass, float xVelocity, float yVelocity);
		static uint32_t createRigidBodyQuad(float xPos, float yPos, bool dynamic, float rot, bool canRot, float width, float height, float mass, float xVelocity, float yVelocity, float gravity, float airDrag, float friction, float elasticity);

		static void destroyRigidBody(uint32_t id);

		static std::vector<float> getRigidBodyPos(uint32_t id);
		static float getRigidBodyRot(uint32_t id);

		static void runSimulation(float deltaTime);
		
		static void setGravity(float gravity);
		static void setAirDrag(float airDrag);
		static void setFriction(float friction);
		static void setElasticity(float elasticity);
		static float getGravity();
		static float getAirDrag();
		static float getFriction();
		static float getElasticity();
	};

}