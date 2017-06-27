/* Norris Smith
   2/5/16
   Programming Assignment # 6
   A program using a two-dimensional array in order to read in a slip a ticket consisting of information
   such as salesperson's number, product number, and total dollar value of product sold. Information is
   then uses to display a table which has represents sales person number and specific item sold. Finally
   the program calculates a total for sales person and product sold then displays them in their own
   specfic total line. */

#include <iostream> // allows program to perform input and output
#include <iomanip> // parameterized stream manipulators

using namespace std; // program uses names from the std namespace

int main()
{
    // declarationg of variables

    const int PEOPLE = 5, PRODUCTS = 6;
    double sales[ PEOPLE ][ PRODUCTS ] = { 0.0 }, value,
        totalSales, productSales[ PRODUCTS ] = { 0.0 };
    int salesPerson, product;

    // screen print asking user to enter in information
    cout << "Enter the sales person (1 - 4), "
         << "product number (1 - 5) and total sales value.\n"
         << "Enter -1 for the sales person to end input.\n";
    cin >> salesPerson;

    while ( salesPerson != -1 ) // loop to determine whether user is done entering information
    {
        cin >> product >> value;
        sales[ salesPerson ][ product ] += value;
        cin >> salesPerson;
    } // ends loop

    // screen printout of the top line of the table
    cout << "\nThe total sales for each sales person "
         << "are displayed at the end of each row.\n"
         << "Total sales for per product "
         << "are displayed at the bottom of each column.\n\n"
         << setw( 10 ) << 1 << setw( 10 ) << 2
         << setw( 10 ) << 3 << setw( 10 ) << 4
         << setw( 10 ) << 5 << setw( 12 ) << "Total\n"
         << setiosflags( ios::fixed | ios::showpoint );

    for ( int i = 1; i < PEOPLE; ++i )
    {
        totalSales = 0.0; //sets value
        cout << i; // prints out row counter

        for ( int j = 1; j < PRODUCTS; ++j )
        {
            totalSales += sales[ i ][ j ]; // calculates the total
            cout << setw( 10 ) << setprecision( 2 ) // sets spacing and display of values to be displayed
                << sales[ i ][ j ];   // prints out the values of items chosen by user
            productSales[ j ] += sales[ i ][ j ]; // calculates and displays the total of each item
        } // end loop

        cout << setw( 10 ) << setprecision( 2 )
            << totalSales << '\n'; // arranges and display of table
    } //ends loop
    // display the total of eaech item sold
    cout << "\nTotal" << setw( 6 ) << setprecision( 2 )
        << productSales[ 1 ];

    for ( int j = 2; j < PRODUCTS; ++j ) // loop that runs through program to calculate and display total of each item in the bottom line
    {
        cout << setw( 10 ) << setprecision( 2 )
            << productSales[ j ];
    } //end loop
    cout << endl;
    return 0;
} //end main
