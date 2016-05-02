#pragma once

namespace AbsolutEngine {

	template <typename T> class Singleton {
	public:
		static T& Instance();

	protected:
		virtual ~Singleton();
		Singleton();

	private:
		static T* m_instance;
	};

	template<typename T> T* Singleton<T>::m_instance = nullptr;
}