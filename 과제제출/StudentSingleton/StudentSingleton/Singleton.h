#pragma once

template <typename T>
class Singleton
{
private:
	static T* m_pThis;

protected:
	Singleton()
	{
	};
	virtual ~Singleton()
	{
	};
public:
	static T* Getinstance()
	{
		if (m_pThis == NULL)
			m_pThis = new T;
		return m_pThis;
	}

	static T* DeleteInstance()
	{
		if (m_pThis != NULL)
		{
			delete m_pThis;
			m_pThis = NULL;
		}
	}
};

template<typename T> T* Singleton<T>::m_pThis = 0;