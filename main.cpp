#include <iostream>
#include "booking.h"

int main()
{
    cHotel_manager hotel_manager;

    int Q = 0;
    std::string command = "", hotel_name = "";
    int64_t time = 0;
    uint64_t client_id = 0;
    uint16_t room_count = 0;
    std::cin >> Q;

    for (;Q; --Q)
    {
        std::cin >> command;
        if (command == "BOOK")
        {
            std::cin >> time >> hotel_name >> client_id >> room_count;
            hotel_manager.Book(time, hotel_name, client_id, room_count);
        }
        if (command == "CLIENTS")
        {
            std::cin >> hotel_name;
            std::cout << hotel_manager.Clients(hotel_name) << "\n";
        }
        if (command == "ROOMS")
        {
            std::cin >> hotel_name;
            std::cout << hotel_manager.Rooms(hotel_name) << "\n";
        }
    }

    return 0;
}