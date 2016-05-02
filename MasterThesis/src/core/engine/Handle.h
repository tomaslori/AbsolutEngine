#pragma once

//#include <memory>
//#include "../../utils/sharedptr.h" // allows for shared_from_this() from constructor and destructor

#include "HandleManager.h"
#include "System.h"

namespace AbsolutEngine {

	class HandleManager;

	class Handle /*: public std::enable_shared_from_this<Handle> */ {
		friend class HandleManager;

	public:
		Handle(const Handle &handle);
		~Handle();

	private:
		Handle(uint16_t index, uint16_t version, HandleManager* handleManager);
		uint16_t m_index;
		uint16_t m_version;
		HandleManager* m_handleManager;
	};

}