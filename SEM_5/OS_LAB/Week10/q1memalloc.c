#include <stdio.h>
#include <stdlib.h>

typedef struct mab {
    int offset;
    int size;
    int allocated;
    struct mab *next;
    struct mab *prev;
} Mab;
typedef Mab* MabPtr;

// ---------- Memory functions ----------
MabPtr memMerge(MabPtr m) {
    if (m->next && !m->next->allocated) {
        m->size += m->next->size;
        MabPtr temp = m->next;
        m->next = temp->next;
        if (temp->next) temp->next->prev = m;
        free(temp);
    }
    if (m->prev && !m->prev->allocated) {
        m = m->prev;
        m->size += m->next->size;
        MabPtr temp = m->next;
        m->next = temp->next;
        if (temp->next) temp->next->prev = m;
        free(temp);
    }
    return m;
}

MabPtr memSplit(MabPtr m, int size) {
    if (size >= m->size) return NULL;
    MabPtr newblock = (MabPtr)malloc(sizeof(Mab));
    newblock->offset = m->offset + size;
    newblock->size = m->size - size;
    newblock->allocated = 0;
    newblock->next = m->next;
    newblock->prev = m;
    if (m->next) m->next->prev = newblock;
    m->next = newblock;
    m->size = size;
    return newblock;
}

MabPtr memChk(MabPtr m, int size) {
    MabPtr p = m;
    while (p) {
        if (!p->allocated && p->size >= size)
            return p;
        p = p->next;
    }
    return NULL;
}

MabPtr memAlloc(MabPtr m, int size) {
    MabPtr block = memChk(m, size);
    if (!block)
        return NULL;
    if (block->size > size)
        memSplit(block, size);
    block->allocated = 1;
    return block;
}

MabPtr memFree(MabPtr m) {
    m->allocated = 0;
    memMerge(m);
    return m;
}

void printHeap(MabPtr head) {
    MabPtr p = head;
    printf("Offset\tSize\tAllocated\n");
    while (p) {
        printf("%d\t%d\t%d\n", p->offset, p->size, p->allocated);
        p = p->next;
    }
    printf("\n");
}

MabPtr memBestFit(MabPtr m, int size) {
    MabPtr best = NULL;
    for (MabPtr p = m; p != NULL; p = p->next)
        if (!p->allocated && p->size >= size)
            if (best == NULL || p->size < best->size)
                best = p;
    return best;
}

MabPtr memWorstFit(MabPtr m, int size) {
    MabPtr worst = NULL;
    for (MabPtr p = m; p != NULL; p = p->next)
        if (!p->allocated && p->size >= size)
            if (worst == NULL || p->size > worst->size)
                worst = p;
    return worst;
}

MabPtr memNextFit(MabPtr *last, MabPtr head, int size) {
    MabPtr p = *last ? (*last)->next : head;
    if (!p)
        p = head;
    MabPtr start = p;
    do {
        if (!p->allocated && p->size >= size) {
            *last = p;
            return p;
        }
        p = p->next ? p->next : head;
    } while (p != start);
    return NULL;
}

MabPtr initHeap() {
    MabPtr h1 = (MabPtr)malloc(sizeof(Mab));
    MabPtr h2 = (MabPtr)malloc(sizeof(Mab));
    MabPtr h3 = (MabPtr)malloc(sizeof(Mab));
    h1->offset = 0;   h1->size = 100; h1->allocated = 0; h1->prev = NULL; h1->next = h2;
    h2->offset = 100; h2->size = 300; h2->allocated = 0; h2->prev = h1;   h2->next = h3;
    h3->offset = 400; h3->size = 200;  h3->allocated = 0; h3->prev = h2;   h3->next = NULL;
    return h1;
}

void freeHeap(MabPtr head) {
    MabPtr p = head;
    while (p) {
        MabPtr nxt = p->next;
        free(p);
        p = nxt;
    }
}

int main() {
    MabPtr p;
    
    printf("Initial Heap\n");
    MabPtr heap1 = initHeap();
    printHeap(heap1);
    // FIRST FIT
    printf("After allocating two 100-byte blocks:\n");
    printf("First Fit\n");
    
    MabPtr b1 = memChk(heap1, 100);
    if (b1) { 
        memSplit(b1, 100); 
        b1->allocated = 1; 
    }
    MabPtr b2 = memChk(heap1, 100);
    if (b2) { 
        memSplit(b2, 100); 
        b2->allocated = 1; 
    }
    printHeap(heap1);
    freeHeap(heap1);

    // BEST FIT
    printf("Best Fit\n");
    MabPtr heap2 = initHeap();
    MabPtr b3 = memBestFit(heap2, 100);
    if (b3) { 
        memSplit(b3, 100); 
        b3->allocated = 1; 
    }
    MabPtr b4 = memBestFit(heap2, 100);
    if (b4) { 
        memSplit(b4, 100); 
        b4->allocated = 1; 
    }
    printHeap(heap2);
    freeHeap(heap2);

    // WORST FIT
    printf("Worst Fit\n");
    MabPtr heap3 = initHeap();
    MabPtr b5 = memWorstFit(heap3, 100);
    if (b5) { 
        memSplit(b5, 100); 
        b5->allocated = 1; 
    }
    MabPtr b6 = memWorstFit(heap3, 100);
    if (b6) { 
        memSplit(b6, 100); 
        b6->allocated = 1; 
    }
    printHeap(heap3);
    freeHeap(heap3);
    
    // NEXT FIT
    printf("Next Fit\n");
    MabPtr heap4 = initHeap();
    static MabPtr lastAllocated = NULL;
    MabPtr b7 = memNextFit(&lastAllocated, heap4, 100);
    if (b7) { 
        memSplit(b7, 100); 
        b7->allocated = 1; 
    }
    MabPtr b8 = memNextFit(&lastAllocated, heap4, 100);
    if (b8) { 
        memSplit(b8, 100); 
        b8->allocated = 1; 
    }
    printHeap(heap4);
    freeHeap(heap4);
    return 0;
}
