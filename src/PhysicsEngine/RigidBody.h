#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace PhysicsEngine {

	class RigidBody {
	public:
		RigidBody() = default;
		RigidBody(float xPos, float yPos, bool dynamic, float rot, bool canRot, float width, float height, float mass, float xVelocity, float yVelocity);
		RigidBody(float xPos, float yPos, bool dynamic, float rot, bool canRot, float width, float height, float mass, float xVelocity, float yVelocity, float gravity, float airDrag, float friction, float elasticity);

		void addForce(float xForce, float yForce, float deltaTime);

		void simulate(float deltaTime);

		float getXPos();
		float getYPos();
		float getRot();
		void setXPos(float xPos);
		void setYPos(float yPos);
		void setRot(float rot);

		float getXVelocity();
		float getYVelocity();
		void setXVelocity(float xVelocity);
		void setYVelocity(float yVelocity);

		float getMass();
		void setMass(float mass);
	private:
		glm::vec2 m_Transform;
		float m_XPos;
		float m_YPos;
		float m_Rot;
		float m_Width;
		float m_Height;
		
		float m_Mass;
		float m_XVelocity;
		float m_YVelocity;

		bool m_Dynamic;
		bool m_CanRot;
	};

}