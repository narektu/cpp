#include <iostream>
#include <cassert>
#include <filesystem>
#include "../../projects/basics/include/manager.h"
#include "../../projects/basics/include/contact.h"

#define RUN_TEST(test_func)                         \
   std::cout << "Running " << #test_func << "... "; \
   test_func();                                     \
   std::cout << "PASSED\n";

void test_add_and_get_contact()
{
   ContactManager mgr;
   mgr.add_contact(Contact("John", "Doe", "12345", "john@example.com"));

   const auto &contacts = mgr.get_all_contacts();
   assert(contacts.size() == 1);
   assert(contacts[0].get_first_name() == "John");
   assert(contacts[0].get_phone_number() == "12345");
}

void test_remove_contact()
{
   ContactManager mgr;
   mgr.add_contact(Contact("Alice", "Smith", "111", "alice@test.com"));
   mgr.add_contact(Contact("Bob", "Brown", "222", "bob@test.com"));

   bool removed = mgr.remove_contact("111");
   assert(removed == true);
   assert(mgr.get_all_contacts().size() == 1);
   assert(mgr.get_all_contacts()[0].get_first_name() == "Bob");

   removed = mgr.remove_contact("999");
   assert(removed == false);
   assert(mgr.get_all_contacts().size() == 1);
}

void test_find_contact()
{
   ContactManager mgr;
   mgr.add_contact(Contact("Sherlock", "Holmes", "221B", "detective@london.uk"));
   mgr.add_contact(Contact("John", "Watson", "777", "doctor@london.uk"));

   auto results = mgr.find_contacts("Sherlock");
   assert(results.size() == 1);
   assert(results[0].get_last_name() == "Holmes");

   results = mgr.find_contacts("77");
   assert(results.size() == 1);
   assert(results[0].get_last_name() == "Watson");

   results = mgr.find_contacts("Moriarty");
   assert(results.empty());
}

void test_file_io()
{
   std::string test_file = "test_db.csv";

   {
      ContactManager mgr;
      mgr.add_contact(Contact("Test", "User", "555", "test@test.com"));
      mgr.save_to_file(test_file);
   }

   {
      ContactManager mgr;
      mgr.load_from_file(test_file);

      const auto &contacts = mgr.get_all_contacts();
      assert(contacts.size() == 1);
      assert(contacts[0].get_first_name() == "Test");
      assert(contacts[0].get_phone_number() == "555");
   }

   std::filesystem::remove(test_file);
}

int main()
{
   std::cout << "Starting ContactManager Tests\n";

   RUN_TEST(test_add_and_get_contact);
   RUN_TEST(test_remove_contact);
   RUN_TEST(test_find_contact);
   RUN_TEST(test_file_io);

   std::cout << "All Tests Passed\n";
   return 0;
}