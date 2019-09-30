/****************************************************************************************
 *                                                                                      *
 *  @Ankit Dimri                                                                        *
 *  A simple code to find the radius and diamemter of a given graph                     *
 *  Radius and diameter of a graph are minimum and maximum eccentricity respectively    *
 *  of any node or vertex in a graph                                                    *
 *                                                                                      *
 ****************************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

 /* function to find the eccentricity of all vertices in a graph */
 std::vector <int> eccentricity  (std::vector <std::vector <int>>&);

 /* Finding the radius and diameter of graph */
 void rnd (std::vector <int> &);

 int main(int argc, char const *argv[]) {

     int edg = 0, ver = 0, u, v;
     std::vector <int> E; // Holding the eccentricity of each vertex

     std::cout << "\n\n\t Enter the number of vertices and edges in the graph :";
     std::cin >> ver >> edg; // number of vertices and edges

     /* Data structure to hold the Adjacency list of the input graph */
     std::vector <std::vector <int>> G (ver, std::vector <int> (0));

     std::cout << "\n\t Enter the vertex pair between which an edge exists :" << '\n';

     for (int i = 0; i < edg; i++) {
         std::cin >> u >> v; // enter edge
         /* Convesion to array numbers */
         u--;
         v--;
         /* Push them into the adjaency list */
         G [u].push_back (v);
         G [v].push_back (u);
     }

     /* Find the eccentricities */
     E = eccentricity (G);
     rnd (E); // find the radius and diameter

     return 0;
 }

 std::vector <int> eccentricity (std::vector <std::vector <int>> &g) {

     int ecc = 0, t = 0, v;
     std::queue <int> q, temp; // queue to perform BFS
     std::vector <int> E (g.size ()); // Data structure to hold values

     for (int i = 0; i < g.size (); i++) {

         ecc = 0;  // Starting
         std::vector <bool> check (g.size (), 0); // Check list to check the visited nodes

         check [i] = 1;
         for (int j = 0; j < g [i].size (); j++) {
             q.push (g [i][j]); // Start BFS for this vertex
             check [g [i][j]] = 1;
         }

         /*
          * Perform BFS and increment the eccentricity value as and when you
          * traverse to a new level
          */
         while (!q.empty ()) {

             temp = q;
             t = temp.size ();

             while (t--) {

                     v = temp.front ();
                     temp.pop ();

                     for (int l = 0; l < g [v].size (); l++) {
                         if (!check [g [v][l]]) {
                             q.push (g [v][l]);
                             check [g [v][l]] = 1;
                         }
                     }

                     q.pop ();
                 }
             ecc++; // New level
         }

         E [i] = ecc; // store the vlaue in the vector
     }

     return E;
 }

 void rnd (std::vector <int> &e) {
      /*
       *  Radius is the minimum eccentricity
       *  Diameter is the maxium eccentricity in the graph
       */
     std::cout << "\n\n\t Radius : " << *std::min_element (e.begin (), e.end ()) << '\n';
     std::cout << "\t Diameter : " << *std::max_element (e.begin (), e.end ()) << '\n';
 }
