#include "../src/trie.hpp"

int test_trie(void) {
    int failures = 0;

    {
        std::string context = "Test Queue Ordering";


        double c = 0.01;
        bool calculate_size = false;
        int ablation = 0;
        int nrules, nsamples, nlabels, nsamples_label;
        rule_t *rules, *labels;
        rule_t *meta;
        char const *type = "node";
        Trie* tree = new Trie(calculate_size, type);
        tree->insert_root();
        Node* root = tree->root();

        std::vector<int> id1 {1, 2};
        Node* child1 = tree->construct_node(id1, root);
        tree->insert(child1);

        std::vector<int> id2 {2, 3, 4, 5};
        Node* child2 = tree->construct_node(id2, child1);
        tree->insert(child2);

        std::vector<int> id3 {1, 3, 5, 6};
        Node* child3 = tree->construct_node(id3, child1);
        tree->insert(child3);

        tracking_vector<std::vector<int>, DataStruct::Tree> prefix {{1, 2}, {2,3,4,5}};
        failures += expect(child2 == tree->check_prefix(prefix), "test1", context);

        std::string serialization;
        tree->serialize(serialization, 2);
        std::cout << serialization << std::endl;

        // float equity_bias = 0.5;
        // Queue queue;
        // Message message;

        // Bitmask a(2);
        // a.set(0, false);
        // a.set(1, false);

        // Bitmask b(2);
        // b.set(0, true);
        // b.set(1, false);

        // Bitmask c(2);
        // c.set(0, false);
        // c.set(1, true);

        // Bitmask d(2);
        // d.set(0, true);
        // d.set(1, true);

        // // Messages
        // // a = (1, 00)
        // // b = (2, 10)
        // // c = (3, 01)
        // // d = (4, 11)

        // failures += expect(0, queue.size(), "Queue::size reports incorrect size", context);
        // queue.push(a, 1, 0.0, 0.5, 0.5, 0.7); // 4th
        // failures += expect(1, queue.size(), "Queue::size reports incorrect size", context);
        // queue.push(b, 2, 0.0, 0.5, 0.7, 0.5); // 3rd
        // failures += expect(2, queue.size(), "Queue::size reports incorrect size", context);
        // queue.push(c, 3, 0.0, 0.6, 0.3, 0.2); // 1st
        // failures += expect(3, queue.size(), "Queue::size reports incorrect size", context);
        // queue.push(d, 4, 0.0, 0.6, 0.2, 0.3); // 2nd
        // failures += expect(4, queue.size(), "Queue::size reports incorrect size", context);

        // // Expected Ordering: c, d, b, a
        // // Erroneous Ordering: d, a, b, c

        // failures += expect(false, queue.empty(), "Queue::empty reports extraneous message", context);

        // char code;
        // float weight;
        // Bitmask content(2);

        // queue.pop(content, & code, & weight);
        // failures += expect(3, code, "1st Message Context Mismatch", context);
        // failures += expect(c.to_string(), content.to_string(), "1st Message Content Mismatch", context);
        // failures += expect(3, queue.size(), "Queue::size reports incorrect size", context);

        // queue.pop(content, & code, & weight);
        // failures += expect(4, code, "2nd Message Context Mismatch", context);
        // failures += expect(d.to_string(), content.to_string(), "2nd Message Content Mismatch", context);
        // failures += expect(2, queue.size(), "Queue::size reports incorrect size", context);

        // queue.pop(content, & code, & weight);
        // failures += expect(2, code, "3rd Message Context Mismatch", context);
        // failures += expect(b.to_string(), content.to_string(), "3rd Message Content Mismatch", context);
        // failures += expect(1, queue.size(), "Queue::size reports incorrect size", context);

        // queue.pop(content, & code, & weight);
        // failures += expect(1, code, "4th Message Context Mismatch", context);
        // failures += expect(a.to_string(), content.to_string(), "4th Message Content Mismatch", context);
        // failures += expect(0, queue.size(), "Queue::size reports incorrect size", context);

        // failures += expect(queue.empty(), "Queue::empty reports extraneous message", context);
    }

    return failures;
}