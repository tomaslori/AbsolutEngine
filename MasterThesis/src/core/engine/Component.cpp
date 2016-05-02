#include "Component.h"

namespace AbsolutEngine {

	Component::Component() : m_handle(std::make_unique<Handle>()), m_enabled(false) { }

	std::unique_ptr<Handle> Component::getHandle() {
		return std::make_unique<Handle>(m_handle);
	}
	
	void Component::init(std::unique_ptr<Handle> handle) {
		m_enabled = false;
		m_handle = std::make_unique<Handle>(handle);
	}

}
