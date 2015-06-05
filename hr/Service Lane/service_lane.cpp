#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

using Segment = tuple<unsigned int, unsigned int>;

vector<unsigned int> getAllowedTypes_BruteForce(
    vector<unsigned int> widths, vector<Segment> segments);

vector<unsigned int> getAllowedTypes_Prefix(
    vector<unsigned int> widths, vector<Segment> segments);

vector<unsigned int> getAllowedTypes(
    vector<unsigned int> widths, vector<Segment> segments) {
    return getAllowedTypes_Prefix(widths, segments);
}

int main() {
    unsigned int lenHighway;
    unsigned int numTestCases;

    cin >> lenHighway;
    cin >> numTestCases;

    vector<unsigned int> widths;
    for (unsigned int i = 0; i < lenHighway; ++i) {
        unsigned int width;
        cin >> width;
        widths.push_back(width);
    }

    vector<Segment> segments;
    for (unsigned int i = 0; i < numTestCases; ++i) {
        unsigned int begin, end;
        cin >> begin;
        cin >> end;
        segments.push_back(make_tuple(begin, end));
    }

    auto results = getAllowedTypes(widths, segments);

    for (auto type : results) {
        cout << type << endl;
    }
}

//
// Runtime is quadratic.
//  O(n * m)
//   n = sizeof(segments)
//   m = distance(begin, end)
//
vector<unsigned int> getAllowedTypes_BruteForce(
    vector<unsigned int> widths, vector<Segment> segments) {

    vector<unsigned int> results;

    for (auto seg : segments) {
        unsigned int begin, end;
        tie(begin, end) = seg;
        unsigned int type = 3;
        for (unsigned int i = begin; i <= end; ++i) {
            if (type > widths[i]) {
                type = widths[i];
            }
        }
        results.push_back(type);
    }

    return results;
}

vector<unsigned int> getAllowedTypes_Prefix(
    vector<unsigned int> widths, vector<Segment> segments) {

    vector<unsigned int> truckEndMarkers(widths.size(), 0);
    {
        unsigned int begin = 0;
        unsigned int end = 0;
        for (unsigned int i = 0; i < widths.size(); ++i) {
            if (widths[i] == 3) {
                if (begin == 0 && end == 0) {
                    begin = i;
                    end = i;
                }
                else {
                    ++end;
                }
            }
            else {
                if (begin != end) {
                    for (unsigned int j = begin; j < end; ++j) {
                        truckEndMarkers[j] = end;
                    }
                }
                begin = 0;
                end = 0;
            }
        }
        if (begin != end) {
            for (unsigned int j = begin; j < end; ++j) {
                truckEndMarkers[j] = end;
            }
        }
        begin = 0;
        end = 0;
    }

    vector<unsigned int> carEndMarkers(widths.size(), 0);
    {
        unsigned int begin = 0;
        unsigned int end = 0;
        for (unsigned int i = 0; i < widths.size(); ++i) {
            if (widths[i] >= 2) {
                if (begin == 0 && end == 0) {
                    begin = i;
                    end = i;
                }
                else {
                    ++end;
                }
            }
            else {
                if (begin != end) {
                    for (unsigned int j = begin; j < end; ++j) {
                        carEndMarkers[j] = end;
                    }
                }
                begin = 0;
                end = 0;
            }
        }
        if (begin != end) {
            for (unsigned int j = begin; j < end; ++j) {
                carEndMarkers[j] = end;
            }
        }
        begin = 0;
        end = 0;
    }

    vector<unsigned int> results;

    for (auto seg : segments) {
        unsigned int begin, end;
        tie(begin, end) = seg;
        unsigned int type = 1;

        if (end <= truckEndMarkers[begin]) {
            type = 3;
        }
        else if (end <= carEndMarkers[begin]) {
            type = 2;
        }

        results.push_back(type);
    }

    return results;
}
