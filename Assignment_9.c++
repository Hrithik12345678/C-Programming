/*
Name   : Hrithik Singh
Roll No: 233020
GR No  : 21910952
Batch  : C-1
*/

#include<iostream>
using namespace std;

class student
{
public:
  char name[30];
  int rank, roll;
};

void min_heapify (student * s, int i, int n)
{
  int highest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < n && s[l].rank < s[highest].rank)
    {
      highest = l;
    }
  if (r < n && s[r].rank < s[highest].rank)
    {
      highest = r;
    }
  student temp;
  if (highest != i)
    {
      temp = s[i];
      s[i] = s[highest];
      s[highest] = temp;
      min_heapify (s, highest, n);
    }
}

void min_heap (student * s, int n)
{
  for (int i = (n / 2) - 1; i >= 0; i--)
    {
      min_heapify (s, i, n);
    }
}

void delete_root (student s[], int &n)
{
  student temp = s[n - 1];
  s[0] = temp;
  n = n - 1;
  min_heapify (s, 0, n);
}

void heapsort (student * s, int n)
{
  for (int i = ((n / 2) - 1); i >= 0; i--)
    {
      min_heapify (s, i, n);
    }
  student temp;
  for (int i = n - 1; i >= 0; i--)
    {
      temp = s[0];
      s[0] = s[i];
      s[i] = temp;
      min_heapify (s, 0, i);
    }

}

int main ()
{
  int choice, n, flag = 0, temp = 0;
  student s[20];
  do
    {
      cout << "\n****Menu**" << endl;
      cout << "\n1.Create heap\n2.Get the topper \n3.HeapSort\n4.Exit";
      cout << "Enter Your Choice : ";
      cin >> choice;
      switch (choice)
	{
	case 1:
	  temp = 1;
	  flag = 0;
	  cout << "\nEnter the number of students :";
	  cin >> n;
	  for (int i = 0; i < n; i++)
	    {
	      cout << "\nEnter the Name :";
	      cin >> s[i].name;
	      cout << "\nEnter the Roll Number :";
	      cin >> s[i].roll;
	      cout << "\nEnter the Rank :";
	      cin >> s[i].rank;
	    }
	  min_heap (s, n);
	  cout << "\n*****Student DataBase***" << endl;
	  cout << "\n Name\t Roll No \tRank" << endl;
	  for (int i = 0; i < n; i++)
	    {
	      cout << " " << s[i].name << "\t " << s[i].
		roll << "\t\t" << s[i].rank << endl;

	    }
	  break;
	case 2:
	  if (flag == 0 && temp == 1)
	    {
	      delete_root (s, n);
	      cout << "\nAfter deleting topper :" << endl;
	      cout << "\n*****Student DataBase***" << endl;
	      cout << "\n Name\t Roll No \tRank" << endl;
	      for (int i = 0; i < n; i++)
		{
		  cout << " " << s[i].name << "\t " << s[i].
		    roll << "\t\t" << s[i].rank << endl;
		}
	    }
	  else
	    {
	      cout << "\nERROR OCCURED!!\n" << endl;
	    }

	  break;
	case 3:
	  if (temp == 1)
	    {
	      flag = 1;
	      heapsort (s, n);
	      cout << "\nAfter heap sort :" << endl;
	      cout << "\n Name\t Roll No \tRank" << endl;
	      for (int i = 0; i < n; i++)
		{
		  cout << " " << s[i].name << "\t " << s[i].
		    roll << "\t\t" << s[i].rank << endl;
		}
	      cout << "\n10 students having least score are :" << endl;
	      cout << "\n Name\t Roll No \tRank" << endl;
	      if (n > 10)
		{
		  for (int i = n - 1; i >= 0; i--)
		    {
		      cout << " " << s[i].name << "\t " << s[i].
			roll << "\t\t" << s[i].rank << endl;
		    }
		}
	      else
		{
		  for (int i = n - 1; i >= 0; i--)
		    {
		      cout << " " << s[i].name << "\t " << s[i].
			roll << "\t\t" << s[i].rank << endl;
		    }
		  cout << "\nStudents are less \n";
		}
	    }
	  else
	    {
	      cout << "\nCreate min Heap first \n" << endl;
	    }
	  break;

	case 4:
	  cout << "Thank You!!";
	  break;

	default:
	  cout << "Enter Valid Choice!!";

	}
    }
  while (choice != 4);
  return 0;
}