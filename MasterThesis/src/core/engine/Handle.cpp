#include "Handle.h"

namespace AbsolutEngine {

	Handle::Handle(uint16_t index, uint16_t version, HandleManager* handleManager) : m_index(index), m_version(version), m_handleManager(handleManager) {
		m_handleManager->subscribe(this);
	}

	Handle::Handle(const Handle &handle) : Handle(handle.m_index, handle.m_version, handle.m_handleManager) { }

	Handle::~Handle() {
		m_handleManager->unsubscribe(this);
	}

}
