#pragma once

#include <memory>

#include "HandleManager.h"
#include "System.h"

namespace AbsolutEngine {

	class HandleManager;

	class Handle {
		friend class HandleManager;
		friend class GameObject;

	public:
		Handle(const Handle &handle);
		Handle(uint16_t index, uint16_t version, HandleManager* handleManager);
		~Handle();

	private:
		uint16_t m_index;
		uint16_t m_version;
		HandleManager* m_handleManager;
	};

}