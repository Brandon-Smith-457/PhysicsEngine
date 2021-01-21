#pragma once

#include <stdint.h>
#include <unordered_map>

#include "RigidBody.h"


namespace PhysicsEngine {

	class World {
	public:
		World(float gravity, float airDrag, float friction, float elasticity);
		~World() = default;

		uint32_t addRigidBody(float xPos, float yPos, bool dynamic, float rot, bool canRot, float width, float height, float mass, float xVelocity, float yVelocity);
		uint32_t addRigidBody(float xPos, float yPos, bool dynamic, float rot, bool canRot, float width, float height, float mass, float xVelocity, float yVelocity, float gravity, float airDrag, float friction, float elasticity);

		void removeRigidBody(uint32_t id);

		std::vector<float> getRigidBodyPos(uint32_t id);
		float getRigidBodyRot(uint32_t id);

		std::unordered_map<uint32_t, RigidBody*> getBodies();

		inline void setGravity(float gravity) { m_Gravity = gravity; }
		inline void setAirDrag(float airDrag) { m_AirDrag = airDrag; }
		inline void setFriction(float friction) { m_Friction = friction; }
		inline void setElasticity(float elasticity) { m_Elasticity = elasticity; }
		inline float getGravity() { return m_Gravity; }
		inline float getAirDrag() { return m_AirDrag; }
		inline float getFriction() { return m_Friction; }
		inline float getElasticity() { return m_Elasticity; }
	private:
		uint32_t getID();
	private:
		float m_Gravity, m_AirDrag, m_Friction, m_Elasticity;
		std::unordered_map<uint32_t, RigidBody*> m_Bodies;
		std::vector<uint32_t> m_IDs;
	};

}