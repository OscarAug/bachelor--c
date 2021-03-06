/*
	File Name:functions.cpp
	Athour: Peng Gao
	Date: April 24
	Purpose: Store inventory program
*/

#include "store.h"


Item ItemArray[100];
int ItemArrayNum = 0;

float stringToFloat(string str)
{
	float number;
	char converStr[1000];
	strcpy(converStr, str.c_str());
	number = atof(converStr);
	return number;
}

/*menu function*/
int menu()
{
	int choice = -1;
	/*enter chhoice*/
	cout << "Please choose from the following options:" << endl;
	cout << "1. Add new ThinkGeek item(s)." << endl;
	cout << "2. Print most popular item." << endl;
	cout << "3. Print all items." << endl;
	cout << "4. End the program." << endl;
	cout << endl << "CHOOSE 1-4: ";
	/*situation for if enter worng number*/
	while (true)
	{
		cin >> choice;
		if (choice < 1 || choice > 4)
		{
			cout << "Input error, please input again!" << endl;
			cout << "CHOOSE 1-4: ";
			cin.fail();
			continue;
		}
		break;
	}
	return choice;
}

bool add()
{
	/*enter chhoice*/
	cout << "Do you want to..." << endl;
	cout << "1. Add items from a file?" << endl;
	cout << "2. Add one item manually?" << endl;
	cout << "3. Return to main menu?" << endl;
	cout << "CHOOSE 1-3: ";
	int choice = -1;
	/*situation for if enter worng number*/
	while (true)
	{
		cin >> choice;
		if (choice < 1 || choice > 3)
		{
			cout << "Input error, please input again!" << endl;
			cout << "CHOOSE 1-3: ";
			cin.fail();
			continue;
		}
		break;
	}
	
	/*situation for decide different choices*/
	switch (choice)
	{
	/* if choose add items from a file*/
	case 1:
	{
			  string filename;

			  while (true)
			  {
				  cout << "What is the name of the file that contains your inventory items? ";
				  cin >> filename;
				  ifstream in(filename.c_str());
				  if (in.bad())
				  {
					  cout << "the filename is not exist!" << endl;
					  continue;
				  }

				  char buffer[65535];
				  if (in.is_open())
				  {
					  while (!in.eof())
					  {
						  in.getline(buffer, 65535);
						  const char * split = "#";
						  char *p;
						  p = strtok(buffer, split);
						  int i = 0;
						  if (i / 20 > 100) cout << "We can only store 100 elements of data type Item!";
						  else {
							  while (p != NULL) {
								  switch (i % 20)
								  {
								  case 0:
									  ItemArray[i / 20].Name = p;
								  case 1:
									  ItemArray[i / 20].Description = p;
								  case 2:
									  ItemArray[i / 20].Cost.GoodsPrice = stringToFloat(p);
								  case 3:
									  ItemArray[i / 20].Cost.SalePrice = stringToFloat(p);
								  case 4:
									  ItemArray[i / 20].Cost.Profit = stringToFloat(p);
								  case 5:
									  ItemArray[i / 20].Popularity[0] = atoi(p);
								  case 6:
									  ItemArray[i / 20].Popularity[1] = atoi(p);
								  case 7:
									  ItemArray[i / 20].Popularity[2] = atoi(p);
								  case 8:
									  ItemArray[i / 20].Popularity[3] = atoi(p);
								  case 9:
									  ItemArray[i / 20].Popularity[4] = atoi(p);
								  case 10:
									  ItemArray[i / 20].Popularity[5] = atoi(p);
								  case 11:
									  ItemArray[i / 20].Popularity[6] = atoi(p);
								  case 12:
									  ItemArray[i / 20].Popularity[7] = atoi(p);
								  case 13:
									  ItemArray[i / 20].Popularity[8] = atoi(p);
								  case 14:
									  ItemArray[i / 20].Popularity[9] = atoi(p);
								  case 15:
									  ItemArray[i / 20].Popularity[10] = atoi(p);
								  case 16:
									  ItemArray[i / 20].Popularity[11] = atoi(p);
								  case 17:
									  ItemArray[i / 20].Date.Month = atoi(p);
								  case 18:
									  ItemArray[i / 20].Date.Day = atoi(p);
								  case 19:
									  ItemArray[i / 20].Date.Year = atoi(p);
								  default:
									  break;
								  }
								  p = strtok(NULL, split);
								  i++;
							  }
						  }
						  ItemArrayNum = i / 20;
						  cout << ItemArrayNum << " items from the " << filename << " have been added!" << endl;
					  }
				  }

				  in.close();
				  cout << endl;
				  break;
			  }
			  break;
	}
	/* if choose add one item manually*/
	case 2:
	{
			  cout << "Please enter the item details below:" << endl;
			  cout << "NAME: ";
			  cin.ignore();
			  getline(cin, ItemArray[ItemArrayNum].Name, '\n');
			  cout << "DESCRIPTION: ";
			  getline(cin, ItemArray[ItemArrayNum].Description, '\n');
			  cout << "RETAIL PRICE OF GOODS(what the store paid for it): $ ";
			  cin >> ItemArray[ItemArrayNum].Cost.GoodsPrice;
			  cout << "SALE PRICE (what the store selling it for): $ ";
			  cin >> ItemArray[ItemArrayNum].Cost.SalePrice;
			  cout << "ENTER THE POPULARITY OF THE ITEM FOR EACH MONTH." << endl;
			  cout << "1 = unpopular and 10 = extremely popular" << endl;
			  ItemArray[ItemArrayNum].Cost.Profit = ItemArray[ItemArrayNum].Cost.SalePrice - ItemArray[ItemArrayNum].Cost.GoodsPrice;
			  for (int i = 0; i < 12; i++)
			  {
				  int tempint;
				  while (true)
				  {
					  cout << "	MONTH " << i + 1 << " : ";
					  cin >> tempint;
					  if (0 < tempint && tempint < 11) ItemArray[ItemArrayNum].Popularity[i] = tempint;
					  else{
						  printf("Input error,please make your number is in (1-10)!\n");
						  cin.fail();
						  continue;
					  }
					  break;
				  }
			  }
			  cout << "AQUIRE DATE (example: 04 02 16)" << endl;
			  cin >> ItemArray[ItemArrayNum].Date.Month >> ItemArray[ItemArrayNum].Date.Day >> ItemArray[ItemArrayNum].Date.Year;
			  ItemArray[ItemArrayNum].Cost.Profit = ItemArray[ItemArrayNum].Cost.SalePrice - ItemArray[ItemArrayNum].Cost.GoodsPrice;
			  ItemArrayNum++;
			  cout << "Add item success!" << endl;
			  cout << endl;
			  break;
	}
	/* if choose return to main menu*/
	case 3:
		return false;
	}
	return true;
}

/*printPopular function*/
bool printPopular()
{
	cout << "What month would you like to investigate?(1-12)" << endl;
	int choice = -1;
	/*situation for enter wrong number*/
	while (true)
	{
		cin >> choice;
		if (choice < 1 || choice > 12)
		{
			cout << "Input error, please input again!" << endl;
			cout << "CHOOSE 1-12: ";
			cin.fail();
			continue;
		}
		break;
	}

	cout << "The most popular item for month " << choice << " is: ";

	int mostIndex = -1;
	int max = 0;

	for (int i = 0; i < ItemArrayNum; i++)
	{
		if (ItemArray[i].Popularity[choice - 1] > max)
		{
			max = ItemArray[i].Popularity[choice - 1];
			mostIndex = i;
		}
	}
	/*output information*/
	cout << "NAME: " << ItemArray[mostIndex].Name << endl;
	cout << "DESCRIPTION: " << ItemArray[mostIndex].Description << endl;
	cout << "GOODS PRICE: " << ItemArray[mostIndex].Cost.GoodsPrice << endl;
	cout << "SALE PRICE: " << ItemArray[mostIndex].Cost.SalePrice << endl;
	cout << "PROFIT: " << ItemArray[mostIndex].Cost.Profit << endl;
	cout << "POPULARITY PER MONTH: " << endl;
	for (int i = 0; i < 12; i++)
	{
		cout << "		MONTH" << i + 1 << "- " << ItemArray[mostIndex].Popularity[i] << endl;
	}
	cout << "AQUIRE DATE:" << ItemArray[mostIndex].Date.Month << "/" << ItemArray[mostIndex].Date.Day << "/" << ItemArray[mostIndex].Date.Year;
	cout << endl<<endl;
	return true;
}

/*printItems function*/
bool printItems()
{
	cout << "ALL ITEMS:" << endl;
	for (int i = 0; i < ItemArrayNum; i++)
	{
		/*output information*/
		cout << "--------------------------------------------------------------------" << endl;
		cout << "                                                             ITEM " << i + 1 << endl;
		cout << "NAME: " << ItemArray[i].Name << endl;
		cout << "DESCRIPTION: " << ItemArray[i].Description << endl;
		cout << "GOODS PRICE: " << ItemArray[i].Cost.GoodsPrice << endl;
		cout << "SALE PRICE: " << ItemArray[i].Cost.SalePrice << endl;
		cout << "PROFIT: " << ItemArray[i].Cost.Profit << endl;
		cout << "POPULARITY PER MONTH:" << endl;
		for (int j = 0; j < 12; j++)
		{
			cout << "		MONTH" << j + 1 << "- " << ItemArray[i].Popularity[j] << endl;
		}
		cout << "AQUIRE DATE:" << ItemArray[i].Date.Month << "/" << ItemArray[i].Date.Day << "/" << ItemArray[i].Date.Year << endl;

	}
	cout << endl<<endl;
	return true;
}

/*saveInventory function*/
bool saveInventory()
{
	string filename;
	cout << "what do you want to name your inventory file?(example.txt)" << endl;
	cin >> filename;
	ofstream out(filename.c_str(), ios::out);
	if (out.is_open())
	{
		for (int i = 0; i < ItemArrayNum; i++)
		{
			out << ItemArray[i].Name << "#";
			out << ItemArray[i].Description << "#";
			out << ItemArray[i].Cost.GoodsPrice << "#";
			out << ItemArray[i].Cost.SalePrice << "#";
			out << ItemArray[i].Cost.Profit << "#";
			for (int j = 0; j < 12; j++)
			{
				out << ItemArray[i].Popularity[j] << "#";
			}
			out << ItemArray[i].Date.Month << "#" << ItemArray[i].Date.Day << "#" << ItemArray[i].Date.Year << "#";
		}

		out.close();
	}
	/*save to a new file*/
	cout << "All your items have been saved to " << filename << "." << endl;
	cout << "Goodbye!";
	cout << endl << endl;
	return true;
}
