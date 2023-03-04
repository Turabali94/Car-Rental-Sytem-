#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Node
{
	string name;
	long long id;
	int rentprice;
	int numbereofdays;
	Node* next;
};
class linkedList
{
private:
	Node* head; //POINTING ADRESS OF 1ST NODE
	Node* tail;
public:
	linkedList() //CONSTRUCTOR
	{
		head = tail = NULL;
	};

	void addItem(int rp, int d, string n, long long i)
	{
		Node* temp = new Node;
		temp->rentprice = rp;
		temp->numbereofdays = d;
		temp->name = n;
		temp->id = i;
		temp->next = 0;
if (head == 0 && tail == 0)
		{
			head = temp;
			tail = temp;
			cout << "Empty" << endl;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
		cout << "Data entered successfully!" << endl;
	}

	void delitem()
	{
		Node *curr=NULL;
		Node*prev=NULL;
		 Node*temp = NULL;
		int tdata = 0;
		if (head == NULL)
		{
			cout << "No records found!" << endl;
			return;
		}
		cout << "Enter the Id Card Number to be deleted " << endl;
		cin >> tdata;
		prev = curr = head;
		while ((curr != NULL) && (curr->id != tdata))
		{
			prev = curr;
			curr = curr->next;
		}
		if (curr == NULL)
		{
			cout << "No Records of the entered Id Card Number found!" << endl;
			return;
		}
		if (curr == head)
		{
			head = head->next;
			cout << "Records related to Id Card Number " << tdata << " deleted from the list" << endl;
		}
		else
		{
			prev->next = curr->next;
			if (curr->next == NULL)
			{
				temp = prev;
			}
			 
		}
    
		delete(curr);
		cout<<"deleted"<<endl;
}

	void print()
	{
		if (head == NULL)
		{
			cout << "No records found!" << endl;
			return;
		}
		for (Node* p = head; p != NULL; p = p->next)
		{
			cout << "Reading records from linked list" << endl;
			cout << "The name of the person is " << p->name << endl;
			cout << "The ID of the person is " << p->id << endl;
			cout << "Total number of days for which the car is booked are " << p->numbereofdays << endl;
			cout << "The total rent will be Rs " << p->rentprice << "/-" << endl;
		}
	}

	void search()
	{
		Node* searchnumber = NULL;
		Node* temp = head;
		Node* current = head;
		int searchNum = 0;
		if (head == NULL)
		{
			cout << "No records found!" << endl;
			return;
		}
		cout << "Enter the ID Card Number of the person" << endl;
		cin >> searchNum;
		while (current != NULL && current->id != searchNum) 
		{
			temp = current;
			current = current->next;
		}
		if (current != NULL)
		{
			searchnumber = current;	
			current = current->next;
			cout << "The card number " << searchNum << " found in our records" << endl;
		}
		else
		{
			cout << "The card number " << searchNum << " not found in our records" << endl;
		}
	}

	void myupdate()
	{
		int pos, i;
		string newname;
		int newprice = 0;
		int newnumberofdays = 0;
		string carnum;
		if (head == NULL)
		{
			cout << "No records found!" << endl;
			return;
		}
		cout << "Enter the Id card number of the person to be updated" << endl;
		cin >> pos;
		cout << "Enter the new name" << endl;
		cin >> newname;
		cout << "Car 1 : Honda Civic 2019" << endl;
		cout << "Price : 2500" << endl;
		cout << "Car 2 : Toyota Corolla 2018" << endl;
		cout << "Price : 2400" << endl;
		cout << "Car 3 : Suzuki Mehran 2015" << endl;
		cout << "Price : 2000" << endl;
		cout << "Car 4 : Suzuki Cultus 2017" << endl;
		cout << "Price : 2200" << endl;

		cout << "Press the car number (1, 2, 3, 4) to book it with per day price" << endl;
		cin >> carnum;
		cout << "Now enter number of days that you want to book this car (updated number of days)" << endl;
		cin >> newnumberofdays;
		if (carnum == "1")
		{
			newprice = 2500 * newnumberofdays;
		}
		else if (carnum == "2")
		{
			newprice = 2400 * newnumberofdays;
		}
		else if (carnum == "3")
		{
			newprice = 2000 * newnumberofdays;
		}
		else if (carnum == "4")
		{
			newprice = 2200 * newnumberofdays;
		}
		else
		{
			cout << "We donot have such a car number that you entered" << endl;
			newprice = 0;
		}
		struct Node *s;
		s = head;
		if (pos == s->id)
		{
			head->name = newname;
			head->numbereofdays = newnumberofdays;
			head->rentprice = newprice;
		}
		else
		{
			for (i = 0;i < pos - 1;i++)	
			{
				if (s == NULL)
				{
					cout << "Id card number " << pos << " not found" << endl;
					return;
				}
				s = s->next;
			}
		}
		cout << "Record Updated Successfully!" << endl;
	}

	void saveToFile()
	{
		if (head == NULL)
		{
			cout << "No records to save!" << endl;
			return;
		}
		for (Node* p = head; p != NULL; p = p->next)
		{
			ofstream os("car.txt", ios::out | ios::app);
			os << "The name of the person who booked the car is " << p->name << endl;
			os << "The ID Card Number of the person who booked the car is " << p->id << endl;
			os << "The rent for the number of booked days is Rs " << p->rentprice << "/-" << endl;
			os << "The car booked for the number of days is " << p->numbereofdays << endl;
			os.close();
		}
		cout << "Record Saved Successfully!" << endl;
	}

};

int main() {

	int num = 0;
	string c;
	long long i = 0;
	int price = 0;
	string carnum;
	int days = 0;
	string name;
	linkedList ll;
	Node *head = NULL;
	cout << "Welcome to Car Rental Management System!" << endl;
	do
	{
		cout << "Press 1 to make a booking to rent a car" << endl;
		cout << "Press 2 to delete a booking" << endl;
		cout << "Press 3 to search a booking" << endl;
		cout << "Press 4 to update a booking" << endl;
		cout << "Press 5 to view all bookings from the linked list" << endl;
		cout << "Press 6 to save all records to a file" << endl;
		cout << "Press 7 to view all bookings from the file" << endl;
		cout << "Press 8 to exit the program" << endl << endl;
		cout << "Enter your choice" << endl << endl;
		cin >> c;
		if (c == "1")
		{
			cout << "Enter your name first to book a car" << endl;
			cin >> name;
			cout << "Now enter ID Card Number of the person" << endl;
			cin >> i;
			cout << "There are a variety of car that we can rent out to you!" << endl;
			cout << "Car 1 : Honda Civic 2019" << endl;
			cout << "Price : 2500" << endl;
			cout << "Car 2 : Toyota Corolla 2018" << endl;
			cout << "Price : 2400" << endl;
			cout << "Car 3 : Suzuki Mehran 2015" << endl;
			cout << "Price : 2000" << endl;
			cout << "Car 4 : Suzuki Cultus 2017" << endl;
			cout << "Price : 2200" << endl;

			cout << "Press the car number (1, 2, 3, 4) to book it with per day price" << endl;
			cin >> carnum;
			cout << "Now enter number of days that you want to book this car" << endl;
			cin >> days;
			if (carnum == "1")
			{
				price = 2500 * days;
			}
			else if (carnum == "2")
			{
				price = 2400 * days;
			}
			else if (carnum == "3")
			{
				price = 2000 * days;
			}
			else if (carnum == "4")
			{
				price = 2200 * days;
			}
			else
			{
				cout << "We donot have such a car number that you entered" << endl;
				price = 0;
			}
			ll.addItem(price, days, name, i);
			cout << endl;
		}
		else if (c == "2")
		{
			ll.delitem();
			cout << endl;
		}
		else if (c == "3")
		{
			ll.search();
			cout << endl;
		}
		else if (c == "4")
		{
			ll.myupdate();
			cout << endl;
		}
		else if (c == "5")
		{
			ll.print();
			cout << endl;
		}
		else if (c == "6")
		{
			ll.saveToFile();
			cout << endl;
		}
		else if (c == "7")
		{
			cout << "Reading records from the file" << endl;
			char str;
			ifstream is;
			is.open("car.txt");
			while (is)
			{
				is.get(str);
				cout << str;
			}
			is.close();
			cout << endl;
		}
		else if (c == "8")
		{
			cout << "Thank you for using Car Rental Management System!" << endl;
			return 0;
		}
		else
		{
			cout << "You entered an invalid input" << endl;
		}
	} while (c != "1" || c != "2" || c != "3" || c != "4" || c != "5" || c != "6" || c != "7" || c != "8");
}
