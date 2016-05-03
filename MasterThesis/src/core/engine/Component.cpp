#include "Component.h"

namespace AbsolutEngine {

	Component::Component() : m_handle(nullptr), m_enabled(false) { }

	std::unique_ptr<Handle> Component::getHandle() {
		return std::unique_ptr<Handle>(new Handle(*m_handle));
	}
	
	void Component::init(std::unique_ptr<Handle> handle) {
		m_enabled = false;
		m_handle = std::unique_ptr<Handle>(new Handle(*handle));
	}

}
