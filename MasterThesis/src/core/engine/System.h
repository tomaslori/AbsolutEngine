#pragma once

#include <memory>

#include "HandleManager.h"
#include "GameObject.h"
#include "Component.h"

namespace AbsolutEngine {

	class HandleManager; // Forward declaration
	class GameObject; // Forward declaration

	template <class T> class System {

	public:
		System(const System &system) = delete;
		std::unique_ptr<Handle> createComponent(GameObject* go);

	protected:
		virtual void Update(float deltaTime, T *component) =0;
		virtual void FixedUpdate(float deltaTime, T *component) =0;

	private:
		std::unique_ptr<HandleManager> m_handleManager;
		std::vector<T> m_components;

		System();
		void Update(float deltaTime);
		void FixedUpdate(float deltaTime);
	};

}