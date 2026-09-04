/**
 * @author Miles Collins
 * @file doubly_linked_list.cpp
 * @brief Implementation of a doubly linked list.
 * @date 9/3/2025 -- Started implementation of the doubly linked list class.
 */

#include "doubly_linked_list.h"
#include <iostream>
#include <memory>
#include <stdexcept>

/**
 * @brief Constructs an empty doubly linked list.
 *
 * Initializes both the head and tail pointers to nullptr to indicate
 * that the list contains no nodes upon creation.
 */
DoublyLinkedList::DoublyLinkedList() {
  head = nullptr;
  tail = nullptr;
}

/**
 * @brief Destroys the doubly linked list.
 */
DoublyLinkedList::~DoublyLinkedList() {
  clear();
}

/**
 * @brief Checks if the doubly linked list is empty.
 *
 * @return true if head is nullptr, false otherwise.
 */
bool DoublyLinkedList::isEmpty() const {
  return head == nullptr;
}

/**
 * @brief Inserts a new node with the specified value at the head of the list.
 *
 * Allocates a new node with the given value. If the list is empty, sets both head
 * and tail to the new node. Otherwise, links the new node before the current head
 * and updates the head pointer.
 *
 * @param value The integer value to insert at the front.
 */
void DoublyLinkedList::insertAtHead(int value) {
  auto* newNode = new DllNode(value);

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
 * Allocates a new node with the given value. If the list is empty, sets both head
 * and tail to the new node. Otherwise, links the new node after the current tail
 * and updates the tail pointer.
 *
 * @param value The integer value to insert at the end.
 */
void DoublyLinkedList::insertAtTail(int value) {
  auto* newNode = new DllNode(value);

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
 * @brief Removes the first node containing the specified value from the list.
 *
 * Checks if the list is empty. Delegates removal to removeHeaderNode() or
 * removeTailNode() if the matching value resides at the head or tail. Otherwise,
 * traverses the inner nodes, updates surrounding pointers, and deletes the node.
 *
 * @param value The integer value of the node to remove.
 */
void DoublyLinkedList::remove(int value) {
  /// First check if empty
  if (isEmpty()) { return; }

  /// Handle head removal using helper function
  if (head->key == value) { removeHeaderNode(); return; }

  /// Handle tail removal using helper function
  if (tail->key == value) { removeTailNode(); return; }

  /// Traverse the list to find the node with the given value and remove it.
  DllNode* current = head->next;
  while (current != nullptr) {
    if (current->key == value) {
        /// Detach node from previous neighbor
        current->prev->next = current->next;

        /// Detach node from next neighbor
        current->next->prev = current->prev;

        /// Delete node and exit
        delete current;
        return;
    }

    /// Advance to the next node
    current = current->next;
  }
}

/**
 * @brief Moves a node with the specified value to the head of the list.
 *
 * Traverses the list starting from the head to search for the node with the target value:
 * - Returns immediately if the list is empty or the matching node is already at the head.
 * - If the node is the current tail, detaches it and updates the tail to the previous node.
 * - If the node is in the middle, detaches it by re-linking its adjacent nodes.
 * - Re-inserts the detached node as the new head and updates the list pointers.
 *
 * If no node matches the value, no modifications are made.
 *
 * @param value The key of the node to move to the head.
 */
void DoublyLinkedList::moveNodeToHead(int value) {
  /// Check if list is empty for quick exit
  if(isEmpty()) {return;}

  DllNode* current = head;
  /// Traverse the list starting from the head to find the node with the value.
  while(current != nullptr) {

    /// If the node is found, move it to the head of the list.
    if(current->key == value) {

      /// Quick check to see if the node is already the head.
      if(current == head) {return;}

      /// If it's the tail, update the tail pointer and disconnect the current node.
      if(current == tail) {
        tail = current->prev;
        tail->next = nullptr;
        /// Otherwise, re-link adjacent nodes to detach current from the middle.
      } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
      }

      /// Insert the detached node as the new head of the list.
      head->prev = current;
      current->next = head;
      current->prev = nullptr;
      head = current;

      /// Exit after moving the node to avoid unnecessary iteration.
      return;
    }
    current = current->next;
  }
}

/**
 * @brief Finds a node by its value and relocates it to the tail of the list.
 *
 * Traverses the doubly linked list starting from the tail. If a node matching the
 * specified value is found:
 * - Returns immediately if the node is already at the tail.
 * - Detaches the node from its current position (updating adjacent pointers).
 * - Appends the detached node to the end of the list and updates the tail pointer.
 *
 * If the list is empty or the value is not present, no changes are made.
 *
 * @param value The key of the node to move to the tail.
 */
void DoublyLinkedList::moveNodeToTail(int value) {
  if (isEmpty()) { return; }

  DllNode* current = tail;

  while(current != nullptr) {
    if(current->key == value) {
      if(current == tail) {return;}

      if(current == head) {
        head = current->next;
        head-> prev = nullptr;
      } else {
        current->next->prev = current->prev;
        current->prev->next = current->next;
      }

      tail->next = current;
      current->prev = tail;
      current->next = nullptr;
      tail = current;
      return;
    }
    current = current->prev;
  }
}

/**
 * @brief Clears the entire doubly linked list by removing all nodes.
 *
 * Continuously checks if the list is empty with a while loop. As long as the list contains
 * nodes, it calls removeHeaderNode() to remove each node from the front until no nodes remain.
 *
 * @return void
 */
void DoublyLinkedList::clear() {
  while(!isEmpty()) {
    removeHeaderNode();
  }
}

/**
 * @brief Prints the entire doubly linked list from head to tail.
 *
 * Creates a pointer starting at the head of the list. Iterates forward through
 * the list using a while loop, calling printNode() on each node and updating the
 * pointer to current->next until current reaches nullptr.
 *
 * @return void
 */
void DoublyLinkedList::printList() const {
  DllNode* current = head;
  while(current != nullptr) {
    current->printNode();
    current = current->next;
  }
}

/**
 * @brief Prints the entire doubly linked list in reverse order from tail to head.
 *
 * Creates a pointer starting at the tail of the list. Iterates backward through
 * the list using a while loop, calling printNode() on each node and updating the
 * pointer to current->prev until current reaches nullptr.
 *
 * @return void
 */
void DoublyLinkedList::reversePrintList() const {
  DllNode* current = tail;
  while(current != nullptr) {
    current->printNode();
    current = current->prev;
  }
}



