#pragma once

#include <unordered_map>
#include <typeinfo>
#include <typeindex>

#include "Component.h"
#include "Handle.h"

namespace AbsolutEngine {

	class GameObject {

	public:
		GameObject();
		// std::unique_ptr<Handle> addComponent(); maybe later give a chance to add components from go instead of system...
		bool hasComponent(std::type_index systemType);
		std::unique_ptr<Handle> getComponent(std::type_index systemType);

	protected:
		virtual ~GameObject();

	private:
		std::unordered_map<std::type_index, std::unique_ptr<Handle> > m_componentHandles;

		void addComponent(std::type_index systemType, std::unique_ptr<Handle> handle);
	};

}