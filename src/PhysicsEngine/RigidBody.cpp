#include "RigidBody.h"

namespace PhysicsEngine {

	RigidBody::RigidBody(float xPos, float yPos, bool dynamic, float rot, bool canRot, float width, float height, float mass, float xVelocity, float yVelocity)
		: m_XPos(xPos), m_YPos(yPos), m_Dynamic(dynamic), m_Rot(rot), m_CanRot(canRot), m_Width(width), m_Height(height), m_Mass(mass), m_XVelocity(xVelocity), m_YVelocity(yVelocity) {
		
	}

	RigidBody::RigidBody(float xPos, float yPos, bool dynamic, float rot, bool canRot, float width, float height, float mass, float xVelocity, float yVelocity, float gravity, float airDrag, float friction, float elasticity)
		: m_XPos(xPos), m_YPos(yPos), m_Dynamic(dynamic), m_Rot(rot), m_CanRot(canRot), m_Width(width), m_Height(height), m_Mass(mass), m_XVelocity(xVelocity), m_YVelocity(yVelocity) {

	}

	void RigidBody::addForce(float xForce, float yForce, float deltaTime) {
		m_XVelocity += xForce / m_Mass * deltaTime;
		m_YVelocity += yForce / m_Mass * deltaTime;
	}

	void RigidBody::simulate(float deltaTime) {
		m_XPos += m_XVelocity * deltaTime;
		m_YPos += m_YVelocity * deltaTime;
	}

	// Getters / Setters

	float RigidBody::getXPos() {
		return m_XPos;
	}

	float RigidBody::getYPos() {
		return m_YPos;
	}

	float RigidBody::getRot() {
		return m_Rot;
	}

	void RigidBody::setXPos(float xPos) {
		m_XPos = xPos;
	}

	void RigidBody::setYPos(float yPos) {
		m_YPos = yPos;
	}

	void RigidBody::setRot(float rot) {
		m_Rot = rot;
	}

	float RigidBody::getXVelocity() {
		return m_XVelocity;
	}

	float RigidBody::getYVelocity() {
		return m_YVelocity;
	}

	void RigidBody::setXVelocity(float xVelocity) {
		m_XVelocity = xVelocity;
	}

	void RigidBody::setYVelocity(float yVelocity) {
		m_YVelocity = yVelocity;
	}

	float RigidBody::getMass() {
		return m_Mass;
	}

	void RigidBody::setMass(float mass) {
		m_Mass = mass;
	}

}