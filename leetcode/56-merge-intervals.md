# 56. Merge Intervals
* Topics: Array, Sorting
* Level: Medium
* Date: 2021-12-24
* Duration to solve: N/A
* Link: https://leetcode.com/problems/merge-intervals/

# Idea #1: Brute-force
1. 10001 길이의 flag bool 배열을 생성하고 모두 false로 초기화한다. 시간복잡도는 $O(N)$.
3. 범위에 속한 모든 숫자들을 배열의 인덱스에 대응시켜 flag를 true로 설정한다. 시간복잡도는 $O(N^2)$.
4. flag가 false인 부분을 기준으로 split하여, flag가 true인 구간들을 구한다. 시간복잡도는 $O(N)$.

최종 시간복잡도: $O(N^2)$

여기서는 N이 $10000$ 까지지만, 더 커지면 비효율적일 것이다.

# Idea #2: Greedy
1. 구간 쌍 [start, end] 을 정렬한다. 정렬할 때 std::sort를 사용했다. 시간복잡도는 $O(NlogN)$.
   a. start 값이 같은 경우, end 오름차순
   b. start 값이 다른 경우, start 오름차순
2. 맨 앞에 있는 구간 쌍을 answers에 하나 추가한다. 시간복잡도는 $O(1)$.
3. 나머지 구간들을 하나씩 뽑는다. 시간복잡도는 $O(N)$.
   a. 이전 구간과 현재 구간이 겹칠 경우,  end를 큰 값으로 업데이트.
   b. 이전 구간과 현재 구간이 겹치지 않을 경우, answers 뒤에 추가.

최종 시간복잡도: $O(NlogN)$

# Source Code

```cpp
bool compare(const vector<int>& lhs, const vector<int>& rhs)
{
    assert(lhs.size() == 2);
    assert(rhs.size() == 2);

    if (lhs[0] == rhs[0])
    {
        return lhs[1] < rhs[1];
    }
    return lhs[0] < rhs[0];
}

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), compare);
        
        vector<vector<int>> answers;
        answers.reserve(intervals.size());
        
        answers.emplace_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); ++i)
        {
            vector<int>& prev = answers[answers.size() - 1];
            vector<int>& cur = intervals[i];
            
            if (prev[0] <= cur[0] && cur[0] <= prev[1])
            {
                prev[1] = std::max(prev[1], cur[1]);
            }
            else
            {
                answers.emplace_back(cur);
            }
        }
        
        return answers;
    }
};
```