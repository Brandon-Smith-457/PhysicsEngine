#include "Engine.h"

#include <unordered_map>

#include "World.h"
#include "RigidBody.h"

namespace PhysicsEngine {

	static World* s_World = nullptr;

	void Engine::init(float gravity, float airDrag, float friction, float elasticity) {
		s_World = new World(gravity, airDrag, friction, elasticity);
	}

	void Engine::init() {
		Engine::init(9.81f, 0.0f, 0.0f, 1.0f);
	}

	uint32_t Engine::createRigidBodyQuad(float xPos, float yPos, bool dynamic, float rot, bool canRot, float width, float height, float mass, float xVelocity, float yVelocity) {
		return s_World->addRigidBody(xPos, yPos, dynamic, rot, canRot, width, height, mass, xVelocity, yVelocity);
	}

	uint32_t Engine::createRigidBodyQuad(float xPos, float yPos, bool dynamic, float rot, bool canRot, float width, float height, float mass, float xVelocity, float yVelocity, float gravity, float airDrag, float friction, float elasticity) {
		return s_World->addRigidBody(xPos, yPos, dynamic, rot, canRot, width, height, mass, xVelocity, yVelocity, gravity, airDrag, friction, elasticity);
	}

	void Engine::destroyRigidBody(uint32_t id) {
		s_World->removeRigidBody(id);
	}

	std::vector<float> Engine::getRigidBodyPos(uint32_t id) {
		return s_World->getRigidBodyPos(id);
	}

	float Engine::getRigidBodyRot(uint32_t id) {
		return s_World->getRigidBodyRot(id);
	}

	void Engine::runSimulation(float deltaTime) {
		std::unordered_map<uint32_t, RigidBody*> bodies = s_World->getBodies();
		for (std::pair<uint32_t, RigidBody*> pair : bodies) {
			RigidBody* body = pair.second;
			// Scaling down by a factor of 10 because the height of the screen is currently being represented by around 9 units (ie 9.81 units per second means the gravity will be a bit high)
			body->addForce(0.0f, -s_World->getGravity()*0.1f, deltaTime);

			body->simulate(deltaTime);
		}
	}

	// Getters / Setters

	void Engine::setGravity(float gravity) {
		s_World->setGravity(gravity);
	}

	void Engine::setAirDrag(float airDrag) {
		s_World->setAirDrag(airDrag);
	}

	void Engine::setFriction(float friction) {
		s_World->setFriction(friction);
	}

	void Engine::setElasticity(float elasticity) {
		s_World->setElasticity(elasticity);
	}

	float Engine::getGravity() {
		return s_World->getGravity();
	}

	float Engine::getAirDrag() {
		return s_World->getAirDrag();
	}

	float Engine::getFriction() {
		return s_World->getFriction();
	}

	float Engine::getElasticity() {
		return s_World->getElasticity();
	}

}