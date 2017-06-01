class TakeBuses {
public:
    int chooseLine(vector<int> stops, vector<int> period, vector<int> interval, int n, int s) {
        int faster = 0x7fffffff;
		/*
		小明到达公司的时间由三部分组成：起床时间，等车时间，车的行驶时间

		起床时间是固定的s。 
		等车时间取决于起床时间s与发车间隔interval。如果s%interval为0，则等车时间是0；否则等车时间是(interval-s%interval)。

		车的行驶时间，包括停车时间与行驶时间，即 (停站数+1)*5分钟+停站数*停车时间。 
		取等车时间+行驶时间的最小值即可，返回时记得加上起床时间。 
		*/
		for(int i=0;i<n;i++){
			int miss_time = s % interval[i];
			int wait_time = (miss_time == 0?0:interval[i]-miss_time);
			int bus_time = stops[i]*period[i] + (stops[i] + 1)*5;
			faster = min(faster, wait_time+bus_time);
		}
		//必须加上赖床的时间
		return faster+s;
    }
};