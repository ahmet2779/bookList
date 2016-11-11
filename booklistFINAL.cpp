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

	

};


string ReadingStatusString(ReadingStatus rs)
{
	if (rs == NOT_STARTED)
	{
		return "Not Started";
	}
	else if (rs == READING)
	{
		return "Reading";
	}
	else if (rs == FINISHED)
	{
		return "Finished";
	}
	else
	{
		return "?";
	}
}

string PurchaseStatusString(PurchaseStatus ps)
{
	if (ps == OWNED)
	{
		return "Owned";
	}
	else if (ps == WISHLIST)
	{
		return "Wishlist";
	}
	else
	{
		return "?";
	}
}




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
	cout << "Purchase: " << PurchaseStatusString(book.purchaseStatus) << ", " << "Reading: " << ReadingStatusString(book.readingStatus) << endl;
	cout << "----------------------------------" << endl;
}


int GetValidInput(int min, int max)
{
	int choice;
	cout << "\n" << "Input: " << endl;
	cin >> choice;

	while (choice < min || choice > max)
	{
		cout << "\n" << "Invalid Number!!!" << endl;
		cout << "\n" << "Input: " << endl;
		cin >> choice;
	}

	cin.ignore();

	return choice;

}



void AddBookMenu(Book books[100], int &bookCount)
{
	string title;
	string author;

	cout << "\n" << "Enter a title: " << endl;
	getline(cin, title);

	cout << "\n" << "Enter an author: " << endl;
	getline(cin, author);

	cout << endl << "Purchase Status:" << endl;
	cout << "\t" << 0 << ". " << PurchaseStatusString(OWNED) << endl;
	cout << "\t" << 1 << ". " << PurchaseStatusString(WISHLIST) << endl;

	int ps = GetValidInput(OWNED, WISHLIST);

	cout << endl << "Reading Status:" << endl;
	cout << "\t" << 0 << ". " << ReadingStatusString(NOT_STARTED) << endl;
	cout << "\t" << 1 << ". " << ReadingStatusString(READING) << endl;
	cout << "\t" << 2 << ". " << ReadingStatusString(FINISHED) << endl;


	int rs = GetValidInput(NOT_STARTED, FINISHED);

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

	cout << "\n" << "What do you want to update?" << endl;
	int index = GetValidInput(0, bookCount);
	

	string title;
	string author;
	PurchaseStatus ps;
	ReadingStatus rs;

	title = books[index].title;
	author = books[index].author;
	ps = books[index].purchaseStatus;
	rs = books[index].readingStatus;

	cout << "\n" << "What do you want to update in another menu?" << endl;
	cout << "\n" << "1. Update title" << endl;
	cout << "\n" << "2. Update author " << endl;
	cout << "\n" << "3. Update purchase status " << endl;
	cout << "\n" << "4. Update reading status" << endl;
	
	int choice = GetValidInput(1, 4);
	if (choice == 1)
	{
		cout << "\n" << "Enter the new title:" << endl;
		getline(cin, books[index].title);

	}
	if (choice == 2)
	{
		cout << "\n" << "Enter the new author:" << endl;
		getline(cin, books[index].author);

	}
	if (choice == 3)
	{
		cout << "\n" << "Enter the new purchase status:" << endl;

		int ps = GetValidInput(OWNED, WISHLIST);

		books[index].purchaseStatus = (PurchaseStatus)ps;

	}
	if (choice == 4)
	{
		cout << "\n" << "Enter the reading status:" << endl;

		int rs = GetValidInput(NOT_STARTED, FINISHED);

		books[index].readingStatus = (ReadingStatus)rs;

	}
	else
	{
		cout << "\n" << "Invalid Choice. Please try another number." << endl;
	}

	cout << "\n" << "Updated succesfully" << endl;


}



void MainMenu(Book books[100], int &bookCount)
{
	
	while (true)
{ 
	cout << "\n" << "1. Add book" << endl;
	cout << "\n" << "2. Update book" << endl;
	cout << "\n" << "3. Display book list" << endl;
	cout << "\n" << "4. Quit" << endl;

	int choice = GetValidInput(1, 4);

	if (choice == 1)
	{
		AddBookMenu(books, bookCount);
	}
	if (choice == 2)
	{
		UpdateBookMenu(books, bookCount);
	}
	if (choice == 3)
	{
		DisplayBookList(books, bookCount);
	}
	if (choice == 4)
	{
		break;
	}

}

	

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



void SaveList(Book books[100], int & bookCount)
{
	ofstream output("booklist.txt");

	for (int i = 0; i < 100; i++)
	{
		output << "BOOK_" << i << endl;
		output << books[i].title << endl;
		output << books[i].author << endl;
		output << PurchaseStatusString(books[i].purchaseStatus) << endl;
		output << ReadingStatusString(books[i].readingStatus) << endl;
	}

	output.close();

}



void LoadList(Book books[100], int bookCount)
{
	ifstream input("booklist.txt");

	bookCount = 0;

	string title;
	string status;
	string author;
	string buffer;

	int rstatus;
	int pstatus;

	while (input >> buffer)
	{
		input.ignore();

		getline(input, title);
		getline(input, author);
		input >> pstatus;
		input >> rstatus;



	}


}


void ExportCsv(Book books[100], int & bookCount)
{
	ofstream output("booklist.csv");

	output << "TITLE,AUTHOR,READING?,OWNED?" << endl;

	for (int i = 0; i < bookCount; i++)
	{
		output << books[i].title << ","
			<< books[i].author << ","
			<< books[i].readingStatus << ","
			<< books[i].purchaseStatus << ","
			<< endl;
	}

	output.close();
}




void ExportUnfinishedBooks(Book books[100], int bookCount)
{
	ofstream output("booklist.csv");

	output << "NOT_STARTED? READING?" << endl;

	for (int i = 0; i < bookCount; i++)
	{
		if (books[i].readingStatus == NOT_STARTED || books[i].readingStatus == READING)
		{
			output << books[i].title << ","
				<< books[i].author << ","
				<< books[i].readingStatus << ","
				<< books[i].purchaseStatus << ","
				<< endl;
		}
		
	}

	output.close();
}



int main()
{

	Book books[100];
	int bookCount = 0;

	LoadList(books, bookCount);

	MainMenu(books, bookCount);

	ExportCsv(books, bookCount);

	ExportUnfinishedBooks(books, bookCount);




	return 0;
}
