//***************************************************************
// Written by Steven Smail for COP3331
//
// Movie.cpp (Project 2)
//
// This program allows the user to enter movie information, which
// is then stored in a vector. When the user has indicated that
// they are done entering movie data, the program outputs the
// information stored in the vector.
//***************************************************************

#include <iostream>
#include <vector>
using namespace std;

struct Movie
{
  string title;    // Movie's title
  string director; // Movie's director
  int year;        // Year released
  int minutes;     // Running time
};

void movieMaker(struct Movie *p);
void print(vector <Movie> a, int size);

int main ()
{
  char ch;
  int count{0};  Movie temp;                // Create a temp structure  vector <Movie> newMovies;  // Create a vector for new movies

  Movie *moviePnt = &temp;  do
  {
    movieMaker(moviePnt);    // Insert it into the vector    newMovies.push_back(temp);
    // Count the number of vector entries
    count++;

    cout << "\nDo you have more movie info to enter?"
         << "\nEnter y/Y for yes or n/N for no: ";
    cin >> ch;
    cin.ignore(); // To skip the remaining '\n' character
  } while(ch == 'y' || ch == 'Y');

  // Display the movie information
  cout << "\nHere is the info that you entered:";
  print(newMovies, count);
}

void movieMaker(struct Movie *p)
{
  // Get the movie information
  // Get the movie title  cout << "\nEnter the title of the movie: ";
  getline(cin, p->title);

  // Get the director's name  cout << "Enter the director's name: ";
  getline(cin, p->director);

  // Get the release year  cout << "Enter the year the movie was created: ";
  cin >> p->year;

  // Get the length
  cout << "Enter the movie length (in minutes): ";
  cin >> p->minutes;

  return;
}

void print(vector <Movie> a, int size)
{
  for(int i = 0; i < size; i++)
  {
    cout << "\nMovie Title: " << a[i].title
         << "\nMovie Director: " << a[i].director
         << "\nMovie Year: " << a[i].year
         << "\nMovie Length: " << a[i].minutes
         << " minutes" << endl;
  }

  return;
}