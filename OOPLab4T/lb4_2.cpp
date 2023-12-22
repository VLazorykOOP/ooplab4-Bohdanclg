#include <iostream>

typedef unsigned int uint;

struct MyTime{
    unsigned short hour; 
    unsigned short minute; 

    bool operator==(const MyTime &s) const{
        return hour == s.hour && minute == s.minute;
    }

    bool operator>(const MyTime &s) const{
        if (hour > s.hour) return true;
        if (hour < s.hour) return false;
        return minute > s.minute;
    }

    bool operator<(const MyTime &s) const{
        if (hour < s.hour) return true;
        if (hour > s.hour) return false;
        return minute < s.minute;
    }
        
};

std::ostream& operator<<(std::ostream& os, const MyTime& t){
    os << t.hour << ":";
    if (t.minute <= 9) os << "0" << t.minute;
    else os << t.minute;
    os << " ";
    return os;
}

std::istream& operator>>(std::istream& iso, MyTime& t){
    iso >> t.hour >> t.minute;
    t.hour %= 24;
    t.minute %= 60;
    return iso;
}


class BusSchedule{
    int state;
    uint *busNumbers;
    MyTime *departureTimes;
    int maxDepartures;
    int numDepartures;

    public:

    BusSchedule() : numDepartures(0), maxDepartures(20){

        busNumbers = new uint[maxDepartures];
        departureTimes = new MyTime[maxDepartures];

    }

    ~BusSchedule(){

        if (busNumbers != nullptr)
            delete[] busNumbers;
        if (departureTimes != nullptr)
            delete[] departureTimes;

    }

    BusSchedule(int size, uint *numbers, MyTime *times) : numDepartures(size), maxDepartures(size + 5){

        busNumbers = new uint[maxDepartures];
        departureTimes = new MyTime[maxDepartures];
        for (int i = 0; i < size; i++)
        {
            busNumbers[i] = numbers[i];
            departureTimes[i] = times[i];
        }
    }

    void DisplaySchedule(){

        std::cout << "Bus Schedule:\n";
        for (int i = 0; i < numDepartures; i++)
        {
            std::cout << "Bus Number: " << busNumbers[i] << ", Departure Time: " << departureTimes[i] << std::endl;
        }

    }

    uint operator[](const MyTime &time){

        uint busNumber = 0;
        for (int i = 0; i < numDepartures; i++)
        {
            if (departureTimes[i] == time)
                return busNumbers[i];
        }
        std::cout << "Error: Item not found ";
        state = 1;
        return busNumber;

    }

    MyTime operator[](uint number){

        MyTime time{0};
        for (int i = 0; i < numDepartures; i++)
        {
            if (busNumbers[i] == number)
                return departureTimes[i];
        }
        std::cout << "Error: Item not found ";
        state = 1;
        return time;

    }

    void operator()(const MyTime &startTime, const MyTime &endTime){

        bool found = false;
        for (int i = 0; i < numDepartures; i++){
            if (departureTimes[i] > startTime && departureTimes[i] < endTime){
                std::cout << "Bus Number: " << busNumbers[i] << ", Departure Time: " << departureTimes[i] << "\n";
                found = true;
            }
        }
        if (!found)
            std::cout << "No departures found between the specified times.\n";
    }
};



int main()
{

    uint busNumbersArray[5] = {12, 32, 23, 43, 43};
    MyTime departureTimesArray[5] = {{9, 10}, {10, 30}, {10, 30}, {10, 30}, {15, 35}};

    BusSchedule busSchedule(5, busNumbersArray, departureTimesArray);

    busSchedule.DisplaySchedule();

    MyTime queryTime = {10, 30};
    uint resultBusNumber = busSchedule[queryTime];
    std::cout << "Bus Number at " << queryTime << ": " << resultBusNumber << std::endl;

    uint queryNumber = 32;
    MyTime resultTime = busSchedule[queryNumber];
    std::cout << "Departure Time for Bus Number " << queryNumber << ": " << resultTime << std::endl;

    std::cout << "Bus Departures between 9 to 11:\n";
    busSchedule(MyTime{9, 0}, MyTime{11, 0});

    return 0;
    
}
