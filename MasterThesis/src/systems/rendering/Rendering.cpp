#include "Rendering.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace AbsolutEngine {

	std::shared_ptr<Component> System::CreateComponent() {
		std::make_shared<Component>(new Renderer(this));
	}

	void System::Update(float deltaTime) {
		// TODO: Add rendering code...
	}

}
