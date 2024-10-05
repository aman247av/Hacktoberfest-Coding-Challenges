// Problem Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

public class Main {

    // Definition for singly-linked list.
    static class ListNode {
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

    static class Solution {
        public ListNode swapNodes(ListNode head, int k) {
            // Initialize pointers for traversal
            ListNode nodeFromStart = head;  // Pointer for k-th node from start
            ListNode nodeFromEnd = head;    // Pointer for k-th node from end
            ListNode current = head;        // Pointer for traversing the list
            ListNode preStart = head;       // Pointer for node before the k-th node from start
            ListNode preEnd = head;         // Pointer for node before the k-th node from end

            int count = 1;  // Counter to track the position

            // Traverse the list to locate the k-th nodes and their previous nodes
            while (current.next != null) {
                count++;

                if (count <= k) {
                    preStart = nodeFromStart;
                    current = current.next;
                    nodeFromStart = nodeFromStart.next;
                } else {
                    preEnd = nodeFromEnd;
                    current = current.next;
                    nodeFromEnd = nodeFromEnd.next;
                }
            }

            // Edge case: If the node from start is the last node in the list
            boolean isLastNode = (nodeFromStart.next == null);

            if (isLastNode) {
                // Swap when k-th node from start is the last node
                preStart.next = nodeFromEnd;
                nodeFromStart.next = nodeFromEnd.next;
                nodeFromEnd.next = null;
                head = nodeFromStart;

            } else if (k == 1) { // Edge case: When swapping the first and the last nodes
                preEnd.next = nodeFromStart;
                nodeFromEnd.next = nodeFromStart.next;
                nodeFromStart.next = null;
                head = nodeFromEnd;

            } else {
                // General case: Swap the nodes by adjusting the pointers
                preStart.next = preEnd.next;
                preEnd.next = nodeFromStart;
                ListNode temp = nodeFromStart.next;
                nodeFromStart.next = nodeFromEnd.next;
                nodeFromEnd.next = temp;
            }

            return head;
        }
    }

    // Helper function to create a linked list from an array
    public static ListNode createLinkedList(int[] values) {
        if (values.length == 0) return null;

        ListNode head = new ListNode(values[0]);
        ListNode current = head;

        for (int i = 1; i < values.length; i++) {
            current.next = new ListNode(values[i]);
            current = current.next;
        }

        return head;
    }

    // Helper function to print the linked list
    public static void printLinkedList(ListNode head) {
        ListNode current = head;
        while (current != null) {
            System.out.print(current.val + " ");
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test Case 1: head = [1, 2, 3, 4, 5], k = 2
        int[] values1 = {1, 2, 3, 4, 5};
        ListNode head1 = createLinkedList(values1);
        int k1 = 2;

        System.out.println("Original list 1:");
        printLinkedList(head1);

        ListNode result1 = solution.swapNodes(head1, k1);

        System.out.println("List after swapping:");
        printLinkedList(result1);

        // Test Case 2: head = [7, 9, 6, 6, 7, 8, 3, 0, 9, 5], k = 5
        int[] values2 = {7, 9, 6, 6, 7, 8, 3, 0, 9, 5};
        ListNode head2 = createLinkedList(values2);
        int k2 = 5;

        System.out.println("Original list 2:");
        printLinkedList(head2);

        ListNode result2 = solution.swapNodes(head2, k2);

        System.out.println("List after swapping:");
        printLinkedList(result2);
    }
}
