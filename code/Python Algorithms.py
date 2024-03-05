# Kadane Algorithm
def maxSubArraySum(nums,n):
    
    max_product = nums[0]
    start_idx = 0
    end_idx = 0
    current_product = nums[0]
    max_start_idx = 0

    for i in range(1, len(nums)):
        # Update the current product
        current_product += nums[i]

        # Check if the current product is greater than the maximum product
        if current_product > max_product:
            max_product = current_product
            end_idx = i
            start_idx = max_start_idx

        # Check if the current product becomes zero or negative
        if current_product <= 0:
            current_product = 0
            max_start_idx = i+1

    # Retrieve the subarray contributing to the maximum product
    max_subarray = nums[start_idx:end_idx + 1]
    return max_subarray
        
a = [-2, -3, 4, -1, -2, 1, 5, -3]
 
print("Maximum contiguous sum is", maxSubArraySum(a, len(a)))