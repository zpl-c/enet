#include "enet.h"
#include "enet_unit.h"

// Test structure to use in our list
typedef struct TestNode {
    ENetListNode node;
    int value;
} TestNode;

TEST(enet_list_insert) {
    ENetList list;
    TestNode node0 = {0};
    TestNode node1 = {0};
    TestNode node2 = {0};
    node0.value = 0;
    node1.value = 1;
    node2.value = 2;

    // for begin
    {
        enet_list_clear(&list);
        enet_list_insert(enet_list_begin(&list), &node0);
        enet_list_insert(enet_list_begin(&list), &node1);
        enet_list_insert(enet_list_begin(&list), &node2);

        ENetListIterator b0 = enet_list_begin(&list);
        ENetListIterator b1 = enet_list_next(b0);
        ENetListIterator b2 = enet_list_next(b1);

        ASSERT_EQ(((TestNode *)b0)->value, 2);
        ASSERT_EQ(((TestNode *)b1)->value, 1);
        ASSERT_EQ(((TestNode *)b2)->value, 0);
    }

    // for end
    {
        enet_list_clear(&list);
        enet_list_insert(enet_list_end(&list), &node0);
        enet_list_insert(enet_list_end(&list), &node1);
        enet_list_insert(enet_list_end(&list), &node2);

        ENetListIterator b0 = enet_list_begin(&list);
        ENetListIterator b1 = enet_list_next(b0);
        ENetListIterator b2 = enet_list_next(b1);

        ASSERT_EQ(((TestNode *)b0)->value, 0);
        ASSERT_EQ(((TestNode *)b1)->value, 1);
        ASSERT_EQ(((TestNode *)b2)->value, 2);
    }

    // for position
    {
        enet_list_clear(&list);
        enet_list_insert(enet_list_end(&list), &node0);
        enet_list_insert(enet_list_end(&list), &node1);

        ENetListIterator middle = enet_list_next(enet_list_begin(&list));
        enet_list_insert(middle, &node2);

        ENetListIterator b0 = enet_list_begin(&list);
        ENetListIterator b1 = enet_list_next(b0);
        ENetListIterator b2 = enet_list_next(b1);

        ASSERT_EQ(((TestNode *)b0)->value, 0);
        ASSERT_EQ(((TestNode *)b1)->value, 2);
        ASSERT_EQ(((TestNode *)b2)->value, 1);
    }

    // // Test inserting the same node multiple times
    // {
    //     enet_list_clear(&list);
    //
    //     // First insert
    //     enet_list_insert(enet_list_end(&list), &node0);
    //     ASSERT_EQ(enet_list_size(&list), 1);
    //
    //     // Try to insert the same node again
    //     enet_list_insert(enet_list_end(&list), &node0);
    //     ASSERT_EQ(enet_list_size(&list), 1); // Size should not change
    //
    //     // Verify list integrity
    //     ENetListIterator current = enet_list_begin(&list);
    //     ENetListIterator next = enet_list_next(current);
    //     ASSERT_EQ(next, enet_list_end(&list)); // Should be the only node
    // }

    // // Test inserting the same node in different lists
    // {
    //     ENetList list1, list2;
    //     enet_list_clear(&list1);
    //     enet_list_clear(&list2);
    //
    //     // Insert into first list
    //     enet_list_insert(enet_list_end(&list1), &node0);
    //     ASSERT_EQ(enet_list_size(&list1), 1);
    //     ASSERT_EQ(enet_list_size(&list2), 0);
    //
    //     // Try to insert into second list
    //     enet_list_insert(enet_list_end(&list2), &node0);
    //     ASSERT_EQ(enet_list_size(&list1), 0); // Should be removed from first list
    //     ASSERT_EQ(enet_list_size(&list2), 1); // Should be in second list
    // }
}

TEST(enet_list_remove) {
    ENetList list;
    TestNode node0 = {0};
    TestNode node1 = {0};
    TestNode node2 = {0};
    node0.value = 0;
    node1.value = 1;
    node2.value = 2;

    // Test 1: Remove already removed node (edge case)
    {
        enet_list_clear(&list);
        enet_list_insert(enet_list_end(&list), &node0);

        ENetListIterator first = enet_list_begin(&list);
        enet_list_remove(first);
        enet_list_remove(first); // Should not crash when removing already removed node
        ASSERT_EQ(enet_list_size(&list), 0);
    }

    // Test 2: Remove from beginning
    {
        enet_list_clear(&list);
        enet_list_insert(enet_list_end(&list), &node0);
        enet_list_insert(enet_list_end(&list), &node1);
        enet_list_insert(enet_list_end(&list), &node2);

        enet_list_remove(enet_list_begin(&list));
        ASSERT_EQ(enet_list_size(&list), 2);

        ENetListIterator b0 = enet_list_begin(&list);
        ENetListIterator b1 = enet_list_next(b0);
        ASSERT_EQ(((TestNode *)b0)->value, 1);
        ASSERT_EQ(((TestNode *)b1)->value, 2);
    }

    // Test 3: Remove from middle
    {
        enet_list_clear(&list);
        enet_list_insert(enet_list_end(&list), &node0);
        enet_list_insert(enet_list_end(&list), &node1);
        enet_list_insert(enet_list_end(&list), &node2);

        ENetListIterator middle = enet_list_next(enet_list_begin(&list));
        enet_list_remove(middle);
        ASSERT_EQ(enet_list_size(&list), 2);

        ENetListIterator b0 = enet_list_begin(&list);
        ENetListIterator b1 = enet_list_next(b0);
        ASSERT_EQ(((TestNode *)b0)->value, 0);
        ASSERT_EQ(((TestNode *)b1)->value, 2);
    }

    // Test 4: Remove from end
    {
        enet_list_clear(&list);
        enet_list_insert(enet_list_end(&list), &node0);
        enet_list_insert(enet_list_end(&list), &node1);
        enet_list_insert(enet_list_end(&list), &node2);

        ENetListIterator last = enet_list_previous(enet_list_end(&list));
        enet_list_remove(last);
        ASSERT_EQ(enet_list_size(&list), 2);

        ENetListIterator b0 = enet_list_begin(&list);
        ENetListIterator b1 = enet_list_next(b0);
        ASSERT_EQ(((TestNode *)b0)->value, 0);
        ASSERT_EQ(((TestNode *)b1)->value, 1);
    }
}


TEST(enet_list_move) {
    ENetList list1, list2;
    TestNode nodes[10] = {0}; // Increased to 10 nodes for more comprehensive testing

    for (int i = 0; i < 10; i++) {
        nodes[i].value = i;
    }

    // Initialize lists
    enet_list_clear(&list1);
    enet_list_clear(&list2);

    // Insert 5 nodes into first list with values 0-4
    for (int i = 0; i < 5; i++) {
        enet_list_insert(enet_list_end(&list1), &nodes[i].node);
    }

    // Insert 5 nodes into second list with values 5-9
    for (int i = 5; i < 10; i++) {
        enet_list_insert(enet_list_end(&list2), &nodes[i].node);
    }
    ASSERT_EQ(enet_list_size(&list1), 5);
    ASSERT_EQ(enet_list_size(&list2), 5);

    // Test 1: Move single node from list2 to list1
    ENetListIterator n6 = enet_list_next(enet_list_begin(&list2));
    ENetListIterator n8 = enet_list_next(enet_list_next(n6));
    enet_list_move(enet_list_end(&list2), n6, n8);

    // Verify node order in list1
    int expected_values1[] = {0, 1, 2, 3, 4, 6, 7, 8};
    int i = 0;
    for (ENetListNode *current = enet_list_begin(&list1);
         current != enet_list_end(&list1);
         current = enet_list_next(current)) {
        TestNode *node = (TestNode *) current;
        ASSERT_EQ(node->value, expected_values1[i++]);
    }

    // // Verify node order in list2
    // int expected_values2[] = {5, 9};
    // i = 0;
    // for (ENetListNode *current = enet_list_begin(&list2);
    //      current != enet_list_end(&list2);
    //      current = enet_list_next(current)) {
    //     TestNode *node = (TestNode *) current;
    //     ASSERT_EQ(node->value, expected_values2[i++]);
    // }

    // // Test 2: Move node to beginning of list
    // enet_list_move(enet_list_begin(&list1), &nodes[8].node);
    // ASSERT_EQ(enet_list_size(&list1), 5);
    // ASSERT_EQ(enet_list_size(&list2), 5);
    //
    // // Test 3: Move node to middle of list
    // enet_list_move(enet_list_next(enet_list_begin(&list1)), &nodes[5].node);
    // ASSERT_EQ(enet_list_size(&list1), 6);
    // ASSERT_EQ(enet_list_size(&list2), 4);
    //
    // // Test 4: Move multiple nodes at once
    // enet_list_move(enet_list_end(&list2), &nodes[0].node, &nodes[3].node);
    // ASSERT_EQ(enet_list_size(&list1), 3);
    // ASSERT_EQ(enet_list_size(&list2), 7);
    //
    // // Test 5: Move node to its current position (should not change anything)
    // enet_list_move(enet_list_next(enet_list_begin(&list1)), &nodes[8].node);
    // ASSERT_EQ(enet_list_size(&list1), 3);
    // ASSERT_EQ(enet_list_size(&list2), 7);
}

TEST(enet_list_clear) {
    ENetList list;
    TestNode node0 = {0};
    TestNode node1 = {0};
    TestNode node2 = {0};
    node0.value = 0;
    node1.value = 1;
    node2.value = 2;

    // Initialize list
    enet_list_clear(&list);

    // Insert nodes
    enet_list_insert(enet_list_end(&list), &node0.node);
    enet_list_insert(enet_list_end(&list), &node1.node);
    enet_list_insert(enet_list_end(&list), &node2.node);

    ASSERT_EQ(enet_list_size(&list), 3);

    // Clear list
    enet_list_clear(&list);
    ASSERT_EQ(enet_list_size(&list), 0);
}

TEST(enet_list_iteration) {
    ENetList list;
    TestNode nodes[5] = {0};
    int i;

    // Initialize list
    enet_list_clear(&list);

    // Insert nodes with values
    for (i = 0; i < 5; i++) {
        nodes[i].value = i;
        enet_list_insert(enet_list_end(&list), &nodes[i].node);
    }

    // Iterate through list and verify values
    ENetListNode *current;
    i = 0;
    for (current = enet_list_begin(&list);
         current != enet_list_end(&list);
         current = enet_list_next(current)) {
        TestNode *node = (TestNode *) current;
        ASSERT_EQ(node->value, i);
        i++;
    }
    ASSERT_EQ(i, 5);
}

TEST(enet_list_empty) {
    ENetList list;
}

TEST(enet_list_size) {
    ENetList list;
    TestNode node0 = {0};
    TestNode node1 = {0};
    TestNode node2 = {0};
    node0.value = 0;
    node1.value = 1;
    node2.value = 2;

    // Initialize list
    enet_list_clear(&list);
    ASSERT_EQ(enet_list_size(&list), 0);

    // Insert nodes
    enet_list_insert(enet_list_end(&list), &node0.node);
    enet_list_insert(enet_list_end(&list), &node1.node);
    enet_list_insert(enet_list_end(&list), &node2.node);
    ASSERT_EQ(enet_list_size(&list), 3);

    // Remove nodes
    enet_list_remove(&node2.node);
    enet_list_remove(&node1.node);
    enet_list_remove(&node0.node);
    ASSERT_EQ(enet_list_size(&list), 0);
}
