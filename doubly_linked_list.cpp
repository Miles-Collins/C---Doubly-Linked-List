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
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}

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
void DoublyLinkedList::remove(int value) {
  return;
}

void DoublyLinkedList::removeHeaderNode() {
  return;
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



