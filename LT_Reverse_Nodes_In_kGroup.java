// Problem Link: https://leetcode.com/problems/reverse-nodes-in-k-group/description/

class ListNode {
    int val;
    ListNode next;

    ListNode() {}

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode reverseInGroups(ListNode head, int k) {
        if (head == null) return head;

        ListNode current = head;
        ListNode previous = null;
        ListNode next = head.next;

        // Check if there are k nodes available
        for (int i = 0; i < k - 1; i++) {
            if (next == null) return current;
            next = next.next;
        }

        next = head.next;

        // Reverse k nodes
        for (int i = 0; i < k; i++) {
            current.next = previous;
            previous = current;
            current = next;
            if (next == null) break;
            next = next.next;
        }

        head.next = reverseInGroups(current, k);
        return previous;
    }

    // Function to print the linked list
    public static void printList(ListNode head) {
        ListNode temp = head;
        while (temp != null) {
            System.out.print(temp.val + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1
        ListNode head1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        int k1 = 2;
        ListNode result1 = solution.reverseInGroups(head1, k1);
        System.out.print("Output for test case 1: ");
        Solution.printList(result1);

        // Test case 2
        ListNode head2 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        int k2 = 3;
        ListNode result2 = solution.reverseInGroups(head2, k2);
        System.out.print("Output for test case 2: ");
        Solution.printList(result2);
    }
}
