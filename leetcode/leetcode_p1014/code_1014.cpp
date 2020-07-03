// 力扣1014题
// 给定正整数数组 A，A[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的距离为 j - i。
// 一对景点（i < j）组成的观光组合的得分为（A[i] + A[j] + i - j）：景点的评分之和减去它们两者之间的距离。
// 返回一对观光景点能取得的最高分。

#include <iostream>
#include <vector>

int maxScoreSightseeingPair_one(std::vector<int> & A);
int maxScoreSightseeingPair_two(std::vector<int> & A);
int maxScoreSightseeingPair_three(std::vector<int> & A);

int main()
{
    using namespace std;
    vector<int> a = {8, 1, 5, 2, 6};
    int max_score1 = maxScoreSightseeingPair_one(a);
    int max_score2 = maxScoreSightseeingPair_two(a);
    int max_score3 = maxScoreSightseeingPair_three(a);

    cout << "#1 -- max_score: " << max_score1 << endl;

    cout << "#2 -- max_score: " << max_score2 << endl;

    cout << "#3 -- max_score: " << max_score3 << endl;

    cin.get();
    return 0;
}

int maxScoreSightseeingPair_one(std::vector<int> & A)
{
    int max_score = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i + 1; j < A.size(); j++)
        {
            int score = A[i] + A[j] + i - j;
            if (max_score < score)
                max_score = score;
        }
    }

    return max_score;
}

int maxScoreSightseeingPair_two(std::vector<int> & A){
    int max_score = 0;
    std::vector<int> split_window;
    for (int i = 0; i < A.size(); i++)
    {
        if (split_window.size() < 2)
            split_window.push_back(A[i]);
        if (split_window.size() == 2)
        {
            int score = split_window[0] + split_window[1] - 1;
            if (score > max_score)
                max_score = score;
            if (split_window[0] - 1 < split_window[1])
                split_window[0] = split_window[1];
            else
                split_window[0] -= 1;
            split_window.pop_back();
        }
    }

    return max_score;
}

int maxScoreSightseeingPair_three(std::vector<int> & A)
{
    int max_score = 0;
    int m = A[0];
    for (int i = 1; i < A.size(); i ++)
    {
        int score = m + A[i] - 1;
        if (score > max_score)
            max_score = score;
        if (m - 1 > A[i])
            m -= 1;
        else
            m = A[i];
    }

    return max_score;
}