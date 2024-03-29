#include "response.h"

using namespace std;

void BusInfoResponse::AddToStream(ostream& os) const {
    os << "Bus " << bus_id << ": ";
    if (bus) {
        os << bus->GetStopsCount() << " stops on route, "
           << bus->GetStats().unique_stops_count << " unique stops, "
           << bus->GetStats().route_length << " route length";
    } else {
        os << "not found";
    }
}

void StopInfoResponse::AddToStream(ostream& os) const {
    os << "Stop " << stop_id << ": ";
    if (stop) {
        const auto& buses = stop->GetBuses();
        if (!buses.empty()) {
            os << "buses ";
            for (const string& bus : buses) {
                os << bus << ' ';
            }
        } else {
            os << "no buses";
        }
    } else {
        os << "not found";
    }
}

ostream& operator<<(ostream& os, const Response& response) {
    response.AddToStream(os);
    return os;
}

void PrintResponses(const vector<ResponsePtr>& responses, ostream& stream) {
    for (const ResponsePtr& response : responses) {
        stream << *response << '\n';
    }
}
