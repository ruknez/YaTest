#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>
#include <queue>

class cHotel_manager
{
public:
    void Book(int64_t time, const std::string &hotel_name, uint64_t client_id, uint16_t room_count);
    int64_t Clients(const std::string &hotel_name) const;
    int64_t Rooms(const std::string &hotel_name) const;

private:
    static constexpr int seconds_in_day = 60 * 60 * 24; // 86400;

    struct sEvent
    {
        int64_t time;
        std::string hotel;
        uint64_t client;
        uint16_t rooms_count;
    };

    void inserter(const sEvent &event);
    void deleter(int64_t current_time);

    std::queue<sEvent> timeLineEvents;

    std::unordered_map<std::string, std::unordered_set<int>> hotel_to_clients;
    std::unordered_map<std::string, int> hotel_to_rooms;
};
