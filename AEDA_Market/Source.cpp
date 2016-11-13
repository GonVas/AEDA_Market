#include <iostream>
#include "Market.h"

using namespace std;

int main()
{
	Market test;
	cout << "Test market id: " << test.getID() << endl;
	Client new1("ola", 12, 12);
	Client new2("dsa", 10, 34);
	Client new3("fff", 13, 2);
	Client new4("rrrr", 11, 224);
	test.addClient(&new1);
	test.addClient(&new2);
	test.addClient(&new3);
	test.addClient(&new4);
	test.showClients();
	cout << "Exists? : " << ((test.findCli(10, 1) == -1)?"False": "True") << endl;
	try
	{
		test.removeClient(15, 1);
	}
	catch (ClientError err) { cout << "error in removing: " << err.what() << endl; }
	test.showClients();

	Industry oil("Oil", 20.0);

	Share new_share(&oil, 10, 12);
	cout << new_share;
	
	return 0;
}