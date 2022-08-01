
#include "BookClass.h"
using std::cout;

class Catalog {

private:
	Book* books;
	int next_slot;
	int capacity;

	

public:
	// constructor
	Catalog(int initi_size = 20) {
		capacity = initi_size;
		next_slot = 0;
		books = new Book[20];

	}
	int getNumBooks() {
		return next_slot;
	}
	
	// looks books by title
	bool getBookbyTitle(string title, Book& bk)
	{
		for (int i = 0; i < next_slot; i++) {
			if (books[i].getTitle() == title) {
				bk = books[i];
				return true;
			}
			
		}
		return false;
	}// looks at lsit of books by author
	bool getBookbyISBN(int isbn, Book& bk) {
		for (int i = 0; i < next_slot; i++) {
			if (books[i].getISBN() == isbn) {
				bk = books[i];
				return true;
			}
			
		}
		return false;
		
	}
	bool listByAuthors(string author) {
		int a = 0;
		for (int i = 0; i < next_slot; i++) {
			if (books[i].getAuthor() == author) {
				books[i].outputBook();
				a++;
			}
		}
		if (a == 0) {
			return false;
		}
		return true;
	}
	bool getBookStatus(int isbn, string& checkedOutBy) {
		for (int i = 0; i < next_slot; i++) {
			if (books[i].getISBN() == isbn) {
				if (books[i].getStatus()) {
					checkedOutBy = books[i].getCheckedOutBy();
					return true;
				}
				return false;
			}
		}
		return false;
	}

	//checks books out
	bool checkOutBook(int isbn, string name) {
		for (int i = 0; i < next_slot; i++) {
			if (books[i].getISBN() == isbn) {
				return books[i].checkOutBook(name);
			}
		}
	} // checks in books
	bool checkInBook(int isbn) {
		for (int i = 0; i < next_slot; i++) {
			if (books[i].getISBN() == isbn) {
				books[i].returnBook();
				return true;
			}
			
		}
		return false;
	}
	bool addBook(Book new_book) {
		Book found;
		bool exist = getBookbyISBN(new_book.getISBN(), found);
		if (exist == true)
			return false;
		else{
			if (next_slot == capacity) {
				grow_catalog();
			}
			books[next_slot] = new_book;
			next_slot++;
			return true;
		}


		books[next_slot] = new_book;
		next_slot++;
	}
	void outputCatalog() {
		for (int i = 0; i < next_slot; i++) {
			books[i].outputBook(); 
		}

	}
	~Catalog() {
		delete[] books;
		books = nullptr;
	}
private:

	void grow_catalog() {
		Book* temp = books;
		capacity *= 2;
		books = new Book[capacity];
		for (int i = 0; i < next_slot; i++)
			books[i] = temp[i];
		delete[] temp;
		temp = nullptr;
	}
	void empty_catalog() {
		delete[] books;
	}
	
	
};
