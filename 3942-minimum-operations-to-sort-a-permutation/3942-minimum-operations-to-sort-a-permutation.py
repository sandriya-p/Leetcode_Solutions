class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)

        # Find the index of zero
        zero = nums.index(0)

        # Check whether the array follows increasing order
        # in the given circular direction
        def check(step: int) -> bool:
            for i in range(1, n):
                # Calculate the previous and current indices
                prev = (zero + (i - 1) * step) % n
                curr = (zero + i * step) % n

                # If the order decreases, this direction fails
                if nums[prev] > nums[curr]:
                    return False

            return True

        # Initially, no valid answer has been found
        ans = inf

        # Try moving forward
        if check(1):
            ans = min(ans, zero)
            ans = min(ans, n - zero + 2)

        # Try moving backward
        if check(-1):
            ans = min(ans, zero + 2)
            ans = min(ans, n - zero)

        # Return -1 if neither direction works
        return -1 if ans == inf else ans
