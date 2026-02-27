# Data Structures in C (Linked List, Stack, Queue, BST + DFS/BFS)

Este repositório contém implementações **didáticas** em linguagem C de estruturas de dados clássicas, com foco em aprendizado, legibilidade e análise de complexidade.

## Conteúdo
- **Lista Encadeada (Singly Linked List)**
- **Pilha (Stack)**
- **Fila (Queue - circular dinâmica)**
- **Árvore Binária de Busca (BST)**
- **Busca em árvore**
- **DFS (Pré-ordem, Em-ordem, Pós-ordem)**
- **BFS (Level-order)**

---

## 1) Lista Encadeada
Estrutura linear formada por nós (`Node`) em que cada nó aponta para o próximo.

Operações incluídas:
- Inserção no início/fim
- Remoção do início
- Remoção por valor (primeira ocorrência)
- Busca (contains)
- Impressão e limpeza

### Complexidade (Big-O)
- Inserção no início: **O(1)**
- Inserção no fim: **O(n)** (sem ponteiro para cauda)
- Busca: **O(n)**
- Remover por valor: **O(n)**

---

## 2) Pilha (Stack)
Estrutura LIFO (*Last In, First Out*): o último a entrar é o primeiro a sair.

Operações incluídas:
- push, pop, peek

### Complexidade (Big-O)
- push: **O(1)** amortizado (com realocação)
- pop: **O(1)**
- peek: **O(1)**

---

## 3) Fila (Queue)
Estrutura FIFO (*First In, First Out*): o primeiro a entrar é o primeiro a sair.

Implementação:
- Fila circular com crescimento automático (realocação).

Operações incluídas:
- enqueue, dequeue, peek

### Complexidade (Big-O)
- enqueue: **O(1)** amortizado
- dequeue: **O(1)**
- peek: **O(1)**

---

## 4) Árvore Binária de Busca (BST)
Árvore onde:
- valores menores ficam à esquerda
- valores maiores ficam à direita

Operações incluídas:
- inserção
- busca
- DFS (preorder/inorder/postorder)
- BFS (level-order)

### Complexidade (Big-O)
Para BST (sem balanceamento):
- Inserção: **O(h)** (média O(log n), pior O(n))
- Busca: **O(h)** (média O(log n), pior O(n))

Traversals:
- DFS / BFS: **O(n)**

---

## Como compilar

### Opção 1: usando Makefile
```bash
make