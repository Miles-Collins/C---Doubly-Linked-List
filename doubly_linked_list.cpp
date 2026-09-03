/**
 * @author Miles Collins
 * @file doubly_linked_list.cpp
 * @brief Implementation of a doubly linked list.
 * @date 9/3/2025 -- Started implementation of the doubly linked list class.
 */

#include "doubly_linked_list.h"
#include <iostream>

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
    
  }
}

void DoublyLinkedList::insertAtTail(int value) {}
void DoublyLinkedList::remove(int value) {}

void DoublyLinkedList::removeHeaderNode() {}

void DoublyLinkedList::removeTailNode() {}

void DoublyLinkedList::moveNodeToHead(int value) {}

void DoublyLinkedList::moveNodeToTail(int value) {}

void DoublyLinkedList::clear() {}

void DoublyLinkedList::printList() {}

void DoublyLinkedList::reversePrintList() {}



