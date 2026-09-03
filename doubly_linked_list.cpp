/**
 * @author Miles Collins
 * @file doubly_linked_list.cpp
 * @brief Implementation of a doubly linked list.
 * @date 9/3/2025 -- Started implementation of the doubly linked list class.
 */

#include "doubly_linked_list.h"
#include <iostream>
#include <stdexcept>

DoublyLinkedList::DoublyLinkedList() {
  head = nullptr;
  tail = nullptr;
}

bool DoublyLinkedList::isEmpty() {
  return head == nullptr;
}

void DoublyLinkedList::insertAtHead(int value) {
  DllNode* newNode = new DllNode(value);

  if (isEmpty()) {
    head = newNode;
    tail = newNode;
  } else {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}

/**
 * @brief Inserts a new node with the specified value at the tail of the list.
 * 
 * Create a pointer to a new DllNode with the given value. Then check if the list is empty. If it is, set both head and tail to the new node.
 * If the list isn't empty, set the new node's previous pointer to the tail, then set the tail's next pointer to the new node.
 * Finally, update the tail pointer to point to the new node.
 * 
 * @param value The value to be inserted.
 * @return void 
 */
void DoublyLinkedList::insertAtTail(int value) {
  DllNode* newNode = new DllNode(value);

  if (isEmpty()) {
    head = newNode;
    tail = newNode;
  } else {
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
  }
}

/**
 * @brief Removes a node with the specified value from the list.
 * 
 * Checks for an empty list, and delegates the dangling pointer issues to removeHeaderNode() and removeTailNode() if the head or tail is the node to remove. 
 * Otherwise, it traverses the list to find the node and removes it by updating the previous and next pointers of adjacent nodes.
 * 
 * @param value The value of the node to be removed.
 * @return void
 */
void DoublyLinkedList::remove(int value) {
  /// First check if empty
  if (isEmpty()) { return; }

  /// I will have the removeHeaderNode() take care of the possible dangling pointer issue 
  /// if the head is the node to remove, and the removeTailNode() take care of the possible dangling pointer issue if the tail is the node to remove.
  if (head->key == value) { removeHeaderNode(); return;}

  /// Same as above, but for the tail node.
  if (tail->key == value) { removeTailNode(); return; }

  /// Traverse the list to find the node with the given value and remove it.
  DllNode* current = head->next;
  while (current != nullptr) {
    if (current->key == value) {
        /// If I find the node, update the previous node's next pointer to point to the next node, 
        /// since the current node is being removed. Since we know it isn't the head, I can safely update the previous node's next pointer.
        current->prev->next = current->next;

        /// Now do the same for the next node's previous pointer. Since we know the current node can't be the tail, 
        /// I can safely update the next node's previous pointer.
        current->next->prev = current->prev;

        /// Now I can safely delete the current node and return.
        delete current;
        return;
    }

    /// Assign current to be the next node in the list, so I can continue traversing the list.
    current = current->next;
  }
}

/**
 * @brief Removes the head node from the list.
 * 
 * If the list is empty, just return. Then check if the list has only 1 node, if it does delete the head and set head and tail to nullptr to prevent dangling
 * If list contains more than 1 node, set a temporary pointer to the head node, then update the head pointer to point to the next node in the list
 * Finally, delete the temporary pointer to free the memory of the old head node.
 * 
 * @param void
 * @return void
 */
void DoublyLinkedList::removeHeaderNode() {
  /// If the list is empty, there's nothing to remove so just return.
  if (isEmpty()) { return; }
  /// Quick exit -> if the list only has 1 node, delete head, then make sure to set head and tail to nullptr to avoid dangling pointers.
  if(head == tail) {
    delete head;
    head = nullptr;
    tail = nullptr;
    return;
  }

  /// Now that we know the list has more than 1 node, set a temporary pointer to the head node, then update the head pointer to point to the next node in the list.
  DllNode* temp = head;
  head = head->next;
  head->prev = nullptr;
  delete temp;
  temp = nullptr;
  }


void DoublyLinkedList::removeTailNode() {
  return;
}

void DoublyLinkedList::moveNodeToHead(int value) {
  return;
}

void DoublyLinkedList::moveNodeToTail(int value) {return;}

void DoublyLinkedList::clear() {return;}

void DoublyLinkedList::printList() {return;}

void DoublyLinkedList::reversePrintList() {return;}



