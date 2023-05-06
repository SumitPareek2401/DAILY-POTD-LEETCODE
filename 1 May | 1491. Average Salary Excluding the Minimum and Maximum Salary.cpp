class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        
        double sum = 0, count = 0;
        double avrg = 0;
        for(int i = 1; i < salary.size()-1; i++){
            sum += salary[i];
            count++;
        }
        avrg = sum/count;
        return avrg;
    }
};
