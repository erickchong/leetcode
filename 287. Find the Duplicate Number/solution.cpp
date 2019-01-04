class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        const int start = nums[0];
        int hare = nums[nums[start]];
        int tortoise = nums[start];
        /* Find intersection of hare & tortoise */
        while (hare != tortoise) {
            hare = nums[nums[hare]];
            tortoise = nums[tortoise];
        }
        int entrance = start;
        int intersection = hare;
        /* Find the entrance to the cycle that caused the intersection */
        while (entrance != intersection) {
            entrance = nums[entrance];
            intersection = nums[intersection];
        }
        return entrance;
    }
};