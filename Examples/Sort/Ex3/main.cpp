#include "Header.h"

int main() {
    List list;
    init(list);
    int n, x = 0;
    cout << "Input number of elements: ";
    cin >> n;
    cout << "Please input the elements:" << endl;
    input(list, n, x);
    printList(list);
    cout << "After sorting the list: " << endl;
    list.head = sortLinkedList(list.head);
    printList(list);
    return 0;
}