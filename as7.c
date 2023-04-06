#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_POINTS 8

bool road_network[NUM_POINTS][NUM_POINTS] = {
    {true, true, false, false, false, true, false, false},
    {true, true, true, false, false, false, false, false},
    {false, true, true, false, true, true, false, false},
    {false, false, false, true, true, false, false, false},
    {false, false, false, true, true, false, false, false},
    {true, false, true, false, false, true, false, false},
    {true, false, false, true, false, false, true, false},
    {false, false, false, false, false, true, false, true}
};

int charging_stations[NUM_POINTS] = {0, 0, 1, 1, 0, 0, 0, 0};

int find_nearest_charging_station(int point) {
    int nearest_charging_station = -1;
    int min_distance = NUM_POINTS;
    
    for (int i = 0; i < NUM_POINTS; i++) {
        if (charging_stations[i]) {
            int distance = abs(i - point);
            if (distance < min_distance) {
                nearest_charging_station = i;
                min_distance = distance;
            }
        }
    }
    
    return nearest_charging_station;
}

int main() {
    //find the nearest charging station to a given point
    int point;
    printf("Which point are you located? 0 - A, 1 - B, 2 - C, 3 - D, 4 - E, 5 - F, 6 - G, 7 - H: ");
    scanf("%d", &point);
    
    if (point < 0 || point >= NUM_POINTS) {
        printf("Invalid point\n");
        return 1;
    }
    
    int nearest_charging_station = find_nearest_charging_station(point);
    if (nearest_charging_station == -1) {
        printf("No charging stations found\n");
    } else {
        printf("At point: %c\npoint: %c arrived to charging station\n", point + 'A', nearest_charging_station + 'A');
    }
    
    return 0;
}
