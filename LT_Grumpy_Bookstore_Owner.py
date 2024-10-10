class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        n = len(customers)
        # Calculate initial satisfied customers without any secret technique.
        initial_satisfaction = sum(customers[i] for i in range(n) if not grumpy[i])
    
        # Use a sliding window to find the maximum additional satisfaction.
        max_additional_satisfaction = 0
        current_additional_satisfaction = 0
        window = deque()
    
        for i in range(n):
            # Add current minute's customers to the window if the owner is grumpy.
            if grumpy[i]:
                current_additional_satisfaction += customers[i]
                window.append(customers[i])
            else:
                window.append(0)
    
            # If window size exceeds the limit, remove the oldest minute's customers.
            if len(window) > minutes:
                removed_customers = window.popleft()
                current_additional_satisfaction -= removed_customers
    
            # Update the maximum additional satisfaction.
            max_additional_satisfaction = max(max_additional_satisfaction, current_additional_satisfaction)
    
        # The result is the sum of the initial satisfaction and the maximum additional satisfaction.
        return initial_satisfaction + max_additional_satisfaction
    