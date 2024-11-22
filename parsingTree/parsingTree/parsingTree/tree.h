#pragma once

typedef struct Node Node;

// создать дерево разбора по префиксному арифметического выражению
Node* createTree(char* value, int* index);

// вывести на экран в префиксном порядке
void printTree(Node* node);

// посчитать значение префиксного выражения
int calculateTree(Node* node);

// удаление дерева
void removeTree(Node** node);