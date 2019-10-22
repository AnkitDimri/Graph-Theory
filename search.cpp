/****************************************************************************************
 *                                                                                      *
 *  @Author: Ankit Dimri                                                                *
 *                                                                                      *
 *  A implementation of a code to find the first and second largest element in an       *
 *  unordered set in n+log(n)-1 comparisons where n is the length of the set.           *
 *                                                                                      *
 *  HINT: Finding the largest in n-1 comparisons and 2nd largest in log(n) comparisons  *
 *  The implementation is done in C++ with use of vector library.                       *
 *  Run this file using command g++ search.cpp -o search (This will create a object     *
 *  file for this program). Now execute the object file using ./search.                 *
 *                                                                                      *
 ****************************************************************************************/

 /*
  * It functions like a divide and conquer. The algorithm works bottom-up. All the
  * elements are initially put in the leaves and every consequtive pair is compared to
  * find the larger or the smaller number of the pair and put in the next layer.
  * Traverses similarly into an inverted tree and the last level consists of the
  * largerst element we intend to find. This though takes n-1 comparisons to find the
  * first largest element. The second largest element is found by traversing the path
  * from root element to the leaf passing through each node pair which consists of
  * comparisons with the largest element. Now comparing only these elements of the
  * path, we find the second largest element. This takes log(n) comparisons as the
  * number of compared elements is the length/height/depth of the tree created
  * to find the largest element.
  */

/* Libraries used */
#include <iostream>
#include <vector>
#include <limits.h>

 int main(int argc, char const *argv[]) {

     std::vector <int> v, temp;
     std::vector <std::vector <int>> t, t1;
     int n, ele, max1, max2;

     std::cout << "\n\n\t Enter the size of the unordered set : ";
     std::cin >> n; // Enter the size (user input)

     std::cout << "\n\t Enter the elements of the unordered set : ";
     /* Enter the elements one by one */
     for (int i = 0; i < n; i++) {

         std::cin >> ele;
         v.push_back (ele); // elements pushed back into the vector

     }

     t.push_back (v); // initial tree level (inverted tree)

     /* Create new levels in accordance to the algorithm */
     for (int i = 0; i < n-1; i += 2)
         temp.push_back ( (v [i] > v [i+1])?v [i]: v [i+1]);

     if (n%2 != 0)
         temp [temp.size ()-1] = temp [temp.size ()-1] > v [n-1]? temp [temp.size ()-1]:v [n-1];

     t.push_back (temp); // Add tree levels with half number of nodes
     v.clear (); // clear the vector for reuse
     v = temp; //assigning vector temp to v
     temp.clear (); // clear the vector for reuse
     /* loop till the top element is found */
     while (v.size () != 1) {

         n = v.size ();

         /* Compare using the terinary and push back into the level vector */
         for (int i = 0; i < v.size ()-1; i += 2)
             temp.push_back ( (v [i] > v [i+1])?v [i]: v [i+1]);

         /* Check in the case with odd sized level so as to not miss the last element of the level */
         if (n%2 != 0)
             temp [temp.size ()-1] = temp [temp.size ()-1] > v [n-1]? temp [temp.size ()-1]:v [n-1];

         t.push_back (temp);

         /* prepare the data structures for next iteration */
         v.clear ();
         v = temp;
         temp.clear ();

     }

     v.clear ();

     /* First largest element computed in n-1 comparisions */
     max1 = t [t.size () - 1][0];

     max2 = INT_MIN; // Initilize with the smallest number (integer)

     for (int i = 0; i < t.size ()-1; i++) {

         n = t [i].size ();
         for (int j = 0; j < n; j += 2) {

             if (t [i][j] == max1)
                 if (t [i][j+1] > max2)
                     max2 = t [i][j+1];

             else if (t [i][j+1] == max1)
                     if (t [i][j] > max2)
                         max2 = t [i][j];

         }

         /* case to handle when the lenght of level vector is odd */
         if (n%2 != 0) {
             if (t [i][n-2] == max1 || t [0][n-3] == max1) {
                 //v.push_back (t [i][n-1]);
                 if (t [i][n-1] > max2)
                     max2 = t [i][n-1];
             }

             else if (t [i][n-1] == max1) {
                 //v.push_back (t [i][n-2] > t [i][n-3]? t [i][n-2]:t [i][n-3]);
                 int m;
                 if ((m = t [i][n-2] > t [i][n-3]? t [i][n-2]:t [i][n-3]) > max2)
                     max2 = m;
             }
         }
     }

     std::cout << "\n\t First largest : " << max1 << '\n'; //prints the first largest number
     std::cout << "\t Second largest : " << max2 << '\n'; //prints the second largest number

     return 0;
 }
