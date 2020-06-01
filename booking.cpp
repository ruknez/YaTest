#include <string>
#include "booking.h"

int64_t cHotel_manager::Clients(const std::string &hotel_name) const
{
    if (hotel_to_clients.count(hotel_name) == 0)
    {
        return 0;
    }

    return hotel_to_clients.at(hotel_name).size();
}

int64_t cHotel_manager::Rooms(const std::string &hotel_name) const
{
    if (hotel_to_rooms.count(hotel_name) == 0)
    {
        return 0;
    }

    return hotel_to_rooms.at(hotel_name);
}

void cHotel_manager::Book(int64_t time, const std::string &hotel_name, uint64_t client_id, uint16_t room_count)
{

    auto event = sEvent{time, hotel_name, client_id, room_count};

    if (timeLineEvents.empty())
    {
        inserter(event);
    }
    else
    {
        deleter(time);

        inserter(event);
    }
}

void cHotel_manager::inserter(const sEvent &event)
{
    timeLineEvents.push(event);
    hotel_to_clients[event.hotel].insert(event.client);
    hotel_to_rooms[event.hotel] += event.rooms_count;
}

void cHotel_manager::deleter(int64_t current_time)
{
    while (!timeLineEvents.empty())
    {
        auto event = timeLineEvents.front();
        if (event.time > (current_time - seconds_in_day))
        {
            break;
        }

        hotel_to_clients.at(event.hotel).erase(event.client);
        hotel_to_rooms.at(event.hotel) -= event.rooms_count;
        timeLineEvents.pop();
    }
}