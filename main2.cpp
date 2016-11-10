#include <iostream>
#include <string>
#include <ostream>
#include <istream>
#include <fstream>
using namespace std;

enum ReadingStatus { NOT_STARTED = 0, READING = 1, FINISHED = 2 };
enum PurchaseStatus { OWNED = 0, WISHLIST = 1 };

struct Book
{

	string title;
	string author;
	ReadingStatus readingStatus;
	PurchaseStatus purchaseStatus;

	string ReadingStatusString()
	{
		if (readingStatus == NOT_STARTED)
		{
			return "Not Started";
		}
		else if (readingStatus == READING)
		{
			return "Reading";
		}
		else if (readingStatus == FINISHED)
		{
			return "Finished";
		}
		else
		{
			return "?";
		}
	}

	string PurchaseStatusString(bool a)
	{
		if (purchaseStatus == OWNED)
		{
			return "Owned";
		}
		else if (purchaseStatus == WISHLIST)
		{
			return "Wishlist";
		}
		else
		{
			return "?";
		}
	}

};




void SetBook(Book & book, string title, string author, PurchaseStatus ps, ReadingStatus rs)
{
	book.title = title;
	book.author = author;
	book.purchaseStatus = ps;
	book.readingStatus = rs;

}




void DisplayBook(Book book)
{
	cout << "----------------------------------" << endl;
	cout << book.title << " by " << book.author << endl;
	cout << "Purchase: " << book.PurchaseStatusString() << ", " << "Reading: " << book.ReadingStatusString() << endl;

}


int GetValidInput(int min, int max)
{
	int choice;
	cout << "Input: " << endl;
	cin >> choice;

	while (choice < min || choice > max)
	{
		cout << "Invalid Number!!!" << endl;
		cout << "Input: " << endl;
		cin >> choice;
	}

	cin.ignore();

	return choice;

}



void AddBookMenu(Book books[100], int &bookCount)
{
	string title;
	string author;

	cout << "Enter a title: " << endl;
	getline(cin, title);

	cout << "Enter an author: " << endl;
	getline(cin, author);

	cout << endl << "Purchase Status:" << endl;
	cout << "\t" << OWNED << ". " << books[100].PurchaseStatusString(OWNED) << endl;
	cout << "\t" << WISHLIST << ". " << books[100].PurchaseStatusString(WISHLIST) << endl;

	ps = GetValidInput(OWNED, WISHLIST);
	rs = GetValidInput(NOT_STARTED, FINISHED);

	SetBook(books[bookCount], title, author, (PurchaseStatus)ps, (ReadingStatus)rs);

	bookCount++;

}



void DisplayBookList(Book books[100], int bookCount)
{
	for (int i = 0; i < bookCount; i++)
	{
		DisplayBook(books[i]);
	}
}



void UpdateBookMenu(Book books[100], int &bookCount)
{
	DisplayBookList(books, bookCount);

	cout << "What do you want to update?" << endl;
	int index;
	GetValidInput(index, bookCount);

	string title;
	string author;
	PurchaseStatus ps;
	ReadingStatus rs;

	title = books[index].title;
	author = books[index].author;
	ps = books[index].ps;
	rs = books[index].rs;

	cout << "What do you want to update in another menu?" << endl;
	cout << "1. Update title" << endl;
	cout << "2. Update author " << endl;
	cout << "3. Update purchase status " << endl;
	cout << "4. Update reading status" << endl;

	GetValidInput(index, bookCount);

	//Get the user's input (again, through GetValidInput), and use an if or switch statement.
	//Based on the user's input, have them either enter a new title (to the title variable), author (to the author variable), purchase status, or reading status.
	//Note: For the status variables, you might need to create a temporary int variable and then cast their input to the proper value, similar to in AddBook.

}



void MainMenu(Book books[100], int &bookCount)
{
	cout << "1. Add book" << endl;
	cout << "2. Update book" << endl;
	cout << "3. Display book list" << endl;
	cout << "4. Quit" << endl;

	GetValidInput(1, 4);

	/*Get the user's input with the GetValidInput function, then use a switch or if statement to decide what to do.
	Add book - call AddBookMenu
	Update book - call UpdateBookMenu
	Display book list - call DisplayBookMenu
	Quit - stop the program loop.*/

}



void DisplayStats(Book books[100], int bookCount)
{
	int totalFinished = 0;
	int totalReading = 0;
	int totalUnstarted = 0;

	for (int i = 0; i < 100; i++)
	{
		if (books[i].readingStatus == FINISHED)
		{
			totalFinished++;
		}
		if (books[i].readingStatus == NOT_STARTED)
		{
			totalUnstarted++;
		}
		if (books[i].readingStatus == READING)
		{
			totalReading++;
		}
	}

	cout << "Total Finished: " << totalFinished << endl;
	cout << "Total Unstarted: " << totalUnstarted << endl;
	cout << "Total Reading: " << totalReading << endl;

}



void SaveList(Book book[100], int & bookCount)
{
	ofstream output("booklist.txt");

	for (int i = 0; i < 100; i++)
	{
		output << "BOOK_" << i << endl;
		output << /*output the book's title on its own line*/ << endl;
		output << /*output the book's author on its own line*/ << endl;
		output << PurchaseStatus() << endl;
		output << ReadingStatus() << endl;
	}

	output.close();

}

int main()
{

	Book books[100];
	int bookCount = 0;



	return 0;
}
