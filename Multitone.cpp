#include <iostream>

class Multitone 
{
public:
	static Multitone* create_instance()
	{
		m_count ++;
		if (m_count < m_size)
		{
			m_buf[m_count - 1] = new Multitone();
			return m_buf[m_count -1];
		}
		std::cout << "index is" << m_count % m_size << std::endl;
		return m_buf[m_count % m_size];
	}
	static void destroy()
	{
		for(int i = 0; i < m_size; ++i)
		{
			delete m_buf[i];
			m_buf[i] = nullptr;
		}
	}
protected:
	~Multitone(){};

private:
	Multitone(){};
	static const int m_size = 3; 
	static Multitone* m_buf[m_size];
	static int m_count;

};
int Multitone::m_count = 0;
Multitone* Multitone::m_buf[m_size] = {nullptr};
	
int main()
{
	Multitone* pt[6];
	for(int i =0; i < 6; ++i)
	{
		pt[i] = Multitone::create_instance();
	}	

	Multitone::destroy();
	return 0;
}



