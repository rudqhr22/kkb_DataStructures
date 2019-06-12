#include <iostream>
#include <thread>
#include <mutex>

#include <deque>
#include <list>
#include <vector>
//static int i = 0;

int main()
{
	//int i = 0;
	//std::mutex m_mtex;
	//std::thread a([&] 
	//{
	//	for (int j = 0; j < 10; ++j)
	//	{
	//		m_mtex.lock();
	//		std::cout << i++ << std::endl;
	//		m_mtex.unlock();
	//	}
	//});
	//std::thread b([&] {
	//	for (int j = 10; j < 20; ++j)
	//	{
	//		m_mtex.lock();
	//		std::cout << i++ << std::endl;
	//		m_mtex.unlock();
	//	}
	//});
	//a.join();
	//b.join();





	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);  //메모리 누수 발생시 오류출력


	std::list<int> m_mylist;
	std::list<int>::iterator iter;

	iter = m_mylist.begin();
	//iter2 = iter++;
	//iter3 = iter++;
	//iter4 = iter++;

	
	m_mylist.push_back(1);
	m_mylist.push_back(2);
	m_mylist.push_back(3);
	//m_mylist.push_front(4);
	
	
	auto asdf = m_mylist.at(1);
	auto asdf2 = m_mylist.at(2);

	//m_mylist.insert(iter,7);
	m_mylist.clear();

	//m_mylist.sort(std::less<int>());
	//m_mylist.sort(std::greater<int>());

	return 0;
}