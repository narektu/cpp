#include <iostream>
#include <string>
#include <limits>
#include "../projects/basics/include/manager.h"
#include "../projects/basics/include/contact.h"

void print_menu()
{
   std::cout << "\n--- Contact Manager ---\n";
   std::cout << "1. Add Contact\n";
   std::cout << "2. List All Contacts\n";
   std::cout << "3. Find Contact\n";
   std::cout << "4. Remove Contact\n";
   std::cout << "5. Save & Exit\n";
   std::cout << "Enter choice: ";
}

std::string get_input(const std::string &prompt)
{
   std::cout << prompt;
   std::string input;
   std::getline(std::cin, input);
   return input;
}

int main()
{
   ContactManager manager;
   const std::string filename = "contacts.csv";

   try
   {
      manager.load_from_file(filename);
      std::cout << "Loaded contacts from " << filename << "\n";
   }
   catch (const std::exception &e)
   {
      std::cerr << "Error loading file: " << e.what() << '\n';
   }

   bool running = true;
   while (running)
   {
      print_menu();

      int choice;
      if (!(std::cin >> choice))
      {
         std::cin.clear();
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         std::cout << "Invalid input. Please enter a number.\n";
         continue;
      }

      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      try
      {
         switch (choice)
         {
         case 1:
         {
            std::string first = get_input("First Name: ");
            std::string last = get_input("Last Name: ");
            std::string phone = get_input("Phone: ");
            std::string email = get_input("Email: ");

            manager.add_contact(Contact(first, last, phone, email));
            std::cout << "Contact added successfully.\n";
            break;
         }
         case 2:
         {
            const auto &contacts = manager.get_all_contacts();
            if (contacts.empty())
            {
               std::cout << "No contacts found.\n";
            }
            else
            {
               for (const auto &c : contacts)
               {
                  std::cout << "----------\n"
                            << c << "\n";
               }
            }
            break;
         }
         case 3:
         {
            std::string query = get_input("Enter search query (name or phone): ");
            auto results = manager.find_contacts(query);
            if (results.empty())
            {
               std::cout << "No matches found.\n";
            }
            else
            {
               std::cout << "Found " << results.size() << " matches:\n";
               for (const auto &c : results)
               {
                  std::cout << "----------------\n"
                            << c << "\n";
               }
            }
            break;
         }
         case 4:
         {
            std::string phone = get_input("Enter phone number to delete: ");
            if (manager.remove_contact(phone))
            {
               std::cout << "Contact removed.\n";
            }
            else
            {
               std::cout << "Contact not found.\n";
            }
            break;
         }
         case 5:
         {
            manager.save_to_file(filename);
            std::cout << "Data saved. Goodbye!\n";
            running = false;
            break;
         }
         default:
            std::cout << "Unknown option. Try again.\n";
         }
      }
      catch (const std::exception &e)
      {
         std::cerr << "Error: " << e.what() << '\n';
      }
   }

   return 0;
}
