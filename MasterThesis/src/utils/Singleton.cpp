#include "Singleton.h"

#include <cstdlib>

namespace AbsolutEngine {

	template<typename T> T& Singleton<T>::Instance() {
		if (Singleton::m_instance == nullptr)
			Singleton::m_instance = return new T();
		return *(Singleton::m_instance);
	}

	template <typename T> Singleton<T>::Singleton()	{
		assert(Singleton::m_instance == nullptr);
		Singleton::m_instance = static_cast<T*>(this);
	}

	template<typename T> Singleton<T>::~Singleton() {
		if (Singleton::m_instance != nullptr)
			delete Singleton::m_instance;
		Singleton::m_instance = nullptr;
	}

}
