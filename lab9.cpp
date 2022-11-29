#include <iostream>
#include <libxml++/libxml++.h>

using namespace std;

int main(int argc, char const *argv[]) {

   xmlpp::TextReader reader(argv[1]);

   string lon = argv[2];
   string lat = argv[3];
   string lonTmp;
   string latTmp;

   vector <string> cityBlock(2);
   vector <string> names = {
           "humidity",
           "pressure",
           "clouds",
           "visibility",
           "precipitation",
           "weather",
           "lastupdate"
   };

   while (reader.read()) {

       if (reader.get_name() == "city") {
           reader.move_to_first_attribute();
           cityBlock[0] = reader.get_value();
           reader.move_to_next_attribute();
           cityBlock[1] = reader.get_value();
       }

       if (reader.get_name() == "coord") {
           reader.move_to_first_attribute();
           lonTmp = reader.get_value();
           reader.move_to_next_attribute();
           latTmp = reader.get_value();

           if (lonTmp == lon && latTmp == lat) {
               cout << "City name = " << cityBlock[1] << " (id = "
                    << cityBlock[0] << ") " << endl;

               cout << "	" << "Coords: " << "lon = " << lonTmp << " "
                    << "lat = " << latTmp << endl;

               for (int i = 0; i < 3; i++)
                   reader.read();

               cout << "	" << "Country: " << reader.get_value() << endl;

               for (int i = 0; i < 3; i++)
                   reader.read();

               cout << "	" << "Sun: ";
               reader.move_to_first_attribute();
               cout << "rise = " << reader.get_value() << " ";
               reader.move_to_next_attribute();
               cout << "set = " << reader.get_value() << endl;
               reader.move_to_element();

               while (reader.read()) {

                   string tmp = reader.get_name();

                   for (string elem: names) {
                       if (elem == tmp) {
                           cout << elem << ": " << endl;
                           reader.move_to_first_attribute();

                           do {
                               cout << "	" << reader.get_name() << " = "
                                    << reader.get_value() << endl;
                           } while (reader.move_to_next_attribute());
                       }
                   }

                   if (reader.get_name() == "temperature") {
                       cout << "temprature: " << endl;
                       reader.move_to_first_attribute();

                       if (false) {
                           do {
                               cout << "	" << reader.get_name() << " = "
                                    << reader.get_value() << endl;
                           } while (reader.move_to_next_attribute());
                       } else {
                           double val = stod(reader.get_value());
                           val = (32 - val) * 5 / 9;
                           cout << "	" << reader.get_name() << ": " << val;

                           int count = 0;
                           do {
                               cout << "	" << reader.get_name() << " = "
                                    << reader.get_value() << endl;
                               count++;
                           } while (reader.move_to_next_attribute() && count < 2);

                           cout << "	" << reader.get_name() << ": " << "celsius" << endl;
                       }
                   }

                   if (reader.get_name() == "wind") {
                       cout << "wind: " << endl;
                       reader.read();
                       reader.read();

                       cout << "	Speed: ";
                       reader.move_to_first_attribute();
                       do {
                           cout << "	" << reader.get_name() << " = "
                                << reader.get_value() << " ";
                       } while (reader.move_to_next_attribute());
                       cout << endl;
                       reader.read();
                       reader.read();

                       cout << "	Direction: ";
                       reader.move_to_first_attribute();
                       do {
                           cout << "	" << reader.get_name() << " = "
                                << reader.get_value() << " ";
                       } while (reader.move_to_next_attribute());
                       cout << endl;

                       reader.read();
                       reader.read();
                   }

               }
           }
           break;
       }
   }
}
