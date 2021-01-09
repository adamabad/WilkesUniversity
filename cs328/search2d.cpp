/*
 * File: search2d.cpp
 * Name: Adam Abad
 * Date: 9/14/2020
 * Assignment Name: Theta(lgn + lgm) Search of 2-Dimenstional Array
 */

#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;


// Header functions, prints name and program title
void header() {
    cout<<"\nName: Adam Abad\n";
    cout<<"Logrithmic Search of a 2D array\n";
}


/*
 *
 * mysearch() returns an array pointer that contains data regarding the position of data found.
 * Prototype: 
 *      target - the integer being searched for
 *      theArray - 2D array that is being searched in
 *      n - the number of rows in the 2D array
 *      m - the number of columns in the 2D array 
 * Returns: {-1, -1} if the data is not found otherwise, returns the row and column of the found data.
 * Logic: Uses a nested binary search to perform a search on the 2d array in Theta(logn + logm) time.
 * 
 */
int *mySearch(int target, int **theArray, int n, int m) {
    //Variable Declaration
    int *result;            //The array that will be returned with position of value found or {-1, -1}
    result = new int[2];
    result[0] = -1;
    result[1] = -1;

    //The 3 data values needed for the binary search.
    int left = 0;        
    int right = n - 1;
    int midpoint;
    
    //The 3 data values needed for the nested binary search
    int innerLeft;
    int innerRight;
    int innerMidpoint;

    //If right <= 0, the array is size 0, returns {-1, -1}
    if(right <= 0) {
        return result;
    }
    
    //While loop for the outer binary search
    while(left <= right) {
        
        //Midpoint calculation, adds left to the devision to offset the midpoint to the correct partition
        midpoint = left + (right - left) / 2;

        //The equality case. If the target is greater than the smallest value and less than the largest value, 
        // the target can be in the selected array. 
        if(target >= theArray[midpoint][0] && target <= theArray[midpoint][m - 1]) {
            
            //Setting inner values for the inner array
            innerLeft = 0;
            innerRight = m - 1;

            //While loop for the inner binary search
            while(innerLeft <= innerRight) {

                //Midpoint calculation for the inner loop
                innerMidpoint = innerLeft + (innerRight - innerLeft) / 2;

                //If the target is less than the midpoint, set the right value to the midpoint - 1
                if(target < theArray[midpoint][innerMidpoint]) {
                    innerRight = innerMidpoint - 1; 
                }
                //If the target is greater than the midpoint, set the left value to midpoint + 1
                else if(target > theArray[midpoint][innerMidpoint]){
                    innerLeft = innerMidpoint + 1;
                }
                //If the target is not greater than or less than the midpoint, than the value is found
                // Sets the result array to the corresponding row/columns found and returns
                else {
                    result[0] = midpoint;
                    result[1] = innerMidpoint;
                    return result;
                }
            }
        }

        //If the target is less than the midpoint, set the right value to the midpoint - 1
        if(target < theArray[midpoint][0]) {
            right = midpoint - 1;
        }
        //If the target is greater than the midpoint, set the left value to the midpoint + 1
        else {
            left = midpoint + 1;
        }
    }

    //If the algorithm reaches this result, then the value is not in the 2D array, returns {-1, -1}
    return result;
}

//Main function
int main() {

    //Prints the header
    header();
    
    //Reads name of file
    string filename;
    ifstream myfile;
    cout<<"Enter the name of the file: ";
    cin>>filename;
    cout<<"\n\nOpening: "<<filename<<endl;
    myfile.open(filename);
    //cassert to check if opened
    assert(myfile.good());

    //Variable declaration
    int m = 0;
    int n = 0;
    int search = 0;
    int *result;  

    //First integer n, 2nd integer m
    // n x m array (n = row, m = columns)
    myfile>>n;
    myfile>>m;
    int **myarray;
    myarray = new int *[n];
    for(int x = 0; x < n; x++) {
        myarray[x] = new int[m];
    }
    
    //Read m x n into array row by row
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
           myfile>>myarray[x][y];
        }
        cout<<endl;
    }

    //Remaining integers in the file are data points to search for
    //loop through the remaining data one integer at a time and search the array for the elements in theta lgm + lgn time
    //loop terminates at eof
    cout<<"Array "<<n<<" x "<<m<<" constructed, starting search.\n";
    while(!myfile.eof()) {

        myfile>>search;
        result = mySearch(search, myarray, n, m);
        if(result[0] == -1) {
            // if key not found, print a message stating invalid
            cout<<search<<"    "<<"Not Found"<<endl;
        }
        else {
            // if key found, print row and column num
            cout<<search<<"    "<<"Row: "<<result[0]<<"   Col: "<<result[1]<<"\n";
        }       
    }
    //Close file after finishing
    myfile.close();
    return 0;    
}
