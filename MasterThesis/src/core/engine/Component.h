#pragma once

#include "Handle.h"
#include "HandleManager.h"
#include "System.h"

namespace AbsolutEngine {

	template <class T> class System; // Forward declaration
	class Handle; // Forward declaration

	class Component : public std::enable_shared_from_this<Component> {
		template <class T> friend class System;

	public:
		Component(const Component& component) = delete;
		std::unique_ptr<Handle> getHandle();

	protected:
		virtual void init(std::unique_ptr<Handle> handle);

	private:
		std::unique_ptr<Handle> m_handle;
		bool m_enabled;
		
		Component();
	};

}