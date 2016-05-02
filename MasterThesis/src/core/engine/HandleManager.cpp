#include "HandleManager.h"

namespace AbsolutEngine {

	HandleManager::HandleManager() : m_handleEntries(UINT16_MAX), m_last(0) { }

	std::unique_ptr<Handle> HandleManager::alloc() {
		HandleEntry handleEntry, original = m_handleEntries[m_last];
		do {
			handleEntry = m_handleEntries[++m_last];
			if (&original == &handleEntry) { // full loop...
				std::cout << "ERROR::HandleManager::alloc::The handle couldn't be allocated (probably no handles left)." << std::endl;
				return nullptr; 
			}
		} while (handleEntry.aliveHandlersCount > 0);

		handleEntry.aliveHandlersCount = 0;
		handleEntry.version++;
		return std::make_unique<Handle>(m_last, handleEntry.version, this);
	}

	void HandleManager::dealloc(Handle *handle) {
		HandleEntry handleEntry = m_handleEntries[handle->m_index];
		if (handle->m_version == handleEntry.version) {
			handleEntry.aliveHandlersCount = 0;
			handleEntry.version++;
			m_handleEntries[handle->m_index] = handleEntry;
		}
	}

	bool HandleManager::isValid(Handle *handle) {
		HandleEntry handleEntry = m_handleEntries[handle->m_index];
		return (handle->m_version == handleEntry.version && handleEntry.aliveHandlersCount > 0);
	}

	void HandleManager::subscribe(Handle *handle) {
		HandleEntry handleEntry = m_handleEntries[handle->m_index];
		if (handle->m_version == handleEntry.version)
			handleEntry.aliveHandlersCount++;
			m_handleEntries[handle->m_index] = handleEntry;
	}

	void HandleManager::unsubscribe(Handle *handle) {
		HandleEntry handleEntry = m_handleEntries[handle->m_index];
		if (handle->m_version == handleEntry.version && handleEntry.aliveHandlersCount > 0) {
			handleEntry.aliveHandlersCount--;
			m_handleEntries[handle->m_index] = handleEntry;
		}
	}
	
}

