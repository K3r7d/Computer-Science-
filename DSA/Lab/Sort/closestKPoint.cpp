void closestKPoints(Point points[], int n, Point &des_point, int k){
//TODO
    int i, j;
    int max = 0;
    Point tmp;
    for (i = 1; i < n; i++) {
        max = pow(points[i].x - des_point.x, 2) + pow(points[i].y - des_point.y, 2);
        tmp = points[i];
        j = i - 1;
        while (j >= 0 && pow(points[j].x - des_point.x, 2) + pow(points[j].y - des_point.y, 2) > max) {
            points[j + 1] = points[j];
            j = j - 1;
        }
            points[j + 1] = tmp;
    }
    if(k > n) k = n;
    for (int i = 0; i < k; i++) {
        points[i].display();
    cout << endl;
    }
}