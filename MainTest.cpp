#include<iostream>
#include<string>

#include"Date.h"
#include"employee.h"
#include"Street_Store.h"
#include"City.h"
#include"node.h"
#include"btree.h"
#include"Country.h"
#include"listnode.h"
#include"linked_list.h"

using namespace std;

int main() 
{

	linked_list Countries;
	

	while (true)
	{
		int temp;
		cout << endl; //just for better output design

		cout << "Welcome to EECE 330 Store Program" << endl;
		cout << endl; //just for better output design

		cout << "Please Choose The Needed Option: " << endl;
		cout << "Press 1 For Countries" << endl;
		cout << "Press 2 For Cities" << endl;
		cout << "Press 3 For Streets & Stores" << endl;
		cout << "Press 4 For Employees"<< endl;
		cout << "Press 5 For Printing" << endl;
		cout << "Press 6 to Exit The Program" << endl;
		cin >> temp;

		if(!cin)
		{
			cout<< "Error: You didn't enter a number" <<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),"\n");
			cout<<"Please choose The Needed Option from the list above. Make sure to insert a number 1 to 6"<<endl;
			cin>>temp;
			if(cin.fail())
			{
				cout<<"Error: You didn't enter a number for the second time in a row. The program will terminate, please restart it"<<endl;
			}
		}

		if (temp == 1)
		{
			int temp1;
			cout << "Press 1 to add a country" << endl;
			cout << "Press 2 to delete a country" << endl;
			cout << "Press 3 to print the number of stores in a country" << endl;
			cin >> temp1;

			if (temp1 == 1)
			{
				//ask for the id and name of the country and then check if it exists and add it if it doesnt
				int country_id;
				string country_name;
				cout << "Please enter the Id of the Country you want to add" << endl;
				cin >> country_id;
				cout << "Please enter the Name of the Country you want to add" << endl;
				cin >> country_name;
				Country firstcountry(country_id, country_name); //one of the constructors
				if (Countries.searchifthere(firstcountry) == true) //using the searhching function in countries
				{
					cout << "This country already exist" << endl;
				}
				else //adding the country
				{
					Countries.add_node(firstcountry);
					cout << "The country has been added" << endl;
				}
			}

			else if (temp1 == 2)
			{
				//ask for the id and then delete the country of that id if it exists
				int country_id;
				string country_name = "";
				cout << "Please enter the Id of the country you want to delete " << endl;
				cin >> country_id;
				Country firstcountry(country_id, country_name);
				if (Countries.searchifthere(firstcountry) == true)
				{
					Countries.deletefunction(firstcountry);
					cout << "The city has been deleted" << endl;
				}
				else
				{
					cout << "The country doesnt exist" << endl;
				}

			}
			else if (temp1 == 3)
			{
				//prints the number of stores in a country
				int country_id;
				string country_name = "";
				cout << "Please enter the Id of the Country you want to print the number of stores of " << endl;
				cin >> country_id;
				Country firstcountry(country_id, country_name);
				if (Countries.searchifthere(firstcountry) == true)
				{
					cout << "The number of stores in the country of Id " << country_id << " is " << Countries.search(firstcountry)->data.tree.countstoreofcountry() << endl;
				}
				else
				{
					cout << "The country doesnt exist" << endl;
				}

			}
			else // if the user doesn't input 1,2, or 3
			{
				cout << "Such command doesnt exist" << endl;
			}
		}

		else if (temp == 2)
		{
			int temp1;
			cout << "Press 1 to add a City" << endl;
			cout << "Press 2 to delete a City" << endl;
			cout << "Press 3 to print the number of stores in a city" << endl;
			cin >> temp1;
			if (temp1 == 1)
			{
				//add a city to a specific country while checking
				int country_id;
				string country_name = "";
				int city_id;
				string city_name = "";
				cout << "Please enter the id of the country you want to add to " << endl;
				cin >> country_id;
				Country firstcountry(country_id, country_name);
				if (Countries.searchifthere(firstcountry) == true)
				{
					cout << "Please enter the id of the city you want to add" << endl;
					cin >> city_id;
					City firstcity(city_id, city_name);
					if (Countries.search(firstcountry)->data.tree.searchifthere(firstcity) == true)
					{
						cout << "This city already exists" << endl;
					}
					else
					{
						cout << "Please enter the name of the city you want to add" << endl;
						cin >> city_name;
						City firstcity(city_id, city_name);
						Countries.search(firstcountry)->data.tree.insert(firstcity);
						cout << "The city has been added" << endl;
					}
				}
				else
				{
					cout << "This country doesnt exist" << endl;
				}
			}
			else if (temp1 == 2)
			{
				//delete a city from a specific country
				int country_id;
				string country_name = "";
				int city_id;
				string city_name = "";
				cout << "Please enter the id of the country you want to delete from " << endl;
				cin >> country_id;
				Country firstcountry(country_id, country_name);
				if (Countries.searchifthere(firstcountry) == true)
				{
					cout << "Please enter the id of the city you want to delete" << endl;
					cin >> city_id;
					City firstcity(city_id, city_name);
					if (Countries.search(firstcountry)->data.tree.searchifthere(firstcity) == true)
					{
						Countries.search(firstcountry)->data.tree.deleteNode(firstcity);
						cout << "The city has been deleted" << endl;
					}
					else
					{
						cout << "This city doesnt exist" << endl;
					}
				}
				else
				{
					cout << "This country doesnt exist" << endl;
				}
			}
			else if (temp1 == 3)
			{
				//print the number of stores in a specific city
				int country_id;
				string country_name = "";
				int city_id;
				string city_name = "";
				cout << "Please enter the id of the country you want to print the number of stores from " << endl;
				cin >> country_id;
				Country firstcountry(country_id, country_name);
				if (Countries.searchifthere(firstcountry) == true)
				{
					cout << "Please enter the id of the city you want to print the number of stores of" << endl;
					cin >> city_id;
					City firstcity(city_id, city_name);
					if (Countries.search(firstcountry)->data.tree.searchifthere(firstcity) == true)
					{
						cout << "the number of stores in the city of id " << firstcity.City_id << " is " << Countries.search(firstcountry)->data.tree.search(firstcity)->value.countstoreincity() << endl;
					}
					else
					{
						cout << "This city doesnt exist" << endl;
					}
				}
				else
				{
					cout << "This country doesnt exist" << endl;
				}
			}
			else // if the user inputs something different than 1,2,3
			{
				cout << "Such command doesnt exist" << endl;
			}
		}

		else if (temp == 3)
		{
			int temp1;
			cout << "Press 1 to add a Store" << endl;
			cout << "Press 2 to delete a Store" << endl;
			cout << "Press 3 to update" << endl;
			cin >> temp1;
			if (temp1 == 1)
			{
				//add a store to a specifc city
				int country_id;
				string country_name = "";
				int city_id;
				string city_name = "";
				int store_id;
				string Street_name = "";
				string Manager_name = "";
				string Telephone = "";
				int day = 1;
				int month = 1;
				int year = 1;
				cout << "Please enter the Id of the Country you want to add to " << endl;
				cin >> country_id;
				Country firstcountry(country_id, country_name);
				if (Countries.searchifthere(firstcountry) == true)
				{
					cout << "Please enter the Id of the City you want to add to" << endl;
					cin >> city_id;
					City firstcity(city_id, city_name);
					if (Countries.search(firstcountry)->data.tree.searchifthere(firstcity) == true)
					{
						cout << "Please enter the Id of the Store you want to add" << endl;
						cin >> store_id;
						Street_Store firststore(store_id, Street_name, Manager_name, Telephone, day, month, year);
						if (Countries.search(firstcountry)->data.tree.search(firstcity)->value.searchstorebool(firststore) == true)
						{
							cout << "This Store already exist" << endl;
						}
						else
						{
							cout << "Please enter the Name of the Street of the Store "<< endl;
							cin >> Street_name;
							cout << "Please enter the Name of the Manager of the Store" << endl;
							cin >> Manager_name;
							cout << "Please enter the Telephone number of the Store" << endl;
							cin >> Telephone;
							cout << "Please enter the Day you opened/will the Store" << endl;
							cin >> day;
							cout << "Please enter the Month you opened/will open the Store" << endl;
							cin >> month;
							cout << "Please enter the Year you opened/will open the Store" << endl;
							cin >> year;
							Street_Store firststore(store_id, Street_name, Manager_name, Telephone, day, month, year);
							Countries.search(firstcountry)->data.tree.search(firstcity)->value.insertStore(firststore);
							cout << "The store has been added" << endl;
						}

					}
					else
					{
						cout << "This City doesnt exist" << endl;
					}
				}
				else
				{
					cout << "This Country doesnt exist" << endl;
				}
			}
			else if (temp1 == 2)
			{
				//delete a store from a specifc city
				int country_id;
				string country_name = "";
				int city_id;
				string city_name = "";
				int store_id;
				string Street_name = "";
				string Manager_name = "";
				string Telephone = "";
				int day = 1;
				int month = 1;
				int year = 1;
				cout << "Please enter the Id of the Country you want to delete from " << endl;
				cin >> country_id;
				Country firstcountry(country_id, country_name);
				if (Countries.searchifthere(firstcountry) == true)
				{
					cout << "Please enter the Id of the City you want to delete from" << endl;
					cin >> city_id;
					City firstcity(city_id, city_name);
					if (Countries.search(firstcountry)->data.tree.searchifthere(firstcity) == true)
					{
						cout << "Please enter the Id of the Store you want to delete" << endl;
						cin >> store_id;
						Street_Store firststore(store_id, Street_name, Manager_name, Telephone, day, month, year);
						if (Countries.search(firstcountry)->data.tree.search(firstcity)->value.searchstorebool(firststore) == true)
						{
							Countries.search(firstcountry)->data.tree.search(firstcity)->value.deletestore(firststore);
							cout << "The store has been deleted" << endl;
						}
						else
						{
							cout << "This Store doesnt exist" << endl;
						}

					}
					else
					{
						cout << "This City doesnt exist" << endl;
					}
				}
				else
				{
					cout << "This Country doesnt exist" << endl;
				}


			}
			else if (temp1 == 3)
			{
				//update the information of a store in a specific city
				int country_id;
				string country_name = "";
				int city_id;
				string city_name = "";
				int store_id;
				string Street_name = "";
				string Manager_name = "";
				string Telephone = "";
				int day = 1;
				int month = 1;
				int year = 1;
				cout << "Please enter the Id of the Country you want to update to " << endl;
				cin >> country_id;
				Country firstcountry(country_id, country_name);
				if (Countries.searchifthere(firstcountry) == true)
				{
					cout << "Please enter the Id of the City you want to update to" << endl;
					cin >> city_id;
					City firstcity(city_id, city_name);
					if (Countries.search(firstcountry)->data.tree.searchifthere(firstcity) == true)
					{
						cout << "Please enter the Id of the Store you want to update" << endl;
						cin >> store_id;
						Street_Store firststore(store_id, Street_name, Manager_name, Telephone, day, month, year);
						if (Countries.search(firstcountry)->data.tree.search(firstcity)->value.searchstorebool(firststore) == true)
						{
							cout << "Please enter the new Street Name of the Store" << endl;
							cin >> Street_name;
							cout << "Please enter the Name of the new Manager of the Store" << endl;
							cin >> Manager_name;
							cout << "Please enter the new Telephone number of the Store" << endl;
							cin >> Telephone;
							cout << "Please enter the new Day of the store's openning" << endl;
							cin >> day;
							cout << "Please enter the new Month of the store's openning" << endl;
							cin >> month;
							cout << "Please enter the new Year of the store's openning" << endl;
							cin >> year;
							Countries.search(firstcountry)->data.tree.search(firstcity)->value.Stores[Countries.search(firstcountry)->data.tree.search(firstcity)->value.searchstoreint(firststore)].Street_name = Street_name;
							Countries.search(firstcountry)->data.tree.search(firstcity)->value.Stores[Countries.search(firstcountry)->data.tree.search(firstcity)->value.searchstoreint(firststore)].Manager_name = Manager_name;
							Countries.search(firstcountry)->data.tree.search(firstcity)->value.Stores[Countries.search(firstcountry)->data.tree.search(firstcity)->value.searchstoreint(firststore)].Telephone = Telephone;
							Countries.search(firstcountry)->data.tree.search(firstcity)->value.Stores[Countries.search(firstcountry)->data.tree.search(firstcity)->value.searchstoreint(firststore)].date_open.setDate(day, month, year);
							cout << "The store has been updated" << endl;

						}
						else
						{
							cout << "This Store doesnt exist" << endl;
						}
					}
					else
					{
						cout << "This City doesnt exist" << endl;
					}
				}
				else
				{
					cout << "This Country doesnt exist" << endl;
				}
			}
			else //inputting other than 1,2,3
			{
				cout << "Such command doesnt exist" << endl;
			}
		}

		else if (temp == 4)
		{
			int temp1;
			cout << "Press 1 to add an Employee" << endl;
			cout << "Press 2 to delete an Employee" << endl;
			cout << "Press 3 to transfer an Employee" << endl;
			cin >> temp1;
			if (temp1 == 1)
			{
				//add an employee to a specifc store
				int country_id;
				string country_name = "";
				int city_id;
				string city_name = "";
				int store_id;
				string Street_name = "";
				string Manager_name = "";
				string Telephone = "";
				int day = 1;
				int month = 1;
				int year = 1;
				int employee_id;
				string employee_name = "";
				cout << "Please enter the id of the country you want to add to " << endl;
				cin >> country_id;
				Country firstcountry(country_id, country_name);
				if (Countries.searchifthere(firstcountry) == true)
				{
					cout << "Please enter the id of the city you want to add to" << endl;
					cin >> city_id;
					City firstcity(city_id, city_name);
					if (Countries.search(firstcountry)->data.tree.searchifthere(firstcity) == true)
					{
						cout << "Please enter the id of the store you want to add to" << endl;
						cin >> store_id;
						Street_Store firststore(store_id, Street_name, Manager_name, Telephone, day, month, year);
						if (Countries.search(firstcountry)->data.tree.search(firstcity)->value.searchstorebool(firststore) == true)
						{
							cout << "Please enter the employee id" << endl;
							cin >> employee_id;
							employee firstemployee(employee_id, employee_name);
							if (Countries.search(firstcountry)->data.tree.search(firstcity)->value.Stores[Countries.search(firstcountry)->data.tree.search(firstcity)->value.searchstoreint(firststore)].searchemployeecheck(firstemployee) == true)
							{
								cout << "The employee already exist" << endl;
							}
							else
							{
								cout << "Please enter the employee name " << endl;
								cin >> employee_name;
								employee firstemployee(employee_id, employee_name);
								Countries.search(firstcountry)->data.tree.search(firstcity)->value.Stores[Countries.search(firstcountry)->data.tree.search(firstcity)->value.searchstoreint(firststore)].insertemployee(firstemployee);
								cout << "The employee has been added" << endl;
							}
						}
						else
						{
							cout << "The store doesnt exist" << endl;
						}
					}
					else
					{
						cout << "This city doesnt exist" << endl;
					}
				}
				else
				{
					cout << "This country doesnt exist" << endl;
				}
			}
			else if (temp1 == 2)
			{
				//delete an employee from a specific store
				int country_id;
				string country_name = "";
				int city_id;
				string city_name = "";
				int store_id;
				string Street_name = "";
				string Manager_name = "";
				string Telephone = "";
				int day = 1;
				int month = 1;
				int year = 1;
				int employee_id;
				string employee_name = "";
				cout << "Please enter the id of the country you want to delete from " << endl;
				cin >> country_id;
				Country firstcountry(country_id, country_name);
				if (Countries.searchifthere(firstcountry) == true)
				{
					cout << "Please enter the id of the city you want delete from" << endl;
					cin >> city_id;
					City firstcity(city_id, city_name);
					if (Countries.search(firstcountry)->data.tree.searchifthere(firstcity) == true)
					{
						cout << "Please enter the id of the store you want to delete from" << endl;
						cin >> store_id;
						Street_Store firststore(store_id, Street_name, Manager_name, Telephone, day, month, year);
						if (Countries.search(firstcountry)->data.tree.search(firstcity)->value.searchstorebool(firststore) == true)
						{
							cout << "Please enter the employee id you want to remove" << endl;
							cin >> employee_id;
							employee firstemployee(employee_id, employee_name);
							if (Countries.search(firstcountry)->data.tree.search(firstcity)->value.Stores[Countries.search(firstcountry)->data.tree.search(firstcity)->value.searchstoreint(firststore)].searchemployeecheck(firstemployee) == true)
							{
								Countries.search(firstcountry)->data.tree.search(firstcity)->value.Stores[Countries.search(firstcountry)->data.tree.search(firstcity)->value.searchstoreint(firststore)].deleteemployee(firstemployee);
								cout << "The employee has been removed" << endl;
							}
							else
							{
								cout << "The employee doesnt exist" << endl;
							}
						}
						else
						{
							cout << "The store doesnt exist" << endl;
						}
					}
					else
					{
						cout << "This city doesnt exist" << endl;
					}
				}
				else
				{
					cout << "This country doesnt exist" << endl;
				}
			}
			else if (temp1 == 3)
			{
				//transfer an emplyee from a store to a store by deleting him from the first store and then adding it to the second
				int country_id;
				string country_name = "";
				int city_id;
				string city_name = "";
				int store1_id;
				int store2_id;
				string Street_name = "";
				string Manager_name = "";
				string Telephone = "";
				int day = 1;
				int month = 1;
				int year = 1;
				int employee_id;
				string employee_name = "";
				cout << "Please enter the id of the country you want to move from " << endl;
				cin >> country_id;
				Country firstcountry(country_id, country_name);
				if (Countries.searchifthere(firstcountry) == true)
				{
					cout << "Please enter the id of the city you want move from" << endl;
					cin >> city_id;
					City firstcity(city_id, city_name);
					if (Countries.search(firstcountry)->data.tree.searchifthere(firstcity) == true)
					{
						cout << "Please enter the id of the store you want to move from" << endl;
						cin >> store1_id;
						Street_Store firststore(store1_id, Street_name, Manager_name, Telephone, day, month, year);
						if (Countries.search(firstcountry)->data.tree.search(firstcity)->value.searchstorebool(firststore) == true)
						{
							cout << "Please enter the employee id you want to move" << endl;
							cin >> employee_id;
							employee firstemployee(employee_id, employee_name);
							if (Countries.search(firstcountry)->data.tree.search(firstcity)->value.Stores[Countries.search(firstcountry)->data.tree.search(firstcity)->value.searchstoreint(firststore)].searchemployeecheck(firstemployee) == true)
							{
								employee_name = Countries.search(firstcountry)->data.tree.search(firstcity)->value.Stores[Countries.search(firstcountry)->data.tree.search(firstcity)->value.searchstoreint(firststore)].A_emplyee[Countries.search(firstcountry)->data.tree.search(firstcity)->value.Stores[Countries.search(firstcountry)->data.tree.search(firstcity)->value.searchstoreint(firststore)].searchemployeeindex(firstemployee)].employee_name;
								Countries.search(firstcountry)->data.tree.search(firstcity)->value.Stores[Countries.search(firstcountry)->data.tree.search(firstcity)->value.searchstoreint(firststore)].deleteemployee(firstemployee);
								employee firstemployee(employee_id, employee_name);
								cout << "Please enter the id of the store you want to move to" << endl;
								cin >> store2_id;
								Street_Store secondstore(store2_id, Street_name, Manager_name, Telephone, day, month, year);
								if (Countries.search(firstcountry)->data.tree.search(firstcity)->value.searchstorebool(secondstore) == true)
								{
									if (Countries.search(firstcountry)->data.tree.search(firstcity)->value.Stores[Countries.search(firstcountry)->data.tree.search(firstcity)->value.searchstoreint(secondstore)].searchemployeecheck(firstemployee) == true)
									{
										cout << "This employee already exist in this store" << endl;
									}
									else
									{
										Countries.search(firstcountry)->data.tree.search(firstcity)->value.Stores[Countries.search(firstcountry)->data.tree.search(firstcity)->value.searchstoreint(secondstore)].insertemployee(firstemployee);
										cout << "The employee has been transfered from store of id " << firststore.Store_id << " to store of id " << secondstore.Store_id << endl;
									}
								}
								else
								{
									cout << "The store you want to trasnfer to doesnt exist" << endl;
								}
							}
							else
							{
								cout << "The employee doesnt exist" << endl;
							}
						}
						else
						{
							cout << "The store you want to transfer from doesnt exist" << endl;
						}
					}
					else
					{
						cout << "This city doesnt exist" << endl;
					}
				}
				else
				{
					cout << "This country doesnt exist" << endl;
				}
			}
			else
			{
				cout << "Such command doesnt exist" << endl;
			}
		}

		else if (temp == 5)
		{

			int temp1;
			cout << "Press 1 to print information of stores in all countries" << endl;
			cout << "Press 2 to print information of stores in a specific country" << endl;
			cout << "Press 3 to print information of stores in a specific city" << endl;
			cout << "Press 4 to print information of specific store" << endl;
			cin >> temp1;
			//deleting all the cities and countries that doesnt contain any stores before printing

			Countries.deleteifnostorescities();
			Countries.deleteifnostores();

			if (temp1 == 1)
			{
				//print everything
				Countries.print();
			}
			else if (temp1 == 2)
			{
				//print everything in a specific country
				int country_id;
				string country_name = "";
				cout << "Please enter the id of the country you want to print the number of stores from " << endl;
				cin >> country_id;
				Country firstcountry(country_id, country_name);
				if (Countries.searchifthere(firstcountry) == true)
				{
					cout << "The stores in the country " << Countries.search(firstcountry)->data.country_name << " of id " << Countries.search(firstcountry)->data.country_id << "is :" << endl;
					Countries.search(firstcountry)->data.tree.inorder_print();
				}
				else
				{
					cout << "This Country doesnt exist" << endl;
				}
			}
			else if (temp1 == 3)
			{
				//print everything in a specifc city
				int country_id;
				string country_name = "";
				int city_id;
				string city_name = "";
				cout << "Please enter the id of the country you want to print the number of stores from " << endl;
				cin >> country_id;
				Country firstcountry(country_id, country_name);
				if (Countries.searchifthere(firstcountry) == true)
				{
					cout << "Please enter the id of the city you want to print the number of stores from" << endl;
					cin >> city_id;
					City firstcity(city_id, city_name);
					if (Countries.search(firstcountry)->data.tree.searchifthere(firstcity) == true)
					{
						cout << "The stores in the city " << Countries.search(firstcountry)->data.tree.search(firstcity)->value.City_name << " of id " << city_id << "is :" << endl;
						Countries.search(firstcountry)->data.tree.search(firstcity)->value.print();
					}
					else
					{
						cout << "This city doesnt exist" << endl;
					}
				}
				else
				{
					cout << "This country doesnt exist" << endl;
				}
			}
			else if (temp1 == 4)
			{
				//print information for a specific store
				int country_id;
				string country_name = "";
				int city_id;
				string city_name = "";
				int store_id;
				string Street_name = "";
				string Manager_name = "";
				string Telephone = "";
				int day = 1;
				int month = 1;
				int year = 1;
				cout << "Please enter the id of the country you want to print the number of stores from " << endl;
				cin >> country_id;
				Country firstcountry(country_id, country_name);
				if (Countries.searchifthere(firstcountry) == true)
				{
					cout << "Please enter the id of the city you want to print the number of stores from" << endl;
					cin >> city_id;
					City firstcity(city_id, city_name);
					if (Countries.search(firstcountry)->data.tree.searchifthere(firstcity) == true)
					{
						cout << "Please enter the id of the store you want to print the number of stores from" << endl;
						cin >> store_id;
						Street_Store firststore(store_id, Street_name, Manager_name, Telephone, day, month, year);
						if (Countries.search(firstcountry)->data.tree.search(firstcity)->value.searchstorebool(firststore) == true)
						{

							Countries.search(firstcountry)->data.tree.search(firstcity)->value.Stores[Countries.search(firstcountry)->data.tree.search(firstcity)->value.searchstoreint(firststore)].print();
						}
						else
						{
							cout << "This store doesnt exist" << endl;
						}
					}
					else
					{
						cout << "This city doesnt exist" << endl;
					}
				}
				else
				{
					cout << "This country doesnt exist" << endl;
				}

			}
		}

		else if (temp == 6)
		{
			break;
		}

		else
		cout << "The option you entered isn't valid. Please re-enter an option that is available" << endl;
	}

}
