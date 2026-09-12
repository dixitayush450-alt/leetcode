class Solution {
    struct State {
        long long score = 0;
        vector<int> ids;
        bool calculated = false;
    };

    struct Interval {
        int start, end, weight, index;
    };

    vector<Interval> arr;
    vector<int> starts;
    vector<vector<State>> memo;
    int n;

    bool better(const State& a, const State& b) {
        if (a.score != b.score) {
            return a.score > b.score;
        }

        return a.ids < b.ids;  // Lexicographically smaller
    }

    State solve(int i, int remaining) {
        if (i == n || remaining == 0) {
            return State();
        }

        if (memo[i][remaining].calculated) {
            return memo[i][remaining];
        }

        // Option 1: Current interval ko skip karo
        State skip = solve(i + 1, remaining);

        // Option 2: Current interval ko select karo
        int nextIndex = upper_bound(
            starts.begin(),
            starts.end(),
            arr[i].end
        ) - starts.begin();

        State next = solve(nextIndex, remaining - 1);

        State take;
        take.score = arr[i].weight + next.score;
        take.ids = next.ids;
        take.ids.push_back(arr[i].index);

        sort(take.ids.begin(), take.ids.end());

        State answer = better(take, skip) ? take : skip;

        answer.calculated = true;
        memo[i][remaining] = answer;

        return answer;
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        arr.clear();

        for (int i = 0; i < n; i++) {
            arr.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Start time ke according sort
        sort(arr.begin(), arr.end(), [](const Interval& a, const Interval& b) {
            if (a.start != b.start) {
                return a.start < b.start;
            }
            return a.end < b.end;
        });

        starts.clear();

        for (auto& interval : arr) {
            starts.push_back(interval.start);
        }

        memo.assign(n, vector<State>(5));

        return solve(0, 4).ids;
    }
};