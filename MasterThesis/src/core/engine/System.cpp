#include "System.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace AbsolutEngine {

	template <class T> System<T>::System() : m_handleManager(std::make_unique<HandleManager>()), m_components(UINT16_MAX) {
		static_assert(std::is_base_of<Component, T>::value, "T not derived from Component!");
	}

	template <class T> void System<T>::Update(float deltaTime) {
		for (int i=0; i<m_components.size() ;i++)
			if ((*m_handleManager).m_handleEntries[i].aliveHandlersCount > 0)
				Update(deltaTime, &(m_components[i]));
	}

	template <class T> void System<T>::FixedUpdate(float deltaTime) {
		for (int i = 0; i<m_components.size(); i++)
			if ((*m_handleManager).m_handleEntries[i].aliveHandlersCount > 0)
				FixedUpdate(deltaTime, &(m_components[i]));
	}

	template <class T> std::unique_ptr<Handle> System<T>::createComponent(GameObject* go) {
		if (go->hasComponent(std::type_index(typeid(this)))) {
			std::cout << "ERROR::System::createComponent::Another component of same type was already present on the GameObject " << std::endl;
			return nullptr;
		}

		std::unique_ptr<Handle> handle = m_handleManager->alloc();
		if (handle) {
			static_cast<Component &>((m_components[handle->m_index])).init(handle);
			go->addComponent(handle);
		}
		return handle;
	}

}
