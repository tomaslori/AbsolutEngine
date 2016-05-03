#pragma once

#include <vector>
#include <memory>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Handle.h"

namespace AbsolutEngine {

	class Handle;  // Forward declaration

	class HandleManager {
		friend class Handle;

		struct HandleEntry {
			uint16_t aliveHandlersCount;
			uint16_t version;
			HandleEntry() : aliveHandlersCount(0), version(0) {}
		};

	public:
		HandleManager();
		std::unique_ptr<Handle> alloc();
		void dealloc(std::unique_ptr<Handle> handle);
		bool isValid(std::unique_ptr<Handle> handle);

	private:
		std::vector<HandleEntry> m_handleEntries;
		uint16_t m_last;

		void subscribe(Handle *handle);
		void unsubscribe(Handle *handle);

	};

}