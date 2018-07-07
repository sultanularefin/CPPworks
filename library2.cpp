/*www.DailyFreeCode.comDownload Projects, Sourcecodes, Tips and Tricks, Interview FAQs, Hotlinks and more....Logon to www.DailyFreeCode.com*///Library Database


#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string.h>
using namespace std;

struct library
{
	char author[20], title[40], pub[20];
	int price;
	library *next;
};

void display(library *start)
{
	
	cout << endl;
	cout << setw(16) << "Book Title" << setw(15) << "Author of Book" << setw(20) << "Publication" << setw(20) << "Price" << endl << endl;
	for (int i = 0; i<40; i++)
		cout << "=*";
	cout << endl;
	while (start != NULL)
	{
		cout << setw(16) << start->title << setw(15) << start->author << setw(20) << start->pub << setw(20) << start->price << endl;
		start = start->next;
	}
	return;
}


int sum = 0;

int main()
{
	
	library *head = NULL;
	library *initial(void);
	library *purchase(library *);
	void display(library *);
	void stock(library *);
	void search(library *);

	int choice;
	while (1)
	{
		cout << endl;
		cout << "Choose your Choice\n";
		cout << "1)    Initial Data Entry\n";
		cout << "2)    Purchase of Book\n";
		cout << "3)    Stock of Book\n";
		cout << "4)    Search of Book\n";
		cout << "5)    Display Books\n";
		cout << "6)    Exit\n";
		cout << "Enter Your Choice:-";
		cin >> choice;
		switch (choice)
		{
		case 1: head = initial();
			getch();
			break;
		case 2: head = purchase(head);
			getch();
			break;
		case 3 : stock(head);
			getch();
			break;
		case 4: search(head);
			getch();
			break;
		case 5: display(head);
			getch();
			break;
		case 6: return 0;
		default: cout << "\nInvalid Choice\nTRY AGAIN\n";
		}
	
	}

	
}

library *initial(void)
{
	
	library *newl = NULL, *start = NULL, *end = newl;
	char ch;
	while (1)
	{
		cout << "\n\nType y or Y for yes\n";
		cout << "Are you Interested in Entering Entry:-";
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
		{
			newl = new library;
			cout << "\n\nEnter Author of Book:-";
			cin >> newl->author;
			cout << "Enter Title of Book:-";
			cin >> newl->title;
			cout << "Enter Publication of Book:-";
			cin >> newl->pub;
			cout << "Enter Price of Book:-";
			cin >> newl->price;
			sum = sum + newl->price;
			if (start == NULL)
				start = newl;
			else
				end->next = newl;
			end = newl;
			end->next = NULL;
		}
		else break;
	}
	return(start);
}

library *purchase(library *start)
{
	
	int pos, count = 1, choice;
	library *newl, *cnt = start, *head = start;
	if (start == NULL)
		cout << "\n\nLIST IS EMPTY\n";

	cout << "\n\nChoose your Choice\n";
	cout << "1)    Inserting At FIRST POSITION\n";
	cout << "2)    Inserting In BETWEEN\n";
	cout << "3)    Inserting At LAST POSITION \n";
	cout << "4)    Exit\n";
	cout << "Enter your choice:-";
	cin >> choice;

	if (choice >= 1 && choice <= 3)
	{
		newl = new library;
		cout << "Enter Author Name :-";
		cin >> newl->author;
		cout << "Enter Book Title :-";
		cin >> newl->title;
		cout << "Enter Publication :-";
		cin >> newl->pub;
		cout << "Enter Price of Book:-";
		cin >> newl->price;
		sum = sum + newl->price;
	}

	switch (choice)
	{
	case 1:          //for First position
		newl->next = head;
		head = newl;
		break;

	case 2:          //for Middle position
	read :
		cout << "\n\nAt which position you want to insert Record:-";
		 cin >> pos;
		 while (cnt != NULL)
		 {
			 count++;                   //cnt for counting variable of type node
			 cnt = cnt->next;
		 }
		 if (pos<1 || pos>count + 1)
		 {
			 cout << "\n\nEntered position is Invalid\nTRY AGAIN\n";
			 goto read;
		 }

				  {                    //Extra Braces are used as case bypasses intialization of a local variable
					  int c=1;
					  while (c <pos - 1)
					  {
						  c++;
						  start = start->next;
					  }
				  }
				  newl->next = start->next;
				  start->next = newl;
				  break;

	case 3:        //for Last positionwhile(start->next!=NULL)
		start = start->next;

		start->next = newl;
		newl->next = NULL;
		break;

	case 4:         goto out;

	default:       cout << "\nEntered Choice is Invalid Try again\n";
		break;

	}
out:
	return(head);
}


void stock(library *start)
{
	
	int count = 0;
	while (start != NULL)
	{
		count++;
		start = start->next;
	}
	cout << "\n\n\n\tTotal Number of Books in Stock is  " << count << endl;
	cout << "\tPurchase Price of Total Stock is  " << sum;
}


void search(library *start)
{
	
	char author[20];
	cout << "Enter Author name to Search in stock\n";
	cin >>  author;
	while (start != NULL)
	{
		
		if (!strcmp(author,start->author))
			
			{
				cout << "\n\nBook is In Stock\n";
				cout << "It Cost Rs" << start->price;
				return;
			}
		
			start = start->next;
	}
	cout << "\n\n book not found \n";
}


