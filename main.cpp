#include <iostream>
#include <string>
#include <ostream>
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

	string PurchaseStatusString()
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

int main()
{

	Book bookA, bookB, bookC, bookD, bookE, bookF;

	// Testing all permutations of purchase/reading status
	SetBook(bookA, "Harry Potter and the Sorcerer's Stone", "J K Rowling", OWNED, FINISHED);
	SetBook(bookB, "Who cooked the last supper?", "Rosalind Miles", OWNED, READING);
	SetBook(bookC, "Marvirinstrato", "Tim Westover", OWNED, NOT_STARTED);

	SetBook(bookD, "Masters of Doom", "David Kushner", WISHLIST, FINISHED);
	SetBook(bookE, "Earthsong", "Suzette Haden Elgin", WISHLIST, READING);
	SetBook(bookF, "Invent to Learn", "Martinez, Stager", WISHLIST, NOT_STARTED);

	DisplayBook(bookA);
	DisplayBook(bookB);
	DisplayBook(bookC);
	DisplayBook(bookD);
	DisplayBook(bookE);
	DisplayBook(bookF);

	return 0;
}
