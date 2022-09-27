# 283. Move Zeroes
* Topic: `Array` and `Two Pointers`
* Level: Easy
* Date: 2022-09-27
* Elapsed Time: 15 min.
* Problem Link: https://leetcode.com/problems/move-zeroes/

# Solution
예제 데이터 `[0, 1, 0, 3, 12]` 를 살펴보자. bubble sort를 사용하듯이, 이웃한 item을 swap하여 풀 수 있다. stable 성질을 유지할 수 있다.

1. [0, 1, 0, 3, 12]
2. [1, 0, 0, 3, 12]
3. [1, 0, 3, 0, 12]
4. [1, 3, 0, 0, 12]
5. [1, 3, 0, 12, 0]
6. [1, 3, 12, 0, 0]

왼쪽에서 오른쪽 방향으로 0이 아닌 숫자를 찾는다. 왼쪽의 이웃한 숫자가 0인 경우 swap한다. 왼쪽에 있는 숫자가 0이 아닐 때까지 왼쪽으로 인덱스를 한 칸씩 옮기면서 swap을 반복한다.

# Source Code
```c
void swap(int* const a, int* const b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void moveZeroes(int* const nums, const int numsSize)
{
    for (int i = 0; i < numsSize; ++i)
    {
        if (nums[i] != 0)
        {
            for (int x = i; x > 0 && nums[x - 1] == 0; --x)
            {
                swap(nums + x - 1, nums + x);
            }
        }
    }
}
```