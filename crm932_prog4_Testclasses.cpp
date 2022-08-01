#include "CatalogClass.h"
#include <string>
/* Name: Cooper Medved
*  NetId: crm932
* Program Description:
*  This is a contination of the library managment system it is a catalog
* with books. program can grow and add books and see
* books written by one author and is it to practice
* OOP and pointers
*/
using std::cin;
using std::getline;

void populate_catalog(Catalog& my_catalog);
int display_menu();

int main()
{
	Catalog my_catalog;
	populate_catalog(my_catalog);

	cout << "Welcome to the Library!\n";
	int choice = 0;

	
	string input_str;
	int isbn;
	bool result;
	Book book_obj;

	do {
		cout << "\n\n";
		choice = display_menu();
		cout << "\n\n";
		switch (choice) {
		case 1: // this is for Find book by title
			cout << "Enter Book Title: ";
			cin.ignore();
			getline(cin, input_str);
			result = my_catalog.getBookbyTitle(input_str, book_obj);
			if (result == true) {
				cout << "Book Found" << endl;
				book_obj.outputBook();
			}
			else {
				cout << "Book not found" << endl;
			}

			break;
		case 2:// this is for Find book by isbn
			cout << "Enter the ISBN: ";
			cin.ignore();
			cin >> isbn;

			result = my_catalog.getBookbyISBN(isbn, book_obj);
			if (result == true) {
				cout << "Book Found" << endl;
				book_obj.outputBook();
			}
			else {
				cout << "Error Book could not be found!" << endl;
			}
			break;
		case 3: // gets author list of books 
			cout << "Enter Name of Author: ";
			cin.ignore();
			getline(cin, input_str);

			cout << "\n\n\t\tBooks by " << input_str << ": \n";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			result = my_catalog.listByAuthors(input_str);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

			if (result == false)
				cout << "Error no books were found by this Author." << endl;
			break;


		case 4: // 
			cin.ignore();
			cout << "Enter the book title: ";
			getline(cin, input_str);
			book_obj.setTitle(input_str);

			cout << "Enter the book author: ";
			getline(cin, input_str);
			book_obj.setAuthor(input_str);

			cout << "Enter the ISBN number: ";
			cin >> isbn;
			book_obj.setISBN(isbn);

			result = my_catalog.addBook(book_obj);

			if (result == true)
				cout << "Successfully added!\n";
			else
				cout << "Add Failed.  Does the book already exist?\n";


			break;

		case 5: // checks status of book if it checked out
			cout << "Enter the ISBN number of the book: ";
			cin >> isbn;

			result = my_catalog.getBookbyISBN(isbn, book_obj);

			if (result == true)
			{
				if (book_obj.getStatus() == true)
					cout << "This book is checked out by " << book_obj.getCheckedOutBy() << "\n";
				else
					cout << "This book is not checked out.\n";
			}
			else
				cout << "Error: Could not find book!\n";

			break;
		case 6: // Cchecks in a checked out book
			cout << "Enter the ISBN number of the book: ";
			cin >> isbn;

			result = my_catalog.checkInBook(isbn);

			if (result == true)
				cout << "Successfully checked in book!";
			else
				cout << "Error: Could not find book!\n";

			break;

		case 7: // Checkouts a book from the catalog
			cout << "Enter the ISBN number of the book: ";
			cin >> isbn;

			result = my_catalog.getBookbyISBN(isbn, book_obj);

			if (result == true)
			{
				if (book_obj.getStatus() == false)
				{
					cout << "Enter the name of the person checking out the book: ";
					cin.ignore();
					getline(cin, input_str);

					result = my_catalog.checkOutBook(isbn, input_str);
					cout << "Book successfully checked out!\n";
				}
				else
					cout << "Error: book already checked out!\n";
			}
			else
				cout << "Error: Could not find book!\n";

			break;

		case 8: // quits program
			return 0;
		}



		} while (choice >= 1 && choice < 8);

		return 0;
	}

int display_menu()
{
	int choice;
	do
	{
		cout << "Main Menu\n";
		cout << "1.  Search by Book Title\n";
		cout << "2.  Search by Book ISBN\n";
		cout << "3.  Output all books by Author\n";
		cout << "4.  Add a New Book to the Catalog\n";
		cout << "5.  Get Check Out Status of Book\n";
		cout << "6.  Check in a book\n";
		cout << "7.  Check out a book\n";
		cout << "8.  Exit Program\n";

		cout << "Enter your choice: ";
		cin >> choice;

		if (choice < 1 and choice > 8)
		{
			cout << "Error: Not a valid Selection!  ";
		}

	} while (choice < 1 || choice > 8);

	return choice;

}

void populate_catalog(Catalog& my_catalog)
{
	Book temp_obj;
	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Sorcerers Stone");
	temp_obj.setISBN(98346);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Chamber of Secrets");
	temp_obj.setISBN(19285);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Prisioner of Azkaban");
	temp_obj.setISBN(88224);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Goblet of Fire");
	temp_obj.setISBN(21001);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Order of Phoenix");
	temp_obj.setISBN(66754);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Half-Blood Prince");
	temp_obj.setISBN(50125);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Deathly Hallows");
	temp_obj.setISBN(68304);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("C.S. Lewis");
	temp_obj.setTitle("The Lion, the Witch, and the Wardrobe");
	temp_obj.setISBN(45336);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("C.S. Lewis");
	temp_obj.setTitle("Prince Caspian");
	temp_obj.setISBN(76689);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("C.S. Lewis");
	temp_obj.setTitle("The Voyage of the Dawn Treader");
	temp_obj.setISBN(34982);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("C.S. Lewis");
	temp_obj.setTitle("The Silver Chair");
	temp_obj.setISBN(45993);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("C.S. Lewis");
	temp_obj.setTitle("A Horse and His Boy");
	temp_obj.setISBN(42398);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("C.S. Lewis");
	temp_obj.setTitle("The Magician's Nephew");
	temp_obj.setISBN(39203);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("C.S. Lewis");
	temp_obj.setTitle("TheLast Battle");
	temp_obj.setISBN(56342);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("E. B. White");
	temp_obj.setTitle("Charlotte's Web");
	temp_obj.setISBN(47851);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("F. Scott Fitzgerald");
	temp_obj.setTitle("The Great Gasby");
	temp_obj.setISBN(11934);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("S. E. Hinton");
	temp_obj.setTitle("The Outsiders");
	temp_obj.setISBN(72331);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("Rick Riordan");
	temp_obj.setTitle("Percy Jackson and The Lighnting Theif");
	temp_obj.setISBN(62789);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("Rick Riordan");
	temp_obj.setTitle("Sea of Monsters");
	temp_obj.setISBN(58739);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("Rick Riordan");
	temp_obj.setTitle("Titan's Curse");
	temp_obj.setISBN(23147);
	my_catalog.addBook(temp_obj);



	
}