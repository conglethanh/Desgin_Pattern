#include <iostream>
using namespace std;

class Singleton
{
private:
	static    Singleton*  m_Instance;
	Singleton();
	~Singleton();
public:
	static void init();
	static void release();
	static Singleton* getInstance();

	void method();
};

Singleton*	Singleton::m_Instance = NULL;

Singleton::Singleton()
{
}

Singleton::~Singleton()
{
}

Singleton* Singleton::getInstance()
{
	if (m_Instance == NULL)
		Singleton::init();
	return m_Instance;
}

void Singleton::init()
{
	if (m_Instance == NULL)
		m_Instance = new Singleton();
}

void Singleton::release()
{
	if (m_Instance)
	{
		delete m_Instance;
		m_Instance = NULL;
	}
}

void	Singleton::method()
{
	cout << "This is a singleton method." << endl;
}

void main()
{
	Singleton::getInstance()->method();
}