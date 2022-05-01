#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_

//#define DATAFILE "accounts.csv"
namespace sdds {
	struct Report
	{
		int account;
		double balance;
	};
	void sort();
	bool load(Report& rep);
	bool load(const char* file);
	void display(const Report& rep);
	void display();
	void deallocateMemory();
}
#endif // SDDS_ACCOUNT_H_