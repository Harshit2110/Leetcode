class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {

        int n = coordinates.size();

        if(n == 2)
            return true;

        int dx1 = abs(coordinates[1][0] - coordinates[0][0]); // dx1 = x2 - x1
        int dy1 = abs(coordinates[1][1] - coordinates[0][1]); // dy1 = y2 - y1

        /*
        slope of line is dy1/dx1
        slope of line when (x2, y2) is changed to (x3, y3) is dy2/dx2 when:
            dx2 = x3 - x1
            dy2 = y3 - y1

        if these (x1,y1), (x2,y2), (x3,y3) lie on the same line then
            dy1/dx1 = dy2/dx2 => dy1 * dx2 = dy2 * dx1
        this simplification is done to avoid division by zero case.
        */

        for(int i = 2; i < n; i++){
            int dx2 = abs(coordinates[i][0] - coordinates[0][0]);
            int dy2 = abs(coordinates[i][1] - coordinates[0][1]);

            if( (dy1 * dx2) != (dy2 * dx1) )
                return false;
        }

        return true;
    }
};
