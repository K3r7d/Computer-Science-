int maxNumberOfPeople(vector<int>& rooms, vector<int>& people, int k) {
     sort(rooms.begin(), rooms.end());
    sort(people.begin(), people.end());

    int roomCount = rooms.size();
    int peopleCount = people.size();
    int i = 0, j = 0, count = 0;

    while (i < roomCount && j < peopleCount) {
        int roomSize = rooms[i];
        int personSize = people[j];

        if (abs(roomSize - personSize) <= k) {
            // Assign the room to the person
            count++;
            i++;
            j++;
        } else if (roomSize < personSize) {
            // Move to the next available room
            i++;
        } else {
            // Move to the next available person
            j++;
        }
    }

    return count;
}