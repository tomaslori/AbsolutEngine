#pragma once

#include <memory>

#include "../../core/engine/System.h"
#include "../../core/engine/Component.h"

namespace AbsolutEngine {

	class Rendering : System {

	public:
		virtual std::shared_ptr<Component> CreateComponent();

	private:
		virtual void Update(float deltaTime);
		virtual void FixedUpdate(float deltaTime);
	};

}