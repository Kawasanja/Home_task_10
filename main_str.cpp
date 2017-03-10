#include <fstream>
#include <iostream>
using namespace std;


int main()
{
   ifstream in;
   fstream out;
   
   int count = 0, posg = 0, posp = 0;
   int str1, str2;
   
   in.open("infile.txt");
   out.open("outfile.txt");
 
   while (!in.eof())
   {
      in >> str1;
      out << str1 << ' ';
      count++;
   }
   in.close();
   out.clear();
   out.seekg(0);
   
   for (int i = 0; i < count - 1; i++)
   {
      for (int j = 0; j < count - i - 1; j++)
      {
         out >> str1;
         posg = out.tellg() + 1;
         out >> str2;
         if (str1 > str2)
         {
            out.seekg(posp);
            out << str2 << ' ';
            posg = out.tellg();
            out << str1 << ' ';
            out.seekg(posg);
            posp = posg;
          
         }
         else
         {
            out.seekg(posg);
            posp = posg;
            continue;
         }
      }
      out.clear();
      posg = posp = 0;
      out.seekg(posg);
   }
   out.close();
   
   return 0;
}
 
