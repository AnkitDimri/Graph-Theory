/****************************************************************************************
 *                                                                                      *
 *  @Ankit Dimri                                                                        *
 *  A implimentation of a code to find the first and second largest element in an       *
 *  unordered set in n+log(n)-1 comparisons where n is the length of the set.           *
 *  HINT: Finding the largest in n-1 comparisons and 2nd largest in log(n) comparisons  *
 *                                                                                      *
 ****************************************************************************************/

 /*
  * It functions like a divide and conquer. The algorithm works bottom-up. All the
  * elements are initially put in the leaves and every consequtive pair is compared to
  * find the larger or the smaller number of the pair and put in the next layer.
  * Traverses similarly into an inverted tree and the last level consists of the
  * largerst element we intend to find. This though takes n-1 comparisons/
  */
#include <iostream>
#include <vector>

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

     t.push_back (temp);
     v.clear (); // clear the vector for reuse
     v = temp;
     temp.clear (); // clear the vector for reuse
     /* loop till the top element is found */
     while (v.size () != 1) {

         n = v.size ();
         for (int i = 0; i < v.size ()-1; i += 2)
             temp.push_back ( (v [i] > v [i+1])?v [i]: v [i+1]);
         if (n%2 != 0)
             temp [temp.size ()-1] = temp [temp.size ()-1] > v [n-1]? temp [temp.size ()-1]:v [n-1];

         t.push_back (temp);

         v.clear ();
         v = temp;
         temp.clear ();

     }

     v.clear ();

     // First largest element computed in n-1 comparisions
     max1 = t [t.size () - 1][0];

     // Making unordered set of log(n) elements to compare to find second largest element
     for (int i = 0; i < t.size ()-1; i++) {
         n = t [i].size ();
         for (int j = 0; j < t [i].size ()-1; j += 2) {
             if (t [i][j] == max1)
                 v.push_back (t [i][j+1]);
             else if (t [i][j+1] == max1)
                     v.push_back (t [i][j]);
         }
         if (n%2 != 0) {
             if (t [i][n-2] == max1 || t [0][n-3] == max1)
                 v.push_back (t [i][n-1]);

             else if (t [i][n-1] == max1)
                 v.push_back (t [i][n-2] > t [i][n-3]? t [i][n-2]:t [i][n-3]);
         }
     }

     n = v.size ();
     // Searching for second largest element in the unordered set
     t1.push_back (v);
     for (int i = 0; i < n-1; i += 2)
         temp.push_back ( (v [i] > v [i+1])?v [i]: v [i+1]);

     if (n%2 != 0)
         temp [temp.size ()-1] = temp [temp.size ()-1] > v [n-1]? temp [temp.size ()-1]:v [n-1];

     t1.push_back (temp);
     v.clear ();
     v = temp;
     temp.clear ();
     while (v.size () != 1) {

         n = v.size ();
         for (int i = 0; i < v.size ()-1; i += 2)
             temp.push_back ( (v [i] > v [i+1])?v [i]: v [i+1]);
         if (n%2 != 0)
             temp [temp.size ()-1] = temp [temp.size ()-1] > v [n-1]? temp [temp.size ()-1]:v [n-1];

         t1.push_back (temp);

         v.clear ();
         v = temp;
         temp.clear ();


     }

     // Second largest element computed in log(n)-1 comparisons
     max2 = t1 [t1.size () - 1][0];

     std::cout << "\n\t First largest : " << max1 << '\n';
     std::cout << "\t Second largest : " << max2 << '\n';

     return 0;
 }
