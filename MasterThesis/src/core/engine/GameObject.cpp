#include "GameObject.h"

namespace AbsolutEngine {

	GameObject::GameObject() : m_componentHandles() {
		// TODO: Construct GO and add transform!
	}

	GameObject::~GameObject() {
		// TODO: destroy all components!
	}

	void GameObject::addComponent(std::type_index systemType, std::unique_ptr<Handle> handle) {
		m_componentHandles.insert({systemType, handle});
	}

	bool GameObject::hasComponent(std::type_index systemType) {
		return m_componentHandles.count(systemType) > 0;
	}

	std::unique_ptr<Handle> GameObject::getComponent(std::type_index systemType) {
		auto it = m_componentHandles.find(systemType);
		if (it != m_componentHandles.end())
			return std::make_unique<Handle>(it->second);
		return nullptr;
	}

}
