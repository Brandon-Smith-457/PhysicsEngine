#include "World.h"

namespace PhysicsEngine {
	   
	World::World(float gravity, float airDrag, float friction, float elasticity)
		: m_Gravity(gravity), m_AirDrag(airDrag), m_Friction(friction), m_Elasticity(elasticity) {

	}

	uint32_t World::addRigidBody(float xPos, float yPos, bool dynamic, float rot, bool canRot, float width, float height, float mass, float xVelocity, float yVelocity) {
		uint32_t id = getID();
		m_Bodies[id] = new RigidBody(xPos, yPos, dynamic, rot, canRot, width, height, mass, xVelocity, yVelocity);
		return id;
	}

	uint32_t World::addRigidBody(float xPos, float yPos, bool dynamic, float rot, bool canRot, float width, float height, float mass, float xVelocity, float yVelocity, float gravity, float airDrag, float friction, float elasticity) {
		uint32_t id = getID();
		m_Bodies[id] = new RigidBody(xPos, yPos, dynamic, rot, canRot, width, height, mass, xVelocity, yVelocity, gravity, airDrag, friction, elasticity);
		return id;
	}

	void World::removeRigidBody(uint32_t id) {
		m_Bodies.erase(id);
		m_IDs.erase(m_IDs.begin() + id);
	}

	std::vector<float> World::getRigidBodyPos(uint32_t id) {
		std::vector<float> pos;
		pos.push_back(m_Bodies[id]->getXPos());
		pos.push_back(m_Bodies[id]->getYPos());
		return pos;
	}

	float World::getRigidBodyRot(uint32_t id) {
		return m_Bodies[id]->getRot();
	}

	std::unordered_map<uint32_t, RigidBody*> World::getBodies() {
		return m_Bodies;
	}

	// TODO: Look into a better data-structure / method to make getting these ids a little less costly
	uint32_t World::getID()
	{
		if (m_IDs.empty()) {
			m_IDs.push_back(0);
			return 0;
		}
		else {
			uint32_t i = 0;
			for (auto id : m_IDs) {
				if (id > i) {
					m_IDs.insert(m_IDs.begin() + i, i);
					return i;
				}
				i++;
			}
			m_IDs.push_back(i);
			return i;
		}
	}

}